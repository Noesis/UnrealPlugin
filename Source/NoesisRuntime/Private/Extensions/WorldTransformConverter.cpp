////////////////////////////////////////////////////////////////////////////////////////////////////
// NoesisGUI - http://www.noesisengine.com
// Copyright (c) 2013 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#include "Extensions/WorldTransformConverter.h"


////////////////////////////////////////////////////////////////////////////////////////////////////
bool WorldTransformConverter::TryConvert(Noesis::BaseComponent* Value, const Noesis::Type* TargetType,
	Noesis::BaseComponent*, Noesis::Ptr<Noesis::BaseComponent>& Result)
{
	if (TargetType != Noesis::TypeOf<Noesis::Transform3>())
		return false;

	if (!Noesis::Boxing::CanUnbox<Noesis::Transform3>(Value))
		return false;
	
	Noesis::Transform3 Transform = Noesis::Boxing::Unbox<Noesis::Transform3>(Value);

	/// Transform = BaseChange * UnrealTransform * Inverse(BaseChange), where
	/// BaseChange = Matrix4(
	///		 0.f, -1.f,  0.f, 0.f,
	///		 0.f,  0.f, -1.f, 0.f,
	///		-1.f,  0.f,  0.f, 0.f,
	///		 0.f,  0.f,  0.f, 1.f
	///	);
	/// BaseChange transforms from Unreal's coordinate system to what we need.
	/// Doing it this way we can skip a lot of multiplies by 0.0f and 1.0f.
	
	auto t = Noesis::Transform3(
		 Transform[1][1],  Transform[1][2],  Transform[1][0],
		 Transform[2][1],  Transform[2][2],  Transform[2][0],
		 Transform[0][1],  Transform[0][2],  Transform[0][0],
		-Transform[3][1], -Transform[3][2], -Transform[3][0]
	);

	Result = Noesis::Boxing::Box(t);
	return true;
}

////////////////////////////////////////////////////////////////////////////////////////////////////
NS_BEGIN_COLD_REGION

NS_IMPLEMENT_REFLECTION_(WorldTransformConverter, "NoesisGUIExtensions.WorldTransformConverter")

NS_END_COLD_REGION
