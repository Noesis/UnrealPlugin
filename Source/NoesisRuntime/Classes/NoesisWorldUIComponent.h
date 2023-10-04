////////////////////////////////////////////////////////////////////////////////////////////////////
// NoesisGUI - http://www.noesisengine.com
// Copyright (c) 2013 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#pragma once

// Core includes
#include "CoreMinimal.h"

// Engine includes
#include "Components/SceneComponent.h"

// NoesisRuntime includes
#include "NoesisInstance.h"

// Generated header include
#include "NoesisWorldUIComponent.generated.h"

UCLASS( BlueprintType, ClassGroup=(Noesis), meta=(BlueprintSpawnableComponent) )
class NOESISRUNTIME_API UNoesisWorldUIComponent: public USceneComponent
{
	GENERATED_BODY()

public:	
	UNoesisWorldUIComponent();

	void Add3DElement();
	void Remove3DElement();

protected:
	virtual void BeginPlay() override;
	virtual void EndPlay(const EEndPlayReason::Type EndPlayReason) override;

public:	
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	void OnTransformUpdated(USceneComponent* UpdatedComponent, EUpdateTransformFlags UpdateTransformFlags, ETeleportType Teleport);

	UPROPERTY(EditAnywhere, Category = Noesis)
	UNoesisXaml* Xaml;

	UPROPERTY(EditAnywhere, Category = Noesis)
	float Scale;

	UPROPERTY(EditAnywhere, Category = Noesis)
	FVector Offset;

	UPROPERTY(EditAnywhere, Category = Noesis)
	bool Center;

	UFUNCTION(BlueprintCallable, Category = "NoesisGUI")
	void SetDataContext(UObject* DataContext);

	Noesis::Ptr<Noesis::FrameworkElement> Element;
	FDelegateHandle TransformUpdatedDelegateHandle;
};
