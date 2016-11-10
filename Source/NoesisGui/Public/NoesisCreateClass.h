////////////////////////////////////////////////////////////////////////////////////////////////////
// Noesis Engine - http://www.noesisengine.com
// Copyright (c) 2009-2010 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#pragma once

#include "NoesisGeneratedClasses.h"

UNoesisBaseComponent* CreateClassFor(Noesis::Core::BaseComponent* BaseComponent, UObject* Outer)
{
	const Noesis::Core::TypeClass* BaseComponentClass = BaseComponent->GetClassType();
	UClass* Class = UNoesisBaseComponent::StaticClass();
	if (BaseComponentClass == Noesis::Gui::BaseBinding::StaticGetClassType() || BaseComponentClass->IsDescendantOf(Noesis::Gui::BaseBinding::StaticGetClassType()))
	{
		Class = UNoesisBaseBinding::StaticClass();
	}
	if (BaseComponentClass == Noesis::Gui::Binding::StaticGetClassType() || BaseComponentClass->IsDescendantOf(Noesis::Gui::Binding::StaticGetClassType()))
	{
		Class = UNoesisBinding::StaticClass();
	}
	if (BaseComponentClass == Noesis::Gui::BaseCommand::StaticGetClassType() || BaseComponentClass->IsDescendantOf(Noesis::Gui::BaseCommand::StaticGetClassType()))
	{
		Class = UNoesisBaseCommand::StaticClass();
	}
	if (BaseComponentClass == Noesis::Gui::BaseDictionary::StaticGetClassType() || BaseComponentClass->IsDescendantOf(Noesis::Gui::BaseDictionary::StaticGetClassType()))
	{
		Class = UNoesisBaseDictionary::StaticClass();
	}
	if (BaseComponentClass == Noesis::Gui::ResourceDictionary::StaticGetClassType() || BaseComponentClass->IsDescendantOf(Noesis::Gui::ResourceDictionary::StaticGetClassType()))
	{
		Class = UNoesisResourceDictionary::StaticClass();
	}
	if (BaseComponentClass == Noesis::Gui::BaseSetter::StaticGetClassType() || BaseComponentClass->IsDescendantOf(Noesis::Gui::BaseSetter::StaticGetClassType()))
	{
		Class = UNoesisBaseSetter::StaticClass();
	}
	if (BaseComponentClass == Noesis::Gui::Setter::StaticGetClassType() || BaseComponentClass->IsDescendantOf(Noesis::Gui::Setter::StaticGetClassType()))
	{
		Class = UNoesisSetter::StaticClass();
	}
	if (BaseComponentClass == Noesis::Gui::BaseValueConverter::StaticGetClassType() || BaseComponentClass->IsDescendantOf(Noesis::Gui::BaseValueConverter::StaticGetClassType()))
	{
		Class = UNoesisBaseValueConverter::StaticClass();
	}
	if (BaseComponentClass == Noesis::Gui::Clock::StaticGetClassType() || BaseComponentClass->IsDescendantOf(Noesis::Gui::Clock::StaticGetClassType()))
	{
		Class = UNoesisClock::StaticClass();
	}
	if (BaseComponentClass == Noesis::Gui::AnimationClock::StaticGetClassType() || BaseComponentClass->IsDescendantOf(Noesis::Gui::AnimationClock::StaticGetClassType()))
	{
		Class = UNoesisAnimationClock::StaticClass();
	}
	if (BaseComponentClass == Noesis::Gui::ClockGroup::StaticGetClassType() || BaseComponentClass->IsDescendantOf(Noesis::Gui::ClockGroup::StaticGetClassType()))
	{
		Class = UNoesisClockGroup::StaticClass();
	}
	if (BaseComponentClass == Noesis::Gui::Collection::StaticGetClassType() || BaseComponentClass->IsDescendantOf(Noesis::Gui::Collection::StaticGetClassType()))
	{
		Class = UNoesisCollection::StaticClass();
	}
	if (BaseComponentClass == Noesis::Gui::TriggerCollection::StaticGetClassType() || BaseComponentClass->IsDescendantOf(Noesis::Gui::TriggerCollection::StaticGetClassType()))
	{
		Class = UNoesisTriggerCollection::StaticClass();
	}
	if (BaseComponentClass == Noesis::Gui::InputBindingCollection::StaticGetClassType() || BaseComponentClass->IsDescendantOf(Noesis::Gui::InputBindingCollection::StaticGetClassType()))
	{
		Class = UNoesisInputBindingCollection::StaticClass();
	}
	if (BaseComponentClass == Noesis::Gui::BaseSetterCollection::StaticGetClassType() || BaseComponentClass->IsDescendantOf(Noesis::Gui::BaseSetterCollection::StaticGetClassType()))
	{
		Class = UNoesisBaseSetterCollection::StaticClass();
	}
	if (BaseComponentClass == Noesis::Gui::VisualStateCollection::StaticGetClassType() || BaseComponentClass->IsDescendantOf(Noesis::Gui::VisualStateCollection::StaticGetClassType()))
	{
		Class = UNoesisVisualStateCollection::StaticClass();
	}
	if (BaseComponentClass == Noesis::Gui::CommandBindingCollection::StaticGetClassType() || BaseComponentClass->IsDescendantOf(Noesis::Gui::CommandBindingCollection::StaticGetClassType()))
	{
		Class = UNoesisCommandBindingCollection::StaticClass();
	}
	if (BaseComponentClass == Noesis::Gui::InlineCollection::StaticGetClassType() || BaseComponentClass->IsDescendantOf(Noesis::Gui::InlineCollection::StaticGetClassType()))
	{
		Class = UNoesisInlineCollection::StaticClass();
	}
	if (BaseComponentClass == Noesis::Gui::ColumnDefinitionCollection::StaticGetClassType() || BaseComponentClass->IsDescendantOf(Noesis::Gui::ColumnDefinitionCollection::StaticGetClassType()))
	{
		Class = UNoesisColumnDefinitionCollection::StaticClass();
	}
	if (BaseComponentClass == Noesis::Gui::RowDefinitionCollection::StaticGetClassType() || BaseComponentClass->IsDescendantOf(Noesis::Gui::RowDefinitionCollection::StaticGetClassType()))
	{
		Class = UNoesisRowDefinitionCollection::StaticClass();
	}
	if (BaseComponentClass == Noesis::Gui::GridViewColumnCollection::StaticGetClassType() || BaseComponentClass->IsDescendantOf(Noesis::Gui::GridViewColumnCollection::StaticGetClassType()))
	{
		Class = UNoesisGridViewColumnCollection::StaticClass();
	}
	if (BaseComponentClass == Noesis::Gui::TriggerActionCollection::StaticGetClassType() || BaseComponentClass->IsDescendantOf(Noesis::Gui::TriggerActionCollection::StaticGetClassType()))
	{
		Class = UNoesisTriggerActionCollection::StaticClass();
	}
	if (BaseComponentClass == Noesis::Gui::ConditionCollection::StaticGetClassType() || BaseComponentClass->IsDescendantOf(Noesis::Gui::ConditionCollection::StaticGetClassType()))
	{
		Class = UNoesisConditionCollection::StaticClass();
	}
	if (BaseComponentClass == Noesis::Gui::ResourceDictionaryCollection::StaticGetClassType() || BaseComponentClass->IsDescendantOf(Noesis::Gui::ResourceDictionaryCollection::StaticGetClassType()))
	{
		Class = UNoesisResourceDictionaryCollection::StaticClass();
	}
	if (BaseComponentClass == Noesis::Gui::VisualTransitionCollection::StaticGetClassType() || BaseComponentClass->IsDescendantOf(Noesis::Gui::VisualTransitionCollection::StaticGetClassType()))
	{
		Class = UNoesisVisualTransitionCollection::StaticClass();
	}
	if (BaseComponentClass == Noesis::Gui::InputGestureCollection::StaticGetClassType() || BaseComponentClass->IsDescendantOf(Noesis::Gui::InputGestureCollection::StaticGetClassType()))
	{
		Class = UNoesisInputGestureCollection::StaticClass();
	}
	if (BaseComponentClass == Noesis::Gui::VisualCollection::StaticGetClassType() || BaseComponentClass->IsDescendantOf(Noesis::Gui::VisualCollection::StaticGetClassType()))
	{
		Class = UNoesisVisualCollection::StaticClass();
	}
	if (BaseComponentClass == Noesis::Gui::UIElementCollection::StaticGetClassType() || BaseComponentClass->IsDescendantOf(Noesis::Gui::UIElementCollection::StaticGetClassType()))
	{
		Class = UNoesisUIElementCollection::StaticClass();
	}
	if (BaseComponentClass == Noesis::Gui::CollectionView::StaticGetClassType() || BaseComponentClass->IsDescendantOf(Noesis::Gui::CollectionView::StaticGetClassType()))
	{
		Class = UNoesisCollectionView::StaticClass();
	}
	if (BaseComponentClass == Noesis::Gui::CommandBinding::StaticGetClassType() || BaseComponentClass->IsDescendantOf(Noesis::Gui::CommandBinding::StaticGetClassType()))
	{
		Class = UNoesisCommandBinding::StaticClass();
	}
	if (BaseComponentClass == Noesis::Gui::Condition::StaticGetClassType() || BaseComponentClass->IsDescendantOf(Noesis::Gui::Condition::StaticGetClassType()))
	{
		Class = UNoesisCondition::StaticClass();
	}
	if (BaseComponentClass == Noesis::Gui::DataTemplateSelector::StaticGetClassType() || BaseComponentClass->IsDescendantOf(Noesis::Gui::DataTemplateSelector::StaticGetClassType()))
	{
		Class = UNoesisDataTemplateSelector::StaticClass();
	}
	if (BaseComponentClass == Noesis::Gui::DependencyObject::StaticGetClassType() || BaseComponentClass->IsDescendantOf(Noesis::Gui::DependencyObject::StaticGetClassType()))
	{
		Class = UNoesisDependencyObject::StaticClass();
	}
	if (BaseComponentClass == Noesis::Gui::BaseTrigger::StaticGetClassType() || BaseComponentClass->IsDescendantOf(Noesis::Gui::BaseTrigger::StaticGetClassType()))
	{
		Class = UNoesisBaseTrigger::StaticClass();
	}
	if (BaseComponentClass == Noesis::Gui::DataTrigger::StaticGetClassType() || BaseComponentClass->IsDescendantOf(Noesis::Gui::DataTrigger::StaticGetClassType()))
	{
		Class = UNoesisDataTrigger::StaticClass();
	}
	if (BaseComponentClass == Noesis::Gui::EventTrigger::StaticGetClassType() || BaseComponentClass->IsDescendantOf(Noesis::Gui::EventTrigger::StaticGetClassType()))
	{
		Class = UNoesisEventTrigger::StaticClass();
	}
	if (BaseComponentClass == Noesis::Gui::MultiDataTrigger::StaticGetClassType() || BaseComponentClass->IsDescendantOf(Noesis::Gui::MultiDataTrigger::StaticGetClassType()))
	{
		Class = UNoesisMultiDataTrigger::StaticClass();
	}
	if (BaseComponentClass == Noesis::Gui::MultiTrigger::StaticGetClassType() || BaseComponentClass->IsDescendantOf(Noesis::Gui::MultiTrigger::StaticGetClassType()))
	{
		Class = UNoesisMultiTrigger::StaticClass();
	}
	if (BaseComponentClass == Noesis::Gui::Trigger::StaticGetClassType() || BaseComponentClass->IsDescendantOf(Noesis::Gui::Trigger::StaticGetClassType()))
	{
		Class = UNoesisTrigger::StaticClass();
	}
	if (BaseComponentClass == Noesis::Gui::BaseView::StaticGetClassType() || BaseComponentClass->IsDescendantOf(Noesis::Gui::BaseView::StaticGetClassType()))
	{
		Class = UNoesisBaseView::StaticClass();
	}
	if (BaseComponentClass == Noesis::Gui::GridView::StaticGetClassType() || BaseComponentClass->IsDescendantOf(Noesis::Gui::GridView::StaticGetClassType()))
	{
		Class = UNoesisGridView::StaticClass();
	}
	if (BaseComponentClass == Noesis::Gui::CollectionViewSource::StaticGetClassType() || BaseComponentClass->IsDescendantOf(Noesis::Gui::CollectionViewSource::StaticGetClassType()))
	{
		Class = UNoesisCollectionViewSource::StaticClass();
	}
	if (BaseComponentClass == Noesis::Gui::Freezable::StaticGetClassType() || BaseComponentClass->IsDescendantOf(Noesis::Gui::Freezable::StaticGetClassType()))
	{
		Class = UNoesisFreezable::StaticClass();
	}
	if (BaseComponentClass == Noesis::Gui::Animatable::StaticGetClassType() || BaseComponentClass->IsDescendantOf(Noesis::Gui::Animatable::StaticGetClassType()))
	{
		Class = UNoesisAnimatable::StaticClass();
	}
	if (BaseComponentClass == Noesis::Gui::Brush::StaticGetClassType() || BaseComponentClass->IsDescendantOf(Noesis::Gui::Brush::StaticGetClassType()))
	{
		Class = UNoesisBrush::StaticClass();
	}
	if (BaseComponentClass == Noesis::Gui::GradientBrush::StaticGetClassType() || BaseComponentClass->IsDescendantOf(Noesis::Gui::GradientBrush::StaticGetClassType()))
	{
		Class = UNoesisGradientBrush::StaticClass();
	}
	if (BaseComponentClass == Noesis::Gui::LinearGradientBrush::StaticGetClassType() || BaseComponentClass->IsDescendantOf(Noesis::Gui::LinearGradientBrush::StaticGetClassType()))
	{
		Class = UNoesisLinearGradientBrush::StaticClass();
	}
	if (BaseComponentClass == Noesis::Gui::RadialGradientBrush::StaticGetClassType() || BaseComponentClass->IsDescendantOf(Noesis::Gui::RadialGradientBrush::StaticGetClassType()))
	{
		Class = UNoesisRadialGradientBrush::StaticClass();
	}
	if (BaseComponentClass == Noesis::Gui::SolidColorBrush::StaticGetClassType() || BaseComponentClass->IsDescendantOf(Noesis::Gui::SolidColorBrush::StaticGetClassType()))
	{
		Class = UNoesisSolidColorBrush::StaticClass();
	}
	if (BaseComponentClass == Noesis::Gui::TileBrush::StaticGetClassType() || BaseComponentClass->IsDescendantOf(Noesis::Gui::TileBrush::StaticGetClassType()))
	{
		Class = UNoesisTileBrush::StaticClass();
	}
	if (BaseComponentClass == Noesis::Gui::ImageBrush::StaticGetClassType() || BaseComponentClass->IsDescendantOf(Noesis::Gui::ImageBrush::StaticGetClassType()))
	{
		Class = UNoesisImageBrush::StaticClass();
	}
	if (BaseComponentClass == Noesis::Gui::VisualBrush::StaticGetClassType() || BaseComponentClass->IsDescendantOf(Noesis::Gui::VisualBrush::StaticGetClassType()))
	{
		Class = UNoesisVisualBrush::StaticClass();
	}
	if (BaseComponentClass == Noesis::Gui::DashStyle::StaticGetClassType() || BaseComponentClass->IsDescendantOf(Noesis::Gui::DashStyle::StaticGetClassType()))
	{
		Class = UNoesisDashStyle::StaticClass();
	}
	if (BaseComponentClass == Noesis::Gui::Geometry::StaticGetClassType() || BaseComponentClass->IsDescendantOf(Noesis::Gui::Geometry::StaticGetClassType()))
	{
		Class = UNoesisGeometry::StaticClass();
	}
	if (BaseComponentClass == Noesis::Gui::CombinedGeometry::StaticGetClassType() || BaseComponentClass->IsDescendantOf(Noesis::Gui::CombinedGeometry::StaticGetClassType()))
	{
		Class = UNoesisCombinedGeometry::StaticClass();
	}
	if (BaseComponentClass == Noesis::Gui::EllipseGeometry::StaticGetClassType() || BaseComponentClass->IsDescendantOf(Noesis::Gui::EllipseGeometry::StaticGetClassType()))
	{
		Class = UNoesisEllipseGeometry::StaticClass();
	}
	if (BaseComponentClass == Noesis::Gui::GeometryGroup::StaticGetClassType() || BaseComponentClass->IsDescendantOf(Noesis::Gui::GeometryGroup::StaticGetClassType()))
	{
		Class = UNoesisGeometryGroup::StaticClass();
	}
	if (BaseComponentClass == Noesis::Gui::LineGeometry::StaticGetClassType() || BaseComponentClass->IsDescendantOf(Noesis::Gui::LineGeometry::StaticGetClassType()))
	{
		Class = UNoesisLineGeometry::StaticClass();
	}
	if (BaseComponentClass == Noesis::Gui::RectangleGeometry::StaticGetClassType() || BaseComponentClass->IsDescendantOf(Noesis::Gui::RectangleGeometry::StaticGetClassType()))
	{
		Class = UNoesisRectangleGeometry::StaticClass();
	}
	if (BaseComponentClass == Noesis::Gui::StreamGeometry::StaticGetClassType() || BaseComponentClass->IsDescendantOf(Noesis::Gui::StreamGeometry::StaticGetClassType()))
	{
		Class = UNoesisStreamGeometry::StaticClass();
	}
	if (BaseComponentClass == Noesis::Gui::GradientStop::StaticGetClassType() || BaseComponentClass->IsDescendantOf(Noesis::Gui::GradientStop::StaticGetClassType()))
	{
		Class = UNoesisGradientStop::StaticClass();
	}
	if (BaseComponentClass == Noesis::Gui::ImageSource::StaticGetClassType() || BaseComponentClass->IsDescendantOf(Noesis::Gui::ImageSource::StaticGetClassType()))
	{
		Class = UNoesisImageSource::StaticClass();
	}
	if (BaseComponentClass == Noesis::Gui::BitmapSource::StaticGetClassType() || BaseComponentClass->IsDescendantOf(Noesis::Gui::BitmapSource::StaticGetClassType()))
	{
		Class = UNoesisBitmapSource::StaticClass();
	}
	if (BaseComponentClass == Noesis::Gui::BitmapImage::StaticGetClassType() || BaseComponentClass->IsDescendantOf(Noesis::Gui::BitmapImage::StaticGetClassType()))
	{
		Class = UNoesisBitmapImage::StaticClass();
	}
	if (BaseComponentClass == Noesis::Gui::TextureSource::StaticGetClassType() || BaseComponentClass->IsDescendantOf(Noesis::Gui::TextureSource::StaticGetClassType()))
	{
		Class = UNoesisTextureSource::StaticClass();
	}
	if (BaseComponentClass == Noesis::Gui::Pen::StaticGetClassType() || BaseComponentClass->IsDescendantOf(Noesis::Gui::Pen::StaticGetClassType()))
	{
		Class = UNoesisPen::StaticClass();
	}
	if (BaseComponentClass == Noesis::Gui::Projection::StaticGetClassType() || BaseComponentClass->IsDescendantOf(Noesis::Gui::Projection::StaticGetClassType()))
	{
		Class = UNoesisProjection::StaticClass();
	}
	if (BaseComponentClass == Noesis::Gui::Matrix3DProjection::StaticGetClassType() || BaseComponentClass->IsDescendantOf(Noesis::Gui::Matrix3DProjection::StaticGetClassType()))
	{
		Class = UNoesisMatrix3DProjection::StaticClass();
	}
	if (BaseComponentClass == Noesis::Gui::PlaneProjection::StaticGetClassType() || BaseComponentClass->IsDescendantOf(Noesis::Gui::PlaneProjection::StaticGetClassType()))
	{
		Class = UNoesisPlaneProjection::StaticClass();
	}
	if (BaseComponentClass == Noesis::Gui::Timeline::StaticGetClassType() || BaseComponentClass->IsDescendantOf(Noesis::Gui::Timeline::StaticGetClassType()))
	{
		Class = UNoesisTimeline::StaticClass();
	}
	if (BaseComponentClass == Noesis::Gui::AnimationTimeline::StaticGetClassType() || BaseComponentClass->IsDescendantOf(Noesis::Gui::AnimationTimeline::StaticGetClassType()))
	{
		Class = UNoesisAnimationTimeline::StaticClass();
	}
	if (BaseComponentClass == Noesis::Gui::Int16AnimationUsingKeyFrames::StaticGetClassType() || BaseComponentClass->IsDescendantOf(Noesis::Gui::Int16AnimationUsingKeyFrames::StaticGetClassType()))
	{
		Class = UNoesisInt16AnimationUsingKeyFrames::StaticClass();
	}
	if (BaseComponentClass == Noesis::Gui::SizeAnimationUsingKeyFrames::StaticGetClassType() || BaseComponentClass->IsDescendantOf(Noesis::Gui::SizeAnimationUsingKeyFrames::StaticGetClassType()))
	{
		Class = UNoesisSizeAnimationUsingKeyFrames::StaticClass();
	}
	if (BaseComponentClass == Noesis::Gui::PointAnimationUsingKeyFrames::StaticGetClassType() || BaseComponentClass->IsDescendantOf(Noesis::Gui::PointAnimationUsingKeyFrames::StaticGetClassType()))
	{
		Class = UNoesisPointAnimationUsingKeyFrames::StaticClass();
	}
	if (BaseComponentClass == Noesis::Gui::ColorAnimationUsingKeyFrames::StaticGetClassType() || BaseComponentClass->IsDescendantOf(Noesis::Gui::ColorAnimationUsingKeyFrames::StaticGetClassType()))
	{
		Class = UNoesisColorAnimationUsingKeyFrames::StaticClass();
	}
	if (BaseComponentClass == Noesis::Gui::ThicknessAnimationUsingKeyFrames::StaticGetClassType() || BaseComponentClass->IsDescendantOf(Noesis::Gui::ThicknessAnimationUsingKeyFrames::StaticGetClassType()))
	{
		Class = UNoesisThicknessAnimationUsingKeyFrames::StaticClass();
	}
	if (BaseComponentClass == Noesis::Gui::ObjectAnimationUsingKeyFrames::StaticGetClassType() || BaseComponentClass->IsDescendantOf(Noesis::Gui::ObjectAnimationUsingKeyFrames::StaticGetClassType()))
	{
		Class = UNoesisObjectAnimationUsingKeyFrames::StaticClass();
	}
	if (BaseComponentClass == Noesis::Gui::Int32AnimationUsingKeyFrames::StaticGetClassType() || BaseComponentClass->IsDescendantOf(Noesis::Gui::Int32AnimationUsingKeyFrames::StaticGetClassType()))
	{
		Class = UNoesisInt32AnimationUsingKeyFrames::StaticClass();
	}
	if (BaseComponentClass == Noesis::Gui::StringAnimationUsingKeyFrames::StaticGetClassType() || BaseComponentClass->IsDescendantOf(Noesis::Gui::StringAnimationUsingKeyFrames::StaticGetClassType()))
	{
		Class = UNoesisStringAnimationUsingKeyFrames::StaticClass();
	}
	if (BaseComponentClass == Noesis::Gui::BooleanAnimationUsingKeyFrames::StaticGetClassType() || BaseComponentClass->IsDescendantOf(Noesis::Gui::BooleanAnimationUsingKeyFrames::StaticGetClassType()))
	{
		Class = UNoesisBooleanAnimationUsingKeyFrames::StaticClass();
	}
	if (BaseComponentClass == Noesis::Gui::RectAnimationUsingKeyFrames::StaticGetClassType() || BaseComponentClass->IsDescendantOf(Noesis::Gui::RectAnimationUsingKeyFrames::StaticGetClassType()))
	{
		Class = UNoesisRectAnimationUsingKeyFrames::StaticClass();
	}
	if (BaseComponentClass == Noesis::Gui::DoubleAnimationUsingKeyFrames::StaticGetClassType() || BaseComponentClass->IsDescendantOf(Noesis::Gui::DoubleAnimationUsingKeyFrames::StaticGetClassType()))
	{
		Class = UNoesisDoubleAnimationUsingKeyFrames::StaticClass();
	}
	if (BaseComponentClass == Noesis::Gui::BaseAnimation::StaticGetClassType() || BaseComponentClass->IsDescendantOf(Noesis::Gui::BaseAnimation::StaticGetClassType()))
	{
		Class = UNoesisBaseAnimation::StaticClass();
	}
	if (BaseComponentClass == Noesis::Gui::Int32Animation::StaticGetClassType() || BaseComponentClass->IsDescendantOf(Noesis::Gui::Int32Animation::StaticGetClassType()))
	{
		Class = UNoesisInt32Animation::StaticClass();
	}
	if (BaseComponentClass == Noesis::Gui::PointAnimation::StaticGetClassType() || BaseComponentClass->IsDescendantOf(Noesis::Gui::PointAnimation::StaticGetClassType()))
	{
		Class = UNoesisPointAnimation::StaticClass();
	}
	if (BaseComponentClass == Noesis::Gui::ColorAnimation::StaticGetClassType() || BaseComponentClass->IsDescendantOf(Noesis::Gui::ColorAnimation::StaticGetClassType()))
	{
		Class = UNoesisColorAnimation::StaticClass();
	}
	if (BaseComponentClass == Noesis::Gui::RectAnimation::StaticGetClassType() || BaseComponentClass->IsDescendantOf(Noesis::Gui::RectAnimation::StaticGetClassType()))
	{
		Class = UNoesisRectAnimation::StaticClass();
	}
	if (BaseComponentClass == Noesis::Gui::ThicknessAnimation::StaticGetClassType() || BaseComponentClass->IsDescendantOf(Noesis::Gui::ThicknessAnimation::StaticGetClassType()))
	{
		Class = UNoesisThicknessAnimation::StaticClass();
	}
	if (BaseComponentClass == Noesis::Gui::SizeAnimation::StaticGetClassType() || BaseComponentClass->IsDescendantOf(Noesis::Gui::SizeAnimation::StaticGetClassType()))
	{
		Class = UNoesisSizeAnimation::StaticClass();
	}
	if (BaseComponentClass == Noesis::Gui::Int16Animation::StaticGetClassType() || BaseComponentClass->IsDescendantOf(Noesis::Gui::Int16Animation::StaticGetClassType()))
	{
		Class = UNoesisInt16Animation::StaticClass();
	}
	if (BaseComponentClass == Noesis::Gui::DoubleAnimation::StaticGetClassType() || BaseComponentClass->IsDescendantOf(Noesis::Gui::DoubleAnimation::StaticGetClassType()))
	{
		Class = UNoesisDoubleAnimation::StaticClass();
	}
	if (BaseComponentClass == Noesis::Gui::TimelineGroup::StaticGetClassType() || BaseComponentClass->IsDescendantOf(Noesis::Gui::TimelineGroup::StaticGetClassType()))
	{
		Class = UNoesisTimelineGroup::StaticClass();
	}
	if (BaseComponentClass == Noesis::Gui::ParallelTimeline::StaticGetClassType() || BaseComponentClass->IsDescendantOf(Noesis::Gui::ParallelTimeline::StaticGetClassType()))
	{
		Class = UNoesisParallelTimeline::StaticClass();
	}
	if (BaseComponentClass == Noesis::Gui::Storyboard::StaticGetClassType() || BaseComponentClass->IsDescendantOf(Noesis::Gui::Storyboard::StaticGetClassType()))
	{
		Class = UNoesisStoryboard::StaticClass();
	}
	if (BaseComponentClass == Noesis::Gui::Transform::StaticGetClassType() || BaseComponentClass->IsDescendantOf(Noesis::Gui::Transform::StaticGetClassType()))
	{
		Class = UNoesisTransform::StaticClass();
	}
	if (BaseComponentClass == Noesis::Gui::CompositeTransform::StaticGetClassType() || BaseComponentClass->IsDescendantOf(Noesis::Gui::CompositeTransform::StaticGetClassType()))
	{
		Class = UNoesisCompositeTransform::StaticClass();
	}
	if (BaseComponentClass == Noesis::Gui::MatrixTransform::StaticGetClassType() || BaseComponentClass->IsDescendantOf(Noesis::Gui::MatrixTransform::StaticGetClassType()))
	{
		Class = UNoesisMatrixTransform::StaticClass();
	}
	if (BaseComponentClass == Noesis::Gui::RotateTransform::StaticGetClassType() || BaseComponentClass->IsDescendantOf(Noesis::Gui::RotateTransform::StaticGetClassType()))
	{
		Class = UNoesisRotateTransform::StaticClass();
	}
	if (BaseComponentClass == Noesis::Gui::ScaleTransform::StaticGetClassType() || BaseComponentClass->IsDescendantOf(Noesis::Gui::ScaleTransform::StaticGetClassType()))
	{
		Class = UNoesisScaleTransform::StaticClass();
	}
	if (BaseComponentClass == Noesis::Gui::SkewTransform::StaticGetClassType() || BaseComponentClass->IsDescendantOf(Noesis::Gui::SkewTransform::StaticGetClassType()))
	{
		Class = UNoesisSkewTransform::StaticClass();
	}
	if (BaseComponentClass == Noesis::Gui::TransformGroup::StaticGetClassType() || BaseComponentClass->IsDescendantOf(Noesis::Gui::TransformGroup::StaticGetClassType()))
	{
		Class = UNoesisTransformGroup::StaticClass();
	}
	if (BaseComponentClass == Noesis::Gui::TranslateTransform::StaticGetClassType() || BaseComponentClass->IsDescendantOf(Noesis::Gui::TranslateTransform::StaticGetClassType()))
	{
		Class = UNoesisTranslateTransform::StaticClass();
	}
	if (BaseComponentClass == Noesis::Gui::EasingFunctionBase::StaticGetClassType() || BaseComponentClass->IsDescendantOf(Noesis::Gui::EasingFunctionBase::StaticGetClassType()))
	{
		Class = UNoesisEasingFunctionBase::StaticClass();
	}
	if (BaseComponentClass == Noesis::Gui::BackEase::StaticGetClassType() || BaseComponentClass->IsDescendantOf(Noesis::Gui::BackEase::StaticGetClassType()))
	{
		Class = UNoesisBackEase::StaticClass();
	}
	if (BaseComponentClass == Noesis::Gui::BounceEase::StaticGetClassType() || BaseComponentClass->IsDescendantOf(Noesis::Gui::BounceEase::StaticGetClassType()))
	{
		Class = UNoesisBounceEase::StaticClass();
	}
	if (BaseComponentClass == Noesis::Gui::CircleEase::StaticGetClassType() || BaseComponentClass->IsDescendantOf(Noesis::Gui::CircleEase::StaticGetClassType()))
	{
		Class = UNoesisCircleEase::StaticClass();
	}
	if (BaseComponentClass == Noesis::Gui::CubicEase::StaticGetClassType() || BaseComponentClass->IsDescendantOf(Noesis::Gui::CubicEase::StaticGetClassType()))
	{
		Class = UNoesisCubicEase::StaticClass();
	}
	if (BaseComponentClass == Noesis::Gui::ElasticEase::StaticGetClassType() || BaseComponentClass->IsDescendantOf(Noesis::Gui::ElasticEase::StaticGetClassType()))
	{
		Class = UNoesisElasticEase::StaticClass();
	}
	if (BaseComponentClass == Noesis::Gui::ExponentialEase::StaticGetClassType() || BaseComponentClass->IsDescendantOf(Noesis::Gui::ExponentialEase::StaticGetClassType()))
	{
		Class = UNoesisExponentialEase::StaticClass();
	}
	if (BaseComponentClass == Noesis::Gui::PowerEase::StaticGetClassType() || BaseComponentClass->IsDescendantOf(Noesis::Gui::PowerEase::StaticGetClassType()))
	{
		Class = UNoesisPowerEase::StaticClass();
	}
	if (BaseComponentClass == Noesis::Gui::QuadraticEase::StaticGetClassType() || BaseComponentClass->IsDescendantOf(Noesis::Gui::QuadraticEase::StaticGetClassType()))
	{
		Class = UNoesisQuadraticEase::StaticClass();
	}
	if (BaseComponentClass == Noesis::Gui::QuarticEase::StaticGetClassType() || BaseComponentClass->IsDescendantOf(Noesis::Gui::QuarticEase::StaticGetClassType()))
	{
		Class = UNoesisQuarticEase::StaticClass();
	}
	if (BaseComponentClass == Noesis::Gui::QuinticEase::StaticGetClassType() || BaseComponentClass->IsDescendantOf(Noesis::Gui::QuinticEase::StaticGetClassType()))
	{
		Class = UNoesisQuinticEase::StaticClass();
	}
	if (BaseComponentClass == Noesis::Gui::SineEase::StaticGetClassType() || BaseComponentClass->IsDescendantOf(Noesis::Gui::SineEase::StaticGetClassType()))
	{
		Class = UNoesisSineEase::StaticClass();
	}
	if (BaseComponentClass == Noesis::Gui::InputBinding::StaticGetClassType() || BaseComponentClass->IsDescendantOf(Noesis::Gui::InputBinding::StaticGetClassType()))
	{
		Class = UNoesisInputBinding::StaticClass();
	}
	if (BaseComponentClass == Noesis::Gui::KeyBinding::StaticGetClassType() || BaseComponentClass->IsDescendantOf(Noesis::Gui::KeyBinding::StaticGetClassType()))
	{
		Class = UNoesisKeyBinding::StaticClass();
	}
	if (BaseComponentClass == Noesis::Gui::Int16KeyFrame::StaticGetClassType() || BaseComponentClass->IsDescendantOf(Noesis::Gui::Int16KeyFrame::StaticGetClassType()))
	{
		Class = UNoesisInt16KeyFrame::StaticClass();
	}
	if (BaseComponentClass == Noesis::Gui::SizeKeyFrame::StaticGetClassType() || BaseComponentClass->IsDescendantOf(Noesis::Gui::SizeKeyFrame::StaticGetClassType()))
	{
		Class = UNoesisSizeKeyFrame::StaticClass();
	}
	if (BaseComponentClass == Noesis::Gui::PointKeyFrame::StaticGetClassType() || BaseComponentClass->IsDescendantOf(Noesis::Gui::PointKeyFrame::StaticGetClassType()))
	{
		Class = UNoesisPointKeyFrame::StaticClass();
	}
	if (BaseComponentClass == Noesis::Gui::ColorKeyFrame::StaticGetClassType() || BaseComponentClass->IsDescendantOf(Noesis::Gui::ColorKeyFrame::StaticGetClassType()))
	{
		Class = UNoesisColorKeyFrame::StaticClass();
	}
	if (BaseComponentClass == Noesis::Gui::ThicknessKeyFrame::StaticGetClassType() || BaseComponentClass->IsDescendantOf(Noesis::Gui::ThicknessKeyFrame::StaticGetClassType()))
	{
		Class = UNoesisThicknessKeyFrame::StaticClass();
	}
	if (BaseComponentClass == Noesis::Gui::ObjectKeyFrame::StaticGetClassType() || BaseComponentClass->IsDescendantOf(Noesis::Gui::ObjectKeyFrame::StaticGetClassType()))
	{
		Class = UNoesisObjectKeyFrame::StaticClass();
	}
	if (BaseComponentClass == Noesis::Gui::Int32KeyFrame::StaticGetClassType() || BaseComponentClass->IsDescendantOf(Noesis::Gui::Int32KeyFrame::StaticGetClassType()))
	{
		Class = UNoesisInt32KeyFrame::StaticClass();
	}
	if (BaseComponentClass == Noesis::Gui::StringKeyFrame::StaticGetClassType() || BaseComponentClass->IsDescendantOf(Noesis::Gui::StringKeyFrame::StaticGetClassType()))
	{
		Class = UNoesisStringKeyFrame::StaticClass();
	}
	if (BaseComponentClass == Noesis::Gui::BooleanKeyFrame::StaticGetClassType() || BaseComponentClass->IsDescendantOf(Noesis::Gui::BooleanKeyFrame::StaticGetClassType()))
	{
		Class = UNoesisBooleanKeyFrame::StaticClass();
	}
	if (BaseComponentClass == Noesis::Gui::RectKeyFrame::StaticGetClassType() || BaseComponentClass->IsDescendantOf(Noesis::Gui::RectKeyFrame::StaticGetClassType()))
	{
		Class = UNoesisRectKeyFrame::StaticClass();
	}
	if (BaseComponentClass == Noesis::Gui::DoubleKeyFrame::StaticGetClassType() || BaseComponentClass->IsDescendantOf(Noesis::Gui::DoubleKeyFrame::StaticGetClassType()))
	{
		Class = UNoesisDoubleKeyFrame::StaticClass();
	}
	if (BaseComponentClass == Noesis::Gui::DiscreteInt16KeyFrame::StaticGetClassType() || BaseComponentClass->IsDescendantOf(Noesis::Gui::DiscreteInt16KeyFrame::StaticGetClassType()))
	{
		Class = UNoesisDiscreteInt16KeyFrame::StaticClass();
	}
	if (BaseComponentClass == Noesis::Gui::DiscreteSizeKeyFrame::StaticGetClassType() || BaseComponentClass->IsDescendantOf(Noesis::Gui::DiscreteSizeKeyFrame::StaticGetClassType()))
	{
		Class = UNoesisDiscreteSizeKeyFrame::StaticClass();
	}
	if (BaseComponentClass == Noesis::Gui::DiscretePointKeyFrame::StaticGetClassType() || BaseComponentClass->IsDescendantOf(Noesis::Gui::DiscretePointKeyFrame::StaticGetClassType()))
	{
		Class = UNoesisDiscretePointKeyFrame::StaticClass();
	}
	if (BaseComponentClass == Noesis::Gui::DiscreteColorKeyFrame::StaticGetClassType() || BaseComponentClass->IsDescendantOf(Noesis::Gui::DiscreteColorKeyFrame::StaticGetClassType()))
	{
		Class = UNoesisDiscreteColorKeyFrame::StaticClass();
	}
	if (BaseComponentClass == Noesis::Gui::DiscreteThicknessKeyFrame::StaticGetClassType() || BaseComponentClass->IsDescendantOf(Noesis::Gui::DiscreteThicknessKeyFrame::StaticGetClassType()))
	{
		Class = UNoesisDiscreteThicknessKeyFrame::StaticClass();
	}
	if (BaseComponentClass == Noesis::Gui::DiscreteObjectKeyFrame::StaticGetClassType() || BaseComponentClass->IsDescendantOf(Noesis::Gui::DiscreteObjectKeyFrame::StaticGetClassType()))
	{
		Class = UNoesisDiscreteObjectKeyFrame::StaticClass();
	}
	if (BaseComponentClass == Noesis::Gui::DiscreteInt32KeyFrame::StaticGetClassType() || BaseComponentClass->IsDescendantOf(Noesis::Gui::DiscreteInt32KeyFrame::StaticGetClassType()))
	{
		Class = UNoesisDiscreteInt32KeyFrame::StaticClass();
	}
	if (BaseComponentClass == Noesis::Gui::DiscreteStringKeyFrame::StaticGetClassType() || BaseComponentClass->IsDescendantOf(Noesis::Gui::DiscreteStringKeyFrame::StaticGetClassType()))
	{
		Class = UNoesisDiscreteStringKeyFrame::StaticClass();
	}
	if (BaseComponentClass == Noesis::Gui::DiscreteBooleanKeyFrame::StaticGetClassType() || BaseComponentClass->IsDescendantOf(Noesis::Gui::DiscreteBooleanKeyFrame::StaticGetClassType()))
	{
		Class = UNoesisDiscreteBooleanKeyFrame::StaticClass();
	}
	if (BaseComponentClass == Noesis::Gui::DiscreteRectKeyFrame::StaticGetClassType() || BaseComponentClass->IsDescendantOf(Noesis::Gui::DiscreteRectKeyFrame::StaticGetClassType()))
	{
		Class = UNoesisDiscreteRectKeyFrame::StaticClass();
	}
	if (BaseComponentClass == Noesis::Gui::DiscreteDoubleKeyFrame::StaticGetClassType() || BaseComponentClass->IsDescendantOf(Noesis::Gui::DiscreteDoubleKeyFrame::StaticGetClassType()))
	{
		Class = UNoesisDiscreteDoubleKeyFrame::StaticClass();
	}
	if (BaseComponentClass == Noesis::Gui::EasingInt32KeyFrame::StaticGetClassType() || BaseComponentClass->IsDescendantOf(Noesis::Gui::EasingInt32KeyFrame::StaticGetClassType()))
	{
		Class = UNoesisEasingInt32KeyFrame::StaticClass();
	}
	if (BaseComponentClass == Noesis::Gui::EasingPointKeyFrame::StaticGetClassType() || BaseComponentClass->IsDescendantOf(Noesis::Gui::EasingPointKeyFrame::StaticGetClassType()))
	{
		Class = UNoesisEasingPointKeyFrame::StaticClass();
	}
	if (BaseComponentClass == Noesis::Gui::EasingColorKeyFrame::StaticGetClassType() || BaseComponentClass->IsDescendantOf(Noesis::Gui::EasingColorKeyFrame::StaticGetClassType()))
	{
		Class = UNoesisEasingColorKeyFrame::StaticClass();
	}
	if (BaseComponentClass == Noesis::Gui::EasingRectKeyFrame::StaticGetClassType() || BaseComponentClass->IsDescendantOf(Noesis::Gui::EasingRectKeyFrame::StaticGetClassType()))
	{
		Class = UNoesisEasingRectKeyFrame::StaticClass();
	}
	if (BaseComponentClass == Noesis::Gui::EasingThicknessKeyFrame::StaticGetClassType() || BaseComponentClass->IsDescendantOf(Noesis::Gui::EasingThicknessKeyFrame::StaticGetClassType()))
	{
		Class = UNoesisEasingThicknessKeyFrame::StaticClass();
	}
	if (BaseComponentClass == Noesis::Gui::EasingSizeKeyFrame::StaticGetClassType() || BaseComponentClass->IsDescendantOf(Noesis::Gui::EasingSizeKeyFrame::StaticGetClassType()))
	{
		Class = UNoesisEasingSizeKeyFrame::StaticClass();
	}
	if (BaseComponentClass == Noesis::Gui::EasingInt16KeyFrame::StaticGetClassType() || BaseComponentClass->IsDescendantOf(Noesis::Gui::EasingInt16KeyFrame::StaticGetClassType()))
	{
		Class = UNoesisEasingInt16KeyFrame::StaticClass();
	}
	if (BaseComponentClass == Noesis::Gui::EasingDoubleKeyFrame::StaticGetClassType() || BaseComponentClass->IsDescendantOf(Noesis::Gui::EasingDoubleKeyFrame::StaticGetClassType()))
	{
		Class = UNoesisEasingDoubleKeyFrame::StaticClass();
	}
	if (BaseComponentClass == Noesis::Gui::LinearInt32KeyFrame::StaticGetClassType() || BaseComponentClass->IsDescendantOf(Noesis::Gui::LinearInt32KeyFrame::StaticGetClassType()))
	{
		Class = UNoesisLinearInt32KeyFrame::StaticClass();
	}
	if (BaseComponentClass == Noesis::Gui::LinearPointKeyFrame::StaticGetClassType() || BaseComponentClass->IsDescendantOf(Noesis::Gui::LinearPointKeyFrame::StaticGetClassType()))
	{
		Class = UNoesisLinearPointKeyFrame::StaticClass();
	}
	if (BaseComponentClass == Noesis::Gui::LinearColorKeyFrame::StaticGetClassType() || BaseComponentClass->IsDescendantOf(Noesis::Gui::LinearColorKeyFrame::StaticGetClassType()))
	{
		Class = UNoesisLinearColorKeyFrame::StaticClass();
	}
	if (BaseComponentClass == Noesis::Gui::LinearRectKeyFrame::StaticGetClassType() || BaseComponentClass->IsDescendantOf(Noesis::Gui::LinearRectKeyFrame::StaticGetClassType()))
	{
		Class = UNoesisLinearRectKeyFrame::StaticClass();
	}
	if (BaseComponentClass == Noesis::Gui::LinearThicknessKeyFrame::StaticGetClassType() || BaseComponentClass->IsDescendantOf(Noesis::Gui::LinearThicknessKeyFrame::StaticGetClassType()))
	{
		Class = UNoesisLinearThicknessKeyFrame::StaticClass();
	}
	if (BaseComponentClass == Noesis::Gui::LinearSizeKeyFrame::StaticGetClassType() || BaseComponentClass->IsDescendantOf(Noesis::Gui::LinearSizeKeyFrame::StaticGetClassType()))
	{
		Class = UNoesisLinearSizeKeyFrame::StaticClass();
	}
	if (BaseComponentClass == Noesis::Gui::LinearInt16KeyFrame::StaticGetClassType() || BaseComponentClass->IsDescendantOf(Noesis::Gui::LinearInt16KeyFrame::StaticGetClassType()))
	{
		Class = UNoesisLinearInt16KeyFrame::StaticClass();
	}
	if (BaseComponentClass == Noesis::Gui::LinearDoubleKeyFrame::StaticGetClassType() || BaseComponentClass->IsDescendantOf(Noesis::Gui::LinearDoubleKeyFrame::StaticGetClassType()))
	{
		Class = UNoesisLinearDoubleKeyFrame::StaticClass();
	}
	if (BaseComponentClass == Noesis::Gui::SplineInt32KeyFrame::StaticGetClassType() || BaseComponentClass->IsDescendantOf(Noesis::Gui::SplineInt32KeyFrame::StaticGetClassType()))
	{
		Class = UNoesisSplineInt32KeyFrame::StaticClass();
	}
	if (BaseComponentClass == Noesis::Gui::SplinePointKeyFrame::StaticGetClassType() || BaseComponentClass->IsDescendantOf(Noesis::Gui::SplinePointKeyFrame::StaticGetClassType()))
	{
		Class = UNoesisSplinePointKeyFrame::StaticClass();
	}
	if (BaseComponentClass == Noesis::Gui::SplineColorKeyFrame::StaticGetClassType() || BaseComponentClass->IsDescendantOf(Noesis::Gui::SplineColorKeyFrame::StaticGetClassType()))
	{
		Class = UNoesisSplineColorKeyFrame::StaticClass();
	}
	if (BaseComponentClass == Noesis::Gui::SplineRectKeyFrame::StaticGetClassType() || BaseComponentClass->IsDescendantOf(Noesis::Gui::SplineRectKeyFrame::StaticGetClassType()))
	{
		Class = UNoesisSplineRectKeyFrame::StaticClass();
	}
	if (BaseComponentClass == Noesis::Gui::SplineThicknessKeyFrame::StaticGetClassType() || BaseComponentClass->IsDescendantOf(Noesis::Gui::SplineThicknessKeyFrame::StaticGetClassType()))
	{
		Class = UNoesisSplineThicknessKeyFrame::StaticClass();
	}
	if (BaseComponentClass == Noesis::Gui::SplineSizeKeyFrame::StaticGetClassType() || BaseComponentClass->IsDescendantOf(Noesis::Gui::SplineSizeKeyFrame::StaticGetClassType()))
	{
		Class = UNoesisSplineSizeKeyFrame::StaticClass();
	}
	if (BaseComponentClass == Noesis::Gui::SplineInt16KeyFrame::StaticGetClassType() || BaseComponentClass->IsDescendantOf(Noesis::Gui::SplineInt16KeyFrame::StaticGetClassType()))
	{
		Class = UNoesisSplineInt16KeyFrame::StaticClass();
	}
	if (BaseComponentClass == Noesis::Gui::SplineDoubleKeyFrame::StaticGetClassType() || BaseComponentClass->IsDescendantOf(Noesis::Gui::SplineDoubleKeyFrame::StaticGetClassType()))
	{
		Class = UNoesisSplineDoubleKeyFrame::StaticClass();
	}
	if (BaseComponentClass == Noesis::Gui::KeySpline::StaticGetClassType() || BaseComponentClass->IsDescendantOf(Noesis::Gui::KeySpline::StaticGetClassType()))
	{
		Class = UNoesisKeySpline::StaticClass();
	}
	if (BaseComponentClass == Noesis::Gui::GridViewColumn::StaticGetClassType() || BaseComponentClass->IsDescendantOf(Noesis::Gui::GridViewColumn::StaticGetClassType()))
	{
		Class = UNoesisGridViewColumn::StaticClass();
	}
	if (BaseComponentClass == Noesis::Gui::TextElement::StaticGetClassType() || BaseComponentClass->IsDescendantOf(Noesis::Gui::TextElement::StaticGetClassType()))
	{
		Class = UNoesisTextElement::StaticClass();
	}
	if (BaseComponentClass == Noesis::Gui::Inline::StaticGetClassType() || BaseComponentClass->IsDescendantOf(Noesis::Gui::Inline::StaticGetClassType()))
	{
		Class = UNoesisInline::StaticClass();
	}
	if (BaseComponentClass == Noesis::Gui::LineBreak::StaticGetClassType() || BaseComponentClass->IsDescendantOf(Noesis::Gui::LineBreak::StaticGetClassType()))
	{
		Class = UNoesisLineBreak::StaticClass();
	}
	if (BaseComponentClass == Noesis::Gui::Run::StaticGetClassType() || BaseComponentClass->IsDescendantOf(Noesis::Gui::Run::StaticGetClassType()))
	{
		Class = UNoesisRun::StaticClass();
	}
	if (BaseComponentClass == Noesis::Gui::TriggerAction::StaticGetClassType() || BaseComponentClass->IsDescendantOf(Noesis::Gui::TriggerAction::StaticGetClassType()))
	{
		Class = UNoesisTriggerAction::StaticClass();
	}
	if (BaseComponentClass == Noesis::Gui::BeginStoryboard::StaticGetClassType() || BaseComponentClass->IsDescendantOf(Noesis::Gui::BeginStoryboard::StaticGetClassType()))
	{
		Class = UNoesisBeginStoryboard::StaticClass();
	}
	if (BaseComponentClass == Noesis::Gui::ControllableStoryboardAction::StaticGetClassType() || BaseComponentClass->IsDescendantOf(Noesis::Gui::ControllableStoryboardAction::StaticGetClassType()))
	{
		Class = UNoesisControllableStoryboardAction::StaticClass();
	}
	if (BaseComponentClass == Noesis::Gui::PauseStoryboard::StaticGetClassType() || BaseComponentClass->IsDescendantOf(Noesis::Gui::PauseStoryboard::StaticGetClassType()))
	{
		Class = UNoesisPauseStoryboard::StaticClass();
	}
	if (BaseComponentClass == Noesis::Gui::ResumeStoryboard::StaticGetClassType() || BaseComponentClass->IsDescendantOf(Noesis::Gui::ResumeStoryboard::StaticGetClassType()))
	{
		Class = UNoesisResumeStoryboard::StaticClass();
	}
	if (BaseComponentClass == Noesis::Gui::StopStoryboard::StaticGetClassType() || BaseComponentClass->IsDescendantOf(Noesis::Gui::StopStoryboard::StaticGetClassType()))
	{
		Class = UNoesisStopStoryboard::StaticClass();
	}
	if (BaseComponentClass == Noesis::Gui::Visual::StaticGetClassType() || BaseComponentClass->IsDescendantOf(Noesis::Gui::Visual::StaticGetClassType()))
	{
		Class = UNoesisVisual::StaticClass();
	}
	if (BaseComponentClass == Noesis::Gui::UIElement::StaticGetClassType() || BaseComponentClass->IsDescendantOf(Noesis::Gui::UIElement::StaticGetClassType()))
	{
		Class = UNoesisUIElement::StaticClass();
	}
	if (BaseComponentClass == Noesis::Gui::FrameworkElement::StaticGetClassType() || BaseComponentClass->IsDescendantOf(Noesis::Gui::FrameworkElement::StaticGetClassType()))
	{
		Class = UNoesisFrameworkElement::StaticClass();
	}
	if (BaseComponentClass == Noesis::Gui::BaseDefinition::StaticGetClassType() || BaseComponentClass->IsDescendantOf(Noesis::Gui::BaseDefinition::StaticGetClassType()))
	{
		Class = UNoesisBaseDefinition::StaticClass();
	}
	if (BaseComponentClass == Noesis::Gui::ColumnDefinition::StaticGetClassType() || BaseComponentClass->IsDescendantOf(Noesis::Gui::ColumnDefinition::StaticGetClassType()))
	{
		Class = UNoesisColumnDefinition::StaticClass();
	}
	if (BaseComponentClass == Noesis::Gui::RowDefinition::StaticGetClassType() || BaseComponentClass->IsDescendantOf(Noesis::Gui::RowDefinition::StaticGetClassType()))
	{
		Class = UNoesisRowDefinition::StaticClass();
	}
	if (BaseComponentClass == Noesis::Gui::BaseGridViewRowPresenter::StaticGetClassType() || BaseComponentClass->IsDescendantOf(Noesis::Gui::BaseGridViewRowPresenter::StaticGetClassType()))
	{
		Class = UNoesisBaseGridViewRowPresenter::StaticClass();
	}
	if (BaseComponentClass == Noesis::Gui::GridViewHeaderRowPresenter::StaticGetClassType() || BaseComponentClass->IsDescendantOf(Noesis::Gui::GridViewHeaderRowPresenter::StaticGetClassType()))
	{
		Class = UNoesisGridViewHeaderRowPresenter::StaticClass();
	}
	if (BaseComponentClass == Noesis::Gui::GridViewRowPresenter::StaticGetClassType() || BaseComponentClass->IsDescendantOf(Noesis::Gui::GridViewRowPresenter::StaticGetClassType()))
	{
		Class = UNoesisGridViewRowPresenter::StaticClass();
	}
	if (BaseComponentClass == Noesis::Gui::ContentPresenter::StaticGetClassType() || BaseComponentClass->IsDescendantOf(Noesis::Gui::ContentPresenter::StaticGetClassType()))
	{
		Class = UNoesisContentPresenter::StaticClass();
	}
	if (BaseComponentClass == Noesis::Gui::ScrollContentPresenter::StaticGetClassType() || BaseComponentClass->IsDescendantOf(Noesis::Gui::ScrollContentPresenter::StaticGetClassType()))
	{
		Class = UNoesisScrollContentPresenter::StaticClass();
	}
	if (BaseComponentClass == Noesis::Gui::Control::StaticGetClassType() || BaseComponentClass->IsDescendantOf(Noesis::Gui::Control::StaticGetClassType()))
	{
		Class = UNoesisControl::StaticClass();
	}
	if (BaseComponentClass == Noesis::Gui::BaseTextBox::StaticGetClassType() || BaseComponentClass->IsDescendantOf(Noesis::Gui::BaseTextBox::StaticGetClassType()))
	{
		Class = UNoesisBaseTextBox::StaticClass();
	}
	if (BaseComponentClass == Noesis::Gui::TextBox::StaticGetClassType() || BaseComponentClass->IsDescendantOf(Noesis::Gui::TextBox::StaticGetClassType()))
	{
		Class = UNoesisTextBox::StaticClass();
	}
	if (BaseComponentClass == Noesis::Gui::ContentControl::StaticGetClassType() || BaseComponentClass->IsDescendantOf(Noesis::Gui::ContentControl::StaticGetClassType()))
	{
		Class = UNoesisContentControl::StaticClass();
	}
	if (BaseComponentClass == Noesis::Gui::BaseButton::StaticGetClassType() || BaseComponentClass->IsDescendantOf(Noesis::Gui::BaseButton::StaticGetClassType()))
	{
		Class = UNoesisBaseButton::StaticClass();
	}
	if (BaseComponentClass == Noesis::Gui::Button::StaticGetClassType() || BaseComponentClass->IsDescendantOf(Noesis::Gui::Button::StaticGetClassType()))
	{
		Class = UNoesisButton::StaticClass();
	}
	if (BaseComponentClass == Noesis::Gui::GridViewColumnHeader::StaticGetClassType() || BaseComponentClass->IsDescendantOf(Noesis::Gui::GridViewColumnHeader::StaticGetClassType()))
	{
		Class = UNoesisGridViewColumnHeader::StaticClass();
	}
	if (BaseComponentClass == Noesis::Gui::RepeatButton::StaticGetClassType() || BaseComponentClass->IsDescendantOf(Noesis::Gui::RepeatButton::StaticGetClassType()))
	{
		Class = UNoesisRepeatButton::StaticClass();
	}
	if (BaseComponentClass == Noesis::Gui::ToggleButton::StaticGetClassType() || BaseComponentClass->IsDescendantOf(Noesis::Gui::ToggleButton::StaticGetClassType()))
	{
		Class = UNoesisToggleButton::StaticClass();
	}
	if (BaseComponentClass == Noesis::Gui::CheckBox::StaticGetClassType() || BaseComponentClass->IsDescendantOf(Noesis::Gui::CheckBox::StaticGetClassType()))
	{
		Class = UNoesisCheckBox::StaticClass();
	}
	if (BaseComponentClass == Noesis::Gui::RadioButton::StaticGetClassType() || BaseComponentClass->IsDescendantOf(Noesis::Gui::RadioButton::StaticGetClassType()))
	{
		Class = UNoesisRadioButton::StaticClass();
	}
	if (BaseComponentClass == Noesis::Gui::HeaderedContentControl::StaticGetClassType() || BaseComponentClass->IsDescendantOf(Noesis::Gui::HeaderedContentControl::StaticGetClassType()))
	{
		Class = UNoesisHeaderedContentControl::StaticClass();
	}
	if (BaseComponentClass == Noesis::Gui::Expander::StaticGetClassType() || BaseComponentClass->IsDescendantOf(Noesis::Gui::Expander::StaticGetClassType()))
	{
		Class = UNoesisExpander::StaticClass();
	}
	if (BaseComponentClass == Noesis::Gui::GroupBox::StaticGetClassType() || BaseComponentClass->IsDescendantOf(Noesis::Gui::GroupBox::StaticGetClassType()))
	{
		Class = UNoesisGroupBox::StaticClass();
	}
	if (BaseComponentClass == Noesis::Gui::TabItem::StaticGetClassType() || BaseComponentClass->IsDescendantOf(Noesis::Gui::TabItem::StaticGetClassType()))
	{
		Class = UNoesisTabItem::StaticClass();
	}
	if (BaseComponentClass == Noesis::Gui::Label::StaticGetClassType() || BaseComponentClass->IsDescendantOf(Noesis::Gui::Label::StaticGetClassType()))
	{
		Class = UNoesisLabel::StaticClass();
	}
	if (BaseComponentClass == Noesis::Gui::ListBoxItem::StaticGetClassType() || BaseComponentClass->IsDescendantOf(Noesis::Gui::ListBoxItem::StaticGetClassType()))
	{
		Class = UNoesisListBoxItem::StaticClass();
	}
	if (BaseComponentClass == Noesis::Gui::ComboBoxItem::StaticGetClassType() || BaseComponentClass->IsDescendantOf(Noesis::Gui::ComboBoxItem::StaticGetClassType()))
	{
		Class = UNoesisComboBoxItem::StaticClass();
	}
	if (BaseComponentClass == Noesis::Gui::ListViewItem::StaticGetClassType() || BaseComponentClass->IsDescendantOf(Noesis::Gui::ListViewItem::StaticGetClassType()))
	{
		Class = UNoesisListViewItem::StaticClass();
	}
	if (BaseComponentClass == Noesis::Gui::ScrollViewer::StaticGetClassType() || BaseComponentClass->IsDescendantOf(Noesis::Gui::ScrollViewer::StaticGetClassType()))
	{
		Class = UNoesisScrollViewer::StaticClass();
	}
	if (BaseComponentClass == Noesis::Gui::StatusBarItem::StaticGetClassType() || BaseComponentClass->IsDescendantOf(Noesis::Gui::StatusBarItem::StaticGetClassType()))
	{
		Class = UNoesisStatusBarItem::StaticClass();
	}
	if (BaseComponentClass == Noesis::Gui::ToolTip::StaticGetClassType() || BaseComponentClass->IsDescendantOf(Noesis::Gui::ToolTip::StaticGetClassType()))
	{
		Class = UNoesisToolTip::StaticClass();
	}
	if (BaseComponentClass == Noesis::Gui::UserControl::StaticGetClassType() || BaseComponentClass->IsDescendantOf(Noesis::Gui::UserControl::StaticGetClassType()))
	{
		Class = UNoesisUserControl::StaticClass();
	}
	if (BaseComponentClass == Noesis::Gui::Page::StaticGetClassType() || BaseComponentClass->IsDescendantOf(Noesis::Gui::Page::StaticGetClassType()))
	{
		Class = UNoesisPage::StaticClass();
	}
	if (BaseComponentClass == Noesis::Gui::ItemsControl::StaticGetClassType() || BaseComponentClass->IsDescendantOf(Noesis::Gui::ItemsControl::StaticGetClassType()))
	{
		Class = UNoesisItemsControl::StaticClass();
	}
	if (BaseComponentClass == Noesis::Gui::BaseMenu::StaticGetClassType() || BaseComponentClass->IsDescendantOf(Noesis::Gui::BaseMenu::StaticGetClassType()))
	{
		Class = UNoesisBaseMenu::StaticClass();
	}
	if (BaseComponentClass == Noesis::Gui::ContextMenu::StaticGetClassType() || BaseComponentClass->IsDescendantOf(Noesis::Gui::ContextMenu::StaticGetClassType()))
	{
		Class = UNoesisContextMenu::StaticClass();
	}
	if (BaseComponentClass == Noesis::Gui::Menu::StaticGetClassType() || BaseComponentClass->IsDescendantOf(Noesis::Gui::Menu::StaticGetClassType()))
	{
		Class = UNoesisMenu::StaticClass();
	}
	if (BaseComponentClass == Noesis::Gui::HeaderedItemsControl::StaticGetClassType() || BaseComponentClass->IsDescendantOf(Noesis::Gui::HeaderedItemsControl::StaticGetClassType()))
	{
		Class = UNoesisHeaderedItemsControl::StaticClass();
	}
	if (BaseComponentClass == Noesis::Gui::MenuItem::StaticGetClassType() || BaseComponentClass->IsDescendantOf(Noesis::Gui::MenuItem::StaticGetClassType()))
	{
		Class = UNoesisMenuItem::StaticClass();
	}
	if (BaseComponentClass == Noesis::Gui::ToolBar::StaticGetClassType() || BaseComponentClass->IsDescendantOf(Noesis::Gui::ToolBar::StaticGetClassType()))
	{
		Class = UNoesisToolBar::StaticClass();
	}
	if (BaseComponentClass == Noesis::Gui::TreeViewItem::StaticGetClassType() || BaseComponentClass->IsDescendantOf(Noesis::Gui::TreeViewItem::StaticGetClassType()))
	{
		Class = UNoesisTreeViewItem::StaticClass();
	}
	if (BaseComponentClass == Noesis::Gui::Selector::StaticGetClassType() || BaseComponentClass->IsDescendantOf(Noesis::Gui::Selector::StaticGetClassType()))
	{
		Class = UNoesisSelector::StaticClass();
	}
	if (BaseComponentClass == Noesis::Gui::ComboBox::StaticGetClassType() || BaseComponentClass->IsDescendantOf(Noesis::Gui::ComboBox::StaticGetClassType()))
	{
		Class = UNoesisComboBox::StaticClass();
	}
	if (BaseComponentClass == Noesis::Gui::ListBox::StaticGetClassType() || BaseComponentClass->IsDescendantOf(Noesis::Gui::ListBox::StaticGetClassType()))
	{
		Class = UNoesisListBox::StaticClass();
	}
	if (BaseComponentClass == Noesis::Gui::ListView::StaticGetClassType() || BaseComponentClass->IsDescendantOf(Noesis::Gui::ListView::StaticGetClassType()))
	{
		Class = UNoesisListView::StaticClass();
	}
	if (BaseComponentClass == Noesis::Gui::TabControl::StaticGetClassType() || BaseComponentClass->IsDescendantOf(Noesis::Gui::TabControl::StaticGetClassType()))
	{
		Class = UNoesisTabControl::StaticClass();
	}
	if (BaseComponentClass == Noesis::Gui::StatusBar::StaticGetClassType() || BaseComponentClass->IsDescendantOf(Noesis::Gui::StatusBar::StaticGetClassType()))
	{
		Class = UNoesisStatusBar::StaticClass();
	}
	if (BaseComponentClass == Noesis::Gui::TreeView::StaticGetClassType() || BaseComponentClass->IsDescendantOf(Noesis::Gui::TreeView::StaticGetClassType()))
	{
		Class = UNoesisTreeView::StaticClass();
	}
	if (BaseComponentClass == Noesis::Gui::PasswordBox::StaticGetClassType() || BaseComponentClass->IsDescendantOf(Noesis::Gui::PasswordBox::StaticGetClassType()))
	{
		Class = UNoesisPasswordBox::StaticClass();
	}
	if (BaseComponentClass == Noesis::Gui::RangeBase::StaticGetClassType() || BaseComponentClass->IsDescendantOf(Noesis::Gui::RangeBase::StaticGetClassType()))
	{
		Class = UNoesisRangeBase::StaticClass();
	}
	if (BaseComponentClass == Noesis::Gui::ProgressBar::StaticGetClassType() || BaseComponentClass->IsDescendantOf(Noesis::Gui::ProgressBar::StaticGetClassType()))
	{
		Class = UNoesisProgressBar::StaticClass();
	}
	if (BaseComponentClass == Noesis::Gui::ScrollBar::StaticGetClassType() || BaseComponentClass->IsDescendantOf(Noesis::Gui::ScrollBar::StaticGetClassType()))
	{
		Class = UNoesisScrollBar::StaticClass();
	}
	if (BaseComponentClass == Noesis::Gui::Slider::StaticGetClassType() || BaseComponentClass->IsDescendantOf(Noesis::Gui::Slider::StaticGetClassType()))
	{
		Class = UNoesisSlider::StaticClass();
	}
	if (BaseComponentClass == Noesis::Gui::Separator::StaticGetClassType() || BaseComponentClass->IsDescendantOf(Noesis::Gui::Separator::StaticGetClassType()))
	{
		Class = UNoesisSeparator::StaticClass();
	}
	if (BaseComponentClass == Noesis::Gui::Thumb::StaticGetClassType() || BaseComponentClass->IsDescendantOf(Noesis::Gui::Thumb::StaticGetClassType()))
	{
		Class = UNoesisThumb::StaticClass();
	}
	if (BaseComponentClass == Noesis::Gui::Decorator::StaticGetClassType() || BaseComponentClass->IsDescendantOf(Noesis::Gui::Decorator::StaticGetClassType()))
	{
		Class = UNoesisDecorator::StaticClass();
	}
	if (BaseComponentClass == Noesis::Gui::AdornerDecorator::StaticGetClassType() || BaseComponentClass->IsDescendantOf(Noesis::Gui::AdornerDecorator::StaticGetClassType()))
	{
		Class = UNoesisAdornerDecorator::StaticClass();
	}
	if (BaseComponentClass == Noesis::Gui::Border::StaticGetClassType() || BaseComponentClass->IsDescendantOf(Noesis::Gui::Border::StaticGetClassType()))
	{
		Class = UNoesisBorder::StaticClass();
	}
	if (BaseComponentClass == Noesis::Gui::BulletDecorator::StaticGetClassType() || BaseComponentClass->IsDescendantOf(Noesis::Gui::BulletDecorator::StaticGetClassType()))
	{
		Class = UNoesisBulletDecorator::StaticClass();
	}
	if (BaseComponentClass == Noesis::Gui::Image::StaticGetClassType() || BaseComponentClass->IsDescendantOf(Noesis::Gui::Image::StaticGetClassType()))
	{
		Class = UNoesisImage::StaticClass();
	}
	if (BaseComponentClass == Noesis::Gui::ItemsPresenter::StaticGetClassType() || BaseComponentClass->IsDescendantOf(Noesis::Gui::ItemsPresenter::StaticGetClassType()))
	{
		Class = UNoesisItemsPresenter::StaticClass();
	}
	if (BaseComponentClass == Noesis::Gui::Panel::StaticGetClassType() || BaseComponentClass->IsDescendantOf(Noesis::Gui::Panel::StaticGetClassType()))
	{
		Class = UNoesisPanel::StaticClass();
	}
	if (BaseComponentClass == Noesis::Gui::Canvas::StaticGetClassType() || BaseComponentClass->IsDescendantOf(Noesis::Gui::Canvas::StaticGetClassType()))
	{
		Class = UNoesisCanvas::StaticClass();
	}
	if (BaseComponentClass == Noesis::Gui::DockPanel::StaticGetClassType() || BaseComponentClass->IsDescendantOf(Noesis::Gui::DockPanel::StaticGetClassType()))
	{
		Class = UNoesisDockPanel::StaticClass();
	}
	if (BaseComponentClass == Noesis::Gui::Grid::StaticGetClassType() || BaseComponentClass->IsDescendantOf(Noesis::Gui::Grid::StaticGetClassType()))
	{
		Class = UNoesisGrid::StaticClass();
	}
	if (BaseComponentClass == Noesis::Gui::StackPanel::StaticGetClassType() || BaseComponentClass->IsDescendantOf(Noesis::Gui::StackPanel::StaticGetClassType()))
	{
		Class = UNoesisStackPanel::StaticClass();
	}
	if (BaseComponentClass == Noesis::Gui::ToolBarPanel::StaticGetClassType() || BaseComponentClass->IsDescendantOf(Noesis::Gui::ToolBarPanel::StaticGetClassType()))
	{
		Class = UNoesisToolBarPanel::StaticClass();
	}
	if (BaseComponentClass == Noesis::Gui::TabPanel::StaticGetClassType() || BaseComponentClass->IsDescendantOf(Noesis::Gui::TabPanel::StaticGetClassType()))
	{
		Class = UNoesisTabPanel::StaticClass();
	}
	if (BaseComponentClass == Noesis::Gui::ToolBarOverflowPanel::StaticGetClassType() || BaseComponentClass->IsDescendantOf(Noesis::Gui::ToolBarOverflowPanel::StaticGetClassType()))
	{
		Class = UNoesisToolBarOverflowPanel::StaticClass();
	}
	if (BaseComponentClass == Noesis::Gui::UniformGrid::StaticGetClassType() || BaseComponentClass->IsDescendantOf(Noesis::Gui::UniformGrid::StaticGetClassType()))
	{
		Class = UNoesisUniformGrid::StaticClass();
	}
	if (BaseComponentClass == Noesis::Gui::VirtualizingPanel::StaticGetClassType() || BaseComponentClass->IsDescendantOf(Noesis::Gui::VirtualizingPanel::StaticGetClassType()))
	{
		Class = UNoesisVirtualizingPanel::StaticClass();
	}
	if (BaseComponentClass == Noesis::Gui::VirtualizingStackPanel::StaticGetClassType() || BaseComponentClass->IsDescendantOf(Noesis::Gui::VirtualizingStackPanel::StaticGetClassType()))
	{
		Class = UNoesisVirtualizingStackPanel::StaticClass();
	}
	if (BaseComponentClass == Noesis::Gui::WrapPanel::StaticGetClassType() || BaseComponentClass->IsDescendantOf(Noesis::Gui::WrapPanel::StaticGetClassType()))
	{
		Class = UNoesisWrapPanel::StaticClass();
	}
	if (BaseComponentClass == Noesis::Gui::Popup::StaticGetClassType() || BaseComponentClass->IsDescendantOf(Noesis::Gui::Popup::StaticGetClassType()))
	{
		Class = UNoesisPopup::StaticClass();
	}
	if (BaseComponentClass == Noesis::Gui::Shape::StaticGetClassType() || BaseComponentClass->IsDescendantOf(Noesis::Gui::Shape::StaticGetClassType()))
	{
		Class = UNoesisShape::StaticClass();
	}
	if (BaseComponentClass == Noesis::Gui::Ellipse::StaticGetClassType() || BaseComponentClass->IsDescendantOf(Noesis::Gui::Ellipse::StaticGetClassType()))
	{
		Class = UNoesisEllipse::StaticClass();
	}
	if (BaseComponentClass == Noesis::Gui::Line::StaticGetClassType() || BaseComponentClass->IsDescendantOf(Noesis::Gui::Line::StaticGetClassType()))
	{
		Class = UNoesisLine::StaticClass();
	}
	if (BaseComponentClass == Noesis::Gui::Path::StaticGetClassType() || BaseComponentClass->IsDescendantOf(Noesis::Gui::Path::StaticGetClassType()))
	{
		Class = UNoesisPath::StaticClass();
	}
	if (BaseComponentClass == Noesis::Gui::Rectangle::StaticGetClassType() || BaseComponentClass->IsDescendantOf(Noesis::Gui::Rectangle::StaticGetClassType()))
	{
		Class = UNoesisRectangle::StaticClass();
	}
	if (BaseComponentClass == Noesis::Gui::TextBlock::StaticGetClassType() || BaseComponentClass->IsDescendantOf(Noesis::Gui::TextBlock::StaticGetClassType()))
	{
		Class = UNoesisTextBlock::StaticClass();
	}
	if (BaseComponentClass == Noesis::Gui::TickBar::StaticGetClassType() || BaseComponentClass->IsDescendantOf(Noesis::Gui::TickBar::StaticGetClassType()))
	{
		Class = UNoesisTickBar::StaticClass();
	}
	if (BaseComponentClass == Noesis::Gui::ToolBarTray::StaticGetClassType() || BaseComponentClass->IsDescendantOf(Noesis::Gui::ToolBarTray::StaticGetClassType()))
	{
		Class = UNoesisToolBarTray::StaticClass();
	}
	if (BaseComponentClass == Noesis::Gui::Track::StaticGetClassType() || BaseComponentClass->IsDescendantOf(Noesis::Gui::Track::StaticGetClassType()))
	{
		Class = UNoesisTrack::StaticClass();
	}
	if (BaseComponentClass == Noesis::Gui::Viewbox::StaticGetClassType() || BaseComponentClass->IsDescendantOf(Noesis::Gui::Viewbox::StaticGetClassType()))
	{
		Class = UNoesisViewbox::StaticClass();
	}
	if (BaseComponentClass == Noesis::Gui::VisualState::StaticGetClassType() || BaseComponentClass->IsDescendantOf(Noesis::Gui::VisualState::StaticGetClassType()))
	{
		Class = UNoesisVisualState::StaticClass();
	}
	if (BaseComponentClass == Noesis::Gui::VisualStateGroup::StaticGetClassType() || BaseComponentClass->IsDescendantOf(Noesis::Gui::VisualStateGroup::StaticGetClassType()))
	{
		Class = UNoesisVisualStateGroup::StaticClass();
	}
	if (BaseComponentClass == Noesis::Gui::VisualTransition::StaticGetClassType() || BaseComponentClass->IsDescendantOf(Noesis::Gui::VisualTransition::StaticGetClassType()))
	{
		Class = UNoesisVisualTransition::StaticClass();
	}
	if (BaseComponentClass == Noesis::Gui::DependencyProperty::StaticGetClassType() || BaseComponentClass->IsDescendantOf(Noesis::Gui::DependencyProperty::StaticGetClassType()))
	{
		Class = UNoesisDependencyProperty::StaticClass();
	}
	if (BaseComponentClass == Noesis::Gui::Expression::StaticGetClassType() || BaseComponentClass->IsDescendantOf(Noesis::Gui::Expression::StaticGetClassType()))
	{
		Class = UNoesisExpression::StaticClass();
	}
	if (BaseComponentClass == Noesis::Gui::BaseBindingExpression::StaticGetClassType() || BaseComponentClass->IsDescendantOf(Noesis::Gui::BaseBindingExpression::StaticGetClassType()))
	{
		Class = UNoesisBaseBindingExpression::StaticClass();
	}
	if (BaseComponentClass == Noesis::Gui::BindingExpression::StaticGetClassType() || BaseComponentClass->IsDescendantOf(Noesis::Gui::BindingExpression::StaticGetClassType()))
	{
		Class = UNoesisBindingExpression::StaticClass();
	}
	if (BaseComponentClass == Noesis::Gui::TemplateBindingExpression::StaticGetClassType() || BaseComponentClass->IsDescendantOf(Noesis::Gui::TemplateBindingExpression::StaticGetClassType()))
	{
		Class = UNoesisTemplateBindingExpression::StaticClass();
	}
	if (BaseComponentClass == Noesis::Gui::FontFamily::StaticGetClassType() || BaseComponentClass->IsDescendantOf(Noesis::Gui::FontFamily::StaticGetClassType()))
	{
		Class = UNoesisFontFamily::StaticClass();
	}
	if (BaseComponentClass == Noesis::Gui::FrameworkTemplate::StaticGetClassType() || BaseComponentClass->IsDescendantOf(Noesis::Gui::FrameworkTemplate::StaticGetClassType()))
	{
		Class = UNoesisFrameworkTemplate::StaticClass();
	}
	if (BaseComponentClass == Noesis::Gui::ControlTemplate::StaticGetClassType() || BaseComponentClass->IsDescendantOf(Noesis::Gui::ControlTemplate::StaticGetClassType()))
	{
		Class = UNoesisControlTemplate::StaticClass();
	}
	if (BaseComponentClass == Noesis::Gui::DataTemplate::StaticGetClassType() || BaseComponentClass->IsDescendantOf(Noesis::Gui::DataTemplate::StaticGetClassType()))
	{
		Class = UNoesisDataTemplate::StaticClass();
	}
	if (BaseComponentClass == Noesis::Gui::HierarchicalDataTemplate::StaticGetClassType() || BaseComponentClass->IsDescendantOf(Noesis::Gui::HierarchicalDataTemplate::StaticGetClassType()))
	{
		Class = UNoesisHierarchicalDataTemplate::StaticClass();
	}
	if (BaseComponentClass == Noesis::Gui::ItemsPanelTemplate::StaticGetClassType() || BaseComponentClass->IsDescendantOf(Noesis::Gui::ItemsPanelTemplate::StaticGetClassType()))
	{
		Class = UNoesisItemsPanelTemplate::StaticClass();
	}
	if (BaseComponentClass == Noesis::Gui::GradientStopCollection::StaticGetClassType() || BaseComponentClass->IsDescendantOf(Noesis::Gui::GradientStopCollection::StaticGetClassType()))
	{
		Class = UNoesisGradientStopCollection::StaticClass();
	}
	if (BaseComponentClass == Noesis::Gui::InputGesture::StaticGetClassType() || BaseComponentClass->IsDescendantOf(Noesis::Gui::InputGesture::StaticGetClassType()))
	{
		Class = UNoesisInputGesture::StaticClass();
	}
	if (BaseComponentClass == Noesis::Gui::KeyGesture::StaticGetClassType() || BaseComponentClass->IsDescendantOf(Noesis::Gui::KeyGesture::StaticGetClassType()))
	{
		Class = UNoesisKeyGesture::StaticClass();
	}
	if (BaseComponentClass == Noesis::Gui::ItemCollection::StaticGetClassType() || BaseComponentClass->IsDescendantOf(Noesis::Gui::ItemCollection::StaticGetClassType()))
	{
		Class = UNoesisItemCollection::StaticClass();
	}
	if (BaseComponentClass == Noesis::Gui::ItemContainerGenerator::StaticGetClassType() || BaseComponentClass->IsDescendantOf(Noesis::Gui::ItemContainerGenerator::StaticGetClassType()))
	{
		Class = UNoesisItemContainerGenerator::StaticClass();
	}
	if (BaseComponentClass == Noesis::Gui::Keyboard::StaticGetClassType() || BaseComponentClass->IsDescendantOf(Noesis::Gui::Keyboard::StaticGetClassType()))
	{
		Class = UNoesisKeyboard::StaticClass();
	}
	if (BaseComponentClass == Noesis::Gui::KeyboardNavigation::StaticGetClassType() || BaseComponentClass->IsDescendantOf(Noesis::Gui::KeyboardNavigation::StaticGetClassType()))
	{
		Class = UNoesisKeyboardNavigation::StaticClass();
	}
	if (BaseComponentClass == Noesis::Gui::Mouse::StaticGetClassType() || BaseComponentClass->IsDescendantOf(Noesis::Gui::Mouse::StaticGetClassType()))
	{
		Class = UNoesisMouse::StaticClass();
	}
	if (BaseComponentClass == Noesis::Gui::PropertyMetadata::StaticGetClassType() || BaseComponentClass->IsDescendantOf(Noesis::Gui::PropertyMetadata::StaticGetClassType()))
	{
		Class = UNoesisPropertyMetadata::StaticClass();
	}
	if (BaseComponentClass == Noesis::Gui::PropertyPath::StaticGetClassType() || BaseComponentClass->IsDescendantOf(Noesis::Gui::PropertyPath::StaticGetClassType()))
	{
		Class = UNoesisPropertyPath::StaticClass();
	}
	if (BaseComponentClass == Noesis::Gui::RelativeSource::StaticGetClassType() || BaseComponentClass->IsDescendantOf(Noesis::Gui::RelativeSource::StaticGetClassType()))
	{
		Class = UNoesisRelativeSource::StaticClass();
	}
	if (BaseComponentClass == Noesis::Gui::ResourceKeyType::StaticGetClassType() || BaseComponentClass->IsDescendantOf(Noesis::Gui::ResourceKeyType::StaticGetClassType()))
	{
		Class = UNoesisResourceKeyType::StaticClass();
	}
	if (BaseComponentClass == Noesis::Gui::RoutedCommand::StaticGetClassType() || BaseComponentClass->IsDescendantOf(Noesis::Gui::RoutedCommand::StaticGetClassType()))
	{
		Class = UNoesisRoutedCommand::StaticClass();
	}
	if (BaseComponentClass == Noesis::Gui::RoutedUICommand::StaticGetClassType() || BaseComponentClass->IsDescendantOf(Noesis::Gui::RoutedUICommand::StaticGetClassType()))
	{
		Class = UNoesisRoutedUICommand::StaticClass();
	}
	if (BaseComponentClass == Noesis::Gui::RoutedEvent::StaticGetClassType() || BaseComponentClass->IsDescendantOf(Noesis::Gui::RoutedEvent::StaticGetClassType()))
	{
		Class = UNoesisRoutedEvent::StaticClass();
	}
	if (BaseComponentClass == Noesis::Gui::Style::StaticGetClassType() || BaseComponentClass->IsDescendantOf(Noesis::Gui::Style::StaticGetClassType()))
	{
		Class = UNoesisStyle::StaticClass();
	}
	if (BaseComponentClass == Noesis::Gui::TemplateBindingExtension::StaticGetClassType() || BaseComponentClass->IsDescendantOf(Noesis::Gui::TemplateBindingExtension::StaticGetClassType()))
	{
		Class = UNoesisTemplateBindingExtension::StaticClass();
	}
	if (BaseComponentClass == Noesis::Gui::ToolTipService::StaticGetClassType() || BaseComponentClass->IsDescendantOf(Noesis::Gui::ToolTipService::StaticGetClassType()))
	{
		Class = UNoesisToolTipService::StaticClass();
	}
	if (BaseComponentClass == Noesis::Gui::ThicknessKeyFrameCollection::StaticGetClassType() || BaseComponentClass->IsDescendantOf(Noesis::Gui::ThicknessKeyFrameCollection::StaticGetClassType()))
	{
		Class = UNoesisThicknessKeyFrameCollection::StaticClass();
	}
	if (BaseComponentClass == Noesis::Gui::ColorKeyFrameCollection::StaticGetClassType() || BaseComponentClass->IsDescendantOf(Noesis::Gui::ColorKeyFrameCollection::StaticGetClassType()))
	{
		Class = UNoesisColorKeyFrameCollection::StaticClass();
	}
	if (BaseComponentClass == Noesis::Gui::SizeKeyFrameCollection::StaticGetClassType() || BaseComponentClass->IsDescendantOf(Noesis::Gui::SizeKeyFrameCollection::StaticGetClassType()))
	{
		Class = UNoesisSizeKeyFrameCollection::StaticClass();
	}
	if (BaseComponentClass == Noesis::Gui::ObjectKeyFrameCollection::StaticGetClassType() || BaseComponentClass->IsDescendantOf(Noesis::Gui::ObjectKeyFrameCollection::StaticGetClassType()))
	{
		Class = UNoesisObjectKeyFrameCollection::StaticClass();
	}
	if (BaseComponentClass == Noesis::Gui::BooleanKeyFrameCollection::StaticGetClassType() || BaseComponentClass->IsDescendantOf(Noesis::Gui::BooleanKeyFrameCollection::StaticGetClassType()))
	{
		Class = UNoesisBooleanKeyFrameCollection::StaticClass();
	}
	if (BaseComponentClass == Noesis::Gui::TransformCollection::StaticGetClassType() || BaseComponentClass->IsDescendantOf(Noesis::Gui::TransformCollection::StaticGetClassType()))
	{
		Class = UNoesisTransformCollection::StaticClass();
	}
	if (BaseComponentClass == Noesis::Gui::Int32KeyFrameCollection::StaticGetClassType() || BaseComponentClass->IsDescendantOf(Noesis::Gui::Int32KeyFrameCollection::StaticGetClassType()))
	{
		Class = UNoesisInt32KeyFrameCollection::StaticClass();
	}
	if (BaseComponentClass == Noesis::Gui::DoubleKeyFrameCollection::StaticGetClassType() || BaseComponentClass->IsDescendantOf(Noesis::Gui::DoubleKeyFrameCollection::StaticGetClassType()))
	{
		Class = UNoesisDoubleKeyFrameCollection::StaticClass();
	}
	if (BaseComponentClass == Noesis::Gui::Int16KeyFrameCollection::StaticGetClassType() || BaseComponentClass->IsDescendantOf(Noesis::Gui::Int16KeyFrameCollection::StaticGetClassType()))
	{
		Class = UNoesisInt16KeyFrameCollection::StaticClass();
	}
	if (BaseComponentClass == Noesis::Gui::TimelineCollection::StaticGetClassType() || BaseComponentClass->IsDescendantOf(Noesis::Gui::TimelineCollection::StaticGetClassType()))
	{
		Class = UNoesisTimelineCollection::StaticClass();
	}
	if (BaseComponentClass == Noesis::Gui::GeometryCollection::StaticGetClassType() || BaseComponentClass->IsDescendantOf(Noesis::Gui::GeometryCollection::StaticGetClassType()))
	{
		Class = UNoesisGeometryCollection::StaticClass();
	}
	if (BaseComponentClass == Noesis::Gui::StringKeyFrameCollection::StaticGetClassType() || BaseComponentClass->IsDescendantOf(Noesis::Gui::StringKeyFrameCollection::StaticGetClassType()))
	{
		Class = UNoesisStringKeyFrameCollection::StaticClass();
	}
	if (BaseComponentClass == Noesis::Gui::PointKeyFrameCollection::StaticGetClassType() || BaseComponentClass->IsDescendantOf(Noesis::Gui::PointKeyFrameCollection::StaticGetClassType()))
	{
		Class = UNoesisPointKeyFrameCollection::StaticClass();
	}
	if (BaseComponentClass == Noesis::Gui::RectKeyFrameCollection::StaticGetClassType() || BaseComponentClass->IsDescendantOf(Noesis::Gui::RectKeyFrameCollection::StaticGetClassType()))
	{
		Class = UNoesisRectKeyFrameCollection::StaticClass();
	}
	if (BaseComponentClass == Noesis::Gui::VirtualizationCacheLength::StaticGetClassType() || BaseComponentClass->IsDescendantOf(Noesis::Gui::VirtualizationCacheLength::StaticGetClassType()))
	{
		Class = UNoesisVirtualizationCacheLength::StaticClass();
	}
	if (BaseComponentClass == Noesis::Gui::VisualStateManager::StaticGetClassType() || BaseComponentClass->IsDescendantOf(Noesis::Gui::VisualStateManager::StaticGetClassType()))
	{
		Class = UNoesisVisualStateManager::StaticClass();
	}
	UNoesisBaseComponent* Component = NewObject<UNoesisBaseComponent>(Outer, Class);
	Component->SetNoesisComponent(BaseComponent);
	return Component;
}

