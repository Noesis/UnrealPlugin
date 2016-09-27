////////////////////////////////////////////////////////////////////////////////////////////////////
// Noesis Engine - http://www.noesisengine.com
// Copyright (c) 2009-2010 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#pragma once

#include "NoesisGuiGeneratedClasses.h"

UNoesisGuiBaseComponent* CreateClassFor(Noesis::Core::BaseComponent* BaseComponent, UObject* Outer)
{
	const Noesis::Core::TypeClass* BaseComponentClass = BaseComponent->GetClassType();
	if (BaseComponentClass == Noesis::Gui::BaseBinding::StaticGetClassType())
	{
		UNoesisGuiBaseComponent* Component = NewObject<UNoesisGuiBaseBinding>(Outer);
		Component->SetNoesisComponent(BaseComponent);
		return Component;
	}
	if (BaseComponentClass == Noesis::Gui::Binding::StaticGetClassType())
	{
		UNoesisGuiBaseComponent* Component = NewObject<UNoesisGuiBinding>(Outer);
		Component->SetNoesisComponent(BaseComponent);
		return Component;
	}
	if (BaseComponentClass == Noesis::Gui::BaseCommand::StaticGetClassType())
	{
		UNoesisGuiBaseComponent* Component = NewObject<UNoesisGuiBaseCommand>(Outer);
		Component->SetNoesisComponent(BaseComponent);
		return Component;
	}
	if (BaseComponentClass == Noesis::Gui::BaseDictionary::StaticGetClassType())
	{
		UNoesisGuiBaseComponent* Component = NewObject<UNoesisGuiBaseDictionary>(Outer);
		Component->SetNoesisComponent(BaseComponent);
		return Component;
	}
	if (BaseComponentClass == Noesis::Gui::ResourceDictionary::StaticGetClassType())
	{
		UNoesisGuiBaseComponent* Component = NewObject<UNoesisGuiResourceDictionary>(Outer);
		Component->SetNoesisComponent(BaseComponent);
		return Component;
	}
	if (BaseComponentClass == Noesis::Gui::BaseExpression::StaticGetClassType())
	{
		UNoesisGuiBaseComponent* Component = NewObject<UNoesisGuiBaseExpression>(Outer);
		Component->SetNoesisComponent(BaseComponent);
		return Component;
	}
	if (BaseComponentClass == Noesis::Gui::BaseBindingExpression::StaticGetClassType())
	{
		UNoesisGuiBaseComponent* Component = NewObject<UNoesisGuiBaseBindingExpression>(Outer);
		Component->SetNoesisComponent(BaseComponent);
		return Component;
	}
	if (BaseComponentClass == Noesis::Gui::BaseSetter::StaticGetClassType())
	{
		UNoesisGuiBaseComponent* Component = NewObject<UNoesisGuiBaseSetter>(Outer);
		Component->SetNoesisComponent(BaseComponent);
		return Component;
	}
	if (BaseComponentClass == Noesis::Gui::Setter::StaticGetClassType())
	{
		UNoesisGuiBaseComponent* Component = NewObject<UNoesisGuiSetter>(Outer);
		Component->SetNoesisComponent(BaseComponent);
		return Component;
	}
	if (BaseComponentClass == Noesis::Gui::BaseValueConverter::StaticGetClassType())
	{
		UNoesisGuiBaseComponent* Component = NewObject<UNoesisGuiBaseValueConverter>(Outer);
		Component->SetNoesisComponent(BaseComponent);
		return Component;
	}
	if (BaseComponentClass == Noesis::Gui::Clock::StaticGetClassType())
	{
		UNoesisGuiBaseComponent* Component = NewObject<UNoesisGuiClock>(Outer);
		Component->SetNoesisComponent(BaseComponent);
		return Component;
	}
	if (BaseComponentClass == Noesis::Gui::AnimationClock::StaticGetClassType())
	{
		UNoesisGuiBaseComponent* Component = NewObject<UNoesisGuiAnimationClock>(Outer);
		Component->SetNoesisComponent(BaseComponent);
		return Component;
	}
	if (BaseComponentClass == Noesis::Gui::ClockGroup::StaticGetClassType())
	{
		UNoesisGuiBaseComponent* Component = NewObject<UNoesisGuiClockGroup>(Outer);
		Component->SetNoesisComponent(BaseComponent);
		return Component;
	}
	if (BaseComponentClass == Noesis::Gui::Collection::StaticGetClassType())
	{
		UNoesisGuiBaseComponent* Component = NewObject<UNoesisGuiCollection>(Outer);
		Component->SetNoesisComponent(BaseComponent);
		return Component;
	}
	if (BaseComponentClass == Noesis::Gui::TriggerCollection::StaticGetClassType())
	{
		UNoesisGuiBaseComponent* Component = NewObject<UNoesisGuiTriggerCollection>(Outer);
		Component->SetNoesisComponent(BaseComponent);
		return Component;
	}
	if (BaseComponentClass == Noesis::Gui::InputBindingCollection::StaticGetClassType())
	{
		UNoesisGuiBaseComponent* Component = NewObject<UNoesisGuiInputBindingCollection>(Outer);
		Component->SetNoesisComponent(BaseComponent);
		return Component;
	}
	if (BaseComponentClass == Noesis::Gui::BaseSetterCollection::StaticGetClassType())
	{
		UNoesisGuiBaseComponent* Component = NewObject<UNoesisGuiBaseSetterCollection>(Outer);
		Component->SetNoesisComponent(BaseComponent);
		return Component;
	}
	if (BaseComponentClass == Noesis::Gui::VisualStateCollection::StaticGetClassType())
	{
		UNoesisGuiBaseComponent* Component = NewObject<UNoesisGuiVisualStateCollection>(Outer);
		Component->SetNoesisComponent(BaseComponent);
		return Component;
	}
	if (BaseComponentClass == Noesis::Gui::CommandBindingCollection::StaticGetClassType())
	{
		UNoesisGuiBaseComponent* Component = NewObject<UNoesisGuiCommandBindingCollection>(Outer);
		Component->SetNoesisComponent(BaseComponent);
		return Component;
	}
	if (BaseComponentClass == Noesis::Gui::InlineCollection::StaticGetClassType())
	{
		UNoesisGuiBaseComponent* Component = NewObject<UNoesisGuiInlineCollection>(Outer);
		Component->SetNoesisComponent(BaseComponent);
		return Component;
	}
	if (BaseComponentClass == Noesis::Gui::ColumnDefinitionCollection::StaticGetClassType())
	{
		UNoesisGuiBaseComponent* Component = NewObject<UNoesisGuiColumnDefinitionCollection>(Outer);
		Component->SetNoesisComponent(BaseComponent);
		return Component;
	}
	if (BaseComponentClass == Noesis::Gui::RowDefinitionCollection::StaticGetClassType())
	{
		UNoesisGuiBaseComponent* Component = NewObject<UNoesisGuiRowDefinitionCollection>(Outer);
		Component->SetNoesisComponent(BaseComponent);
		return Component;
	}
	if (BaseComponentClass == Noesis::Gui::GridViewColumnCollection::StaticGetClassType())
	{
		UNoesisGuiBaseComponent* Component = NewObject<UNoesisGuiGridViewColumnCollection>(Outer);
		Component->SetNoesisComponent(BaseComponent);
		return Component;
	}
	if (BaseComponentClass == Noesis::Gui::TriggerActionCollection::StaticGetClassType())
	{
		UNoesisGuiBaseComponent* Component = NewObject<UNoesisGuiTriggerActionCollection>(Outer);
		Component->SetNoesisComponent(BaseComponent);
		return Component;
	}
	if (BaseComponentClass == Noesis::Gui::ConditionCollection::StaticGetClassType())
	{
		UNoesisGuiBaseComponent* Component = NewObject<UNoesisGuiConditionCollection>(Outer);
		Component->SetNoesisComponent(BaseComponent);
		return Component;
	}
	if (BaseComponentClass == Noesis::Gui::VisualTransitionCollection::StaticGetClassType())
	{
		UNoesisGuiBaseComponent* Component = NewObject<UNoesisGuiVisualTransitionCollection>(Outer);
		Component->SetNoesisComponent(BaseComponent);
		return Component;
	}
	if (BaseComponentClass == Noesis::Gui::InputGestureCollection::StaticGetClassType())
	{
		UNoesisGuiBaseComponent* Component = NewObject<UNoesisGuiInputGestureCollection>(Outer);
		Component->SetNoesisComponent(BaseComponent);
		return Component;
	}
	if (BaseComponentClass == Noesis::Gui::VisualCollection::StaticGetClassType())
	{
		UNoesisGuiBaseComponent* Component = NewObject<UNoesisGuiVisualCollection>(Outer);
		Component->SetNoesisComponent(BaseComponent);
		return Component;
	}
	if (BaseComponentClass == Noesis::Gui::UIElementCollection::StaticGetClassType())
	{
		UNoesisGuiBaseComponent* Component = NewObject<UNoesisGuiUIElementCollection>(Outer);
		Component->SetNoesisComponent(BaseComponent);
		return Component;
	}
	if (BaseComponentClass == Noesis::Gui::CommandBinding::StaticGetClassType())
	{
		UNoesisGuiBaseComponent* Component = NewObject<UNoesisGuiCommandBinding>(Outer);
		Component->SetNoesisComponent(BaseComponent);
		return Component;
	}
	if (BaseComponentClass == Noesis::Gui::Condition::StaticGetClassType())
	{
		UNoesisGuiBaseComponent* Component = NewObject<UNoesisGuiCondition>(Outer);
		Component->SetNoesisComponent(BaseComponent);
		return Component;
	}
	if (BaseComponentClass == Noesis::Gui::DataTemplateSelector::StaticGetClassType())
	{
		UNoesisGuiBaseComponent* Component = NewObject<UNoesisGuiDataTemplateSelector>(Outer);
		Component->SetNoesisComponent(BaseComponent);
		return Component;
	}
	if (BaseComponentClass == Noesis::Gui::DependencyObject::StaticGetClassType())
	{
		UNoesisGuiBaseComponent* Component = NewObject<UNoesisGuiDependencyObject>(Outer);
		Component->SetNoesisComponent(BaseComponent);
		return Component;
	}
	if (BaseComponentClass == Noesis::Gui::BaseTrigger::StaticGetClassType())
	{
		UNoesisGuiBaseComponent* Component = NewObject<UNoesisGuiBaseTrigger>(Outer);
		Component->SetNoesisComponent(BaseComponent);
		return Component;
	}
	if (BaseComponentClass == Noesis::Gui::DataTrigger::StaticGetClassType())
	{
		UNoesisGuiBaseComponent* Component = NewObject<UNoesisGuiDataTrigger>(Outer);
		Component->SetNoesisComponent(BaseComponent);
		return Component;
	}
	if (BaseComponentClass == Noesis::Gui::EventTrigger::StaticGetClassType())
	{
		UNoesisGuiBaseComponent* Component = NewObject<UNoesisGuiEventTrigger>(Outer);
		Component->SetNoesisComponent(BaseComponent);
		return Component;
	}
	if (BaseComponentClass == Noesis::Gui::MultiDataTrigger::StaticGetClassType())
	{
		UNoesisGuiBaseComponent* Component = NewObject<UNoesisGuiMultiDataTrigger>(Outer);
		Component->SetNoesisComponent(BaseComponent);
		return Component;
	}
	if (BaseComponentClass == Noesis::Gui::MultiTrigger::StaticGetClassType())
	{
		UNoesisGuiBaseComponent* Component = NewObject<UNoesisGuiMultiTrigger>(Outer);
		Component->SetNoesisComponent(BaseComponent);
		return Component;
	}
	if (BaseComponentClass == Noesis::Gui::Trigger::StaticGetClassType())
	{
		UNoesisGuiBaseComponent* Component = NewObject<UNoesisGuiTrigger>(Outer);
		Component->SetNoesisComponent(BaseComponent);
		return Component;
	}
	if (BaseComponentClass == Noesis::Gui::BaseView::StaticGetClassType())
	{
		UNoesisGuiBaseComponent* Component = NewObject<UNoesisGuiBaseView>(Outer);
		Component->SetNoesisComponent(BaseComponent);
		return Component;
	}
	if (BaseComponentClass == Noesis::Gui::GridView::StaticGetClassType())
	{
		UNoesisGuiBaseComponent* Component = NewObject<UNoesisGuiGridView>(Outer);
		Component->SetNoesisComponent(BaseComponent);
		return Component;
	}
	if (BaseComponentClass == Noesis::Gui::CollectionViewSource::StaticGetClassType())
	{
		UNoesisGuiBaseComponent* Component = NewObject<UNoesisGuiCollectionViewSource>(Outer);
		Component->SetNoesisComponent(BaseComponent);
		return Component;
	}
	if (BaseComponentClass == Noesis::Gui::Freezable::StaticGetClassType())
	{
		UNoesisGuiBaseComponent* Component = NewObject<UNoesisGuiFreezable>(Outer);
		Component->SetNoesisComponent(BaseComponent);
		return Component;
	}
	if (BaseComponentClass == Noesis::Gui::Animatable::StaticGetClassType())
	{
		UNoesisGuiBaseComponent* Component = NewObject<UNoesisGuiAnimatable>(Outer);
		Component->SetNoesisComponent(BaseComponent);
		return Component;
	}
	if (BaseComponentClass == Noesis::Gui::Brush::StaticGetClassType())
	{
		UNoesisGuiBaseComponent* Component = NewObject<UNoesisGuiBrush>(Outer);
		Component->SetNoesisComponent(BaseComponent);
		return Component;
	}
	if (BaseComponentClass == Noesis::Gui::GradientBrush::StaticGetClassType())
	{
		UNoesisGuiBaseComponent* Component = NewObject<UNoesisGuiGradientBrush>(Outer);
		Component->SetNoesisComponent(BaseComponent);
		return Component;
	}
	if (BaseComponentClass == Noesis::Gui::LinearGradientBrush::StaticGetClassType())
	{
		UNoesisGuiBaseComponent* Component = NewObject<UNoesisGuiLinearGradientBrush>(Outer);
		Component->SetNoesisComponent(BaseComponent);
		return Component;
	}
	if (BaseComponentClass == Noesis::Gui::RadialGradientBrush::StaticGetClassType())
	{
		UNoesisGuiBaseComponent* Component = NewObject<UNoesisGuiRadialGradientBrush>(Outer);
		Component->SetNoesisComponent(BaseComponent);
		return Component;
	}
	if (BaseComponentClass == Noesis::Gui::SolidColorBrush::StaticGetClassType())
	{
		UNoesisGuiBaseComponent* Component = NewObject<UNoesisGuiSolidColorBrush>(Outer);
		Component->SetNoesisComponent(BaseComponent);
		return Component;
	}
	if (BaseComponentClass == Noesis::Gui::TileBrush::StaticGetClassType())
	{
		UNoesisGuiBaseComponent* Component = NewObject<UNoesisGuiTileBrush>(Outer);
		Component->SetNoesisComponent(BaseComponent);
		return Component;
	}
	if (BaseComponentClass == Noesis::Gui::ImageBrush::StaticGetClassType())
	{
		UNoesisGuiBaseComponent* Component = NewObject<UNoesisGuiImageBrush>(Outer);
		Component->SetNoesisComponent(BaseComponent);
		return Component;
	}
	if (BaseComponentClass == Noesis::Gui::VisualBrush::StaticGetClassType())
	{
		UNoesisGuiBaseComponent* Component = NewObject<UNoesisGuiVisualBrush>(Outer);
		Component->SetNoesisComponent(BaseComponent);
		return Component;
	}
	if (BaseComponentClass == Noesis::Gui::DashStyle::StaticGetClassType())
	{
		UNoesisGuiBaseComponent* Component = NewObject<UNoesisGuiDashStyle>(Outer);
		Component->SetNoesisComponent(BaseComponent);
		return Component;
	}
	if (BaseComponentClass == Noesis::Gui::Geometry::StaticGetClassType())
	{
		UNoesisGuiBaseComponent* Component = NewObject<UNoesisGuiGeometry>(Outer);
		Component->SetNoesisComponent(BaseComponent);
		return Component;
	}
	if (BaseComponentClass == Noesis::Gui::CombinedGeometry::StaticGetClassType())
	{
		UNoesisGuiBaseComponent* Component = NewObject<UNoesisGuiCombinedGeometry>(Outer);
		Component->SetNoesisComponent(BaseComponent);
		return Component;
	}
	if (BaseComponentClass == Noesis::Gui::EllipseGeometry::StaticGetClassType())
	{
		UNoesisGuiBaseComponent* Component = NewObject<UNoesisGuiEllipseGeometry>(Outer);
		Component->SetNoesisComponent(BaseComponent);
		return Component;
	}
	if (BaseComponentClass == Noesis::Gui::GeometryGroup::StaticGetClassType())
	{
		UNoesisGuiBaseComponent* Component = NewObject<UNoesisGuiGeometryGroup>(Outer);
		Component->SetNoesisComponent(BaseComponent);
		return Component;
	}
	if (BaseComponentClass == Noesis::Gui::LineGeometry::StaticGetClassType())
	{
		UNoesisGuiBaseComponent* Component = NewObject<UNoesisGuiLineGeometry>(Outer);
		Component->SetNoesisComponent(BaseComponent);
		return Component;
	}
	if (BaseComponentClass == Noesis::Gui::RectangleGeometry::StaticGetClassType())
	{
		UNoesisGuiBaseComponent* Component = NewObject<UNoesisGuiRectangleGeometry>(Outer);
		Component->SetNoesisComponent(BaseComponent);
		return Component;
	}
	if (BaseComponentClass == Noesis::Gui::StreamGeometry::StaticGetClassType())
	{
		UNoesisGuiBaseComponent* Component = NewObject<UNoesisGuiStreamGeometry>(Outer);
		Component->SetNoesisComponent(BaseComponent);
		return Component;
	}
	if (BaseComponentClass == Noesis::Gui::GradientStop::StaticGetClassType())
	{
		UNoesisGuiBaseComponent* Component = NewObject<UNoesisGuiGradientStop>(Outer);
		Component->SetNoesisComponent(BaseComponent);
		return Component;
	}
	if (BaseComponentClass == Noesis::Gui::ImageSource::StaticGetClassType())
	{
		UNoesisGuiBaseComponent* Component = NewObject<UNoesisGuiImageSource>(Outer);
		Component->SetNoesisComponent(BaseComponent);
		return Component;
	}
	if (BaseComponentClass == Noesis::Gui::TextureSource::StaticGetClassType())
	{
		UNoesisGuiBaseComponent* Component = NewObject<UNoesisGuiTextureSource>(Outer);
		Component->SetNoesisComponent(BaseComponent);
		return Component;
	}
	if (BaseComponentClass == Noesis::Gui::Pen::StaticGetClassType())
	{
		UNoesisGuiBaseComponent* Component = NewObject<UNoesisGuiPen>(Outer);
		Component->SetNoesisComponent(BaseComponent);
		return Component;
	}
	if (BaseComponentClass == Noesis::Gui::Projection::StaticGetClassType())
	{
		UNoesisGuiBaseComponent* Component = NewObject<UNoesisGuiProjection>(Outer);
		Component->SetNoesisComponent(BaseComponent);
		return Component;
	}
	if (BaseComponentClass == Noesis::Gui::Matrix3DProjection::StaticGetClassType())
	{
		UNoesisGuiBaseComponent* Component = NewObject<UNoesisGuiMatrix3DProjection>(Outer);
		Component->SetNoesisComponent(BaseComponent);
		return Component;
	}
	if (BaseComponentClass == Noesis::Gui::PlaneProjection::StaticGetClassType())
	{
		UNoesisGuiBaseComponent* Component = NewObject<UNoesisGuiPlaneProjection>(Outer);
		Component->SetNoesisComponent(BaseComponent);
		return Component;
	}
	if (BaseComponentClass == Noesis::Gui::Timeline::StaticGetClassType())
	{
		UNoesisGuiBaseComponent* Component = NewObject<UNoesisGuiTimeline>(Outer);
		Component->SetNoesisComponent(BaseComponent);
		return Component;
	}
	if (BaseComponentClass == Noesis::Gui::AnimationTimeline::StaticGetClassType())
	{
		UNoesisGuiBaseComponent* Component = NewObject<UNoesisGuiAnimationTimeline>(Outer);
		Component->SetNoesisComponent(BaseComponent);
		return Component;
	}
	if (BaseComponentClass == Noesis::Gui::Int16AnimationUsingKeyFrames::StaticGetClassType())
	{
		UNoesisGuiBaseComponent* Component = NewObject<UNoesisGuiInt16AnimationUsingKeyFrames>(Outer);
		Component->SetNoesisComponent(BaseComponent);
		return Component;
	}
	if (BaseComponentClass == Noesis::Gui::SizeAnimationUsingKeyFrames::StaticGetClassType())
	{
		UNoesisGuiBaseComponent* Component = NewObject<UNoesisGuiSizeAnimationUsingKeyFrames>(Outer);
		Component->SetNoesisComponent(BaseComponent);
		return Component;
	}
	if (BaseComponentClass == Noesis::Gui::PointAnimationUsingKeyFrames::StaticGetClassType())
	{
		UNoesisGuiBaseComponent* Component = NewObject<UNoesisGuiPointAnimationUsingKeyFrames>(Outer);
		Component->SetNoesisComponent(BaseComponent);
		return Component;
	}
	if (BaseComponentClass == Noesis::Gui::ColorAnimationUsingKeyFrames::StaticGetClassType())
	{
		UNoesisGuiBaseComponent* Component = NewObject<UNoesisGuiColorAnimationUsingKeyFrames>(Outer);
		Component->SetNoesisComponent(BaseComponent);
		return Component;
	}
	if (BaseComponentClass == Noesis::Gui::ThicknessAnimationUsingKeyFrames::StaticGetClassType())
	{
		UNoesisGuiBaseComponent* Component = NewObject<UNoesisGuiThicknessAnimationUsingKeyFrames>(Outer);
		Component->SetNoesisComponent(BaseComponent);
		return Component;
	}
	if (BaseComponentClass == Noesis::Gui::ObjectAnimationUsingKeyFrames::StaticGetClassType())
	{
		UNoesisGuiBaseComponent* Component = NewObject<UNoesisGuiObjectAnimationUsingKeyFrames>(Outer);
		Component->SetNoesisComponent(BaseComponent);
		return Component;
	}
	if (BaseComponentClass == Noesis::Gui::Int32AnimationUsingKeyFrames::StaticGetClassType())
	{
		UNoesisGuiBaseComponent* Component = NewObject<UNoesisGuiInt32AnimationUsingKeyFrames>(Outer);
		Component->SetNoesisComponent(BaseComponent);
		return Component;
	}
	if (BaseComponentClass == Noesis::Gui::StringAnimationUsingKeyFrames::StaticGetClassType())
	{
		UNoesisGuiBaseComponent* Component = NewObject<UNoesisGuiStringAnimationUsingKeyFrames>(Outer);
		Component->SetNoesisComponent(BaseComponent);
		return Component;
	}
	if (BaseComponentClass == Noesis::Gui::BooleanAnimationUsingKeyFrames::StaticGetClassType())
	{
		UNoesisGuiBaseComponent* Component = NewObject<UNoesisGuiBooleanAnimationUsingKeyFrames>(Outer);
		Component->SetNoesisComponent(BaseComponent);
		return Component;
	}
	if (BaseComponentClass == Noesis::Gui::RectAnimationUsingKeyFrames::StaticGetClassType())
	{
		UNoesisGuiBaseComponent* Component = NewObject<UNoesisGuiRectAnimationUsingKeyFrames>(Outer);
		Component->SetNoesisComponent(BaseComponent);
		return Component;
	}
	if (BaseComponentClass == Noesis::Gui::DoubleAnimationUsingKeyFrames::StaticGetClassType())
	{
		UNoesisGuiBaseComponent* Component = NewObject<UNoesisGuiDoubleAnimationUsingKeyFrames>(Outer);
		Component->SetNoesisComponent(BaseComponent);
		return Component;
	}
	if (BaseComponentClass == Noesis::Gui::BaseAnimation::StaticGetClassType())
	{
		UNoesisGuiBaseComponent* Component = NewObject<UNoesisGuiBaseAnimation>(Outer);
		Component->SetNoesisComponent(BaseComponent);
		return Component;
	}
	if (BaseComponentClass == Noesis::Gui::Int32Animation::StaticGetClassType())
	{
		UNoesisGuiBaseComponent* Component = NewObject<UNoesisGuiInt32Animation>(Outer);
		Component->SetNoesisComponent(BaseComponent);
		return Component;
	}
	if (BaseComponentClass == Noesis::Gui::PointAnimation::StaticGetClassType())
	{
		UNoesisGuiBaseComponent* Component = NewObject<UNoesisGuiPointAnimation>(Outer);
		Component->SetNoesisComponent(BaseComponent);
		return Component;
	}
	if (BaseComponentClass == Noesis::Gui::ColorAnimation::StaticGetClassType())
	{
		UNoesisGuiBaseComponent* Component = NewObject<UNoesisGuiColorAnimation>(Outer);
		Component->SetNoesisComponent(BaseComponent);
		return Component;
	}
	if (BaseComponentClass == Noesis::Gui::RectAnimation::StaticGetClassType())
	{
		UNoesisGuiBaseComponent* Component = NewObject<UNoesisGuiRectAnimation>(Outer);
		Component->SetNoesisComponent(BaseComponent);
		return Component;
	}
	if (BaseComponentClass == Noesis::Gui::ThicknessAnimation::StaticGetClassType())
	{
		UNoesisGuiBaseComponent* Component = NewObject<UNoesisGuiThicknessAnimation>(Outer);
		Component->SetNoesisComponent(BaseComponent);
		return Component;
	}
	if (BaseComponentClass == Noesis::Gui::SizeAnimation::StaticGetClassType())
	{
		UNoesisGuiBaseComponent* Component = NewObject<UNoesisGuiSizeAnimation>(Outer);
		Component->SetNoesisComponent(BaseComponent);
		return Component;
	}
	if (BaseComponentClass == Noesis::Gui::Int16Animation::StaticGetClassType())
	{
		UNoesisGuiBaseComponent* Component = NewObject<UNoesisGuiInt16Animation>(Outer);
		Component->SetNoesisComponent(BaseComponent);
		return Component;
	}
	if (BaseComponentClass == Noesis::Gui::DoubleAnimation::StaticGetClassType())
	{
		UNoesisGuiBaseComponent* Component = NewObject<UNoesisGuiDoubleAnimation>(Outer);
		Component->SetNoesisComponent(BaseComponent);
		return Component;
	}
	if (BaseComponentClass == Noesis::Gui::TimelineGroup::StaticGetClassType())
	{
		UNoesisGuiBaseComponent* Component = NewObject<UNoesisGuiTimelineGroup>(Outer);
		Component->SetNoesisComponent(BaseComponent);
		return Component;
	}
	if (BaseComponentClass == Noesis::Gui::ParallelTimeline::StaticGetClassType())
	{
		UNoesisGuiBaseComponent* Component = NewObject<UNoesisGuiParallelTimeline>(Outer);
		Component->SetNoesisComponent(BaseComponent);
		return Component;
	}
	if (BaseComponentClass == Noesis::Gui::Storyboard::StaticGetClassType())
	{
		UNoesisGuiBaseComponent* Component = NewObject<UNoesisGuiStoryboard>(Outer);
		Component->SetNoesisComponent(BaseComponent);
		return Component;
	}
	if (BaseComponentClass == Noesis::Gui::Transform::StaticGetClassType())
	{
		UNoesisGuiBaseComponent* Component = NewObject<UNoesisGuiTransform>(Outer);
		Component->SetNoesisComponent(BaseComponent);
		return Component;
	}
	if (BaseComponentClass == Noesis::Gui::CompositeTransform::StaticGetClassType())
	{
		UNoesisGuiBaseComponent* Component = NewObject<UNoesisGuiCompositeTransform>(Outer);
		Component->SetNoesisComponent(BaseComponent);
		return Component;
	}
	if (BaseComponentClass == Noesis::Gui::MatrixTransform::StaticGetClassType())
	{
		UNoesisGuiBaseComponent* Component = NewObject<UNoesisGuiMatrixTransform>(Outer);
		Component->SetNoesisComponent(BaseComponent);
		return Component;
	}
	if (BaseComponentClass == Noesis::Gui::RotateTransform::StaticGetClassType())
	{
		UNoesisGuiBaseComponent* Component = NewObject<UNoesisGuiRotateTransform>(Outer);
		Component->SetNoesisComponent(BaseComponent);
		return Component;
	}
	if (BaseComponentClass == Noesis::Gui::ScaleTransform::StaticGetClassType())
	{
		UNoesisGuiBaseComponent* Component = NewObject<UNoesisGuiScaleTransform>(Outer);
		Component->SetNoesisComponent(BaseComponent);
		return Component;
	}
	if (BaseComponentClass == Noesis::Gui::SkewTransform::StaticGetClassType())
	{
		UNoesisGuiBaseComponent* Component = NewObject<UNoesisGuiSkewTransform>(Outer);
		Component->SetNoesisComponent(BaseComponent);
		return Component;
	}
	if (BaseComponentClass == Noesis::Gui::TransformGroup::StaticGetClassType())
	{
		UNoesisGuiBaseComponent* Component = NewObject<UNoesisGuiTransformGroup>(Outer);
		Component->SetNoesisComponent(BaseComponent);
		return Component;
	}
	if (BaseComponentClass == Noesis::Gui::TranslateTransform::StaticGetClassType())
	{
		UNoesisGuiBaseComponent* Component = NewObject<UNoesisGuiTranslateTransform>(Outer);
		Component->SetNoesisComponent(BaseComponent);
		return Component;
	}
	if (BaseComponentClass == Noesis::Gui::EasingFunctionBase::StaticGetClassType())
	{
		UNoesisGuiBaseComponent* Component = NewObject<UNoesisGuiEasingFunctionBase>(Outer);
		Component->SetNoesisComponent(BaseComponent);
		return Component;
	}
	if (BaseComponentClass == Noesis::Gui::BackEase::StaticGetClassType())
	{
		UNoesisGuiBaseComponent* Component = NewObject<UNoesisGuiBackEase>(Outer);
		Component->SetNoesisComponent(BaseComponent);
		return Component;
	}
	if (BaseComponentClass == Noesis::Gui::BounceEase::StaticGetClassType())
	{
		UNoesisGuiBaseComponent* Component = NewObject<UNoesisGuiBounceEase>(Outer);
		Component->SetNoesisComponent(BaseComponent);
		return Component;
	}
	if (BaseComponentClass == Noesis::Gui::CircleEase::StaticGetClassType())
	{
		UNoesisGuiBaseComponent* Component = NewObject<UNoesisGuiCircleEase>(Outer);
		Component->SetNoesisComponent(BaseComponent);
		return Component;
	}
	if (BaseComponentClass == Noesis::Gui::CubicEase::StaticGetClassType())
	{
		UNoesisGuiBaseComponent* Component = NewObject<UNoesisGuiCubicEase>(Outer);
		Component->SetNoesisComponent(BaseComponent);
		return Component;
	}
	if (BaseComponentClass == Noesis::Gui::ElasticEase::StaticGetClassType())
	{
		UNoesisGuiBaseComponent* Component = NewObject<UNoesisGuiElasticEase>(Outer);
		Component->SetNoesisComponent(BaseComponent);
		return Component;
	}
	if (BaseComponentClass == Noesis::Gui::ExponentialEase::StaticGetClassType())
	{
		UNoesisGuiBaseComponent* Component = NewObject<UNoesisGuiExponentialEase>(Outer);
		Component->SetNoesisComponent(BaseComponent);
		return Component;
	}
	if (BaseComponentClass == Noesis::Gui::PowerEase::StaticGetClassType())
	{
		UNoesisGuiBaseComponent* Component = NewObject<UNoesisGuiPowerEase>(Outer);
		Component->SetNoesisComponent(BaseComponent);
		return Component;
	}
	if (BaseComponentClass == Noesis::Gui::QuadraticEase::StaticGetClassType())
	{
		UNoesisGuiBaseComponent* Component = NewObject<UNoesisGuiQuadraticEase>(Outer);
		Component->SetNoesisComponent(BaseComponent);
		return Component;
	}
	if (BaseComponentClass == Noesis::Gui::QuarticEase::StaticGetClassType())
	{
		UNoesisGuiBaseComponent* Component = NewObject<UNoesisGuiQuarticEase>(Outer);
		Component->SetNoesisComponent(BaseComponent);
		return Component;
	}
	if (BaseComponentClass == Noesis::Gui::QuinticEase::StaticGetClassType())
	{
		UNoesisGuiBaseComponent* Component = NewObject<UNoesisGuiQuinticEase>(Outer);
		Component->SetNoesisComponent(BaseComponent);
		return Component;
	}
	if (BaseComponentClass == Noesis::Gui::SineEase::StaticGetClassType())
	{
		UNoesisGuiBaseComponent* Component = NewObject<UNoesisGuiSineEase>(Outer);
		Component->SetNoesisComponent(BaseComponent);
		return Component;
	}
	if (BaseComponentClass == Noesis::Gui::InputBinding::StaticGetClassType())
	{
		UNoesisGuiBaseComponent* Component = NewObject<UNoesisGuiInputBinding>(Outer);
		Component->SetNoesisComponent(BaseComponent);
		return Component;
	}
	if (BaseComponentClass == Noesis::Gui::KeyBinding::StaticGetClassType())
	{
		UNoesisGuiBaseComponent* Component = NewObject<UNoesisGuiKeyBinding>(Outer);
		Component->SetNoesisComponent(BaseComponent);
		return Component;
	}
	if (BaseComponentClass == Noesis::Gui::Int16KeyFrame::StaticGetClassType())
	{
		UNoesisGuiBaseComponent* Component = NewObject<UNoesisGuiInt16KeyFrame>(Outer);
		Component->SetNoesisComponent(BaseComponent);
		return Component;
	}
	if (BaseComponentClass == Noesis::Gui::SizeKeyFrame::StaticGetClassType())
	{
		UNoesisGuiBaseComponent* Component = NewObject<UNoesisGuiSizeKeyFrame>(Outer);
		Component->SetNoesisComponent(BaseComponent);
		return Component;
	}
	if (BaseComponentClass == Noesis::Gui::PointKeyFrame::StaticGetClassType())
	{
		UNoesisGuiBaseComponent* Component = NewObject<UNoesisGuiPointKeyFrame>(Outer);
		Component->SetNoesisComponent(BaseComponent);
		return Component;
	}
	if (BaseComponentClass == Noesis::Gui::ColorKeyFrame::StaticGetClassType())
	{
		UNoesisGuiBaseComponent* Component = NewObject<UNoesisGuiColorKeyFrame>(Outer);
		Component->SetNoesisComponent(BaseComponent);
		return Component;
	}
	if (BaseComponentClass == Noesis::Gui::ThicknessKeyFrame::StaticGetClassType())
	{
		UNoesisGuiBaseComponent* Component = NewObject<UNoesisGuiThicknessKeyFrame>(Outer);
		Component->SetNoesisComponent(BaseComponent);
		return Component;
	}
	if (BaseComponentClass == Noesis::Gui::ObjectKeyFrame::StaticGetClassType())
	{
		UNoesisGuiBaseComponent* Component = NewObject<UNoesisGuiObjectKeyFrame>(Outer);
		Component->SetNoesisComponent(BaseComponent);
		return Component;
	}
	if (BaseComponentClass == Noesis::Gui::Int32KeyFrame::StaticGetClassType())
	{
		UNoesisGuiBaseComponent* Component = NewObject<UNoesisGuiInt32KeyFrame>(Outer);
		Component->SetNoesisComponent(BaseComponent);
		return Component;
	}
	if (BaseComponentClass == Noesis::Gui::StringKeyFrame::StaticGetClassType())
	{
		UNoesisGuiBaseComponent* Component = NewObject<UNoesisGuiStringKeyFrame>(Outer);
		Component->SetNoesisComponent(BaseComponent);
		return Component;
	}
	if (BaseComponentClass == Noesis::Gui::BooleanKeyFrame::StaticGetClassType())
	{
		UNoesisGuiBaseComponent* Component = NewObject<UNoesisGuiBooleanKeyFrame>(Outer);
		Component->SetNoesisComponent(BaseComponent);
		return Component;
	}
	if (BaseComponentClass == Noesis::Gui::RectKeyFrame::StaticGetClassType())
	{
		UNoesisGuiBaseComponent* Component = NewObject<UNoesisGuiRectKeyFrame>(Outer);
		Component->SetNoesisComponent(BaseComponent);
		return Component;
	}
	if (BaseComponentClass == Noesis::Gui::DoubleKeyFrame::StaticGetClassType())
	{
		UNoesisGuiBaseComponent* Component = NewObject<UNoesisGuiDoubleKeyFrame>(Outer);
		Component->SetNoesisComponent(BaseComponent);
		return Component;
	}
	if (BaseComponentClass == Noesis::Gui::DiscreteInt16KeyFrame::StaticGetClassType())
	{
		UNoesisGuiBaseComponent* Component = NewObject<UNoesisGuiDiscreteInt16KeyFrame>(Outer);
		Component->SetNoesisComponent(BaseComponent);
		return Component;
	}
	if (BaseComponentClass == Noesis::Gui::DiscreteSizeKeyFrame::StaticGetClassType())
	{
		UNoesisGuiBaseComponent* Component = NewObject<UNoesisGuiDiscreteSizeKeyFrame>(Outer);
		Component->SetNoesisComponent(BaseComponent);
		return Component;
	}
	if (BaseComponentClass == Noesis::Gui::DiscretePointKeyFrame::StaticGetClassType())
	{
		UNoesisGuiBaseComponent* Component = NewObject<UNoesisGuiDiscretePointKeyFrame>(Outer);
		Component->SetNoesisComponent(BaseComponent);
		return Component;
	}
	if (BaseComponentClass == Noesis::Gui::DiscreteColorKeyFrame::StaticGetClassType())
	{
		UNoesisGuiBaseComponent* Component = NewObject<UNoesisGuiDiscreteColorKeyFrame>(Outer);
		Component->SetNoesisComponent(BaseComponent);
		return Component;
	}
	if (BaseComponentClass == Noesis::Gui::DiscreteThicknessKeyFrame::StaticGetClassType())
	{
		UNoesisGuiBaseComponent* Component = NewObject<UNoesisGuiDiscreteThicknessKeyFrame>(Outer);
		Component->SetNoesisComponent(BaseComponent);
		return Component;
	}
	if (BaseComponentClass == Noesis::Gui::DiscreteObjectKeyFrame::StaticGetClassType())
	{
		UNoesisGuiBaseComponent* Component = NewObject<UNoesisGuiDiscreteObjectKeyFrame>(Outer);
		Component->SetNoesisComponent(BaseComponent);
		return Component;
	}
	if (BaseComponentClass == Noesis::Gui::DiscreteInt32KeyFrame::StaticGetClassType())
	{
		UNoesisGuiBaseComponent* Component = NewObject<UNoesisGuiDiscreteInt32KeyFrame>(Outer);
		Component->SetNoesisComponent(BaseComponent);
		return Component;
	}
	if (BaseComponentClass == Noesis::Gui::DiscreteStringKeyFrame::StaticGetClassType())
	{
		UNoesisGuiBaseComponent* Component = NewObject<UNoesisGuiDiscreteStringKeyFrame>(Outer);
		Component->SetNoesisComponent(BaseComponent);
		return Component;
	}
	if (BaseComponentClass == Noesis::Gui::DiscreteBooleanKeyFrame::StaticGetClassType())
	{
		UNoesisGuiBaseComponent* Component = NewObject<UNoesisGuiDiscreteBooleanKeyFrame>(Outer);
		Component->SetNoesisComponent(BaseComponent);
		return Component;
	}
	if (BaseComponentClass == Noesis::Gui::DiscreteRectKeyFrame::StaticGetClassType())
	{
		UNoesisGuiBaseComponent* Component = NewObject<UNoesisGuiDiscreteRectKeyFrame>(Outer);
		Component->SetNoesisComponent(BaseComponent);
		return Component;
	}
	if (BaseComponentClass == Noesis::Gui::DiscreteDoubleKeyFrame::StaticGetClassType())
	{
		UNoesisGuiBaseComponent* Component = NewObject<UNoesisGuiDiscreteDoubleKeyFrame>(Outer);
		Component->SetNoesisComponent(BaseComponent);
		return Component;
	}
	if (BaseComponentClass == Noesis::Gui::EasingInt32KeyFrame::StaticGetClassType())
	{
		UNoesisGuiBaseComponent* Component = NewObject<UNoesisGuiEasingInt32KeyFrame>(Outer);
		Component->SetNoesisComponent(BaseComponent);
		return Component;
	}
	if (BaseComponentClass == Noesis::Gui::EasingPointKeyFrame::StaticGetClassType())
	{
		UNoesisGuiBaseComponent* Component = NewObject<UNoesisGuiEasingPointKeyFrame>(Outer);
		Component->SetNoesisComponent(BaseComponent);
		return Component;
	}
	if (BaseComponentClass == Noesis::Gui::EasingColorKeyFrame::StaticGetClassType())
	{
		UNoesisGuiBaseComponent* Component = NewObject<UNoesisGuiEasingColorKeyFrame>(Outer);
		Component->SetNoesisComponent(BaseComponent);
		return Component;
	}
	if (BaseComponentClass == Noesis::Gui::EasingRectKeyFrame::StaticGetClassType())
	{
		UNoesisGuiBaseComponent* Component = NewObject<UNoesisGuiEasingRectKeyFrame>(Outer);
		Component->SetNoesisComponent(BaseComponent);
		return Component;
	}
	if (BaseComponentClass == Noesis::Gui::EasingThicknessKeyFrame::StaticGetClassType())
	{
		UNoesisGuiBaseComponent* Component = NewObject<UNoesisGuiEasingThicknessKeyFrame>(Outer);
		Component->SetNoesisComponent(BaseComponent);
		return Component;
	}
	if (BaseComponentClass == Noesis::Gui::EasingSizeKeyFrame::StaticGetClassType())
	{
		UNoesisGuiBaseComponent* Component = NewObject<UNoesisGuiEasingSizeKeyFrame>(Outer);
		Component->SetNoesisComponent(BaseComponent);
		return Component;
	}
	if (BaseComponentClass == Noesis::Gui::EasingInt16KeyFrame::StaticGetClassType())
	{
		UNoesisGuiBaseComponent* Component = NewObject<UNoesisGuiEasingInt16KeyFrame>(Outer);
		Component->SetNoesisComponent(BaseComponent);
		return Component;
	}
	if (BaseComponentClass == Noesis::Gui::EasingDoubleKeyFrame::StaticGetClassType())
	{
		UNoesisGuiBaseComponent* Component = NewObject<UNoesisGuiEasingDoubleKeyFrame>(Outer);
		Component->SetNoesisComponent(BaseComponent);
		return Component;
	}
	if (BaseComponentClass == Noesis::Gui::LinearInt32KeyFrame::StaticGetClassType())
	{
		UNoesisGuiBaseComponent* Component = NewObject<UNoesisGuiLinearInt32KeyFrame>(Outer);
		Component->SetNoesisComponent(BaseComponent);
		return Component;
	}
	if (BaseComponentClass == Noesis::Gui::LinearPointKeyFrame::StaticGetClassType())
	{
		UNoesisGuiBaseComponent* Component = NewObject<UNoesisGuiLinearPointKeyFrame>(Outer);
		Component->SetNoesisComponent(BaseComponent);
		return Component;
	}
	if (BaseComponentClass == Noesis::Gui::LinearColorKeyFrame::StaticGetClassType())
	{
		UNoesisGuiBaseComponent* Component = NewObject<UNoesisGuiLinearColorKeyFrame>(Outer);
		Component->SetNoesisComponent(BaseComponent);
		return Component;
	}
	if (BaseComponentClass == Noesis::Gui::LinearRectKeyFrame::StaticGetClassType())
	{
		UNoesisGuiBaseComponent* Component = NewObject<UNoesisGuiLinearRectKeyFrame>(Outer);
		Component->SetNoesisComponent(BaseComponent);
		return Component;
	}
	if (BaseComponentClass == Noesis::Gui::LinearThicknessKeyFrame::StaticGetClassType())
	{
		UNoesisGuiBaseComponent* Component = NewObject<UNoesisGuiLinearThicknessKeyFrame>(Outer);
		Component->SetNoesisComponent(BaseComponent);
		return Component;
	}
	if (BaseComponentClass == Noesis::Gui::LinearSizeKeyFrame::StaticGetClassType())
	{
		UNoesisGuiBaseComponent* Component = NewObject<UNoesisGuiLinearSizeKeyFrame>(Outer);
		Component->SetNoesisComponent(BaseComponent);
		return Component;
	}
	if (BaseComponentClass == Noesis::Gui::LinearInt16KeyFrame::StaticGetClassType())
	{
		UNoesisGuiBaseComponent* Component = NewObject<UNoesisGuiLinearInt16KeyFrame>(Outer);
		Component->SetNoesisComponent(BaseComponent);
		return Component;
	}
	if (BaseComponentClass == Noesis::Gui::LinearDoubleKeyFrame::StaticGetClassType())
	{
		UNoesisGuiBaseComponent* Component = NewObject<UNoesisGuiLinearDoubleKeyFrame>(Outer);
		Component->SetNoesisComponent(BaseComponent);
		return Component;
	}
	if (BaseComponentClass == Noesis::Gui::SplineInt32KeyFrame::StaticGetClassType())
	{
		UNoesisGuiBaseComponent* Component = NewObject<UNoesisGuiSplineInt32KeyFrame>(Outer);
		Component->SetNoesisComponent(BaseComponent);
		return Component;
	}
	if (BaseComponentClass == Noesis::Gui::SplinePointKeyFrame::StaticGetClassType())
	{
		UNoesisGuiBaseComponent* Component = NewObject<UNoesisGuiSplinePointKeyFrame>(Outer);
		Component->SetNoesisComponent(BaseComponent);
		return Component;
	}
	if (BaseComponentClass == Noesis::Gui::SplineColorKeyFrame::StaticGetClassType())
	{
		UNoesisGuiBaseComponent* Component = NewObject<UNoesisGuiSplineColorKeyFrame>(Outer);
		Component->SetNoesisComponent(BaseComponent);
		return Component;
	}
	if (BaseComponentClass == Noesis::Gui::SplineRectKeyFrame::StaticGetClassType())
	{
		UNoesisGuiBaseComponent* Component = NewObject<UNoesisGuiSplineRectKeyFrame>(Outer);
		Component->SetNoesisComponent(BaseComponent);
		return Component;
	}
	if (BaseComponentClass == Noesis::Gui::SplineThicknessKeyFrame::StaticGetClassType())
	{
		UNoesisGuiBaseComponent* Component = NewObject<UNoesisGuiSplineThicknessKeyFrame>(Outer);
		Component->SetNoesisComponent(BaseComponent);
		return Component;
	}
	if (BaseComponentClass == Noesis::Gui::SplineSizeKeyFrame::StaticGetClassType())
	{
		UNoesisGuiBaseComponent* Component = NewObject<UNoesisGuiSplineSizeKeyFrame>(Outer);
		Component->SetNoesisComponent(BaseComponent);
		return Component;
	}
	if (BaseComponentClass == Noesis::Gui::SplineInt16KeyFrame::StaticGetClassType())
	{
		UNoesisGuiBaseComponent* Component = NewObject<UNoesisGuiSplineInt16KeyFrame>(Outer);
		Component->SetNoesisComponent(BaseComponent);
		return Component;
	}
	if (BaseComponentClass == Noesis::Gui::SplineDoubleKeyFrame::StaticGetClassType())
	{
		UNoesisGuiBaseComponent* Component = NewObject<UNoesisGuiSplineDoubleKeyFrame>(Outer);
		Component->SetNoesisComponent(BaseComponent);
		return Component;
	}
	if (BaseComponentClass == Noesis::Gui::KeySpline::StaticGetClassType())
	{
		UNoesisGuiBaseComponent* Component = NewObject<UNoesisGuiKeySpline>(Outer);
		Component->SetNoesisComponent(BaseComponent);
		return Component;
	}
	if (BaseComponentClass == Noesis::Gui::GridViewColumn::StaticGetClassType())
	{
		UNoesisGuiBaseComponent* Component = NewObject<UNoesisGuiGridViewColumn>(Outer);
		Component->SetNoesisComponent(BaseComponent);
		return Component;
	}
	if (BaseComponentClass == Noesis::Gui::TextElement::StaticGetClassType())
	{
		UNoesisGuiBaseComponent* Component = NewObject<UNoesisGuiTextElement>(Outer);
		Component->SetNoesisComponent(BaseComponent);
		return Component;
	}
	if (BaseComponentClass == Noesis::Gui::Inline::StaticGetClassType())
	{
		UNoesisGuiBaseComponent* Component = NewObject<UNoesisGuiInline>(Outer);
		Component->SetNoesisComponent(BaseComponent);
		return Component;
	}
	if (BaseComponentClass == Noesis::Gui::LineBreak::StaticGetClassType())
	{
		UNoesisGuiBaseComponent* Component = NewObject<UNoesisGuiLineBreak>(Outer);
		Component->SetNoesisComponent(BaseComponent);
		return Component;
	}
	if (BaseComponentClass == Noesis::Gui::Run::StaticGetClassType())
	{
		UNoesisGuiBaseComponent* Component = NewObject<UNoesisGuiRun>(Outer);
		Component->SetNoesisComponent(BaseComponent);
		return Component;
	}
	if (BaseComponentClass == Noesis::Gui::TriggerAction::StaticGetClassType())
	{
		UNoesisGuiBaseComponent* Component = NewObject<UNoesisGuiTriggerAction>(Outer);
		Component->SetNoesisComponent(BaseComponent);
		return Component;
	}
	if (BaseComponentClass == Noesis::Gui::BeginStoryboard::StaticGetClassType())
	{
		UNoesisGuiBaseComponent* Component = NewObject<UNoesisGuiBeginStoryboard>(Outer);
		Component->SetNoesisComponent(BaseComponent);
		return Component;
	}
	if (BaseComponentClass == Noesis::Gui::ControllableStoryboardAction::StaticGetClassType())
	{
		UNoesisGuiBaseComponent* Component = NewObject<UNoesisGuiControllableStoryboardAction>(Outer);
		Component->SetNoesisComponent(BaseComponent);
		return Component;
	}
	if (BaseComponentClass == Noesis::Gui::PauseStoryboard::StaticGetClassType())
	{
		UNoesisGuiBaseComponent* Component = NewObject<UNoesisGuiPauseStoryboard>(Outer);
		Component->SetNoesisComponent(BaseComponent);
		return Component;
	}
	if (BaseComponentClass == Noesis::Gui::ResumeStoryboard::StaticGetClassType())
	{
		UNoesisGuiBaseComponent* Component = NewObject<UNoesisGuiResumeStoryboard>(Outer);
		Component->SetNoesisComponent(BaseComponent);
		return Component;
	}
	if (BaseComponentClass == Noesis::Gui::StopStoryboard::StaticGetClassType())
	{
		UNoesisGuiBaseComponent* Component = NewObject<UNoesisGuiStopStoryboard>(Outer);
		Component->SetNoesisComponent(BaseComponent);
		return Component;
	}
	if (BaseComponentClass == Noesis::Gui::Visual::StaticGetClassType())
	{
		UNoesisGuiBaseComponent* Component = NewObject<UNoesisGuiVisual>(Outer);
		Component->SetNoesisComponent(BaseComponent);
		return Component;
	}
	if (BaseComponentClass == Noesis::Gui::UIElement::StaticGetClassType())
	{
		UNoesisGuiBaseComponent* Component = NewObject<UNoesisGuiUIElement>(Outer);
		Component->SetNoesisComponent(BaseComponent);
		return Component;
	}
	if (BaseComponentClass == Noesis::Gui::FrameworkElement::StaticGetClassType())
	{
		UNoesisGuiBaseComponent* Component = NewObject<UNoesisGuiFrameworkElement>(Outer);
		Component->SetNoesisComponent(BaseComponent);
		return Component;
	}
	if (BaseComponentClass == Noesis::Gui::BaseDefinition::StaticGetClassType())
	{
		UNoesisGuiBaseComponent* Component = NewObject<UNoesisGuiBaseDefinition>(Outer);
		Component->SetNoesisComponent(BaseComponent);
		return Component;
	}
	if (BaseComponentClass == Noesis::Gui::ColumnDefinition::StaticGetClassType())
	{
		UNoesisGuiBaseComponent* Component = NewObject<UNoesisGuiColumnDefinition>(Outer);
		Component->SetNoesisComponent(BaseComponent);
		return Component;
	}
	if (BaseComponentClass == Noesis::Gui::RowDefinition::StaticGetClassType())
	{
		UNoesisGuiBaseComponent* Component = NewObject<UNoesisGuiRowDefinition>(Outer);
		Component->SetNoesisComponent(BaseComponent);
		return Component;
	}
	if (BaseComponentClass == Noesis::Gui::BaseGridViewRowPresenter::StaticGetClassType())
	{
		UNoesisGuiBaseComponent* Component = NewObject<UNoesisGuiBaseGridViewRowPresenter>(Outer);
		Component->SetNoesisComponent(BaseComponent);
		return Component;
	}
	if (BaseComponentClass == Noesis::Gui::GridViewHeaderRowPresenter::StaticGetClassType())
	{
		UNoesisGuiBaseComponent* Component = NewObject<UNoesisGuiGridViewHeaderRowPresenter>(Outer);
		Component->SetNoesisComponent(BaseComponent);
		return Component;
	}
	if (BaseComponentClass == Noesis::Gui::GridViewRowPresenter::StaticGetClassType())
	{
		UNoesisGuiBaseComponent* Component = NewObject<UNoesisGuiGridViewRowPresenter>(Outer);
		Component->SetNoesisComponent(BaseComponent);
		return Component;
	}
	if (BaseComponentClass == Noesis::Gui::ContentPresenter::StaticGetClassType())
	{
		UNoesisGuiBaseComponent* Component = NewObject<UNoesisGuiContentPresenter>(Outer);
		Component->SetNoesisComponent(BaseComponent);
		return Component;
	}
	if (BaseComponentClass == Noesis::Gui::ScrollContentPresenter::StaticGetClassType())
	{
		UNoesisGuiBaseComponent* Component = NewObject<UNoesisGuiScrollContentPresenter>(Outer);
		Component->SetNoesisComponent(BaseComponent);
		return Component;
	}
	if (BaseComponentClass == Noesis::Gui::Control::StaticGetClassType())
	{
		UNoesisGuiBaseComponent* Component = NewObject<UNoesisGuiControl>(Outer);
		Component->SetNoesisComponent(BaseComponent);
		return Component;
	}
	if (BaseComponentClass == Noesis::Gui::BaseTextBox::StaticGetClassType())
	{
		UNoesisGuiBaseComponent* Component = NewObject<UNoesisGuiBaseTextBox>(Outer);
		Component->SetNoesisComponent(BaseComponent);
		return Component;
	}
	if (BaseComponentClass == Noesis::Gui::TextBox::StaticGetClassType())
	{
		UNoesisGuiBaseComponent* Component = NewObject<UNoesisGuiTextBox>(Outer);
		Component->SetNoesisComponent(BaseComponent);
		return Component;
	}
	if (BaseComponentClass == Noesis::Gui::ContentControl::StaticGetClassType())
	{
		UNoesisGuiBaseComponent* Component = NewObject<UNoesisGuiContentControl>(Outer);
		Component->SetNoesisComponent(BaseComponent);
		return Component;
	}
	if (BaseComponentClass == Noesis::Gui::BaseButton::StaticGetClassType())
	{
		UNoesisGuiBaseComponent* Component = NewObject<UNoesisGuiBaseButton>(Outer);
		Component->SetNoesisComponent(BaseComponent);
		return Component;
	}
	if (BaseComponentClass == Noesis::Gui::Button::StaticGetClassType())
	{
		UNoesisGuiBaseComponent* Component = NewObject<UNoesisGuiButton>(Outer);
		Component->SetNoesisComponent(BaseComponent);
		return Component;
	}
	if (BaseComponentClass == Noesis::Gui::GridViewColumnHeader::StaticGetClassType())
	{
		UNoesisGuiBaseComponent* Component = NewObject<UNoesisGuiGridViewColumnHeader>(Outer);
		Component->SetNoesisComponent(BaseComponent);
		return Component;
	}
	if (BaseComponentClass == Noesis::Gui::RepeatButton::StaticGetClassType())
	{
		UNoesisGuiBaseComponent* Component = NewObject<UNoesisGuiRepeatButton>(Outer);
		Component->SetNoesisComponent(BaseComponent);
		return Component;
	}
	if (BaseComponentClass == Noesis::Gui::ToggleButton::StaticGetClassType())
	{
		UNoesisGuiBaseComponent* Component = NewObject<UNoesisGuiToggleButton>(Outer);
		Component->SetNoesisComponent(BaseComponent);
		return Component;
	}
	if (BaseComponentClass == Noesis::Gui::CheckBox::StaticGetClassType())
	{
		UNoesisGuiBaseComponent* Component = NewObject<UNoesisGuiCheckBox>(Outer);
		Component->SetNoesisComponent(BaseComponent);
		return Component;
	}
	if (BaseComponentClass == Noesis::Gui::RadioButton::StaticGetClassType())
	{
		UNoesisGuiBaseComponent* Component = NewObject<UNoesisGuiRadioButton>(Outer);
		Component->SetNoesisComponent(BaseComponent);
		return Component;
	}
	if (BaseComponentClass == Noesis::Gui::HeaderedContentControl::StaticGetClassType())
	{
		UNoesisGuiBaseComponent* Component = NewObject<UNoesisGuiHeaderedContentControl>(Outer);
		Component->SetNoesisComponent(BaseComponent);
		return Component;
	}
	if (BaseComponentClass == Noesis::Gui::Expander::StaticGetClassType())
	{
		UNoesisGuiBaseComponent* Component = NewObject<UNoesisGuiExpander>(Outer);
		Component->SetNoesisComponent(BaseComponent);
		return Component;
	}
	if (BaseComponentClass == Noesis::Gui::GroupBox::StaticGetClassType())
	{
		UNoesisGuiBaseComponent* Component = NewObject<UNoesisGuiGroupBox>(Outer);
		Component->SetNoesisComponent(BaseComponent);
		return Component;
	}
	if (BaseComponentClass == Noesis::Gui::TabItem::StaticGetClassType())
	{
		UNoesisGuiBaseComponent* Component = NewObject<UNoesisGuiTabItem>(Outer);
		Component->SetNoesisComponent(BaseComponent);
		return Component;
	}
	if (BaseComponentClass == Noesis::Gui::Label::StaticGetClassType())
	{
		UNoesisGuiBaseComponent* Component = NewObject<UNoesisGuiLabel>(Outer);
		Component->SetNoesisComponent(BaseComponent);
		return Component;
	}
	if (BaseComponentClass == Noesis::Gui::ListBoxItem::StaticGetClassType())
	{
		UNoesisGuiBaseComponent* Component = NewObject<UNoesisGuiListBoxItem>(Outer);
		Component->SetNoesisComponent(BaseComponent);
		return Component;
	}
	if (BaseComponentClass == Noesis::Gui::ComboBoxItem::StaticGetClassType())
	{
		UNoesisGuiBaseComponent* Component = NewObject<UNoesisGuiComboBoxItem>(Outer);
		Component->SetNoesisComponent(BaseComponent);
		return Component;
	}
	if (BaseComponentClass == Noesis::Gui::ListViewItem::StaticGetClassType())
	{
		UNoesisGuiBaseComponent* Component = NewObject<UNoesisGuiListViewItem>(Outer);
		Component->SetNoesisComponent(BaseComponent);
		return Component;
	}
	if (BaseComponentClass == Noesis::Gui::ScrollViewer::StaticGetClassType())
	{
		UNoesisGuiBaseComponent* Component = NewObject<UNoesisGuiScrollViewer>(Outer);
		Component->SetNoesisComponent(BaseComponent);
		return Component;
	}
	if (BaseComponentClass == Noesis::Gui::StatusBarItem::StaticGetClassType())
	{
		UNoesisGuiBaseComponent* Component = NewObject<UNoesisGuiStatusBarItem>(Outer);
		Component->SetNoesisComponent(BaseComponent);
		return Component;
	}
	if (BaseComponentClass == Noesis::Gui::ToolTip::StaticGetClassType())
	{
		UNoesisGuiBaseComponent* Component = NewObject<UNoesisGuiToolTip>(Outer);
		Component->SetNoesisComponent(BaseComponent);
		return Component;
	}
	if (BaseComponentClass == Noesis::Gui::UserControl::StaticGetClassType())
	{
		UNoesisGuiBaseComponent* Component = NewObject<UNoesisGuiUserControl>(Outer);
		Component->SetNoesisComponent(BaseComponent);
		return Component;
	}
	if (BaseComponentClass == Noesis::Gui::Page::StaticGetClassType())
	{
		UNoesisGuiBaseComponent* Component = NewObject<UNoesisGuiPage>(Outer);
		Component->SetNoesisComponent(BaseComponent);
		return Component;
	}
	if (BaseComponentClass == Noesis::Gui::ItemsControl::StaticGetClassType())
	{
		UNoesisGuiBaseComponent* Component = NewObject<UNoesisGuiItemsControl>(Outer);
		Component->SetNoesisComponent(BaseComponent);
		return Component;
	}
	if (BaseComponentClass == Noesis::Gui::BaseMenu::StaticGetClassType())
	{
		UNoesisGuiBaseComponent* Component = NewObject<UNoesisGuiBaseMenu>(Outer);
		Component->SetNoesisComponent(BaseComponent);
		return Component;
	}
	if (BaseComponentClass == Noesis::Gui::ContextMenu::StaticGetClassType())
	{
		UNoesisGuiBaseComponent* Component = NewObject<UNoesisGuiContextMenu>(Outer);
		Component->SetNoesisComponent(BaseComponent);
		return Component;
	}
	if (BaseComponentClass == Noesis::Gui::Menu::StaticGetClassType())
	{
		UNoesisGuiBaseComponent* Component = NewObject<UNoesisGuiMenu>(Outer);
		Component->SetNoesisComponent(BaseComponent);
		return Component;
	}
	if (BaseComponentClass == Noesis::Gui::HeaderedItemsControl::StaticGetClassType())
	{
		UNoesisGuiBaseComponent* Component = NewObject<UNoesisGuiHeaderedItemsControl>(Outer);
		Component->SetNoesisComponent(BaseComponent);
		return Component;
	}
	if (BaseComponentClass == Noesis::Gui::MenuItem::StaticGetClassType())
	{
		UNoesisGuiBaseComponent* Component = NewObject<UNoesisGuiMenuItem>(Outer);
		Component->SetNoesisComponent(BaseComponent);
		return Component;
	}
	if (BaseComponentClass == Noesis::Gui::ToolBar::StaticGetClassType())
	{
		UNoesisGuiBaseComponent* Component = NewObject<UNoesisGuiToolBar>(Outer);
		Component->SetNoesisComponent(BaseComponent);
		return Component;
	}
	if (BaseComponentClass == Noesis::Gui::TreeViewItem::StaticGetClassType())
	{
		UNoesisGuiBaseComponent* Component = NewObject<UNoesisGuiTreeViewItem>(Outer);
		Component->SetNoesisComponent(BaseComponent);
		return Component;
	}
	if (BaseComponentClass == Noesis::Gui::Selector::StaticGetClassType())
	{
		UNoesisGuiBaseComponent* Component = NewObject<UNoesisGuiSelector>(Outer);
		Component->SetNoesisComponent(BaseComponent);
		return Component;
	}
	if (BaseComponentClass == Noesis::Gui::ComboBox::StaticGetClassType())
	{
		UNoesisGuiBaseComponent* Component = NewObject<UNoesisGuiComboBox>(Outer);
		Component->SetNoesisComponent(BaseComponent);
		return Component;
	}
	if (BaseComponentClass == Noesis::Gui::ListBox::StaticGetClassType())
	{
		UNoesisGuiBaseComponent* Component = NewObject<UNoesisGuiListBox>(Outer);
		Component->SetNoesisComponent(BaseComponent);
		return Component;
	}
	if (BaseComponentClass == Noesis::Gui::ListView::StaticGetClassType())
	{
		UNoesisGuiBaseComponent* Component = NewObject<UNoesisGuiListView>(Outer);
		Component->SetNoesisComponent(BaseComponent);
		return Component;
	}
	if (BaseComponentClass == Noesis::Gui::TabControl::StaticGetClassType())
	{
		UNoesisGuiBaseComponent* Component = NewObject<UNoesisGuiTabControl>(Outer);
		Component->SetNoesisComponent(BaseComponent);
		return Component;
	}
	if (BaseComponentClass == Noesis::Gui::StatusBar::StaticGetClassType())
	{
		UNoesisGuiBaseComponent* Component = NewObject<UNoesisGuiStatusBar>(Outer);
		Component->SetNoesisComponent(BaseComponent);
		return Component;
	}
	if (BaseComponentClass == Noesis::Gui::TreeView::StaticGetClassType())
	{
		UNoesisGuiBaseComponent* Component = NewObject<UNoesisGuiTreeView>(Outer);
		Component->SetNoesisComponent(BaseComponent);
		return Component;
	}
	if (BaseComponentClass == Noesis::Gui::PasswordBox::StaticGetClassType())
	{
		UNoesisGuiBaseComponent* Component = NewObject<UNoesisGuiPasswordBox>(Outer);
		Component->SetNoesisComponent(BaseComponent);
		return Component;
	}
	if (BaseComponentClass == Noesis::Gui::RangeBase::StaticGetClassType())
	{
		UNoesisGuiBaseComponent* Component = NewObject<UNoesisGuiRangeBase>(Outer);
		Component->SetNoesisComponent(BaseComponent);
		return Component;
	}
	if (BaseComponentClass == Noesis::Gui::ProgressBar::StaticGetClassType())
	{
		UNoesisGuiBaseComponent* Component = NewObject<UNoesisGuiProgressBar>(Outer);
		Component->SetNoesisComponent(BaseComponent);
		return Component;
	}
	if (BaseComponentClass == Noesis::Gui::ScrollBar::StaticGetClassType())
	{
		UNoesisGuiBaseComponent* Component = NewObject<UNoesisGuiScrollBar>(Outer);
		Component->SetNoesisComponent(BaseComponent);
		return Component;
	}
	if (BaseComponentClass == Noesis::Gui::Slider::StaticGetClassType())
	{
		UNoesisGuiBaseComponent* Component = NewObject<UNoesisGuiSlider>(Outer);
		Component->SetNoesisComponent(BaseComponent);
		return Component;
	}
	if (BaseComponentClass == Noesis::Gui::Separator::StaticGetClassType())
	{
		UNoesisGuiBaseComponent* Component = NewObject<UNoesisGuiSeparator>(Outer);
		Component->SetNoesisComponent(BaseComponent);
		return Component;
	}
	if (BaseComponentClass == Noesis::Gui::Thumb::StaticGetClassType())
	{
		UNoesisGuiBaseComponent* Component = NewObject<UNoesisGuiThumb>(Outer);
		Component->SetNoesisComponent(BaseComponent);
		return Component;
	}
	if (BaseComponentClass == Noesis::Gui::Decorator::StaticGetClassType())
	{
		UNoesisGuiBaseComponent* Component = NewObject<UNoesisGuiDecorator>(Outer);
		Component->SetNoesisComponent(BaseComponent);
		return Component;
	}
	if (BaseComponentClass == Noesis::Gui::AdornerDecorator::StaticGetClassType())
	{
		UNoesisGuiBaseComponent* Component = NewObject<UNoesisGuiAdornerDecorator>(Outer);
		Component->SetNoesisComponent(BaseComponent);
		return Component;
	}
	if (BaseComponentClass == Noesis::Gui::Border::StaticGetClassType())
	{
		UNoesisGuiBaseComponent* Component = NewObject<UNoesisGuiBorder>(Outer);
		Component->SetNoesisComponent(BaseComponent);
		return Component;
	}
	if (BaseComponentClass == Noesis::Gui::BulletDecorator::StaticGetClassType())
	{
		UNoesisGuiBaseComponent* Component = NewObject<UNoesisGuiBulletDecorator>(Outer);
		Component->SetNoesisComponent(BaseComponent);
		return Component;
	}
	if (BaseComponentClass == Noesis::Gui::Image::StaticGetClassType())
	{
		UNoesisGuiBaseComponent* Component = NewObject<UNoesisGuiImage>(Outer);
		Component->SetNoesisComponent(BaseComponent);
		return Component;
	}
	if (BaseComponentClass == Noesis::Gui::ItemsPresenter::StaticGetClassType())
	{
		UNoesisGuiBaseComponent* Component = NewObject<UNoesisGuiItemsPresenter>(Outer);
		Component->SetNoesisComponent(BaseComponent);
		return Component;
	}
	if (BaseComponentClass == Noesis::Gui::Panel::StaticGetClassType())
	{
		UNoesisGuiBaseComponent* Component = NewObject<UNoesisGuiPanel>(Outer);
		Component->SetNoesisComponent(BaseComponent);
		return Component;
	}
	if (BaseComponentClass == Noesis::Gui::Canvas::StaticGetClassType())
	{
		UNoesisGuiBaseComponent* Component = NewObject<UNoesisGuiCanvas>(Outer);
		Component->SetNoesisComponent(BaseComponent);
		return Component;
	}
	if (BaseComponentClass == Noesis::Gui::DockPanel::StaticGetClassType())
	{
		UNoesisGuiBaseComponent* Component = NewObject<UNoesisGuiDockPanel>(Outer);
		Component->SetNoesisComponent(BaseComponent);
		return Component;
	}
	if (BaseComponentClass == Noesis::Gui::Grid::StaticGetClassType())
	{
		UNoesisGuiBaseComponent* Component = NewObject<UNoesisGuiGrid>(Outer);
		Component->SetNoesisComponent(BaseComponent);
		return Component;
	}
	if (BaseComponentClass == Noesis::Gui::StackPanel::StaticGetClassType())
	{
		UNoesisGuiBaseComponent* Component = NewObject<UNoesisGuiStackPanel>(Outer);
		Component->SetNoesisComponent(BaseComponent);
		return Component;
	}
	if (BaseComponentClass == Noesis::Gui::ToolBarPanel::StaticGetClassType())
	{
		UNoesisGuiBaseComponent* Component = NewObject<UNoesisGuiToolBarPanel>(Outer);
		Component->SetNoesisComponent(BaseComponent);
		return Component;
	}
	if (BaseComponentClass == Noesis::Gui::TabPanel::StaticGetClassType())
	{
		UNoesisGuiBaseComponent* Component = NewObject<UNoesisGuiTabPanel>(Outer);
		Component->SetNoesisComponent(BaseComponent);
		return Component;
	}
	if (BaseComponentClass == Noesis::Gui::ToolBarOverflowPanel::StaticGetClassType())
	{
		UNoesisGuiBaseComponent* Component = NewObject<UNoesisGuiToolBarOverflowPanel>(Outer);
		Component->SetNoesisComponent(BaseComponent);
		return Component;
	}
	if (BaseComponentClass == Noesis::Gui::UniformGrid::StaticGetClassType())
	{
		UNoesisGuiBaseComponent* Component = NewObject<UNoesisGuiUniformGrid>(Outer);
		Component->SetNoesisComponent(BaseComponent);
		return Component;
	}
	if (BaseComponentClass == Noesis::Gui::VirtualizingPanel::StaticGetClassType())
	{
		UNoesisGuiBaseComponent* Component = NewObject<UNoesisGuiVirtualizingPanel>(Outer);
		Component->SetNoesisComponent(BaseComponent);
		return Component;
	}
	if (BaseComponentClass == Noesis::Gui::VirtualizingStackPanel::StaticGetClassType())
	{
		UNoesisGuiBaseComponent* Component = NewObject<UNoesisGuiVirtualizingStackPanel>(Outer);
		Component->SetNoesisComponent(BaseComponent);
		return Component;
	}
	if (BaseComponentClass == Noesis::Gui::WrapPanel::StaticGetClassType())
	{
		UNoesisGuiBaseComponent* Component = NewObject<UNoesisGuiWrapPanel>(Outer);
		Component->SetNoesisComponent(BaseComponent);
		return Component;
	}
	if (BaseComponentClass == Noesis::Gui::Popup::StaticGetClassType())
	{
		UNoesisGuiBaseComponent* Component = NewObject<UNoesisGuiPopup>(Outer);
		Component->SetNoesisComponent(BaseComponent);
		return Component;
	}
	if (BaseComponentClass == Noesis::Gui::Shape::StaticGetClassType())
	{
		UNoesisGuiBaseComponent* Component = NewObject<UNoesisGuiShape>(Outer);
		Component->SetNoesisComponent(BaseComponent);
		return Component;
	}
	if (BaseComponentClass == Noesis::Gui::Ellipse::StaticGetClassType())
	{
		UNoesisGuiBaseComponent* Component = NewObject<UNoesisGuiEllipse>(Outer);
		Component->SetNoesisComponent(BaseComponent);
		return Component;
	}
	if (BaseComponentClass == Noesis::Gui::Line::StaticGetClassType())
	{
		UNoesisGuiBaseComponent* Component = NewObject<UNoesisGuiLine>(Outer);
		Component->SetNoesisComponent(BaseComponent);
		return Component;
	}
	if (BaseComponentClass == Noesis::Gui::Path::StaticGetClassType())
	{
		UNoesisGuiBaseComponent* Component = NewObject<UNoesisGuiPath>(Outer);
		Component->SetNoesisComponent(BaseComponent);
		return Component;
	}
	if (BaseComponentClass == Noesis::Gui::Rectangle::StaticGetClassType())
	{
		UNoesisGuiBaseComponent* Component = NewObject<UNoesisGuiRectangle>(Outer);
		Component->SetNoesisComponent(BaseComponent);
		return Component;
	}
	if (BaseComponentClass == Noesis::Gui::TextBlock::StaticGetClassType())
	{
		UNoesisGuiBaseComponent* Component = NewObject<UNoesisGuiTextBlock>(Outer);
		Component->SetNoesisComponent(BaseComponent);
		return Component;
	}
	if (BaseComponentClass == Noesis::Gui::TickBar::StaticGetClassType())
	{
		UNoesisGuiBaseComponent* Component = NewObject<UNoesisGuiTickBar>(Outer);
		Component->SetNoesisComponent(BaseComponent);
		return Component;
	}
	if (BaseComponentClass == Noesis::Gui::ToolBarTray::StaticGetClassType())
	{
		UNoesisGuiBaseComponent* Component = NewObject<UNoesisGuiToolBarTray>(Outer);
		Component->SetNoesisComponent(BaseComponent);
		return Component;
	}
	if (BaseComponentClass == Noesis::Gui::Track::StaticGetClassType())
	{
		UNoesisGuiBaseComponent* Component = NewObject<UNoesisGuiTrack>(Outer);
		Component->SetNoesisComponent(BaseComponent);
		return Component;
	}
	if (BaseComponentClass == Noesis::Gui::Viewbox::StaticGetClassType())
	{
		UNoesisGuiBaseComponent* Component = NewObject<UNoesisGuiViewbox>(Outer);
		Component->SetNoesisComponent(BaseComponent);
		return Component;
	}
	if (BaseComponentClass == Noesis::Gui::VisualState::StaticGetClassType())
	{
		UNoesisGuiBaseComponent* Component = NewObject<UNoesisGuiVisualState>(Outer);
		Component->SetNoesisComponent(BaseComponent);
		return Component;
	}
	if (BaseComponentClass == Noesis::Gui::VisualStateGroup::StaticGetClassType())
	{
		UNoesisGuiBaseComponent* Component = NewObject<UNoesisGuiVisualStateGroup>(Outer);
		Component->SetNoesisComponent(BaseComponent);
		return Component;
	}
	if (BaseComponentClass == Noesis::Gui::VisualTransition::StaticGetClassType())
	{
		UNoesisGuiBaseComponent* Component = NewObject<UNoesisGuiVisualTransition>(Outer);
		Component->SetNoesisComponent(BaseComponent);
		return Component;
	}
	if (BaseComponentClass == Noesis::Gui::DependencyProperty::StaticGetClassType())
	{
		UNoesisGuiBaseComponent* Component = NewObject<UNoesisGuiDependencyProperty>(Outer);
		Component->SetNoesisComponent(BaseComponent);
		return Component;
	}
	if (BaseComponentClass == Noesis::Gui::FrameworkTemplate::StaticGetClassType())
	{
		UNoesisGuiBaseComponent* Component = NewObject<UNoesisGuiFrameworkTemplate>(Outer);
		Component->SetNoesisComponent(BaseComponent);
		return Component;
	}
	if (BaseComponentClass == Noesis::Gui::ControlTemplate::StaticGetClassType())
	{
		UNoesisGuiBaseComponent* Component = NewObject<UNoesisGuiControlTemplate>(Outer);
		Component->SetNoesisComponent(BaseComponent);
		return Component;
	}
	if (BaseComponentClass == Noesis::Gui::DataTemplate::StaticGetClassType())
	{
		UNoesisGuiBaseComponent* Component = NewObject<UNoesisGuiDataTemplate>(Outer);
		Component->SetNoesisComponent(BaseComponent);
		return Component;
	}
	if (BaseComponentClass == Noesis::Gui::HierarchicalDataTemplate::StaticGetClassType())
	{
		UNoesisGuiBaseComponent* Component = NewObject<UNoesisGuiHierarchicalDataTemplate>(Outer);
		Component->SetNoesisComponent(BaseComponent);
		return Component;
	}
	if (BaseComponentClass == Noesis::Gui::ItemsPanelTemplate::StaticGetClassType())
	{
		UNoesisGuiBaseComponent* Component = NewObject<UNoesisGuiItemsPanelTemplate>(Outer);
		Component->SetNoesisComponent(BaseComponent);
		return Component;
	}
	if (BaseComponentClass == Noesis::Gui::InputGesture::StaticGetClassType())
	{
		UNoesisGuiBaseComponent* Component = NewObject<UNoesisGuiInputGesture>(Outer);
		Component->SetNoesisComponent(BaseComponent);
		return Component;
	}
	if (BaseComponentClass == Noesis::Gui::KeyGesture::StaticGetClassType())
	{
		UNoesisGuiBaseComponent* Component = NewObject<UNoesisGuiKeyGesture>(Outer);
		Component->SetNoesisComponent(BaseComponent);
		return Component;
	}
	if (BaseComponentClass == Noesis::Gui::ItemCollection::StaticGetClassType())
	{
		UNoesisGuiBaseComponent* Component = NewObject<UNoesisGuiItemCollection>(Outer);
		Component->SetNoesisComponent(BaseComponent);
		return Component;
	}
	if (BaseComponentClass == Noesis::Gui::ItemContainerGenerator::StaticGetClassType())
	{
		UNoesisGuiBaseComponent* Component = NewObject<UNoesisGuiItemContainerGenerator>(Outer);
		Component->SetNoesisComponent(BaseComponent);
		return Component;
	}
	if (BaseComponentClass == Noesis::Gui::KeyboardNavigation::StaticGetClassType())
	{
		UNoesisGuiBaseComponent* Component = NewObject<UNoesisGuiKeyboardNavigation>(Outer);
		Component->SetNoesisComponent(BaseComponent);
		return Component;
	}
	if (BaseComponentClass == Noesis::Gui::PropertyPath::StaticGetClassType())
	{
		UNoesisGuiBaseComponent* Component = NewObject<UNoesisGuiPropertyPath>(Outer);
		Component->SetNoesisComponent(BaseComponent);
		return Component;
	}
	if (BaseComponentClass == Noesis::Gui::RelativeSource::StaticGetClassType())
	{
		UNoesisGuiBaseComponent* Component = NewObject<UNoesisGuiRelativeSource>(Outer);
		Component->SetNoesisComponent(BaseComponent);
		return Component;
	}
	if (BaseComponentClass == Noesis::Gui::ResourceKeyType::StaticGetClassType())
	{
		UNoesisGuiBaseComponent* Component = NewObject<UNoesisGuiResourceKeyType>(Outer);
		Component->SetNoesisComponent(BaseComponent);
		return Component;
	}
	if (BaseComponentClass == Noesis::Gui::RoutedCommand::StaticGetClassType())
	{
		UNoesisGuiBaseComponent* Component = NewObject<UNoesisGuiRoutedCommand>(Outer);
		Component->SetNoesisComponent(BaseComponent);
		return Component;
	}
	if (BaseComponentClass == Noesis::Gui::RoutedUICommand::StaticGetClassType())
	{
		UNoesisGuiBaseComponent* Component = NewObject<UNoesisGuiRoutedUICommand>(Outer);
		Component->SetNoesisComponent(BaseComponent);
		return Component;
	}
	if (BaseComponentClass == Noesis::Gui::RoutedEvent::StaticGetClassType())
	{
		UNoesisGuiBaseComponent* Component = NewObject<UNoesisGuiRoutedEvent>(Outer);
		Component->SetNoesisComponent(BaseComponent);
		return Component;
	}
	if (BaseComponentClass == Noesis::Gui::Style::StaticGetClassType())
	{
		UNoesisGuiBaseComponent* Component = NewObject<UNoesisGuiStyle>(Outer);
		Component->SetNoesisComponent(BaseComponent);
		return Component;
	}
	if (BaseComponentClass == Noesis::Gui::TemplateBinding::StaticGetClassType())
	{
		UNoesisGuiBaseComponent* Component = NewObject<UNoesisGuiTemplateBinding>(Outer);
		Component->SetNoesisComponent(BaseComponent);
		return Component;
	}
	if (BaseComponentClass == Noesis::Gui::ToolTipService::StaticGetClassType())
	{
		UNoesisGuiBaseComponent* Component = NewObject<UNoesisGuiToolTipService>(Outer);
		Component->SetNoesisComponent(BaseComponent);
		return Component;
	}
	if (BaseComponentClass == Noesis::Gui::ThicknessKeyFrameCollection::StaticGetClassType())
	{
		UNoesisGuiBaseComponent* Component = NewObject<UNoesisGuiThicknessKeyFrameCollection>(Outer);
		Component->SetNoesisComponent(BaseComponent);
		return Component;
	}
	if (BaseComponentClass == Noesis::Gui::ColorKeyFrameCollection::StaticGetClassType())
	{
		UNoesisGuiBaseComponent* Component = NewObject<UNoesisGuiColorKeyFrameCollection>(Outer);
		Component->SetNoesisComponent(BaseComponent);
		return Component;
	}
	if (BaseComponentClass == Noesis::Gui::SizeKeyFrameCollection::StaticGetClassType())
	{
		UNoesisGuiBaseComponent* Component = NewObject<UNoesisGuiSizeKeyFrameCollection>(Outer);
		Component->SetNoesisComponent(BaseComponent);
		return Component;
	}
	if (BaseComponentClass == Noesis::Gui::ObjectKeyFrameCollection::StaticGetClassType())
	{
		UNoesisGuiBaseComponent* Component = NewObject<UNoesisGuiObjectKeyFrameCollection>(Outer);
		Component->SetNoesisComponent(BaseComponent);
		return Component;
	}
	if (BaseComponentClass == Noesis::Gui::BooleanKeyFrameCollection::StaticGetClassType())
	{
		UNoesisGuiBaseComponent* Component = NewObject<UNoesisGuiBooleanKeyFrameCollection>(Outer);
		Component->SetNoesisComponent(BaseComponent);
		return Component;
	}
	if (BaseComponentClass == Noesis::Gui::Int32KeyFrameCollection::StaticGetClassType())
	{
		UNoesisGuiBaseComponent* Component = NewObject<UNoesisGuiInt32KeyFrameCollection>(Outer);
		Component->SetNoesisComponent(BaseComponent);
		return Component;
	}
	if (BaseComponentClass == Noesis::Gui::DoubleKeyFrameCollection::StaticGetClassType())
	{
		UNoesisGuiBaseComponent* Component = NewObject<UNoesisGuiDoubleKeyFrameCollection>(Outer);
		Component->SetNoesisComponent(BaseComponent);
		return Component;
	}
	if (BaseComponentClass == Noesis::Gui::Int16KeyFrameCollection::StaticGetClassType())
	{
		UNoesisGuiBaseComponent* Component = NewObject<UNoesisGuiInt16KeyFrameCollection>(Outer);
		Component->SetNoesisComponent(BaseComponent);
		return Component;
	}
	if (BaseComponentClass == Noesis::Gui::StringKeyFrameCollection::StaticGetClassType())
	{
		UNoesisGuiBaseComponent* Component = NewObject<UNoesisGuiStringKeyFrameCollection>(Outer);
		Component->SetNoesisComponent(BaseComponent);
		return Component;
	}
	if (BaseComponentClass == Noesis::Gui::PointKeyFrameCollection::StaticGetClassType())
	{
		UNoesisGuiBaseComponent* Component = NewObject<UNoesisGuiPointKeyFrameCollection>(Outer);
		Component->SetNoesisComponent(BaseComponent);
		return Component;
	}
	if (BaseComponentClass == Noesis::Gui::RectKeyFrameCollection::StaticGetClassType())
	{
		UNoesisGuiBaseComponent* Component = NewObject<UNoesisGuiRectKeyFrameCollection>(Outer);
		Component->SetNoesisComponent(BaseComponent);
		return Component;
	}
	if (BaseComponentClass == Noesis::Gui::VirtualizationCacheLength::StaticGetClassType())
	{
		UNoesisGuiBaseComponent* Component = NewObject<UNoesisGuiVirtualizationCacheLength>(Outer);
		Component->SetNoesisComponent(BaseComponent);
		return Component;
	}
	if (BaseComponentClass == Noesis::Gui::VisualStateManager::StaticGetClassType())
	{
		UNoesisGuiBaseComponent* Component = NewObject<UNoesisGuiVisualStateManager>(Outer);
		Component->SetNoesisComponent(BaseComponent);
		return Component;
	}
	{
		return NewObject<UNoesisGuiBaseComponent>();
	}
}

