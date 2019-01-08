#include "NoesisResourceResolver.h"

#if WITH_EDITOR
#include "ObjectTools.h"
#endif

FString UNoesisResourceResolver::ResolveName(const FString& Name, const ENoesisResourceType ResourceType /*= ENoesisResourceType::NRT_Unknown*/) const
{
#if WITH_EDITOR
	if (ResourceType == ENoesisResourceType::NRT_Font)
		return ObjectTools::SanitizeObjectName(Name + TEXT("_Font"));
#endif

	return Name;
}

FString UNoesisResourceResolver::ResolvePath(const FString& Path, const ENoesisResourceType ResourceType /*= ENoesisResourceType::NRT_Unknown*/) const
{
	// Do nothing for default implementation
	return Path;
}

