////////////////////////////////////////////////////////////////////////////////////////////////////
// NoesisGUI - http://www.noesisengine.com
// Copyright (c) 2013 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#pragma once

// Core includes
#include "CoreMinimal.h"

// SlateCore includes
#include "Widgets/DeclarativeSyntaxSupport.h"
#include "Widgets/SCompoundWidget.h"

// Noesis
#include "NsCore/Delegate.h"
#include "NsGui/Uri.h"

class UNoesisStudioInstance;

struct StudioOptions
{
    template<class T> using Ptr = Noesis::Ptr<T>;
    template<class T> using Delegate = Noesis::Delegate<T>;

    FString ProjectPath;

    // Invoked when a new file is created by Studio
    Delegate<void(const Noesis::Uri& uri)> FileCreated;

    // Invoked when an existing file is modified by Studio
    Delegate<void(const Noesis::Uri& uri)> FileWritten;

    // Invoked when a file is moved or renamed by Studio
    Delegate<void(const Noesis::Uri& src, const Noesis::Uri& dst)> FileMoved;

    // Invoked when the save state of the project changes
    Delegate<void(bool hasUnsavedChanges)> SaveStateChanged;

    // Invoked when Studio requests to close
    Delegate<void()> Exit;
};

class SNoesisStudioWidget : public SCompoundWidget
{
	SLATE_BEGIN_ARGS(SNoesisStudioWidget) {}
		SLATE_ATTRIBUTE(StudioOptions, Options)
	SLATE_END_ARGS()

	SNoesisStudioWidget();
	virtual ~SNoesisStudioWidget();

	void Construct(const FArguments& InArgs);

    void SaveAllChanges();
    void DiscardAllChanges();

	// SWidget interface
	virtual void Tick(const FGeometry& AllottedGeometry, const double InCurrentTime, const float InDeltaTime) override;
    virtual FNavigationReply OnNavigation(const FGeometry& MyGeometry, const FNavigationEvent& InNavigationEvent) override;
    // End of SWidget interface

private:
	TSharedPtr<class SBox> ViewBox;
	TWeakPtr<SWidget> ViewSlateWidget;
    UNoesisStudioInstance* StudioInstance;
};
