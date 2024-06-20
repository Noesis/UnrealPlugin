////////////////////////////////////////////////////////////////////////////////////////////////////
// NoesisGUI - http://www.noesisengine.com
// Copyright (c) 2013 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#pragma once

// Core includes
#include "CoreMinimal.h"

// Media includes
#include "IMediaEventSink.h"

// Noesis includes
#include "NoesisSDK.h"
#include "NsApp/MediaPlayer.h"


////////////////////////////////////////////////////////////////////////////////////////////////////
namespace Noesis
{
NS_INTERFACE IView;
}
namespace NoesisApp
{
class MediaElement;
}

////////////////////////////////////////////////////////////////////////////////////////////////////
/// Implementatation of Noesis MediaPlayer for Unreal
////////////////////////////////////////////////////////////////////////////////////////////////////
class NoesisMediaPlayer final: public NoesisApp::MediaPlayer
{
public:
	NoesisMediaPlayer(NoesisApp::MediaElement* Owner, const Noesis::Uri& Uri, void* User);
	~NoesisMediaPlayer();

	uint32_t GetWidth() const override;
	uint32_t GetHeight() const override;
	bool CanPause() const override;
	bool HasAudio() const override;
	bool HasVideo() const override;
	double GetDuration() const override;
	double GetPosition() const override;
	void SetPosition(double value) override;
	float GetSpeedRatio() const override;
	void SetSpeedRatio(float value) override;
	float GetVolume() const override;
	void SetVolume(float value) override;
	bool GetIsMuted() const override;
	void SetIsMuted(bool value) override;
	void Play() override;
	void Pause() override;
	void Stop() override;
	Noesis::ImageSource* GetTextureSource() const override;

private:
	void OnRendering(Noesis::IView* View);
	void OnMediaEvent(EMediaEvent Event);

private:
	class UMediaPlayer* MediaPlayer;
	class UMediaTexture* MediaTexture;
	class UMediaSoundComponent* SoundComponent;

	Noesis::Ptr<Noesis::TextureSource> TextureSource;
	Noesis::IView* View;
	float Rate;
	float Volume;
	float Position;
	bool Opened;
	bool Ended;
	bool KeepPlaying;
	bool IsBuffering;
};
