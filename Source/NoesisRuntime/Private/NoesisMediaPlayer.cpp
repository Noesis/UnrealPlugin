////////////////////////////////////////////////////////////////////////////////////////////////////
// NoesisGUI - http://www.noesisengine.com
// Copyright (c) 2013 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////


#include "NoesisMediaPlayer.h"

// Core includes
#include "CoreMinimal.h"
#include "Misc/EngineVersionComparison.h"
#include "Misc/CoreDelegates.h"

// CoreUObject includes
#include "UObject/Package.h"

// Engine includes
#include "AudioDevice.h"
#include "AudioDeviceManager.h"
#include "TextureResource.h"
#include "Engine/Texture2D.h"

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

// RHI includes
#include "RHIResources.h"

#include "NsApp/MediaElement.h"


////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////
NoesisMediaPlayer::NoesisMediaPlayer(NoesisApp::MediaElement* Owner, const Noesis::Uri& Uri, void*):
	MediaPlayer(nullptr), MediaTexture(nullptr), SoundComponent(nullptr),
	TextureSource(*new Noesis::TextureSource()), View(nullptr), Volume(0.5f), Position(0.0),
	Opened(false), Ended(false), KeepPlaying(false), IsBuffering(false)
{
	MediaPlayer = NewObject<UMediaPlayer>(GetTransientPackage(), NAME_None, RF_Transient | RF_Public);
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

	FString VideoPath = NsProviderUriToAssetPath(Uri);
	UMediaSource* MediaSource = LoadObject<UMediaSource>(nullptr, *VideoPath, nullptr, LOAD_NoWarn);
	if (MediaSource != nullptr && MediaPlayer->OpenSource(MediaSource))
	{
		MediaPlayer->OnMediaEvent().AddRaw(this, &NoesisMediaPlayer::OnMediaEvent);

		View = Owner->GetView();
		View->Rendering() += Noesis::MakeDelegate(this, &NoesisMediaPlayer::OnRendering);
	}
	else if (MediaPlayer->OpenFile(UTF8_TO_TCHAR(Uri.Str())))
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
	MediaPlayer->Close();
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
}

////////////////////////////////////////////////////////////////////////////////////////////////////
void NoesisMediaPlayer::Pause()
{
	KeepPlaying = false;
}

////////////////////////////////////////////////////////////////////////////////////////////////////
void NoesisMediaPlayer::Stop()
{
	KeepPlaying = false;
	MediaPlayer->Rewind();
}

////////////////////////////////////////////////////////////////////////////////////////////////////
Noesis::ImageSource* NoesisMediaPlayer::GetTextureSource() const
{
	return TextureSource;
}

////////////////////////////////////////////////////////////////////////////////////////////////////
void NoesisMediaPlayer::OnRendering(Noesis::IView*)
{
	// Raise MediaOpened when texture is correctly created
	if (Opened && MediaTexture->GetWidth() > 2 && MediaTexture->GetHeight() > 2)
	{
		TextureSource->SetTexture(FNoesisRenderDevice::CreateTexture(MediaTexture));

		// Some platforms need looping to be enabled in order to work correctly:
		// Windows: The texture resource is discarded when the media ends.
		// PS4/5: sceAvPlayerStop is called when the media ends, leaving the player in an unrecoverable state.
		// Some platforms need looping to be disabled in order to work correctly:
		// Switch: It never sends the PlaybackEndReached if set to looping.
		bool NeedsLooping = FCStringAnsi::Strcmp(FPlatformProperties::IniPlatformName(), "Switch") != 0;

		// Set here instead of constructor because some implementations ignore it if MediaOpened is not called
		MediaPlayer->SetLooping(NeedsLooping);

		mMediaOpened();
		Opened = false;
	}

	// Raise MediaEnded
	if (Ended)
	{
		mMediaEnded();
		Ended = false;
	}

	// Check if we need to continue playing or player has been paused/stopped
	if (KeepPlaying)
	{
		if (!MediaPlayer->IsPlaying())
		{
			MediaPlayer->Play();
		}
	}
	else
	{
		MediaPlayer->Pause();
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
			/*if (KeepPlaying)
			{
				MediaPlayer->Play();
			}*/
			break;
		}
		case EMediaEvent::TracksChanged:
		{
			break;
		}
		default: NS_ASSERT_UNREACHABLE;
	}
}
