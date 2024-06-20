////////////////////////////////////////////////////////////////////////////////////////////////////
// NoesisGUI - http://www.noesisengine.com
// Copyright (c) 2013 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#include "NoesisRive.h"

// CoreUObject includes
#include "Misc/PackageName.h"
#include "UObject/Package.h"

// Engine includes
#include "EditorFramework/AssetImportData.h"
#include "Engine/World.h"

// NoesisRuntime includes
#include "NoesisThumbnailRenderer.h"

// NoesisGUI includes
#include "NsGui/Border.h"
#include "NsGui/Brushes.h"
#include "NsGui/SolidColorBrush.h"
#include "NsGui/Uri.h"
#include "NsApp/RiveControl.h"

UNoesisRive::UNoesisRive(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
}

#if WITH_EDITORONLY_DATA
void UNoesisRive::PostInitProperties()
{
	if (!HasAnyFlags(RF_ClassDefaultObject))
	{
		AssetImportData = NewObject<UAssetImportData>(this, TEXT("AssetImportData"));
	}

	Super::PostInitProperties();
}

#if UE_VERSION_OLDER_THAN(5, 4, 0)
void UNoesisRive::GetAssetRegistryTags(TArray<FAssetRegistryTag>& OutTags) const
{
	if (AssetImportData)
	{
		OutTags.Add(FAssetRegistryTag(SourceFileTagName(), AssetImportData->GetSourceData().ToJson(), FAssetRegistryTag::TT_Hidden));
	}

	Super::GetAssetRegistryTags(OutTags);
}
#else
void UNoesisRive::GetAssetRegistryTags(FAssetRegistryTagsContext Context) const
{
	if (AssetImportData)
	{
		Context.AddTag(FAssetRegistryTag(SourceFileTagName(), AssetImportData->GetSourceData().ToJson(), FAssetRegistryTag::TT_Hidden));
	}

	Super::GetAssetRegistryTags(Context);
}
#endif
#endif // WITH_EDITORONLY_DATA

#if WITH_EDITOR
void UNoesisRive::RenderThumbnail(FIntRect ViewportRect, const FTexture2DRHIRef& BackBuffer)
{
	if (ThumbnailView == nullptr)
	{
		UObject* Package = GetOutermost();
		FString PackageRoot, PackagePath, PackageName;
		FPackageName::SplitLongPackageName(Package->GetPathName(), PackageRoot, PackagePath, PackageName, false);
		FString Uri = PackageRoot.LeftChop(1) + TEXT(";component/") + PackagePath + PackageName + TEXT(".riv");

		Noesis::Ptr<NoesisApp::RiveControl> Rive = Noesis::MakePtr<NoesisApp::RiveControl>();
		Rive->SetSource(TCHAR_TO_UTF8(*Uri));
		Rive->SetStretch(Noesis::Stretch_Uniform);

		Noesis::Ptr<Noesis::Border> Root = Noesis::MakePtr<Noesis::Border>();
		Root->SetChild(Rive);

		ThumbnailView = FNoesisThumbnailRenderer::CreateView(Root);
	}

	UWorld* World = GetWorld();
	if (World == nullptr) World = GWorld.GetReference();
	FNoesisThumbnailRenderer::RenderView(ThumbnailView, World, ViewportRect, BackBuffer);
}

void UNoesisRive::DestroyThumbnailRenderData()
{
	ThumbnailView.Reset();
}
#endif
