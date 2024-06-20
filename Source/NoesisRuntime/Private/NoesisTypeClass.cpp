////////////////////////////////////////////////////////////////////////////////////////////////////
// NoesisGUI - http://www.noesisengine.com
// Copyright (c) 2013 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#include "NoesisTypeClass.h"

// Core includes
#include "UObject/PropertyPortFlags.h"
#include "Misc/EngineVersionComparison.h"

// CoreUObject includes
#include "UObject/TextProperty.h"
#include "UObject/UObjectIterator.h"
#include "UObject/UObjectThreadContext.h"
#include "UObject/FieldIterator.h"
#include "UObject/Package.h"

// Engine includes
#include "Engine/Texture2D.h"
#include "Engine/TextureRenderTarget2D.h"
#include "Engine/Blueprint.h"
#include "Engine/UserDefinedStruct.h"
#include "Engine/UserDefinedEnum.h"
#include "Materials/Material.h"
#include "Materials/MaterialInstanceDynamic.h"
#include "Slate/SlateTextureAtlasInterface.h"
#if UE_VERSION_OLDER_THAN(5, 2, 0)
#include "MaterialShared.h"
#else
#include "MaterialDomain.h"
#endif

// MediaAsset includes
#include "MediaTexture.h"

// Slate includes
#include "Framework/Text/TextLayout.h"

// AssetRegistry includes
#include "AssetRegistry/AssetRegistryModule.h"
#include "AssetRegistry/IAssetRegistry.h"

// NoesisRuntime includes
#include "NoesisInstance.h"
#include "NoesisSupport.h"
#include "NoesisStructs.h"
#include "NoesisRuntimeModule.h"
#include "NoesisBaseComponent.h"
#include "NoesisRive.h"
#include "NoesisXaml.h"
#include "NoesisWorldUIComponent.h"

// Noesis includes
#include "NoesisSDK.h"

DECLARE_CYCLE_STAT(TEXT("NoesisNotifyPropertyChanged"), STAT_NoesisNotifyPropertyChanged, STATGROUP_Noesis);
DECLARE_CYCLE_STAT(TEXT("NoesisNotifyArrayPropertyAdd"), STAT_NoesisNotifyArrayPropertyAdd, STATGROUP_Noesis);
DECLARE_CYCLE_STAT(TEXT("NoesisNotifyArrayPropertyChanged"), STAT_NoesisNotifyArrayPropertyChanged, STATGROUP_Noesis);
DECLARE_CYCLE_STAT(TEXT("NoesisNotifyCanExecuteFunctionChanged"), STAT_NoesisNotifyCanExecuteFunctionChanged, STATGROUP_Noesis);
DECLARE_CYCLE_STAT(TEXT("NoesisNotifyArrayPropertyAppend"), STAT_NoesisNotifyArrayPropertyAppend, STATGROUP_Noesis);
DECLARE_CYCLE_STAT(TEXT("NoesisNotifyArrayPropertyInsert"), STAT_NoesisNotifyArrayPropertyInsert, STATGROUP_Noesis);
DECLARE_CYCLE_STAT(TEXT("NoesisNotifyArrayPropertyRemove"), STAT_NoesisNotifyArrayPropertyRemove, STATGROUP_Noesis);
DECLARE_CYCLE_STAT(TEXT("NoesisNotifyArrayPropertyClear"), STAT_NoesisNotifyArrayPropertyClear, STATGROUP_Noesis);
DECLARE_CYCLE_STAT(TEXT("NoesisNotifyArrayPropertyResize"), STAT_NoesisNotifyArrayPropertyResize, STATGROUP_Noesis);
DECLARE_CYCLE_STAT(TEXT("NoesisNotifyArrayPropertySet"), STAT_NoesisNotifyArrayPropertySet, STATGROUP_Noesis);
DECLARE_CYCLE_STAT(TEXT("NoesisGarbageCollected"), STAT_NoesisGarbageCollected, STATGROUP_Noesis);
DECLARE_CYCLE_STAT(TEXT("NoesisNotifyMapPropertyAdd"), STAT_NoesisNotifyMapPropertyAdd, STATGROUP_Noesis);
DECLARE_CYCLE_STAT(TEXT("NoesisNotifyMapPropertyChanged"), STAT_NoesisNotifyMapPropertyChanged, STATGROUP_Noesis);
DECLARE_CYCLE_STAT(TEXT("NoesisNotifyMapPropertyRemove"), STAT_NoesisNotifyMapPropertyRemove, STATGROUP_Noesis);

Noesis::Ptr<Noesis::BaseComponent> NoesisCreateComponentForTArray(void*, FArrayProperty*);
Noesis::Ptr<Noesis::BaseComponent> NoesisCreateComponentForTArrayStruct(void*, FArrayProperty*, void*);
const Noesis::Type* NoesisCreateTypeForTArray(FArrayProperty*);
Noesis::Ptr<Noesis::BaseComponent> NoesisCreateComponentForTMap(void* MapPtr, FMapProperty* MapProperty);
Noesis::Ptr<Noesis::BaseComponent> NoesisCreateComponentForTMapStruct(void* MapPtr, FMapProperty* MapProperty, void* StructPtr);
const Noesis::Type* NoesisCreateTypeForTMap(FMapProperty* MapProperty);
bool AssignStruct(void*, UScriptStruct*, Noesis::BaseComponent*);
bool AssignEnum(void*, UEnum*, FNumericProperty*, Noesis::BaseComponent*);
const Noesis::Type* NoesisGetTypeForUClass(UClass*);
const Noesis::Type* NoesisGetTypeForUStruct(UStruct*);
Noesis::TypeClass* NoesisCreateTypeClassForUMaterial(UMaterialInterface* Material);
Noesis::Ptr<Noesis::BaseComponent> NoesisCreateComponentForUTexture(UTexture*);

template<class UnrealType>
struct NoesisTypeTraits
{
	typedef UnrealType NoesisType;
	static NoesisType ToNoesis(const UnrealType& Value)
	{
		return Value;
	}
	static UnrealType ToUnreal(const NoesisType& Value)
	{
		return Value;
	}
	static bool Equals(const UnrealType& Left, const UnrealType& Right)
	{
		return Left == Right;
	}
};

template<>
struct NoesisTypeTraits<FString>
{
	typedef Noesis::String NoesisType;
	static Noesis::String ToNoesis(const FString& Value)
	{
		return TCHARToNsString(*Value);
	}
	static FString ToUnreal(const Noesis::String& Value)
	{
		return NsStringToFString(Value.Str());
	}
	static bool Equals(const FString& Left, const FString& Right)
	{
		return Left == Right;
	}
};

template<>
struct NoesisTypeTraits<FText>
{
	typedef Noesis::String NoesisType;
	static Noesis::String ToNoesis(const FText& Value)
	{
		return TCHARToNsString(*Value.ToString());
	}
	static FText ToUnreal(const Noesis::String& Value)
	{
		return FText::FromString(NsStringToFString(Value.Str()));
	}
	static bool Equals(const FText& Left, const FText& Right)
	{
		return Left.EqualTo(Right);
	}
};

template<>
struct NoesisTypeTraits<FColor>
{
	typedef Noesis::Color NoesisType;
	static Noesis::Color ToNoesis(const FColor& Value)
	{
#if PLATFORM_LITTLE_ENDIAN
		return Noesis::Color::FromPackedBGRA(Value.DWColor());
#else // PLATFORM_LITTLE_ENDIAN
		return Noesis::Color(Value.R, Value.G, Value.B, Value.A);
#endif
	}
	static FColor ToUnreal(const Noesis::Color& Value)
	{
#if PLATFORM_LITTLE_ENDIAN
		return FColor(Value.GetPackedColorBGRA());
#else // PLATFORM_LITTLE_ENDIAN
		return FColor(Value.G, Value.R, Value.A, Value.B);
#endif
	}
	static bool Equals(const FColor& Left, const FColor& Right)
	{
		return Left == Right;
	}
};

template<>
struct NoesisTypeTraits<FVector2D>
{
	typedef Noesis::Point NoesisType;
	static Noesis::Point ToNoesis(const FVector2D& Value)
	{
		return Noesis::Point(Value.X, Value.Y);
	}
	static FVector2D ToUnreal(const Noesis::Point& Value)
	{
		return FVector2D(Value.x, Value.y);
	}
	static bool Equals(const FVector2D& Left, const FVector2D& Right)
	{
		return Left == Right;
	}
};

template<>
struct NoesisTypeTraits<FBox2D>
{
	typedef Noesis::Rect NoesisType;
	static Noesis::Rect ToNoesis(const FBox2D& Value)
	{
		return Noesis::Rect(Value.Min.X, Value.Min.Y, Value.Max.X, Value.Max.Y);
	}
	static FBox2D ToUnreal(const Noesis::Rect& Value)
	{
		return FBox2D(FVector2D(Value.x, Value.y), FVector2D(Value.x + Value.width, Value.y + Value.height));
	}
	static bool Equals(const FBox2D& Left, const FBox2D& Right)
	{
		return Left == Right;
	}
};

template<>
struct NoesisTypeTraits<FNoesisSize>
{
	typedef Noesis::Size NoesisType;
	static Noesis::Size ToNoesis(const FNoesisSize& Value)
	{
		return Value.ToNoesis();
	}
	static FNoesisSize ToUnreal(const Noesis::Size& Value)
	{
		return FNoesisSize(Value);
	}
	static bool Equals(const FNoesisSize& Left, const FNoesisSize& Right)
	{
		return Left.Width == Right.Width && Left.Height == Right.Height;
	}
};

template<>
struct NoesisTypeTraits<FNoesisCornerRadius>
{
	typedef Noesis::CornerRadius NoesisType;
	static Noesis::CornerRadius ToNoesis(const FNoesisCornerRadius& Value)
	{
		return Value.ToNoesis();
	}
	static FNoesisCornerRadius ToUnreal(const Noesis::CornerRadius& Value)
	{
		return FNoesisCornerRadius(Value);
	}
	static bool Equals(const FNoesisCornerRadius& Left, const FNoesisCornerRadius& Right)
	{
		return Left.TopLeft == Right.TopLeft && Left.TopRight == Right.TopRight &&
			Left.BottomRight == Right.BottomRight && Left.BottomLeft == Right.BottomLeft;
	}
};

template<>
struct NoesisTypeTraits<FNoesisThickness>
{
	typedef Noesis::Thickness NoesisType;
	static Noesis::Thickness ToNoesis(const FNoesisThickness& Value)
	{
		return Value.ToNoesis();
	}
	static FNoesisThickness ToUnreal(const Noesis::Thickness& Value)
	{
		return FNoesisThickness(Value);
	}
	static bool Equals(const FNoesisThickness& Left, const FNoesisThickness& Right)
	{
		return Left.Left == Right.Left && Left.Top == Right.Top &&
			Left.Right == Right.Right && Left.Bottom == Right.Bottom;
	}
};

template<>
struct NoesisTypeTraits<FNoesisDuration>
{
	typedef Noesis::Duration NoesisType;
	static Noesis::Duration ToNoesis(const FNoesisDuration& Value)
	{
		return Value.ToNoesis();
	}
	static FNoesisDuration ToUnreal(const Noesis::Duration& Value)
	{
		return FNoesisDuration(Value);
	}
	static bool Equals(const FNoesisDuration& Left, const FNoesisDuration& Right)
	{
		return Left.DurationType == Right.DurationType && Left.Milliseconds == Right.Milliseconds;
	}
};

template<>
struct NoesisTypeTraits<FNoesisKeyTime>
{
	typedef Noesis::KeyTime NoesisType;
	static Noesis::KeyTime ToNoesis(const FNoesisKeyTime& Value)
	{
		return Value.ToNoesis();
	}
	static FNoesisKeyTime ToUnreal(const Noesis::KeyTime& Value)
	{
		return FNoesisKeyTime(Value);
	}
	static bool Equals(const FNoesisKeyTime& Left, const FNoesisKeyTime& Right)
	{
		return Left.TextForm == Right.TextForm;
	}
};

template<>
struct NoesisTypeTraits<FTimespan>
{
	typedef Noesis::TimeSpan NoesisType;
	static Noesis::TimeSpan ToNoesis(const FTimespan& Value)
	{
		return Noesis::TimeSpan((int64_t)Value.GetTicks());
	}
	static FTimespan ToUnreal(const Noesis::TimeSpan& Value)
	{
		return FTimespan(Value.GetTicks());
	}
	static bool Equals(const FTimespan& Left, const FTimespan& Right)
	{
		return Left.GetTicks() == Right.GetTicks();
	}
};

template<>
struct NoesisTypeTraits<FMatrix>
{
	typedef Noesis::Matrix4 NoesisType;
	static Noesis::Matrix4 ToNoesis(const FMatrix& Value)
	{
		return Noesis::Matrix4(
			Value.M[0][0], Value.M[0][1], Value.M[0][2], Value.M[0][3],
			Value.M[1][0], Value.M[1][1], Value.M[1][2], Value.M[1][3],
			Value.M[2][0], Value.M[2][1], Value.M[2][2], Value.M[2][3],
			Value.M[3][0], Value.M[3][1], Value.M[3][2], Value.M[3][3]
		);
	}
	static FMatrix ToUnreal(const Noesis::Matrix4& Value)
	{
		return FMatrix(
			FPlane(Value[0][0], Value[0][1], Value[0][2], Value[0][3]),
			FPlane(Value[1][0], Value[1][1], Value[1][2], Value[1][3]),
			FPlane(Value[2][0], Value[2][1], Value[2][2], Value[2][3]),
			FPlane(Value[3][0], Value[3][1], Value[3][2], Value[3][3])
		);
	}
	static bool Equals(const FMatrix& Left, const FMatrix& Right)
	{
		return Left == Right;
	}
};

template<>
struct NoesisTypeTraits<FTransform>
{
	typedef Noesis::Transform3 NoesisType;
	static Noesis::Transform3 ToNoesis(const FTransform& Value)
	{
		FMatrix Matrix = Value.ToMatrixWithScale();

		return Noesis::Transform3(
			Matrix.M[0][0], Matrix.M[0][1], Matrix.M[0][2],
			Matrix.M[1][0], Matrix.M[1][1], Matrix.M[1][2],
			Matrix.M[2][0], Matrix.M[2][1], Matrix.M[2][2],
			Matrix.M[3][0], Matrix.M[3][1], Matrix.M[3][2]
		);
	}
	static FTransform ToUnreal(const Noesis::Transform3& Value)
	{
		FMatrix Matrix(
			FPlane(Value[0][0], Value[0][1], Value[0][2], 0.f),
			FPlane(Value[1][0], Value[1][1], Value[1][2], 0.f),
			FPlane(Value[2][0], Value[2][1], Value[2][2], 0.f),
			FPlane(Value[3][0], Value[3][1], Value[3][2], 1.f)
		);
		return FTransform(Matrix);
	}
	static bool Equals(const FTransform& Left, const FTransform& Right)
	{
		return Left.Equals(Right);
	}
};

template<>
struct NoesisTypeTraits<ETextFlowDirection>
{
	typedef Noesis::FlowDirection NoesisType;
	static Noesis::FlowDirection ToNoesis(const ETextFlowDirection& Value)
	{
		switch (Value)
		{
		case ETextFlowDirection::Auto:
			{
				EFlowDirection FlowDirection = FLayoutLocalization::GetLocalizedLayoutDirection();
				return (FlowDirection == EFlowDirection::RightToLeft) ? Noesis::FlowDirection_RightToLeft : Noesis::FlowDirection_LeftToRight;
			}
		case ETextFlowDirection::LeftToRight:
			return Noesis::FlowDirection_LeftToRight;
		case ETextFlowDirection::RightToLeft:
			return Noesis::FlowDirection_RightToLeft;
		}
		return Noesis::FlowDirection_LeftToRight;
	}
	static ETextFlowDirection ToUnreal(const Noesis::FlowDirection& Value)
	{
		return (Value == Noesis::FlowDirection_LeftToRight) ? ETextFlowDirection::LeftToRight : ETextFlowDirection::RightToLeft;
	}
	static bool Equals(const ETextFlowDirection& Left, const ETextFlowDirection& Right)
	{
		return Left == Right;
	}
};

template<>
struct NoesisTypeTraits<UTexture2D*>
{
	typedef Noesis::TextureSource* NoesisType;
	static Noesis::Ptr<Noesis::BaseComponent> ToNoesis(UObject* Value)
	{
		check(Value == nullptr || Value->IsA<UTexture2D>());
		return NoesisCreateComponentForUTexture((UTexture2D*)Value);
	}
	static UObject* ToUnreal(Noesis::BaseComponent* Value)
	{
		return nullptr;
	}
	static bool Equals(UObject* Left, UObject* Right)
	{
		return Left == Right;
	}
};

template<>
struct NoesisTypeTraits<UTextureRenderTarget2D*>
{
	typedef Noesis::TextureSource* NoesisType;
	static Noesis::Ptr<Noesis::BaseComponent> ToNoesis(UObject* Value)
	{
		check(Value == nullptr || Value->IsA<UTextureRenderTarget2D>());
		return NoesisCreateComponentForUTexture((UTextureRenderTarget2D*)Value);
	}
	static UObject* ToUnreal(Noesis::BaseComponent* Value)
	{
		return nullptr;
	}
	static bool Equals(UObject* Left, UObject* Right)
	{
		return Left == Right;
	}
};

template<>
struct NoesisTypeTraits<UMediaTexture*>
{
	typedef Noesis::TextureSource* NoesisType;
	static Noesis::Ptr<Noesis::BaseComponent> ToNoesis(UObject* Value)
	{
		check(Value == nullptr || Value->IsA<UMediaTexture>());
		return NoesisCreateComponentForUTexture((UMediaTexture*)Value);
	}
	static UObject* ToUnreal(Noesis::BaseComponent* Value)
	{
		return nullptr;
	}
	static bool Equals(UObject* Left, UObject* Right)
	{
		return Left == Right;
	}
};

template<class T>
Noesis::Ptr<Noesis::BaseComponent> GenericGetter(void* BasePointer, FProperty* Property)
{
	void* Value = Property->template ContainerPtrToValuePtr<void>(BasePointer);
	T& TValue = *(T*)Value;
	return Noesis::Boxing::Box<typename NoesisTypeTraits<T>::NoesisType>(NoesisTypeTraits<T>::ToNoesis(TValue));
}

template<class T>
bool GenericSetter(Noesis::BaseComponent* Input, void* BasePointer, FProperty* Property)
{
	auto Boxed = Noesis::DynamicCast<Noesis::Boxed<typename NoesisTypeTraits<T>::NoesisType>*>(Input);
	if (Boxed == nullptr)
		return false;

	void* Value = Property->template ContainerPtrToValuePtr<void>(BasePointer);
	T TInput = NoesisTypeTraits<T>::ToUnreal(Noesis::Boxing::Unbox<typename NoesisTypeTraits<T>::NoesisType>(Input));
	T& TValue = *(T*)Value;
	bool Changed = !NoesisTypeTraits<T>::Equals(TInput, TValue);
	TValue = TInput;
	return Changed;
}

template<class T>
const Noesis::Type* GenericGetType(FProperty*)
{
	return Noesis::TypeOf<typename NoesisTypeTraits<T>::NoesisType>();
}

typedef Noesis::Ptr<Noesis::BaseComponent>(*GetterFn)(void*, FProperty*);
typedef bool (*SetterFn)(Noesis::BaseComponent*, void*, FProperty*);
typedef const Noesis::Type* (*GetTypeFn)(FProperty*);
struct NoesisTypeInfo
{
	GetterFn Getter;
	SetterFn Setter;
	GetTypeFn GetType;
};

TMap<UScriptStruct*, NoesisTypeInfo> StructTypeInfos;
TMap<UEnum*, NoesisTypeInfo> EnumTypeInfos;

Noesis::Ptr<Noesis::BaseComponent> StructGetter(void* BasePointer, FProperty* Property)
{
	check(Property->IsA<FStructProperty>());
	FStructProperty* StructProperty = (FStructProperty*)Property;
	NoesisTypeInfo* TypeInfo = StructTypeInfos.Find(StructProperty->Struct);
	if (TypeInfo != nullptr)
	{
		return (*TypeInfo->Getter)(BasePointer, Property);
	}
	void* Value = Property->template ContainerPtrToValuePtr<void>(BasePointer);
	return NoesisCreateComponentForUStruct(StructProperty->Struct, Value);
}

bool StructSetter(Noesis::BaseComponent* Input, void* BasePointer, FProperty* Property)
{
	check(Property->IsA<FStructProperty>());
	FStructProperty* StructProperty = (FStructProperty*)Property;
	NoesisTypeInfo* TypeInfo = StructTypeInfos.Find(StructProperty->Struct);
	if (TypeInfo != nullptr)
	{
		return (*TypeInfo->Setter)(Input, BasePointer, Property);
	}
	void* Value = Property->template ContainerPtrToValuePtr<void>(BasePointer);
	return AssignStruct(Value, StructProperty->Struct, Input);
}

const Noesis::Type* StructGetType(FProperty* Property)
{
	check(Property->IsA<FStructProperty>());
	FStructProperty* StructProperty = (FStructProperty*)Property;
	NoesisTypeInfo* TypeInfo = StructTypeInfos.Find(StructProperty->Struct);
	if (TypeInfo != nullptr)
	{
		return (*TypeInfo->GetType)(Property);
	}
	return NoesisGetTypeForUStruct(StructProperty->Struct);
	//return NoesisCreateTypeClassForUStruct(StructProperty->Struct);
}

Noesis::Ptr<Noesis::BaseComponent> EnumGetter(void* BasePointer, FProperty* Property)
{
	check(Property->IsA<FEnumProperty>());
	FEnumProperty* EnumProperty = (FEnumProperty*)Property;
	NoesisTypeInfo* TypeInfo = EnumTypeInfos.Find(EnumProperty->GetEnum());
	if (TypeInfo != nullptr)
	{
		return (*TypeInfo->Getter)(BasePointer, Property);
	}
	void* Value = Property->template ContainerPtrToValuePtr<void>(BasePointer);
	FNumericProperty* UnderlyingProperty = EnumProperty->GetUnderlyingProperty();
	check(UnderlyingProperty->IsInteger());
	int64 IntValue = UnderlyingProperty->GetSignedIntPropertyValue(Value);
	return NoesisCreateComponentForUEnum(EnumProperty->GetEnum(), IntValue);
}

bool EnumSetter(Noesis::BaseComponent* Input, void* BasePointer, FProperty* Property)
{
	check(Property->IsA<FEnumProperty>());
	FEnumProperty* EnumProperty = (FEnumProperty*)Property;
	NoesisTypeInfo* TypeInfo = EnumTypeInfos.Find(EnumProperty->GetEnum());
	if (TypeInfo != nullptr)
	{
		return (*TypeInfo->Setter)(Input, BasePointer, Property);
	}
	void* Value = Property->template ContainerPtrToValuePtr<void>(BasePointer);
	FNumericProperty* UnderlyingProperty = EnumProperty->GetUnderlyingProperty();
	check(UnderlyingProperty->IsInteger());
	return AssignEnum(Value, EnumProperty->GetEnum(), UnderlyingProperty, Input);
}

const Noesis::Type* EnumGetType(FProperty* Property)
{
	check(Property->IsA<FEnumProperty>());
	FEnumProperty* EnumProperty = (FEnumProperty*)Property;
	NoesisTypeInfo* TypeInfo = EnumTypeInfos.Find(EnumProperty->GetEnum());
	if (TypeInfo != nullptr)
	{
		return (*TypeInfo->GetType)(Property);
	}
	return NoesisCreateTypeEnumForUEnum(EnumProperty->GetEnum());
}

Noesis::Ptr<Noesis::BaseComponent> ByteGetter(void* BasePointer, FProperty* Property)
{
	check(Property->IsA<FByteProperty>());
	FByteProperty* ByteProperty = (FByteProperty*)Property;
	if (ByteProperty->Enum != nullptr)
	{
		void* Value = Property->template ContainerPtrToValuePtr<void>(BasePointer);
		uint8& ByteValue = *(uint8*)Value;
		return NoesisCreateComponentForUEnum(ByteProperty->Enum, (int64)ByteValue);
	}
	else
	{
		return GenericGetter<uint8>(BasePointer, Property);
	}
}

bool ByteSetter(Noesis::BaseComponent* Input, void* BasePointer, FProperty* Property)
{
	check(Property->IsA<FByteProperty>());
	FByteProperty* ByteProperty = (FByteProperty*)Property;
	if (ByteProperty->Enum != nullptr)
	{
		void* Value = Property->template ContainerPtrToValuePtr<void>(BasePointer);
		return AssignEnum(Value, ByteProperty->Enum, ByteProperty, Input);
	}
	else
	{
		return GenericSetter<uint8>(Input, BasePointer, Property);
	}
}

const Noesis::Type* ByteGetType(FProperty* Property)
{
	check(Property->IsA<FByteProperty>());
	FByteProperty* ByteProperty = (FByteProperty*)Property;
	if (ByteProperty->Enum != nullptr)
	{
		return NoesisCreateTypeEnumForUEnum(ByteProperty->Enum);
	}
	else
	{
		return Noesis::TypeOf<uint8>();
	}
}

typedef Noesis::Ptr<Noesis::BaseComponent> (*WrapperFn)(UObject*);
typedef UObject* (*UnwrapperFn)(Noesis::BaseComponent*);
typedef const Noesis::Type* (*GetTypeFn)(FProperty*);
struct NoesisClassConversion
{
	WrapperFn Wrapper;
	UnwrapperFn Unwrapper;
	const Noesis::Type* Type;

	template<class T>
	static NoesisClassConversion FromType()
	{
		NoesisClassConversion Ret;
		Ret.Wrapper = &NoesisTypeTraits<T>::ToNoesis;
		Ret.Unwrapper = &NoesisTypeTraits<T>::ToUnreal;
		Ret.Type = Noesis::TypeOf<typename NoesisTypeTraits<T>::NoesisType>();
		return Ret;
	}
};
TMap<UClass*, NoesisClassConversion> ClassConversions;

Noesis::Ptr<Noesis::BaseComponent> ObjectGetter(void* BasePointer, FProperty* Property)
{
	void* Value = Property->template ContainerPtrToValuePtr<void>(BasePointer);
	UObject*& Object = *(UObject**)Value;
	check(Property->IsA<FObjectProperty>());
	UClass* Class = Object != nullptr ? Object->GetClass() : nullptr;
	NoesisClassConversion* ClassConversion = Class != nullptr ? ClassConversions.Find(Class) : nullptr;
	if (ClassConversion != nullptr)
	{
		return (*ClassConversion->Wrapper)(Object);
	}
	else
	{
		return NoesisCreateComponentForUObject(Object);
	}
}

bool ObjectSetter(Noesis::BaseComponent* Input, void* BasePointer, FProperty* Property)
{
	void* Value = Property->template ContainerPtrToValuePtr<void>(BasePointer);
	UObject*& Object = *(UObject**)Value;
	check(Property->IsA<FObjectProperty>());
	UObject* InputObject = NoesisFindUObjectForComponent(Input);
	UClass* Class = InputObject != nullptr ? InputObject->GetClass() : nullptr;
	NoesisClassConversion* ClassConversion = Class != nullptr ? ClassConversions.Find(Class) : nullptr;
	if (ClassConversion != nullptr)
	{
		UObject* NewObject = (*ClassConversion->Unwrapper)(Input);
		bool Changed = Object != NewObject;
		Object = NewObject;
		return Changed;
	}
	else
	{
		UObject* NewObject = NoesisCreateUObjectForComponent(Input);
		bool Changed = Object != NewObject;
		Object = NewObject;
		return Changed;
	}
}

const Noesis::Type* ObjectGetType(FProperty* Property)
{
	check(Property->IsA<FObjectProperty>());
	FObjectProperty* ObjectProperty = (FObjectProperty*)Property;
	NoesisClassConversion* ClassConversion = ClassConversions.Find(ObjectProperty->PropertyClass);
	if (ClassConversion != nullptr)
	{
		return ClassConversion->Type;
	}
	else
	{
		return NoesisGetTypeForUClass(ObjectProperty->PropertyClass);
	}
}

TMap<FFieldClass*, NoesisTypeInfo> TypeInfos;

Noesis::Ptr<Noesis::BaseComponent> ArrayGetter(void* BasePointer, FProperty* Property)
{
	void* Value = Property->template ContainerPtrToValuePtr<void>(BasePointer);
	check(Property->IsA<FArrayProperty>());
	FArrayProperty* ArrayProperty = (FArrayProperty*)Property;
	if (Property->GetOwnerVariant().IsUObject() && Property->GetOwnerVariant().ToUObject()->IsA<UClass>())
	{
		return NoesisCreateComponentForTArray(Value, ArrayProperty);
	}
	else
	{
		return NoesisCreateComponentForTArrayStruct(Value, ArrayProperty, BasePointer);
	}
}

bool ArraySetter(Noesis::BaseComponent* Input, void* BasePointer, FProperty* Property)
{
	void* Value = Property->template ContainerPtrToValuePtr<void>(BasePointer);
	NS_LOG("Setting TArrays is not supported");
	return false;
}

const Noesis::Type* ArrayGetType(FProperty* Property)
{
	check(Property->IsA<FArrayProperty>());
	FArrayProperty* ArrayProperty = (FArrayProperty*)Property;
	FProperty* InnerProperty = ArrayProperty->Inner;
	NoesisTypeInfo* TypeInfo = TypeInfos.Find(InnerProperty->GetClass());
	if (TypeInfo != nullptr)
	{
		const Noesis::Type* InnerType = (*TypeInfo->GetType)(InnerProperty);
		if (InnerType != nullptr)
		{
			return NoesisCreateTypeForTArray(ArrayProperty);
		}
	}

	return nullptr;
}

Noesis::Ptr<Noesis::BaseComponent> MapGetter(void* BasePointer, FProperty* Property)
{
	void* Value = Property->template ContainerPtrToValuePtr<void>(BasePointer);
	check(Property->IsA<FMapProperty>());
	FMapProperty* MapProperty = (FMapProperty*)Property;
	if (Property->GetOwnerVariant().IsUObject() && Property->GetOwnerVariant().ToUObject()->IsA<UClass>())
	{
		return NoesisCreateComponentForTMap(Value, MapProperty);
	}
	else
	{
		return NoesisCreateComponentForTMapStruct(Value, MapProperty, BasePointer);
	}
}

bool MapSetter(Noesis::BaseComponent* Input, void* BasePointer, FProperty* Property)
{
	void* Value = Property->template ContainerPtrToValuePtr<void>(BasePointer);
	NS_LOG("Setting TMaps is not supported");
	return false;
}

const Noesis::Type* MapGetType(FProperty* Property)
{
	check(Property->IsA<FMapProperty>());
	FMapProperty* MapProperty = (FMapProperty*)Property;
	FProperty* KeyProperty = MapProperty->KeyProp;
	if (KeyProperty->IsA<FStrProperty>())
	{
		FProperty* ValueProperty = MapProperty->ValueProp;
		NoesisTypeInfo* TypeInfo = TypeInfos.Find(ValueProperty->GetClass());
		if (TypeInfo != nullptr)
		{
			const Noesis::Type* InnerType = (*TypeInfo->GetType)(ValueProperty);
			if (InnerType != nullptr)
			{
				return NoesisCreateTypeForTMap(MapProperty);
			}
		}
	}

	return nullptr;
}

void NoesisInitTypeTables()
{
	ClassConversions =
	{
		{UTexture2D::StaticClass(), NoesisClassConversion::FromType<UTexture2D*>() },
		{UTextureRenderTarget2D::StaticClass(), NoesisClassConversion::FromType<UTextureRenderTarget2D*>() },
		{UMediaTexture::StaticClass(), NoesisClassConversion::FromType<UMediaTexture*>() }
	};

	UScriptStruct* TimespanStruct = nullptr;
	for (TObjectIterator<UScriptStruct> It; It; ++It)
	{
		if (It->GetName() == TEXT("Timespan"))
		{
			TimespanStruct = *It;
			break;
		}
	}

	StructTypeInfos =
	{
		{TBaseStructure<FColor>::Get(), { &GenericGetter<FColor>, &GenericSetter<FColor>, &GenericGetType<FColor> }},
		{TBaseStructure<FVector2D>::Get(), { &GenericGetter<FVector2D>, &GenericSetter<FVector2D>, &GenericGetType<FVector2D> }},
		{TBaseStructure<FBox2D>::Get(), { &GenericGetter<FBox2D>, &GenericSetter<FBox2D>, &GenericGetType<FBox2D> }},
		{TBaseStructure<FNoesisSize>::Get(), { &GenericGetter<FNoesisSize>, &GenericSetter<FNoesisSize>, &GenericGetType<FNoesisSize> }},
		{TBaseStructure<FNoesisThickness>::Get(), { &GenericGetter<FNoesisThickness>, &GenericSetter<FNoesisThickness>, &GenericGetType<FNoesisThickness> }},
		{TBaseStructure<FNoesisCornerRadius>::Get(), { &GenericGetter<FNoesisCornerRadius>, &GenericSetter<FNoesisCornerRadius>, &GenericGetType<FNoesisCornerRadius> }},
		{TBaseStructure<FNoesisDuration>::Get(), { &GenericGetter<FNoesisDuration>, &GenericSetter<FNoesisDuration>, &GenericGetType<FNoesisDuration> }},
		{TBaseStructure<FNoesisKeyTime>::Get(), { &GenericGetter<FNoesisKeyTime>, &GenericSetter<FNoesisKeyTime>, &GenericGetType<FNoesisKeyTime> }},
		{TimespanStruct, { &GenericGetter<FTimespan>, &GenericSetter<FTimespan>, &GenericGetType<FTimespan> }},
		{TBaseStructure<FMatrix>::Get(), { &GenericGetter<FMatrix>, &GenericSetter<FMatrix>, &GenericGetType<FMatrix> }},
		{TBaseStructure<FTransform>::Get(), { &GenericGetter<FTransform>, &GenericSetter<FTransform>, &GenericGetType<FTransform> }}
	};

	EnumTypeInfos =
	{
		{StaticEnum<ETextFlowDirection>(), { &GenericGetter<ETextFlowDirection>, &GenericSetter<ETextFlowDirection>, &GenericGetType<ETextFlowDirection> }}
	};

	TypeInfos =
	{
		{FIntProperty::StaticClass(), { &GenericGetter<int32>, &GenericSetter<int32>, &GenericGetType<int32> }},
		{FFloatProperty::StaticClass(),{  &GenericGetter<float>, &GenericSetter<float>, &GenericGetType<float> }},
		{FDoubleProperty::StaticClass(),{  &GenericGetter<double>, &GenericSetter<double>, &GenericGetType<double> }},
		{FBoolProperty::StaticClass(), { &GenericGetter<bool>, &GenericSetter<bool>, &GenericGetType<bool> }},
		{FStrProperty::StaticClass(), { &GenericGetter<FString>, &GenericSetter<FString>, &GenericGetType<Noesis::String> }},
		{FTextProperty::StaticClass(), { &GenericGetter<FText>, &GenericSetter<FText>, &GenericGetType<Noesis::String> }},
		{FEnumProperty::StaticClass(), { &EnumGetter, &EnumSetter, &EnumGetType }},
		{FByteProperty::StaticClass(), { &ByteGetter, &ByteSetter, &ByteGetType }},
		{FStructProperty::StaticClass(), { &StructGetter, &StructSetter, &StructGetType }},
		{FObjectProperty::StaticClass(), { &ObjectGetter, &ObjectSetter, &ObjectGetType }},
		{FArrayProperty::StaticClass(), { &ArrayGetter, &ArraySetter, &ArrayGetType }},
		{FMapProperty::StaticClass(), { &MapGetter, &MapSetter, &MapGetType }}
	};
}

TMap<UObject*, class NoesisObjectWrapper* > ObjectMap;
TMap<UObject*, class NoesisTextureWrapper* > TextureMap;
TMap<void*, class NoesisArrayWrapper*> ArrayMap;
TMap<void*, class NoesisMapWrapper*> MapMap;

TMap<UClass*, class NoesisTypeClass*> ClassMap;
TMap<UStruct*, class NoesisTypeClass*> StructMap;
TMap<UEnum*, class NoesisTypeEnum*> EnumMap;
TMap<UMaterialInterface*, class NoesisTypeClass*> MaterialMap;

TArray<class Noesis::Type*> DeletedTypes;
bool NoesisIsShuttingDown = false;

class NoesisObjectWrapper;
class NoesisStructWrapper;
class NoesisEnumWrapper;

FString PathFromRegisterName_GameAsset(FString RegisterName);
FString PathFromRegisterName_ModuleAsset(FString RegisterName);
FString PathFromRegisterName_Native(FString RegisterName);

FString RegisterNameFromPath(FString Path)
{
	if (Path.StartsWith(TEXT("/")))
	{
		Path = Path.RightChop(1);
	}
	int32 FirstSlashIndex;
	Path.FindChar(TEXT('/'), FirstSlashIndex);
	int32 DotIndex;
	Path.FindChar(TEXT('.'), DotIndex);

	FString RegisterName;
	if (Path.StartsWith(TEXT("Game")))
	{
		// Asset names from the game are in the form /Game/Path/To/Asset.Asset
		// We register them as Path.To.Asset
		RegisterName = Path.Left(DotIndex).RightChop(FirstSlashIndex + 1).Replace(TEXT("/"), TEXT("."));
	}
	else if (!Path.StartsWith(TEXT("Script")))
	{
		// Asset names from other roots are in the form /Root/Path/To/Asset.Asset
		// We register them as Root.Path.To.Asset
		RegisterName = Path.Left(DotIndex).Replace(TEXT("/"), TEXT("."));
	}
	else
	{
		// Native names are in the form /Script/Module.Type
		// We register them as Module.Type
		RegisterName = Path.RightChop(FirstSlashIndex + 1);
	}
	return RegisterName;
}

FString PathFromRegisterName_GameAsset(FString RegisterName)
{
	FString Path;
	int32 DotIndex;
	if (RegisterName.FindLastChar(TEXT('.'), DotIndex))
	{
		Path = FString(TEXT("/Game/")) + RegisterName.Replace(TEXT("."), TEXT("/")) + RegisterName.RightChop(DotIndex);
	}
	else
	{
		Path = FString(TEXT("/Game/")) + RegisterName + TEXT(".") + RegisterName;
	}
	return Path;
}

FString PathFromRegisterName_ModuleAsset(FString RegisterName)
{
	int32 DotIndex;
	RegisterName.FindLastChar(TEXT('.'), DotIndex);

	FString Path = FString(TEXT("/")) + RegisterName.Replace(TEXT("."), TEXT("/"));
	if (!FPackageName::IsValidLongPackageName(Path))
		return FString();

	Path += RegisterName.RightChop(DotIndex);
	return Path;
}

FString PathFromRegisterName_Native(FString RegisterName)
{
	int32 DotIndex;
	RegisterName.FindLastChar(TEXT('.'), DotIndex);

	FString Path = FString(TEXT("/Script/")) + RegisterName;
	return Path;
}

class NoesisTypeEnum : public Noesis::TypeEnum
{
public:
	NoesisTypeEnum(UEnum* InEnum, Noesis::Symbol Name)
		: Noesis::TypeEnum(Name), Enum(InEnum)
	{
	}

	~NoesisTypeEnum()
	{
		check(NoesisIsShuttingDown);
	}

	bool GetValueObject(Noesis::Symbol Id, Noesis::Ptr<Noesis::BoxedValue>& Value) const override;

	void ChangeName(Noesis::Symbol NewName)
	{
		UEnum* EnumRef = Enum;
		Noesis::ArrayRef<Value> ValueRefs = GetValues();
		Noesis::Vector<Value> Values(ValueRefs.Begin(), ValueRefs.End());
		NoesisIsShuttingDown = true;
		this->~NoesisTypeEnum();
		NoesisIsShuttingDown = false;
		::new(this) NoesisTypeEnum(EnumRef, NewName);
		for (auto& Value : Values)
		{
			AddValue(Value.first, Value.second);
		}
	}

	UEnum* Enum;

	NS_IMPLEMENT_INLINE_REFLECTION_(NoesisTypeEnum, Noesis::TypeEnum)
};

class NoesisTypeEnumNull : public Noesis::TypeEnum
{
public:
	NoesisTypeEnumNull()
		: Noesis::TypeEnum(Noesis::Symbol())
	{
	}

	bool GetValueObject(Noesis::Symbol Id, Noesis::Ptr<Noesis::BoxedValue>& Value) const override
	{
		return false;
	}
};

NoesisTypeEnumNull NullEnumType;

class NoesisEnumWrapper : public Noesis::Boxed<int64_t>
{
public:
	NoesisEnumWrapper(const NoesisTypeEnum* InTypeEnum, int64 InValue)
		: Noesis::Boxed<int64_t>(InValue), TypeEnum(InTypeEnum)
	{
		check(INT_MIN <= InValue && InValue <= INT_MAX);
	}

	virtual const Noesis::Type* GetValueType() const override
	{
		return TypeEnum;
	}

	virtual Noesis::String ToString() const override
	{
		Noesis::Symbol Name;
		return TypeEnum->HasValue(mValue, Name) ? Noesis::String(Name.Str()) : Noesis::ToString(mValue);
	}

	const NoesisTypeEnum* TypeEnum;

	NS_IMPLEMENT_INLINE_REFLECTION_(NoesisEnumWrapper, Noesis::Boxed<int64_t>)
};

bool NoesisTypeEnum::GetValueObject(Noesis::Symbol Id, Noesis::Ptr<Noesis::BoxedValue>& Value) const
{
	uint64_t Val;
	if (!HasName(Id, Val))
		return false;
	Value = Noesis::Ptr<Noesis::BoxedValue>(*new NoesisEnumWrapper(this, (int64)Val));
	return true;
}

class NoesisEnumConverter : public Noesis::BaseEnumConverter
{
public:
	NoesisEnumConverter(const NoesisTypeEnum* InTypeEnum)
		: Noesis::BaseEnumConverter(InTypeEnum), TypeEnum(InTypeEnum)
	{
	}

	virtual Noesis::Ptr<Noesis::BaseComponent> Box(uint64_t Value) const override
	{
		return *new NoesisEnumWrapper(TypeEnum, Value);
	}

	virtual uint64_t Unbox(Noesis::BaseComponent* Value) const override
	{
		return (uint64_t)Noesis::Boxing::Unbox<int64_t>(Value);
	}

	const NoesisTypeEnum* TypeEnum;

	NS_IMPLEMENT_INLINE_REFLECTION_(NoesisEnumConverter, Noesis::BaseEnumConverter)
};

Noesis::Ptr<Noesis::BaseComponent> NoesisCreateComponentForUEnum(class UEnum* Enum, int64 Value)
{
	NoesisTypeEnum* TypeEnum = (NoesisTypeEnum*)NoesisCreateTypeEnumForUEnum(Enum);
	return *new NoesisEnumWrapper(TypeEnum, Value);
}

Noesis::Ptr<Noesis::BaseComponent> GetPropertyByRef(void* BasePointer, FProperty* Property)
{
	FFieldClass* PropertyClass = Property->GetClass();
	NoesisTypeInfo* TypeInfo = TypeInfos.Find(Property->GetClass());
	return (*TypeInfo->Getter)(BasePointer, Property);
}

bool SetPropertyByRef(void* BasePointer, FProperty* Property, Noesis::BaseComponent* Input)
{
	check(BasePointer != nullptr);
	check(Property != nullptr);

	FFieldClass* PropertyClass = Property->GetClass();

	// Setting non object properties to null is invalid.
	if (Input == nullptr && PropertyClass != FObjectProperty::StaticClass())
		return false;

	NoesisTypeInfo* TypeInfo = TypeInfos.Find(Property->GetClass());
	return (*TypeInfo->Setter)(Input, BasePointer, Property);
}

const Noesis::Type* GetPropertyType(FProperty* Property)
{
	NoesisTypeInfo* TypeInfo = TypeInfos.Find(Property->GetClass());
	if (TypeInfo != nullptr)
	{
		return (*TypeInfo->GetType)(Property);
	}

	return nullptr;
}

static void InitializeFunctionParams(UFunction* Function, void* Params)
{
	for (TFieldIterator<FProperty> It(Function); It && ((It->PropertyFlags & CPF_Parm) == CPF_Parm); ++It)
	{
		FProperty* Property = *It;
		Property->InitializeValue(Params);
	}
}

static void DestroyFunctionParams(UFunction* Function, void* Params)
{
	for (TFieldIterator<FProperty> It(Function); It && ((It->PropertyFlags & CPF_Parm) == CPF_Parm); ++It)
	{
		FProperty* Property = *It;
		Property->DestroyValue(Params);
	}
}

Noesis::Ptr<Noesis::BaseComponent> GetFunctionProperty(void* BasePointer, UFunction* Getter)
{
	UObject* Object = (UObject*)BasePointer;
	if (IsValid(Object) && !Object->IsUnreachable())
	{
		void* Params = FMemory_Alloca(Getter->GetStructureSize());
		InitializeFunctionParams(Getter, Params);
		Object->ProcessEvent(Getter, Params);
		FProperty* OutputProperty = (FProperty*)Getter->ChildProperties; 
		Noesis::Ptr<Noesis::BaseComponent> Ret = GetPropertyByRef(Params, OutputProperty);
		DestroyFunctionParams(Getter, Params);
		return Ret;
	}
	return nullptr;
}

bool SetFunctionProperty(void* BasePointer, UFunction* Setter, Noesis::BaseComponent* Value)
{
	UObject* Object = (UObject*)BasePointer;
	if (IsValid(Object) && !Object->IsUnreachable())
	{
		void* Params = FMemory_Alloca(Setter->GetStructureSize());
		InitializeFunctionParams(Setter, Params);
		FProperty* InputProperty = (FProperty*)Setter->ChildProperties;
		SetPropertyByRef(Params, InputProperty, Value);
		Object->ProcessEvent(Setter, Params);
		DestroyFunctionParams(Setter, Params);
		return true;
}

	return false;
}

// Macro for preserving Noesis::BaseComponent objects when external code is invoked, since external code may cause the objects to be deleted
#define LOCAL_PRESERVE(var) auto PRESERVE_##var = Noesis::Ptr<const Noesis::BaseComponent>(var)

class NoesisValueArrayWrapper : public Noesis::BaseComponent, public Noesis::IList
{
public:
	NoesisValueArrayWrapper(void* ArrayPtr, FArrayProperty* ArrayProperty)
	{
		FProperty* InnerProperty = ArrayProperty->Inner;
		check(InnerProperty->GetOffset_ForDebug() == 0);

		ComponentArray.Empty();

		FScriptArrayHelper ArrayHelper(ArrayProperty, ArrayPtr);

		for (int32 Index = 0; Index != ArrayHelper.Num(); ++Index)
		{
			Noesis::Ptr<Noesis::BaseComponent> Item = GetPropertyByRef(ArrayHelper.GetRawPtr(Index), InnerProperty);
			ComponentArray.Add(Item);
		}
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

	virtual void InsertComponent(uint32_t Index, Noesis::BaseComponent* Item) override
	{
	}

	virtual int IndexOfComponent(const Noesis::BaseComponent* Item) const override
	{
		return ComponentArray.Find(Noesis::Ptr<Noesis::BaseComponent>((Noesis::BaseComponent*)Item));
	}

	virtual void RemoveAt(uint32_t Index) override
	{
	}

	virtual void Clear() override
	{
	}
	// End of IList interface

	NS_IMPLEMENT_INLINE_REFLECTION(NoesisValueArrayWrapper, Noesis::BaseComponent)
	{
		NsImpl<Noesis::IList>();
		NsProp("Count", &NoesisValueArrayWrapper::Count);
	}

public:
	TArray<Noesis::Ptr<Noesis::BaseComponent>> ComponentArray;
};

class NoesisArrayWrapper : public Noesis::BaseComponent, public Noesis::IList, public Noesis::INotifyCollectionChanged
{
public:
	NoesisArrayWrapper(void* ArrayPtr, FArrayProperty* InArrayProperty)
		: ArrayProperty(InArrayProperty), ArrayPointer(ArrayPtr)
	{
		check(ArrayProperty->Inner->GetOffset_ForDebug() == 0);
		ArrayMap.Add(ArrayPointer, this);
	}

	~NoesisArrayWrapper()
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
	Noesis::Ptr<Noesis::BaseComponent> NativeGet(uint32 Index) const
	{
#if WITH_EDITOR
		if (ArrayProperty == nullptr)
			return nullptr;
#endif
		FScriptArrayHelper ArrayHelper(ArrayProperty, ArrayPointer);
		ArrayHelper.ExpandForIndex(Index);
		FProperty* InnerProperty = ArrayProperty->Inner;
		return GetPropertyByRef(ArrayHelper.GetRawPtr(Index), InnerProperty);
	}
	bool NativeSet(uint32 Index, Noesis::BaseComponent* Item)
	{
#if WITH_EDITOR
		if (ArrayProperty == nullptr)
			return false;
#endif
		FScriptArrayHelper ArrayHelper(ArrayProperty, ArrayPointer);
		ArrayHelper.ExpandForIndex(Index);
		FProperty* InnerProperty = ArrayProperty->Inner;
		return SetPropertyByRef(ArrayHelper.GetRawPtr(Index), InnerProperty, Item);
	}
	int32 NativeSize() const
	{
#if WITH_EDITOR
		if (ArrayProperty == nullptr)
			return 0;
#endif
		FScriptArrayHelper ArrayHelper(ArrayProperty, ArrayPointer);
		return ArrayHelper.Num();
	}
	void NativeInsert(uint32 Index)
	{
#if WITH_EDITOR
		if (ArrayProperty == nullptr)
			return;
#endif
		FScriptArrayHelper ArrayHelper(ArrayProperty, ArrayPointer);
		ArrayHelper.InsertValues(Index);
	}
	void NativeClear()
	{
#if WITH_EDITOR
		if (ArrayProperty == nullptr)
			return;
#endif
		FScriptArrayHelper ArrayHelper(ArrayProperty, ArrayPointer);
		ArrayHelper.EmptyValues();
	}
	void NativeRemoveAt(uint32 Index)
	{
#if WITH_EDITOR
		if (ArrayProperty == nullptr)
			return;
#endif
		FScriptArrayHelper ArrayHelper(ArrayProperty, ArrayPointer);
		ArrayHelper.RemoveValues(Index);
	}

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

	virtual void InsertComponent(uint32_t Index, Noesis::BaseComponent* Item) override
	{
		NativeInsert(Index);
		NativeSet(Index, Item);
		NotifyPostInsert(Index);
	}

	virtual int IndexOfComponent(const Noesis::BaseComponent* Item) const override
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

	virtual void RemoveAt(uint32_t Index) override
	{
		NativeRemoveAt(Index);
	}

	virtual void Clear() override
	{
		NativeClear();
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

		// Preserve this in case it is deleted in the event handler
		LOCAL_PRESERVE(this);
		Noesis::NotifyCollectionChangedEventArgs CollectionChangedArgs = { Noesis::NotifyCollectionChangedAction_Add, -1, (int32)Index, nullptr, Item };
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

		// Preserve this in case it is deleted in the event handler
		LOCAL_PRESERVE(this);
		Noesis::NotifyCollectionChangedEventArgs CollectionChangedArgs = { Noesis::NotifyCollectionChangedAction_Replace, (int32)Index, (int32)Index, ItemToDelete, NewItem };
		CollectionChangedHandler(this, CollectionChangedArgs);
		ItemToDelete.Reset();
	}

	void NotifyPreRemoveAt(int32 Index)
	{
		check(ItemToDelete == nullptr);
		ItemToDelete = NativeGet(Index);
	}

	void NotifyPostRemoveAt(int32 Index)
	{
		check(ItemToDelete != nullptr);
		// Preserve this in case it is deleted in the event handler
		LOCAL_PRESERVE(this);
		Noesis::NotifyCollectionChangedEventArgs CollectionChangedArgs = { Noesis::NotifyCollectionChangedAction_Remove, Index, -1, ItemToDelete, nullptr };
		CollectionChangedHandler(this, CollectionChangedArgs);
		ItemToDelete.Reset();
	}

	void NotifyPostReset()
	{
		// Preserve this in case it is deleted in the event handler
		LOCAL_PRESERVE(this);
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

	NS_IMPLEMENT_INLINE_REFLECTION(NoesisArrayWrapper, Noesis::BaseComponent)
	{
		NsImpl<Noesis::IList>();
		NsImpl<Noesis::INotifyCollectionChanged>();
		NsProp("Count", &NoesisArrayWrapper::Count);
	}

private:
	Noesis::NotifyCollectionChangedEventHandler CollectionChangedHandler;

public:
	FArrayProperty* ArrayProperty;
	void* ArrayPointer; 
	Noesis::Ptr<Noesis::BaseComponent> ItemToDelete;
	int32 PreviousCount;
};

class NoesisMapWrapper : public Noesis::BaseComponent, public Noesis::IDictionary, public Noesis::INotifyDictionaryChanged
{
public:
	NoesisMapWrapper(void* MapPtr, FMapProperty* InMapProperty)
		: MapProperty(InMapProperty), MapPointer(MapPtr)
	{
		MapMap.Add(MapPtr, this);
	}

	~NoesisMapWrapper()
	{
		MapMap.Remove(MapPointer);
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
	bool NativeFind(const char* Key, Noesis::Ptr<Noesis::BaseComponent>& Value) const
	{
		FScriptMapHelper MapHelper(MapProperty, MapPointer);
		FString KeyString = UTF8_TO_TCHAR(Key);
		uint8* PairPtr = MapHelper.FindMapPairPtrFromHash(&KeyString);
		if (PairPtr)
		{
			FProperty* ValueProperty = MapProperty->ValueProp;
			Value = GetPropertyByRef(PairPtr, ValueProperty);
			return true;
		}
		return false;
	}

	void NativeSet(const char* Key, Noesis::BaseComponent* Value)
	{
		FScriptMapHelper MapHelper(MapProperty, MapPointer);
		FString KeyString = UTF8_TO_TCHAR(Key);
		uint8* PairPtr = MapHelper.FindMapPairPtrFromHash(&KeyString);
		if (PairPtr)
		{
			FProperty* ValueProperty = MapProperty->ValueProp;
			SetPropertyByRef(PairPtr, ValueProperty, Value);
		}
	}

	void NativeAdd(const char* Key, Noesis::BaseComponent* Value)
	{
		FScriptMapHelper MapHelper(MapProperty, MapPointer);
		FString KeyString = UTF8_TO_TCHAR(Key);
		FProperty* ValueProperty = MapProperty->ValueProp;
		uint8* PairPtr = MapHelper.FindMapPairPtrFromHash(&KeyString);
		if (!PairPtr)
		{
			int32 Index = MapHelper.AddDefaultValue_Invalid_NeedsRehash();
			MapHelper.Rehash();
			PairPtr = MapHelper.GetPairPtr(Index);
		}
		SetPropertyByRef(PairPtr, ValueProperty, Value);
	}

	void NativeRemove(const char* Key)
	{
		FScriptMapHelper MapHelper(MapProperty, MapPointer);
		FString KeyString = UTF8_TO_TCHAR(Key);
		FProperty* ValueProperty = MapProperty->ValueProp;
		uint8* PairPtr = MapHelper.FindMapPairPtrFromHash(&KeyString);
		if (PairPtr)
		{
			MapHelper.RemovePair(PairPtr);
		}
	}

public:
	// IDictionary interface
	virtual bool Find(const char* Key, Noesis::Ptr<Noesis::BaseComponent>& Value) const override
	{
		return NativeFind(Key, Value);
	}

	virtual void Set(const char* Key, Noesis::BaseComponent* Value) override
	{
		NativeSet(Key, Value);
	}

	virtual void Add(const char* Key, BaseComponent* Value) override
	{
		NativeAdd(Key, Value);
	}

	virtual void Remove(const char* Key) override
	{
		NativeRemove(Key);
	}

	virtual Noesis::NotifyDictionaryChangedEventHandler& DictionaryChanged() override
	{
		return DictionaryChangedHandler;
	}

	void NotifyPostAdd(const char* Key)
	{
		Noesis::Ptr<Noesis::BaseComponent> Item;
		NativeFind(Key, Item);
		// Preserve this in case it is deleted in the event handler
		LOCAL_PRESERVE(this);
		Noesis::NotifyDictionaryChangedEventArgs DictionaryChangedArgs = { Noesis::NotifyDictionaryChangedAction_Add, Key, nullptr, Item };
		DictionaryChangedHandler(this, DictionaryChangedArgs);
	}

	void NotifyPreRemove(const char* Key)
	{
		check(ItemToDelete == nullptr);
		NativeFind(Key, ItemToDelete);
	}

	void NotifyPostRemove(const char* Key)
	{
		check(ItemToDelete != nullptr);
		// Preserve this in case it is deleted in the event handler
		LOCAL_PRESERVE(this);
		Noesis::NotifyDictionaryChangedEventArgs DictionaryChangedArgs = { Noesis::NotifyDictionaryChangedAction_Remove, Key, ItemToDelete, nullptr };
		DictionaryChangedHandler(this, DictionaryChangedArgs);
		ItemToDelete = nullptr;
	}

	void NotifyPostReset()
	{
		// Preserve this in case it is deleted in the event handler
		LOCAL_PRESERVE(this);
		Noesis::NotifyDictionaryChangedEventArgs DictionaryChangedArgs = { Noesis::NotifyDictionaryChangedAction_Reset, "", nullptr, nullptr };
		DictionaryChangedHandler(this, DictionaryChangedArgs);
	}

	NS_IMPLEMENT_INLINE_REFLECTION(NoesisMapWrapper, Noesis::BaseComponent)
	{
		NsImpl<Noesis::IDictionary>();
		NsImpl<Noesis::INotifyDictionaryChanged>();
	}

private:
	Noesis::NotifyDictionaryChangedEventHandler DictionaryChangedHandler;

public:
	FMapProperty* MapProperty;
	void* MapPointer;
	Noesis::Ptr<Noesis::BaseComponent> ItemToDelete;
};

Noesis::Ptr<Noesis::BaseComponent> NoesisCreateComponentForTMap(void* MapPtr, FMapProperty* MapProperty)
{
	auto WrapperPtr = MapMap.Find(MapPtr);
	if (WrapperPtr)
	{
		return Noesis::Ptr<Noesis::BaseComponent>(*WrapperPtr);
	}

	return *new NoesisMapWrapper(MapPtr, MapProperty);
}

Noesis::Ptr<Noesis::BaseComponent> NoesisCreateComponentForTMapStruct(void* MapPtr, FMapProperty* MapProperty, void* StructPtr)
{
	return *new NoesisMapWrapper(MapPtr, MapProperty);
}

const Noesis::Type* NoesisCreateTypeForTMap(FMapProperty* MapProperty)
{
	return Noesis::TypeOf<Noesis::BaseComponent>();
}

class NoesisTypeProperty : public Noesis::TypeProperty
{
public:
	NoesisTypeProperty(Noesis::Symbol Name, const Noesis::Type* Type);

	/// From TypeProperty
	//@{
	void* GetContent(void* Ptr) const;
	void* GetContent(const void* Ptr) const;
	void SetComponent(void* Ptr, Noesis::BaseComponent* Value) const;
	//@}

	virtual void Invalidate() = 0;

protected:
	/// From TypeProperty
	//@{
	const void* InternalGet(const void* Ptr) const;
	void InternalGet(const void* Ptr, void* Storage) const;
	void InternalSet(void* Ptr, const void* Value) const;
	bool IsReadOnly() const override;
	//@}
};

NoesisTypeProperty::NoesisTypeProperty(Noesis::Symbol Name, const Noesis::Type* Type)
	: Noesis::TypeProperty(Name, Type)
{
}

void* NoesisTypeProperty::GetContent(void* Ptr) const
{
	check(false);
	return nullptr;
}

void* NoesisTypeProperty::GetContent(const void* Ptr) const
{
	check(false);
	return nullptr;
}

const void* NoesisTypeProperty::InternalGet(const void* Ptr) const
{
	check(false);
	return nullptr;
}

void NoesisTypeProperty::SetComponent(void* Ptr, Noesis::BaseComponent* Value) const
{
}

void NoesisTypeProperty::InternalGet(const void* Ptr, void* Storage) const
{
	check(false);
}

void NoesisTypeProperty::InternalSet(void* Ptr, const void* Value) const
{
	check(false);
}

bool NoesisTypeProperty::IsReadOnly() const
{
	return true;
}

class NoesisTypeClass : public Noesis::TypeClass
{
public:
	NoesisTypeClass(Noesis::Symbol Name)
		: Noesis::TypeClass(Name, false)
	{
	}

	~NoesisTypeClass()
	{
		check(NoesisIsShuttingDown);
	}

	bool Equals(const Noesis::BaseObject* BaseObject) const override
	{
		const NoesisTypeClass* TypeClass = Noesis::DynamicCast<const NoesisTypeClass*>(BaseObject);
		return TypeClass && Class == TypeClass->Class;
	}

	void AddBase(const Noesis::TypeClass* BaseType)
	{
		check(BaseType);
		check(!mBase);

		mBase = BaseType;
	}

	void AddProperty(NoesisTypeProperty* Property)
	{
		check(Property);

		PropertyVector::Iterator It = LowerBound(mProperties.Begin(), mProperties.End(), Property,
			[](Noesis::TypeProperty* elem1, Noesis::TypeProperty* elem2)
			{
				return elem1->GetName() < elem2->GetName();
			});

		check(It == mProperties.End() || (*It)->GetName() != Property->GetName());

		mProperties.Insert(It, Property);
	}

	void AddEvent(NoesisTypeProperty* Event)
	{
		check(Event);

		PropertyVector::Iterator It = LowerBound(mEvents.Begin(), mEvents.End(), Event,
			[](Noesis::TypeProperty* elem1, Noesis::TypeProperty* elem2)
			{
				return elem1->GetName() < elem2->GetName();
			});

		check(It == mEvents.End() || (*It)->GetName() != Event->GetName());

		mEvents.Insert(It, Event);
	}

	void ChangeName(Noesis::Symbol NewName)
	{
		PropertyVector Properties = mProperties;
		mProperties.Clear();
		PropertyVector Events = mEvents;
		mEvents.Clear();
		const Noesis::TypeClass* Base = mBase;
		NoesisIsShuttingDown = true;
		this->~NoesisTypeClass();
		NoesisIsShuttingDown = false;
		::new(this) NoesisTypeClass(NewName);
		mEvents = Noesis::MoveArg(Events);
		mProperties = Noesis::MoveArg(Properties);
		mBase = Base;
	}

	void InvalidateProperties()
	{
		for (auto TypeProperty : mProperties)
		{
			NoesisTypeProperty* Property = (NoesisTypeProperty*)TypeProperty;
			Property->Invalidate();
		}

		for (auto TypeProperty : mEvents)
		{
			NoesisTypeProperty* Property = (NoesisTypeProperty*)TypeProperty;
			Property->Invalidate();
		}
	}

	union
	{
		UStruct* Class;
		UMaterialInterface* Material;
	};

	int32 GetStructureSize() const
	{
		return Class->GetStructureSize();
	}

	int32 GetMinAlignment() const
	{
		return Class->GetMinAlignment();
	}

	void InitializeStruct(void* Dest) const
	{
		Class->InitializeStruct(Dest);
	}

	void DestroyStruct(void* Dest) const
	{
		Class->DestroyStruct(Dest);
	}

	NS_IMPLEMENT_INLINE_REFLECTION_(NoesisTypeClass, Noesis::TypeClass)
};

bool IsTypeRegistered(Noesis::Type* TypeClass)
{
	Noesis::Symbol TypeId = TypeClass->GetTypeId();
	return Noesis::Reflection::IsTypeRegistered(TypeId);
}

void ReplaceType(Noesis::Type* OldType, Noesis::Type* NewType)
{
	if (IsTypeRegistered(OldType))
	{
		Noesis::Reflection::UnregisterNoDelete(OldType);
		if (NewType != nullptr)
		{
			Noesis::Reflection::RegisterType(NewType);
		}
	}
	DeletedTypes.Add(OldType);
}

void ReplaceTypeClass(NoesisTypeClass* OldTypeClass, NoesisTypeClass* NewTypeClass)
{
	OldTypeClass->InvalidateProperties();
	ReplaceType(OldTypeClass, NewTypeClass);
}

class NoesisStructWrapper : public Noesis::BaseComponent
{
public:

	NoesisStructWrapper(NoesisTypeClass* InTypeClass) :
		Noesis::BaseComponent(), TypeClass(InTypeClass)
	{
		StructData = FMemory::Malloc(TypeClass->GetStructureSize(), TypeClass->GetMinAlignment());
		TypeClass->InitializeStruct(GetStructPtr());
	}

	~NoesisStructWrapper()
	{
		TypeClass->DestroyStruct(GetStructPtr());
		FMemory::Free(StructData);
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
		check(TypeClass->Class->IsA<UScriptStruct>());
		return Wrapper && TypeClass->Equals(Wrapper->TypeClass) && ((UScriptStruct*)TypeClass->Class)->CompareScriptStruct(GetStructPtr(), Wrapper->GetStructPtr(), PPF_None);
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

	static void StaticFillClassType(Noesis::TypeClassCreator& Helper)
	{
	}

	void* GetStructPtr() const
	{
		return StructData;
	}

public:
	NoesisTypeClass* TypeClass;
	void* StructData;
};

class NoesisObjectWrapper : public Noesis::BaseComponent, public Noesis::INotifyPropertyChanged
{
public:

	NoesisObjectWrapper(UObject* InObject) :
		Noesis::BaseComponent(), Object(InObject)
	{
		ObjectMap.Add(Object, this);
	}

	~NoesisObjectWrapper();

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
		// Can't return null. Just pretend it's a BaseComponent
		if (Object == nullptr)
		{
			NS_LOG("A wrapper of a deleted object is still referenced");
			return Noesis::BaseComponent::StaticGetClassType(nullptr);
		}

		if (IsValid(Object) && !Object->IsUnreachable())
		{
			UClass* Class = Object->GetClass();
			const Noesis::TypeClass* TypeClass = NoesisCreateTypeClassForUClass(Class);
			return TypeClass == nullptr ? Noesis::BaseComponent::StaticGetClassType(nullptr) : TypeClass;
		}
		return Noesis::BaseComponent::StaticGetClassType(nullptr);
	}

	Noesis::String ToString() const override
	{
		if (Object == nullptr)
		{
			NS_LOG("A wrapper of a deleted object is still referenced");
			return "";
		}

		if (IsValid(Object) && !Object->IsUnreachable())
		{
			return TCHARToNsString(*Object->GetPathName());
		}
		return "";
	}

	bool Equals(const Noesis::BaseObject* BaseObject) const override
	{
		if (Object == nullptr)
		{
			NS_LOG("A wrapper of a deleted object is still referenced");
			return false;
		}

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

	static void StaticFillClassType(Noesis::TypeClassCreator& Helper)
	{
		Helper.Impl<NoesisObjectWrapper, Noesis::INotifyPropertyChanged>();
	}

	void NotifyPropertyChanged(Noesis::Symbol PropertyId)
	{
		// Preserve this in case it is deleted in the event handler
		LOCAL_PRESERVE(this);
		Noesis::PropertyChangedEventArgs ChangedEventArgs(PropertyId);
		PropertyChangedHandler(this, ChangedEventArgs);
	}

public:
	Noesis::PropertyChangedEventHandler PropertyChangedHandler;
	UObject* Object;
	TMap<UFunction*, Noesis::Ptr<class NoesisFunctionWrapper>> CommandMap;
	TMap<FProperty*, Noesis::EventHandler> EventMap;
};

class NoesisFunctionWrapper : public Noesis::BaseCommand
{
public:
	NoesisFunctionWrapper(NoesisObjectWrapper* InWrapper, UFunction* InFunction, UFunction* InCanExecuteFunction)
		: Wrapper(InWrapper), Function(InFunction), CanExecuteFunction(InCanExecuteFunction)
	{
		Wrapper->CommandMap.Add(Function, Noesis::Ptr<NoesisFunctionWrapper>(this));
	}

	~NoesisFunctionWrapper()
	{
		if (Wrapper != nullptr)
		{
			Wrapper->CommandMap.Remove(Function);
		}
	}

	bool CanExecute(Noesis::BaseComponent* Param) const override
	{
		if (Wrapper == nullptr || Wrapper->Object == nullptr)
			return false;

		UObject* Object = Wrapper->Object;
		if (IsValid(Object) && !Object->IsUnreachable() && CanExecuteFunction)
		{
			if (CanExecuteFunction->NumParms == 1)
			{
				// Preserve this in case it is deleted in ProcessEvent
				LOCAL_PRESERVE(this);
				void* Params = FMemory_Alloca(CanExecuteFunction->GetStructureSize());
				InitializeFunctionParams(CanExecuteFunction, Params);
				Object->ProcessEvent(CanExecuteFunction, Params);
				FBoolProperty* OutputProperty = (FBoolProperty*)(CanExecuteFunction->ChildProperties);
				bool Ret = OutputProperty->GetPropertyValue(OutputProperty->ContainerPtrToValuePtr<bool>(Params));
				DestroyFunctionParams(CanExecuteFunction, Params);
				return Ret;
			}
			else
			{
				// Preserve this in case it is deleted in ProcessEvent
				LOCAL_PRESERVE(this);
				check(CanExecuteFunction->NumParms == 2);
				void* Params = FMemory_Alloca(CanExecuteFunction->GetStructureSize());
				InitializeFunctionParams(CanExecuteFunction, Params);
				FProperty* InputProperty = (FProperty*)CanExecuteFunction->ChildProperties;
				SetPropertyByRef(Params, InputProperty, Param);
				Object->ProcessEvent(CanExecuteFunction, Params);
				FBoolProperty* OutputProperty = (FBoolProperty*)(CanExecuteFunction->ChildProperties->Next);
				bool Ret = OutputProperty->GetPropertyValue(OutputProperty->ContainerPtrToValuePtr<bool>(Params));
				DestroyFunctionParams(CanExecuteFunction, Params);
				return Ret;
			}
		}

		return true;
	}

	void Execute(Noesis::BaseComponent* Param) const override
	{
		if (Wrapper == nullptr || Wrapper->Object == nullptr)
			return;

		UObject* Object = Wrapper->Object;
		if (IsValid(Object) && !Object->IsUnreachable())
		{
			if (Function->NumParms == 0)
			{
				Object->ProcessEvent(Function, nullptr);
			}
			else
			{
				// Preserve this in case it is deleted in ProcessEvent
				LOCAL_PRESERVE(this);
				void* Params = FMemory_Alloca(Function->GetStructureSize());
				InitializeFunctionParams(Function, Params);
				FProperty* InputProperty = (FProperty*)Function->ChildProperties;
				SetPropertyByRef(Params, InputProperty, Param);
				Object->ProcessEvent(Function, Params);
				DestroyFunctionParams(Function, Params);
			}
		}
	}

	NS_IMPLEMENT_INLINE_REFLECTION_(NoesisFunctionWrapper, Noesis::BaseCommand)

public:
	NoesisObjectWrapper* Wrapper;
	UFunction* Function;
	UFunction* CanExecuteFunction;
};

NoesisObjectWrapper::~NoesisObjectWrapper()
{
	for (auto CommandPair : CommandMap)
	{
		CommandPair.Value->Wrapper = nullptr;
	}
	CommandMap.Empty();

	if (Object != nullptr)
	{
		ObjectMap.Remove(Object);
	}

	for (auto Pairs : EventMap)
	{
		check(Pairs.Value.Empty());
	}
}

class NoesisMaterialWrapper
{
public:

	NoesisMaterialWrapper(UMaterialInterface* InMaterial)
	{
		TypeClass = (NoesisTypeClass*)NoesisCreateTypeClassForUMaterial(InMaterial);

		MaterialInstanceDynamic = Cast<UMaterialInstanceDynamic>(InMaterial);
		if (MaterialInstanceDynamic == nullptr)
		{
			MaterialInstanceDynamic = UMaterialInstanceDynamic::Create(InMaterial, GetTransientPackage());
		}
		MaterialInstanceDynamic->AddToRoot();
		Material = NoesisCreateMaterial(MaterialInstanceDynamic.Get());
	}

	virtual ~NoesisMaterialWrapper()
	{
		NoesisDestroyMaterial(Material);
		if (MaterialInstanceDynamic.IsValid())
		{
			MaterialInstanceDynamic->RemoveFromRoot();
		}
	}

	void SetScalarParameterValue(FName ParamName, float Value)
	{
		if (MaterialInstanceDynamic.IsValid())
		{
			MaterialInstanceDynamic->SetScalarParameterValue(ParamName, Value);
		}
	}

	void SetVectorParameterValue(FName ParamName, FLinearColor Value)
	{
		if (MaterialInstanceDynamic.IsValid())
		{
			MaterialInstanceDynamic->SetVectorParameterValue(ParamName, Value);
		}
	}

	void SetTextureParameterValue(FName ParamName, UTexture* Value)
	{
		if (MaterialInstanceDynamic.IsValid())
		{
			MaterialInstanceDynamic->SetTextureParameterValue(ParamName, Value);
		}
	}

protected:

	NoesisTypeClass* TypeClass = nullptr;
	TWeakObjectPtr<UMaterialInstanceDynamic> MaterialInstanceDynamic;
	void* Material = nullptr;
};

class NoesisUIMaterialWrapper : public Noesis::BrushShader, public NoesisMaterialWrapper
{
public:

	NoesisUIMaterialWrapper(UMaterialInterface* InMaterial)
		: NoesisMaterialWrapper(InMaterial)
	{
		SetPixelShader(Material, Target::Path);
		SetPixelShader(Material, Target::Path_AA);
		SetPixelShader(Material, Target::SDF);
		SetPixelShader(Material, Target::SDF_LCD);
		SetPixelShader(Material, Target::Opacity);
	}

	virtual const Noesis::TypeClass* GetClassType() const override
	{
		return TypeClass;
	}
};

class NoesisPostProcessMaterialWrapper : public Noesis::ShaderEffect, public NoesisMaterialWrapper
{
public:

	NoesisPostProcessMaterialWrapper(UMaterialInterface* InMaterial)
		: NoesisMaterialWrapper(InMaterial)
	{
		SetPixelShader(Material);
	}

	virtual const Noesis::TypeClass* GetClassType() const override
	{
		return TypeClass;
	}
};

class NoesisTextureWrapper : public Noesis::TextureSource
{
public:
	NoesisTextureWrapper(UTexture* InTexture)
		: Noesis::TextureSource(NoesisCreateTexture(InTexture)), Texture(InTexture)
	{
		TextureMap.Add(Texture, this);
	}

	~NoesisTextureWrapper()
	{
		if (Texture != nullptr)
		{
			TextureMap.Remove(Texture);
		}
	}

	UTexture* Texture;

	NS_IMPLEMENT_INLINE_REFLECTION_(NoesisTextureWrapper, Noesis::TextureSource)
};

Noesis::Ptr<Noesis::BaseComponent> NoesisCreateComponentForUTexture(UTexture* Texture)
{
	NoesisTextureWrapper** TextureSourcePtr = TextureMap.Find(Texture);
	if (TextureSourcePtr != nullptr)
	{
		return Noesis::Ptr<Noesis::BaseComponent>(*TextureSourcePtr);
	}
	else
	{
		NoesisTextureWrapper* TextureSource = new NoesisTextureWrapper(Texture);
		return Noesis::Ptr<Noesis::BaseComponent>(*TextureSource);
	}
}

Noesis::Ptr<Noesis::BaseComponent> NoesisCreateComponentForTArray(void* ArrayPtr, FArrayProperty* ArrayProperty)
{
	auto ListPtr = ArrayMap.Find(ArrayPtr);
	if (ListPtr)
	{
		return Noesis::Ptr<Noesis::BaseComponent>(*ListPtr);
	}

	return *new NoesisArrayWrapper(ArrayPtr, ArrayProperty);
}

Noesis::Ptr<Noesis::BaseComponent> NoesisCreateComponentForTArrayStruct(void* ArrayPtr, FArrayProperty* ArrayProperty, void* StructPtr)
{
	return *new NoesisValueArrayWrapper(ArrayPtr, ArrayProperty);
}

const Noesis::Type* NoesisCreateTypeForTArray(FArrayProperty* ArrayProperty)
{
	return Noesis::TypeOf<Noesis::BaseComponent>();
}

class NoesisTypePropertyStructWrapper : public NoesisTypeProperty
{
public:
	NoesisTypePropertyStructWrapper(Noesis::Symbol Name, const Noesis::Type* Type, FProperty* InProperty);

	/// From TypeProperty
	//@{
	Noesis::Ptr<Noesis::BaseComponent> GetComponent(const void* Ptr) const;
	//@}

	virtual void Invalidate() override;

private:
	FProperty* Property;
};

NoesisTypePropertyStructWrapper::NoesisTypePropertyStructWrapper(Noesis::Symbol Name, const Noesis::Type* Type, FProperty* InProperty)
	: NoesisTypeProperty(Name, Type), Property(InProperty)
{
}

Noesis::Ptr<Noesis::BaseComponent> NoesisTypePropertyStructWrapper::GetComponent(const void* Ptr) const
{
#if WITH_EDITOR
	if (Property == nullptr)
	{
		NS_LOG("A property of a deleted struct is still referenced");
		return nullptr;
	}
#endif

	NoesisStructWrapper* Wrapper = (NoesisStructWrapper*)Ptr;
	return GetPropertyByRef(Wrapper->GetStructPtr(), Property);
}

void NoesisTypePropertyStructWrapper::Invalidate()
{
	Property = nullptr;
}

class NoesisTypePropertyObjectWrapper : public NoesisTypeProperty
{
public:
	NoesisTypePropertyObjectWrapper(Noesis::Symbol Name, const Noesis::Type* Type, FProperty* InProperty);

	/// From TypeProperty
	//@{
	Noesis::Ptr<Noesis::BaseComponent> GetComponent(const void* Ptr) const;
	void SetComponent(void* Ptr, Noesis::BaseComponent* Value) const;
	//@}

	virtual void Invalidate() override;

protected:
	/// From TypeProperty
	//@{
	bool IsReadOnly() const override;
	//@}

private:
	FProperty* Property;
};

NoesisTypePropertyObjectWrapper::NoesisTypePropertyObjectWrapper(Noesis::Symbol Name, const Noesis::Type* Type, FProperty* InProperty)
	: NoesisTypeProperty(Name, Type), Property(InProperty)
{
}

Noesis::Ptr<Noesis::BaseComponent> NoesisTypePropertyObjectWrapper::GetComponent(const void* Ptr) const
{
#if WITH_EDITOR
	if (Property == nullptr)
	{
		NS_LOG("A property of a deleted class is still referenced");
		return nullptr;
	}
#endif

	NoesisObjectWrapper* Wrapper = (NoesisObjectWrapper*)Ptr;
	if (Wrapper->Object == nullptr)
	{
		NS_LOG("A wrapper of a deleted object is still referenced");
		return nullptr;
	}

	return GetPropertyByRef(Wrapper->Object, Property);
}

void NoesisTypePropertyObjectWrapper::SetComponent(void* Ptr, Noesis::BaseComponent* Value) const
{
#if WITH_EDITOR
	if (Property == nullptr)
	{
		NS_LOG("A property of a deleted class is still referenced");
		return;
	}
#endif

	NoesisObjectWrapper* Wrapper = (NoesisObjectWrapper*)Ptr;
	if (Wrapper->Object == nullptr)
	{
		NS_LOG("A wrapper of a deleted object is still referenced");
		return;
	}

	if (SetPropertyByRef(Wrapper->Object, Property, Value))
	{
		Wrapper->NotifyPropertyChanged(GetName());
	}
}

void NoesisTypePropertyObjectWrapper::Invalidate()
{
	for (auto Pair : ArrayMap)
	{
		NoesisArrayWrapper* Wrapper = Pair.Value;
		if (Wrapper->ArrayProperty == Property)
		{
			Wrapper->ArrayProperty = nullptr;
		}
	}
	Property = nullptr;
}

bool NoesisTypePropertyObjectWrapper::IsReadOnly() const
{
#if WITH_EDITOR
	if (Property == nullptr)
	{
		NS_LOG("A property of a deleted class is still referenced");
		return true;
	}
#endif

	return Property->HasAllPropertyFlags(CPF_BlueprintReadOnly);
}

class NoesisTypePropertyObjectWrapperEvent : public NoesisTypeProperty
{
public:
	NoesisTypePropertyObjectWrapperEvent(Noesis::Symbol Name, FProperty* InProperty);

	/// From TypeProperty
	//@{
	void* GetContent(const void* Ptr) const override;
	const void* Get(const void* Ptr) const override;
	//@}

	virtual void Invalidate() override;

protected:
	/// From TypeProperty
	//@{
	bool IsReadOnly() const override;
	//@}

private:
	FProperty* Property;
};

NoesisTypePropertyObjectWrapperEvent::NoesisTypePropertyObjectWrapperEvent(Noesis::Symbol Name, FProperty* InProperty)
	: NoesisTypeProperty(Name, nullptr), Property(InProperty)
{
}

DEFINE_FUNCTION(execNoesisDelegate)
{
	P_FINISH;
	P_NATIVE_BEGIN;

	UFunction* Delegate = Stack.Node;
	FString EventName = Delegate->GetName().RightChop(15); // Remove the NoesisDelegate_ prefix
	auto Wrapper = NoesisFindComponentForUObject(Context);
	if (Wrapper != nullptr)
	{
		auto TypeClass = (NoesisTypeClass*)Wrapper->GetClassType();
		Noesis::TypeClassEvent ClassEvent = Noesis::FindEvent(TypeClass, Noesis::Symbol(TCHAR_TO_UTF8(*EventName)));
		auto TypeProperty = (NoesisTypePropertyObjectWrapperEvent*)ClassEvent.event;
		if (TypeProperty != nullptr)
		{
			auto EventHandler = (Noesis::EventHandler*)TypeProperty->GetContent(Wrapper);
			Noesis::EventArgs Args;
			EventHandler->Invoke(Wrapper, Args);
		}
	}

	P_NATIVE_END;
}

void* NoesisTypePropertyObjectWrapperEvent::GetContent(const void* Ptr) const
{
#if WITH_EDITOR
	if (Property == nullptr)
	{
		NS_LOG("A property of a deleted class is still referenced");
		return nullptr;
	}
#endif

	NoesisObjectWrapper* Wrapper = (NoesisObjectWrapper*)Ptr;
	if (Wrapper->Object == nullptr)
	{
		NS_LOG("A wrapper of a deleted object is still referenced");
		return nullptr;
	}

	auto CountEvents = [](const Noesis::TypeClass* TypeClass)
	{
		int32 Count = 0;
		do
		{
			Count += (int32)TypeClass->GetNumEvents();
			TypeClass = TypeClass->GetBase();
		} while (TypeClass != nullptr);
		return Count;
	};

	const Noesis::TypeClass* TypeClass = Wrapper->GetClassType();
	int32 EventCount = CountEvents(TypeClass);
	Wrapper->EventMap.Reserve(EventCount);

	auto Found = Wrapper->EventMap.Find(Property);
	if (Found == nullptr)
	{
		// We add the fuction names to the UObject class so FScriptDelegate can find them later.
		// We only need to do this once per event name.
		const auto DelegateName = WriteToString<128>("NoesisDelegate_", *Property->GetName());
		UClass* ObjectClass = UObject::StaticClass();
		if (ObjectClass->FindFunctionByName(*DelegateName) == nullptr)
		{
			auto NoesisDelegateFunc = NewObject<UFunction>(ObjectClass, *DelegateName);
			NoesisDelegateFunc->AddToRoot();
			NoesisDelegateFunc->SetNativeFunc(&execNoesisDelegate);
			NoesisDelegateFunc->FunctionFlags |= FUNC_Native;
			ObjectClass->AddFunctionToFunctionMap(NoesisDelegateFunc, *DelegateName);
		}

		FScriptDelegate Delegate;
		Delegate.BindUFunction(Wrapper->Object, *DelegateName);
		FMulticastDelegateProperty* DelegateProperty = (FMulticastDelegateProperty*)Property;
		DelegateProperty->AddDelegate(Delegate, Wrapper->Object);
	}
	return &Wrapper->EventMap.FindOrAdd(Property);
}

const void* NoesisTypePropertyObjectWrapperEvent::Get(const void* Ptr) const
{
	return GetContent(Ptr);
}

void NoesisTypePropertyObjectWrapperEvent::Invalidate()
{
}

bool NoesisTypePropertyObjectWrapperEvent::IsReadOnly() const
{
	return true;
}

class NoesisTypePropertyObjectWrapperGetterSetter : public NoesisTypeProperty
{
public:
	NoesisTypePropertyObjectWrapperGetterSetter(Noesis::Symbol Name, const Noesis::Type* Type, UFunction* InGetter, UFunction* InSetter);

	/// From TypeProperty
	//@{
	Noesis::Ptr<Noesis::BaseComponent> GetComponent(const void* Ptr) const;
	void SetComponent(void* Ptr, Noesis::BaseComponent* Value) const;
	//@}

	virtual void Invalidate() override;

protected:
	/// From TypeProperty
	//@{
	bool IsReadOnly() const override;
	//@}

private:
	UFunction* Getter;
	UFunction* Setter;
};

NoesisTypePropertyObjectWrapperGetterSetter::NoesisTypePropertyObjectWrapperGetterSetter(Noesis::Symbol Name, const Noesis::Type* Type, UFunction* InGetter, UFunction* InSetter)
	: NoesisTypeProperty(Name, Type), Getter(InGetter), Setter(InSetter)
{
}

Noesis::Ptr<Noesis::BaseComponent> NoesisTypePropertyObjectWrapperGetterSetter::GetComponent(const void* Ptr) const
{
#if WITH_EDITOR
	if (Getter == nullptr)
	{
		NS_LOG("A property of a deleted class is still referenced");
		return nullptr;
	}
#endif

	NoesisObjectWrapper* Wrapper = (NoesisObjectWrapper*)Ptr;
	if (Wrapper->Object == nullptr)
	{
		NS_LOG("A wrapper of a deleted object is still referenced");
		return nullptr;
	}

	// Preserve Wrapper in case it is deleted in ProcessEvent in GetFunctionProperty
	LOCAL_PRESERVE(Wrapper);
	return GetFunctionProperty(Wrapper->Object, Getter);
}

void NoesisTypePropertyObjectWrapperGetterSetter::SetComponent(void* Ptr, Noesis::BaseComponent* Value) const
{
#if WITH_EDITOR
	if (Getter == nullptr)
	{
		NS_LOG("A property of a deleted class is still referenced");
		return;
	}
#endif

	NoesisObjectWrapper* Wrapper = (NoesisObjectWrapper*)Ptr;
	if (Wrapper->Object == nullptr)
	{
		NS_LOG("A wrapper of a deleted object is still referenced");
		return;
	}

	// Preserve Wrapper in case it is deleted in ProcessEvents in SetFunctionProperty
	LOCAL_PRESERVE(Wrapper);
	if (SetFunctionProperty(Wrapper->Object, Setter, Value))
	{
		Wrapper->NotifyPropertyChanged(GetName());
	}
}

void NoesisTypePropertyObjectWrapperGetterSetter::Invalidate()
{
	Getter = nullptr;
}

bool NoesisTypePropertyObjectWrapperGetterSetter::IsReadOnly() const
{
#if WITH_EDITOR
	if (Getter == nullptr)
	{
		NS_LOG("A property of a deleted class is still referenced");
		return true;
	}
#endif

	return Setter == nullptr;
}

class NoesisTypePropertyObjectWrapperCommand : public NoesisTypeProperty
{
public:
	NoesisTypePropertyObjectWrapperCommand(Noesis::Symbol Name, const Noesis::Type* Type, UFunction* InCommand, UFunction* InCanExecute);

	/// From TypeProperty
	//@{
	Noesis::Ptr<Noesis::BaseComponent> GetComponent(const void* Ptr) const;
	//@}

	virtual void Invalidate() override;

private:
	UFunction* Command;
	UFunction* CanExecute;
};

NoesisTypePropertyObjectWrapperCommand::NoesisTypePropertyObjectWrapperCommand(Noesis::Symbol Name, const Noesis::Type* Type, UFunction* InCommand, UFunction* InCanExecute)
	: NoesisTypeProperty(Name, Type), Command(InCommand), CanExecute(InCanExecute)
{
}

Noesis::Ptr<Noesis::BaseComponent> NoesisTypePropertyObjectWrapperCommand::GetComponent(const void* Ptr) const
{
#if WITH_EDITOR
	if (Command == nullptr)
	{
		NS_LOG("A property of a deleted class is still referenced");
		return nullptr;
	}
#endif

	NoesisObjectWrapper* Wrapper = (NoesisObjectWrapper*)Ptr;
	if (Wrapper->Object == nullptr)
	{
		NS_LOG("A wrapper of a deleted object is still referenced");
		return nullptr;
	}

	auto CommandPtr = Wrapper->CommandMap.Find(Command);
	if (CommandPtr != nullptr)
		return *CommandPtr;

	return *new NoesisFunctionWrapper(Wrapper, Command, CanExecute);
}

void NoesisTypePropertyObjectWrapperCommand::Invalidate()
{
	Command = nullptr;
}

void NoesisFillTypeClassForUStruct(NoesisTypeClass* TypeClass, UScriptStruct* Class)
{
	const Noesis::TypeClass* ParentType = NoesisStructWrapper::StaticGetClassType(nullptr);

	TypeClass->Class = Class;
	check(TypeClass);

	TypeClass->AddBase(ParentType);

	for (TFieldIterator<FProperty> PropertyIt(Class, EFieldIteratorFlags::ExcludeSuper); PropertyIt; ++PropertyIt)
	{
		FProperty* Property = *PropertyIt;
		FString PropertyName = Property->GetName();
		if (!(Class->StructFlags & STRUCT_Native))
		{
			int32 UnderscorePosition = INDEX_NONE;
			ensure(PropertyName.FindLastChar(TEXT('_'), UnderscorePosition));
			PropertyName = PropertyName.LeftChop(PropertyName.Len() - UnderscorePosition);
			ensure(PropertyName.FindLastChar(TEXT('_'), UnderscorePosition));
			PropertyName = PropertyName.LeftChop(PropertyName.Len() - UnderscorePosition);
		}
		Noesis::Symbol PropertyId = Noesis::Symbol(TCHAR_TO_UTF8(*PropertyName));

		const Noesis::Type* PropertyType = GetPropertyType(Property);
		if (PropertyType != nullptr)
		{
			NoesisTypeProperty* TypeProperty = new NoesisTypePropertyStructWrapper(PropertyId, PropertyType, Property);
			TypeClass->AddProperty(TypeProperty);
		}
	}
}

void NoesisFillTypeClassForUClass(NoesisTypeClass* TypeClass, UClass* Class)
{
	const Noesis::TypeClass* ParentType = NoesisObjectWrapper::StaticGetClassType(nullptr);
	UClass* SuperClass = Class->GetSuperClass();
	if (SuperClass)
	{
		ParentType = NoesisCreateTypeClassForUClass(SuperClass);
	}

	TypeClass->Class = Class;
	check(TypeClass);

	TypeClass->AddBase(ParentType);

	for (TFieldIterator<UFunction> FunctionIt(Class, EFieldIteratorFlags::ExcludeSuper); FunctionIt; ++FunctionIt)
	{
		UFunction* Function = *FunctionIt;
		FString FunctionName = Function->GetName();

		FProperty* Param = CastField<FProperty>(Function->ChildProperties);
		bool HasNoParams = Function->NumParms == 0;
		bool HasOneParam = Function->NumParms == 1 && (Param != nullptr) && ((Param->PropertyFlags & CPF_OutParm) == 0);

		if (HasNoParams || HasOneParam)
		{
			UFunction* CanExecuteFunction = Class->FindFunctionByName(*(FString(TEXT("CanExecute")) + FunctionName), EIncludeSuperFlag::ExcludeSuper);
			if (CanExecuteFunction)
			{
				FProperty* CanExecuteParam = CastField<FProperty>(CanExecuteFunction->ChildProperties);
				bool CanExecuteHasNoParams = CanExecuteFunction->NumParms == 1 &&
					(CanExecuteParam != nullptr) &&
					CanExecuteParam->IsA<FBoolProperty>() &&
					((CanExecuteParam->PropertyFlags & CPF_OutParm) != 0);
				bool CanExecuteHasOneParam = CanExecuteFunction->NumParms == 2 &&
					(CanExecuteParam != nullptr) &&
					((CanExecuteParam->PropertyFlags & CPF_OutParm) == 0) &&
					(Param != nullptr) &&
					(CanExecuteParam->GetClass() == Param->GetClass()) &&
					CanExecuteParam->Next->IsA<FBoolProperty>() &&
					((((FProperty*)CanExecuteParam->Next)->PropertyFlags & CPF_OutParm) != 0);
				if (!CanExecuteHasNoParams && !CanExecuteHasOneParam)
				{
					CanExecuteFunction = nullptr;
				}
			}

			if (HasNoParams)
			{
				NoesisTypeProperty* TypeProperty = new NoesisTypePropertyObjectWrapperCommand(Noesis::Symbol(TCHAR_TO_UTF8(*Function->GetName())), Noesis::TypeOf<NoesisFunctionWrapper>(), Function, CanExecuteFunction);
				TypeClass->AddProperty(TypeProperty);
			}
			else
			{
				const Noesis::Type* ParamType = GetPropertyType(Param);
				if (ParamType != nullptr)
				{
					NoesisTypeProperty* TypeProperty = new NoesisTypePropertyObjectWrapperCommand(Noesis::Symbol(TCHAR_TO_UTF8(*Function->GetName())), Noesis::TypeOf<NoesisFunctionWrapper>(), Function, CanExecuteFunction);
					TypeClass->AddProperty(TypeProperty);
				}
			}
		}

		bool IsGetter = false;
		FString SetterName = FunctionName;
		Noesis::Symbol PropertyId;
		if (FunctionName.StartsWith(TEXT("Get")))
		{
			IsGetter = true;
			SetterName[0] = TEXT('S');
			PropertyId = Noesis::Symbol(TCHAR_TO_UTF8(*FunctionName.RightChop(3)));
		}

		if (IsGetter)
		{
			FProperty* OutParam = CastField<FProperty>(Function->ChildProperties);
			if (Function->NumParms == 1 && (OutParam != nullptr) && ((OutParam->PropertyFlags & CPF_OutParm) != 0))
			{
				UFunction* Setter = Class->FindFunctionByName(*SetterName, EIncludeSuperFlag::ExcludeSuper);
				if (Setter != nullptr)
				{
					FProperty* SetterParam = CastField<FProperty>(Setter->ChildProperties);
					bool SetterHasOneParam = Setter->NumParms == 1 &&
						(SetterParam != nullptr) &&
						((SetterParam->PropertyFlags & CPF_OutParm) == 0) &&
						(SetterParam->SameType(OutParam));
					if (!SetterHasOneParam)
						Setter = nullptr;
				}

				const Noesis::Type* OutParamType = GetPropertyType(OutParam);
				if (OutParamType != nullptr)
				{
					NoesisTypeProperty* TypeProperty = new NoesisTypePropertyObjectWrapperGetterSetter(PropertyId, OutParamType, Function, Setter);
					TypeClass->AddProperty(TypeProperty);
				}
			}
		}
	}

	for (TFieldIterator<FProperty> PropertyIt(Class, EFieldIteratorFlags::ExcludeSuper); PropertyIt; ++PropertyIt)
	{
		FProperty* Property = *PropertyIt;
		FString PropertyName = Property->GetName();
		Noesis::Symbol PropertyId = Noesis::Symbol(TCHAR_TO_UTF8(*PropertyName));

		if (TypeClass->FindProperty(PropertyId) == nullptr)
		{
			const Noesis::Type* PropertyType = GetPropertyType(Property);
			if (PropertyType != nullptr)
			{
				NoesisTypeProperty* TypeProperty = new NoesisTypePropertyObjectWrapper(PropertyId, PropertyType, Property);
				TypeClass->AddProperty(TypeProperty);
			}
		}

		if (Property->GetClass()->IsChildOf(FMulticastDelegateProperty::StaticClass()))
		{
			NoesisTypeProperty* TypeProperty = new NoesisTypePropertyObjectWrapperEvent(PropertyId, Property);
			TypeClass->AddEvent(TypeProperty);
		}
	}
}

const Noesis::Type* NoesisGetTypeForUClass(UClass* Class)
{
	return Noesis::TypeOf<NoesisObjectWrapper>();
}

Noesis::TypeClass* NoesisCreateTypeClassForUClass(UClass* Class)
{
	NoesisTypeClass** TypeClassPtr = ClassMap.Find(Class);
	if (TypeClassPtr != nullptr)
	{
		return *TypeClassPtr;
	}

	FString RegisterClassName = RegisterNameFromPath(Class->GetPathName());
	NoesisTypeClass* TypeClass = new NoesisTypeClass(Noesis::Symbol(TCHAR_TO_UTF8(*RegisterClassName)));

	NoesisFillTypeClassForUClass(TypeClass, Class);

	ClassMap.Add(Class, TypeClass);
	return TypeClass;
}

Noesis::BaseComponent* CallbackCreateMaterialWrapper(Noesis::Symbol Name)
{
	FString UnrealTypeName = UTF8_TO_TCHAR(Name.Str());
	FString GamePath = PathFromRegisterName_GameAsset(UnrealTypeName);
	UMaterialInterface* Material = LoadObject<UMaterialInterface>(nullptr, *GamePath, nullptr, LOAD_NoWarn);
	if (Material == nullptr)
	{
		FString ModulePath = PathFromRegisterName_ModuleAsset(UnrealTypeName);
		if (!ModulePath.IsEmpty())
		{
			Material = LoadObject<UMaterialInterface>(nullptr, *ModulePath, nullptr, LOAD_NoWarn);
		}
	}

	if (Material != nullptr)
	{
		UMaterial* BaseMaterial = Material->GetBaseMaterial();
		if (BaseMaterial->MaterialDomain == MD_UI)
		{
			return new NoesisUIMaterialWrapper(Material);
		}
		else if (BaseMaterial->MaterialDomain == MD_PostProcess)
		{
			return new NoesisPostProcessMaterialWrapper(Material);
		}
	}

	return nullptr;
}

Noesis::TypeClass* NoesisCreateTypeClassForUMaterial(UMaterialInterface* Material)
{
	NoesisTypeClass** TypeClassPtr = MaterialMap.Find(Material);
	if (TypeClassPtr != nullptr)
	{
		return *TypeClassPtr;
	}

	FString RegisterClassName = RegisterNameFromPath(Material->GetPathName());
	NoesisTypeClass* TypeClass = new NoesisTypeClass(Noesis::Symbol(TCHAR_TO_UTF8(*RegisterClassName)));

	TypeClass->Material = Material;

	UMaterial* BaseMaterial = Material->GetBaseMaterial();
	const Noesis::TypeClass* Parent = BaseMaterial->MaterialDomain == MD_UI ? Noesis::TypeOf<Noesis::BrushShader>() : Noesis::TypeOf<Noesis::ShaderEffect>();
	TypeClass->AddBase(Parent);

	Noesis::Ptr<Noesis::UIElementData> Data = *new Noesis::UIElementData(TypeClass);
	TypeClass->AddMeta(Data);
	{
		TArray<FMaterialParameterInfo> ParamInfo;
		TArray<FGuid> ParamGuid;
		Material->GetAllScalarParameterInfo(ParamInfo, ParamGuid);

		for (auto& Param : ParamInfo)
		{
			float Value;
			Material->GetScalarParameterDefaultValue(Param, Value);
			
			const Noesis::DependencyProperty* DependencyProperty = nullptr;

			if (BaseMaterial->MaterialDomain == MD_UI)
			{
				Data->RegisterProperty<float>(DependencyProperty, TCHAR_TO_UTF8(*Param.Name.ToString()),
					Noesis::FrameworkPropertyMetadata::Create(Value,
						Noesis::FrameworkPropertyMetadataOptions_None, Noesis::PropertyChangedCallback(
							[ParamName = Param.Name](Noesis::DependencyObject* Object, const Noesis::DependencyPropertyChangedEventArgs& Args)
							{
								NoesisUIMaterialWrapper* Wrapper = (NoesisUIMaterialWrapper*)Object;
								Wrapper->SetScalarParameterValue(ParamName, Args.NewValue<float>());
							})));
			}
			else
			{
				Data->RegisterProperty<float>(DependencyProperty, TCHAR_TO_UTF8(*Param.Name.ToString()),
					Noesis::FrameworkPropertyMetadata::Create(Value,
						Noesis::FrameworkPropertyMetadataOptions_None, Noesis::PropertyChangedCallback(
							[ParamName = Param.Name](Noesis::DependencyObject* Object, const Noesis::DependencyPropertyChangedEventArgs& Args)
							{
								NoesisPostProcessMaterialWrapper* Wrapper = (NoesisPostProcessMaterialWrapper*)Object;
								Wrapper->SetScalarParameterValue(ParamName, Args.NewValue<float>());
							})));
			}
		}
	}

	{
		TArray<FMaterialParameterInfo> ParamInfo;
		TArray<FGuid> ParamGuid;
		Material->GetAllVectorParameterInfo(ParamInfo, ParamGuid);

		for (auto& Param : ParamInfo)
		{
			FLinearColor Value;
			Material->GetVectorParameterDefaultValue(Param, Value);

			const Noesis::DependencyProperty* DependencyProperty = nullptr;
			const Noesis::DependencyProperty* LinearDependencyProperty = nullptr;

			if (BaseMaterial->MaterialDomain == MD_UI)
			{
				Data->RegisterProperty<Noesis::Color>(DependencyProperty, TCHAR_TO_UTF8(*Param.Name.ToString()),
					Noesis::FrameworkPropertyMetadata::Create(Noesis::Color(Value.R, Value.G, Value.B, Value.A),
						Noesis::FrameworkPropertyMetadataOptions_None, Noesis::PropertyChangedCallback(
							[ParamName = Param.Name](Noesis::DependencyObject* Object, const Noesis::DependencyPropertyChangedEventArgs& Args)
							{
								NoesisUIMaterialWrapper* Wrapper = (NoesisUIMaterialWrapper*)Object;
								Noesis::Color Color = Args.NewValue<Noesis::Color>();
								Wrapper->SetVectorParameterValue(ParamName, FLinearColor(Color.r, Color.g, Color.b, Color.a));
							})));

				Data->RegisterProperty<Noesis::Point4D>(LinearDependencyProperty, TCHAR_TO_UTF8(*(Param.Name.ToString() + "_Linear")),
					Noesis::FrameworkPropertyMetadata::Create(Noesis::Point4D(Value.R, Value.G, Value.B, Value.A),
						Noesis::FrameworkPropertyMetadataOptions_None, Noesis::PropertyChangedCallback(
							[ParamName = Param.Name](Noesis::DependencyObject* Object, const Noesis::DependencyPropertyChangedEventArgs& Args)
							{
								NoesisUIMaterialWrapper* Wrapper = (NoesisUIMaterialWrapper*)Object;
								Noesis::Point4D Color = Args.NewValue<Noesis::Point4D>();
								Wrapper->SetVectorParameterValue(ParamName, FLinearColor(Color.y, Color.z, Color.w, Color.x));
							})));
			}
			else
			{
				Data->RegisterProperty<Noesis::Color>(DependencyProperty, TCHAR_TO_UTF8(*Param.Name.ToString()),
					Noesis::FrameworkPropertyMetadata::Create(Noesis::Color(Value.R, Value.G, Value.B, Value.A),
						Noesis::FrameworkPropertyMetadataOptions_None, Noesis::PropertyChangedCallback(
							[ParamName = Param.Name](Noesis::DependencyObject* Object, const Noesis::DependencyPropertyChangedEventArgs& Args)
							{
								NoesisPostProcessMaterialWrapper* Wrapper = (NoesisPostProcessMaterialWrapper*)Object;
								Noesis::Color Color = Args.NewValue<Noesis::Color>();
								Wrapper->SetVectorParameterValue(ParamName, FLinearColor(Color.r, Color.g, Color.b, Color.a));
							})));

				Data->RegisterProperty<Noesis::Point4D>(LinearDependencyProperty, TCHAR_TO_UTF8(*(Param.Name.ToString() + "_Linear")),
					Noesis::FrameworkPropertyMetadata::Create(Noesis::Point4D(Value.R, Value.G, Value.B, Value.A),
						Noesis::FrameworkPropertyMetadataOptions_None, Noesis::PropertyChangedCallback(
							[ParamName = Param.Name](Noesis::DependencyObject* Object, const Noesis::DependencyPropertyChangedEventArgs& Args)
							{
								NoesisPostProcessMaterialWrapper* Wrapper = (NoesisPostProcessMaterialWrapper*)Object;
								Noesis::Point4D Color = Args.NewValue<Noesis::Point4D>();
								Wrapper->SetVectorParameterValue(ParamName, FLinearColor(Color.y, Color.z, Color.w, Color.x));
							})));
			}
		}
	}

	{
		TArray<FMaterialParameterInfo> ParamInfo;
		TArray<FGuid> ParamGuid;
		Material->GetAllTextureParameterInfo(ParamInfo, ParamGuid);

		for (auto& Param : ParamInfo)
		{
			UTexture* Value;
			Material->GetTextureParameterDefaultValue(Param, Value);

			const Noesis::DependencyProperty* DependencyProperty = nullptr;

			if (BaseMaterial->MaterialDomain == MD_UI)
			{
				Data->RegisterProperty<Noesis::Ptr<Noesis::BitmapSource>>(DependencyProperty, TCHAR_TO_UTF8(*Param.Name.ToString()),
					Noesis::FrameworkPropertyMetadata::Create(Noesis::StaticPtrCast<Noesis::BitmapSource>(NoesisCreateComponentForUObject(Value)),
						Noesis::FrameworkPropertyMetadataOptions_None, Noesis::PropertyChangedCallback(
							[ParamName = Param.Name](Noesis::DependencyObject* Object, const Noesis::DependencyPropertyChangedEventArgs& Args)
							{
								NoesisUIMaterialWrapper* Wrapper = (NoesisUIMaterialWrapper*)Object;
								Noesis::BitmapSource* NewValue = Args.NewValue<Noesis::BitmapSource*>();
								Noesis::BitmapImage* BitmapImage = Noesis::DynamicCast<Noesis::BitmapImage*>(NewValue);
								if (BitmapImage != nullptr)
								{
									const Noesis::Uri& SourceUri = BitmapImage->GetUriSource();
									FString SourcePath = NsProviderUriToAssetPath(SourceUri);
									UTexture* UnrealTexture = LoadObject<UTexture>(nullptr, *SourcePath, nullptr, LOAD_NoWarn);
									Wrapper->SetTextureParameterValue(ParamName, UnrealTexture);
								}
								NoesisTextureWrapper* TextureWrapper = Noesis::DynamicCast<NoesisTextureWrapper*>(NewValue);
								if (TextureWrapper != nullptr)
								{
									UTexture* UnrealTexture = TextureWrapper->Texture;
									Wrapper->SetTextureParameterValue(ParamName, UnrealTexture);
								}
							})));
			}
			else
			{
				Data->RegisterProperty<Noesis::Ptr<Noesis::BitmapSource>>(DependencyProperty, TCHAR_TO_UTF8(*Param.Name.ToString()),
					Noesis::FrameworkPropertyMetadata::Create(Noesis::StaticPtrCast<Noesis::BitmapSource>(NoesisCreateComponentForUObject(Value)),
						Noesis::FrameworkPropertyMetadataOptions_None, Noesis::PropertyChangedCallback(
							[ParamName = Param.Name](Noesis::DependencyObject* Object, const Noesis::DependencyPropertyChangedEventArgs& Args)
							{
								NoesisPostProcessMaterialWrapper* Wrapper = (NoesisPostProcessMaterialWrapper*)Object;
								Noesis::BitmapSource* NewValue = Args.NewValue<Noesis::BitmapSource*>();
								Noesis::BitmapImage* BitmapImage = Noesis::DynamicCast<Noesis::BitmapImage*>(NewValue);
								if (BitmapImage != nullptr)
								{
									const Noesis::Uri& SourceUri = BitmapImage->GetUriSource();
									FString SourcePath = NsProviderUriToAssetPath(SourceUri);
									UTexture* UnrealTexture = LoadObject<UTexture>(nullptr, *SourcePath, nullptr, LOAD_NoWarn);
									Wrapper->SetTextureParameterValue(ParamName, UnrealTexture);
								}
								NoesisTextureWrapper* TextureWrapper = Noesis::DynamicCast<NoesisTextureWrapper*>(NewValue);
								if (TextureWrapper != nullptr)
								{
									UTexture* UnrealTexture = TextureWrapper->Texture;
									Wrapper->SetTextureParameterValue(ParamName, UnrealTexture);
								}
							})));
			}
		}
	}

	Noesis::RegisterComponent(TypeClass, &CallbackCreateMaterialWrapper);

	MaterialMap.Add(Material, TypeClass);
	return TypeClass;
}

Noesis::BaseComponent* CallbackCreateEnumConverter(Noesis::Symbol Id)
{
	const char* ConverterName = Id.Str();
	check(FCStringAnsi::Strlen(ConverterName) > 11);
	Noesis::String EnumName = Noesis::String(ConverterName + 10, FCStringAnsi::Strlen(ConverterName) - 11);

	Noesis::Type* Type = (Noesis::Type*)Noesis::Reflection::GetType(Noesis::Symbol(EnumName.Str()));
	NoesisTypeEnum* TypeEnum = Noesis::DynamicCast<NoesisTypeEnum*>(Type);
	if (TypeEnum != nullptr)
	{
		return new NoesisEnumConverter(TypeEnum);
	}
	return nullptr;
}

void NoesisFillTypeEnumForUEnum(NoesisTypeEnum* TypeEnum, UEnum* Enum)
{
	for (int32 Index = 0; Index != Enum->NumEnums(); ++Index)
	{
		FString EnumValueName = Enum->GetAuthoredNameStringByIndex(Index);
		TypeEnum->AddValue(Noesis::Symbol(TCHAR_TO_UTF8(*EnumValueName)), (int)Enum->GetValueByIndex(Index));
	}
}

Noesis::TypeEnum* NoesisCreateTypeEnumForUEnum(UEnum* Enum)
{
	NoesisTypeEnum** TypeEnumPtr = EnumMap.Find(Enum);
	if (TypeEnumPtr != nullptr)
	{
		return *TypeEnumPtr;
	}

	FString RegisterEnumName = RegisterNameFromPath(Enum->GetPathName());
	Noesis::String PersistentEnumName = TCHAR_TO_UTF8(*RegisterEnumName);
	NoesisTypeEnum* TypeEnum = new NoesisTypeEnum(Enum, Noesis::Symbol(PersistentEnumName.Str()));
	check(TypeEnum);

	NoesisFillTypeEnumForUEnum(TypeEnum, Enum);

	Noesis::Symbol EnumConverterId = Noesis::IdOf("Converter<", PersistentEnumName.Str(), ">");
	if (!Noesis::Factory::IsComponentRegistered(EnumConverterId))
	{
		Noesis::Factory::RegisterComponent(EnumConverterId, Noesis::Symbol::Null(), &CallbackCreateEnumConverter);
	}

	EnumMap.Add(Enum, TypeEnum);
	return TypeEnum;
}

#if WITH_EDITOR
void NoesisDestroyViews()
{
	// The types may be in use. We have to destroy all Views.
	// We simply get rid of all the thumbnails
	for (TObjectIterator<UNoesisXaml> It; It; ++It)
	{
		UNoesisXaml* Xaml = *It;
		Xaml->DestroyThumbnailRenderData();
	}
	for (TObjectIterator<UNoesisRive> It; It; ++It)
	{
		UNoesisRive* Rive = *It;
		Rive->DestroyThumbnailRenderData();
	}

	
	for (TObjectIterator<UNoesisWorldUIComponent> It; It; ++It)
	{
		UNoesisWorldUIComponent* WorldUIComponent = *It;
		WorldUIComponent->Remove3DElement();
	}

	// We keep track of the rest of initialized views, and their DataContexts, as those may be running in game.
	TArray<UNoesisInstance*> InstancesToRecreate;
	TArray<bool> IsInstance3DWidget;
	for (TObjectIterator<UNoesisInstance> It; It; ++It)
	{
		UNoesisInstance* Instance = *It;
		if (Instance->XamlView != nullptr)
		{
			InstancesToRecreate.Add(Instance);
			bool Is3DWidget = Instance->Is3DWidget;
			if (Is3DWidget)
			{
				Instance->Term3DWidget(Instance->GetWorld());
			}
			else
			{
				Instance->TermInstance();
			}
			IsInstance3DWidget.Add(Is3DWidget);
		}
	}

	// Reinitialize the Views that are in game
	for (int32 InstanceIndex = 0; InstanceIndex != InstancesToRecreate.Num(); ++InstanceIndex)
	{
		auto Instance = InstancesToRecreate[InstanceIndex];
		bool Is3DWidget = IsInstance3DWidget[InstanceIndex];
		if (Is3DWidget)
		{
			Instance->Init3DWidget(Instance->GetWorld());
		}
		else
		{
			Instance->InitInstance();
		}
	}

	for (TObjectIterator<UNoesisWorldUIComponent> It; It; ++It)
	{
		UNoesisWorldUIComponent* WorldUIComponent = *It;
		WorldUIComponent->Add3DElement();
	}
}

static void OnBlueprintCompiled(UBlueprint* Blueprint);

auto OnBlueprintCompiledDelegate = TDelegate<void(UBlueprint*), FDefaultDelegateUserPolicy>::CreateStatic(OnBlueprintCompiled);

void OnClassChanged(UClass* Class)
{
	NoesisTypeClass* TypeClass = nullptr;
	if (ClassMap.RemoveAndCopyValue(Class, TypeClass))
	{
		ReplaceTypeClass(TypeClass, nullptr);
	}
}

static void OnBlueprintCompiled(UBlueprint* Blueprint)
{
	Blueprint->OnCompiled().Remove(OnBlueprintCompiledDelegate.GetHandle());
	NoesisDestroyViews();
}

void NoesisDestroyTypeClassForBlueprint(UBlueprint* Blueprint)
{
	UClass* Class = Blueprint->GeneratedClass;
	if (!Blueprint->bIsRegeneratingOnLoad && ClassMap.Contains(Class))
	{
		Blueprint->OnCompiled().Add(OnBlueprintCompiledDelegate);
		OnClassChanged(Class);
	}
}

void OnStructChanged(UUserDefinedStruct* OriginalStruct)
{
	for (TObjectIterator<UUserDefinedStruct> StructIt; StructIt; ++StructIt)
	{
		UUserDefinedStruct* Struct = *StructIt;
		if (Struct->PrimaryStruct.IsValid() && Struct->PrimaryStruct == OriginalStruct)
		{
			NoesisTypeClass* TypeClass = nullptr;
			if (StructMap.RemoveAndCopyValue(OriginalStruct, TypeClass))
			{
				check(TypeClass->Class == OriginalStruct);
				TypeClass->Class = Struct;
				NoesisTypeClass* NewClass = (NoesisTypeClass*)NoesisCreateTypeClassForUStruct(Struct);
				ReplaceTypeClass(TypeClass, NewClass);

				NoesisDestroyViews();
			}
		}
	}
}

void NoesisDestroyTypeClassForStruct(UUserDefinedStruct* BaseStruct)
{
	OnStructChanged(BaseStruct);

	/*for (TAllFieldsIterator<FStructProperty> FieldIt(RF_NoFlags, EInternalObjectFlags::PendingKill); FieldIt; ++FieldIt)
	{
		FStructProperty* StructProperty = *FieldIt;
		if ((StructProperty != nullptr) && (StructProperty->Struct != nullptr))
		{
			UUserDefinedStruct* PropertyStruct = Cast<UUserDefinedStruct>(StructProperty->Struct);
			if ((PropertyStruct != nullptr) && PropertyStruct->PrimaryStruct.IsValid() && PropertyStruct->PrimaryStruct->IsChildOf(BaseStruct))
			{
				FField* Field = StructProperty;
				FFieldVariant Owner = Field->GetOwnerVariant();
				while (!Owner.IsUObject())
				{
					Field = Owner.ToField();
					Owner = Field->GetOwnerVariant();
				}

				if (UClass* OwnerClass = Cast<UClass>(Owner.ToUObject()))
				{
					for (auto It = ObjectMap.CreateIterator(); It; ++It)
					{
						auto& ObjectComponentPair = *It;
						UObject* Object = ObjectComponentPair.Key;
						if (IsValid(Object) && !Object->IsUnreachable())
						{
							if (Object->GetClass() == OwnerClass)
							{
								NoesisObjectWrapper* Wrapper = (NoesisObjectWrapper*)ObjectComponentPair.Value;
								auto PropertySymbol = Noesis::Symbol(TCHAR_TO_UTF8(*Field->GetName()));
								Wrapper->NotifyPropertyChanged(PropertySymbol);
							}
						}
					}
				}
			}
		}
	}*/
}

void OnEnumChanged(UEnum* Enum)
{
	NoesisTypeEnum* TypeEnum = nullptr;
	if (EnumMap.RemoveAndCopyValue(Enum, TypeEnum))
	{
		NoesisTypeEnum* NewEnum = (NoesisTypeEnum*)NoesisCreateTypeEnumForUEnum(Enum);
		ReplaceType(TypeEnum, NewEnum);

		NoesisDestroyViews();
	}
}

void NoesisDestroyTypeClassForEnum(UEnum* Enum)
{
	OnEnumChanged(Enum);

	/*for (TAllFieldsIterator<FEnumProperty> FieldIt(RF_NoFlags, EInternalObjectFlags::PendingKill); FieldIt; ++FieldIt)
	{
		FEnumProperty* EnumProperty = *FieldIt;
		if ((EnumProperty != nullptr) && (EnumProperty->GetEnum() != nullptr))
		{
			UEnum* PropertyEnum = EnumProperty->GetEnum();
			if ((PropertyEnum != nullptr) && (PropertyEnum == Enum))
			{
				FField* Field = EnumProperty;
				FFieldVariant Owner = Field->GetOwnerVariant();
				while (!Owner.IsUObject())
				{
					Field = Owner.ToField();
					Owner = Field->GetOwnerVariant();
				}

				if (UClass* OwnerClass = Cast<UClass>(Owner.ToUObject()))
				{
					for (auto It = ObjectMap.CreateIterator(); It; ++It)
					{
						auto& ObjectComponentPair = *It;
						UObject* Object = ObjectComponentPair.Key;
						if (IsValid(Object) && !Object->IsUnreachable())
						{
							if (Object->GetClass() == OwnerClass)
							{
								NoesisObjectWrapper* Wrapper = (NoesisObjectWrapper*)ObjectComponentPair.Value;
								auto PropertySymbol = Noesis::Symbol(TCHAR_TO_UTF8(*Field->GetName()));
								Wrapper->NotifyPropertyChanged(PropertySymbol);
							}
						}
					}
				}
			}
		}
	}

	for (TAllFieldsIterator<FByteProperty> FieldIt(RF_NoFlags, EInternalObjectFlags::PendingKill); FieldIt; ++FieldIt)
	{
		FByteProperty* ByteProperty = *FieldIt;
		if ((ByteProperty != nullptr) && (ByteProperty->Enum != nullptr))
		{
			UEnum* PropertyEnum = ByteProperty->Enum;
			if ((PropertyEnum != nullptr) && (PropertyEnum == Enum))
			{
				FField* Field = ByteProperty;
				FFieldVariant Owner = Field->GetOwnerVariant();
				while (!Owner.IsUObject())
				{
					Field = Owner.ToField();
					Owner = Field->GetOwnerVariant();
				}

				if (UClass* OwnerClass = Cast<UClass>(Owner.ToUObject()))
				{
					for (auto It = ObjectMap.CreateIterator(); It; ++It)
					{
						auto& ObjectComponentPair = *It;
						UObject* Object = ObjectComponentPair.Key;
						if (IsValid(Object) && !Object->IsUnreachable())
						{
							if (Object->GetClass() == OwnerClass)
							{
								NoesisObjectWrapper* Wrapper = (NoesisObjectWrapper*)ObjectComponentPair.Value;
								auto PropertySymbol = Noesis::Symbol(TCHAR_TO_UTF8(*Field->GetName()));
								Wrapper->NotifyPropertyChanged(PropertySymbol);
							}
						}
					}
				}
			}
		}
	}*/
}

void OnMaterialChanged(class UMaterialInterface* Material)
{
	NoesisTypeClass* TypeClass = nullptr;
	if (MaterialMap.RemoveAndCopyValue(Material, TypeClass))
	{
		NoesisTypeClass* NewClass = (NoesisTypeClass*)NoesisCreateTypeClassForUMaterial(Material);
		ReplaceTypeClass(TypeClass, NewClass);

		NoesisDestroyViews();
	}
}

void NoesisDestroyTypeClassForMaterial(class UMaterialInterface* Material)
{
	OnMaterialChanged(Material);
}

void NoesisAssetRenamed(UObject* Object, FString OldPath)
{
	if (UBlueprint* Blueprint = Cast<UBlueprint>(Object))
	{
		UClass* Class = Blueprint->GeneratedClass;
		NoesisTypeClass** TypeClassPtr = ClassMap.Find(Class);
		if (TypeClassPtr != nullptr)
		{
			NoesisTypeClass* TypeClass = *TypeClassPtr;
			bool IsRegistered = IsTypeRegistered(TypeClass);
			if (IsRegistered)
			{
				Noesis::Reflection::UnregisterNoDelete(TypeClass);
			}
			FString RegisterClassName = RegisterNameFromPath(Class->GetPathName());
			TypeClass->ChangeName(Noesis::Symbol(TCHAR_TO_UTF8(*RegisterClassName)));
			if (IsRegistered)
			{
				Noesis::Reflection::RegisterType(TypeClass);
			}
		}
	}
	else if (UUserDefinedEnum* Enum = Cast<UUserDefinedEnum>(Object))
	{
		NoesisTypeEnum** TypeEnumPtr = EnumMap.Find(Enum);
		if (TypeEnumPtr != nullptr)
		{
			NoesisTypeEnum* TypeEnum = *TypeEnumPtr;
			bool IsRegistered = IsTypeRegistered(TypeEnum);
			if (IsRegistered)
			{
				Noesis::Reflection::UnregisterNoDelete(TypeEnum);
			}
			FString RegisterEnumName = RegisterNameFromPath(Enum->GetPathName());
			TypeEnum->ChangeName(Noesis::Symbol(TCHAR_TO_UTF8(*RegisterEnumName)));
			if (IsRegistered)
			{
				Noesis::Reflection::RegisterType(TypeEnum);
			}
		}
	}
	else if (UUserDefinedStruct* Struct = Cast<UUserDefinedStruct>(Object))
	{
		NoesisTypeClass** TypeClassPtr = StructMap.Find(Struct);
		if (TypeClassPtr != nullptr)
		{
			NoesisTypeClass* TypeClass = *TypeClassPtr;
			bool IsRegistered = IsTypeRegistered(TypeClass);
			if (IsRegistered)
			{
				Noesis::Reflection::UnregisterNoDelete(TypeClass);
			}
			FString RegisterClassName = RegisterNameFromPath(Struct->GetPathName());
			TypeClass->ChangeName(Noesis::Symbol(TCHAR_TO_UTF8(*RegisterClassName)));
			if (IsRegistered)
			{
				Noesis::Reflection::RegisterType(TypeClass);
			}
		}
	}
}
#endif

bool AssignStruct(void* Value, UScriptStruct* Struct, Noesis::BaseComponent* Input)
{
	if (!Input->GetClassType()->IsDescendantOf(NoesisStructWrapper::StaticGetClassType(nullptr)))
		return false;

	check(Noesis::DynamicCast<const NoesisTypeClass*>(Input->GetClassType()));
	if (((NoesisTypeClass*)Input->GetClassType())->Class != Struct)
		return false;

	NoesisStructWrapper* Wrapper = ((NoesisStructWrapper*)Input);
	bool Changed = !Struct->CompareScriptStruct(Value, Wrapper->GetStructPtr(), PPF_None);
	Struct->CopyScriptStruct(Value, Wrapper->GetStructPtr(), 1);
	return Changed;
}

bool AssignEnum(void* Value, UEnum* Enum, FNumericProperty* ValueProperty, Noesis::BaseComponent* Input)
{
	NoesisEnumWrapper* Wrapper = Noesis::DynamicCast<NoesisEnumWrapper*>(Input);
	if (Wrapper == nullptr)
		return false;

	const Noesis::Type* TypeEnum = Wrapper->GetValueType();
	check(Noesis::DynamicCast<const NoesisTypeEnum*>(TypeEnum));
	if (((NoesisTypeEnum*)TypeEnum)->Enum != Enum)
		return false;

	int64 InputValue = (int64)Noesis::Boxing::Unbox<int32>(Input);
	int64 IntValue = ValueProperty->GetSignedIntPropertyValue(Value);
	bool Changed = (InputValue != IntValue);
	ValueProperty->SetIntPropertyValue(Value, InputValue);
	return Changed;
}

const Noesis::Type* NoesisGetTypeForUStruct(UStruct* Class)
{
	return Noesis::TypeOf<NoesisStructWrapper>();
}

Noesis::TypeClass* NoesisCreateTypeClassForUStruct(UScriptStruct* Class)
{
	NoesisTypeClass** TypeClassPtr = StructMap.Find(Class);
	if (TypeClassPtr != nullptr)
	{
		return *TypeClassPtr;
	}

	FString RegisterClassName = RegisterNameFromPath(Class->GetPathName());
	NoesisTypeClass* TypeClass = new NoesisTypeClass(Noesis::Symbol(TCHAR_TO_UTF8(*RegisterClassName)));

	NoesisFillTypeClassForUStruct(TypeClass, Class);

	StructMap.Add(Class, TypeClass);
	return TypeClass;
}

Noesis::Ptr<Noesis::BaseComponent> NoesisCreateComponentForUStruct(UScriptStruct* Struct, void* Src)
{
	if (!Src)
	{
		return nullptr;
	}

	NoesisTypeClass* TypeClass = (NoesisTypeClass*)NoesisCreateTypeClassForUStruct(Struct);
	Noesis::Ptr<NoesisStructWrapper> Wrapper = *new NoesisStructWrapper(TypeClass);
	Struct->CopyScriptStruct(Wrapper->GetStructPtr(), Src, 1);

	return Wrapper;
}

NOESISRUNTIME_API Noesis::Ptr<Noesis::BaseComponent> NoesisFindComponentForUObject(UObject* Object)
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

	UClass* Class = Object->GetClass();
	if (Class == UTexture2D::StaticClass() || Class == UTextureRenderTarget2D::StaticClass())
	{
		NoesisTextureWrapper** WrapperPtr = TextureMap.Find(Object);
		if (WrapperPtr)
		{
			return Noesis::Ptr<Noesis::BaseComponent>(*WrapperPtr);
		}
	}
	else
	{
		NoesisObjectWrapper** WrapperPtr = ObjectMap.Find(Object);
		if (WrapperPtr)
		{
			return Noesis::Ptr<Noesis::BaseComponent>(*WrapperPtr);
		}
	}

	return nullptr;
}

NOESISRUNTIME_API UObject* NoesisFindUObjectForComponent(Noesis::BaseComponent* Component)
{
	if (Component == nullptr)
		return nullptr;

	NoesisObjectWrapper* Wrapper = Noesis::DynamicCast<NoesisObjectWrapper*>(Component);
	if (Wrapper != nullptr)
	{
		UObject* const* ObjectPtr = ObjectMap.FindKey(Wrapper);
		if (ObjectPtr)
		{
			return *ObjectPtr;
		}
	}

	return nullptr;
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

	NoesisObjectWrapper** WrapperPtr = ObjectMap.Find(Object);
	if (WrapperPtr)
	{
		return Noesis::Ptr<Noesis::BaseComponent>(*WrapperPtr);
	}

	UClass* Class = Object->GetClass();
	Noesis::Ptr<Noesis::BaseComponent> Wrapper;
	ISlateTextureAtlasInterface* SlateAtlas = Cast<ISlateTextureAtlasInterface>(Object);
	if (SlateAtlas != nullptr)
	{
		FSlateAtlasData AtlasData = SlateAtlas->GetSlateAtlasData();
		UTexture2D* Texture = Cast<UTexture2D>(AtlasData.AtlasTexture);
		if (Texture != nullptr)
		{
			Noesis::Ptr<NoesisTextureWrapper> TextureSource;
			NoesisTextureWrapper** TextureSourcePtr = TextureMap.Find(Texture);
			if (TextureSourcePtr != nullptr)
			{
				TextureSource.Reset(*TextureSourcePtr);
			}
			else
			{
				TextureSource = *new NoesisTextureWrapper(Texture);
				TextureMap.Add(Texture, TextureSource);
			}

			Wrapper = *new Noesis::CroppedBitmap(TextureSource, Noesis::Int32Rect(AtlasData.StartUV.X * Texture->GetSizeX(), AtlasData.StartUV.Y * Texture->GetSizeY(), AtlasData.SizeUV.X * Texture->GetSizeX(), AtlasData.SizeUV.Y * Texture->GetSizeY()));
		}
	}
	else if (Class->IsChildOf(UMaterialInterface::StaticClass()))
	{
		UMaterialInterface* Material = (UMaterialInterface*)Object;
		UMaterial* BaseMaterial = Material->GetBaseMaterial();
		if (BaseMaterial->MaterialDomain == MD_UI)
		{
			Wrapper = *new NoesisUIMaterialWrapper(Material);
		}
		else if (BaseMaterial->MaterialDomain == MD_PostProcess)
		{
			Wrapper = *new NoesisPostProcessMaterialWrapper(Material);
		}
	}
	else if (Class->IsChildOf(UTexture2D::StaticClass()) || Class->IsChildOf(UTextureRenderTarget2D::StaticClass()) || Class->IsChildOf(UMediaTexture::StaticClass()))
	{
		UTexture* Texture = (UTexture*)Object;
		return NoesisCreateComponentForUTexture(Texture);
	}
	else
	{
		Wrapper = *new NoesisObjectWrapper(Object);
	}

	return Wrapper;
}

NOESISRUNTIME_API UObject* NoesisCreateUObjectForComponent(Noesis::BaseComponent* Component)
{
	// Don't create a UNoesisBaseComponent for null Components
	if (Component == nullptr)
		return nullptr;

	NoesisObjectWrapper* Wrapper = Noesis::DynamicCast<NoesisObjectWrapper*>(Component);
	if (Wrapper != nullptr)
	{
		UObject* const* ObjectPtr = ObjectMap.FindKey(Wrapper);
		if (ObjectPtr)
		{
			return *ObjectPtr;
		}
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
	NoesisObjectWrapper** WrapperPtr = ObjectMap.Find(Owner);
	if (WrapperPtr)
	{
		NoesisObjectWrapper* Wrapper = *WrapperPtr;
		auto PropertySymbol = Noesis::Symbol(TCHAR_TO_UTF8(*PropertyName.ToString()));
#if DO_CHECK // Skip in shipping build
		const Noesis::TypeClass* WrapperTypeClass = Wrapper->GetClassType();
		Noesis::TypeClassProperty ClassProperty = Noesis::FindProperty(WrapperTypeClass, PropertySymbol);
		const Noesis::TypeProperty* TypeProperty = ClassProperty.property;
		if (TypeProperty == nullptr)
		{
			NS_LOG("Couldn't resolve property %s::%s",
				TCHARToNsString(*Owner->GetClass()->GetFName().ToString()).Str(),
				TCHARToNsString(*PropertyName.ToString()).Str());
		}
#endif
		Wrapper->NotifyPropertyChanged(PropertySymbol);
	}
}

void NoesisNotifyArrayPropertyChanged(UObject* Owner, FName ArrayPropertyName)
{
	SCOPE_CYCLE_COUNTER(STAT_NoesisNotifyArrayPropertyChanged);
	if (!IsValid(Owner))
		return;

	// NoesisArrayWrappers can only come from properties of the class, not from Getters, so this is equivalent to the
	// previous code, except that we don't create a temporary wrapper if one didn't already exist.
	UClass* OwnerClass = Owner->GetClass();
	FProperty* ArrayProperty = OwnerClass->FindPropertyByName(ArrayPropertyName);
	if (ArrayProperty != nullptr)
	{
		void* ArrayPointer = ArrayProperty->template ContainerPtrToValuePtr<void>(Owner);
		NoesisNotifyArrayPropertyPostReset(ArrayPointer);
	}
#if DO_CHECK // Skip in shipping build
	else
	{
		NS_LOG("Couldn't resolve Array property %s::%s",
			TCHARToNsString(*Owner->GetClass()->GetFName().ToString()).Str(),
			TCHARToNsString(*ArrayPropertyName.ToString()).Str());
	}
#endif
}

void NoesisNotifyMapPropertyChanged(UObject* Owner, FName MapPropertyName)
{
	//SCOPE_CYCLE_COUNTER(STAT_NoesisNotifyArrayPropertyChanged);
	if (!IsValid(Owner))
		return;

	// NoesisArrayWrappers can only come from properties of the class, not from Getters, so this is equivalent to the
	// previous code, except that we don't create a temporary wrapper if one didn't already exist.
	UClass* OwnerClass = Owner->GetClass();
	FProperty* MapProperty = OwnerClass->FindPropertyByName(MapPropertyName);
	if (MapProperty != nullptr)
	{
		void* MapPointer = MapProperty->template ContainerPtrToValuePtr<void>(Owner);
		NoesisNotifyMapPropertyPostReset(MapPointer);
	}
#if DO_CHECK // Skip in shipping build
	else
	{
		NS_LOG("Couldn't resolve Map property %s::%s",
			TCHARToNsString(*Owner->GetClass()->GetFName().ToString()).Str(),
			TCHARToNsString(*MapPropertyName.ToString()).Str());
	}
#endif
}

void NoesisNotifyCanExecuteFunctionChanged(UObject* Owner, FName FunctionName)
{
	SCOPE_CYCLE_COUNTER(STAT_NoesisNotifyCanExecuteFunctionChanged);
	if (!IsValid(Owner))
		return;

	// NoesisArrayWrappers can only come from properties of the class, not from Getters, so this is equivalent to the
	// previous code, except that we don't create a temporary wrapper if one didn't already exist.
	UClass* OwnerClass = Owner->GetClass();
	UFunction* Function = OwnerClass->FindFunctionByName(FunctionName);
	if (Function != nullptr)
	{
		NoesisNotifyCanExecuteFunctionChanged(Owner, Function);
	}
#if DO_CHECK // Skip in shipping build
	else
	{
		NS_LOG("Couldn't resolve function %s::%s",
			TCHARToNsString(*Owner->GetClass()->GetFName().ToString()).Str(),
			TCHARToNsString(*FunctionName.ToString()).Str());
	}
#endif
}

void NoesisNotifyCanExecuteFunctionChanged(class UObject* Owner, class UFunction* Function)
{
	NoesisObjectWrapper** WrapperPtr = ObjectMap.Find(Owner);
	if (WrapperPtr)
	{
		NoesisObjectWrapper* Wrapper = *WrapperPtr;
		auto CommandPtr = Wrapper->CommandMap.Find(Function);
		if (CommandPtr != nullptr)
		{
			NoesisFunctionWrapper* CommandWrapper = *CommandPtr;
			CommandWrapper->RaiseCanExecuteChanged();
		}
	}
}

void NoesisNotifyArrayPropertyPostAdd(void* ArrayPointer)
{
	SCOPE_CYCLE_COUNTER(STAT_NoesisNotifyArrayPropertyAdd);
	NoesisArrayWrapper** ArrayWrapperPtr = ArrayMap.Find(ArrayPointer);
	if (ArrayWrapperPtr)
	{
		NoesisArrayWrapper* Array = *ArrayWrapperPtr;
		Array->NotifyPostAdd();
	}
}

void NoesisNotifyArrayPropertyPostChanged(void* ArrayPointer)
{
	NoesisNotifyArrayPropertyPostReset(ArrayPointer);
}

void NoesisNotifyArrayPropertyPreAppend(void* ArrayPointer)
{
	SCOPE_CYCLE_COUNTER(STAT_NoesisNotifyArrayPropertyAppend);
	NoesisArrayWrapper** ArrayWrapperPtr = ArrayMap.Find(ArrayPointer);
	if (ArrayWrapperPtr)
	{
		NoesisArrayWrapper* Array = *ArrayWrapperPtr;
		Array->NotifyPreAppend();
	}
}

void NoesisNotifyArrayPropertyPostAppend(void* ArrayPointer)
{
	SCOPE_CYCLE_COUNTER(STAT_NoesisNotifyArrayPropertyAppend);
	NoesisArrayWrapper** ArrayWrapperPtr = ArrayMap.Find(ArrayPointer);
	if (ArrayWrapperPtr)
	{
		NoesisArrayWrapper* Array = *ArrayWrapperPtr;
		Array->NotifyPostAppend();
	}
}

void NoesisNotifyArrayPropertyPostInsert(void* ArrayPointer, int32 Index)
{
	SCOPE_CYCLE_COUNTER(STAT_NoesisNotifyArrayPropertyInsert);
	NoesisArrayWrapper** ArrayWrapperPtr = ArrayMap.Find(ArrayPointer);
	if (ArrayWrapperPtr)
	{
		NoesisArrayWrapper* Array = *ArrayWrapperPtr;
		Array->NotifyPostInsert(Index);
	}
}

void NoesisNotifyArrayPropertyPreRemove(void* ArrayPointer, int32 Index)
{
	SCOPE_CYCLE_COUNTER(STAT_NoesisNotifyArrayPropertyRemove);
	NoesisArrayWrapper** ArrayWrapperPtr = ArrayMap.Find(ArrayPointer);
	if (ArrayWrapperPtr)
	{
		NoesisArrayWrapper* Array = *ArrayWrapperPtr;
		Array->NotifyPreRemoveAt(Index);
	}
}

void NoesisNotifyArrayPropertyPostRemove(void* ArrayPointer, int32 Index)
{
	SCOPE_CYCLE_COUNTER(STAT_NoesisNotifyArrayPropertyRemove);
	NoesisArrayWrapper** ArrayWrapperPtr = ArrayMap.Find(ArrayPointer);
	if (ArrayWrapperPtr)
	{
		NoesisArrayWrapper* Array = *ArrayWrapperPtr;
		Array->NotifyPostRemoveAt(Index);
	}
}

void NoesisNotifyArrayPropertyPostClear(void* ArrayPointer)
{
	SCOPE_CYCLE_COUNTER(STAT_NoesisNotifyArrayPropertyClear);
	NoesisArrayWrapper** ArrayWrapperPtr = ArrayMap.Find(ArrayPointer);
	if (ArrayWrapperPtr)
	{
		NoesisArrayWrapper* Array = *ArrayWrapperPtr;
		Array->NotifyPostReset();
	}
}

void NoesisNotifyArrayPropertyPreSet(void* ArrayPointer, int32 Index)
{
	SCOPE_CYCLE_COUNTER(STAT_NoesisNotifyArrayPropertySet);
	NoesisArrayWrapper** ArrayWrapperPtr = ArrayMap.Find(ArrayPointer);
	if (ArrayWrapperPtr)
	{
		NoesisArrayWrapper* Array = *ArrayWrapperPtr;
		Array->NotifyPreSet(Index);
	}
}

void NoesisNotifyArrayPropertyPostSet(void* ArrayPointer, int32 Index)
{
	SCOPE_CYCLE_COUNTER(STAT_NoesisNotifyArrayPropertySet);
	NoesisArrayWrapper** ArrayWrapperPtr = ArrayMap.Find(ArrayPointer);
	if (ArrayWrapperPtr)
	{
		NoesisArrayWrapper* Array = *ArrayWrapperPtr;
		Array->NotifyPostSet(Index);
	}
}

void NoesisNotifyArrayPropertyPostReset(void* ArrayPointer)
{
	SCOPE_CYCLE_COUNTER(STAT_NoesisNotifyArrayPropertyChanged);
	NoesisArrayWrapper** ArrayWrapperPtr = ArrayMap.Find(ArrayPointer);
	if (ArrayWrapperPtr)
	{
		NoesisArrayWrapper* Array = *ArrayWrapperPtr;
		Array->NotifyPostReset();
	}
}

void NoesisNotifyMapPropertyPostAdd(void* MapPointer, const FString& Key)
{
	SCOPE_CYCLE_COUNTER(STAT_NoesisNotifyMapPropertyAdd);
	NoesisMapWrapper** MapWrapperPtr = MapMap.Find(MapPointer);
	if (MapWrapperPtr)
	{
		NoesisMapWrapper* Map = *MapWrapperPtr;
		Map->NotifyPostAdd(TCHAR_TO_UTF8(*Key));
	}
}

void NoesisNotifyMapPropertyPostChanged(void* MapPointer)
{
	NoesisNotifyMapPropertyPostReset(MapPointer);
}

void NoesisNotifyMapPropertyPostReset(void* MapPointer)
{
	SCOPE_CYCLE_COUNTER(STAT_NoesisNotifyMapPropertyChanged);
	NoesisMapWrapper** MapWrapperPtr = MapMap.Find(MapPointer);
	if (MapWrapperPtr)
	{
		NoesisMapWrapper* Map = *MapWrapperPtr;
		Map->NotifyPostReset();
	}
}

void NoesisNotifyMapPropertyPreRemove(void* MapPointer, const FString& Key)
{
	SCOPE_CYCLE_COUNTER(STAT_NoesisNotifyMapPropertyRemove);
	NoesisMapWrapper** MapWrapperPtr = MapMap.Find(MapPointer);
	if (MapWrapperPtr)
	{
		NoesisMapWrapper* Map = *MapWrapperPtr;
		Map->NotifyPreRemove(TCHAR_TO_UTF8(*Key));
	}
}

void NoesisNotifyMapPropertyPostRemove(void* MapPointer, const FString& Key)
{
	SCOPE_CYCLE_COUNTER(STAT_NoesisNotifyMapPropertyRemove);
	NoesisMapWrapper** MapWrapperPtr = MapMap.Find(MapPointer);
	if (MapWrapperPtr)
	{
		NoesisMapWrapper* Map = *MapWrapperPtr;
		Map->NotifyPostRemove(TCHAR_TO_UTF8(*Key));
	}
}

void NoesisDeleteMaps()
{
	NoesisIsShuttingDown = true;

	for (auto Pair : ClassMap)
	{
		ReplaceTypeClass(Pair.Value, nullptr);
	}
	ClassMap.Empty();

	for (auto Pair : StructMap)
	{
		ReplaceTypeClass(Pair.Value, nullptr);
	}
	StructMap.Empty();

	for (auto Pair : EnumMap)
	{
		ReplaceType(Pair.Value, nullptr);
	}
	EnumMap.Empty();

	for (auto Pair : MaterialMap)
	{
		ReplaceType(Pair.Value, nullptr);
	}
	MaterialMap.Empty();

	for (auto TypeClass : DeletedTypes)
	{
		delete TypeClass;
	}
	DeletedTypes.Empty();
}

void NoesisCultureChanged()
{
	if (GIsRunning)
	{
		for (auto It = ObjectMap.CreateIterator(); It; ++It)
		{
			auto& ObjectComponentPair = *It;
			UObject* Object = ObjectComponentPair.Key;
			if (IsValid(Object) && !Object->IsUnreachable())
			{
				NoesisObjectWrapper* Wrapper = ObjectComponentPair.Value;
				UClass* Class = Object->GetClass();

				for (TFieldIterator<FProperty> PropertyIt(Class, EFieldIteratorFlags::IncludeSuper); PropertyIt; ++PropertyIt)
				{
					FProperty* Property = *PropertyIt;
					if (Property->IsA<FTextProperty>())
					{
						FString PropertyName = Property->GetName();
						Noesis::Symbol PropertyId = Noesis::Symbol(TCHAR_TO_UTF8(*PropertyName));

						Wrapper->NotifyPropertyChanged(PropertyId);
					}
				}

				for (TFieldIterator<UFunction> FunctionIt(Class, EFieldIteratorFlags::IncludeSuper); FunctionIt; ++FunctionIt)
				{
					UFunction* Function = *FunctionIt;
					if (Function->GetName().StartsWith(TEXT("Get")) && Function->NumParms == 1 && Function->HasAnyFunctionFlags(FUNC_HasOutParms))
					{
						FProperty* OutParam = CastField<FProperty>(Function->ChildProperties);

						if (OutParam->IsA<FTextProperty>())
						{
							FString PropertyName = Function->GetName().RightChop(3);
							Noesis::Symbol PropertyId = Noesis::Symbol(TCHAR_TO_UTF8(*PropertyName));

							Wrapper->NotifyPropertyChanged(PropertyId);
						}
					}
				}
			}
		}
	}
}

void NoesisGarbageCollected()
{
	if (GIsRunning)
	{
		SCOPE_CYCLE_COUNTER(STAT_NoesisGarbageCollected);
		for (auto It = ObjectMap.CreateIterator(); It; ++It)
		{
			auto& ObjectComponentPair = *It;
			UObject* Object = ObjectComponentPair.Key;
			if (Object->IsUnreachable())
			{
				NoesisObjectWrapper* Wrapper = ObjectComponentPair.Value;
				Wrapper->Object = nullptr;
				It.RemoveCurrent();
			}
		}

		for (auto It = TextureMap.CreateIterator(); It; ++It)
		{
			auto& ObjectComponentPair = *It;
			UObject* Object = ObjectComponentPair.Key;
			if (Object->IsUnreachable())
			{
				NoesisTextureWrapper* Wrapper = ObjectComponentPair.Value;
				Wrapper->Texture = nullptr;
				It.RemoveCurrent();
			}
		}

		for (auto It = ClassMap.CreateIterator(); It; ++It)
		{
			auto& ObjectComponentPair = *It;
			UClass* Class = ObjectComponentPair.Key;
			if (Class->IsUnreachable())
			{
				NoesisTypeClass* Type = ObjectComponentPair.Value;
				ReplaceTypeClass(Type, nullptr);
				It.RemoveCurrent();
			}
		}

		for (auto It = StructMap.CreateIterator(); It; ++It)
		{
			auto& ObjectComponentPair = *It;
			UStruct* Class = ObjectComponentPair.Key;
			if (Class->IsUnreachable())
			{
				NoesisTypeClass* Type = ObjectComponentPair.Value;
				ReplaceTypeClass(Type, nullptr);
				It.RemoveCurrent();
			}
		}

		for (auto It = EnumMap.CreateIterator(); It; ++It)
		{
			auto& ObjectComponentPair = *It;
			UEnum* Enum = ObjectComponentPair.Key;
			if (Enum->IsUnreachable())
			{
				NoesisTypeEnum* Type = ObjectComponentPair.Value;
				ReplaceType(Type, nullptr);
				It.RemoveCurrent();
			}
		}
	}
}

void NoesisReflectionRegistryCallback(Noesis::Symbol Name)
{
	// Can't load objects in these circumstances
	if (GIsSavingPackage || (IsInGameThread() && IsGarbageCollecting()))
		return;

	// Make sure the name doesn't have invalid charaters to avoid errors in LoadObject
	FString UnrealTypeName = UTF8_TO_TCHAR(Name.Str());
	if (UnrealTypeName.Contains(TEXT("<")))
		return;

	// Warn users about unsupported types in Unreal
	if (UnrealTypeName == "Application")
	{
		NS_LOG("Application not supported in Unreal, please set Application Resources in NoesisGUI settings.");
		return;
	}
	if (UnrealTypeName == "Window")
	{
		NS_LOG("Window not supported in Unreal, please use Page or UserControl instead.");
		return;
	}

	// Find asset from type name
	FString GamePath = PathFromRegisterName_GameAsset(UnrealTypeName);
	UObject* Object = LoadObject<UObject>(nullptr, *GamePath, nullptr, LOAD_NoWarn);
	if (Object == nullptr)
	{
		Object = LoadObject<UObject>(nullptr, *(GamePath + TEXT("_C")), nullptr, LOAD_NoWarn);
		if (Object == nullptr)
		{
			Object = LoadObject<UObject>(nullptr, *PathFromRegisterName_Native(UnrealTypeName), nullptr, LOAD_NoWarn);
			if (Object == nullptr)
			{
				FString ModulePath = PathFromRegisterName_ModuleAsset(UnrealTypeName);
				if (!ModulePath.IsEmpty())
				{
					Object = LoadObject<UObject>(nullptr, *ModulePath, nullptr, LOAD_NoWarn);
					if (Object == nullptr)
					{
						Object = LoadObject<UObject>(nullptr, *(ModulePath + TEXT("_C")), nullptr, LOAD_NoWarn);
						if (Object == nullptr)
						{
							return;
						}
					}
				}
				else
				{
					return;
				}
			}
		}
	}

	if (Object->IsA<UBlueprint>())
	{
		Noesis::TypeClass* Type = NoesisCreateTypeClassForUClass(((UBlueprint*)Object)->GeneratedClass);
		Noesis::Reflection::RegisterType(Type);
	}
	else if (Object->IsA<UClass>())
	{
		Noesis::TypeClass* Type = NoesisCreateTypeClassForUClass((UClass*)Object);
		Noesis::Reflection::RegisterType(Type);
	}
	else if (Object->IsA<UScriptStruct>())
	{
		Noesis::TypeClass* Type = NoesisCreateTypeClassForUStruct((UScriptStruct*)Object);
		Noesis::Reflection::RegisterType(Type);
	}
	else if (Object->IsA<UEnum>())
	{
		Noesis::TypeEnum* Type = NoesisCreateTypeEnumForUEnum((UEnum*)Object);
		Noesis::Reflection::RegisterType(Type);
	}
	else if (Object->IsA<UMaterialInterface>())
	{
		Noesis::TypeClass* Type = NoesisCreateTypeClassForUMaterial((UMaterialInterface*)Object);
		Noesis::Reflection::RegisterType(Type);
	}
}
