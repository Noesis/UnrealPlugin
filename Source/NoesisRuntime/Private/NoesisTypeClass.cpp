////////////////////////////////////////////////////////////////////////////////////////////////////
// NoesisGUI - http://www.noesisengine.com
// Copyright (c) 2013 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#include "NoesisTypeClass.h"

// Core includes
#include "UObject/PropertyPortFlags.h"

// CoreUObject includes
#include "UObject/TextProperty.h"
#include "UObject/UObjectIterator.h"
#include "UObject/UObjectThreadContext.h"

// Engine includes
#include "Engine/Texture2D.h"
#include "Engine/TextureRenderTarget2D.h"
#include "Engine/Blueprint.h"
#include "Engine/UserDefinedStruct.h"
#include "Engine/UserDefinedEnum.h"

// AssetRegistry includes
#include "AssetRegistryModule.h"
#include "IAssetRegistry.h"

// NoesisRuntime includes
#include "NoesisSupport.h"
#include "NoesisStructs.h"
#include "NoesisRuntimeModule.h"
#include "NoesisBaseComponent.h"
#include "NoesisXaml.h"

// Noesis includes
#include "NoesisSDK.h"

DECLARE_CYCLE_STAT(TEXT("NoesisNotifyPropertyChanged"), STAT_NoesisNotifyPropertyChanged, STATGROUP_Noesis);
DECLARE_CYCLE_STAT(TEXT("NoesisNotifyArrayPropertyAdd"), STAT_NoesisNotifyArrayPropertyAdd, STATGROUP_Noesis);
DECLARE_CYCLE_STAT(TEXT("NoesisNotifyArrayPropertyChanged"), STAT_NoesisNotifyArrayPropertyChanged, STATGROUP_Noesis);
DECLARE_CYCLE_STAT(TEXT("NoesisNotifyArrayPropertyAppend"), STAT_NoesisNotifyArrayPropertyAppend, STATGROUP_Noesis);
DECLARE_CYCLE_STAT(TEXT("NoesisNotifyArrayPropertyInsert"), STAT_NoesisNotifyArrayPropertyInsert, STATGROUP_Noesis);
DECLARE_CYCLE_STAT(TEXT("NoesisNotifyArrayPropertyRemove"), STAT_NoesisNotifyArrayPropertyRemove, STATGROUP_Noesis);
DECLARE_CYCLE_STAT(TEXT("NoesisNotifyArrayPropertyClear"), STAT_NoesisNotifyArrayPropertyClear, STATGROUP_Noesis);
DECLARE_CYCLE_STAT(TEXT("NoesisNotifyArrayPropertyResize"), STAT_NoesisNotifyArrayPropertyResize, STATGROUP_Noesis);
DECLARE_CYCLE_STAT(TEXT("NoesisNotifyArrayPropertySet"), STAT_NoesisNotifyArrayPropertySet, STATGROUP_Noesis);
DECLARE_CYCLE_STAT(TEXT("NoesisGarbageCollected"), STAT_NoesisGarbageCollected, STATGROUP_Noesis);

TMap<UObject*, Noesis::Ptr<Noesis::BaseComponent> > ObjectMap;
TMap<UStruct*, TPair<Noesis::TypeClass*, const char*> > ClassMap;
TMap<UEnum*, TPair<Noesis::TypeEnum*, const char*> > EnumMap;
TMap<uint32, class NoesisTypeEnum*> ConverterIdMap;
TMap<void*, class NoesisArrayWrapperBase*> ArrayMap;
TMap<FString, FString> RegisterNameMap;

class NoesisObjectWrapper;
class NoesisStructWrapper;
class NoesisEnumWrapper;

const char* GetPersistentName(FString Name)
{
	Noesis::Symbol Symbol(TCHARToNsString(*Name).Str());
	return Symbol.Str();
}

FString RegisterNameFromPath(FString Path)
{
	static FString ProjectName = FApp::GetProjectName();

	check(Path.StartsWith(TEXT("/")));
	Path = Path.RightChop(1);
	int32 FirstSlashIndex;
	Path.FindChar(TEXT('/'), FirstSlashIndex);
	int32 DotIndex;
	Path.FindLastChar(TEXT('.'), DotIndex);

	FString RegisterName = ProjectName + TEXT(".");
	if (!Path.StartsWith(TEXT("Script")))
	{
		RegisterName += Path.Left(DotIndex).RightChop(FirstSlashIndex + 1).Replace(TEXT("/"), TEXT("."));
	}
	else
	{
		RegisterName += Path.RightChop(DotIndex + 1);
	}
	return RegisterName;
}

class NoesisTypeEnum : public Noesis::TypeEnum
{
public:
	NoesisTypeEnum(Noesis::Symbol Name)
		: Noesis::TypeEnum(Name)
	{
	}

	bool GetValueObject(Noesis::Symbol Id, Noesis::Ptr<Noesis::BoxedValue>& Value) const override;
};

class NoesisEnumWrapper : public Noesis::Boxed<int32>
{
public:
	NoesisEnumWrapper(NoesisTypeEnum* InTypeEnum, int64 InValue)
		: Noesis::Boxed<int32>((int32)InValue), TypeEnum(InTypeEnum)
	{
		check(INT_MIN <= InValue && InValue <= INT_MAX);
	}

	virtual const Noesis::Type* GetValueType() const override
	{
		return TypeEnum;
	}

	NoesisTypeEnum* TypeEnum;

	NS_IMPLEMENT_INLINE_REFLECTION_(NoesisEnumWrapper, Noesis::Boxed<int32>)
};

bool NoesisTypeEnum::GetValueObject(Noesis::Symbol Id, Noesis::Ptr<Noesis::BoxedValue>& Value) const
{
	int32 Val;
	if (!HasName(Id, Val))
		return false;
	Value = Noesis::Ptr<Noesis::BoxedValue>(*new NoesisEnumWrapper((NoesisTypeEnum*)this, Val));
	return true;
}

class NoesisEnumConverter : public Noesis::BaseEnumConverter
{
public:
	NoesisEnumConverter(const Noesis::TypeEnum* InTypeEnum)
		: Noesis::BaseEnumConverter(InTypeEnum), TypeEnum(InTypeEnum)
	{
	}

	virtual Noesis::Ptr<Noesis::BaseComponent> Box(uint32 Value) const override
	{
		return *new NoesisEnumWrapper((NoesisTypeEnum*)TypeEnum, Value);
	}

	virtual uint32 Unbox(Noesis::BaseComponent* Value) const override
	{
		return (uint32)Noesis::Boxing::Unbox<int32>(Value);
	}

	const Noesis::TypeEnum* TypeEnum;

	NS_IMPLEMENT_INLINE_REFLECTION_(NoesisEnumConverter, Noesis::BaseEnumConverter)
};

template<class T>
Noesis::Ptr<Noesis::BaseComponent> GetProperty(void* BasePointer, UProperty* Property)
{
	check(Property->IsA<TProperty_Numeric<T> >());
	TProperty_Numeric<T>* NumericProperty = (TProperty_Numeric<T>*)Property;
	const T& Value = NumericProperty->GetPropertyValue(NumericProperty->template ContainerPtrToValuePtr<void>(BasePointer));
	return Noesis::Boxing::Box<T>(Value);
}

template<class T>
void SetProperty(void* BasePointer, UProperty* Property, Noesis::BaseComponent* Value)
{
	Noesis::Boxed<T>* BoxedValue = Noesis::DynamicCast<Noesis::Boxed<T>*>(Value);
	if (BoxedValue)
	{
		check(Property->IsA<TProperty_Numeric<T> >());
		TProperty_Numeric<T>* NumericProperty = (TProperty_Numeric<T>*)Property;
		NumericProperty->SetPropertyValue(NumericProperty->template ContainerPtrToValuePtr<void>(BasePointer), Noesis::Boxing::Unbox<T>(BoxedValue));
	}
}

template<>
Noesis::Ptr<Noesis::BaseComponent> GetProperty<NoesisEnumWrapper>(void* BasePointer, UProperty* Property)
{
	if (UEnumProperty* EnumProperty = Cast<UEnumProperty>(Property))
	{
		Noesis::TypeEnum* TypeEnum = NoesisCreateTypeEnumForUEnum(EnumProperty->GetEnum());
		UNumericProperty* UnderlyingProperty = EnumProperty->GetUnderlyingProperty();
		check(UnderlyingProperty->IsInteger());
		int64 Value = UnderlyingProperty->GetSignedIntPropertyValue(EnumProperty->template ContainerPtrToValuePtr<void>(BasePointer));
		return *new NoesisEnumWrapper((NoesisTypeEnum*)TypeEnum, Value);
	}
	else 
	{
		UByteProperty* ByteProperty = Cast<UByteProperty>(Property);
		check(ByteProperty);
		if (ByteProperty->Enum)
		{
			Noesis::TypeEnum* TypeEnum = NoesisCreateTypeEnumForUEnum(ByteProperty->Enum);
			const uint8& Value = ByteProperty->GetPropertyValue(ByteProperty->template ContainerPtrToValuePtr<void>(BasePointer));
			return *new NoesisEnumWrapper((NoesisTypeEnum*)TypeEnum, (int64)Value);
		}
	}

	return Noesis::Ptr<Noesis::BaseComponent>();
}

template<>
void SetProperty<NoesisEnumWrapper>(void* BasePointer, UProperty* Property, Noesis::BaseComponent* Value)
{
	NoesisEnumWrapper* BoxedValue = Noesis::DynamicCast<NoesisEnumWrapper*>(Value);
	if (BoxedValue)
	{
		if (UEnumProperty* EnumProperty = Cast<UEnumProperty>(Property))
		{
			UNumericProperty* UnderlyingProperty = EnumProperty->GetUnderlyingProperty();
			check(UnderlyingProperty->IsInteger());
			UnderlyingProperty->SetIntPropertyValue(EnumProperty->template ContainerPtrToValuePtr<void>(BasePointer), (int64)Noesis::Boxing::Unbox<int32>(BoxedValue));
		}
		else
		{
			check(Property->IsA<UByteProperty>());
			UByteProperty* ByteProperty = (UByteProperty*)Property;
			ByteProperty->SetPropertyValue(ByteProperty->template ContainerPtrToValuePtr<void>(BasePointer), Noesis::Boxing::Unbox<int32>(BoxedValue));
		}
	}
}

template<>
Noesis::Ptr<Noesis::BaseComponent> GetProperty<Noesis::Color>(void* BasePointer, UProperty* Property)
{
	check(Property->IsA<UStructProperty>());
	UStructProperty* StructProperty = (UStructProperty*)Property;
	check(StructProperty->Struct->GetFName() == NAME_Color);
	const FColor& Value = *StructProperty->ContainerPtrToValuePtr<FColor>(BasePointer);
#if PLATFORM_LITTLE_ENDIAN
	return Noesis::Boxing::Box<Noesis::Color>(Noesis::Color::FromPackedBGRA(Value.DWColor()));
#else // PLATFORM_LITTLE_ENDIAN
	return Noesis::Boxing::Box<Noesis::Color>(Noesis::Color(Value.R, Value.G, VBalue.B, Value.A));
#endif
}

template<>
void SetProperty<Noesis::Color>(void* BasePointer, UProperty* Property, Noesis::BaseComponent* Value)
{
	Noesis::Boxed<Noesis::Color>* BoxedValue = Noesis::DynamicCast<Noesis::Boxed<Noesis::Color>*>(Value);
	if (BoxedValue)
	{
		check(Property->IsA<UStructProperty>());
		UStructProperty* StructProperty = (UStructProperty*)Property;
		check(StructProperty->Struct->GetFName() == NAME_Color);
		Noesis::Color UnboxedValue = Noesis::Boxing::Unbox<Noesis::Color>(BoxedValue);
#if PLATFORM_LITTLE_ENDIAN
		*StructProperty->ContainerPtrToValuePtr<FColor>(BasePointer) = FColor(UnboxedValue.GetPackedColorBGRA());
#else // PLATFORM_LITTLE_ENDIAN
		FColor Color = FColor(UnboxedValue.GetPackedColorBGRA());
		*StructProperty->ContainerPtrToValuePtr<FColor>(BasePointer) = FColor(Color.G, Color.R, Color.A, Color.B);
#endif
	}
}

template<>
Noesis::Ptr<Noesis::BaseComponent> GetProperty<Noesis::Point>(void* BasePointer, UProperty* Property)
{
	check(Property->IsA<UStructProperty>());
	UStructProperty* StructProperty = (UStructProperty*)Property;
	check(StructProperty->Struct->GetFName() == NAME_Vector2D);
	const FVector2D& Value = *StructProperty->ContainerPtrToValuePtr<FVector2D>(BasePointer);
	return Noesis::Boxing::Box<Noesis::Point>(Noesis::Point(Value.X, Value.Y));
}

template<>
void SetProperty<Noesis::Point>(void* BasePointer, UProperty* Property, Noesis::BaseComponent* Value)
{
	Noesis::Boxed<Noesis::Point>* BoxedValue = Noesis::DynamicCast<Noesis::Boxed<Noesis::Point>*>(Value);
	if (BoxedValue)
	{
		check(Property->IsA<UStructProperty>());
		UStructProperty* StructProperty = (UStructProperty*)Property;
		check(StructProperty->Struct->GetFName() == NAME_Vector2D);
		Noesis::Point UnboxedValue = Noesis::Boxing::Unbox<Noesis::Point>(BoxedValue);
		*StructProperty->ContainerPtrToValuePtr<FVector2D>(BasePointer) = FVector2D(UnboxedValue.x, UnboxedValue.y);
	}
}

template<>
Noesis::Ptr<Noesis::BaseComponent> GetProperty<Noesis::Rect>(void* BasePointer, UProperty* Property)
{
	check(Property->IsA<UStructProperty>());
	UStructProperty* StructProperty = (UStructProperty*)Property;
	check(StructProperty->Struct->GetName() == TEXT("NoesisRect"));
	const FNoesisRect& Value = *StructProperty->ContainerPtrToValuePtr<FNoesisRect>(BasePointer);
	return Noesis::Boxing::Box<Noesis::Rect>(Value.ToNoesis());
}

template<>
void SetProperty<Noesis::Rect>(void* BasePointer, UProperty* Property, Noesis::BaseComponent* Value)
{
	Noesis::Boxed<Noesis::Rect>* BoxedValue = Noesis::DynamicCast<Noesis::Boxed<Noesis::Rect>*>(Value);
	if (BoxedValue)
	{
		check(Property->IsA<UStructProperty>());
		UStructProperty* StructProperty = (UStructProperty*)Property;
		check(StructProperty->Struct->GetName() == TEXT("NoesisRect"));
		Noesis::Rect UnboxedValue = Noesis::Boxing::Unbox<Noesis::Rect>(BoxedValue);
		*StructProperty->ContainerPtrToValuePtr<FNoesisRect>(BasePointer) = FNoesisRect(UnboxedValue);
	}
}

template<>
Noesis::Ptr<Noesis::BaseComponent> GetProperty<Noesis::Size>(void* BasePointer, UProperty* Property)
{
	check(Property->IsA<UStructProperty>());
	UStructProperty* StructProperty = (UStructProperty*)Property;
	check(StructProperty->Struct->GetName() == TEXT("NoesisSize"));
	const FNoesisSize& Value = *StructProperty->ContainerPtrToValuePtr<FNoesisSize>(BasePointer);
	return Noesis::Boxing::Box<Noesis::Size>(Value.ToNoesis());
}

template<>
void SetProperty<Noesis::Size>(void* BasePointer, UProperty* Property, Noesis::BaseComponent* Value)
{
	Noesis::Boxed<Noesis::Size>* BoxedValue = Noesis::DynamicCast<Noesis::Boxed<Noesis::Size>*>(Value);
	if (BoxedValue)
	{
		check(Property->IsA<UStructProperty>());
		UStructProperty* StructProperty = (UStructProperty*)Property;
		check(StructProperty->Struct->GetName() == TEXT("NoesisSize"));
		Noesis::Size UnboxedValue = Noesis::Boxing::Unbox<Noesis::Size>(BoxedValue);
		*StructProperty->ContainerPtrToValuePtr<FNoesisSize>(BasePointer) = FNoesisSize(UnboxedValue);
	}
}

template<>
Noesis::Ptr<Noesis::BaseComponent> GetProperty<Noesis::Thickness>(void* BasePointer, UProperty* Property)
{
	check(Property->IsA<UStructProperty>());
	UStructProperty* StructProperty = (UStructProperty*)Property;
	check(StructProperty->Struct->GetName() == TEXT("NoesisThickness"));
	const FNoesisThickness& Value = *StructProperty->ContainerPtrToValuePtr<FNoesisThickness>(BasePointer);
	return Noesis::Boxing::Box<Noesis::Thickness>(Value.ToNoesis());
}

template<>
void SetProperty<Noesis::Thickness>(void* BasePointer, UProperty* Property, Noesis::BaseComponent* Value)
{
	Noesis::Boxed<Noesis::Thickness>* BoxedValue = Noesis::DynamicCast<Noesis::Boxed<Noesis::Thickness>*>(Value);
	if (BoxedValue)
	{
		check(Property->IsA<UStructProperty>());
		UStructProperty* StructProperty = (UStructProperty*)Property;
		check(StructProperty->Struct->GetName() == TEXT("NoesisThickness"));
		Noesis::Thickness UnboxedValue = Noesis::Boxing::Unbox<Noesis::Thickness>(BoxedValue);
		*StructProperty->ContainerPtrToValuePtr<FNoesisThickness>(BasePointer) = FNoesisThickness(UnboxedValue);
	}
}

template<>
Noesis::Ptr<Noesis::BaseComponent> GetProperty<Noesis::CornerRadius>(void* BasePointer, UProperty* Property)
{
	check(Property->IsA<UStructProperty>());
	UStructProperty* StructProperty = (UStructProperty*)Property;
	check(StructProperty->Struct->GetName() == TEXT("NoesisCornerRadius"));
	const FNoesisCornerRadius& Value = *StructProperty->ContainerPtrToValuePtr<FNoesisCornerRadius>(BasePointer);
	return Noesis::Boxing::Box<Noesis::CornerRadius>(Value.ToNoesis());
}

template<>
void SetProperty<Noesis::CornerRadius>(void* BasePointer, UProperty* Property, Noesis::BaseComponent* Value)
{
	Noesis::Boxed<Noesis::CornerRadius>* BoxedValue = Noesis::DynamicCast<Noesis::Boxed<Noesis::CornerRadius>*>(Value);
	if (BoxedValue)
	{
		check(Property->IsA<UStructProperty>());
		UStructProperty* StructProperty = (UStructProperty*)Property;
		check(StructProperty->Struct->GetName() == TEXT("NoesisCornerRadius"));
		Noesis::CornerRadius UnboxedValue = Noesis::Boxing::Unbox<Noesis::CornerRadius>(BoxedValue);
		*StructProperty->ContainerPtrToValuePtr<FNoesisCornerRadius>(BasePointer) = FNoesisCornerRadius(UnboxedValue);
	}
}

template<>
Noesis::Ptr<Noesis::BaseComponent> GetProperty<Noesis::TimeSpan>(void* BasePointer, UProperty* Property)
{
	check(Property->IsA<UStructProperty>());
	UStructProperty* StructProperty = (UStructProperty*)Property;
	check(StructProperty->Struct->GetName() == TEXT("NoesisTimeSpan"));
	const FNoesisTimeSpan& Value = *StructProperty->ContainerPtrToValuePtr<FNoesisTimeSpan>(BasePointer);
	return Noesis::Boxing::Box<Noesis::TimeSpan>(Value.ToNoesis());
}

template<>
void SetProperty<Noesis::TimeSpan>(void* BasePointer, UProperty* Property, Noesis::BaseComponent* Value)
{
	Noesis::Boxed<Noesis::TimeSpan>* BoxedValue = Noesis::DynamicCast<Noesis::Boxed<Noesis::TimeSpan>*>(Value);
	if (BoxedValue)
	{
		check(Property->IsA<UStructProperty>());
		UStructProperty* StructProperty = (UStructProperty*)Property;
		check(StructProperty->Struct->GetName() == TEXT("NoesisTimeSpan"));
		Noesis::TimeSpan UnboxedValue = Noesis::Boxing::Unbox<Noesis::TimeSpan>(BoxedValue);
		*StructProperty->ContainerPtrToValuePtr<FNoesisTimeSpan>(BasePointer) = FNoesisTimeSpan(UnboxedValue);
	}
}

template<>
Noesis::Ptr<Noesis::BaseComponent> GetProperty<Noesis::Duration>(void* BasePointer, UProperty* Property)
{
	check(Property->IsA<UStructProperty>());
	UStructProperty* StructProperty = (UStructProperty*)Property;
	check(StructProperty->Struct->GetName() == TEXT("NoesisDuration"));
	const FNoesisDuration& Value = *StructProperty->ContainerPtrToValuePtr<FNoesisDuration>(BasePointer);
	return Noesis::Boxing::Box<Noesis::Duration>(Value.ToNoesis());
}

template<>
void SetProperty<Noesis::Duration>(void* BasePointer, UProperty* Property, Noesis::BaseComponent* Value)
{
	Noesis::Boxed<Noesis::Duration>* BoxedValue = Noesis::DynamicCast<Noesis::Boxed<Noesis::Duration>*>(Value);
	if (BoxedValue)
	{
		check(Property->IsA<UStructProperty>());
		UStructProperty* StructProperty = (UStructProperty*)Property;
		check(StructProperty->Struct->GetName() == TEXT("NoesisDuration"));
		Noesis::Duration UnboxedValue = Noesis::Boxing::Unbox<Noesis::Duration>(BoxedValue);
		*StructProperty->ContainerPtrToValuePtr<FNoesisDuration>(BasePointer) = FNoesisDuration(UnboxedValue);
	}
}

template<>
Noesis::Ptr<Noesis::BaseComponent> GetProperty<Noesis::KeyTime>(void* BasePointer, UProperty* Property)
{
	check(Property->IsA<UStructProperty>());
	UStructProperty* StructProperty = (UStructProperty*)Property;
	check(StructProperty->Struct->GetName() == TEXT("NoesisKeyTime"));
	const FNoesisKeyTime& Value = *StructProperty->ContainerPtrToValuePtr<FNoesisKeyTime>(BasePointer);
	return Noesis::Boxing::Box<Noesis::KeyTime>(Value.ToNoesis());
}

template<>
void SetProperty<Noesis::KeyTime>(void* BasePointer, UProperty* Property, Noesis::BaseComponent* Value)
{
	Noesis::Boxed<Noesis::KeyTime>* BoxedValue = Noesis::DynamicCast<Noesis::Boxed<Noesis::KeyTime>*>(Value);
	if (BoxedValue)
	{
		check(Property->IsA<UStructProperty>());
		UStructProperty* StructProperty = (UStructProperty*)Property;
		check(StructProperty->Struct->GetName() == TEXT("NoesisKeyTime"));
		Noesis::KeyTime UnboxedValue = Noesis::Boxing::Unbox<Noesis::KeyTime>(BoxedValue);
		*StructProperty->ContainerPtrToValuePtr<FNoesisKeyTime>(BasePointer) = FNoesisKeyTime(UnboxedValue);
	}
}

template<>
Noesis::Ptr<Noesis::BaseComponent> GetProperty<bool>(void* BasePointer, UProperty* Property)
{
	check(Property->IsA<UBoolProperty>());
	UBoolProperty* BoolProperty = (UBoolProperty*)Property;
	bool Value = BoolProperty->GetPropertyValue(BoolProperty->ContainerPtrToValuePtr<void>(BasePointer));
	return Noesis::Boxing::Box<bool>(Value);
}

template<>
void SetProperty<bool>(void* BasePointer, UProperty* Property, Noesis::BaseComponent* Value)
{
	Noesis::Boxed<bool>* BoolValue = Noesis::DynamicCast<Noesis::Boxed<bool>*>(Value);
	if (BoolValue)
	{
		check(Property->IsA<UBoolProperty>());
		UBoolProperty* BoolProperty = (UBoolProperty*)Property;
		BoolProperty->SetPropertyValue(BoolProperty->ContainerPtrToValuePtr<void>(BasePointer), Noesis::Boxing::Unbox<bool>(BoolValue));
	}
}

template<>
Noesis::Ptr<Noesis::BaseComponent> GetProperty<Noesis::String>(void* BasePointer, UProperty* Property)
{
	if (Property->IsA<UStrProperty>())
	{
		UStrProperty* StrProperty = (UStrProperty*)Property;
		FString Value = StrProperty->GetPropertyValue(StrProperty->ContainerPtrToValuePtr<void>(BasePointer));
		return Noesis::Boxing::Box<Noesis::String>(TCHARToNsString(*Value));
	}
	else
	{
		check(Property->IsA<UTextProperty>());
		UTextProperty* TextProperty = (UTextProperty*)Property;
		FText Value = TextProperty->GetPropertyValue(TextProperty->ContainerPtrToValuePtr<void>(BasePointer));
		return Noesis::Boxing::Box<Noesis::String>(TCHARToNsString(*Value.ToString()));
	}
}

template<>
void SetProperty<Noesis::String>(void* BasePointer, UProperty* Property, Noesis::BaseComponent* Value)
{
	Noesis::Boxed<Noesis::String>* StrValue = Noesis::DynamicCast<Noesis::Boxed<Noesis::String>*>(Value);
	if (StrValue)
	{
		if (Property->IsA<UStrProperty>())
		{
			UStrProperty* StrProperty = (UStrProperty*)Property;
			StrProperty->SetPropertyValue(StrProperty->ContainerPtrToValuePtr<void>(BasePointer), NsStringToFString(Noesis::Boxing::Unbox<Noesis::String>(StrValue).Str()));
		}
		else
		{
			check(Property->IsA<UTextProperty>());
			UTextProperty* TextProperty = (UTextProperty*)Property;
			TextProperty->SetPropertyValue(TextProperty->ContainerPtrToValuePtr<void>(BasePointer), FText::FromString(NsStringToFString(Noesis::Boxing::Unbox<Noesis::String>(StrValue).Str())));
		}
	}
}

template<>
Noesis::Ptr<Noesis::BaseComponent> GetProperty<NoesisObjectWrapper>(void* BasePointer, UProperty* Property)
{
	check(Property->IsA<UObjectProperty>());
	UObjectProperty* ObjectProperty = (UObjectProperty*)Property;
	UObject* ReferencedObject = ObjectProperty->GetPropertyValue(ObjectProperty->ContainerPtrToValuePtr<void>(BasePointer));

	return NoesisCreateComponentForUObject(ReferencedObject);
}

template<>
void SetProperty<NoesisObjectWrapper>(void* BasePointer, UProperty* Property, Noesis::BaseComponent* Value)
{
	check(Property->IsA<UObjectProperty>());
	UObjectProperty* ObjectProperty = (UObjectProperty*)Property;
	UObject* Object = NoesisCreateUObjectForComponent(Noesis::Ptr<Noesis::BaseComponent>(Value));
	ObjectProperty->SetPropertyValue(ObjectProperty->ContainerPtrToValuePtr<void>(BasePointer), Object);
}

template<>
Noesis::Ptr<Noesis::BaseComponent> GetProperty<NoesisStructWrapper>(void* BasePointer, UProperty* Property)
{
	check(Property->IsA<UStructProperty>());

	UStructProperty* StructProperty = (UStructProperty*)Property;
	void* Data = StructProperty->ContainerPtrToValuePtr<void>(BasePointer);

	return NoesisCreateComponentForUStruct(StructProperty->Struct, Data);
}

void AssignStruct(void*, UStructProperty*, Noesis::BaseComponent*);

template<>
void SetProperty<NoesisStructWrapper>(void* BasePointer, UProperty* Property, Noesis::BaseComponent* Value)
{
	check(Property->IsA<UStructProperty>());

	AssignStruct(BasePointer, (UStructProperty*)Property, Value);
}

template<>
Noesis::Ptr<Noesis::BaseComponent> GetProperty<Noesis::TextureSource>(void* BasePointer, UProperty* Property)
{
	check(Property->IsA<UObjectProperty>());
	UObjectProperty* ObjectProperty = (UObjectProperty*)Property;
	UObject* ReferencedObject = ObjectProperty->GetPropertyValue(ObjectProperty->ContainerPtrToValuePtr<void>(BasePointer));

	return NoesisCreateComponentForUObject(ReferencedObject);
}

template<>
void SetProperty<Noesis::TextureSource>(void* BasePointer, UProperty* Property, Noesis::BaseComponent* Value)
{

}

template<class T>
Noesis::Ptr<Noesis::BaseComponent> GetFunctionProperty(void* BasePointer, UFunction* Getter)
{
	UObject* Object = (UObject*)BasePointer;
	if (!Object->IsPendingKill())
	{
		UProperty* OutputParam = (UProperty*)Getter->Children;
		uint8* Params = (uint8*)FMemory_Alloca(Getter->ParmsSize);
		FMemory::Memzero(Params, Getter->ParmsSize);
		Object->ProcessEvent(Getter, Params);
		return GetProperty<T>(Params, OutputParam);
	}
	return Noesis::Ptr<Noesis::BaseComponent>();
}

template<class T>
void SetFunctionProperty(void* BasePointer, UFunction* Setter, Noesis::BaseComponent* Value)
{
	UObject* Object = (UObject*)BasePointer;
	if (!Object->IsPendingKill())
	{
		UProperty* InputParam = (UProperty*)Setter->Children;
		uint8* Params = (uint8*)FMemory_Alloca(Setter->ParmsSize);
		FMemory::Memzero(Params, Setter->ParmsSize);
		SetProperty<T>(Params, InputParam, Value);
		Object->ProcessEvent(Setter, Params);
	}
}

class NoesisValueArrayWrapperBase : public Noesis::BaseComponent, public Noesis::IList
{
public:
	NoesisValueArrayWrapperBase()
	{
	}

	virtual Noesis::BaseComponent* GetBaseObject() const override
	{
		return (Noesis::BaseComponent*)this;
	}

	virtual int32 AddReference() const override
	{
		return Noesis::BaseComponent::AddReference();
	}

	virtual int32 Release() const override
	{
		return Noesis::BaseComponent::Release();
	}

	virtual int32 GetNumReferences() const override
	{
		return Noesis::BaseComponent::GetNumReferences();
	}

public:
	// IList interface
	virtual int32 Count() const override
	{
		return ComponentArray.Num();
	}

	virtual Noesis::Ptr<Noesis::BaseComponent> GetComponent(uint32 Index) const override
	{
		return ComponentArray[Index];
	}

	virtual void SetComponent(uint32 Index, Noesis::BaseComponent* Item) override
	{
	}

	virtual int32 AddComponent(Noesis::BaseComponent* Item) override
	{
		return -1;
	}

	virtual int IndexOfComponent(Noesis::BaseComponent* Item) const override
	{
		return ComponentArray.Find(Noesis::Ptr<Noesis::BaseComponent>(Item));
	}
	// End of IList interface

	NS_IMPLEMENT_INLINE_REFLECTION(NoesisValueArrayWrapperBase, Noesis::BaseComponent)
	{
		NsImpl<Noesis::IList>();
	}

public:
	TArray<Noesis::Ptr<Noesis::BaseComponent> > ComponentArray;
};

template<class T>
class NoesisValueArrayWrapper : public NoesisValueArrayWrapperBase
{
public:
	NoesisValueArrayWrapper(void* BasePointer, UArrayProperty* ArrayProperty, UProperty* ArrayInnerProperty)
		: NoesisValueArrayWrapperBase()
	{
		check(ArrayInnerProperty->GetOffset_ForDebug() == 0);

		ComponentArray.Empty();

		FScriptArrayHelper ArrayHelper(ArrayProperty, ArrayProperty->ContainerPtrToValuePtr<void>(BasePointer));

		for (int32 Index = 0; Index != ArrayHelper.Num(); ++Index)
		{
			Noesis::Ptr<Noesis::BaseComponent> Item = GetProperty<T>(ArrayHelper.GetRawPtr(Index), ArrayInnerProperty);
			ComponentArray.Add(Item);
		}
	}
};

class NoesisArrayWrapperBase : public Noesis::BaseComponent, public Noesis::IList, public Noesis::INotifyCollectionChanged
{
public:
	NoesisArrayWrapperBase(void* BasePointer, UArrayProperty* ArrayProperty, UProperty* ArrayInnerProperty)
		: InnerProperty(ArrayInnerProperty), ArrayPointer(ArrayProperty->ContainerPtrToValuePtr<void>(BasePointer)), ArrayHelper(ArrayProperty, ArrayPointer), PreviousCount(INDEX_NONE)
	{
		check(InnerProperty->GetOffset_ForDebug() == 0);
		ArrayMap.Add(ArrayPointer, this);
	}

	~NoesisArrayWrapperBase()
	{
		ArrayMap.Remove(ArrayPointer);
	}

	virtual Noesis::BaseComponent* GetBaseObject() const override
	{
		return (Noesis::BaseComponent*)this;
	}

	virtual int32 AddReference() const override
	{
		return Noesis::BaseComponent::AddReference();
	}

	virtual int32 Release() const override
	{
		return Noesis::BaseComponent::Release();
	}

	virtual int32 GetNumReferences() const override
	{
		return Noesis::BaseComponent::GetNumReferences();
	}

protected:
	virtual Noesis::Ptr<Noesis::BaseComponent> NativeGet(uint32 Index) const = 0;
	virtual void NativeSet(uint32 Index, Noesis::BaseComponent* Item) = 0;
	int32 NativeSize() const { return ArrayHelper.Num(); }
	void NativeInsert(uint32 Index) { ArrayHelper.InsertValues(Index); }
	void NativeClear() { ArrayHelper.EmptyValues(); }
	void NativeRemoveAt(uint32 Index) { ArrayHelper.RemoveValues(Index); }

public:
	// IList interface
	virtual int32 Count() const override
	{
		return NativeSize();
	}

	virtual Noesis::Ptr<Noesis::BaseComponent> GetComponent(uint32 Index) const override
	{
		return NativeGet(Index);
	}

	virtual void SetComponent(uint32 Index, Noesis::BaseComponent* Item) override
	{
		NotifyPreSet(Index);
		NativeSet(Index, Item);
		NotifyPostSet(Index);
	}

	virtual int32 AddComponent(Noesis::BaseComponent* Item) override
	{
		int32 Index = NativeSize();
		NativeInsert(Index);
		NativeSet(Index, Item);
		NotifyPostInsert(Index);
		return Index;
	}

	virtual int IndexOfComponent(Noesis::BaseComponent* Item) const override
	{
		for (uint32 Index = 0; Index != Count(); ++Index)
		{
			Noesis::Ptr<Noesis::BaseComponent> ItemAtIndex = NativeGet(Index);
			if (ItemAtIndex && ItemAtIndex->Equals(Item))
			{
				return Index;
			}
		}
		return -1;
	}
	// End of IList interface

	virtual Noesis::NotifyCollectionChangedEventHandler& CollectionChanged() override
	{
		return CollectionChangedHandler;
	}

	void NotifyPostAdd()
	{
		uint32 Index = NativeSize() - 1;
		NotifyPostInsert(Index);
	}

	void NotifyPostInsert(uint32 Index)
	{
		Noesis::Ptr<Noesis::BaseComponent> Item = NativeGet(Index);

		Noesis::NotifyCollectionChangedEventArgs CollectionChangedArgs = { Noesis::NotifyCollectionChangedAction_Add, -1, (int32)Index, nullptr, Item.GetPtr() };
		CollectionChangedHandler(this, CollectionChangedArgs);
	}

	void NotifyPreSet(int32 Index)
	{
		check(ItemToDelete == nullptr);
		ItemToDelete = NativeGet(Index);
	}

	void NotifyPostSet(int32 Index)
	{
		check(ItemToDelete != nullptr);
		Noesis::Ptr<Noesis::BaseComponent> NewItem = NativeGet(Index);

		Noesis::NotifyCollectionChangedEventArgs CollectionChangedArgs = { Noesis::NotifyCollectionChangedAction_Replace, (int32)Index, (int32)Index, ItemToDelete.GetPtr(), NewItem.GetPtr() };
		CollectionChangedHandler(this, CollectionChangedArgs);
		ItemToDelete.Reset();
	}

	void NotifyPostClear()
	{
		NotifyPostChanged();
	}

	void NotifyPreRemoveAt(int32 Index)
	{
		check(ItemToDelete == nullptr);
		ItemToDelete = NativeGet(Index);
	}

	void NotifyPostRemoveAt(int32 Index)
	{
		check(ItemToDelete != nullptr);
		Noesis::NotifyCollectionChangedEventArgs CollectionChangedArgs = { Noesis::NotifyCollectionChangedAction_Remove, Index, -1, ItemToDelete.GetPtr(), nullptr };
		CollectionChangedHandler(this, CollectionChangedArgs);
		ItemToDelete.Reset();
	}

	void NotifyPostChanged()
	{
		Noesis::NotifyCollectionChangedEventArgs CollectionChangedArgs = { Noesis::NotifyCollectionChangedAction_Reset, -1, -1, nullptr, nullptr };
		CollectionChangedHandler(this, CollectionChangedArgs);
	}

	void NotifyPreAppend()
	{
		check(PreviousCount == INDEX_NONE);
		PreviousCount = NativeSize();
	}

	void NotifyPostAppend()
	{
		check(PreviousCount != INDEX_NONE);
		uint32 Count = NativeSize();
		for (uint32 Index = PreviousCount; Index != Count; ++Index)
		{
			NotifyPostInsert(Index);
		}
		PreviousCount = INDEX_NONE;
	}

	NS_IMPLEMENT_INLINE_REFLECTION(NoesisArrayWrapperBase, Noesis::BaseComponent)
	{
		NsImpl<Noesis::IList>();
		NsImpl<Noesis::INotifyCollectionChanged>();
	}

private:
	Noesis::NotifyCollectionChangedEventHandler CollectionChangedHandler;

public:
	UProperty* InnerProperty;
	void* ArrayPointer;
	mutable FScriptArrayHelper ArrayHelper;
	Noesis::Ptr<Noesis::BaseComponent> ItemToDelete;
	int32 PreviousCount;
};

template<class T>
class NoesisArrayWrapper : public NoesisArrayWrapperBase
{
public:
	NoesisArrayWrapper(void* BasePointer, UArrayProperty* ArrayProperty, UProperty* ArrayInnerProperty)
		: NoesisArrayWrapperBase(BasePointer, ArrayProperty, ArrayInnerProperty)
	{
		check(InnerProperty->GetOffset_ForDebug() == 0);
	}

	virtual Noesis::Ptr<Noesis::BaseComponent> NativeGet(uint32 Index) const override
	{
		ArrayHelper.ExpandForIndex(Index);
		return GetProperty<T>(ArrayHelper.GetRawPtr(Index), InnerProperty);
	}

	virtual void NativeSet(uint32 Index, Noesis::BaseComponent* Item) override
	{
		ArrayHelper.ExpandForIndex(Index);
		SetProperty<T>(ArrayHelper.GetRawPtr(Index), InnerProperty, Item);
	}
};

class NoesisFunctionWrapper : public Noesis::BaseCommand
{
public:
	NoesisFunctionWrapper(UObject* InObject, UFunction* InFunction, UFunction* InCanExecuteFunction)
		: Object(InObject), Function(InFunction), CanExecuteFunction(InCanExecuteFunction)
	{
	}

	bool CanExecute(Noesis::BaseComponent* Param) const override
	{
		if (!Object->IsPendingKill() && CanExecuteFunction)
		{
			int32 ReturnValue = 0;
			Object->ProcessEvent(CanExecuteFunction, &ReturnValue);
			UBoolProperty* OutputParam = (UBoolProperty*)(CanExecuteFunction->Children);
			return OutputParam->GetPropertyValue(OutputParam->ContainerPtrToValuePtr<bool>(&ReturnValue));
		}

		return true;
	}

	void Execute(Noesis::BaseComponent* Param) const override
	{
		if (!Object->IsPendingKill())
		{
			check(Function->NumParms == 0);
			Object->ProcessEvent(Function, nullptr);
		}
	}

	NS_IMPLEMENT_INLINE_REFLECTION_(NoesisFunctionWrapper, Noesis::BaseCommand)

protected:
	UObject* Object;
	UFunction* Function;
	UFunction* CanExecuteFunction;
};

template<class T>
class NoesisFunctionOneParamWrapper : public NoesisFunctionWrapper
{
public:
	NoesisFunctionOneParamWrapper(UObject* InObject, UFunction* InFunction, UFunction* InCanExecuteFunction)
		: NoesisFunctionWrapper(InObject, InFunction, InCanExecuteFunction)
	{
	}

	bool CanExecute(Noesis::BaseComponent* Param) const override
	{
		if (!Object->IsPendingKill() && CanExecuteFunction)
		{
			if (CanExecuteFunction->NumParms == 1)
			{
				int32 ReturnValue = 0;
				Object->ProcessEvent(CanExecuteFunction, &ReturnValue);
				UBoolProperty* OutputParam = (UBoolProperty*)(CanExecuteFunction->Children);
				return OutputParam->GetPropertyValue(OutputParam->ContainerPtrToValuePtr<bool>(&ReturnValue));
			}
			else
			{
				check(CanExecuteFunction->NumParms == 2);
				uint8* Params = (uint8*)FMemory_Alloca(CanExecuteFunction->ParmsSize);
				FMemory::Memzero(Params, CanExecuteFunction->ParmsSize);
				::SetProperty<T>(Params, (UProperty*)CanExecuteFunction->Children, Param);
				Object->ProcessEvent(CanExecuteFunction, Params);
				UBoolProperty* OutputParam = (UBoolProperty*)(CanExecuteFunction->Children->Next);
				return OutputParam->GetPropertyValue(OutputParam->ContainerPtrToValuePtr<bool>(Params));
			}
		}

		return true;
	}

	void Execute(Noesis::BaseComponent* Param) const override
	{
		if (!Object->IsPendingKill())
		{
			if (Function->NumParms == 0)
			{
				Object->ProcessEvent(Function, nullptr);
			}
			else
			{
				uint8* Params = (uint8*)FMemory_Alloca(Function->ParmsSize);
				FMemory::Memzero(Params, Function->ParmsSize);
				::SetProperty<T>(Params, (UProperty*)Function->Children, Param);
				Object->ProcessEvent(Function, Params);
			}
		}
	}
};

union TypePropertyData
{
	explicit TypePropertyData(UFunction* InFunction, UFunction* InCanExecuteFunction)
		: Function(InFunction), CanExecuteFunction(InCanExecuteFunction)
	{
	}

	explicit TypePropertyData(UProperty* InProperty)
		: Property(InProperty)
	{
	}

	explicit TypePropertyData(UArrayProperty* InArrayProperty, UProperty* InArrayInnerProperty)
		: ArrayProperty(InArrayProperty), ArrayInnerProperty(InArrayInnerProperty)
	{
	}

	UProperty* Property;
	struct
	{
		UArrayProperty* ArrayProperty;
		UProperty* ArrayInnerProperty;
	};
	struct
	{
		UFunction* Function;
		UFunction* CanExecuteFunction;
	};
	struct
	{
		UFunction* Getter;
		UFunction* Setter;
	};
};

class NoesisStructWrapper : public Noesis::BaseComponent
{
public:

	NoesisStructWrapper(Noesis::TypeClass* InTypeClass, UScriptStruct* InStruct) :
		Noesis::BaseComponent(), TypeClass(InTypeClass), Struct(InStruct)
	{
		StructData.Empty(InStruct->GetStructureSize());
	}

	virtual const Noesis::TypeClass* GetClassType() const override
	{
		return TypeClass;
	}

	Noesis::String ToString() const override
	{
		return "";
	}

	bool Equals(const Noesis::BaseObject* BaseObject) const override
	{
		const NoesisStructWrapper* Wrapper = Noesis::DynamicCast<const NoesisStructWrapper*>(BaseObject);
		return Wrapper && Struct == Wrapper->Struct && Struct->CompareScriptStruct(GetStructPtr(), Wrapper->GetStructPtr(), PPF_None);
	}

	static const Noesis::TypeClass* StaticGetClassType(Noesis::TypeTag<NoesisStructWrapper>* = 0)
	{
		static const Noesis::TypeClass* Type;

		if (Type == 0)
		{
			Type = static_cast<const Noesis::TypeClass*>(Noesis::Reflection::RegisterType(
				"NoesisStructWrapper",
				Noesis::TypeClassCreator::Create<NoesisStructWrapper>,
				Noesis::TypeClassCreator::Fill<NoesisStructWrapper, Noesis::BaseComponent>));
		}

		return Type;
	}

	template <class VOID_> static void StaticFillClassType(Noesis::TypeClassCreator& Helper)
	{
	}

	template<class T>
	Noesis::Ptr<Noesis::BaseComponent> GetProperty(const TypePropertyData& Data) const
	{
		return ::GetProperty<T>(GetStructPtr(), Data.Property);
	}

	template<class T>
	Noesis::Ptr<Noesis::BaseComponent> GetArrayProperty(const TypePropertyData& Data) const
	{
		return *new NoesisValueArrayWrapper<T>(GetStructPtr(), Data.ArrayProperty, Data.ArrayInnerProperty);
	}

	void* GetStructPtr() const
	{
		return (void*)StructData.GetData();
	}

public:
	Noesis::TypeClass* TypeClass;
	UScriptStruct* Struct;
	TArray<uint8_t> StructData;
};

class NoesisObjectWrapper : public Noesis::BaseComponent, public Noesis::INotifyPropertyChanged
{
public:

	NoesisObjectWrapper(Noesis::TypeClass* InTypeClass, UObject* InObject) :
		Noesis::BaseComponent(), TypeClass(InTypeClass), Object(InObject)
	{
	}

	virtual Noesis::BaseComponent* GetBaseObject() const override
	{
		return (Noesis::BaseComponent*)this;
	}

	virtual Noesis::PropertyChangedEventHandler& PropertyChanged() override
	{
		return PropertyChangedHandler;
	}

	virtual int32 AddReference() const override
	{
		return Noesis::BaseComponent::AddReference();
	}

	virtual int32 Release() const override
	{
		return Noesis::BaseComponent::Release();
	}

	virtual int32 GetNumReferences() const override
	{
		return Noesis::BaseComponent::GetNumReferences();
	}

	virtual const Noesis::TypeClass* GetClassType() const override
	{
		return TypeClass;
	}

	Noesis::String ToString() const override
	{
		return TCHARToNsString(*Object->GetPathName());
	}

	bool Equals(const Noesis::BaseObject* BaseObject) const override
	{
		const NoesisObjectWrapper* Wrapper = Noesis::DynamicCast<const NoesisObjectWrapper*>(BaseObject);
		return Wrapper && Object == Wrapper->Object;
	}

	static const Noesis::TypeClass* StaticGetClassType(Noesis::TypeTag<NoesisObjectWrapper>* = 0)
	{
		static const Noesis::TypeClass* Type;

		if (Type == 0)
		{
			Type = static_cast<const Noesis::TypeClass*>(Noesis::Reflection::RegisterType(
				"NoesisObjectWrapper",
				Noesis::TypeClassCreator::Create<NoesisObjectWrapper>,
				Noesis::TypeClassCreator::Fill<NoesisObjectWrapper, Noesis::BaseComponent>));
		}

		return Type;
	}

	template <class VOID_> static void StaticFillClassType(Noesis::TypeClassCreator& Helper)
	{
		Helper.Impl<NoesisObjectWrapper, Noesis::INotifyPropertyChanged>();
	}

	template<class T>
	Noesis::Ptr<Noesis::BaseComponent> GetProperty(const TypePropertyData& Data) const
	{
		return ::GetProperty<T>(Object, Data.Property);
	}
	template<class T>
	bool SetProperty(const TypePropertyData& Data, Noesis::BaseComponent* Value)
	{
		Noesis::Ptr<Noesis::BaseComponent> OldValue = ::GetProperty<T>(Object, Data.Property);
		::SetProperty<T>(Object, Data.Property, Value);
		Noesis::Ptr<Noesis::BaseComponent> NewValue = ::GetProperty<T>(Object, Data.Property);
		return (NewValue && !NewValue->Equals(OldValue.GetPtr()));
	}
	template<class T>
	Noesis::Ptr<Noesis::BaseComponent> GetFunctionProperty(const TypePropertyData& Data) const
	{
		return ::GetFunctionProperty<T>(Object, Data.Getter);
	}
	template<class T>
	bool SetFunctionProperty(const TypePropertyData& Data, Noesis::BaseComponent* Value)
	{
		Noesis::Ptr<Noesis::BaseComponent> OldValue = ::GetFunctionProperty<T>(Object, Data.Getter);
		::SetFunctionProperty<T>(Object, Data.Setter, Value);
		Noesis::Ptr<Noesis::BaseComponent> NewValue = ::GetFunctionProperty<T>(Object, Data.Getter);
		return (NewValue && !NewValue->Equals(OldValue.GetPtr()));
	}

	Noesis::Ptr<Noesis::BaseComponent> GetCommandProperty(const TypePropertyData& Data) const
	{
		auto CommandPtr = FunctionToCommand.Find(Data.Function);
		if (CommandPtr)
		{
			return *CommandPtr;
		}

		Noesis::Ptr<Noesis::BaseComponent> Command = *new NoesisFunctionWrapper(Object, Data.Function, Data.CanExecuteFunction);
		FunctionToCommand.Add(Data.Function, Command);
		return Command;
	}

	template<class T>
	Noesis::Ptr<Noesis::BaseComponent> GetCommandOneParamProperty(const TypePropertyData& Data) const
	{
		auto CommandPtr = FunctionToCommand.Find(Data.Function);
		if (CommandPtr)
		{
			return *CommandPtr;
		}

		Noesis::Ptr<Noesis::BaseComponent> Command = *new NoesisFunctionOneParamWrapper<T>(Object, Data.Function, Data.CanExecuteFunction);
		FunctionToCommand.Add(Data.Function, Command);
		return Command;
	}

	template<class T>
	Noesis::Ptr<Noesis::BaseComponent> GetArrayProperty(const TypePropertyData& Data) const
	{
		auto ListPtr = ArrayToList.Find(Data.ArrayProperty);
		if (ListPtr)
		{
			return *ListPtr;
		}

		Noesis::Ptr<Noesis::BaseComponent> Wrapper = *new NoesisArrayWrapper<T>(Object, Data.ArrayProperty, Data.ArrayInnerProperty);
		ArrayToList.Add(Data.ArrayProperty, Wrapper);
		return Wrapper;
	}

	template<class T>
	bool SetArrayProperty(const TypePropertyData& Data, Noesis::BaseComponent* Value)
	{
		NoesisArrayWrapperBase* ValueWrapper = Noesis::DynamicCast<NoesisArrayWrapperBase*>(Value);
		if (ValueWrapper)
		{
			FScriptArrayHelper SourceArrayHelper = ValueWrapper->ArrayHelper;
			check(Data.ArrayProperty->IsA<UArrayProperty>());
			UProperty* InnerProperty = Data.ArrayProperty->Inner;
			if (InnerProperty->SameType(ValueWrapper->InnerProperty))
			{
				FScriptArrayHelper TargetArrayHelper(Data.ArrayProperty, Object);

				TargetArrayHelper.EmptyAndAddUninitializedValues(SourceArrayHelper.Num());
				for (int32 Index = 0; Index < SourceArrayHelper.Num(); ++Index)
				{
					InnerProperty->CopySingleValue(TargetArrayHelper.GetRawPtr(Index), SourceArrayHelper.GetRawPtr(Index));
				}
			}
		}

		Noesis::Ptr<Noesis::BaseComponent> Wrapper = GetArrayProperty<T>(Data);
		((NoesisArrayWrapperBase*)Wrapper.GetPtr())->NotifyPostChanged();

		return false;
	}

	void NotifyPropertyChanged(Noesis::Symbol PropertyId)
	{
		Noesis::PropertyChangedEventArgs ChangedEventArgs(PropertyId);
		PropertyChangedHandler(this, ChangedEventArgs);
	}

public:
	Noesis::PropertyChangedEventHandler PropertyChangedHandler;
	mutable TMap<UFunction*, Noesis::Ptr<Noesis::BaseComponent> > FunctionToCommand;
	mutable TMap<UArrayProperty*, Noesis::Ptr<Noesis::BaseComponent> > ArrayToList;
	Noesis::TypeClass* TypeClass;
	UObject* Object;
};

template<class T>
class TypePropertyNoesisObjectWrapper : public Noesis::TypeProperty
{
public:
	typedef Noesis::Ptr<Noesis::BaseComponent> (T::*GetterFn)(const TypePropertyData&) const;
	typedef bool (T::*SetterFn)(const TypePropertyData&, Noesis::BaseComponent*);

	/// Constructor
	TypePropertyNoesisObjectWrapper(Noesis::Symbol Name, const Noesis::Type* Type, GetterFn Getter, SetterFn Setter, const TypePropertyData& Data);

	/// From TypeProperty
	//@{
	void* GetContent(void* Ptr) const;
	const void* GetContent(const void* Ptr) const;
	Noesis::Ptr<Noesis::BaseComponent> GetComponent(const void* Ptr) const;
	void SetComponent(void* Ptr, Noesis::BaseComponent* Value) const;
	//@}

protected:
	/// From TypeProperty
	//@{
	const void* InternalGet(const void* Ptr) const;
	void InternalGet(const void* Ptr, void* Storage) const;
	void InternalSet(void* Ptr, const void* Value) const;
	bool InternalIsReadOnly() const;
	//@}

private:
	GetterFn Getter;
	SetterFn Setter;
	const TypePropertyData Data;
};

template<class T>
TypePropertyNoesisObjectWrapper<T>::TypePropertyNoesisObjectWrapper(Noesis::Symbol Name, const Noesis::Type* Type, GetterFn InGetter, SetterFn InSetter, const TypePropertyData& InData) :
	TypeProperty(Name, Type), Getter(InGetter), Setter(InSetter), Data(InData)
{
	NS_ASSERT(Getter);
}

template<class T>
void* TypePropertyNoesisObjectWrapper<T>::GetContent(void* Ptr) const
{
	check(false);
	return nullptr;
}

template<class T>
const void* TypePropertyNoesisObjectWrapper<T>::GetContent(const void* Ptr) const
{
	check(false);
	return nullptr;
}

template<class T>
Noesis::Ptr<Noesis::BaseComponent> TypePropertyNoesisObjectWrapper<T>::GetComponent(const void* Ptr) const
{
	return (static_cast<const T*>(Ptr)->*Getter)(Data);
}

template<class T>
void TypePropertyNoesisObjectWrapper<T>::SetComponent(void* Ptr, Noesis::BaseComponent* Value) const
{
}

template<>
void TypePropertyNoesisObjectWrapper<NoesisObjectWrapper>::SetComponent(void* Ptr, Noesis::BaseComponent* Value) const
{
	NoesisObjectWrapper* ObjectWrapper = (NoesisObjectWrapper*)Ptr;
	if ((ObjectWrapper->*Setter)(Data, Value))
	{
		ObjectWrapper->NotifyPropertyChanged(GetName());
	}
}

template<class T>
const void* TypePropertyNoesisObjectWrapper<T>::InternalGet(const void* Ptr) const
{
	check(false);
	return nullptr;
}

template<class T>
void TypePropertyNoesisObjectWrapper<T>::InternalGet(const void* Ptr, void* Storage) const
{
	check(false);
}

template<class T>
void TypePropertyNoesisObjectWrapper<T>::InternalSet(void* Ptr, const void* Value) const
{
	check(false);
}

template<class T>
bool TypePropertyNoesisObjectWrapper<T>::InternalIsReadOnly() const
{
	return Setter == 0;
}

class NoesisTypeClass : public Noesis::TypeClass
{
public:
	NoesisTypeClass(Noesis::Symbol Name)
		: Noesis::TypeClass(Name, false)
	{
	}

#if WITH_EDITOR
	FDelegateHandle ChangeDelegateHandle;
#endif

	UStruct* Class;

	NS_IMPLEMENT_INLINE_REFLECTION_(NoesisTypeClass, Noesis::TypeClass)
};

Noesis::Type* UClassTypeCreator(Noesis::Symbol Name)
{
	return new NoesisTypeClass(Name);
}

void UStructTypeFiller(Noesis::Type* Type)
{
	const char* ClassName = Type->GetName();
	check(RegisterNameMap.Find(NsStringToFString(ClassName)));
	UScriptStruct* Class = LoadObject<UScriptStruct>(nullptr, **RegisterNameMap.Find(NsStringToFString(ClassName)));

	const Noesis::TypeClass* ParentType = NoesisStructWrapper::StaticGetClassType(nullptr);

	NoesisTypeClass* TypeClass = Noesis::DynamicCast<NoesisTypeClass*>(Type);
	TypeClass->Class = Class;
	check(TypeClass);

	Noesis::TypeClassBuilder* TypeClassBuilder = (Noesis::TypeClassBuilder*)TypeClass;
	TypeClassBuilder->AddBase(ParentType);

	for (TFieldIterator<UProperty> PropertyIt(Class, EFieldIteratorFlags::ExcludeSuper); PropertyIt; ++PropertyIt)
	{
		UProperty* Property = *PropertyIt;
		FString PropertyName = Property->GetName();
		if (!(Class->StructFlags & STRUCT_Native))
		{
			int32 UnderscorePosition = INDEX_NONE;
			ensure(PropertyName.FindLastChar(TEXT('_'), UnderscorePosition));
			PropertyName = PropertyName.LeftChop(PropertyName.Len() - UnderscorePosition);
			ensure(PropertyName.FindLastChar(TEXT('_'), UnderscorePosition));
			PropertyName = PropertyName.LeftChop(PropertyName.Len() - UnderscorePosition);
		}
		Noesis::Symbol PropertyId = Noesis::Symbol(TCHARToNsString(*PropertyName).Str());

		if (Property->IsA<UIntProperty>())
		{
			Noesis::TypeProperty* TypeProperty = new TypePropertyNoesisObjectWrapper<NoesisStructWrapper>(PropertyId, Noesis::TypeOf<int>(), &NoesisStructWrapper::GetProperty<int>, nullptr, TypePropertyData(Property));
			TypeClassBuilder->AddProperty(TypeProperty);
		}
		else if (Property->IsA<UFloatProperty>())
		{
			Noesis::TypeProperty* TypeProperty = new TypePropertyNoesisObjectWrapper<NoesisStructWrapper>(PropertyId, Noesis::TypeOf<float>(), &NoesisStructWrapper::GetProperty<float>, nullptr, TypePropertyData(Property));
			TypeClassBuilder->AddProperty(TypeProperty);
		}
		else if (Property->IsA<UBoolProperty>())
		{
			Noesis::TypeProperty* TypeProperty = new TypePropertyNoesisObjectWrapper<NoesisStructWrapper>(PropertyId, Noesis::TypeOf<bool>(), &NoesisStructWrapper::GetProperty<bool>, nullptr, TypePropertyData(Property));
			TypeClassBuilder->AddProperty(TypeProperty);
		}
		else if (Property->IsA<UStrProperty>())
		{
			Noesis::TypeProperty* TypeProperty = new TypePropertyNoesisObjectWrapper<NoesisStructWrapper>(PropertyId, Noesis::TypeOf<Noesis::String>(), &NoesisStructWrapper::GetProperty<Noesis::String>, nullptr, TypePropertyData(Property));
			TypeClassBuilder->AddProperty(TypeProperty);
		}
		else if (Property->IsA<UTextProperty>())
		{
			Noesis::TypeProperty* TypeProperty = new TypePropertyNoesisObjectWrapper<NoesisStructWrapper>(PropertyId, Noesis::TypeOf<Noesis::String>(), &NoesisStructWrapper::GetProperty<Noesis::String>, nullptr, TypePropertyData(Property));
			TypeClassBuilder->AddProperty(TypeProperty);
		}
		else if (UStructProperty* StructProperty = Cast<UStructProperty>(Property))
		{
			if (StructProperty->Struct->GetFName() == NAME_Color)
			{
				Noesis::TypeProperty* TypeProperty = new TypePropertyNoesisObjectWrapper<NoesisStructWrapper>(PropertyId, Noesis::TypeOf<Noesis::Color>(), &NoesisStructWrapper::GetProperty<Noesis::Color>, nullptr, TypePropertyData(Property));
				TypeClassBuilder->AddProperty(TypeProperty);
			}
			else if (StructProperty->Struct->GetFName() == NAME_Vector2D)
			{
				Noesis::TypeProperty* TypeProperty = new TypePropertyNoesisObjectWrapper<NoesisStructWrapper>(PropertyId, Noesis::TypeOf<Noesis::Point>(), &NoesisStructWrapper::GetProperty<Noesis::Point>, nullptr, TypePropertyData(Property));
				TypeClassBuilder->AddProperty(TypeProperty);
			}
			else if (StructProperty->Struct->GetName() == TEXT("NoesisRect"))
			{
				Noesis::TypeProperty* TypeProperty = new TypePropertyNoesisObjectWrapper<NoesisStructWrapper>(PropertyId, Noesis::TypeOf<Noesis::Rect>(), &NoesisStructWrapper::GetProperty<Noesis::Rect>, nullptr, TypePropertyData(Property));
				TypeClassBuilder->AddProperty(TypeProperty);
			}
			else if (StructProperty->Struct->GetName() == TEXT("NoesisSize"))
			{
				Noesis::TypeProperty* TypeProperty = new TypePropertyNoesisObjectWrapper<NoesisStructWrapper>(PropertyId, Noesis::TypeOf<Noesis::Size>(), &NoesisStructWrapper::GetProperty<Noesis::Size>, nullptr, TypePropertyData(Property));
				TypeClassBuilder->AddProperty(TypeProperty);
			}
			else if (StructProperty->Struct->GetName() == TEXT("NoesisThickness"))
			{
				Noesis::TypeProperty* TypeProperty = new TypePropertyNoesisObjectWrapper<NoesisStructWrapper>(PropertyId, Noesis::TypeOf<Noesis::Thickness>(), &NoesisStructWrapper::GetProperty<Noesis::Thickness>, nullptr, TypePropertyData(Property));
				TypeClassBuilder->AddProperty(TypeProperty);
			}
			else if (StructProperty->Struct->GetName() == TEXT("NoesisCornerRadius"))
			{
				Noesis::TypeProperty* TypeProperty = new TypePropertyNoesisObjectWrapper<NoesisStructWrapper>(PropertyId, Noesis::TypeOf<Noesis::CornerRadius>(), &NoesisStructWrapper::GetProperty<Noesis::CornerRadius>, nullptr, TypePropertyData(Property));
				TypeClassBuilder->AddProperty(TypeProperty);
			}
			else if (StructProperty->Struct->GetName() == TEXT("NoesisTimeSpan"))
			{
				Noesis::TypeProperty* TypeProperty = new TypePropertyNoesisObjectWrapper<NoesisStructWrapper>(PropertyId, Noesis::TypeOf<Noesis::TimeSpan>(), &NoesisStructWrapper::GetProperty<Noesis::TimeSpan>, nullptr, TypePropertyData(Property));
				TypeClassBuilder->AddProperty(TypeProperty);
			}
			else if (StructProperty->Struct->GetName() == TEXT("NoesisDuration"))
			{
				Noesis::TypeProperty* TypeProperty = new TypePropertyNoesisObjectWrapper<NoesisStructWrapper>(PropertyId, Noesis::TypeOf<Noesis::Duration>(), &NoesisStructWrapper::GetProperty<Noesis::Duration>, nullptr, TypePropertyData(Property));
				TypeClassBuilder->AddProperty(TypeProperty);
			}
			else if (StructProperty->Struct->GetName() == TEXT("NoesisKeyTime"))
			{
				Noesis::TypeProperty* TypeProperty = new TypePropertyNoesisObjectWrapper<NoesisStructWrapper>(PropertyId, Noesis::TypeOf<Noesis::KeyTime>(), &NoesisStructWrapper::GetProperty<Noesis::KeyTime>, nullptr, TypePropertyData(Property));
				TypeClassBuilder->AddProperty(TypeProperty);
			}
			else
			{
				Noesis::TypeProperty* TypeProperty = new TypePropertyNoesisObjectWrapper<NoesisStructWrapper>(PropertyId, Noesis::TypeOf<NoesisStructWrapper>(), &NoesisStructWrapper::GetProperty<NoesisStructWrapper>, nullptr, TypePropertyData(Property));
				TypeClassBuilder->AddProperty(TypeProperty);
			}
		}
		else if (UObjectProperty* ObjectProperty = Cast<UObjectProperty>(Property))
		{
			if (ObjectProperty->PropertyClass == UTexture2D::StaticClass() || ObjectProperty->PropertyClass == UTextureRenderTarget2D::StaticClass())
			{
				Noesis::TypeProperty* TypeProperty = new TypePropertyNoesisObjectWrapper<NoesisStructWrapper>(PropertyId, Noesis::TypeOf<Noesis::TextureSource>(), &NoesisStructWrapper::GetProperty<Noesis::TextureSource>, nullptr, TypePropertyData(Property));
				TypeClassBuilder->AddProperty(TypeProperty);
			}
			else
			{
				Noesis::TypeProperty* TypeProperty = new TypePropertyNoesisObjectWrapper<NoesisStructWrapper>(PropertyId, Noesis::TypeOf<NoesisObjectWrapper>(), &NoesisStructWrapper::GetProperty<NoesisObjectWrapper>, nullptr, TypePropertyData(Property));
				TypeClassBuilder->AddProperty(TypeProperty);
			}
		}
		else if (UEnumProperty* EnumProperty = Cast<UEnumProperty>(Property))
		{
			Noesis::TypeEnum* TypeEnum = NoesisCreateTypeEnumForUEnum(EnumProperty->GetEnum());
			Noesis::TypeProperty* TypeProperty = new TypePropertyNoesisObjectWrapper<NoesisStructWrapper>(PropertyId, TypeEnum, &NoesisStructWrapper::GetProperty<NoesisEnumWrapper>, nullptr, TypePropertyData(EnumProperty));
			TypeClassBuilder->AddProperty(TypeProperty);
		}
		else if (UByteProperty* ByteProperty = Cast<UByteProperty>(Property))
		{
			if (ByteProperty->Enum)
			{
				Noesis::TypeEnum* TypeEnum = NoesisCreateTypeEnumForUEnum(ByteProperty->Enum);
				Noesis::TypeProperty* TypeProperty = new TypePropertyNoesisObjectWrapper<NoesisStructWrapper>(PropertyId, TypeEnum, &NoesisStructWrapper::GetProperty<NoesisEnumWrapper>, nullptr, TypePropertyData(ByteProperty));
				TypeClassBuilder->AddProperty(TypeProperty);
			}
		}
		else if (UArrayProperty* ArrayProperty = Cast<UArrayProperty>(Property))
		{
			UProperty* InnerProperty = ArrayProperty->Inner;
			if (InnerProperty->IsA<UIntProperty>())
			{
				Noesis::TypeProperty* TypeProperty = new TypePropertyNoesisObjectWrapper<NoesisStructWrapper>(PropertyId, Noesis::TypeOf<NoesisArrayWrapperBase>(), &NoesisStructWrapper::GetArrayProperty<int>, nullptr, TypePropertyData(ArrayProperty, InnerProperty));
				TypeClassBuilder->AddProperty(TypeProperty);
			}
			else if (InnerProperty->IsA<UFloatProperty>())
			{
				Noesis::TypeProperty* TypeProperty = new TypePropertyNoesisObjectWrapper<NoesisStructWrapper>(PropertyId, Noesis::TypeOf<NoesisArrayWrapperBase>(), &NoesisStructWrapper::GetArrayProperty<float>, nullptr, TypePropertyData(ArrayProperty, InnerProperty));
				TypeClassBuilder->AddProperty(TypeProperty);
			}
			else if (InnerProperty->IsA<UBoolProperty>())
			{
				Noesis::TypeProperty* TypeProperty = new TypePropertyNoesisObjectWrapper<NoesisStructWrapper>(PropertyId, Noesis::TypeOf<NoesisArrayWrapperBase>(), &NoesisStructWrapper::GetArrayProperty<bool>, nullptr, TypePropertyData(ArrayProperty, InnerProperty));
				TypeClassBuilder->AddProperty(TypeProperty);
			}
			else if (InnerProperty->IsA<UStrProperty>())
			{
				Noesis::TypeProperty* TypeProperty = new TypePropertyNoesisObjectWrapper<NoesisStructWrapper>(PropertyId, Noesis::TypeOf<NoesisArrayWrapperBase>(), &NoesisStructWrapper::GetArrayProperty<Noesis::String>, nullptr, TypePropertyData(ArrayProperty, InnerProperty));
				TypeClassBuilder->AddProperty(TypeProperty);
			}
			else if (InnerProperty->IsA<UTextProperty>())
			{
				Noesis::TypeProperty* TypeProperty = new TypePropertyNoesisObjectWrapper<NoesisStructWrapper>(PropertyId, Noesis::TypeOf<NoesisArrayWrapperBase>(), &NoesisStructWrapper::GetArrayProperty<Noesis::String>, nullptr, TypePropertyData(ArrayProperty, InnerProperty));
				TypeClassBuilder->AddProperty(TypeProperty);
			}
			else if (UStructProperty* StructInnerProperty = Cast<UStructProperty>(InnerProperty))
			{
				if (StructInnerProperty->Struct->GetFName() == NAME_Color)
				{
					Noesis::TypeProperty* TypeProperty = new TypePropertyNoesisObjectWrapper<NoesisStructWrapper>(PropertyId, Noesis::TypeOf<NoesisArrayWrapperBase>(), &NoesisStructWrapper::GetArrayProperty<Noesis::Color>, nullptr, TypePropertyData(ArrayProperty, InnerProperty));
					TypeClassBuilder->AddProperty(TypeProperty);
				}
				else if (StructInnerProperty->Struct->GetFName() == NAME_Vector2D)
				{
					Noesis::TypeProperty* TypeProperty = new TypePropertyNoesisObjectWrapper<NoesisStructWrapper>(PropertyId, Noesis::TypeOf<NoesisArrayWrapperBase>(), &NoesisStructWrapper::GetArrayProperty<Noesis::Point>, nullptr, TypePropertyData(ArrayProperty, InnerProperty));
					TypeClassBuilder->AddProperty(TypeProperty);
				}
				else if (StructInnerProperty->Struct->GetName() == TEXT("NoesisRect"))
				{
					Noesis::TypeProperty* TypeProperty = new TypePropertyNoesisObjectWrapper<NoesisStructWrapper>(PropertyId, Noesis::TypeOf<NoesisArrayWrapperBase>(), &NoesisStructWrapper::GetArrayProperty<Noesis::Rect>, nullptr, TypePropertyData(ArrayProperty, InnerProperty));
					TypeClassBuilder->AddProperty(TypeProperty);
				}
				else if (StructInnerProperty->Struct->GetName() == TEXT("NoesisSize"))
				{
					Noesis::TypeProperty* TypeProperty = new TypePropertyNoesisObjectWrapper<NoesisStructWrapper>(PropertyId, Noesis::TypeOf<NoesisArrayWrapperBase>(), &NoesisStructWrapper::GetArrayProperty<Noesis::Size>, nullptr, TypePropertyData(ArrayProperty, InnerProperty));
					TypeClassBuilder->AddProperty(TypeProperty);
				}
				else if (StructInnerProperty->Struct->GetName() == TEXT("NoesisThickness"))
				{
					Noesis::TypeProperty* TypeProperty = new TypePropertyNoesisObjectWrapper<NoesisStructWrapper>(PropertyId, Noesis::TypeOf<NoesisArrayWrapperBase>(), &NoesisStructWrapper::GetArrayProperty<Noesis::Thickness>, nullptr, TypePropertyData(ArrayProperty, InnerProperty));
					TypeClassBuilder->AddProperty(TypeProperty);
				}
				else if (StructInnerProperty->Struct->GetName() == TEXT("NoesisCornerRadius"))
				{
					Noesis::TypeProperty* TypeProperty = new TypePropertyNoesisObjectWrapper<NoesisStructWrapper>(PropertyId, Noesis::TypeOf<NoesisArrayWrapperBase>(), &NoesisStructWrapper::GetArrayProperty<Noesis::CornerRadius>, nullptr, TypePropertyData(ArrayProperty, InnerProperty));
					TypeClassBuilder->AddProperty(TypeProperty);
				}
				else if (StructInnerProperty->Struct->GetName() == TEXT("NoesisTimeSpan"))
				{
					Noesis::TypeProperty* TypeProperty = new TypePropertyNoesisObjectWrapper<NoesisStructWrapper>(PropertyId, Noesis::TypeOf<NoesisArrayWrapperBase>(), &NoesisStructWrapper::GetArrayProperty<Noesis::TimeSpan>, nullptr, TypePropertyData(ArrayProperty, InnerProperty));
					TypeClassBuilder->AddProperty(TypeProperty);
				}
				else if (StructInnerProperty->Struct->GetName() == TEXT("NoesisDuration"))
				{
					Noesis::TypeProperty* TypeProperty = new TypePropertyNoesisObjectWrapper<NoesisStructWrapper>(PropertyId, Noesis::TypeOf<NoesisArrayWrapperBase>(), &NoesisStructWrapper::GetArrayProperty<Noesis::Duration>, nullptr, TypePropertyData(ArrayProperty, InnerProperty));
					TypeClassBuilder->AddProperty(TypeProperty);
				}
				else if (StructInnerProperty->Struct->GetName() == TEXT("NoesisKeyTime"))
				{
					Noesis::TypeProperty* TypeProperty = new TypePropertyNoesisObjectWrapper<NoesisStructWrapper>(PropertyId, Noesis::TypeOf<NoesisArrayWrapperBase>(), &NoesisStructWrapper::GetArrayProperty<Noesis::KeyTime>, nullptr, TypePropertyData(ArrayProperty, InnerProperty));
					TypeClassBuilder->AddProperty(TypeProperty);
				}
				else
				{
					Noesis::TypeProperty* TypeProperty = new TypePropertyNoesisObjectWrapper<NoesisStructWrapper>(PropertyId, Noesis::TypeOf<NoesisArrayWrapperBase>(), &NoesisStructWrapper::GetArrayProperty<NoesisStructWrapper>, nullptr, TypePropertyData(ArrayProperty, InnerProperty));
					TypeClassBuilder->AddProperty(TypeProperty);
				}
			}
			else if (UObjectProperty* ObjectInnerProperty = Cast<UObjectProperty>(InnerProperty))
			{
				if (ObjectInnerProperty->PropertyClass == UTexture2D::StaticClass() || ObjectInnerProperty->PropertyClass == UTextureRenderTarget2D::StaticClass())
				{
					Noesis::TypeProperty* TypeProperty = new TypePropertyNoesisObjectWrapper<NoesisStructWrapper>(PropertyId, Noesis::TypeOf<NoesisArrayWrapperBase>(), &NoesisStructWrapper::GetArrayProperty<Noesis::TextureSource>, nullptr, TypePropertyData(ArrayProperty, InnerProperty));
					TypeClassBuilder->AddProperty(TypeProperty);
				}
				else
				{
					Noesis::TypeProperty* TypeProperty = new TypePropertyNoesisObjectWrapper<NoesisStructWrapper>(PropertyId, Noesis::TypeOf<NoesisArrayWrapperBase>(), &NoesisStructWrapper::GetArrayProperty<NoesisObjectWrapper>, nullptr, TypePropertyData(ArrayProperty, InnerProperty));
					TypeClassBuilder->AddProperty(TypeProperty);
				}
			}
			else if (UEnumProperty* EnumInnerProperty = Cast<UEnumProperty>(InnerProperty))
			{
				NoesisCreateTypeEnumForUEnum(EnumInnerProperty->GetEnum());
				Noesis::TypeProperty* TypeProperty = new TypePropertyNoesisObjectWrapper<NoesisStructWrapper>(PropertyId, Noesis::TypeOf<NoesisArrayWrapperBase>(), &NoesisStructWrapper::GetArrayProperty<NoesisEnumWrapper>, nullptr, TypePropertyData(ArrayProperty, EnumInnerProperty));
				TypeClassBuilder->AddProperty(TypeProperty);
			}
			else if (UByteProperty* ByteInnerProperty = Cast<UByteProperty>(InnerProperty))
			{
				if (ByteInnerProperty->Enum)
				{
					Noesis::TypeEnum* TypeEnum = NoesisCreateTypeEnumForUEnum(ByteInnerProperty->Enum);
					Noesis::TypeProperty* TypeProperty = new TypePropertyNoesisObjectWrapper<NoesisStructWrapper>(PropertyId, TypeEnum, &NoesisStructWrapper::GetArrayProperty<NoesisEnumWrapper>, nullptr, TypePropertyData(ArrayProperty, InnerProperty));
					TypeClassBuilder->AddProperty(TypeProperty);
				}
			}

		}
	}
}

void UClassTypeFiller(Noesis::Type* Type)
{
	const char* ClassName = Type->GetName();
	check(RegisterNameMap.Find(NsStringToFString(ClassName)));
	UClass* Class = LoadObject<UClass>(nullptr, **RegisterNameMap.Find(NsStringToFString(ClassName)));

	const Noesis::TypeClass* ParentType = NoesisObjectWrapper::StaticGetClassType(nullptr);
	UClass* SuperClass = Class->GetSuperClass();
	if (SuperClass)
	{
		ParentType = NoesisCreateTypeClassForUClass(SuperClass);
	}

	NoesisTypeClass* TypeClass = Noesis::DynamicCast<NoesisTypeClass*>(Type);
	TypeClass->Class = Class;
	check(TypeClass);

	Noesis::TypeClassBuilder* TypeClassBuilder = (Noesis::TypeClassBuilder*)TypeClass;

	TypeClassBuilder->AddBase(ParentType);

	for (TFieldIterator<UProperty> PropertyIt(Class, EFieldIteratorFlags::ExcludeSuper); PropertyIt; ++PropertyIt)
	{
		UProperty* Property = *PropertyIt;
		FString PropertyName = Property->GetName();
		bool IsReadOnly = Property->HasAllPropertyFlags(CPF_BlueprintReadOnly);
		Noesis::Symbol PropertyId = Noesis::Symbol(TCHARToNsString(*PropertyName).Str());

		if (Property->IsA<UIntProperty>())
		{
			Noesis::TypeProperty* TypeProperty = new TypePropertyNoesisObjectWrapper<NoesisObjectWrapper>(PropertyId, Noesis::TypeOf<int>(), &NoesisObjectWrapper::GetProperty<int>, IsReadOnly ? nullptr : &NoesisObjectWrapper::SetProperty<int>, TypePropertyData(Property));
			TypeClassBuilder->AddProperty(TypeProperty);
		}
		else if (Property->IsA<UFloatProperty>())
		{
			Noesis::TypeProperty* TypeProperty = new TypePropertyNoesisObjectWrapper<NoesisObjectWrapper>(PropertyId, Noesis::TypeOf<float>(), &NoesisObjectWrapper::GetProperty<float>, IsReadOnly ? nullptr : &NoesisObjectWrapper::SetProperty<float>, TypePropertyData(Property));
			TypeClassBuilder->AddProperty(TypeProperty);
		}
		else if (Property->IsA<UBoolProperty>())
		{
			Noesis::TypeProperty* TypeProperty = new TypePropertyNoesisObjectWrapper<NoesisObjectWrapper>(PropertyId, Noesis::TypeOf<bool>(), &NoesisObjectWrapper::GetProperty<bool>, IsReadOnly ? nullptr : &NoesisObjectWrapper::SetProperty<bool>, TypePropertyData(Property));
			TypeClassBuilder->AddProperty(TypeProperty);
		}
		else if (Property->IsA<UStrProperty>())
		{
			Noesis::TypeProperty* TypeProperty = new TypePropertyNoesisObjectWrapper<NoesisObjectWrapper>(PropertyId, Noesis::TypeOf<Noesis::String>(), &NoesisObjectWrapper::GetProperty<Noesis::String>, IsReadOnly ? nullptr : &NoesisObjectWrapper::SetProperty<Noesis::String>, TypePropertyData(Property));
			TypeClassBuilder->AddProperty(TypeProperty);
		}
		else if (Property->IsA<UTextProperty>())
		{
			Noesis::TypeProperty* TypeProperty = new TypePropertyNoesisObjectWrapper<NoesisObjectWrapper>(PropertyId, Noesis::TypeOf<Noesis::String>(), &NoesisObjectWrapper::GetProperty<Noesis::String>, IsReadOnly ? nullptr : &NoesisObjectWrapper::SetProperty<Noesis::String>, TypePropertyData(Property));
			TypeClassBuilder->AddProperty(TypeProperty);
		}
		else if (UStructProperty* StructProperty = Cast<UStructProperty>(Property))
		{
			if (StructProperty->Struct->GetFName() == NAME_Color)
			{
				Noesis::TypeProperty* TypeProperty = new TypePropertyNoesisObjectWrapper<NoesisObjectWrapper>(PropertyId, Noesis::TypeOf<Noesis::Color>(), &NoesisObjectWrapper::GetProperty<Noesis::Color>, IsReadOnly ? nullptr : &NoesisObjectWrapper::SetProperty<Noesis::Color>, TypePropertyData(Property));
				TypeClassBuilder->AddProperty(TypeProperty);
			}
			else if (StructProperty->Struct->GetFName() == NAME_Vector2D)
			{
				Noesis::TypeProperty* TypeProperty = new TypePropertyNoesisObjectWrapper<NoesisObjectWrapper>(PropertyId, Noesis::TypeOf<Noesis::Point>(), &NoesisObjectWrapper::GetProperty<Noesis::Point>, IsReadOnly ? nullptr : &NoesisObjectWrapper::SetProperty<Noesis::Point>, TypePropertyData(Property));
				TypeClassBuilder->AddProperty(TypeProperty);
			}
			else if (StructProperty->Struct->GetName() == TEXT("NoesisRect"))
			{
				Noesis::TypeProperty* TypeProperty = new TypePropertyNoesisObjectWrapper<NoesisObjectWrapper>(PropertyId, Noesis::TypeOf<Noesis::Rect>(), &NoesisObjectWrapper::GetProperty<Noesis::Rect>, IsReadOnly ? nullptr : &NoesisObjectWrapper::SetProperty<Noesis::Rect>, TypePropertyData(Property));
				TypeClassBuilder->AddProperty(TypeProperty);
			}
			else if (StructProperty->Struct->GetName() == TEXT("NoesisSize"))
			{
				Noesis::TypeProperty* TypeProperty = new TypePropertyNoesisObjectWrapper<NoesisObjectWrapper>(PropertyId, Noesis::TypeOf<Noesis::Size>(), &NoesisObjectWrapper::GetProperty<Noesis::Size>, IsReadOnly ? nullptr : &NoesisObjectWrapper::SetProperty<Noesis::Size>, TypePropertyData(Property));
				TypeClassBuilder->AddProperty(TypeProperty);
			}
			else if (StructProperty->Struct->GetName() == TEXT("NoesisThickness"))
			{
				Noesis::TypeProperty* TypeProperty = new TypePropertyNoesisObjectWrapper<NoesisObjectWrapper>(PropertyId, Noesis::TypeOf<Noesis::Thickness>(), &NoesisObjectWrapper::GetProperty<Noesis::Thickness>, IsReadOnly ? nullptr : &NoesisObjectWrapper::SetProperty<Noesis::Thickness>, TypePropertyData(Property));
				TypeClassBuilder->AddProperty(TypeProperty);
			}
			else if (StructProperty->Struct->GetName() == TEXT("NoesisCornerRadius"))
			{
				Noesis::TypeProperty* TypeProperty = new TypePropertyNoesisObjectWrapper<NoesisObjectWrapper>(PropertyId, Noesis::TypeOf<Noesis::CornerRadius>(), &NoesisObjectWrapper::GetProperty<Noesis::CornerRadius>, IsReadOnly ? nullptr : &NoesisObjectWrapper::SetProperty<Noesis::CornerRadius>, TypePropertyData(Property));
				TypeClassBuilder->AddProperty(TypeProperty);
			}
			else if (StructProperty->Struct->GetName() == TEXT("NoesisTimeSpan"))
			{
				Noesis::TypeProperty* TypeProperty = new TypePropertyNoesisObjectWrapper<NoesisObjectWrapper>(PropertyId, Noesis::TypeOf<Noesis::TimeSpan>(), &NoesisObjectWrapper::GetProperty<Noesis::TimeSpan>, IsReadOnly ? nullptr : &NoesisObjectWrapper::SetProperty<Noesis::TimeSpan>, TypePropertyData(Property));
				TypeClassBuilder->AddProperty(TypeProperty);
			}
			else if (StructProperty->Struct->GetName() == TEXT("NoesisDuration"))
			{
				Noesis::TypeProperty* TypeProperty = new TypePropertyNoesisObjectWrapper<NoesisObjectWrapper>(PropertyId, Noesis::TypeOf<Noesis::Duration>(), &NoesisObjectWrapper::GetProperty<Noesis::Duration>, IsReadOnly ? nullptr : &NoesisObjectWrapper::SetProperty<Noesis::Duration>, TypePropertyData(Property));
				TypeClassBuilder->AddProperty(TypeProperty);
			}
			else if (StructProperty->Struct->GetName() == TEXT("NoesisKeyTime"))
			{
				Noesis::TypeProperty* TypeProperty = new TypePropertyNoesisObjectWrapper<NoesisObjectWrapper>(PropertyId, Noesis::TypeOf<Noesis::KeyTime>(), &NoesisObjectWrapper::GetProperty<Noesis::KeyTime>, IsReadOnly ? nullptr : &NoesisObjectWrapper::SetProperty<Noesis::KeyTime>, TypePropertyData(Property));
				TypeClassBuilder->AddProperty(TypeProperty);
			}
			else
			{
				Noesis::TypeProperty* TypeProperty = new TypePropertyNoesisObjectWrapper<NoesisObjectWrapper>(PropertyId, Noesis::TypeOf<NoesisStructWrapper>(), &NoesisObjectWrapper::GetProperty<NoesisStructWrapper>, IsReadOnly ? nullptr : &NoesisObjectWrapper::SetProperty<NoesisStructWrapper>, TypePropertyData(Property));
				TypeClassBuilder->AddProperty(TypeProperty);
			}
		}
		else if (UObjectProperty* ObjectProperty = Cast<UObjectProperty>(Property))
		{
			if (ObjectProperty->PropertyClass == UTexture2D::StaticClass() || ObjectProperty->PropertyClass == UTextureRenderTarget2D::StaticClass())
			{
				Noesis::TypeProperty* TypeProperty = new TypePropertyNoesisObjectWrapper<NoesisObjectWrapper>(PropertyId, Noesis::TypeOf<Noesis::TextureSource>(), &NoesisObjectWrapper::GetProperty<Noesis::TextureSource>, IsReadOnly ? nullptr : &NoesisObjectWrapper::SetProperty<Noesis::TextureSource>, TypePropertyData(Property));
				TypeClassBuilder->AddProperty(TypeProperty);
			}
			else
			{
				Noesis::TypeProperty* TypeProperty = new TypePropertyNoesisObjectWrapper<NoesisObjectWrapper>(PropertyId, Noesis::TypeOf<NoesisObjectWrapper>(), &NoesisObjectWrapper::GetProperty<NoesisObjectWrapper>, IsReadOnly ? nullptr : &NoesisObjectWrapper::SetProperty<NoesisObjectWrapper>, TypePropertyData(Property));
				TypeClassBuilder->AddProperty(TypeProperty);
			}
		}
		else if (UEnumProperty* EnumProperty = Cast<UEnumProperty>(Property))
		{
			Noesis::TypeEnum* TypeEnum = NoesisCreateTypeEnumForUEnum(EnumProperty->GetEnum());
			Noesis::TypeProperty* TypeProperty = new TypePropertyNoesisObjectWrapper<NoesisObjectWrapper>(PropertyId, TypeEnum, &NoesisObjectWrapper::GetProperty<NoesisEnumWrapper>, IsReadOnly ? nullptr : &NoesisObjectWrapper::SetProperty<NoesisEnumWrapper>, TypePropertyData(EnumProperty));
			TypeClassBuilder->AddProperty(TypeProperty);
		}
		else if (UByteProperty* ByteProperty = Cast<UByteProperty>(Property))
		{
			if (ByteProperty->Enum)
			{
				Noesis::TypeEnum* TypeEnum = NoesisCreateTypeEnumForUEnum(ByteProperty->Enum);
				Noesis::TypeProperty* TypeProperty = new TypePropertyNoesisObjectWrapper<NoesisObjectWrapper>(PropertyId, TypeEnum, &NoesisObjectWrapper::GetProperty<NoesisEnumWrapper>, IsReadOnly ? nullptr : &NoesisObjectWrapper::SetProperty<NoesisEnumWrapper>, TypePropertyData(ByteProperty));
				TypeClassBuilder->AddProperty(TypeProperty);
			}
		}
		else if (UArrayProperty* ArrayProperty = Cast<UArrayProperty>(Property))
		{
			UProperty* InnerProperty = ArrayProperty->Inner;
			if (InnerProperty->IsA<UIntProperty>())
			{
				Noesis::TypeProperty* TypeProperty = new TypePropertyNoesisObjectWrapper<NoesisObjectWrapper>(PropertyId, Noesis::TypeOf<NoesisArrayWrapperBase>(), &NoesisObjectWrapper::GetArrayProperty<int>, IsReadOnly ? nullptr : &NoesisObjectWrapper::SetArrayProperty<int>, TypePropertyData(ArrayProperty, InnerProperty));
				TypeClassBuilder->AddProperty(TypeProperty);
			}
			else if (InnerProperty->IsA<UFloatProperty>())
			{
				Noesis::TypeProperty* TypeProperty = new TypePropertyNoesisObjectWrapper<NoesisObjectWrapper>(PropertyId, Noesis::TypeOf<NoesisArrayWrapperBase>(), &NoesisObjectWrapper::GetArrayProperty<float>, IsReadOnly ? nullptr : &NoesisObjectWrapper::SetArrayProperty<float>, TypePropertyData(ArrayProperty, InnerProperty));
				TypeClassBuilder->AddProperty(TypeProperty);
			}
			else if (InnerProperty->IsA<UBoolProperty>())
			{
				Noesis::TypeProperty* TypeProperty = new TypePropertyNoesisObjectWrapper<NoesisObjectWrapper>(PropertyId, Noesis::TypeOf<NoesisArrayWrapperBase>(), &NoesisObjectWrapper::GetArrayProperty<bool>, IsReadOnly ? nullptr : &NoesisObjectWrapper::SetArrayProperty<bool>, TypePropertyData(ArrayProperty, InnerProperty));
				TypeClassBuilder->AddProperty(TypeProperty);
			}
			else if (InnerProperty->IsA<UStrProperty>())
			{
				Noesis::TypeProperty* TypeProperty = new TypePropertyNoesisObjectWrapper<NoesisObjectWrapper>(PropertyId, Noesis::TypeOf<NoesisArrayWrapperBase>(), &NoesisObjectWrapper::GetArrayProperty<Noesis::String>, IsReadOnly ? nullptr : &NoesisObjectWrapper::SetArrayProperty<Noesis::String>, TypePropertyData(ArrayProperty, InnerProperty));
				TypeClassBuilder->AddProperty(TypeProperty);
			}
			else if (InnerProperty->IsA<UTextProperty>())
			{
				Noesis::TypeProperty* TypeProperty = new TypePropertyNoesisObjectWrapper<NoesisObjectWrapper>(PropertyId, Noesis::TypeOf<NoesisArrayWrapperBase>(), &NoesisObjectWrapper::GetArrayProperty<Noesis::String>, IsReadOnly ? nullptr : &NoesisObjectWrapper::SetArrayProperty<Noesis::String>, TypePropertyData(ArrayProperty, InnerProperty));
				TypeClassBuilder->AddProperty(TypeProperty);
			}
			else if (UStructProperty* StructInnerProperty = Cast<UStructProperty>(InnerProperty))
			{
				if (StructInnerProperty->Struct->GetFName() == NAME_Color)
				{
					Noesis::TypeProperty* TypeProperty = new TypePropertyNoesisObjectWrapper<NoesisObjectWrapper>(PropertyId, Noesis::TypeOf<NoesisArrayWrapperBase>(), &NoesisObjectWrapper::GetArrayProperty<Noesis::Color>, IsReadOnly ? nullptr : &NoesisObjectWrapper::SetArrayProperty<Noesis::Color>, TypePropertyData(ArrayProperty, InnerProperty));
					TypeClassBuilder->AddProperty(TypeProperty);
				}
				else if (StructInnerProperty->Struct->GetFName() == NAME_Vector2D)
				{
					Noesis::TypeProperty* TypeProperty = new TypePropertyNoesisObjectWrapper<NoesisObjectWrapper>(PropertyId, Noesis::TypeOf<NoesisArrayWrapperBase>(), &NoesisObjectWrapper::GetArrayProperty<Noesis::Point>, IsReadOnly ? nullptr : &NoesisObjectWrapper::SetArrayProperty<Noesis::Point>, TypePropertyData(ArrayProperty, InnerProperty));
					TypeClassBuilder->AddProperty(TypeProperty);
				}
				else if (StructInnerProperty->Struct->GetName() == TEXT("NoesisRect"))
				{
					Noesis::TypeProperty* TypeProperty = new TypePropertyNoesisObjectWrapper<NoesisObjectWrapper>(PropertyId, Noesis::TypeOf<NoesisArrayWrapperBase>(), &NoesisObjectWrapper::GetArrayProperty<Noesis::Rect>, IsReadOnly ? nullptr : &NoesisObjectWrapper::SetArrayProperty<Noesis::Rect>, TypePropertyData(ArrayProperty, InnerProperty));
					TypeClassBuilder->AddProperty(TypeProperty);
				}
				else if (StructInnerProperty->Struct->GetName() == TEXT("NoesisSize"))
				{
					Noesis::TypeProperty* TypeProperty = new TypePropertyNoesisObjectWrapper<NoesisObjectWrapper>(PropertyId, Noesis::TypeOf<NoesisArrayWrapperBase>(), &NoesisObjectWrapper::GetArrayProperty<Noesis::Size>, IsReadOnly ? nullptr : &NoesisObjectWrapper::SetArrayProperty<Noesis::Size>, TypePropertyData(ArrayProperty, InnerProperty));
					TypeClassBuilder->AddProperty(TypeProperty);
				}
				else if (StructInnerProperty->Struct->GetName() == TEXT("NoesisThickness"))
				{
					Noesis::TypeProperty* TypeProperty = new TypePropertyNoesisObjectWrapper<NoesisObjectWrapper>(PropertyId, Noesis::TypeOf<NoesisArrayWrapperBase>(), &NoesisObjectWrapper::GetArrayProperty<Noesis::Thickness>, IsReadOnly ? nullptr : &NoesisObjectWrapper::SetArrayProperty<Noesis::Thickness>, TypePropertyData(ArrayProperty, InnerProperty));
					TypeClassBuilder->AddProperty(TypeProperty);
				}
				else if (StructInnerProperty->Struct->GetName() == TEXT("NoesisCornerRadius"))
				{
					Noesis::TypeProperty* TypeProperty = new TypePropertyNoesisObjectWrapper<NoesisObjectWrapper>(PropertyId, Noesis::TypeOf<NoesisArrayWrapperBase>(), &NoesisObjectWrapper::GetArrayProperty<Noesis::CornerRadius>, IsReadOnly ? nullptr : &NoesisObjectWrapper::SetArrayProperty<Noesis::CornerRadius>, TypePropertyData(ArrayProperty, InnerProperty));
					TypeClassBuilder->AddProperty(TypeProperty);
				}
				else if (StructInnerProperty->Struct->GetName() == TEXT("NoesisTimeSpan"))
				{
					Noesis::TypeProperty* TypeProperty = new TypePropertyNoesisObjectWrapper<NoesisObjectWrapper>(PropertyId, Noesis::TypeOf<NoesisArrayWrapperBase>(), &NoesisObjectWrapper::GetArrayProperty<Noesis::TimeSpan>, IsReadOnly ? nullptr : &NoesisObjectWrapper::SetArrayProperty<Noesis::TimeSpan>, TypePropertyData(ArrayProperty, InnerProperty));
					TypeClassBuilder->AddProperty(TypeProperty);
				}
				else if (StructInnerProperty->Struct->GetName() == TEXT("NoesisDuration"))
				{
					Noesis::TypeProperty* TypeProperty = new TypePropertyNoesisObjectWrapper<NoesisObjectWrapper>(PropertyId, Noesis::TypeOf<NoesisArrayWrapperBase>(), &NoesisObjectWrapper::GetArrayProperty<Noesis::Duration>, IsReadOnly ? nullptr : &NoesisObjectWrapper::SetArrayProperty<Noesis::Duration>, TypePropertyData(ArrayProperty, InnerProperty));
					TypeClassBuilder->AddProperty(TypeProperty);
				}
				else if (StructInnerProperty->Struct->GetName() == TEXT("NoesisKeyTime"))
				{
					Noesis::TypeProperty* TypeProperty = new TypePropertyNoesisObjectWrapper<NoesisObjectWrapper>(PropertyId, Noesis::TypeOf<NoesisArrayWrapperBase>(), &NoesisObjectWrapper::GetArrayProperty<Noesis::KeyTime>, IsReadOnly ? nullptr : &NoesisObjectWrapper::SetArrayProperty<Noesis::KeyTime>, TypePropertyData(ArrayProperty, InnerProperty));
					TypeClassBuilder->AddProperty(TypeProperty);
				}
				else
				{
					Noesis::TypeProperty* TypeProperty = new TypePropertyNoesisObjectWrapper<NoesisObjectWrapper>(PropertyId, Noesis::TypeOf<NoesisArrayWrapperBase>(), &NoesisObjectWrapper::GetArrayProperty<NoesisStructWrapper>, IsReadOnly ? nullptr : &NoesisObjectWrapper::SetArrayProperty<NoesisStructWrapper>, TypePropertyData(ArrayProperty, InnerProperty));
					TypeClassBuilder->AddProperty(TypeProperty);
				}
			}
			else if (UObjectProperty* ObjectInnerProperty = Cast<UObjectProperty>(InnerProperty))
			{
				if (ObjectInnerProperty->PropertyClass == UTexture2D::StaticClass() || ObjectInnerProperty->PropertyClass == UTextureRenderTarget2D::StaticClass())
				{
					Noesis::TypeProperty* TypeProperty = new TypePropertyNoesisObjectWrapper<NoesisObjectWrapper>(PropertyId, Noesis::TypeOf<NoesisArrayWrapperBase>(), &NoesisObjectWrapper::GetArrayProperty<Noesis::TextureSource>, IsReadOnly ? nullptr : &NoesisObjectWrapper::SetArrayProperty<Noesis::TextureSource>, TypePropertyData(ArrayProperty, InnerProperty));
					TypeClassBuilder->AddProperty(TypeProperty);
				}
				else
				{
					Noesis::TypeProperty* TypeProperty = new TypePropertyNoesisObjectWrapper<NoesisObjectWrapper>(PropertyId, Noesis::TypeOf<NoesisArrayWrapperBase>(), &NoesisObjectWrapper::GetArrayProperty<NoesisObjectWrapper>, IsReadOnly ? nullptr : &NoesisObjectWrapper::SetArrayProperty<NoesisObjectWrapper>, TypePropertyData(ArrayProperty, InnerProperty));
					TypeClassBuilder->AddProperty(TypeProperty);
				}
			}
			else if (UEnumProperty* EnumInnerProperty = Cast<UEnumProperty>(InnerProperty))
			{
				NoesisCreateTypeEnumForUEnum(EnumInnerProperty->GetEnum());
				Noesis::TypeProperty* TypeProperty = new TypePropertyNoesisObjectWrapper<NoesisObjectWrapper>(PropertyId, Noesis::TypeOf<NoesisArrayWrapperBase>(), &NoesisObjectWrapper::GetArrayProperty<NoesisEnumWrapper>, IsReadOnly ? nullptr : &NoesisObjectWrapper::SetArrayProperty<NoesisEnumWrapper>, TypePropertyData(ArrayProperty, EnumInnerProperty));
				TypeClassBuilder->AddProperty(TypeProperty);
			}
			else if (UByteProperty* ByteInnerProperty = Cast<UByteProperty>(InnerProperty))
			{
				if (ByteInnerProperty->Enum)
				{
					Noesis::TypeEnum* TypeEnum = NoesisCreateTypeEnumForUEnum(ByteInnerProperty->Enum);
					Noesis::TypeProperty* TypeProperty = new TypePropertyNoesisObjectWrapper<NoesisObjectWrapper>(PropertyId, TypeEnum, &NoesisObjectWrapper::GetArrayProperty<NoesisEnumWrapper>, IsReadOnly ? nullptr : &NoesisObjectWrapper::SetArrayProperty<NoesisEnumWrapper>, TypePropertyData(ArrayProperty, InnerProperty));
					TypeClassBuilder->AddProperty(TypeProperty);
				}
			}

		}
	}

	for (TFieldIterator<UFunction> FunctionIt(Class, EFieldIteratorFlags::ExcludeSuper); FunctionIt; ++FunctionIt)
	{
		UFunction* Function = *FunctionIt;

		bool HasNoParams = Function->NumParms == 0;
		bool HasOneParam = Function->NumParms == 1 && !Function->HasAnyFunctionFlags(FUNC_HasOutParms);
		UField* Param = HasOneParam ? Function->Children : nullptr;

		if (HasNoParams || HasOneParam)
		{
			UFunction* CanExecuteFunction = Class->FindFunctionByName(*(FString(TEXT("CanExecute")) + Function->GetName()), EIncludeSuperFlag::ExcludeSuper);
			if (CanExecuteFunction)
			{
				bool CanExecuteHasNoParams = CanExecuteFunction->NumParms == 1 &&
					CanExecuteFunction->HasAnyFunctionFlags(FUNC_HasOutParms) &&
					CanExecuteFunction->Children->IsA<UBoolProperty>();
				bool CanExecuteHasOneParam = CanExecuteFunction->NumParms == 2 &&
					CanExecuteFunction->HasAnyFunctionFlags(FUNC_HasOutParms) &&
					(!Param || CanExecuteFunction->Children->GetClass() == Param->GetClass()) &&
					CanExecuteFunction->Children->Next->IsA<UBoolProperty>();
				if (!CanExecuteHasNoParams && !CanExecuteHasOneParam)
				{
					CanExecuteFunction = nullptr;
				}
				else if (CanExecuteHasOneParam)
				{
					Param = CanExecuteFunction->Children;
				}
			}

			if (!Param)
			{
				Noesis::TypeProperty* TypeProperty = new TypePropertyNoesisObjectWrapper<NoesisObjectWrapper>(Noesis::Symbol(TCHARToNsString(*Function->GetName()).Str()), Noesis::TypeOf<NoesisFunctionWrapper>(), &NoesisObjectWrapper::GetCommandProperty, nullptr, TypePropertyData(Function, CanExecuteFunction));
				TypeClassBuilder->AddProperty(TypeProperty);
			}
			else if (Param->IsA<UIntProperty>())
			{
				Noesis::TypeProperty* TypeProperty = new TypePropertyNoesisObjectWrapper<NoesisObjectWrapper>(Noesis::Symbol(TCHARToNsString(*Function->GetName()).Str()), Noesis::TypeOf<NoesisFunctionWrapper>(), &NoesisObjectWrapper::GetCommandOneParamProperty<int>, nullptr, TypePropertyData(Function, CanExecuteFunction));
				TypeClassBuilder->AddProperty(TypeProperty);
			}
			else if (Param->IsA<UFloatProperty>())
			{
				Noesis::TypeProperty* TypeProperty = new TypePropertyNoesisObjectWrapper<NoesisObjectWrapper>(Noesis::Symbol(TCHARToNsString(*Function->GetName()).Str()), Noesis::TypeOf<NoesisFunctionWrapper>(), &NoesisObjectWrapper::GetCommandOneParamProperty<float>, nullptr, TypePropertyData(Function, CanExecuteFunction));
				TypeClassBuilder->AddProperty(TypeProperty);
			}
			else if (Param->IsA<UBoolProperty>())
			{
				Noesis::TypeProperty* TypeProperty = new TypePropertyNoesisObjectWrapper<NoesisObjectWrapper>(Noesis::Symbol(TCHARToNsString(*Function->GetName()).Str()), Noesis::TypeOf<NoesisFunctionWrapper>(), &NoesisObjectWrapper::GetCommandOneParamProperty<bool>, nullptr, TypePropertyData(Function, CanExecuteFunction));
				TypeClassBuilder->AddProperty(TypeProperty);
			}
			else if (Param->IsA<UStrProperty>())
			{
				Noesis::TypeProperty* TypeProperty = new TypePropertyNoesisObjectWrapper<NoesisObjectWrapper>(Noesis::Symbol(TCHARToNsString(*Function->GetName()).Str()), Noesis::TypeOf<NoesisFunctionWrapper>(), &NoesisObjectWrapper::GetCommandOneParamProperty<Noesis::String>, nullptr, TypePropertyData(Function, CanExecuteFunction));
				TypeClassBuilder->AddProperty(TypeProperty);
			}
			else if (Param->IsA<UTextProperty>())
			{
				Noesis::TypeProperty* TypeProperty = new TypePropertyNoesisObjectWrapper<NoesisObjectWrapper>(Noesis::Symbol(TCHARToNsString(*Function->GetName()).Str()), Noesis::TypeOf<NoesisFunctionWrapper>(), &NoesisObjectWrapper::GetCommandOneParamProperty<Noesis::String>, nullptr, TypePropertyData(Function, CanExecuteFunction));
				TypeClassBuilder->AddProperty(TypeProperty);
			}
			else if (UStructProperty* StructOutParam = Cast<UStructProperty>(Param))
			{
				if (StructOutParam->Struct->GetFName() == NAME_Color)
				{
					Noesis::TypeProperty* TypeProperty = new TypePropertyNoesisObjectWrapper<NoesisObjectWrapper>(Noesis::Symbol(TCHARToNsString(*Function->GetName()).Str()), Noesis::TypeOf<NoesisFunctionWrapper>(), &NoesisObjectWrapper::GetCommandOneParamProperty<Noesis::Color>, nullptr, TypePropertyData(Function, CanExecuteFunction));
					TypeClassBuilder->AddProperty(TypeProperty);
				}
				else if (StructOutParam->Struct->GetFName() == NAME_Vector2D)
				{
					Noesis::TypeProperty* TypeProperty = new TypePropertyNoesisObjectWrapper<NoesisObjectWrapper>(Noesis::Symbol(TCHARToNsString(*Function->GetName()).Str()), Noesis::TypeOf<NoesisFunctionWrapper>(), &NoesisObjectWrapper::GetCommandOneParamProperty<Noesis::Point>, nullptr, TypePropertyData(Function, CanExecuteFunction));
					TypeClassBuilder->AddProperty(TypeProperty);
				}
				else if (StructOutParam->Struct->GetName() == TEXT("NoesisRect"))
				{
					Noesis::TypeProperty* TypeProperty = new TypePropertyNoesisObjectWrapper<NoesisObjectWrapper>(Noesis::Symbol(TCHARToNsString(*Function->GetName()).Str()), Noesis::TypeOf<NoesisFunctionWrapper>(), &NoesisObjectWrapper::GetCommandOneParamProperty<Noesis::Rect>, nullptr, TypePropertyData(Function, CanExecuteFunction));
					TypeClassBuilder->AddProperty(TypeProperty);
				}
				else if (StructOutParam->Struct->GetName() == TEXT("NoesisSize"))
				{
					Noesis::TypeProperty* TypeProperty = new TypePropertyNoesisObjectWrapper<NoesisObjectWrapper>(Noesis::Symbol(TCHARToNsString(*Function->GetName()).Str()), Noesis::TypeOf<NoesisFunctionWrapper>(), &NoesisObjectWrapper::GetCommandOneParamProperty<Noesis::Size>, nullptr, TypePropertyData(Function, CanExecuteFunction));
					TypeClassBuilder->AddProperty(TypeProperty);
				}
				else if (StructOutParam->Struct->GetName() == TEXT("NoesisThickness"))
				{
					Noesis::TypeProperty* TypeProperty = new TypePropertyNoesisObjectWrapper<NoesisObjectWrapper>(Noesis::Symbol(TCHARToNsString(*Function->GetName()).Str()), Noesis::TypeOf<NoesisFunctionWrapper>(), &NoesisObjectWrapper::GetCommandOneParamProperty<Noesis::Thickness>, nullptr, TypePropertyData(Function, CanExecuteFunction));
					TypeClassBuilder->AddProperty(TypeProperty);
				}
				else if (StructOutParam->Struct->GetName() == TEXT("NoesisCornerRadius"))
				{
					Noesis::TypeProperty* TypeProperty = new TypePropertyNoesisObjectWrapper<NoesisObjectWrapper>(Noesis::Symbol(TCHARToNsString(*Function->GetName()).Str()), Noesis::TypeOf<NoesisFunctionWrapper>(), &NoesisObjectWrapper::GetCommandOneParamProperty<Noesis::CornerRadius>, nullptr, TypePropertyData(Function, CanExecuteFunction));
					TypeClassBuilder->AddProperty(TypeProperty);
				}
				else if (StructOutParam->Struct->GetName() == TEXT("NoesisTimeSpan"))
				{
					Noesis::TypeProperty* TypeProperty = new TypePropertyNoesisObjectWrapper<NoesisObjectWrapper>(Noesis::Symbol(TCHARToNsString(*Function->GetName()).Str()), Noesis::TypeOf<NoesisFunctionWrapper>(), &NoesisObjectWrapper::GetCommandOneParamProperty<Noesis::TimeSpan>, nullptr, TypePropertyData(Function, CanExecuteFunction));
					TypeClassBuilder->AddProperty(TypeProperty);
				}
				else if (StructOutParam->Struct->GetName() == TEXT("NoesisDuration"))
				{
					Noesis::TypeProperty* TypeProperty = new TypePropertyNoesisObjectWrapper<NoesisObjectWrapper>(Noesis::Symbol(TCHARToNsString(*Function->GetName()).Str()), Noesis::TypeOf<NoesisFunctionWrapper>(), &NoesisObjectWrapper::GetCommandOneParamProperty<Noesis::Duration>, nullptr, TypePropertyData(Function, CanExecuteFunction));
					TypeClassBuilder->AddProperty(TypeProperty);
				}
				else if (StructOutParam->Struct->GetName() == TEXT("NoesisKeyTime"))
				{
					Noesis::TypeProperty* TypeProperty = new TypePropertyNoesisObjectWrapper<NoesisObjectWrapper>(Noesis::Symbol(TCHARToNsString(*Function->GetName()).Str()), Noesis::TypeOf<NoesisFunctionWrapper>(), &NoesisObjectWrapper::GetCommandOneParamProperty<Noesis::KeyTime>, nullptr, TypePropertyData(Function, CanExecuteFunction));
					TypeClassBuilder->AddProperty(TypeProperty);
				}
				else
				{
					Noesis::TypeProperty* TypeProperty = new TypePropertyNoesisObjectWrapper<NoesisObjectWrapper>(Noesis::Symbol(TCHARToNsString(*Function->GetName()).Str()), Noesis::TypeOf<NoesisFunctionWrapper>(), &NoesisObjectWrapper::GetCommandOneParamProperty<NoesisStructWrapper>, nullptr, TypePropertyData(Function, CanExecuteFunction));
					TypeClassBuilder->AddProperty(TypeProperty);
				}
			}
			else if (UObjectProperty* ObjectOutParam = Cast<UObjectProperty>(Param))
			{
				if (ObjectOutParam->PropertyClass == UTexture2D::StaticClass() || ObjectOutParam->PropertyClass == UTextureRenderTarget2D::StaticClass())
				{
					Noesis::TypeProperty* TypeProperty = new TypePropertyNoesisObjectWrapper<NoesisObjectWrapper>(Noesis::Symbol(TCHARToNsString(*Function->GetName()).Str()), Noesis::TypeOf<NoesisFunctionWrapper>(), &NoesisObjectWrapper::GetCommandOneParamProperty<Noesis::TextureSource>, nullptr, TypePropertyData(Function, CanExecuteFunction));
					TypeClassBuilder->AddProperty(TypeProperty);
				}
				else
				{
					Noesis::TypeProperty* TypeProperty = new TypePropertyNoesisObjectWrapper<NoesisObjectWrapper>(Noesis::Symbol(TCHARToNsString(*Function->GetName()).Str()), Noesis::TypeOf<NoesisFunctionWrapper>(), &NoesisObjectWrapper::GetCommandOneParamProperty<NoesisObjectWrapper>, nullptr, TypePropertyData(Function, CanExecuteFunction));
					TypeClassBuilder->AddProperty(TypeProperty);
				}
			}
			else if (UEnumProperty* EnumOutParam = Cast<UEnumProperty>(Param))
			{
				Noesis::TypeProperty* TypeProperty = new TypePropertyNoesisObjectWrapper<NoesisObjectWrapper>(Noesis::Symbol(TCHARToNsString(*Function->GetName()).Str()), Noesis::TypeOf<NoesisFunctionWrapper>(), &NoesisObjectWrapper::GetCommandOneParamProperty<NoesisEnumWrapper>, nullptr, TypePropertyData(Function, CanExecuteFunction));
				TypeClassBuilder->AddProperty(TypeProperty);
			}
			else if (UByteProperty* ByteOutParam = Cast<UByteProperty>(Param))
			{
				if (ByteOutParam->Enum)
				{
					Noesis::TypeProperty* TypeProperty = new TypePropertyNoesisObjectWrapper<NoesisObjectWrapper>(Noesis::Symbol(TCHARToNsString(*Function->GetName()).Str()), Noesis::TypeOf<NoesisFunctionWrapper>(), &NoesisObjectWrapper::GetCommandOneParamProperty<NoesisEnumWrapper>, nullptr, TypePropertyData(Function, CanExecuteFunction));
					TypeClassBuilder->AddProperty(TypeProperty);
				}
			}
		}

		if (Function->GetName().StartsWith(TEXT("Get")) && Function->NumParms == 1 && Function->HasAnyFunctionFlags(FUNC_HasOutParms))
		{
			UProperty* OutParam = CastChecked<UProperty>(Function->Children);

			FString SetterName = Function->GetName();
			SetterName[0] = TEXT('S');
			UFunction* Setter = Class->FindFunctionByName(*SetterName, EIncludeSuperFlag::ExcludeSuper);
			if (!Setter || Setter->NumParms != 1 || Setter->HasAnyFunctionFlags(FUNC_HasOutParms) || !CastChecked<UProperty>(Setter->Children)->SameType(OutParam))
			{
				Setter = nullptr;
			}

			if (OutParam->IsA<UIntProperty>())
			{
				Noesis::TypeProperty* TypeProperty = new TypePropertyNoesisObjectWrapper<NoesisObjectWrapper>(Noesis::Symbol(TCHARToNsString(*Function->GetName().RightChop(3)).Str()), Noesis::TypeOf<int>(), &NoesisObjectWrapper::GetFunctionProperty<int>, Setter ? &NoesisObjectWrapper::SetFunctionProperty<int> : nullptr, TypePropertyData(Function, Setter));
				TypeClassBuilder->AddProperty(TypeProperty);
			}
			else if (OutParam->IsA<UFloatProperty>())
			{
				Noesis::TypeProperty* TypeProperty = new TypePropertyNoesisObjectWrapper<NoesisObjectWrapper>(Noesis::Symbol(TCHARToNsString(*Function->GetName().RightChop(3)).Str()), Noesis::TypeOf<float>(), &NoesisObjectWrapper::GetFunctionProperty<float>, Setter ? &NoesisObjectWrapper::SetFunctionProperty<float> : nullptr, TypePropertyData(Function, Setter));
				TypeClassBuilder->AddProperty(TypeProperty);
			}
			else if (OutParam->IsA<UBoolProperty>())
			{
				Noesis::TypeProperty* TypeProperty = new TypePropertyNoesisObjectWrapper<NoesisObjectWrapper>(Noesis::Symbol(TCHARToNsString(*Function->GetName().RightChop(3)).Str()), Noesis::TypeOf<bool>(), &NoesisObjectWrapper::GetFunctionProperty<bool>, Setter ? &NoesisObjectWrapper::SetFunctionProperty<bool> : nullptr, TypePropertyData(Function, Setter));
				TypeClassBuilder->AddProperty(TypeProperty);
			}
			else if (OutParam->IsA<UStrProperty>())
			{
				Noesis::TypeProperty* TypeProperty = new TypePropertyNoesisObjectWrapper<NoesisObjectWrapper>(Noesis::Symbol(TCHARToNsString(*Function->GetName().RightChop(3)).Str()), Noesis::TypeOf<Noesis::String>(), &NoesisObjectWrapper::GetFunctionProperty<Noesis::String>, Setter ? &NoesisObjectWrapper::SetFunctionProperty<Noesis::String> : nullptr, TypePropertyData(Function, Setter));
				TypeClassBuilder->AddProperty(TypeProperty);
			}
			else if (OutParam->IsA<UTextProperty>())
			{
				Noesis::TypeProperty* TypeProperty = new TypePropertyNoesisObjectWrapper<NoesisObjectWrapper>(Noesis::Symbol(TCHARToNsString(*Function->GetName().RightChop(3)).Str()), Noesis::TypeOf<Noesis::String>(), &NoesisObjectWrapper::GetFunctionProperty<Noesis::String>, Setter ? &NoesisObjectWrapper::SetFunctionProperty<Noesis::String> : nullptr, TypePropertyData(Function, Setter));
				TypeClassBuilder->AddProperty(TypeProperty);
			}
			else if (UStructProperty* StructOutParam = Cast<UStructProperty>(OutParam))
			{
				if (StructOutParam->Struct->GetFName() == NAME_Color)
				{
					Noesis::TypeProperty* TypeProperty = new TypePropertyNoesisObjectWrapper<NoesisObjectWrapper>(Noesis::Symbol(TCHARToNsString(*Function->GetName().RightChop(3)).Str()), Noesis::TypeOf<Noesis::Color>(), &NoesisObjectWrapper::GetFunctionProperty<Noesis::Color>, Setter ? &NoesisObjectWrapper::SetFunctionProperty<Noesis::Color> : nullptr, TypePropertyData(Function, Setter));
					TypeClassBuilder->AddProperty(TypeProperty);
				}
				else if (StructOutParam->Struct->GetFName() == NAME_Vector2D)
				{
					Noesis::TypeProperty* TypeProperty = new TypePropertyNoesisObjectWrapper<NoesisObjectWrapper>(Noesis::Symbol(TCHARToNsString(*Function->GetName().RightChop(3)).Str()), Noesis::TypeOf<Noesis::Point>(), &NoesisObjectWrapper::GetFunctionProperty<Noesis::Point>, Setter ? &NoesisObjectWrapper::SetFunctionProperty<Noesis::Point> : nullptr, TypePropertyData(Function, Setter));
					TypeClassBuilder->AddProperty(TypeProperty);
				}
				else if (StructOutParam->Struct->GetName() == TEXT("NoesisRect"))
				{
					Noesis::TypeProperty* TypeProperty = new TypePropertyNoesisObjectWrapper<NoesisObjectWrapper>(Noesis::Symbol(TCHARToNsString(*Function->GetName().RightChop(3)).Str()), Noesis::TypeOf<Noesis::Rect>(), &NoesisObjectWrapper::GetFunctionProperty<Noesis::Rect>, Setter ? &NoesisObjectWrapper::SetFunctionProperty<Noesis::Rect> : nullptr, TypePropertyData(Function, Setter));
					TypeClassBuilder->AddProperty(TypeProperty);
				}
				else if (StructOutParam->Struct->GetName() == TEXT("NoesisSize"))
				{
					Noesis::TypeProperty* TypeProperty = new TypePropertyNoesisObjectWrapper<NoesisObjectWrapper>(Noesis::Symbol(TCHARToNsString(*Function->GetName().RightChop(3)).Str()), Noesis::TypeOf<Noesis::Size>(), &NoesisObjectWrapper::GetFunctionProperty<Noesis::Size>, Setter ? &NoesisObjectWrapper::SetFunctionProperty<Noesis::Size> : nullptr, TypePropertyData(Function, Setter));
					TypeClassBuilder->AddProperty(TypeProperty);
				}
				else if (StructOutParam->Struct->GetName() == TEXT("NoesisThickness"))
				{
					Noesis::TypeProperty* TypeProperty = new TypePropertyNoesisObjectWrapper<NoesisObjectWrapper>(Noesis::Symbol(TCHARToNsString(*Function->GetName().RightChop(3)).Str()), Noesis::TypeOf<Noesis::Thickness>(), &NoesisObjectWrapper::GetFunctionProperty<Noesis::Thickness>, Setter ? &NoesisObjectWrapper::SetFunctionProperty<Noesis::Thickness> : nullptr, TypePropertyData(Function, Setter));
					TypeClassBuilder->AddProperty(TypeProperty);
				}
				else if (StructOutParam->Struct->GetName() == TEXT("NoesisCornerRadius"))
				{
					Noesis::TypeProperty* TypeProperty = new TypePropertyNoesisObjectWrapper<NoesisObjectWrapper>(Noesis::Symbol(TCHARToNsString(*Function->GetName().RightChop(3)).Str()), Noesis::TypeOf<Noesis::CornerRadius>(), &NoesisObjectWrapper::GetFunctionProperty<Noesis::CornerRadius>, Setter ? &NoesisObjectWrapper::SetFunctionProperty<Noesis::CornerRadius> : nullptr, TypePropertyData(Function, Setter));
					TypeClassBuilder->AddProperty(TypeProperty);
				}
				else if (StructOutParam->Struct->GetName() == TEXT("NoesisTimeSpan"))
				{
					Noesis::TypeProperty* TypeProperty = new TypePropertyNoesisObjectWrapper<NoesisObjectWrapper>(Noesis::Symbol(TCHARToNsString(*Function->GetName().RightChop(3)).Str()), Noesis::TypeOf<Noesis::TimeSpan>(), &NoesisObjectWrapper::GetFunctionProperty<Noesis::TimeSpan>, Setter ? &NoesisObjectWrapper::SetFunctionProperty<Noesis::TimeSpan> : nullptr, TypePropertyData(Function, Setter));
					TypeClassBuilder->AddProperty(TypeProperty);
				}
				else if (StructOutParam->Struct->GetName() == TEXT("NoesisDuration"))
				{
					Noesis::TypeProperty* TypeProperty = new TypePropertyNoesisObjectWrapper<NoesisObjectWrapper>(Noesis::Symbol(TCHARToNsString(*Function->GetName().RightChop(3)).Str()), Noesis::TypeOf<Noesis::Duration>(), &NoesisObjectWrapper::GetFunctionProperty<Noesis::Duration>, Setter ? &NoesisObjectWrapper::SetFunctionProperty<Noesis::Duration> : nullptr, TypePropertyData(Function, Setter));
					TypeClassBuilder->AddProperty(TypeProperty);
				}
				else if (StructOutParam->Struct->GetName() == TEXT("NoesisKeyTime"))
				{
					Noesis::TypeProperty* TypeProperty = new TypePropertyNoesisObjectWrapper<NoesisObjectWrapper>(Noesis::Symbol(TCHARToNsString(*Function->GetName().RightChop(3)).Str()), Noesis::TypeOf<Noesis::KeyTime>(), &NoesisObjectWrapper::GetFunctionProperty<Noesis::KeyTime>, Setter ? &NoesisObjectWrapper::SetFunctionProperty<Noesis::KeyTime> : nullptr, TypePropertyData(Function, Setter));
					TypeClassBuilder->AddProperty(TypeProperty);
				}
				else
				{
					Noesis::TypeProperty* TypeProperty = new TypePropertyNoesisObjectWrapper<NoesisObjectWrapper>(Noesis::Symbol(TCHARToNsString(*Function->GetName().RightChop(3)).Str()), Noesis::TypeOf<NoesisStructWrapper>(), &NoesisObjectWrapper::GetFunctionProperty<NoesisStructWrapper>, Setter ? &NoesisObjectWrapper::SetFunctionProperty<NoesisStructWrapper> : nullptr, TypePropertyData(Function, Setter));
					TypeClassBuilder->AddProperty(TypeProperty);
				}
			}
			else if (UObjectProperty* ObjectOutParam = Cast<UObjectProperty>(OutParam))
			{
				if (ObjectOutParam->PropertyClass == UTexture2D::StaticClass() || ObjectOutParam->PropertyClass == UTextureRenderTarget2D::StaticClass())
				{
					Noesis::TypeProperty* TypeProperty = new TypePropertyNoesisObjectWrapper<NoesisObjectWrapper>(Noesis::Symbol(TCHARToNsString(*Function->GetName().RightChop(3)).Str()), Noesis::TypeOf<Noesis::TextureSource>(), &NoesisObjectWrapper::GetFunctionProperty<Noesis::TextureSource>, Setter ? &NoesisObjectWrapper::SetFunctionProperty<Noesis::TextureSource> : nullptr, TypePropertyData(Function, Setter));
					TypeClassBuilder->AddProperty(TypeProperty);
				}
				else
				{
					Noesis::TypeProperty* TypeProperty = new TypePropertyNoesisObjectWrapper<NoesisObjectWrapper>(Noesis::Symbol(TCHARToNsString(*Function->GetName().RightChop(3)).Str()), Noesis::TypeOf<NoesisObjectWrapper>(), &NoesisObjectWrapper::GetFunctionProperty<NoesisObjectWrapper>, Setter ? &NoesisObjectWrapper::SetFunctionProperty<NoesisObjectWrapper> : nullptr, TypePropertyData(Function, Setter));
					TypeClassBuilder->AddProperty(TypeProperty);
				}
			}
			else if (UEnumProperty* EnumOutParam = Cast<UEnumProperty>(OutParam))
			{
				Noesis::TypeEnum* TypeEnum = NoesisCreateTypeEnumForUEnum(EnumOutParam->GetEnum());
				Noesis::TypeProperty* TypeProperty = new TypePropertyNoesisObjectWrapper<NoesisObjectWrapper>(Noesis::Symbol(TCHARToNsString(*Function->GetName().RightChop(3)).Str()), TypeEnum, &NoesisObjectWrapper::GetFunctionProperty<NoesisEnumWrapper>, Setter ? &NoesisObjectWrapper::SetFunctionProperty<NoesisEnumWrapper> : nullptr, TypePropertyData(Function, Setter));
				TypeClassBuilder->AddProperty(TypeProperty);
			}
			else if (UByteProperty* ByteOutParam = Cast<UByteProperty>(OutParam))
			{
				if (ByteOutParam->Enum)
				{
					Noesis::TypeEnum* TypeEnum = NoesisCreateTypeEnumForUEnum(ByteOutParam->Enum);
					Noesis::TypeProperty* TypeProperty = new TypePropertyNoesisObjectWrapper<NoesisObjectWrapper>(Noesis::Symbol(TCHARToNsString(*Function->GetName().RightChop(3)).Str()), TypeEnum, &NoesisObjectWrapper::GetFunctionProperty<NoesisEnumWrapper>, Setter ? &NoesisObjectWrapper::SetFunctionProperty<NoesisEnumWrapper> : nullptr, TypePropertyData(Function, Setter));
					TypeClassBuilder->AddProperty(TypeProperty);
				}
			}
		}
	}
}

Noesis::TypeClass* NoesisCreateTypeClassForUClass(UClass* Class)
{
	FString ClassName;
	if (Class->ClassGeneratedBy)
	{
		ClassName = Class->ClassGeneratedBy->GetPathName();
	}
	else
	{
		ClassName = Class->GetPathName();
	}
	FString AnsiClassName(TCHARToNsString(*RegisterNameFromPath(ClassName)).Str());
	RegisterNameMap.Add(AnsiClassName, Class->GetPathName());
	const char* PersistentClassName = GetPersistentName(AnsiClassName);
	Noesis::TypeClass* TypeClass = nullptr;
	if (auto TypeClassPtr = ClassMap.Find(Class))
	{
		check(!FCStringAnsi::Strcmp(PersistentClassName, TypeClassPtr->Value));
		TypeClass = TypeClassPtr->Key;
	}
	if (!TypeClass)
	{
		TypeClass = Noesis::DynamicCast<Noesis::TypeClass*>(Noesis::Reflection::RegisterType(PersistentClassName, &UClassTypeCreator, &UClassTypeFiller));
		ClassMap.Add(Class, MakeTuple(TypeClass, PersistentClassName));

#if WITH_EDITOR
		if (UBlueprint* Blueprint = Cast<UBlueprint>(Class->ClassGeneratedBy))
		{
			((NoesisTypeClass*)TypeClass)->ChangeDelegateHandle = Blueprint->OnChanged().AddStatic(&NoesisDestroyTypeClassForBlueprint);
		}
#endif
	}

	return TypeClass;
}

Noesis::Type* UEnumTypeCreator(Noesis::Symbol Name)
{
	return new NoesisTypeEnum(Name);
}

void UEnumTypeFiller(Noesis::Type* Type)
{
	const char* EnumName = Type->GetName();
	check(RegisterNameMap.Find(NsStringToFString(EnumName)));
	UEnum* Enum = LoadObject<UEnum>(nullptr, **RegisterNameMap.Find(NsStringToFString(EnumName)));


	Noesis::TypeEnum* TypeEnum = Noesis::DynamicCast<Noesis::TypeEnum*>(Type);
	check(TypeEnum);

	for (int32 Index = 0; Index != Enum->NumEnums(); ++Index)
	{
		const FString EnumValueName = Enum->GetDisplayNameTextByIndex(Index).ToString();
		FString AnsiEnumValueName(TCHARToNsString(*EnumValueName).Str());
		const char* PersistentEnumValueName = GetPersistentName(AnsiEnumValueName);
		TypeEnum->AddValue(Noesis::Symbol(PersistentEnumValueName), (int)Enum->GetValueByIndex(Index));
	}
}

Noesis::BaseComponent* CallbackCreateEnumConverter(Noesis::Symbol Id)
{
	NoesisTypeEnum** TypePtr = ConverterIdMap.Find(Id);
	if (TypePtr)
	{
		return new NoesisEnumConverter(*TypePtr);
	}
	return nullptr;
}

Noesis::TypeEnum* NoesisCreateTypeEnumForUEnum(UEnum* Enum)
{
	FString EnumName = Enum->GetPathName();
	FString AnsiEnumName(TCHARToNsString(*RegisterNameFromPath(EnumName)).Str());
	const char* PersistentEnumName = GetPersistentName(AnsiEnumName);
	RegisterNameMap.Add(AnsiEnumName, EnumName);
	Noesis::TypeEnum* TypeEnum = nullptr;
	if (auto TypeEnumPtr = EnumMap.Find(Enum))
	{
		check(!FCStringAnsi::Strcmp(PersistentEnumName, TypeEnumPtr->Value));
		TypeEnum = TypeEnumPtr->Key;
	}
	if (!TypeEnum)
	{
		TypeEnum = Noesis::DynamicCast<Noesis::TypeEnum*>(Noesis::Reflection::RegisterType(PersistentEnumName, &UEnumTypeCreator, &UEnumTypeFiller));

		Noesis::Symbol EnumConverterId = Noesis::IdOf("Converter<", PersistentEnumName, ">");
		Noesis::Factory::RegisterComponent(EnumConverterId, Noesis::Symbol::Null(), &CallbackCreateEnumConverter);
		EnumMap.Add(Enum, MakeTuple(TypeEnum, PersistentEnumName));
		ConverterIdMap.Add(EnumConverterId, (NoesisTypeEnum*)TypeEnum);
	}

	return TypeEnum;
}

void NoesisDestroyTypeClassForBlueprint(UBlueprint* Blueprint)
{
	UClass* Class = Blueprint->GeneratedClass;
	if (auto TypeClassPtr = ClassMap.Find(Class))
	{
#if WITH_EDITOR
		NoesisTypeClass* TypeClass = (NoesisTypeClass*)TypeClassPtr->Key;
		Blueprint->OnChanged().Remove(TypeClass->ChangeDelegateHandle);
#endif

		Noesis::Reflection::Unregister(TypeClassPtr->Key);
		ClassMap.Remove(Class);
	}
}

void NoesisDestroyAllTypes()
{
	for (auto Entry : ClassMap)
	{
		auto TypeClassPtr = &Entry.Value;
#if WITH_EDITOR
		UStruct* Struct = Entry.Key;
		if (UClass* Class = Cast<UClass>(Struct))
		{
			UBlueprint* Blueprint = Cast<UBlueprint>(((UClass*)Class)->ClassGeneratedBy);
			if (Blueprint)
			{
				NoesisTypeClass* TypeClass = (NoesisTypeClass*)TypeClassPtr->Key;
				Blueprint->OnChanged().Remove(TypeClass->ChangeDelegateHandle);
			}
		}
#endif

		Noesis::Reflection::Unregister(TypeClassPtr->Key);
	}

	ClassMap.Empty();

	for (auto Entry : EnumMap)
	{
		auto EnumClassPtr = &Entry.Value;
		Noesis::Reflection::Unregister(EnumClassPtr->Key);
	}

	EnumMap.Empty();
	
	for (auto Entry : ConverterIdMap)
	{
		Noesis::Factory::UnregisterComponent(Noesis::Symbol(Entry.Key));
	}
	ConverterIdMap.Empty();
}

void AssignStruct(void* BasePointer, UStructProperty* StructProperty, Noesis::BaseComponent* Value)
{
	check(Value->GetClassType()->IsDescendantOf(NoesisStructWrapper::StaticGetClassType(nullptr)));
	check(Noesis::DynamicCast<const NoesisTypeClass*>(Value->GetClassType()));
	check(((NoesisTypeClass*)Value->GetClassType())->Class == StructProperty->Struct);

	void* Dest = StructProperty->ContainerPtrToValuePtr<void>(BasePointer);
	NoesisStructWrapper* Wrapper = ((NoesisStructWrapper*)Value);
	StructProperty->Struct->CopyScriptStruct(Dest, Wrapper->GetStructPtr(), 1);
}

Noesis::TypeClass* NoesisCreateTypeClassForUStruct(UScriptStruct* Class)
{
	FString ClassName = Class->GetPathName();
	FString AnsiClassName(TCHARToNsString(*RegisterNameFromPath(ClassName)).Str());
	const char* PersistentClassName = GetPersistentName(AnsiClassName);
	RegisterNameMap.Add(AnsiClassName, ClassName);
	Noesis::TypeClass* TypeClass = nullptr;
	if (auto TypeClassPtr = ClassMap.Find(Class))
	{
		check(!FCStringAnsi::Strcmp(PersistentClassName, TypeClassPtr->Value));
		TypeClass = TypeClassPtr->Key;
	}
	if (!TypeClass)
	{
		TypeClass = Noesis::DynamicCast<Noesis::TypeClass*>(Noesis::Reflection::RegisterType(PersistentClassName, &UClassTypeCreator, &UStructTypeFiller));
		ClassMap.Add(Class, MakeTuple(TypeClass, PersistentClassName));
	}

	return TypeClass;
}

Noesis::Ptr<Noesis::BaseComponent> NoesisCreateComponentForUStruct(UScriptStruct* Struct, void* Src)
{
	if (!Src)
	{
		return nullptr;
	}

	Noesis::TypeClass* TypeClass = NoesisCreateTypeClassForUStruct(Struct);
	SIZE_T AllocSize = sizeof(NoesisStructWrapper) + Struct->GetStructureSize();
	void* Memory = NoesisAlloc(NoesisAllocationCallbackUserData, AllocSize);
	FMemory::Memzero(Memory, AllocSize);
	Noesis::Ptr<NoesisStructWrapper> Wrapper = *new NoesisStructWrapper(TypeClass, Struct);
	Struct->CopyScriptStruct(Wrapper->GetStructPtr(), Src, 1);

	return Wrapper;
}

NOESISRUNTIME_API Noesis::Ptr<Noesis::BaseComponent> NoesisCreateComponentForUObject(UObject* Object)
{
	if (!Object)
	{
		return nullptr;
	}

	UNoesisBaseComponent* BaseComponent = Cast<UNoesisBaseComponent>(Object);
	if (BaseComponent)
	{
		return BaseComponent->NoesisComponent;
	}

	Noesis::Ptr<Noesis::BaseComponent>* ComponentPtr = ObjectMap.Find(Object);
	if (ComponentPtr)
	{
		return *ComponentPtr;
	}

	UClass* Class = Object->GetClass();
	Noesis::Ptr<Noesis::BaseComponent> Wrapper;
	if (Class == UTexture2D::StaticClass() || Class == UTextureRenderTarget2D::StaticClass())
	{
		Wrapper = *new Noesis::TextureSource(NoesisCreateTexture((UTexture*)Object).GetPtr());
	}
	else
	{
		Noesis::TypeClass* TypeClass = NoesisCreateTypeClassForUClass(Class);
		Wrapper = *new NoesisObjectWrapper(TypeClass, Object);
	}
	ObjectMap.Add(Object, Wrapper);

	return Wrapper;
}

NOESISRUNTIME_API UObject* NoesisCreateUObjectForComponent(Noesis::BaseComponent* Component)
{
	UObject* const* ObjectPtr = ObjectMap.FindKey(Noesis::Ptr<Noesis::BaseComponent>(Component));
	if (ObjectPtr)
	{
		return *ObjectPtr;
	}

	UNoesisBaseComponent* BaseComponent = NewObject<UNoesisBaseComponent>();
	BaseComponent->NoesisComponent.Reset(Component);
	return BaseComponent;
}

NOESISRUNTIME_API void NoesisCopyUStructFromComponent(UScriptStruct* Struct, Noesis::BaseComponent* Component, void* Dest)
{
	check(Component->GetClassType()->IsDescendantOf(NoesisStructWrapper::StaticGetClassType(nullptr)));
	check(Noesis::DynamicCast<const NoesisTypeClass*>(Component->GetClassType()));
	check(((NoesisTypeClass*)Component->GetClassType())->Class == Struct);

	NoesisStructWrapper* Wrapper = ((NoesisStructWrapper*)Component);
	Struct->CopyScriptStruct(Dest, Wrapper->GetStructPtr(), 1);
}

void NoesisNotifyPropertyChanged(UObject* Owner, FName PropertyName)
{
	SCOPE_CYCLE_COUNTER(STAT_NoesisNotifyPropertyChanged);
	Noesis::Ptr<Noesis::BaseComponent>* WrapperPtr = ObjectMap.Find(Owner);
	if (WrapperPtr)
	{
		NoesisObjectWrapper* Wrapper = (NoesisObjectWrapper*)WrapperPtr->GetPtr();
		auto PropertySymbol = Noesis::Symbol(TCHARToNsString(*PropertyName.ToString()).Str());
#if DO_CHECK // Skip in shipping build
		if (!Wrapper->GetClassType()->FindProperty(PropertySymbol))
		{
			UE_LOG(LogNoesis, Warning, TEXT("Couldn't resolve property %s::%s"), *Owner->GetClass()->GetFName().ToString(), *PropertyName.ToString());
		}
#endif
		Wrapper->NotifyPropertyChanged(PropertySymbol);
	}
}

void NoesisNotifyArrayPropertyChanged(UObject* Owner, FName ArrayPropertyName)
{
	SCOPE_CYCLE_COUNTER(STAT_NoesisNotifyArrayPropertyChanged);
	Noesis::Ptr<Noesis::BaseComponent>* WrapperPtr = ObjectMap.Find(Owner);
	if (WrapperPtr)
	{
		NoesisObjectWrapper* Wrapper = (NoesisObjectWrapper*)WrapperPtr->GetPtr();
		const Noesis::TypeClass* WrapperTypeClass = Wrapper->GetClassType();
		const Noesis::TypeProperty* ArrayTypeProperty = WrapperTypeClass->FindProperty(Noesis::Symbol(TCHARToNsString(*ArrayPropertyName.ToString()).Str()));
		if (ArrayTypeProperty)
		{
			NoesisArrayWrapperBase* Array = (NoesisArrayWrapperBase*)(ArrayTypeProperty->GetComponent(Wrapper).GetPtr());
			if (Array)
			{
				Array->NotifyPostChanged();
			}
		}
#if DO_CHECK // Skip in shipping build
		else
		{
			UE_LOG(LogNoesis, Warning, TEXT("Couldn't resolve property %s::%s"), *Owner->GetClass()->GetFName().ToString(), *ArrayPropertyName.ToString());
		}
#endif
	}
}

void NoesisNotifyArrayPropertyPostAdd(void* ArrayPointer)
{
	SCOPE_CYCLE_COUNTER(STAT_NoesisNotifyArrayPropertyAdd);
	NoesisArrayWrapperBase** ArrayWrapperPtr = ArrayMap.Find(ArrayPointer);
	if (ArrayWrapperPtr)
	{
		NoesisArrayWrapperBase* Array = *ArrayWrapperPtr;
		Array->NotifyPostAdd();
	}
}

void NoesisNotifyArrayPropertyPostChanged(void* ArrayPointer)
{
	SCOPE_CYCLE_COUNTER(STAT_NoesisNotifyArrayPropertyChanged);
	NoesisArrayWrapperBase** ArrayWrapperPtr = ArrayMap.Find(ArrayPointer);
	if (ArrayWrapperPtr)
	{
		NoesisArrayWrapperBase* Array = *ArrayWrapperPtr;
		Array->NotifyPostChanged();
	}
}

void NoesisNotifyArrayPropertyPreAppend(void* ArrayPointer)
{
	SCOPE_CYCLE_COUNTER(STAT_NoesisNotifyArrayPropertyAppend);
	NoesisArrayWrapperBase** ArrayWrapperPtr = ArrayMap.Find(ArrayPointer);
	if (ArrayWrapperPtr)
	{
		NoesisArrayWrapperBase* Array = *ArrayWrapperPtr;
		Array->NotifyPreAppend();
	}
}

void NoesisNotifyArrayPropertyPostAppend(void* ArrayPointer)
{
	SCOPE_CYCLE_COUNTER(STAT_NoesisNotifyArrayPropertyAppend);
	NoesisArrayWrapperBase** ArrayWrapperPtr = ArrayMap.Find(ArrayPointer);
	if (ArrayWrapperPtr)
	{
		NoesisArrayWrapperBase* Array = *ArrayWrapperPtr;
		Array->NotifyPostAppend();
	}
}

void NoesisNotifyArrayPropertyPostInsert(void* ArrayPointer, int32 Index)
{
	SCOPE_CYCLE_COUNTER(STAT_NoesisNotifyArrayPropertyInsert);
	NoesisArrayWrapperBase** ArrayWrapperPtr = ArrayMap.Find(ArrayPointer);
	if (ArrayWrapperPtr)
	{
		NoesisArrayWrapperBase* Array = *ArrayWrapperPtr;
		Array->NotifyPostInsert(Index);
	}
}

void NoesisNotifyArrayPropertyPreRemove(void* ArrayPointer, int32 Index)
{
	SCOPE_CYCLE_COUNTER(STAT_NoesisNotifyArrayPropertyRemove);
	NoesisArrayWrapperBase** ArrayWrapperPtr = ArrayMap.Find(ArrayPointer);
	if (ArrayWrapperPtr)
	{
		NoesisArrayWrapperBase* Array = *ArrayWrapperPtr;
		Array->NotifyPreRemoveAt(Index);
	}
}

void NoesisNotifyArrayPropertyPostRemove(void* ArrayPointer, int32 Index)
{
	SCOPE_CYCLE_COUNTER(STAT_NoesisNotifyArrayPropertyRemove);
	NoesisArrayWrapperBase** ArrayWrapperPtr = ArrayMap.Find(ArrayPointer);
	if (ArrayWrapperPtr)
	{
		NoesisArrayWrapperBase* Array = *ArrayWrapperPtr;
		Array->NotifyPostRemoveAt(Index);
	}
}

void NoesisNotifyArrayPropertyPostClear(void* ArrayPointer)
{
	SCOPE_CYCLE_COUNTER(STAT_NoesisNotifyArrayPropertyClear);
	NoesisArrayWrapperBase** ArrayWrapperPtr = ArrayMap.Find(ArrayPointer);
	if (ArrayWrapperPtr)
	{
		NoesisArrayWrapperBase* Array = *ArrayWrapperPtr;
		Array->NotifyPostClear();
	}
}

void NoesisNotifyArrayPropertyPreSet(void* ArrayPointer, int32 Index)
{
	SCOPE_CYCLE_COUNTER(STAT_NoesisNotifyArrayPropertySet);
	NoesisArrayWrapperBase** ArrayWrapperPtr = ArrayMap.Find(ArrayPointer);
	if (ArrayWrapperPtr)
	{
		NoesisArrayWrapperBase* Array = *ArrayWrapperPtr;
		Array->NotifyPreSet(Index);
	}
}

void NoesisNotifyArrayPropertyPostSet(void* ArrayPointer, int32 Index)
{
	SCOPE_CYCLE_COUNTER(STAT_NoesisNotifyArrayPropertySet);
	NoesisArrayWrapperBase** ArrayWrapperPtr = ArrayMap.Find(ArrayPointer);
	if (ArrayWrapperPtr)
	{
		NoesisArrayWrapperBase* Array = *ArrayWrapperPtr;
		Array->NotifyPostSet(Index);
	}
}

void NoesisDeleteMaps()
{
	ClassMap.Reset();

	ObjectMap.Reset();
}

void NoesisGarbageCollected()
{
	if (GIsRunning)
	{
		SCOPE_CYCLE_COUNTER(STAT_NoesisGarbageCollected);
		for (auto It = ObjectMap.CreateIterator(); It; ++It)
		{
			auto& ObjectComponentPair = *It;
			if (ObjectComponentPair.Key->IsUnreachable())
			{
				It.RemoveCurrent();
			}
		}

		for (auto It = ClassMap.CreateIterator(); It; ++It)
		{
			auto& ClassTypeClassPair = *It;
			if (ClassTypeClassPair.Key->IsUnreachable())
			{
				Noesis::Reflection::Unregister(ClassTypeClassPair.Value.Key);
				It.RemoveCurrent();
			}
		}
	}
}

void NoesisReflectionRegistryCallback(Noesis::Symbol Name)
{
	const char* TypeName = Name.Str();
	FString* ObjectPath = RegisterNameMap.Find(NsStringToFString(TypeName));
	if (!ObjectPath)
	{
		NoesisRegisterTypes();
		ObjectPath = RegisterNameMap.Find(NsStringToFString(TypeName));
		if (!ObjectPath)
		{
			return;
		}
	}

	UObject* Object = LoadObject<UObject>(nullptr, **ObjectPath);
	if (!Object)
	{
		return;
	}
	if (Object->IsA<UClass>())
	{
		NoesisCreateTypeClassForUClass((UClass*)Object);
	}
	else if (Object->IsA<UScriptStruct>())
	{
		NoesisCreateTypeClassForUStruct((UScriptStruct*)Object);
	}
	else if (Object->IsA<UEnum>())
	{
		NoesisCreateTypeEnumForUEnum((UEnum*)Object);
	}
}

void NoesisRegisterTypes()
{
	for (TObjectIterator<UClass> It; It; ++It)
	{
		UClass* Class = *It;
		if (Class->ClassGeneratedBy)
		{
			UBlueprint* Blueprint = Cast<UBlueprint>(Class->ClassGeneratedBy);

			FString RegisterName = RegisterNameFromPath(Blueprint->GetPathName());
			RegisterNameMap.Add(RegisterName, Class->GetPathName());
		}
		else
		{
			FString RegisterName = RegisterNameFromPath(Class->GetPathName());
			RegisterNameMap.Add(RegisterName, Class->GetPathName());
		}
	}

	for (TObjectIterator<UScriptStruct> It; It; ++It)
	{
		UScriptStruct* Struct = *It;

		FString RegisterName = RegisterNameFromPath(Struct->GetPathName());
		RegisterNameMap.Add(RegisterName, Struct->GetPathName());
	}

	for (TObjectIterator<UEnum> It; It; ++It)
	{
		UEnum* Enum = *It;

		FString RegisterName = RegisterNameFromPath(Enum->GetPathName());
		RegisterNameMap.Add(RegisterName, Enum->GetPathName());
	}

	IAssetRegistry& AssetRegistry = FModuleManager::LoadModuleChecked<FAssetRegistryModule>("AssetRegistry").Get();
	TArray<FAssetData> Assets;

	AssetRegistry.GetAssetsByClass(UBlueprint::StaticClass()->GetFName(), Assets, true);
	for (auto Asset : Assets)
	{
		FString RegisterName = RegisterNameFromPath(Asset.ObjectPath.ToString());
		RegisterNameMap.Add(RegisterName, Asset.ObjectPath.ToString() + TEXT("_C"));
	}

	Assets.Empty();
	AssetRegistry.GetAssetsByClass(UUserDefinedStruct::StaticClass()->GetFName(), Assets, true);
	for (auto Asset : Assets)
	{
		FString RegisterName = RegisterNameFromPath(Asset.ObjectPath.ToString());
		RegisterNameMap.Add(RegisterName, Asset.ObjectPath.ToString());
	}

	Assets.Empty();
	AssetRegistry.GetAssetsByClass(UUserDefinedEnum::StaticClass()->GetFName(), Assets, true);
	for (auto Asset : Assets)
	{
		FString RegisterName = RegisterNameFromPath(Asset.ObjectPath.ToString());
		RegisterNameMap.Add(RegisterName, Asset.ObjectPath.ToString());
	}
}
