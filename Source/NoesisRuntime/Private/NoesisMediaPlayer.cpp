////////////////////////////////////////////////////////////////////////////////////////////////////
// NoesisGUI - http://www.noesisengine.com
// Copyright (c) 2013 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////


#include "NoesisMediaPlayer.h"

// Core includes
#include "Misc/CoreDelegates.h"

// Engine includes
#include "AudioDevice.h"
#include "AudioDeviceManager.h"

// Media includes
#include "IMediaEventSink.h"

// MediaAssets includes
#include "MediaPlayer.h"
#include "MediaSoundComponent.h"
#include "MediaSource.h"
#include "MediaTexture.h"

// NoesisRuntime includes
#include "NoesisRuntimeModule.h"
#include "NoesisSupport.h"
#include "Render/NoesisRenderDevice.h"

#include "NsApp/MediaElement.h"


////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////
NoesisMediaPlayer::NoesisMediaPlayer(NoesisApp::MediaElement* Owner, const Noesis::Uri& Uri, void*):
	MediaPlayer(nullptr), MediaTexture(nullptr), MediaTextureRHI(nullptr), SoundComponent(nullptr),
	TextureSource(*new Noesis::TextureSource()), View(nullptr), Volume(0.5f),
	Opened(false), Ended(false), KeepPlaying(false), IsBuffering(false)
{
	MediaPlayer = NewObject<UMediaPlayer>(GetTransientPackage(), NAME_None, RF_Transient | RF_Public);
	// Enable looping so texture resource is not discarded when media ends
	MediaPlayer->SetLooping(true);
	MediaPlayer->AddToRoot();

	MediaTexture = NewObject<UMediaTexture>(GetTransientPackage(), NAME_None, RF_Transient | RF_Public);
	// Read the comment next to PATTERN_SRGB in FNoesisPS::ModifyCompilationEnvironment
	// MediaTexture->SRGB = false;
	MediaTexture->AutoClear = true;
	MediaTexture->SetMediaPlayer(MediaPlayer);
	MediaTexture->UpdateResource();
	MediaTexture->AddToRoot();

	FAudioDeviceHandle AudioDevice = GEngine->GetActiveAudioDevice();
	if (AudioDevice.IsValid())
	{
		SoundComponent = NewObject<UMediaSoundComponent>(GetTransientPackage(), NAME_None, RF_Transient | RF_Public);
		SoundComponent->bIsUISound = false;
		SoundComponent->bIsPreviewSound = false;
		SoundComponent->SetMediaPlayer(MediaPlayer);
		SoundComponent->CreateAudioComponent(); // Make sure it plays on the active AudioDevice
		SoundComponent->GetAudioComponent()->AudioDeviceID = AudioDevice->DeviceID;
		SoundComponent->Initialize();
		SoundComponent->AddToRoot();
	}

	Noesis::String Path;
	Uri.GetPath(Path);
	FString VideoPath = FString(TEXT("/Game/")) + NsProviderPathToAssetPath(Path.Str());
	UMediaSource* MediaSource = LoadObject<UMediaSource>(nullptr, *VideoPath, nullptr, LOAD_NoWarn);
	if (MediaSource != nullptr && MediaPlayer->OpenSource(MediaSource))
	{
		MediaPlayer->OnMediaEvent().AddRaw(this, &NoesisMediaPlayer::OnMediaEvent);

		View = Owner->GetView();
		View->Rendering() += Noesis::MakeDelegate(this, &NoesisMediaPlayer::OnRendering);
	}
	else if (MediaPlayer->OpenFile(UTF8_TO_TCHAR(Path.Str())))
	{
		MediaPlayer->OnMediaEvent().AddRaw(this, &NoesisMediaPlayer::OnMediaEvent);

		View = Owner->GetView();
		View->Rendering() += Noesis::MakeDelegate(this, &NoesisMediaPlayer::OnRendering);
	}
	else
	{
		NS_LOG("Can't open MediaSource '%s'", TCHAR_TO_UTF8(*VideoPath));
	}
}

////////////////////////////////////////////////////////////////////////////////////////////////////
NoesisMediaPlayer::~NoesisMediaPlayer()
{
	if (View != nullptr)
	{
		View->Rendering() -= Noesis::MakeDelegate(this, &NoesisMediaPlayer::OnRendering);
	}

	MediaPlayer->OnMediaEvent().RemoveAll(this);
	MediaPlayer->RemoveFromRoot();
	MediaPlayer = nullptr;

	MediaTexture->RemoveFromRoot();
	MediaTexture = nullptr;

	if (SoundComponent != nullptr)
	{
		SoundComponent->Stop();
		SoundComponent->RemoveFromRoot();
		SoundComponent = nullptr;
	}
}

////////////////////////////////////////////////////////////////////////////////////////////////////
uint32_t NoesisMediaPlayer::GetWidth() const
{
	return TextureSource->GetPixelWidth();
}

////////////////////////////////////////////////////////////////////////////////////////////////////
uint32_t NoesisMediaPlayer::GetHeight() const
{
	return TextureSource->GetPixelHeight();
}

////////////////////////////////////////////////////////////////////////////////////////////////////
bool NoesisMediaPlayer::CanPause() const
{
	return MediaPlayer->CanPause();
}

////////////////////////////////////////////////////////////////////////////////////////////////////
bool NoesisMediaPlayer::HasAudio() const
{
	return MediaPlayer->GetNumTracks(EMediaPlayerTrack::Audio) > 0;
}

////////////////////////////////////////////////////////////////////////////////////////////////////
bool NoesisMediaPlayer::HasVideo() const
{
	return MediaPlayer->GetNumTracks(EMediaPlayerTrack::Video) > 0;;
}

////////////////////////////////////////////////////////////////////////////////////////////////////
double NoesisMediaPlayer::GetDuration() const
{
	return MediaPlayer->GetDuration().GetTotalSeconds();
}

////////////////////////////////////////////////////////////////////////////////////////////////////
double NoesisMediaPlayer::GetPosition() const
{
	return MediaPlayer->GetTime().GetTotalSeconds();
}

////////////////////////////////////////////////////////////////////////////////////////////////////
void NoesisMediaPlayer::SetPosition(double value)
{
	// setting position before media is opened can do nothing, so we store the value for later
	Position = value;
	MediaPlayer->Seek(FTimespan::FromSeconds(value));
}

////////////////////////////////////////////////////////////////////////////////////////////////////
float NoesisMediaPlayer::GetSpeedRatio() const
{
	return MediaPlayer->GetRate();
}

////////////////////////////////////////////////////////////////////////////////////////////////////
void NoesisMediaPlayer::SetSpeedRatio(float value)
{
	// setting rate before media is opened does nothing, so we have to store the value for later
	Rate = value;
	MediaPlayer->SetRate(value);
}

////////////////////////////////////////////////////////////////////////////////////////////////////
float NoesisMediaPlayer::GetVolume() const
{
	return Volume;
}

////////////////////////////////////////////////////////////////////////////////////////////////////
void NoesisMediaPlayer::SetVolume(float value)
{
	Volume = value;
	if (SoundComponent != nullptr)
	{
		SoundComponent->SetVolumeMultiplier(value);
	}
}

////////////////////////////////////////////////////////////////////////////////////////////////////
bool NoesisMediaPlayer::GetIsMuted() const
{
	return Noesis::IsZero(SoundComponent->GetAudioComponent()->VolumeMultiplier);
}

////////////////////////////////////////////////////////////////////////////////////////////////////
void NoesisMediaPlayer::SetIsMuted(bool value)
{
	if (SoundComponent != nullptr)
	{
		if (value)
		{
			SoundComponent->SetVolumeMultiplier(0.0f);
		}
		else
		{
			SoundComponent->SetVolumeMultiplier(Volume);
		}
	}
}

////////////////////////////////////////////////////////////////////////////////////////////////////
void NoesisMediaPlayer::Play()
{
	KeepPlaying = true;
	MediaPlayer->Play();
}

////////////////////////////////////////////////////////////////////////////////////////////////////
void NoesisMediaPlayer::Pause()
{
	KeepPlaying = false;
	MediaPlayer->Pause();
}

////////////////////////////////////////////////////////////////////////////////////////////////////
void NoesisMediaPlayer::Stop()
{
	KeepPlaying = false;
	MediaPlayer->Pause();
	MediaPlayer->Rewind();
}

////////////////////////////////////////////////////////////////////////////////////////////////////
Noesis::ImageSource* NoesisMediaPlayer::GetTextureSource() const
{
	return TextureSource;
}

////////////////////////////////////////////////////////////////////////////////////////////////////
void NoesisMediaPlayer::CheckKeepPlaying()
{
	if (!KeepPlaying)
	{
		Stop();
	}
	KeepPlaying = false;
}

////////////////////////////////////////////////////////////////////////////////////////////////////
static FRHITexture2D* GetMediaTextureRHI(UMediaTexture* MediaTexture)
{
#if (ENGINE_MAJOR_VERSION >= 5) || ((ENGINE_MAJOR_VERSION == 4) && (ENGINE_MINOR_VERSION >= 27))
	FTextureResource* Resource = (FTextureResource*)MediaTexture->GetResource();
#else
	FTextureResource* Resource = (FTextureResource*)MediaTexture->Resource;
#endif
	FTextureRHIRef TextureRHI = Resource->TextureRHI;
	return TextureRHI ? TextureRHI->GetTexture2D() : nullptr;
}

////////////////////////////////////////////////////////////////////////////////////////////////////
void NoesisMediaPlayer::OnRendering(Noesis::IView*)
{
	// Each time the MediaPlayer finishes a loop, it updates the MediaTexture internal texture,
	// so we have to update our TextureSource too
	FRHITexture2D* texRHI = GetMediaTextureRHI(MediaTexture);
	if (MediaTextureRHI != texRHI && MediaTexture->GetWidth() > 2 && MediaTexture->GetHeight() > 2)
	{
		MediaTextureRHI = texRHI;
		TextureSource->SetTexture(FNoesisRenderDevice::CreateTexture(MediaTexture));
	}

	if (Opened && MediaTexture->GetWidth() > 2 && MediaTexture->GetHeight() > 2)
	{
		MediaPlayer->SetRate(Rate);
		MediaPlayer->Seek(FTimespan::FromSeconds(Position));

		mMediaOpened();

		Opened = false;
		CheckKeepPlaying();
	}

	if (Ended)
	{
		Ended = false;
		CheckKeepPlaying();
	}

	if (SoundComponent != nullptr)
	{
		SoundComponent->UpdatePlayer();
	}
};

////////////////////////////////////////////////////////////////////////////////////////////////////
void NoesisMediaPlayer::OnMediaEvent(EMediaEvent Event)
{
	switch (Event)
	{
		case EMediaEvent::MediaBuffering:
		{
			IsBuffering = true;
			mBufferingStarted();
			break;
		}
		case EMediaEvent::MediaClosed:
		{
			break;
		}
		case EMediaEvent::MediaConnecting:
		{
			break;
		}
		case EMediaEvent::MediaOpened:
		{
			Opened = true;
			break;
		}
		case EMediaEvent::MediaOpenFailed:
		{
			mMediaFailed("Media Open failed");
			break;
		}
		case EMediaEvent::PlaybackEndReached:
		{
			Ended = true;
			mMediaEnded();
			break;
		}
		case EMediaEvent::PlaybackResumed:
		{
			if (IsBuffering)
			{
				IsBuffering = false;
				mBufferingEnded();
			}
			if (SoundComponent != nullptr)
			{
				SoundComponent->Start();
			}
			break;
		}
		case EMediaEvent::PlaybackSuspended:
		{
			if (SoundComponent != nullptr)
			{
				SoundComponent->Stop();
			}
			break;
		}
		case EMediaEvent::SeekCompleted:
		{
			break;
		}
		case EMediaEvent::TracksChanged:
		{
			break;
		}
		default: NS_ASSERT_UNREACHABLE;
	}
}
