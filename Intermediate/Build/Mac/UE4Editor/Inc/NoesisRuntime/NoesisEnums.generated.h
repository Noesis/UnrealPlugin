// Copyright 1998-2017 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "ObjectMacros.h"
#include "ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
#ifdef NOESISRUNTIME_NoesisEnums_generated_h
#error "NoesisEnums.generated.h already included, missing '#pragma once' in NoesisEnums.h"
#endif
#define NOESISRUNTIME_NoesisEnums_generated_h

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID HostProject_Plugins_NoesisGUI_Source_NoesisRuntime_Classes_NoesisEnums_h


#define FOREACH_ENUM_ENOESISNOTIFYCOLLECTIONCHANGEDACTION(op) \
	op(ENoesisNotifyCollectionChangedAction::Add) \
	op(ENoesisNotifyCollectionChangedAction::Remove) \
	op(ENoesisNotifyCollectionChangedAction::Replace) \
	op(ENoesisNotifyCollectionChangedAction::Move) \
	op(ENoesisNotifyCollectionChangedAction::Reset) 
#define FOREACH_ENUM_ENOESISPLACEMENTMODE(op) \
	op(ENoesisPlacementMode::Absolute) \
	op(ENoesisPlacementMode::Relative) \
	op(ENoesisPlacementMode::Bottom) \
	op(ENoesisPlacementMode::Center) \
	op(ENoesisPlacementMode::Right) \
	op(ENoesisPlacementMode::AbsolutePoint) \
	op(ENoesisPlacementMode::RelativePoint) \
	op(ENoesisPlacementMode::Mouse) \
	op(ENoesisPlacementMode::MousePoint) \
	op(ENoesisPlacementMode::Left) \
	op(ENoesisPlacementMode::Top) 
#define FOREACH_ENUM_ENOESISCOLORINTERPOLATIONMODE(op) \
	op(ENoesisColorInterpolationMode::ScRgbLinearInterpolation) 
#define FOREACH_ENUM_ENOESISMENUITEMROLE(op) \
	op(ENoesisMenuItemRole::TopLevelItem) \
	op(ENoesisMenuItemRole::TopLevelHeader) \
	op(ENoesisMenuItemRole::SubmenuItem) 
#define FOREACH_ENUM_ENOESISGEOMETRYCOMBINEMODE(op) \
	op(ENoesisGeometryCombineMode::Union) \
	op(ENoesisGeometryCombineMode::Intersect) \
	op(ENoesisGeometryCombineMode::Xor) 
#define FOREACH_ENUM_ENOESISFILLBEHAVIOR(op) \
	op(ENoesisFillBehavior::HoldEnd) 
#define FOREACH_ENUM_ENOESISFONTSTRETCH(op) \
	op(ENoesisFontStretch::UltraCondensed) \
	op(ENoesisFontStretch::ExtraCondensed) \
	op(ENoesisFontStretch::Condensed) \
	op(ENoesisFontStretch::SemiCondensed) \
	op(ENoesisFontStretch::Normal) \
	op(ENoesisFontStretch::SemiExpanded) \
	op(ENoesisFontStretch::Expanded) \
	op(ENoesisFontStretch::ExtraExpanded) 
#define FOREACH_ENUM_ENOESISFONTWEIGHT(op) \
	op(ENoesisFontWeight::Thin) \
	op(ENoesisFontWeight::ExtraLight) \
	op(ENoesisFontWeight::Light) \
	op(ENoesisFontWeight::SemiLight) \
	op(ENoesisFontWeight::Normal) \
	op(ENoesisFontWeight::Medium) \
	op(ENoesisFontWeight::SemiBold) \
	op(ENoesisFontWeight::Bold) \
	op(ENoesisFontWeight::ExtraBold) \
	op(ENoesisFontWeight::Black) 
#define FOREACH_ENUM_ENOESISORIENTATION(op) \
	op(ENoesisOrientation::Horizontal) 
#define FOREACH_ENUM_ENOESISGRADIENTSPREADMETHOD(op) \
	op(ENoesisGradientSpreadMethod::Pad) \
	op(ENoesisGradientSpreadMethod::Reflect) 
#define FOREACH_ENUM_ENOESISTEXTTRIMMING(op) \
	op(ENoesisTextTrimming::None) \
	op(ENoesisTextTrimming::CharacterEllipsis) 
#define FOREACH_ENUM_ENOESISFILLRULE(op) \
	op(ENoesisFillRule::EvenOdd) 
#define FOREACH_ENUM_ENOESISTILEMODE(op) \
	op(ENoesisTileMode::None) \
	op(ENoesisTileMode::Tile) \
	op(ENoesisTileMode::FlipX) \
	op(ENoesisTileMode::FlipY) 
#define FOREACH_ENUM_ENOESISSGUIGRIDUNITTYPE(op) \
	op(ENoesissGuiGridUnitType::Auto) \
	op(ENoesissGuiGridUnitType::Pixel) 
#define FOREACH_ENUM_ENOESISFONTSTYLE(op) \
	op(ENoesisFontStyle::Normal) \
	op(ENoesisFontStyle::Italic) 
#define FOREACH_ENUM_ENOESISALIGNMENTX(op) \
	op(ENoesisAlignmentX::Left) \
	op(ENoesisAlignmentX::Center) 
#define FOREACH_ENUM_ENOESISALIGNMENTY(op) \
	op(ENoesisAlignmentY::Top) \
	op(ENoesisAlignmentY::Center) 
#define FOREACH_ENUM_ENOESISHORIZONTALALIGNMENT(op) \
	op(ENoesisHorizontalAlignment::Left) \
	op(ENoesisHorizontalAlignment::Center) \
	op(ENoesisHorizontalAlignment::Right) 
#define FOREACH_ENUM_ENOESISPOPUPANIMATION(op) \
	op(ENoesisPopupAnimation::None) \
	op(ENoesisPopupAnimation::Fade) \
	op(ENoesisPopupAnimation::Slide) 
#define FOREACH_ENUM_ENOESISSLIPBEHAVIOR(op) \
	op(ENoesisSlipBehavior::Grow) 
#define FOREACH_ENUM_ENOESISPENLINEJOIN(op) \
	op(ENoesisPenLineJoin::Miter) \
	op(ENoesisPenLineJoin::Bevel) 
#define FOREACH_ENUM_ENOESISBRUSHMAPPINGMODE(op) \
	op(ENoesisBrushMappingMode::Absolute) 
#define FOREACH_ENUM_ENOESISEXPANDDIRECTION(op) \
	op(ENoesisExpandDirection::Down) \
	op(ENoesisExpandDirection::Up) \
	op(ENoesisExpandDirection::Left) 
#define FOREACH_ENUM_ENOESISPENLINECAP(op) \
	op(ENoesisPenLineCap::Flat) \
	op(ENoesisPenLineCap::Square) \
	op(ENoesisPenLineCap::Round) 
#define FOREACH_ENUM_ENOESISVISIBILITY(op) \
	op(ENoesisVisibility::Collapsed) \
	op(ENoesisVisibility::Hidden) 
#define FOREACH_ENUM_ENOESISPANNINGMODE(op) \
	op(ENoesisPanningMode::Both) \
	op(ENoesisPanningMode::HorizontalFirst) \
	op(ENoesisPanningMode::HorizontalOnly) \
	op(ENoesisPanningMode::None) \
	op(ENoesisPanningMode::VerticalFirst) 
#define FOREACH_ENUM_ENOESISTEXTALIGNMENT(op) \
	op(ENoesisTextAlignment::Center) \
	op(ENoesisTextAlignment::Justify) \
	op(ENoesisTextAlignment::Left) 
#define FOREACH_ENUM_ENOESISEASINGMODE(op) \
	op(ENoesisEasingMode::EaseOut) \
	op(ENoesisEasingMode::EaseIn) 
#define FOREACH_ENUM_ENOESISSELECTIONMODE(op) \
	op(ENoesisSelectionMode::Single) \
	op(ENoesisSelectionMode::Multiple) 
#define FOREACH_ENUM_ENOESISTICKPLACEMENT(op) \
	op(ENoesisTickPlacement::None) \
	op(ENoesisTickPlacement::TopLeft) \
	op(ENoesisTickPlacement::BottomRight) 
#define FOREACH_ENUM_ENOESISSTRETCHDIRECTION(op) \
	op(ENoesisStretchDirection::UpOnly) \
	op(ENoesisStretchDirection::DownOnly) 
#define FOREACH_ENUM_ENOESISVERTICALALIGNMENT(op) \
	op(ENoesisVerticalAlignment::Top) \
	op(ENoesisVerticalAlignment::Center) \
	op(ENoesisVerticalAlignment::Bottom) 
#define FOREACH_ENUM_ENOESISREPEATMODE(op) \
	op(ENoesisRepeatMode::Count) \
	op(ENoesisRepeatMode::Duration) 
#define FOREACH_ENUM_ENOESISGRIDVIEWCOLUMNHEADERROLE(op) \
	op(ENoesisGridViewColumnHeaderRole::Normal) \
	op(ENoesisGridViewColumnHeaderRole::Floating) 
#define FOREACH_ENUM_ENOESISTEXTWRAPPING(op) \
	op(ENoesisTextWrapping::NoWrap) \
	op(ENoesisTextWrapping::Wrap) 
#define FOREACH_ENUM_ENOESISTICKBARPLACEMENT(op) \
	op(ENoesisTickBarPlacement::Left) \
	op(ENoesisTickBarPlacement::Top) \
	op(ENoesisTickBarPlacement::Right) 
#define FOREACH_ENUM_ENOESISSCROLLBARVISIBILITY(op) \
	op(ENoesisScrollBarVisibility::Disabled) \
	op(ENoesisScrollBarVisibility::Auto) \
	op(ENoesisScrollBarVisibility::Hidden) 
#define FOREACH_ENUM_ENOESISCLICKMODE(op) \
	op(ENoesisClickMode::Hover) \
	op(ENoesisClickMode::Press) 
#define FOREACH_ENUM_ENOESISMANIPULATIONMODES(op) \
	op(ENoesisManipulationModes::None) \
	op(ENoesisManipulationModes::Rotate) \
	op(ENoesisManipulationModes::Scale) \
	op(ENoesisManipulationModes::TranslateX) \
	op(ENoesisManipulationModes::TranslateY) \
	op(ENoesisManipulationModes::Translate) 
#define FOREACH_ENUM_ENOESISDOCK(op) \
	op(ENoesisDock::Left) \
	op(ENoesisDock::Top) \
	op(ENoesisDock::Right) 
#define FOREACH_ENUM_ENOESISSTRETCH(op) \
	op(ENoesisStretch::None) \
	op(ENoesisStretch::Fill) \
	op(ENoesisStretch::Uniform) 
#define FOREACH_ENUM_ENOESISCLOCKSTATE(op) \
	op(ENoesisClockState::Active) \
	op(ENoesisClockState::Paused) \
	op(ENoesisClockState::Filling) \
	op(ENoesisClockState::Stopped) 
#define FOREACH_ENUM_ENOESISMESSAGEDIALOGIMAGE(op) \
	op(ENoesisMessageDialogImage::None) \
	op(ENoesisMessageDialogImage::Hand) \
	op(ENoesisMessageDialogImage::Question) \
	op(ENoesisMessageDialogImage::Exclamation) \
	op(ENoesisMessageDialogImage::Asterisk) \
	op(ENoesisMessageDialogImage::Stop) \
	op(ENoesisMessageDialogImage::Error) \
	op(ENoesisMessageDialogImage::Warning) 
#define FOREACH_ENUM_ENOESISMESSAGEDIALOGBUTTON(op) \
	op(ENoesisMessageDialogButton::Ok) \
	op(ENoesisMessageDialogButton::OkCancel) \
	op(ENoesisMessageDialogButton::YesNo) 
#define FOREACH_ENUM_ENOESISMESSAGEDIALOGRESULT(op) \
	op(ENoesisMessageDialogResult::Ok) \
	op(ENoesisMessageDialogResult::Cancel) \
	op(ENoesisMessageDialogResult::Yes) 
#define FOREACH_ENUM_ENOESISBEFORESETACTION(op) \
	op(ENoesisBeforeSetAction::Delete) 
#define FOREACH_ENUM_ENOESISEVALUATEBEHAVIOR(op) \
	op(ENoesisEvaluateBehavior::Default) 
#define FOREACH_ENUM_ENOESISKEY(op) \
	op(ENoesisKey::None) \
	op(ENoesisKey::Back) \
	op(ENoesisKey::Tab) \
	op(ENoesisKey::Clear) \
	op(ENoesisKey::Return) \
	op(ENoesisKey::Pause) \
	op(ENoesisKey::Shift) \
	op(ENoesisKey::Control) \
	op(ENoesisKey::Alt) \
	op(ENoesisKey::Escape) \
	op(ENoesisKey::Space) \
	op(ENoesisKey::Prior) \
	op(ENoesisKey::Next) \
	op(ENoesisKey::End) \
	op(ENoesisKey::Home) \
	op(ENoesisKey::Left) \
	op(ENoesisKey::Up) \
	op(ENoesisKey::Right) \
	op(ENoesisKey::Down) \
	op(ENoesisKey::Select) \
	op(ENoesisKey::Print) \
	op(ENoesisKey::Execute) \
	op(ENoesisKey::SnapShot) \
	op(ENoesisKey::Insert) \
	op(ENoesisKey::Delete) \
	op(ENoesisKey::Help) \
	op(ENoesisKey::Num0) \
	op(ENoesisKey::Num1) \
	op(ENoesisKey::Num2) \
	op(ENoesisKey::Num3) \
	op(ENoesisKey::Num4) \
	op(ENoesisKey::Num5) \
	op(ENoesisKey::Num6) \
	op(ENoesisKey::Num7) \
	op(ENoesisKey::Num8) \
	op(ENoesisKey::Num9) \
	op(ENoesisKey::Pad0) \
	op(ENoesisKey::Pad1) \
	op(ENoesisKey::Pad2) \
	op(ENoesisKey::Pad3) \
	op(ENoesisKey::Pad4) \
	op(ENoesisKey::Pad5) \
	op(ENoesisKey::Pad6) \
	op(ENoesisKey::Pad7) \
	op(ENoesisKey::Pad8) \
	op(ENoesisKey::Pad9) \
	op(ENoesisKey::Multiply) \
	op(ENoesisKey::Add) \
	op(ENoesisKey::Separator) \
	op(ENoesisKey::Subtract) \
	op(ENoesisKey::Decimal) \
	op(ENoesisKey::Divide) \
	op(ENoesisKey::A) \
	op(ENoesisKey::B) \
	op(ENoesisKey::C) \
	op(ENoesisKey::D) \
	op(ENoesisKey::E) \
	op(ENoesisKey::F) \
	op(ENoesisKey::G) \
	op(ENoesisKey::H) \
	op(ENoesisKey::I) \
	op(ENoesisKey::J) \
	op(ENoesisKey::K) \
	op(ENoesisKey::L) \
	op(ENoesisKey::M) \
	op(ENoesisKey::N) \
	op(ENoesisKey::O) \
	op(ENoesisKey::P) \
	op(ENoesisKey::Q) \
	op(ENoesisKey::R) \
	op(ENoesisKey::S) \
	op(ENoesisKey::T) \
	op(ENoesisKey::U) \
	op(ENoesisKey::V) \
	op(ENoesisKey::W) \
	op(ENoesisKey::X) \
	op(ENoesisKey::Y) \
	op(ENoesisKey::Z) \
	op(ENoesisKey::F1) \
	op(ENoesisKey::F2) \
	op(ENoesisKey::F3) \
	op(ENoesisKey::F4) \
	op(ENoesisKey::F5) \
	op(ENoesisKey::F6) \
	op(ENoesisKey::F7) \
	op(ENoesisKey::F8) \
	op(ENoesisKey::F9) \
	op(ENoesisKey::F10) \
	op(ENoesisKey::F11) \
	op(ENoesisKey::F12) \
	op(ENoesisKey::F13) \
	op(ENoesisKey::F14) \
	op(ENoesisKey::F15) \
	op(ENoesisKey::F16) \
	op(ENoesisKey::F17) \
	op(ENoesisKey::F18) \
	op(ENoesisKey::F19) \
	op(ENoesisKey::F20) \
	op(ENoesisKey::F21) \
	op(ENoesisKey::F22) \
	op(ENoesisKey::F23) \
	op(ENoesisKey::F24) \
	op(ENoesisKey::NumLock) \
	op(ENoesisKey::Scroll) \
	op(ENoesisKey::Oem1) \
	op(ENoesisKey::OemPlus) \
	op(ENoesisKey::OemComma) \
	op(ENoesisKey::OemMinus) \
	op(ENoesisKey::OemPeriod) \
	op(ENoesisKey::Oem2) \
	op(ENoesisKey::Oem3) \
	op(ENoesisKey::Oem4) \
	op(ENoesisKey::Oem5) \
	op(ENoesisKey::Oem6) \
	op(ENoesisKey::Oem7) \
	op(ENoesisKey::Oem8) 
#define FOREACH_ENUM_ENOESISSCROLLEVENTTYPE(op) \
	op(ENoesisScrollEventType::EndScroll) \
	op(ENoesisScrollEventType::First) \
	op(ENoesisScrollEventType::LargeDecrement) \
	op(ENoesisScrollEventType::LargeIncrement) \
	op(ENoesisScrollEventType::Last) \
	op(ENoesisScrollEventType::SmallDecrement) \
	op(ENoesisScrollEventType::SmallIncrement) \
	op(ENoesisScrollEventType::ThumbPosition) 
#define FOREACH_ENUM_ENOESISMOUSEBUTTONSTATE(op) \
	op(ENoesisMouseButtonState::Pressed) 
#define FOREACH_ENUM_ENOESISMOUSEBUTTON(op) \
	op(ENoesisMouseButton::Left) \
	op(ENoesisMouseButton::Right) \
	op(ENoesisMouseButton::Middle) \
	op(ENoesisMouseButton::XButton1) 
#define FOREACH_ENUM_ENOESISDURATIONTYPE(op) \
	op(ENoesisDurationType::Automatic) \
	op(ENoesisDurationType::TimeSpan) 
#define FOREACH_ENUM_ENOESISROUTINGSTRATEGY(op) \
	op(ENoesisRoutingStrategy::Bubbling) \
	op(ENoesisRoutingStrategy::Tunneling) 
#define FOREACH_ENUM_ENOESISRELATIVESOURCEMODE(op) \
	op(ENoesisRelativeSourceMode::PreviousData) \
	op(ENoesisRelativeSourceMode::TemplatedParent) \
	op(ENoesisRelativeSourceMode::Self) 
#define FOREACH_ENUM_ENOESISGENERATORSTATUS(op) \
	op(ENoesisGeneratorStatus::NotStarted) \
	op(ENoesisGeneratorStatus::GeneratingContainers) \
	op(ENoesisGeneratorStatus::ContainersGenerated) 
#define FOREACH_ENUM_ENOESISUPDATESOURCETRIGGER(op) \
	op(ENoesisUpdateSourceTrigger::Default) \
	op(ENoesisUpdateSourceTrigger::PropertyChanged) \
	op(ENoesisUpdateSourceTrigger::LostFocus) 
#define FOREACH_ENUM_ENOESISBINDINGMODE(op) \
	op(ENoesisBindingMode::Default) \
	op(ENoesisBindingMode::TwoWay) \
	op(ENoesisBindingMode::OneWay) \
	op(ENoesisBindingMode::OneTime) 
#define FOREACH_ENUM_ENOESISHANDOFFBEHAVIOR(op) \
	op(ENoesisHandoffBehavior::SnapshotAndReplace) 
PRAGMA_ENABLE_DEPRECATION_WARNINGS
