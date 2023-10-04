////////////////////////////////////////////////////////////////////////////////////////////////////
// NoesisGUI - http://www.noesisengine.com
// Copyright (c) 2013 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#include "NoesisWorldUIComponent.h"

// UMG includes
#include "Blueprint/UserWidget.h"

// NoesisRuntime includes
#include "NoesisSupport.h"
#include "NoesisTypeClass.h"
#include "NoesisXaml.h"

UNoesisWorldUIComponent::UNoesisWorldUIComponent(): Xaml(nullptr), Scale(1.0f), Center(true)
{
	PrimaryComponentTick.bCanEverTick = true;
}

void UNoesisWorldUIComponent::Add3DElement()
{
	Element = Noesis::DynamicPtrCast<Noesis::FrameworkElement>(Xaml->LoadXaml());
	if (Element != nullptr)
	{
		Noesis::MatrixTransform3D* Transform3D = Noesis::DynamicCast<Noesis::MatrixTransform3D*>(Element->GetTransform3D());
		if (Transform3D == nullptr)
		{
			Transform3D = new Noesis::MatrixTransform3D();
			Element->SetTransform3D(Transform3D);
			Transform3D->Release();
		}
		TransformUpdatedDelegateHandle = TransformUpdated.AddUObject(this, &UNoesisWorldUIComponent::OnTransformUpdated);
		UNoesisInstance::Add3DElement(GetWorld(), Element);

		OnTransformUpdated(this, EUpdateTransformFlags::None, ETeleportType::None);
	}
}

void UNoesisWorldUIComponent::Remove3DElement()
{
	if (Element != nullptr)
	{
		UNoesisInstance::Remove3DElement(GetWorld(), Element);
		TransformUpdated.Remove(TransformUpdatedDelegateHandle);
		Element.Reset();
	}
}

void UNoesisWorldUIComponent::BeginPlay()
{
	Super::BeginPlay();

	Add3DElement();
}

void UNoesisWorldUIComponent::EndPlay(const EEndPlayReason::Type EndPlayReason)
{
	Remove3DElement();

	Super::EndPlay(EndPlayReason);
}

void UNoesisWorldUIComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	FTransform Transform = GetComponentToWorld();
	APlayerController* PlayerController = GetWorld()->GetFirstPlayerController();
	FVector MonoLocation;
	FRotator MonoRotation;
	PlayerController->GetPlayerViewPoint(MonoLocation, MonoRotation);
	FVector CameraForward = MonoRotation.RotateVector(FVector(-1.0f, 0.0f, 0.0f));
	int32 ZIndex = (int32)CameraForward.Dot(Transform.GetLocation() - MonoLocation);
	Element->SetValue<int32>(Noesis::Panel::ZIndexProperty, ZIndex);
}

void UNoesisWorldUIComponent::OnTransformUpdated(USceneComponent*, EUpdateTransformFlags UpdateTransformFlags, ETeleportType Teleport)
{
	FTransform Transform = GetComponentToWorld();
	FMatrix Matrix = Transform.ToMatrixWithScale();

	/// Transform = BaseChange * UnrealTransform * Inverse(BaseChange), where
	/// BaseChange = Matrix4(
	///		 0.f, -1.f,  0.f, 0.f,
	///		 0.f,  0.f, -1.f, 0.f,
	///		-1.f,  0.f,  0.f, 0.f,
	///		 0.f,  0.f,  0.f, 1.f
	///	);
	/// BaseChange transforms from Unreal's coordinate system to what we need.
	/// Doing it this way we can skip a lot of multiplies by 0.0f and 1.0f.

	 Noesis::Transform3 NoesisTransform(
		 Matrix.M[1][1],  Matrix.M[1][2],  Matrix.M[1][0],
		 Matrix.M[2][1],  Matrix.M[2][2],  Matrix.M[2][0],
		 Matrix.M[0][1],  Matrix.M[0][2],  Matrix.M[0][0],
		-Matrix.M[3][1], -Matrix.M[3][2], -Matrix.M[3][0]
	);

	float OffsetX = 0.0f;
	float OffsetY = 0.0f;

	if (Center)
	{
		Element->Measure(Noesis::Size(FLT_INF, FLT_INF));
		OffsetX = -0.5f * Element->GetDesiredSize().width;
		OffsetY = -0.5f * Element->GetDesiredSize().height;
	}

	Noesis::Transform3 OffsetScale = Noesis::Transform3::Trans(OffsetX, OffsetY, 0.0f) * Noesis::Transform3::Scale(Scale, Scale, Scale);

	Noesis::MatrixTransform3D* Transform3D = Noesis::DynamicCast<Noesis::MatrixTransform3D*>(Element->GetTransform3D());
	Transform3D->SetMatrix(OffsetScale * NoesisTransform);
}

void UNoesisWorldUIComponent::SetDataContext(UObject* InDataContext)
{
	if (Element)
	{
		Noesis::Ptr<Noesis::BaseComponent> DataContext = NoesisCreateComponentForUObject(InDataContext);
		Element->SetDataContext(DataContext);
	}
}
