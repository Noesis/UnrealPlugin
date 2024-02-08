////////////////////////////////////////////////////////////////////////////////////////////////////
// NoesisGUI - http://www.noesisengine.com
// Copyright (c) 2013 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////


#include "Extensions/RichText.h"

#include "NsCore/ReflectionImplement.h"
#include "NsCore/UTF8.h"
#include "NsGui/UIElementData.h"
#include "NsGui/PropertyMetadata.h"
#include "NsGui/TextBlock.h"
#include "NsGui/Image.h"
#include "NsGui/InlineUIContainer.h"
#include "NsGui/Run.h"
#include "NsGui/Span.h"
#include "NsGui/UICollection.h"
#include "NsGui/Uri.h"
#include "NsGui/Style.h"

#include <cctype>


////////////////////////////////////////////////////////////////////////////////////////////////////
static RichText::TryCreateInlineCallback gTryCreateInline = nullptr;

////////////////////////////////////////////////////////////////////////////////////////////////////
static const char* TryParse(const char* begin, const char* end, const Noesis::TextBlock* parent, 
    Noesis::InlineCollection* inlineCollection);

////////////////////////////////////////////////////////////////////////////////////////////////////
/// This method allows for the creation of Spans for RichText tags which act as containers for other
/// Inlines.
///
/// Extend this method to add new container RichText tags, creating a Span (or Span derived type)
/// for each.
///
/// If a Span has been created, return a pointer to that Span's InlineCollection. If no Span has
/// been created, return nullptr.
////////////////////////////////////////////////////////////////////////////////////////////////////
static Noesis::InlineCollection* TryCreateInlineForTag(const char* tagName,
    Noesis::ArrayRef<RichText::Parameter> parameters, const Noesis::TextBlock* parent,
    Noesis::InlineCollection* inlineCollection, bool isSelfClosing)
{
    if (Noesis::StrCaseEquals(tagName, "img"))
    {
        Noesis::Ptr<Noesis::Image> image = Noesis::MakePtr<Noesis::Image>();
        for (const RichText::Parameter& element : parameters)
        {
            if (element.first == "id")
            {
                Noesis::Style* style = parent->FindResource<Noesis::Style>(element.second.Str());
                if (style == nullptr)
                {
                    NS_ERROR("RichText tag 'img' has an invalid value for 'id' parameter");
                    return nullptr;
                }
                image->SetStyle(style);
                inlineCollection->Add(Noesis::MakePtr<Noesis::InlineUIContainer>(image));
                return nullptr;
            }
        }
        NS_ERROR("RichText tag 'img' is missing an 'id' parameter");
        return nullptr;
    }

    // TryCreateInlineCallback is used to support custom tags
    if (gTryCreateInline != nullptr)
    {
        Noesis::Ptr<Noesis::Inline> in = gTryCreateInline(tagName, parameters, parent);
        if (in != nullptr)
        {
            inlineCollection->Add(in);

            // If it is a Span, return it's InlineCollection, allowing for embedded content
            Noesis::Span* span = Noesis::DynamicCast<Noesis::Span*>(in.GetPtr());
            if (span != nullptr)
            {
                return span->GetInlines();
            }
            return nullptr;
        }
    }

    Noesis::Style* style = parent->FindResource<Noesis::Style>(tagName);
    if (style != nullptr)
    {
        const Noesis::Type* targetType = style->GetTargetType();
        if (targetType == nullptr || targetType == Noesis::TypeOf<Noesis::Inline>()
            || !Noesis::TypeOf<Noesis::FrameworkElement>()->IsAssignableFrom(targetType))
        {
            targetType = Noesis::TypeOf<Noesis::Span>();
        }

        Noesis::Ptr<Noesis::FrameworkElement> el =
            Noesis::StaticPtrCast<Noesis::FrameworkElement>(Noesis::Factory::CreateComponent(
                targetType->GetTypeId()));

        el->SetStyle(style);

        Noesis::Inline* in = Noesis::DynamicCast<Noesis::Inline*>(el.GetPtr());
        if (in != nullptr)
        {
            inlineCollection->Add(in);
            Noesis::Span* span = Noesis::DynamicCast<Noesis::Span*>(in);
            if (span != nullptr)
            {
                return span->GetInlines();
            }
        }
        else
        {
            Noesis::Ptr<Noesis::InlineUIContainer> container =
                Noesis::MakePtr<Noesis::InlineUIContainer>(el);
            inlineCollection->Add(container);

            Noesis::ContentControl* content = Noesis::DynamicCast<Noesis::ContentControl*>(
                el.GetPtr());
            if (!isSelfClosing && content != nullptr)
            {
                Noesis::Ptr<Noesis::TextBlock> textBlock = Noesis::MakePtr<Noesis::TextBlock>();
                content->SetContent(textBlock);
                return textBlock->GetInlines();
            }
        }
    }

    NS_ERROR("RichText tag '%s' is not supported", tagName);

    return nullptr;
}

////////////////////////////////////////////////////////////////////////////////////////////////////
static bool IsAlphaNumeric(uint32_t c)
{
    if (c == ' ' || c == '\t' || c < '0' || (c > '9' && c < 'A') || (c > 'Z' && c < 'a')
        || (c > 'z' && c < 0x007F))
    {
        return false;
    }
    return true;
}

////////////////////////////////////////////////////////////////////////////////////////////////////
static const char* ParseText(const char* begin, const char* end,
    Noesis::InlineCollection* inlineCollection)
{
    const char* current = begin;

    Noesis::FixedString<256> text;

    for (; current != end; current++)
    {
        if (*current == '\\')
        {
            text.Append(begin, current);
            ++current;
            begin = current;
        }
        else if (*current == '>')
        {
            NS_ERROR("RichText contains a malformed closing bracket");
            return end;
        }
        else if (*current == '<')
        {
            break;
        }
    }

    if (current == begin)
    {
        current = end;
    }

    text.Append(begin, current);

    inlineCollection->Add(Noesis::MakePtr<Noesis::Run>(text.Str()));

    return current;
}

////////////////////////////////////////////////////////////////////////////////////////////////////
static const char* ParseContent(const char* begin, const char* end, Noesis::BaseString& buffer)
{
    const char* current = begin;

    bool useQuotationMarks = false;
    bool singleQuotes = false;
    if (*current == '\'' || *current == '"')
    {
        useQuotationMarks = true;
        singleQuotes = *current == '\'';
        ++begin;
        ++current;
    }

    for (; current + 1 != end; current++)
    {
        if (*current == '\\')
        {
            buffer.Append(begin, current);
            ++current;
            begin = current;
        }
        else if(useQuotationMarks)
        {
            if ((singleQuotes && *current == '\'') || (!singleQuotes && *current == '"'))
            {
                buffer.Append(begin, current);
                return current + 1;
            }
            if (*current == '<' || *current == '>')
            {
                NS_ERROR("RichText parameter value is missing a closing quotation mark");
                return end;
            }
        }
        else if (!useQuotationMarks && (*current == '<' || *current == '>'))
        {
            break;
        }
    }

    buffer.Append(begin, current);

    return current;
}

////////////////////////////////////////////////////////////////////////////////////////////////////
static const char* ParseName(const char* begin, const char* end, Noesis::BaseString& buffer)
{
    const char* utf8Current = begin;
    const char* utf8Next = begin;
    uint32_t c = Noesis::UTF8::Next(utf8Next);
    for (const char* it = begin; it != end; it++)
    {
        if (it == utf8Current)
        {
            if (!IsAlphaNumeric(c))
            {
                buffer.Assign(begin, it);
                return it;
            }
            utf8Current = utf8Next;
            c = Noesis::UTF8::Next(utf8Next);
        }
    }

    return begin;
}

////////////////////////////////////////////////////////////////////////////////////////////////////
static const char* ParseKeyValuePair(const char* begin, const char* end,
    Noesis::BaseVector<RichText::Parameter>& parameters)
{
    const char* current = begin;
    while (isspace(*current) && current != end)
    {
        ++current;
    }
    
    if (current == end || !IsAlphaNumeric(Noesis::UTF8::Get(current)))
    {
        return current;
    }

    Noesis::FixedString<8> key;
    current = ParseName(current, end, key);

    if (key.Empty())
    {
        NS_ERROR("A parameter for RichText tag key is malformed");
        return end;
    }
    if (*current != '=')
    {
        NS_ERROR("A parameter for RichText tag key '%s' is malformed", key.Str());
        return end;
    }

    Noesis::FixedString<128> value;
    current = ParseContent(current + 1, end, value);

    if (value.Empty())
    {
        NS_ERROR("A parameter for RichText tag key '%s' is malformed", key.Str());
        return end;
    }

    parameters.PushBack({ key, value });

    return current;
}

////////////////////////////////////////////////////////////////////////////////////////////////////
static const char* ParseTag(const char* begin, const char* end, const Noesis::TextBlock* parent,
    Noesis::InlineCollection* inlineCollection)
{
    const char* current = ++begin;

    Noesis::FixedString<8> tagName;
    current = ParseName(current, end, tagName);

    if (tagName.Empty())
    {
        NS_ERROR("A RichText tag is malformed (contains no name)");
        return current;
    }

    else if (current == end)
    {
        return end;
    }

    Noesis::Vector<RichText::Parameter, 2> parameters;

    if (*current == '=')
    {
        Noesis::FixedString<128> value;
        current = ParseContent(current + 1, end, value);
        parameters.PushBack({ tagName, value });
    }
    else
    {
        while (*current == ' ')
        {
            current = ParseKeyValuePair(current, end, parameters);
        }
    }

    if (*current == '/' && *(current + 1) == '>')
    {
        TryCreateInlineForTag(tagName.Str(), parameters, parent, inlineCollection, true);
        return current + 2;
    }

    if (*current != '>')
    {
        NS_ERROR("RichText tag '%s' has a malformed closing tag", tagName.Str());
        return end;
    }

    Noesis::InlineCollection* newCollection = TryCreateInlineForTag(tagName.Str(), parameters,
        parent, inlineCollection, false);
    if (newCollection != nullptr)
    {
        inlineCollection = newCollection;
        current = TryParse(current + 1, end, parent, inlineCollection);
    }
    else
    {
        Noesis::String content;
        current = ParseContent(current + 1, end, content) + 1;
        NS_ERROR("RichText tag '%s' has unsupported content", tagName.Str());
    }

    if (current == end)
    {
        return current;
    }

    if (*current != '/')
    {
        NS_ERROR("RichText tag '%s' is missing a closing tag", tagName.Str());
        return end;
    }

    current++;

    if (*current != '>')
    {
        Noesis::FixedString<8> closingTagName;
        current = ParseName(current, end, closingTagName);

        if (closingTagName != tagName)
        {
            NS_ERROR("RichText tag '%s' has a mismatched closing tag", tagName.Str());
            return end;
        }
    }

    if (*current != '>')
    {
        NS_ERROR("RichText tag '%s' has a malformed closing tag", tagName.Str());
        return end;
    }

    return current + 1;
}

////////////////////////////////////////////////////////////////////////////////////////////////////
static const char* TryParse(const char* begin, const char* end, const Noesis::TextBlock *parent, 
    Noesis::InlineCollection* inlineCollection)
{
    const char* current = begin;

    while (current != end)
    {
        if (*current == '<')
        {
            const char* next = current + 1;
            if (next != end && *next == '/')
            {
                return next;
            }
            current = ParseTag(current, end, parent, inlineCollection);
        }
        else
        {
            current = ParseText(current, end, inlineCollection);
        }
    }
    return current;
}

////////////////////////////////////////////////////////////////////////////////////////////////////
static void OnSourceChanged(Noesis::DependencyObject* obj,
    const Noesis::DependencyPropertyChangedEventArgs& args)
{
    const Noesis::TextBlock* textBlock = Noesis::DynamicCast<Noesis::TextBlock*>(obj);
    if (textBlock)
    {
        Noesis::InlineCollection* inlineCollection = textBlock->GetInlines();

        inlineCollection->Clear();

        const Noesis::String& text = args.NewValue<Noesis::String>();

        TryParse(text.Begin(), text.End(), textBlock, inlineCollection);
    }
}

////////////////////////////////////////////////////////////////////////////////////////////////////
void RichText::SetTryCreateInlineCallback(TryCreateInlineCallback callback)
{
    gTryCreateInline = callback;
}

////////////////////////////////////////////////////////////////////////////////////////////////////
NS_BEGIN_COLD_REGION

NS_IMPLEMENT_REFLECTION(RichText, "NoesisGUIExtensions.RichText")
{
    Noesis::UIElementData* data = NsMeta<Noesis::UIElementData>(Noesis::TypeOf<SelfClass>());
    data->RegisterProperty<Noesis::String>(TextProperty, "Text", Noesis::PropertyMetadata::Create(
        Noesis::String(), Noesis::PropertyChangedCallback(OnSourceChanged)));
}

NS_END_COLD_REGION

////////////////////////////////////////////////////////////////////////////////////////////////////
const Noesis::DependencyProperty* RichText::TextProperty;