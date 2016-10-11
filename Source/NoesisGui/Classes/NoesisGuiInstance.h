////////////////////////////////////////////////////////////////////////////////////////////////////
// Noesis Engine - http://www.noesisengine.com
// Copyright (c) 2009-2010 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#pragma once

// CoreUObject includes
#include "UObject/UObject.h"

// Generated header include
#include "NoesisGuiInstance.generated.h"

UCLASS(Blueprintable)
class NOESISGUI_API UNoesisGuiInstance : public UObject
{
	GENERATED_UCLASS_BODY()

	Noesis::Ptr<Noesis::FrameworkElement> Xaml;
	Noesis::Ptr<Noesis::Gui::VGContext> VgContext;
	Noesis::Ptr<Noesis::Gui::IView> XamlView;
	class FNoesisGuiRenderDevice* NoesisGuiRenderDevice;
	float Left;
	float Top;
	float Width;
	float Height;

	TMap<Noesis::Core::BaseComponent*, class UNoesisGuiBaseComponent*> ComponentMap;

	UPROPERTY(Transient)
	TArray<class UNoesisGuiBaseComponent*> CreatedComponents;

	TMap<Noesis::Core::Interface*, class UNoesisGuiInterface*> InterfaceMap;

	UPROPERTY(Transient)
	TArray<class UNoesisGuiInterface*> CreatedInterfaces;

	UPROPERTY()
	class UNoesisGuiXaml* BaseXaml;

	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	void InitInstance();

	UFUNCTION(BlueprintImplementableEvent, Category = "NoesisGui")
	void EventInitInstance();

	void Update(float InLeft, float InTop, float InWidth, float InHeight);
	void DrawOffscreen_RenderThread(FRHICommandListImmediate& RHICmdList, FTexture2DRHIParamRef BackBuffer, FTexture2DRHIParamRef DepthStencilTarget);
	void Draw_RenderThread(FRHICommandListImmediate& RHICmdList, FTexture2DRHIParamRef BackBuffer, FTexture2DRHIParamRef DepthStencilTarget);

	void MouseButtonDown(FVector2D Position, FKey Button);
	void MouseButtonUp(FVector2D Position, FKey Button);
	void MouseDoubleClick(FVector2D Position, FKey Button);
	void MouseMove(FVector2D Position);
	void MouseWheel(FVector2D Position, float WheelDelta);

	void KeyDown(uint32 Key);
	void KeyUp(uint32 Key);
	void Char(TCHAR Character);

	FVector2D GetSize() const;

	void SetComponentFor(Noesis::Core::BaseComponent* NoesisComponent, class UNoesisGuiBaseComponent* UnrealComponent);
	class UNoesisGuiBaseComponent* FindUnrealComponentForNoesisComponent(const Noesis::Core::BaseComponent* NoesisComponent);
	class UNoesisGuiBaseComponent* FindUnrealComponentForNoesisComponent(const Noesis::Core::Ptr<Noesis::Core::BaseComponent> NoesisComponent);
	void SetInterfaceFor(Noesis::Core::Interface* NoesisInterface, class UNoesisGuiInterface* UnrealInterface);
	class UNoesisGuiInterface* FindUnrealInterfaceForNoesisInterface(const Noesis::Core::Interface* NoesisInterface);
	class UNoesisGuiInterface* FindUnrealInterfaceForNoesisInterface(const Noesis::Core::Ptr<Noesis::Core::Interface> NoesisInterface);

	// UObject interface
	virtual class UWorld* GetWorld() const override;
	virtual void BeginDestroy() override;
	// End of UObject interface
};
