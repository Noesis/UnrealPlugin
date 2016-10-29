////////////////////////////////////////////////////////////////////////////////////////////////////
// Noesis Engine - http://www.noesisengine.com
// Copyright (c) 2009-2010 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#pragma once

#include "NoesisGuiGeneratedClasses.h"

UNoesisGuiBaseComponent* CreateClassFor(Noesis::Core::BaseComponent* BaseComponent, UObject* Outer)
{
	const Noesis::Core::TypeClass* BaseComponentClass = BaseComponent->GetClassType();
	UClass* Class = UNoesisGuiBaseComponent::StaticClass();
	if (BaseComponentClass == Noesis::Gui::BaseBinding::StaticGetClassType() || BaseComponentClass->IsDescendantOf(Noesis::Gui::BaseBinding::StaticGetClassType()))
	{
		Class = UNoesisGuiBaseBinding::StaticClass();
	}
	if (BaseComponentClass == Noesis::Gui::Binding::StaticGetClassType() || BaseComponentClass->IsDescendantOf(Noesis::Gui::Binding::StaticGetClassType()))
	{
		Class = UNoesisGuiBinding::StaticClass();
	}
	if (BaseComponentClass == Noesis::Gui::BaseCommand::StaticGetClassType() || BaseComponentClass->IsDescendantOf(Noesis::Gui::BaseCommand::StaticGetClassType()))
	{
		Class = UNoesisGuiBaseCommand::StaticClass();
	}
	if (BaseComponentClass == Noesis::Gui::BaseDictionary::StaticGetClassType() || BaseComponentClass->IsDescendantOf(Noesis::Gui::BaseDictionary::StaticGetClassType()))
	{
		Class = UNoesisGuiBaseDictionary::StaticClass();
	}
	if (BaseComponentClass == Noesis::Gui::ResourceDictionary::StaticGetClassType() || BaseComponentClass->IsDescendantOf(Noesis::Gui::ResourceDictionary::StaticGetClassType()))
	{
		Class = UNoesisGuiResourceDictionary::StaticClass();
	}
	if (BaseComponentClass == Noesis::Gui::BaseSetter::StaticGetClassType() || BaseComponentClass->IsDescendantOf(Noesis::Gui::BaseSetter::StaticGetClassType()))
	{
		Class = UNoesisGuiBaseSetter::StaticClass();
	}
	if (BaseComponentClass == Noesis::Gui::Setter::StaticGetClassType() || BaseComponentClass->IsDescendantOf(Noesis::Gui::Setter::StaticGetClassType()))
	{
		Class = UNoesisGuiSetter::StaticClass();
	}
	if (BaseComponentClass == Noesis::Gui::BaseValueConverter::StaticGetClassType() || BaseComponentClass->IsDescendantOf(Noesis::Gui::BaseValueConverter::StaticGetClassType()))
	{
		Class = UNoesisGuiBaseValueConverter::StaticClass();
	}
	if (BaseComponentClass == Noesis::Gui::Clock::StaticGetClassType() || BaseComponentClass->IsDescendantOf(Noesis::Gui::Clock::StaticGetClassType()))
	{
		Class = UNoesisGuiClock::StaticClass();
	}
	if (BaseComponentClass == Noesis::Gui::AnimationClock::StaticGetClassType() || BaseComponentClass->IsDescendantOf(Noesis::Gui::AnimationClock::StaticGetClassType()))
	{
		Class = UNoesisGuiAnimationClock::StaticClass();
	}
	if (BaseComponentClass == Noesis::Gui::ClockGroup::StaticGetClassType() || BaseComponentClass->IsDescendantOf(Noesis::Gui::ClockGroup::StaticGetClassType()))
	{
		Class = UNoesisGuiClockGroup::StaticClass();
	}
	if (BaseComponentClass == Noesis::Gui::Collection::StaticGetClassType() || BaseComponentClass->IsDescendantOf(Noesis::Gui::Collection::StaticGetClassType()))
	{
		Class = UNoesisGuiCollection::StaticClass();
	}
	if (BaseComponentClass == Noesis::Gui::TriggerCollection::StaticGetClassType() || BaseComponentClass->IsDescendantOf(Noesis::Gui::TriggerCollection::StaticGetClassType()))
	{
		Class = UNoesisGuiTriggerCollection::StaticClass();
	}
	if (BaseComponentClass == Noesis::Gui::InputBindingCollection::StaticGetClassType() || BaseComponentClass->IsDescendantOf(Noesis::Gui::InputBindingCollection::StaticGetClassType()))
	{
		Class = UNoesisGuiInputBindingCollection::StaticClass();
	}
	if (BaseComponentClass == Noesis::Gui::BaseSetterCollection::StaticGetClassType() || BaseComponentClass->IsDescendantOf(Noesis::Gui::BaseSetterCollection::StaticGetClassType()))
	{
		Class = UNoesisGuiBaseSetterCollection::StaticClass();
	}
	if (BaseComponentClass == Noesis::Gui::VisualStateCollection::StaticGetClassType() || BaseComponentClass->IsDescendantOf(Noesis::Gui::VisualStateCollection::StaticGetClassType()))
	{
		Class = UNoesisGuiVisualStateCollection::StaticClass();
	}
	if (BaseComponentClass == Noesis::Gui::CommandBindingCollection::StaticGetClassType() || BaseComponentClass->IsDescendantOf(Noesis::Gui::CommandBindingCollection::StaticGetClassType()))
	{
		Class = UNoesisGuiCommandBindingCollection::StaticClass();
	}
	if (BaseComponentClass == Noesis::Gui::InlineCollection::StaticGetClassType() || BaseComponentClass->IsDescendantOf(Noesis::Gui::InlineCollection::StaticGetClassType()))
	{
		Class = UNoesisGuiInlineCollection::StaticClass();
	}
	if (BaseComponentClass == Noesis::Gui::ColumnDefinitionCollection::StaticGetClassType() || BaseComponentClass->IsDescendantOf(Noesis::Gui::ColumnDefinitionCollection::StaticGetClassType()))
	{
		Class = UNoesisGuiColumnDefinitionCollection::StaticClass();
	}
	if (BaseComponentClass == Noesis::Gui::RowDefinitionCollection::StaticGetClassType() || BaseComponentClass->IsDescendantOf(Noesis::Gui::RowDefinitionCollection::StaticGetClassType()))
	{
		Class = UNoesisGuiRowDefinitionCollection::StaticClass();
	}
	if (BaseComponentClass == Noesis::Gui::GridViewColumnCollection::StaticGetClassType() || BaseComponentClass->IsDescendantOf(Noesis::Gui::GridViewColumnCollection::StaticGetClassType()))
	{
		Class = UNoesisGuiGridViewColumnCollection::StaticClass();
	}
	if (BaseComponentClass == Noesis::Gui::TriggerActionCollection::StaticGetClassType() || BaseComponentClass->IsDescendantOf(Noesis::Gui::TriggerActionCollection::StaticGetClassType()))
	{
		Class = UNoesisGuiTriggerActionCollection::StaticClass();
	}
	if (BaseComponentClass == Noesis::Gui::ConditionCollection::StaticGetClassType() || BaseComponentClass->IsDescendantOf(Noesis::Gui::ConditionCollection::StaticGetClassType()))
	{
		Class = UNoesisGuiConditionCollection::StaticClass();
	}
	if (BaseComponentClass == Noesis::Gui::ResourceDictionaryCollection::StaticGetClassType() || BaseComponentClass->IsDescendantOf(Noesis::Gui::ResourceDictionaryCollection::StaticGetClassType()))
	{
		Class = UNoesisGuiResourceDictionaryCollection::StaticClass();
	}
	if (BaseComponentClass == Noesis::Gui::VisualTransitionCollection::StaticGetClassType() || BaseComponentClass->IsDescendantOf(Noesis::Gui::VisualTransitionCollection::StaticGetClassType()))
	{
		Class = UNoesisGuiVisualTransitionCollection::StaticClass();
	}
	if (BaseComponentClass == Noesis::Gui::InputGestureCollection::StaticGetClassType() || BaseComponentClass->IsDescendantOf(Noesis::Gui::InputGestureCollection::StaticGetClassType()))
	{
		Class = UNoesisGuiInputGestureCollection::StaticClass();
	}
	if (BaseComponentClass == Noesis::Gui::VisualCollection::StaticGetClassType() || BaseComponentClass->IsDescendantOf(Noesis::Gui::VisualCollection::StaticGetClassType()))
	{
		Class = UNoesisGuiVisualCollection::StaticClass();
	}
	if (BaseComponentClass == Noesis::Gui::UIElementCollection::StaticGetClassType() || BaseComponentClass->IsDescendantOf(Noesis::Gui::UIElementCollection::StaticGetClassType()))
	{
		Class = UNoesisGuiUIElementCollection::StaticClass();
	}
	if (BaseComponentClass == Noesis::Gui::CollectionView::StaticGetClassType() || BaseComponentClass->IsDescendantOf(Noesis::Gui::CollectionView::StaticGetClassType()))
	{
		Class = UNoesisGuiCollectionView::StaticClass();
	}
	if (BaseComponentClass == Noesis::Gui::CommandBinding::StaticGetClassType() || BaseComponentClass->IsDescendantOf(Noesis::Gui::CommandBinding::StaticGetClassType()))
	{
		Class = UNoesisGuiCommandBinding::StaticClass();
	}
	if (BaseComponentClass == Noesis::Gui::Condition::StaticGetClassType() || BaseComponentClass->IsDescendantOf(Noesis::Gui::Condition::StaticGetClassType()))
	{
		Class = UNoesisGuiCondition::StaticClass();
	}
	if (BaseComponentClass == Noesis::Gui::DataTemplateSelector::StaticGetClassType() || BaseComponentClass->IsDescendantOf(Noesis::Gui::DataTemplateSelector::StaticGetClassType()))
	{
		Class = UNoesisGuiDataTemplateSelector::StaticClass();
	}
	if (BaseComponentClass == Noesis::Gui::DependencyObject::StaticGetClassType() || BaseComponentClass->IsDescendantOf(Noesis::Gui::DependencyObject::StaticGetClassType()))
	{
		Class = UNoesisGuiDependencyObject::StaticClass();
	}
	if (BaseComponentClass == Noesis::Gui::BaseTrigger::StaticGetClassType() || BaseComponentClass->IsDescendantOf(Noesis::Gui::BaseTrigger::StaticGetClassType()))
	{
		Class = UNoesisGuiBaseTrigger::StaticClass();
	}
	if (BaseComponentClass == Noesis::Gui::DataTrigger::StaticGetClassType() || BaseComponentClass->IsDescendantOf(Noesis::Gui::DataTrigger::StaticGetClassType()))
	{
		Class = UNoesisGuiDataTrigger::StaticClass();
	}
	if (BaseComponentClass == Noesis::Gui::EventTrigger::StaticGetClassType() || BaseComponentClass->IsDescendantOf(Noesis::Gui::EventTrigger::StaticGetClassType()))
	{
		Class = UNoesisGuiEventTrigger::StaticClass();
	}
	if (BaseComponentClass == Noesis::Gui::MultiDataTrigger::StaticGetClassType() || BaseComponentClass->IsDescendantOf(Noesis::Gui::MultiDataTrigger::StaticGetClassType()))
	{
		Class = UNoesisGuiMultiDataTrigger::StaticClass();
	}
	if (BaseComponentClass == Noesis::Gui::MultiTrigger::StaticGetClassType() || BaseComponentClass->IsDescendantOf(Noesis::Gui::MultiTrigger::StaticGetClassType()))
	{
		Class = UNoesisGuiMultiTrigger::StaticClass();
	}
	if (BaseComponentClass == Noesis::Gui::Trigger::StaticGetClassType() || BaseComponentClass->IsDescendantOf(Noesis::Gui::Trigger::StaticGetClassType()))
	{
		Class = UNoesisGuiTrigger::StaticClass();
	}
	if (BaseComponentClass == Noesis::Gui::BaseView::StaticGetClassType() || BaseComponentClass->IsDescendantOf(Noesis::Gui::BaseView::StaticGetClassType()))
	{
		Class = UNoesisGuiBaseView::StaticClass();
	}
	if (BaseComponentClass == Noesis::Gui::GridView::StaticGetClassType() || BaseComponentClass->IsDescendantOf(Noesis::Gui::GridView::StaticGetClassType()))
	{
		Class = UNoesisGuiGridView::StaticClass();
	}
	if (BaseComponentClass == Noesis::Gui::CollectionViewSource::StaticGetClassType() || BaseComponentClass->IsDescendantOf(Noesis::Gui::CollectionViewSource::StaticGetClassType()))
	{
		Class = UNoesisGuiCollectionViewSource::StaticClass();
	}
	if (BaseComponentClass == Noesis::Gui::Freezable::StaticGetClassType() || BaseComponentClass->IsDescendantOf(Noesis::Gui::Freezable::StaticGetClassType()))
	{
		Class = UNoesisGuiFreezable::StaticClass();
	}
	if (BaseComponentClass == Noesis::Gui::Animatable::StaticGetClassType() || BaseComponentClass->IsDescendantOf(Noesis::Gui::Animatable::StaticGetClassType()))
	{
		Class = UNoesisGuiAnimatable::StaticClass();
	}
	if (BaseComponentClass == Noesis::Gui::Brush::StaticGetClassType() || BaseComponentClass->IsDescendantOf(Noesis::Gui::Brush::StaticGetClassType()))
	{
		Class = UNoesisGuiBrush::StaticClass();
	}
	if (BaseComponentClass == Noesis::Gui::GradientBrush::StaticGetClassType() || BaseComponentClass->IsDescendantOf(Noesis::Gui::GradientBrush::StaticGetClassType()))
	{
		Class = UNoesisGuiGradientBrush::StaticClass();
	}
	if (BaseComponentClass == Noesis::Gui::LinearGradientBrush::StaticGetClassType() || BaseComponentClass->IsDescendantOf(Noesis::Gui::LinearGradientBrush::StaticGetClassType()))
	{
		Class = UNoesisGuiLinearGradientBrush::StaticClass();
	}
	if (BaseComponentClass == Noesis::Gui::RadialGradientBrush::StaticGetClassType() || BaseComponentClass->IsDescendantOf(Noesis::Gui::RadialGradientBrush::StaticGetClassType()))
	{
		Class = UNoesisGuiRadialGradientBrush::StaticClass();
	}
	if (BaseComponentClass == Noesis::Gui::SolidColorBrush::StaticGetClassType() || BaseComponentClass->IsDescendantOf(Noesis::Gui::SolidColorBrush::StaticGetClassType()))
	{
		Class = UNoesisGuiSolidColorBrush::StaticClass();
	}
	if (BaseComponentClass == Noesis::Gui::TileBrush::StaticGetClassType() || BaseComponentClass->IsDescendantOf(Noesis::Gui::TileBrush::StaticGetClassType()))
	{
		Class = UNoesisGuiTileBrush::StaticClass();
	}
	if (BaseComponentClass == Noesis::Gui::ImageBrush::StaticGetClassType() || BaseComponentClass->IsDescendantOf(Noesis::Gui::ImageBrush::StaticGetClassType()))
	{
		Class = UNoesisGuiImageBrush::StaticClass();
	}
	if (BaseComponentClass == Noesis::Gui::VisualBrush::StaticGetClassType() || BaseComponentClass->IsDescendantOf(Noesis::Gui::VisualBrush::StaticGetClassType()))
	{
		Class = UNoesisGuiVisualBrush::StaticClass();
	}
	if (BaseComponentClass == Noesis::Gui::DashStyle::StaticGetClassType() || BaseComponentClass->IsDescendantOf(Noesis::Gui::DashStyle::StaticGetClassType()))
	{
		Class = UNoesisGuiDashStyle::StaticClass();
	}
	if (BaseComponentClass == Noesis::Gui::Geometry::StaticGetClassType() || BaseComponentClass->IsDescendantOf(Noesis::Gui::Geometry::StaticGetClassType()))
	{
		Class = UNoesisGuiGeometry::StaticClass();
	}
	if (BaseComponentClass == Noesis::Gui::CombinedGeometry::StaticGetClassType() || BaseComponentClass->IsDescendantOf(Noesis::Gui::CombinedGeometry::StaticGetClassType()))
	{
		Class = UNoesisGuiCombinedGeometry::StaticClass();
	}
	if (BaseComponentClass == Noesis::Gui::EllipseGeometry::StaticGetClassType() || BaseComponentClass->IsDescendantOf(Noesis::Gui::EllipseGeometry::StaticGetClassType()))
	{
		Class = UNoesisGuiEllipseGeometry::StaticClass();
	}
	if (BaseComponentClass == Noesis::Gui::GeometryGroup::StaticGetClassType() || BaseComponentClass->IsDescendantOf(Noesis::Gui::GeometryGroup::StaticGetClassType()))
	{
		Class = UNoesisGuiGeometryGroup::StaticClass();
	}
	if (BaseComponentClass == Noesis::Gui::LineGeometry::StaticGetClassType() || BaseComponentClass->IsDescendantOf(Noesis::Gui::LineGeometry::StaticGetClassType()))
	{
		Class = UNoesisGuiLineGeometry::StaticClass();
	}
	if (BaseComponentClass == Noesis::Gui::RectangleGeometry::StaticGetClassType() || BaseComponentClass->IsDescendantOf(Noesis::Gui::RectangleGeometry::StaticGetClassType()))
	{
		Class = UNoesisGuiRectangleGeometry::StaticClass();
	}
	if (BaseComponentClass == Noesis::Gui::StreamGeometry::StaticGetClassType() || BaseComponentClass->IsDescendantOf(Noesis::Gui::StreamGeometry::StaticGetClassType()))
	{
		Class = UNoesisGuiStreamGeometry::StaticClass();
	}
	if (BaseComponentClass == Noesis::Gui::GradientStop::StaticGetClassType() || BaseComponentClass->IsDescendantOf(Noesis::Gui::GradientStop::StaticGetClassType()))
	{
		Class = UNoesisGuiGradientStop::StaticClass();
	}
	if (BaseComponentClass == Noesis::Gui::ImageSource::StaticGetClassType() || BaseComponentClass->IsDescendantOf(Noesis::Gui::ImageSource::StaticGetClassType()))
	{
		Class = UNoesisGuiImageSource::StaticClass();
	}
	if (BaseComponentClass == Noesis::Gui::BitmapSource::StaticGetClassType() || BaseComponentClass->IsDescendantOf(Noesis::Gui::BitmapSource::StaticGetClassType()))
	{
		Class = UNoesisGuiBitmapSource::StaticClass();
	}
	if (BaseComponentClass == Noesis::Gui::BitmapImage::StaticGetClassType() || BaseComponentClass->IsDescendantOf(Noesis::Gui::BitmapImage::StaticGetClassType()))
	{
		Class = UNoesisGuiBitmapImage::StaticClass();
	}
	if (BaseComponentClass == Noesis::Gui::TextureSource::StaticGetClassType() || BaseComponentClass->IsDescendantOf(Noesis::Gui::TextureSource::StaticGetClassType()))
	{
		Class = UNoesisGuiTextureSource::StaticClass();
	}
	if (BaseComponentClass == Noesis::Gui::Pen::StaticGetClassType() || BaseComponentClass->IsDescendantOf(Noesis::Gui::Pen::StaticGetClassType()))
	{
		Class = UNoesisGuiPen::StaticClass();
	}
	if (BaseComponentClass == Noesis::Gui::Projection::StaticGetClassType() || BaseComponentClass->IsDescendantOf(Noesis::Gui::Projection::StaticGetClassType()))
	{
		Class = UNoesisGuiProjection::StaticClass();
	}
	if (BaseComponentClass == Noesis::Gui::Matrix3DProjection::StaticGetClassType() || BaseComponentClass->IsDescendantOf(Noesis::Gui::Matrix3DProjection::StaticGetClassType()))
	{
		Class = UNoesisGuiMatrix3DProjection::StaticClass();
	}
	if (BaseComponentClass == Noesis::Gui::PlaneProjection::StaticGetClassType() || BaseComponentClass->IsDescendantOf(Noesis::Gui::PlaneProjection::StaticGetClassType()))
	{
		Class = UNoesisGuiPlaneProjection::StaticClass();
	}
	if (BaseComponentClass == Noesis::Gui::Timeline::StaticGetClassType() || BaseComponentClass->IsDescendantOf(Noesis::Gui::Timeline::StaticGetClassType()))
	{
		Class = UNoesisGuiTimeline::StaticClass();
	}
	if (BaseComponentClass == Noesis::Gui::AnimationTimeline::StaticGetClassType() || BaseComponentClass->IsDescendantOf(Noesis::Gui::AnimationTimeline::StaticGetClassType()))
	{
		Class = UNoesisGuiAnimationTimeline::StaticClass();
	}
	if (BaseComponentClass == Noesis::Gui::Int16AnimationUsingKeyFrames::StaticGetClassType() || BaseComponentClass->IsDescendantOf(Noesis::Gui::Int16AnimationUsingKeyFrames::StaticGetClassType()))
	{
		Class = UNoesisGuiInt16AnimationUsingKeyFrames::StaticClass();
	}
	if (BaseComponentClass == Noesis::Gui::SizeAnimationUsingKeyFrames::StaticGetClassType() || BaseComponentClass->IsDescendantOf(Noesis::Gui::SizeAnimationUsingKeyFrames::StaticGetClassType()))
	{
		Class = UNoesisGuiSizeAnimationUsingKeyFrames::StaticClass();
	}
	if (BaseComponentClass == Noesis::Gui::PointAnimationUsingKeyFrames::StaticGetClassType() || BaseComponentClass->IsDescendantOf(Noesis::Gui::PointAnimationUsingKeyFrames::StaticGetClassType()))
	{
		Class = UNoesisGuiPointAnimationUsingKeyFrames::StaticClass();
	}
	if (BaseComponentClass == Noesis::Gui::ColorAnimationUsingKeyFrames::StaticGetClassType() || BaseComponentClass->IsDescendantOf(Noesis::Gui::ColorAnimationUsingKeyFrames::StaticGetClassType()))
	{
		Class = UNoesisGuiColorAnimationUsingKeyFrames::StaticClass();
	}
	if (BaseComponentClass == Noesis::Gui::ThicknessAnimationUsingKeyFrames::StaticGetClassType() || BaseComponentClass->IsDescendantOf(Noesis::Gui::ThicknessAnimationUsingKeyFrames::StaticGetClassType()))
	{
		Class = UNoesisGuiThicknessAnimationUsingKeyFrames::StaticClass();
	}
	if (BaseComponentClass == Noesis::Gui::ObjectAnimationUsingKeyFrames::StaticGetClassType() || BaseComponentClass->IsDescendantOf(Noesis::Gui::ObjectAnimationUsingKeyFrames::StaticGetClassType()))
	{
		Class = UNoesisGuiObjectAnimationUsingKeyFrames::StaticClass();
	}
	if (BaseComponentClass == Noesis::Gui::Int32AnimationUsingKeyFrames::StaticGetClassType() || BaseComponentClass->IsDescendantOf(Noesis::Gui::Int32AnimationUsingKeyFrames::StaticGetClassType()))
	{
		Class = UNoesisGuiInt32AnimationUsingKeyFrames::StaticClass();
	}
	if (BaseComponentClass == Noesis::Gui::StringAnimationUsingKeyFrames::StaticGetClassType() || BaseComponentClass->IsDescendantOf(Noesis::Gui::StringAnimationUsingKeyFrames::StaticGetClassType()))
	{
		Class = UNoesisGuiStringAnimationUsingKeyFrames::StaticClass();
	}
	if (BaseComponentClass == Noesis::Gui::BooleanAnimationUsingKeyFrames::StaticGetClassType() || BaseComponentClass->IsDescendantOf(Noesis::Gui::BooleanAnimationUsingKeyFrames::StaticGetClassType()))
	{
		Class = UNoesisGuiBooleanAnimationUsingKeyFrames::StaticClass();
	}
	if (BaseComponentClass == Noesis::Gui::RectAnimationUsingKeyFrames::StaticGetClassType() || BaseComponentClass->IsDescendantOf(Noesis::Gui::RectAnimationUsingKeyFrames::StaticGetClassType()))
	{
		Class = UNoesisGuiRectAnimationUsingKeyFrames::StaticClass();
	}
	if (BaseComponentClass == Noesis::Gui::DoubleAnimationUsingKeyFrames::StaticGetClassType() || BaseComponentClass->IsDescendantOf(Noesis::Gui::DoubleAnimationUsingKeyFrames::StaticGetClassType()))
	{
		Class = UNoesisGuiDoubleAnimationUsingKeyFrames::StaticClass();
	}
	if (BaseComponentClass == Noesis::Gui::BaseAnimation::StaticGetClassType() || BaseComponentClass->IsDescendantOf(Noesis::Gui::BaseAnimation::StaticGetClassType()))
	{
		Class = UNoesisGuiBaseAnimation::StaticClass();
	}
	if (BaseComponentClass == Noesis::Gui::Int32Animation::StaticGetClassType() || BaseComponentClass->IsDescendantOf(Noesis::Gui::Int32Animation::StaticGetClassType()))
	{
		Class = UNoesisGuiInt32Animation::StaticClass();
	}
	if (BaseComponentClass == Noesis::Gui::PointAnimation::StaticGetClassType() || BaseComponentClass->IsDescendantOf(Noesis::Gui::PointAnimation::StaticGetClassType()))
	{
		Class = UNoesisGuiPointAnimation::StaticClass();
	}
	if (BaseComponentClass == Noesis::Gui::ColorAnimation::StaticGetClassType() || BaseComponentClass->IsDescendantOf(Noesis::Gui::ColorAnimation::StaticGetClassType()))
	{
		Class = UNoesisGuiColorAnimation::StaticClass();
	}
	if (BaseComponentClass == Noesis::Gui::RectAnimation::StaticGetClassType() || BaseComponentClass->IsDescendantOf(Noesis::Gui::RectAnimation::StaticGetClassType()))
	{
		Class = UNoesisGuiRectAnimation::StaticClass();
	}
	if (BaseComponentClass == Noesis::Gui::ThicknessAnimation::StaticGetClassType() || BaseComponentClass->IsDescendantOf(Noesis::Gui::ThicknessAnimation::StaticGetClassType()))
	{
		Class = UNoesisGuiThicknessAnimation::StaticClass();
	}
	if (BaseComponentClass == Noesis::Gui::SizeAnimation::StaticGetClassType() || BaseComponentClass->IsDescendantOf(Noesis::Gui::SizeAnimation::StaticGetClassType()))
	{
		Class = UNoesisGuiSizeAnimation::StaticClass();
	}
	if (BaseComponentClass == Noesis::Gui::Int16Animation::StaticGetClassType() || BaseComponentClass->IsDescendantOf(Noesis::Gui::Int16Animation::StaticGetClassType()))
	{
		Class = UNoesisGuiInt16Animation::StaticClass();
	}
	if (BaseComponentClass == Noesis::Gui::DoubleAnimation::StaticGetClassType() || BaseComponentClass->IsDescendantOf(Noesis::Gui::DoubleAnimation::StaticGetClassType()))
	{
		Class = UNoesisGuiDoubleAnimation::StaticClass();
	}
	if (BaseComponentClass == Noesis::Gui::TimelineGroup::StaticGetClassType() || BaseComponentClass->IsDescendantOf(Noesis::Gui::TimelineGroup::StaticGetClassType()))
	{
		Class = UNoesisGuiTimelineGroup::StaticClass();
	}
	if (BaseComponentClass == Noesis::Gui::ParallelTimeline::StaticGetClassType() || BaseComponentClass->IsDescendantOf(Noesis::Gui::ParallelTimeline::StaticGetClassType()))
	{
		Class = UNoesisGuiParallelTimeline::StaticClass();
	}
	if (BaseComponentClass == Noesis::Gui::Storyboard::StaticGetClassType() || BaseComponentClass->IsDescendantOf(Noesis::Gui::Storyboard::StaticGetClassType()))
	{
		Class = UNoesisGuiStoryboard::StaticClass();
	}
	if (BaseComponentClass == Noesis::Gui::Transform::StaticGetClassType() || BaseComponentClass->IsDescendantOf(Noesis::Gui::Transform::StaticGetClassType()))
	{
		Class = UNoesisGuiTransform::StaticClass();
	}
	if (BaseComponentClass == Noesis::Gui::CompositeTransform::StaticGetClassType() || BaseComponentClass->IsDescendantOf(Noesis::Gui::CompositeTransform::StaticGetClassType()))
	{
		Class = UNoesisGuiCompositeTransform::StaticClass();
	}
	if (BaseComponentClass == Noesis::Gui::MatrixTransform::StaticGetClassType() || BaseComponentClass->IsDescendantOf(Noesis::Gui::MatrixTransform::StaticGetClassType()))
	{
		Class = UNoesisGuiMatrixTransform::StaticClass();
	}
	if (BaseComponentClass == Noesis::Gui::RotateTransform::StaticGetClassType() || BaseComponentClass->IsDescendantOf(Noesis::Gui::RotateTransform::StaticGetClassType()))
	{
		Class = UNoesisGuiRotateTransform::StaticClass();
	}
	if (BaseComponentClass == Noesis::Gui::ScaleTransform::StaticGetClassType() || BaseComponentClass->IsDescendantOf(Noesis::Gui::ScaleTransform::StaticGetClassType()))
	{
		Class = UNoesisGuiScaleTransform::StaticClass();
	}
	if (BaseComponentClass == Noesis::Gui::SkewTransform::StaticGetClassType() || BaseComponentClass->IsDescendantOf(Noesis::Gui::SkewTransform::StaticGetClassType()))
	{
		Class = UNoesisGuiSkewTransform::StaticClass();
	}
	if (BaseComponentClass == Noesis::Gui::TransformGroup::StaticGetClassType() || BaseComponentClass->IsDescendantOf(Noesis::Gui::TransformGroup::StaticGetClassType()))
	{
		Class = UNoesisGuiTransformGroup::StaticClass();
	}
	if (BaseComponentClass == Noesis::Gui::TranslateTransform::StaticGetClassType() || BaseComponentClass->IsDescendantOf(Noesis::Gui::TranslateTransform::StaticGetClassType()))
	{
		Class = UNoesisGuiTranslateTransform::StaticClass();
	}
	if (BaseComponentClass == Noesis::Gui::EasingFunctionBase::StaticGetClassType() || BaseComponentClass->IsDescendantOf(Noesis::Gui::EasingFunctionBase::StaticGetClassType()))
	{
		Class = UNoesisGuiEasingFunctionBase::StaticClass();
	}
	if (BaseComponentClass == Noesis::Gui::BackEase::StaticGetClassType() || BaseComponentClass->IsDescendantOf(Noesis::Gui::BackEase::StaticGetClassType()))
	{
		Class = UNoesisGuiBackEase::StaticClass();
	}
	if (BaseComponentClass == Noesis::Gui::BounceEase::StaticGetClassType() || BaseComponentClass->IsDescendantOf(Noesis::Gui::BounceEase::StaticGetClassType()))
	{
		Class = UNoesisGuiBounceEase::StaticClass();
	}
	if (BaseComponentClass == Noesis::Gui::CircleEase::StaticGetClassType() || BaseComponentClass->IsDescendantOf(Noesis::Gui::CircleEase::StaticGetClassType()))
	{
		Class = UNoesisGuiCircleEase::StaticClass();
	}
	if (BaseComponentClass == Noesis::Gui::CubicEase::StaticGetClassType() || BaseComponentClass->IsDescendantOf(Noesis::Gui::CubicEase::StaticGetClassType()))
	{
		Class = UNoesisGuiCubicEase::StaticClass();
	}
	if (BaseComponentClass == Noesis::Gui::ElasticEase::StaticGetClassType() || BaseComponentClass->IsDescendantOf(Noesis::Gui::ElasticEase::StaticGetClassType()))
	{
		Class = UNoesisGuiElasticEase::StaticClass();
	}
	if (BaseComponentClass == Noesis::Gui::ExponentialEase::StaticGetClassType() || BaseComponentClass->IsDescendantOf(Noesis::Gui::ExponentialEase::StaticGetClassType()))
	{
		Class = UNoesisGuiExponentialEase::StaticClass();
	}
	if (BaseComponentClass == Noesis::Gui::PowerEase::StaticGetClassType() || BaseComponentClass->IsDescendantOf(Noesis::Gui::PowerEase::StaticGetClassType()))
	{
		Class = UNoesisGuiPowerEase::StaticClass();
	}
	if (BaseComponentClass == Noesis::Gui::QuadraticEase::StaticGetClassType() || BaseComponentClass->IsDescendantOf(Noesis::Gui::QuadraticEase::StaticGetClassType()))
	{
		Class = UNoesisGuiQuadraticEase::StaticClass();
	}
	if (BaseComponentClass == Noesis::Gui::QuarticEase::StaticGetClassType() || BaseComponentClass->IsDescendantOf(Noesis::Gui::QuarticEase::StaticGetClassType()))
	{
		Class = UNoesisGuiQuarticEase::StaticClass();
	}
	if (BaseComponentClass == Noesis::Gui::QuinticEase::StaticGetClassType() || BaseComponentClass->IsDescendantOf(Noesis::Gui::QuinticEase::StaticGetClassType()))
	{
		Class = UNoesisGuiQuinticEase::StaticClass();
	}
	if (BaseComponentClass == Noesis::Gui::SineEase::StaticGetClassType() || BaseComponentClass->IsDescendantOf(Noesis::Gui::SineEase::StaticGetClassType()))
	{
		Class = UNoesisGuiSineEase::StaticClass();
	}
	if (BaseComponentClass == Noesis::Gui::InputBinding::StaticGetClassType() || BaseComponentClass->IsDescendantOf(Noesis::Gui::InputBinding::StaticGetClassType()))
	{
		Class = UNoesisGuiInputBinding::StaticClass();
	}
	if (BaseComponentClass == Noesis::Gui::KeyBinding::StaticGetClassType() || BaseComponentClass->IsDescendantOf(Noesis::Gui::KeyBinding::StaticGetClassType()))
	{
		Class = UNoesisGuiKeyBinding::StaticClass();
	}
	if (BaseComponentClass == Noesis::Gui::Int16KeyFrame::StaticGetClassType() || BaseComponentClass->IsDescendantOf(Noesis::Gui::Int16KeyFrame::StaticGetClassType()))
	{
		Class = UNoesisGuiInt16KeyFrame::StaticClass();
	}
	if (BaseComponentClass == Noesis::Gui::SizeKeyFrame::StaticGetClassType() || BaseComponentClass->IsDescendantOf(Noesis::Gui::SizeKeyFrame::StaticGetClassType()))
	{
		Class = UNoesisGuiSizeKeyFrame::StaticClass();
	}
	if (BaseComponentClass == Noesis::Gui::PointKeyFrame::StaticGetClassType() || BaseComponentClass->IsDescendantOf(Noesis::Gui::PointKeyFrame::StaticGetClassType()))
	{
		Class = UNoesisGuiPointKeyFrame::StaticClass();
	}
	if (BaseComponentClass == Noesis::Gui::ColorKeyFrame::StaticGetClassType() || BaseComponentClass->IsDescendantOf(Noesis::Gui::ColorKeyFrame::StaticGetClassType()))
	{
		Class = UNoesisGuiColorKeyFrame::StaticClass();
	}
	if (BaseComponentClass == Noesis::Gui::ThicknessKeyFrame::StaticGetClassType() || BaseComponentClass->IsDescendantOf(Noesis::Gui::ThicknessKeyFrame::StaticGetClassType()))
	{
		Class = UNoesisGuiThicknessKeyFrame::StaticClass();
	}
	if (BaseComponentClass == Noesis::Gui::ObjectKeyFrame::StaticGetClassType() || BaseComponentClass->IsDescendantOf(Noesis::Gui::ObjectKeyFrame::StaticGetClassType()))
	{
		Class = UNoesisGuiObjectKeyFrame::StaticClass();
	}
	if (BaseComponentClass == Noesis::Gui::Int32KeyFrame::StaticGetClassType() || BaseComponentClass->IsDescendantOf(Noesis::Gui::Int32KeyFrame::StaticGetClassType()))
	{
		Class = UNoesisGuiInt32KeyFrame::StaticClass();
	}
	if (BaseComponentClass == Noesis::Gui::StringKeyFrame::StaticGetClassType() || BaseComponentClass->IsDescendantOf(Noesis::Gui::StringKeyFrame::StaticGetClassType()))
	{
		Class = UNoesisGuiStringKeyFrame::StaticClass();
	}
	if (BaseComponentClass == Noesis::Gui::BooleanKeyFrame::StaticGetClassType() || BaseComponentClass->IsDescendantOf(Noesis::Gui::BooleanKeyFrame::StaticGetClassType()))
	{
		Class = UNoesisGuiBooleanKeyFrame::StaticClass();
	}
	if (BaseComponentClass == Noesis::Gui::RectKeyFrame::StaticGetClassType() || BaseComponentClass->IsDescendantOf(Noesis::Gui::RectKeyFrame::StaticGetClassType()))
	{
		Class = UNoesisGuiRectKeyFrame::StaticClass();
	}
	if (BaseComponentClass == Noesis::Gui::DoubleKeyFrame::StaticGetClassType() || BaseComponentClass->IsDescendantOf(Noesis::Gui::DoubleKeyFrame::StaticGetClassType()))
	{
		Class = UNoesisGuiDoubleKeyFrame::StaticClass();
	}
	if (BaseComponentClass == Noesis::Gui::DiscreteInt16KeyFrame::StaticGetClassType() || BaseComponentClass->IsDescendantOf(Noesis::Gui::DiscreteInt16KeyFrame::StaticGetClassType()))
	{
		Class = UNoesisGuiDiscreteInt16KeyFrame::StaticClass();
	}
	if (BaseComponentClass == Noesis::Gui::DiscreteSizeKeyFrame::StaticGetClassType() || BaseComponentClass->IsDescendantOf(Noesis::Gui::DiscreteSizeKeyFrame::StaticGetClassType()))
	{
		Class = UNoesisGuiDiscreteSizeKeyFrame::StaticClass();
	}
	if (BaseComponentClass == Noesis::Gui::DiscretePointKeyFrame::StaticGetClassType() || BaseComponentClass->IsDescendantOf(Noesis::Gui::DiscretePointKeyFrame::StaticGetClassType()))
	{
		Class = UNoesisGuiDiscretePointKeyFrame::StaticClass();
	}
	if (BaseComponentClass == Noesis::Gui::DiscreteColorKeyFrame::StaticGetClassType() || BaseComponentClass->IsDescendantOf(Noesis::Gui::DiscreteColorKeyFrame::StaticGetClassType()))
	{
		Class = UNoesisGuiDiscreteColorKeyFrame::StaticClass();
	}
	if (BaseComponentClass == Noesis::Gui::DiscreteThicknessKeyFrame::StaticGetClassType() || BaseComponentClass->IsDescendantOf(Noesis::Gui::DiscreteThicknessKeyFrame::StaticGetClassType()))
	{
		Class = UNoesisGuiDiscreteThicknessKeyFrame::StaticClass();
	}
	if (BaseComponentClass == Noesis::Gui::DiscreteObjectKeyFrame::StaticGetClassType() || BaseComponentClass->IsDescendantOf(Noesis::Gui::DiscreteObjectKeyFrame::StaticGetClassType()))
	{
		Class = UNoesisGuiDiscreteObjectKeyFrame::StaticClass();
	}
	if (BaseComponentClass == Noesis::Gui::DiscreteInt32KeyFrame::StaticGetClassType() || BaseComponentClass->IsDescendantOf(Noesis::Gui::DiscreteInt32KeyFrame::StaticGetClassType()))
	{
		Class = UNoesisGuiDiscreteInt32KeyFrame::StaticClass();
	}
	if (BaseComponentClass == Noesis::Gui::DiscreteStringKeyFrame::StaticGetClassType() || BaseComponentClass->IsDescendantOf(Noesis::Gui::DiscreteStringKeyFrame::StaticGetClassType()))
	{
		Class = UNoesisGuiDiscreteStringKeyFrame::StaticClass();
	}
	if (BaseComponentClass == Noesis::Gui::DiscreteBooleanKeyFrame::StaticGetClassType() || BaseComponentClass->IsDescendantOf(Noesis::Gui::DiscreteBooleanKeyFrame::StaticGetClassType()))
	{
		Class = UNoesisGuiDiscreteBooleanKeyFrame::StaticClass();
	}
	if (BaseComponentClass == Noesis::Gui::DiscreteRectKeyFrame::StaticGetClassType() || BaseComponentClass->IsDescendantOf(Noesis::Gui::DiscreteRectKeyFrame::StaticGetClassType()))
	{
		Class = UNoesisGuiDiscreteRectKeyFrame::StaticClass();
	}
	if (BaseComponentClass == Noesis::Gui::DiscreteDoubleKeyFrame::StaticGetClassType() || BaseComponentClass->IsDescendantOf(Noesis::Gui::DiscreteDoubleKeyFrame::StaticGetClassType()))
	{
		Class = UNoesisGuiDiscreteDoubleKeyFrame::StaticClass();
	}
	if (BaseComponentClass == Noesis::Gui::EasingInt32KeyFrame::StaticGetClassType() || BaseComponentClass->IsDescendantOf(Noesis::Gui::EasingInt32KeyFrame::StaticGetClassType()))
	{
		Class = UNoesisGuiEasingInt32KeyFrame::StaticClass();
	}
	if (BaseComponentClass == Noesis::Gui::EasingPointKeyFrame::StaticGetClassType() || BaseComponentClass->IsDescendantOf(Noesis::Gui::EasingPointKeyFrame::StaticGetClassType()))
	{
		Class = UNoesisGuiEasingPointKeyFrame::StaticClass();
	}
	if (BaseComponentClass == Noesis::Gui::EasingColorKeyFrame::StaticGetClassType() || BaseComponentClass->IsDescendantOf(Noesis::Gui::EasingColorKeyFrame::StaticGetClassType()))
	{
		Class = UNoesisGuiEasingColorKeyFrame::StaticClass();
	}
	if (BaseComponentClass == Noesis::Gui::EasingRectKeyFrame::StaticGetClassType() || BaseComponentClass->IsDescendantOf(Noesis::Gui::EasingRectKeyFrame::StaticGetClassType()))
	{
		Class = UNoesisGuiEasingRectKeyFrame::StaticClass();
	}
	if (BaseComponentClass == Noesis::Gui::EasingThicknessKeyFrame::StaticGetClassType() || BaseComponentClass->IsDescendantOf(Noesis::Gui::EasingThicknessKeyFrame::StaticGetClassType()))
	{
		Class = UNoesisGuiEasingThicknessKeyFrame::StaticClass();
	}
	if (BaseComponentClass == Noesis::Gui::EasingSizeKeyFrame::StaticGetClassType() || BaseComponentClass->IsDescendantOf(Noesis::Gui::EasingSizeKeyFrame::StaticGetClassType()))
	{
		Class = UNoesisGuiEasingSizeKeyFrame::StaticClass();
	}
	if (BaseComponentClass == Noesis::Gui::EasingInt16KeyFrame::StaticGetClassType() || BaseComponentClass->IsDescendantOf(Noesis::Gui::EasingInt16KeyFrame::StaticGetClassType()))
	{
		Class = UNoesisGuiEasingInt16KeyFrame::StaticClass();
	}
	if (BaseComponentClass == Noesis::Gui::EasingDoubleKeyFrame::StaticGetClassType() || BaseComponentClass->IsDescendantOf(Noesis::Gui::EasingDoubleKeyFrame::StaticGetClassType()))
	{
		Class = UNoesisGuiEasingDoubleKeyFrame::StaticClass();
	}
	if (BaseComponentClass == Noesis::Gui::LinearInt32KeyFrame::StaticGetClassType() || BaseComponentClass->IsDescendantOf(Noesis::Gui::LinearInt32KeyFrame::StaticGetClassType()))
	{
		Class = UNoesisGuiLinearInt32KeyFrame::StaticClass();
	}
	if (BaseComponentClass == Noesis::Gui::LinearPointKeyFrame::StaticGetClassType() || BaseComponentClass->IsDescendantOf(Noesis::Gui::LinearPointKeyFrame::StaticGetClassType()))
	{
		Class = UNoesisGuiLinearPointKeyFrame::StaticClass();
	}
	if (BaseComponentClass == Noesis::Gui::LinearColorKeyFrame::StaticGetClassType() || BaseComponentClass->IsDescendantOf(Noesis::Gui::LinearColorKeyFrame::StaticGetClassType()))
	{
		Class = UNoesisGuiLinearColorKeyFrame::StaticClass();
	}
	if (BaseComponentClass == Noesis::Gui::LinearRectKeyFrame::StaticGetClassType() || BaseComponentClass->IsDescendantOf(Noesis::Gui::LinearRectKeyFrame::StaticGetClassType()))
	{
		Class = UNoesisGuiLinearRectKeyFrame::StaticClass();
	}
	if (BaseComponentClass == Noesis::Gui::LinearThicknessKeyFrame::StaticGetClassType() || BaseComponentClass->IsDescendantOf(Noesis::Gui::LinearThicknessKeyFrame::StaticGetClassType()))
	{
		Class = UNoesisGuiLinearThicknessKeyFrame::StaticClass();
	}
	if (BaseComponentClass == Noesis::Gui::LinearSizeKeyFrame::StaticGetClassType() || BaseComponentClass->IsDescendantOf(Noesis::Gui::LinearSizeKeyFrame::StaticGetClassType()))
	{
		Class = UNoesisGuiLinearSizeKeyFrame::StaticClass();
	}
	if (BaseComponentClass == Noesis::Gui::LinearInt16KeyFrame::StaticGetClassType() || BaseComponentClass->IsDescendantOf(Noesis::Gui::LinearInt16KeyFrame::StaticGetClassType()))
	{
		Class = UNoesisGuiLinearInt16KeyFrame::StaticClass();
	}
	if (BaseComponentClass == Noesis::Gui::LinearDoubleKeyFrame::StaticGetClassType() || BaseComponentClass->IsDescendantOf(Noesis::Gui::LinearDoubleKeyFrame::StaticGetClassType()))
	{
		Class = UNoesisGuiLinearDoubleKeyFrame::StaticClass();
	}
	if (BaseComponentClass == Noesis::Gui::SplineInt32KeyFrame::StaticGetClassType() || BaseComponentClass->IsDescendantOf(Noesis::Gui::SplineInt32KeyFrame::StaticGetClassType()))
	{
		Class = UNoesisGuiSplineInt32KeyFrame::StaticClass();
	}
	if (BaseComponentClass == Noesis::Gui::SplinePointKeyFrame::StaticGetClassType() || BaseComponentClass->IsDescendantOf(Noesis::Gui::SplinePointKeyFrame::StaticGetClassType()))
	{
		Class = UNoesisGuiSplinePointKeyFrame::StaticClass();
	}
	if (BaseComponentClass == Noesis::Gui::SplineColorKeyFrame::StaticGetClassType() || BaseComponentClass->IsDescendantOf(Noesis::Gui::SplineColorKeyFrame::StaticGetClassType()))
	{
		Class = UNoesisGuiSplineColorKeyFrame::StaticClass();
	}
	if (BaseComponentClass == Noesis::Gui::SplineRectKeyFrame::StaticGetClassType() || BaseComponentClass->IsDescendantOf(Noesis::Gui::SplineRectKeyFrame::StaticGetClassType()))
	{
		Class = UNoesisGuiSplineRectKeyFrame::StaticClass();
	}
	if (BaseComponentClass == Noesis::Gui::SplineThicknessKeyFrame::StaticGetClassType() || BaseComponentClass->IsDescendantOf(Noesis::Gui::SplineThicknessKeyFrame::StaticGetClassType()))
	{
		Class = UNoesisGuiSplineThicknessKeyFrame::StaticClass();
	}
	if (BaseComponentClass == Noesis::Gui::SplineSizeKeyFrame::StaticGetClassType() || BaseComponentClass->IsDescendantOf(Noesis::Gui::SplineSizeKeyFrame::StaticGetClassType()))
	{
		Class = UNoesisGuiSplineSizeKeyFrame::StaticClass();
	}
	if (BaseComponentClass == Noesis::Gui::SplineInt16KeyFrame::StaticGetClassType() || BaseComponentClass->IsDescendantOf(Noesis::Gui::SplineInt16KeyFrame::StaticGetClassType()))
	{
		Class = UNoesisGuiSplineInt16KeyFrame::StaticClass();
	}
	if (BaseComponentClass == Noesis::Gui::SplineDoubleKeyFrame::StaticGetClassType() || BaseComponentClass->IsDescendantOf(Noesis::Gui::SplineDoubleKeyFrame::StaticGetClassType()))
	{
		Class = UNoesisGuiSplineDoubleKeyFrame::StaticClass();
	}
	if (BaseComponentClass == Noesis::Gui::KeySpline::StaticGetClassType() || BaseComponentClass->IsDescendantOf(Noesis::Gui::KeySpline::StaticGetClassType()))
	{
		Class = UNoesisGuiKeySpline::StaticClass();
	}
	if (BaseComponentClass == Noesis::Gui::GridViewColumn::StaticGetClassType() || BaseComponentClass->IsDescendantOf(Noesis::Gui::GridViewColumn::StaticGetClassType()))
	{
		Class = UNoesisGuiGridViewColumn::StaticClass();
	}
	if (BaseComponentClass == Noesis::Gui::TextElement::StaticGetClassType() || BaseComponentClass->IsDescendantOf(Noesis::Gui::TextElement::StaticGetClassType()))
	{
		Class = UNoesisGuiTextElement::StaticClass();
	}
	if (BaseComponentClass == Noesis::Gui::Inline::StaticGetClassType() || BaseComponentClass->IsDescendantOf(Noesis::Gui::Inline::StaticGetClassType()))
	{
		Class = UNoesisGuiInline::StaticClass();
	}
	if (BaseComponentClass == Noesis::Gui::LineBreak::StaticGetClassType() || BaseComponentClass->IsDescendantOf(Noesis::Gui::LineBreak::StaticGetClassType()))
	{
		Class = UNoesisGuiLineBreak::StaticClass();
	}
	if (BaseComponentClass == Noesis::Gui::Run::StaticGetClassType() || BaseComponentClass->IsDescendantOf(Noesis::Gui::Run::StaticGetClassType()))
	{
		Class = UNoesisGuiRun::StaticClass();
	}
	if (BaseComponentClass == Noesis::Gui::TriggerAction::StaticGetClassType() || BaseComponentClass->IsDescendantOf(Noesis::Gui::TriggerAction::StaticGetClassType()))
	{
		Class = UNoesisGuiTriggerAction::StaticClass();
	}
	if (BaseComponentClass == Noesis::Gui::BeginStoryboard::StaticGetClassType() || BaseComponentClass->IsDescendantOf(Noesis::Gui::BeginStoryboard::StaticGetClassType()))
	{
		Class = UNoesisGuiBeginStoryboard::StaticClass();
	}
	if (BaseComponentClass == Noesis::Gui::ControllableStoryboardAction::StaticGetClassType() || BaseComponentClass->IsDescendantOf(Noesis::Gui::ControllableStoryboardAction::StaticGetClassType()))
	{
		Class = UNoesisGuiControllableStoryboardAction::StaticClass();
	}
	if (BaseComponentClass == Noesis::Gui::PauseStoryboard::StaticGetClassType() || BaseComponentClass->IsDescendantOf(Noesis::Gui::PauseStoryboard::StaticGetClassType()))
	{
		Class = UNoesisGuiPauseStoryboard::StaticClass();
	}
	if (BaseComponentClass == Noesis::Gui::ResumeStoryboard::StaticGetClassType() || BaseComponentClass->IsDescendantOf(Noesis::Gui::ResumeStoryboard::StaticGetClassType()))
	{
		Class = UNoesisGuiResumeStoryboard::StaticClass();
	}
	if (BaseComponentClass == Noesis::Gui::StopStoryboard::StaticGetClassType() || BaseComponentClass->IsDescendantOf(Noesis::Gui::StopStoryboard::StaticGetClassType()))
	{
		Class = UNoesisGuiStopStoryboard::StaticClass();
	}
	if (BaseComponentClass == Noesis::Gui::Visual::StaticGetClassType() || BaseComponentClass->IsDescendantOf(Noesis::Gui::Visual::StaticGetClassType()))
	{
		Class = UNoesisGuiVisual::StaticClass();
	}
	if (BaseComponentClass == Noesis::Gui::UIElement::StaticGetClassType() || BaseComponentClass->IsDescendantOf(Noesis::Gui::UIElement::StaticGetClassType()))
	{
		Class = UNoesisGuiUIElement::StaticClass();
	}
	if (BaseComponentClass == Noesis::Gui::FrameworkElement::StaticGetClassType() || BaseComponentClass->IsDescendantOf(Noesis::Gui::FrameworkElement::StaticGetClassType()))
	{
		Class = UNoesisGuiFrameworkElement::StaticClass();
	}
	if (BaseComponentClass == Noesis::Gui::BaseDefinition::StaticGetClassType() || BaseComponentClass->IsDescendantOf(Noesis::Gui::BaseDefinition::StaticGetClassType()))
	{
		Class = UNoesisGuiBaseDefinition::StaticClass();
	}
	if (BaseComponentClass == Noesis::Gui::ColumnDefinition::StaticGetClassType() || BaseComponentClass->IsDescendantOf(Noesis::Gui::ColumnDefinition::StaticGetClassType()))
	{
		Class = UNoesisGuiColumnDefinition::StaticClass();
	}
	if (BaseComponentClass == Noesis::Gui::RowDefinition::StaticGetClassType() || BaseComponentClass->IsDescendantOf(Noesis::Gui::RowDefinition::StaticGetClassType()))
	{
		Class = UNoesisGuiRowDefinition::StaticClass();
	}
	if (BaseComponentClass == Noesis::Gui::BaseGridViewRowPresenter::StaticGetClassType() || BaseComponentClass->IsDescendantOf(Noesis::Gui::BaseGridViewRowPresenter::StaticGetClassType()))
	{
		Class = UNoesisGuiBaseGridViewRowPresenter::StaticClass();
	}
	if (BaseComponentClass == Noesis::Gui::GridViewHeaderRowPresenter::StaticGetClassType() || BaseComponentClass->IsDescendantOf(Noesis::Gui::GridViewHeaderRowPresenter::StaticGetClassType()))
	{
		Class = UNoesisGuiGridViewHeaderRowPresenter::StaticClass();
	}
	if (BaseComponentClass == Noesis::Gui::GridViewRowPresenter::StaticGetClassType() || BaseComponentClass->IsDescendantOf(Noesis::Gui::GridViewRowPresenter::StaticGetClassType()))
	{
		Class = UNoesisGuiGridViewRowPresenter::StaticClass();
	}
	if (BaseComponentClass == Noesis::Gui::ContentPresenter::StaticGetClassType() || BaseComponentClass->IsDescendantOf(Noesis::Gui::ContentPresenter::StaticGetClassType()))
	{
		Class = UNoesisGuiContentPresenter::StaticClass();
	}
	if (BaseComponentClass == Noesis::Gui::ScrollContentPresenter::StaticGetClassType() || BaseComponentClass->IsDescendantOf(Noesis::Gui::ScrollContentPresenter::StaticGetClassType()))
	{
		Class = UNoesisGuiScrollContentPresenter::StaticClass();
	}
	if (BaseComponentClass == Noesis::Gui::Control::StaticGetClassType() || BaseComponentClass->IsDescendantOf(Noesis::Gui::Control::StaticGetClassType()))
	{
		Class = UNoesisGuiControl::StaticClass();
	}
	if (BaseComponentClass == Noesis::Gui::BaseTextBox::StaticGetClassType() || BaseComponentClass->IsDescendantOf(Noesis::Gui::BaseTextBox::StaticGetClassType()))
	{
		Class = UNoesisGuiBaseTextBox::StaticClass();
	}
	if (BaseComponentClass == Noesis::Gui::TextBox::StaticGetClassType() || BaseComponentClass->IsDescendantOf(Noesis::Gui::TextBox::StaticGetClassType()))
	{
		Class = UNoesisGuiTextBox::StaticClass();
	}
	if (BaseComponentClass == Noesis::Gui::ContentControl::StaticGetClassType() || BaseComponentClass->IsDescendantOf(Noesis::Gui::ContentControl::StaticGetClassType()))
	{
		Class = UNoesisGuiContentControl::StaticClass();
	}
	if (BaseComponentClass == Noesis::Gui::BaseButton::StaticGetClassType() || BaseComponentClass->IsDescendantOf(Noesis::Gui::BaseButton::StaticGetClassType()))
	{
		Class = UNoesisGuiBaseButton::StaticClass();
	}
	if (BaseComponentClass == Noesis::Gui::Button::StaticGetClassType() || BaseComponentClass->IsDescendantOf(Noesis::Gui::Button::StaticGetClassType()))
	{
		Class = UNoesisGuiButton::StaticClass();
	}
	if (BaseComponentClass == Noesis::Gui::GridViewColumnHeader::StaticGetClassType() || BaseComponentClass->IsDescendantOf(Noesis::Gui::GridViewColumnHeader::StaticGetClassType()))
	{
		Class = UNoesisGuiGridViewColumnHeader::StaticClass();
	}
	if (BaseComponentClass == Noesis::Gui::RepeatButton::StaticGetClassType() || BaseComponentClass->IsDescendantOf(Noesis::Gui::RepeatButton::StaticGetClassType()))
	{
		Class = UNoesisGuiRepeatButton::StaticClass();
	}
	if (BaseComponentClass == Noesis::Gui::ToggleButton::StaticGetClassType() || BaseComponentClass->IsDescendantOf(Noesis::Gui::ToggleButton::StaticGetClassType()))
	{
		Class = UNoesisGuiToggleButton::StaticClass();
	}
	if (BaseComponentClass == Noesis::Gui::CheckBox::StaticGetClassType() || BaseComponentClass->IsDescendantOf(Noesis::Gui::CheckBox::StaticGetClassType()))
	{
		Class = UNoesisGuiCheckBox::StaticClass();
	}
	if (BaseComponentClass == Noesis::Gui::RadioButton::StaticGetClassType() || BaseComponentClass->IsDescendantOf(Noesis::Gui::RadioButton::StaticGetClassType()))
	{
		Class = UNoesisGuiRadioButton::StaticClass();
	}
	if (BaseComponentClass == Noesis::Gui::HeaderedContentControl::StaticGetClassType() || BaseComponentClass->IsDescendantOf(Noesis::Gui::HeaderedContentControl::StaticGetClassType()))
	{
		Class = UNoesisGuiHeaderedContentControl::StaticClass();
	}
	if (BaseComponentClass == Noesis::Gui::Expander::StaticGetClassType() || BaseComponentClass->IsDescendantOf(Noesis::Gui::Expander::StaticGetClassType()))
	{
		Class = UNoesisGuiExpander::StaticClass();
	}
	if (BaseComponentClass == Noesis::Gui::GroupBox::StaticGetClassType() || BaseComponentClass->IsDescendantOf(Noesis::Gui::GroupBox::StaticGetClassType()))
	{
		Class = UNoesisGuiGroupBox::StaticClass();
	}
	if (BaseComponentClass == Noesis::Gui::TabItem::StaticGetClassType() || BaseComponentClass->IsDescendantOf(Noesis::Gui::TabItem::StaticGetClassType()))
	{
		Class = UNoesisGuiTabItem::StaticClass();
	}
	if (BaseComponentClass == Noesis::Gui::Label::StaticGetClassType() || BaseComponentClass->IsDescendantOf(Noesis::Gui::Label::StaticGetClassType()))
	{
		Class = UNoesisGuiLabel::StaticClass();
	}
	if (BaseComponentClass == Noesis::Gui::ListBoxItem::StaticGetClassType() || BaseComponentClass->IsDescendantOf(Noesis::Gui::ListBoxItem::StaticGetClassType()))
	{
		Class = UNoesisGuiListBoxItem::StaticClass();
	}
	if (BaseComponentClass == Noesis::Gui::ComboBoxItem::StaticGetClassType() || BaseComponentClass->IsDescendantOf(Noesis::Gui::ComboBoxItem::StaticGetClassType()))
	{
		Class = UNoesisGuiComboBoxItem::StaticClass();
	}
	if (BaseComponentClass == Noesis::Gui::ListViewItem::StaticGetClassType() || BaseComponentClass->IsDescendantOf(Noesis::Gui::ListViewItem::StaticGetClassType()))
	{
		Class = UNoesisGuiListViewItem::StaticClass();
	}
	if (BaseComponentClass == Noesis::Gui::ScrollViewer::StaticGetClassType() || BaseComponentClass->IsDescendantOf(Noesis::Gui::ScrollViewer::StaticGetClassType()))
	{
		Class = UNoesisGuiScrollViewer::StaticClass();
	}
	if (BaseComponentClass == Noesis::Gui::StatusBarItem::StaticGetClassType() || BaseComponentClass->IsDescendantOf(Noesis::Gui::StatusBarItem::StaticGetClassType()))
	{
		Class = UNoesisGuiStatusBarItem::StaticClass();
	}
	if (BaseComponentClass == Noesis::Gui::ToolTip::StaticGetClassType() || BaseComponentClass->IsDescendantOf(Noesis::Gui::ToolTip::StaticGetClassType()))
	{
		Class = UNoesisGuiToolTip::StaticClass();
	}
	if (BaseComponentClass == Noesis::Gui::UserControl::StaticGetClassType() || BaseComponentClass->IsDescendantOf(Noesis::Gui::UserControl::StaticGetClassType()))
	{
		Class = UNoesisGuiUserControl::StaticClass();
	}
	if (BaseComponentClass == Noesis::Gui::Page::StaticGetClassType() || BaseComponentClass->IsDescendantOf(Noesis::Gui::Page::StaticGetClassType()))
	{
		Class = UNoesisGuiPage::StaticClass();
	}
	if (BaseComponentClass == Noesis::Gui::ItemsControl::StaticGetClassType() || BaseComponentClass->IsDescendantOf(Noesis::Gui::ItemsControl::StaticGetClassType()))
	{
		Class = UNoesisGuiItemsControl::StaticClass();
	}
	if (BaseComponentClass == Noesis::Gui::BaseMenu::StaticGetClassType() || BaseComponentClass->IsDescendantOf(Noesis::Gui::BaseMenu::StaticGetClassType()))
	{
		Class = UNoesisGuiBaseMenu::StaticClass();
	}
	if (BaseComponentClass == Noesis::Gui::ContextMenu::StaticGetClassType() || BaseComponentClass->IsDescendantOf(Noesis::Gui::ContextMenu::StaticGetClassType()))
	{
		Class = UNoesisGuiContextMenu::StaticClass();
	}
	if (BaseComponentClass == Noesis::Gui::Menu::StaticGetClassType() || BaseComponentClass->IsDescendantOf(Noesis::Gui::Menu::StaticGetClassType()))
	{
		Class = UNoesisGuiMenu::StaticClass();
	}
	if (BaseComponentClass == Noesis::Gui::HeaderedItemsControl::StaticGetClassType() || BaseComponentClass->IsDescendantOf(Noesis::Gui::HeaderedItemsControl::StaticGetClassType()))
	{
		Class = UNoesisGuiHeaderedItemsControl::StaticClass();
	}
	if (BaseComponentClass == Noesis::Gui::MenuItem::StaticGetClassType() || BaseComponentClass->IsDescendantOf(Noesis::Gui::MenuItem::StaticGetClassType()))
	{
		Class = UNoesisGuiMenuItem::StaticClass();
	}
	if (BaseComponentClass == Noesis::Gui::ToolBar::StaticGetClassType() || BaseComponentClass->IsDescendantOf(Noesis::Gui::ToolBar::StaticGetClassType()))
	{
		Class = UNoesisGuiToolBar::StaticClass();
	}
	if (BaseComponentClass == Noesis::Gui::TreeViewItem::StaticGetClassType() || BaseComponentClass->IsDescendantOf(Noesis::Gui::TreeViewItem::StaticGetClassType()))
	{
		Class = UNoesisGuiTreeViewItem::StaticClass();
	}
	if (BaseComponentClass == Noesis::Gui::Selector::StaticGetClassType() || BaseComponentClass->IsDescendantOf(Noesis::Gui::Selector::StaticGetClassType()))
	{
		Class = UNoesisGuiSelector::StaticClass();
	}
	if (BaseComponentClass == Noesis::Gui::ComboBox::StaticGetClassType() || BaseComponentClass->IsDescendantOf(Noesis::Gui::ComboBox::StaticGetClassType()))
	{
		Class = UNoesisGuiComboBox::StaticClass();
	}
	if (BaseComponentClass == Noesis::Gui::ListBox::StaticGetClassType() || BaseComponentClass->IsDescendantOf(Noesis::Gui::ListBox::StaticGetClassType()))
	{
		Class = UNoesisGuiListBox::StaticClass();
	}
	if (BaseComponentClass == Noesis::Gui::ListView::StaticGetClassType() || BaseComponentClass->IsDescendantOf(Noesis::Gui::ListView::StaticGetClassType()))
	{
		Class = UNoesisGuiListView::StaticClass();
	}
	if (BaseComponentClass == Noesis::Gui::TabControl::StaticGetClassType() || BaseComponentClass->IsDescendantOf(Noesis::Gui::TabControl::StaticGetClassType()))
	{
		Class = UNoesisGuiTabControl::StaticClass();
	}
	if (BaseComponentClass == Noesis::Gui::StatusBar::StaticGetClassType() || BaseComponentClass->IsDescendantOf(Noesis::Gui::StatusBar::StaticGetClassType()))
	{
		Class = UNoesisGuiStatusBar::StaticClass();
	}
	if (BaseComponentClass == Noesis::Gui::TreeView::StaticGetClassType() || BaseComponentClass->IsDescendantOf(Noesis::Gui::TreeView::StaticGetClassType()))
	{
		Class = UNoesisGuiTreeView::StaticClass();
	}
	if (BaseComponentClass == Noesis::Gui::PasswordBox::StaticGetClassType() || BaseComponentClass->IsDescendantOf(Noesis::Gui::PasswordBox::StaticGetClassType()))
	{
		Class = UNoesisGuiPasswordBox::StaticClass();
	}
	if (BaseComponentClass == Noesis::Gui::RangeBase::StaticGetClassType() || BaseComponentClass->IsDescendantOf(Noesis::Gui::RangeBase::StaticGetClassType()))
	{
		Class = UNoesisGuiRangeBase::StaticClass();
	}
	if (BaseComponentClass == Noesis::Gui::ProgressBar::StaticGetClassType() || BaseComponentClass->IsDescendantOf(Noesis::Gui::ProgressBar::StaticGetClassType()))
	{
		Class = UNoesisGuiProgressBar::StaticClass();
	}
	if (BaseComponentClass == Noesis::Gui::ScrollBar::StaticGetClassType() || BaseComponentClass->IsDescendantOf(Noesis::Gui::ScrollBar::StaticGetClassType()))
	{
		Class = UNoesisGuiScrollBar::StaticClass();
	}
	if (BaseComponentClass == Noesis::Gui::Slider::StaticGetClassType() || BaseComponentClass->IsDescendantOf(Noesis::Gui::Slider::StaticGetClassType()))
	{
		Class = UNoesisGuiSlider::StaticClass();
	}
	if (BaseComponentClass == Noesis::Gui::Separator::StaticGetClassType() || BaseComponentClass->IsDescendantOf(Noesis::Gui::Separator::StaticGetClassType()))
	{
		Class = UNoesisGuiSeparator::StaticClass();
	}
	if (BaseComponentClass == Noesis::Gui::Thumb::StaticGetClassType() || BaseComponentClass->IsDescendantOf(Noesis::Gui::Thumb::StaticGetClassType()))
	{
		Class = UNoesisGuiThumb::StaticClass();
	}
	if (BaseComponentClass == Noesis::Gui::Decorator::StaticGetClassType() || BaseComponentClass->IsDescendantOf(Noesis::Gui::Decorator::StaticGetClassType()))
	{
		Class = UNoesisGuiDecorator::StaticClass();
	}
	if (BaseComponentClass == Noesis::Gui::AdornerDecorator::StaticGetClassType() || BaseComponentClass->IsDescendantOf(Noesis::Gui::AdornerDecorator::StaticGetClassType()))
	{
		Class = UNoesisGuiAdornerDecorator::StaticClass();
	}
	if (BaseComponentClass == Noesis::Gui::Border::StaticGetClassType() || BaseComponentClass->IsDescendantOf(Noesis::Gui::Border::StaticGetClassType()))
	{
		Class = UNoesisGuiBorder::StaticClass();
	}
	if (BaseComponentClass == Noesis::Gui::BulletDecorator::StaticGetClassType() || BaseComponentClass->IsDescendantOf(Noesis::Gui::BulletDecorator::StaticGetClassType()))
	{
		Class = UNoesisGuiBulletDecorator::StaticClass();
	}
	if (BaseComponentClass == Noesis::Gui::Image::StaticGetClassType() || BaseComponentClass->IsDescendantOf(Noesis::Gui::Image::StaticGetClassType()))
	{
		Class = UNoesisGuiImage::StaticClass();
	}
	if (BaseComponentClass == Noesis::Gui::ItemsPresenter::StaticGetClassType() || BaseComponentClass->IsDescendantOf(Noesis::Gui::ItemsPresenter::StaticGetClassType()))
	{
		Class = UNoesisGuiItemsPresenter::StaticClass();
	}
	if (BaseComponentClass == Noesis::Gui::Panel::StaticGetClassType() || BaseComponentClass->IsDescendantOf(Noesis::Gui::Panel::StaticGetClassType()))
	{
		Class = UNoesisGuiPanel::StaticClass();
	}
	if (BaseComponentClass == Noesis::Gui::Canvas::StaticGetClassType() || BaseComponentClass->IsDescendantOf(Noesis::Gui::Canvas::StaticGetClassType()))
	{
		Class = UNoesisGuiCanvas::StaticClass();
	}
	if (BaseComponentClass == Noesis::Gui::DockPanel::StaticGetClassType() || BaseComponentClass->IsDescendantOf(Noesis::Gui::DockPanel::StaticGetClassType()))
	{
		Class = UNoesisGuiDockPanel::StaticClass();
	}
	if (BaseComponentClass == Noesis::Gui::Grid::StaticGetClassType() || BaseComponentClass->IsDescendantOf(Noesis::Gui::Grid::StaticGetClassType()))
	{
		Class = UNoesisGuiGrid::StaticClass();
	}
	if (BaseComponentClass == Noesis::Gui::StackPanel::StaticGetClassType() || BaseComponentClass->IsDescendantOf(Noesis::Gui::StackPanel::StaticGetClassType()))
	{
		Class = UNoesisGuiStackPanel::StaticClass();
	}
	if (BaseComponentClass == Noesis::Gui::ToolBarPanel::StaticGetClassType() || BaseComponentClass->IsDescendantOf(Noesis::Gui::ToolBarPanel::StaticGetClassType()))
	{
		Class = UNoesisGuiToolBarPanel::StaticClass();
	}
	if (BaseComponentClass == Noesis::Gui::TabPanel::StaticGetClassType() || BaseComponentClass->IsDescendantOf(Noesis::Gui::TabPanel::StaticGetClassType()))
	{
		Class = UNoesisGuiTabPanel::StaticClass();
	}
	if (BaseComponentClass == Noesis::Gui::ToolBarOverflowPanel::StaticGetClassType() || BaseComponentClass->IsDescendantOf(Noesis::Gui::ToolBarOverflowPanel::StaticGetClassType()))
	{
		Class = UNoesisGuiToolBarOverflowPanel::StaticClass();
	}
	if (BaseComponentClass == Noesis::Gui::UniformGrid::StaticGetClassType() || BaseComponentClass->IsDescendantOf(Noesis::Gui::UniformGrid::StaticGetClassType()))
	{
		Class = UNoesisGuiUniformGrid::StaticClass();
	}
	if (BaseComponentClass == Noesis::Gui::VirtualizingPanel::StaticGetClassType() || BaseComponentClass->IsDescendantOf(Noesis::Gui::VirtualizingPanel::StaticGetClassType()))
	{
		Class = UNoesisGuiVirtualizingPanel::StaticClass();
	}
	if (BaseComponentClass == Noesis::Gui::VirtualizingStackPanel::StaticGetClassType() || BaseComponentClass->IsDescendantOf(Noesis::Gui::VirtualizingStackPanel::StaticGetClassType()))
	{
		Class = UNoesisGuiVirtualizingStackPanel::StaticClass();
	}
	if (BaseComponentClass == Noesis::Gui::WrapPanel::StaticGetClassType() || BaseComponentClass->IsDescendantOf(Noesis::Gui::WrapPanel::StaticGetClassType()))
	{
		Class = UNoesisGuiWrapPanel::StaticClass();
	}
	if (BaseComponentClass == Noesis::Gui::Popup::StaticGetClassType() || BaseComponentClass->IsDescendantOf(Noesis::Gui::Popup::StaticGetClassType()))
	{
		Class = UNoesisGuiPopup::StaticClass();
	}
	if (BaseComponentClass == Noesis::Gui::Shape::StaticGetClassType() || BaseComponentClass->IsDescendantOf(Noesis::Gui::Shape::StaticGetClassType()))
	{
		Class = UNoesisGuiShape::StaticClass();
	}
	if (BaseComponentClass == Noesis::Gui::Ellipse::StaticGetClassType() || BaseComponentClass->IsDescendantOf(Noesis::Gui::Ellipse::StaticGetClassType()))
	{
		Class = UNoesisGuiEllipse::StaticClass();
	}
	if (BaseComponentClass == Noesis::Gui::Line::StaticGetClassType() || BaseComponentClass->IsDescendantOf(Noesis::Gui::Line::StaticGetClassType()))
	{
		Class = UNoesisGuiLine::StaticClass();
	}
	if (BaseComponentClass == Noesis::Gui::Path::StaticGetClassType() || BaseComponentClass->IsDescendantOf(Noesis::Gui::Path::StaticGetClassType()))
	{
		Class = UNoesisGuiPath::StaticClass();
	}
	if (BaseComponentClass == Noesis::Gui::Rectangle::StaticGetClassType() || BaseComponentClass->IsDescendantOf(Noesis::Gui::Rectangle::StaticGetClassType()))
	{
		Class = UNoesisGuiRectangle::StaticClass();
	}
	if (BaseComponentClass == Noesis::Gui::TextBlock::StaticGetClassType() || BaseComponentClass->IsDescendantOf(Noesis::Gui::TextBlock::StaticGetClassType()))
	{
		Class = UNoesisGuiTextBlock::StaticClass();
	}
	if (BaseComponentClass == Noesis::Gui::TickBar::StaticGetClassType() || BaseComponentClass->IsDescendantOf(Noesis::Gui::TickBar::StaticGetClassType()))
	{
		Class = UNoesisGuiTickBar::StaticClass();
	}
	if (BaseComponentClass == Noesis::Gui::ToolBarTray::StaticGetClassType() || BaseComponentClass->IsDescendantOf(Noesis::Gui::ToolBarTray::StaticGetClassType()))
	{
		Class = UNoesisGuiToolBarTray::StaticClass();
	}
	if (BaseComponentClass == Noesis::Gui::Track::StaticGetClassType() || BaseComponentClass->IsDescendantOf(Noesis::Gui::Track::StaticGetClassType()))
	{
		Class = UNoesisGuiTrack::StaticClass();
	}
	if (BaseComponentClass == Noesis::Gui::Viewbox::StaticGetClassType() || BaseComponentClass->IsDescendantOf(Noesis::Gui::Viewbox::StaticGetClassType()))
	{
		Class = UNoesisGuiViewbox::StaticClass();
	}
	if (BaseComponentClass == Noesis::Gui::VisualState::StaticGetClassType() || BaseComponentClass->IsDescendantOf(Noesis::Gui::VisualState::StaticGetClassType()))
	{
		Class = UNoesisGuiVisualState::StaticClass();
	}
	if (BaseComponentClass == Noesis::Gui::VisualStateGroup::StaticGetClassType() || BaseComponentClass->IsDescendantOf(Noesis::Gui::VisualStateGroup::StaticGetClassType()))
	{
		Class = UNoesisGuiVisualStateGroup::StaticClass();
	}
	if (BaseComponentClass == Noesis::Gui::VisualTransition::StaticGetClassType() || BaseComponentClass->IsDescendantOf(Noesis::Gui::VisualTransition::StaticGetClassType()))
	{
		Class = UNoesisGuiVisualTransition::StaticClass();
	}
	if (BaseComponentClass == Noesis::Gui::DependencyProperty::StaticGetClassType() || BaseComponentClass->IsDescendantOf(Noesis::Gui::DependencyProperty::StaticGetClassType()))
	{
		Class = UNoesisGuiDependencyProperty::StaticClass();
	}
	if (BaseComponentClass == Noesis::Gui::Expression::StaticGetClassType() || BaseComponentClass->IsDescendantOf(Noesis::Gui::Expression::StaticGetClassType()))
	{
		Class = UNoesisGuiExpression::StaticClass();
	}
	if (BaseComponentClass == Noesis::Gui::BaseBindingExpression::StaticGetClassType() || BaseComponentClass->IsDescendantOf(Noesis::Gui::BaseBindingExpression::StaticGetClassType()))
	{
		Class = UNoesisGuiBaseBindingExpression::StaticClass();
	}
	if (BaseComponentClass == Noesis::Gui::BindingExpression::StaticGetClassType() || BaseComponentClass->IsDescendantOf(Noesis::Gui::BindingExpression::StaticGetClassType()))
	{
		Class = UNoesisGuiBindingExpression::StaticClass();
	}
	if (BaseComponentClass == Noesis::Gui::TemplateBindingExpression::StaticGetClassType() || BaseComponentClass->IsDescendantOf(Noesis::Gui::TemplateBindingExpression::StaticGetClassType()))
	{
		Class = UNoesisGuiTemplateBindingExpression::StaticClass();
	}
	if (BaseComponentClass == Noesis::Gui::FrameworkTemplate::StaticGetClassType() || BaseComponentClass->IsDescendantOf(Noesis::Gui::FrameworkTemplate::StaticGetClassType()))
	{
		Class = UNoesisGuiFrameworkTemplate::StaticClass();
	}
	if (BaseComponentClass == Noesis::Gui::ControlTemplate::StaticGetClassType() || BaseComponentClass->IsDescendantOf(Noesis::Gui::ControlTemplate::StaticGetClassType()))
	{
		Class = UNoesisGuiControlTemplate::StaticClass();
	}
	if (BaseComponentClass == Noesis::Gui::DataTemplate::StaticGetClassType() || BaseComponentClass->IsDescendantOf(Noesis::Gui::DataTemplate::StaticGetClassType()))
	{
		Class = UNoesisGuiDataTemplate::StaticClass();
	}
	if (BaseComponentClass == Noesis::Gui::HierarchicalDataTemplate::StaticGetClassType() || BaseComponentClass->IsDescendantOf(Noesis::Gui::HierarchicalDataTemplate::StaticGetClassType()))
	{
		Class = UNoesisGuiHierarchicalDataTemplate::StaticClass();
	}
	if (BaseComponentClass == Noesis::Gui::ItemsPanelTemplate::StaticGetClassType() || BaseComponentClass->IsDescendantOf(Noesis::Gui::ItemsPanelTemplate::StaticGetClassType()))
	{
		Class = UNoesisGuiItemsPanelTemplate::StaticClass();
	}
	if (BaseComponentClass == Noesis::Gui::InputGesture::StaticGetClassType() || BaseComponentClass->IsDescendantOf(Noesis::Gui::InputGesture::StaticGetClassType()))
	{
		Class = UNoesisGuiInputGesture::StaticClass();
	}
	if (BaseComponentClass == Noesis::Gui::KeyGesture::StaticGetClassType() || BaseComponentClass->IsDescendantOf(Noesis::Gui::KeyGesture::StaticGetClassType()))
	{
		Class = UNoesisGuiKeyGesture::StaticClass();
	}
	if (BaseComponentClass == Noesis::Gui::ItemCollection::StaticGetClassType() || BaseComponentClass->IsDescendantOf(Noesis::Gui::ItemCollection::StaticGetClassType()))
	{
		Class = UNoesisGuiItemCollection::StaticClass();
	}
	if (BaseComponentClass == Noesis::Gui::ItemContainerGenerator::StaticGetClassType() || BaseComponentClass->IsDescendantOf(Noesis::Gui::ItemContainerGenerator::StaticGetClassType()))
	{
		Class = UNoesisGuiItemContainerGenerator::StaticClass();
	}
	if (BaseComponentClass == Noesis::Gui::Keyboard::StaticGetClassType() || BaseComponentClass->IsDescendantOf(Noesis::Gui::Keyboard::StaticGetClassType()))
	{
		Class = UNoesisGuiKeyboard::StaticClass();
	}
	if (BaseComponentClass == Noesis::Gui::KeyboardNavigation::StaticGetClassType() || BaseComponentClass->IsDescendantOf(Noesis::Gui::KeyboardNavigation::StaticGetClassType()))
	{
		Class = UNoesisGuiKeyboardNavigation::StaticClass();
	}
	if (BaseComponentClass == Noesis::Gui::Mouse::StaticGetClassType() || BaseComponentClass->IsDescendantOf(Noesis::Gui::Mouse::StaticGetClassType()))
	{
		Class = UNoesisGuiMouse::StaticClass();
	}
	if (BaseComponentClass == Noesis::Gui::PropertyMetadata::StaticGetClassType() || BaseComponentClass->IsDescendantOf(Noesis::Gui::PropertyMetadata::StaticGetClassType()))
	{
		Class = UNoesisGuiPropertyMetadata::StaticClass();
	}
	if (BaseComponentClass == Noesis::Gui::PropertyPath::StaticGetClassType() || BaseComponentClass->IsDescendantOf(Noesis::Gui::PropertyPath::StaticGetClassType()))
	{
		Class = UNoesisGuiPropertyPath::StaticClass();
	}
	if (BaseComponentClass == Noesis::Gui::RelativeSource::StaticGetClassType() || BaseComponentClass->IsDescendantOf(Noesis::Gui::RelativeSource::StaticGetClassType()))
	{
		Class = UNoesisGuiRelativeSource::StaticClass();
	}
	if (BaseComponentClass == Noesis::Gui::ResourceKeyType::StaticGetClassType() || BaseComponentClass->IsDescendantOf(Noesis::Gui::ResourceKeyType::StaticGetClassType()))
	{
		Class = UNoesisGuiResourceKeyType::StaticClass();
	}
	if (BaseComponentClass == Noesis::Gui::RoutedCommand::StaticGetClassType() || BaseComponentClass->IsDescendantOf(Noesis::Gui::RoutedCommand::StaticGetClassType()))
	{
		Class = UNoesisGuiRoutedCommand::StaticClass();
	}
	if (BaseComponentClass == Noesis::Gui::RoutedUICommand::StaticGetClassType() || BaseComponentClass->IsDescendantOf(Noesis::Gui::RoutedUICommand::StaticGetClassType()))
	{
		Class = UNoesisGuiRoutedUICommand::StaticClass();
	}
	if (BaseComponentClass == Noesis::Gui::RoutedEvent::StaticGetClassType() || BaseComponentClass->IsDescendantOf(Noesis::Gui::RoutedEvent::StaticGetClassType()))
	{
		Class = UNoesisGuiRoutedEvent::StaticClass();
	}
	if (BaseComponentClass == Noesis::Gui::Style::StaticGetClassType() || BaseComponentClass->IsDescendantOf(Noesis::Gui::Style::StaticGetClassType()))
	{
		Class = UNoesisGuiStyle::StaticClass();
	}
	if (BaseComponentClass == Noesis::Gui::TemplateBindingExtension::StaticGetClassType() || BaseComponentClass->IsDescendantOf(Noesis::Gui::TemplateBindingExtension::StaticGetClassType()))
	{
		Class = UNoesisGuiTemplateBindingExtension::StaticClass();
	}
	if (BaseComponentClass == Noesis::Gui::ToolTipService::StaticGetClassType() || BaseComponentClass->IsDescendantOf(Noesis::Gui::ToolTipService::StaticGetClassType()))
	{
		Class = UNoesisGuiToolTipService::StaticClass();
	}
	if (BaseComponentClass == Noesis::Gui::ThicknessKeyFrameCollection::StaticGetClassType() || BaseComponentClass->IsDescendantOf(Noesis::Gui::ThicknessKeyFrameCollection::StaticGetClassType()))
	{
		Class = UNoesisGuiThicknessKeyFrameCollection::StaticClass();
	}
	if (BaseComponentClass == Noesis::Gui::ColorKeyFrameCollection::StaticGetClassType() || BaseComponentClass->IsDescendantOf(Noesis::Gui::ColorKeyFrameCollection::StaticGetClassType()))
	{
		Class = UNoesisGuiColorKeyFrameCollection::StaticClass();
	}
	if (BaseComponentClass == Noesis::Gui::SizeKeyFrameCollection::StaticGetClassType() || BaseComponentClass->IsDescendantOf(Noesis::Gui::SizeKeyFrameCollection::StaticGetClassType()))
	{
		Class = UNoesisGuiSizeKeyFrameCollection::StaticClass();
	}
	if (BaseComponentClass == Noesis::Gui::ObjectKeyFrameCollection::StaticGetClassType() || BaseComponentClass->IsDescendantOf(Noesis::Gui::ObjectKeyFrameCollection::StaticGetClassType()))
	{
		Class = UNoesisGuiObjectKeyFrameCollection::StaticClass();
	}
	if (BaseComponentClass == Noesis::Gui::BooleanKeyFrameCollection::StaticGetClassType() || BaseComponentClass->IsDescendantOf(Noesis::Gui::BooleanKeyFrameCollection::StaticGetClassType()))
	{
		Class = UNoesisGuiBooleanKeyFrameCollection::StaticClass();
	}
	if (BaseComponentClass == Noesis::Gui::Int32KeyFrameCollection::StaticGetClassType() || BaseComponentClass->IsDescendantOf(Noesis::Gui::Int32KeyFrameCollection::StaticGetClassType()))
	{
		Class = UNoesisGuiInt32KeyFrameCollection::StaticClass();
	}
	if (BaseComponentClass == Noesis::Gui::DoubleKeyFrameCollection::StaticGetClassType() || BaseComponentClass->IsDescendantOf(Noesis::Gui::DoubleKeyFrameCollection::StaticGetClassType()))
	{
		Class = UNoesisGuiDoubleKeyFrameCollection::StaticClass();
	}
	if (BaseComponentClass == Noesis::Gui::Int16KeyFrameCollection::StaticGetClassType() || BaseComponentClass->IsDescendantOf(Noesis::Gui::Int16KeyFrameCollection::StaticGetClassType()))
	{
		Class = UNoesisGuiInt16KeyFrameCollection::StaticClass();
	}
	if (BaseComponentClass == Noesis::Gui::StringKeyFrameCollection::StaticGetClassType() || BaseComponentClass->IsDescendantOf(Noesis::Gui::StringKeyFrameCollection::StaticGetClassType()))
	{
		Class = UNoesisGuiStringKeyFrameCollection::StaticClass();
	}
	if (BaseComponentClass == Noesis::Gui::PointKeyFrameCollection::StaticGetClassType() || BaseComponentClass->IsDescendantOf(Noesis::Gui::PointKeyFrameCollection::StaticGetClassType()))
	{
		Class = UNoesisGuiPointKeyFrameCollection::StaticClass();
	}
	if (BaseComponentClass == Noesis::Gui::RectKeyFrameCollection::StaticGetClassType() || BaseComponentClass->IsDescendantOf(Noesis::Gui::RectKeyFrameCollection::StaticGetClassType()))
	{
		Class = UNoesisGuiRectKeyFrameCollection::StaticClass();
	}
	if (BaseComponentClass == Noesis::Gui::VirtualizationCacheLength::StaticGetClassType() || BaseComponentClass->IsDescendantOf(Noesis::Gui::VirtualizationCacheLength::StaticGetClassType()))
	{
		Class = UNoesisGuiVirtualizationCacheLength::StaticClass();
	}
	if (BaseComponentClass == Noesis::Gui::VisualStateManager::StaticGetClassType() || BaseComponentClass->IsDescendantOf(Noesis::Gui::VisualStateManager::StaticGetClassType()))
	{
		Class = UNoesisGuiVisualStateManager::StaticClass();
	}
	UNoesisGuiBaseComponent* Component = NewObject<UNoesisGuiBaseComponent>(Outer, Class);
	Component->SetNoesisComponent(BaseComponent);
	return Component;
}

