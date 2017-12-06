////////////////////////////////////////////////////////////////////////////////////////////////////
// NoesisGUI - http://www.noesisengine.com
// Copyright (c) 2013 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#pragma once

NOESISRUNTIME_API Noesis::TypeClass* NoesisCreateTypeClassForUClass(UClass*);
NOESISRUNTIME_API Noesis::TypeEnum* NoesisCreateTypeEnumForUEnum(UEnum*);
NOESISRUNTIME_API void NoesisDestroyTypeClassForBlueprint(UBlueprint*);
NOESISRUNTIME_API void NoesisDestroyAllTypes();
NOESISRUNTIME_API Noesis::Ptr<Noesis::BaseComponent> NoesisCreateComponentForUStruct(UScriptStruct*, void*);
NOESISRUNTIME_API Noesis::Ptr<Noesis::BaseComponent> NoesisCreateComponentForUObject(UObject*);
NOESISRUNTIME_API class UObject* NoesisCreateUObjectForComponent(Noesis::BaseComponent*);
NOESISRUNTIME_API void NoesisNotifyPropertyChanged(UObject*, FName);
NOESISRUNTIME_API void NoesisNotifyArrayPropertyChanged(UObject*, FName);
NOESISRUNTIME_API void NoesisNotifyArrayPropertyAdd(void*);
NOESISRUNTIME_API void NoesisNotifyArrayPropertyChanged(void*);
NOESISRUNTIME_API void NoesisNotifyArrayPropertyAppend(void*, int32);
NOESISRUNTIME_API void NoesisNotifyArrayPropertyInsert(void*, int32);
NOESISRUNTIME_API void NoesisNotifyArrayPropertyRemove(void*, int32);
NOESISRUNTIME_API void NoesisNotifyArrayPropertyClear(void*);
NOESISRUNTIME_API void NoesisNotifyArrayPropertyResize(void*);
NOESISRUNTIME_API void NoesisNotifyArrayPropertySet(void*, int32);
NOESISRUNTIME_API void NoesisGarbageCollected();
