#include "comdef.h"

#include "WriteFactory.h"

#include "WriteTextFormat.h"

namespace win32::dw
{
	WriteTextFormat::WriteTextFormat(
		const WriteFactory& factory,
		_In_z_ WCHAR const* fontFamilyName,
		_In_opt_ IDWriteFontCollection* fontCollection,
		DWRITE_FONT_WEIGHT fontWeight,
		DWRITE_FONT_STYLE fontStyle,
		DWRITE_FONT_STRETCH fontStretch,
		FLOAT fontSize,
		_In_z_ WCHAR const* localeName)
	{
		const HRESULT result = factory.Get()->CreateTextFormat(
			fontFamilyName,
			fontCollection,
			fontWeight,
			fontStyle,
			fontStretch,
			fontSize,
			localeName,
			&format
		);

		if (FAILED(result))
		{
			throw _com_error(result);
		}
	}

	WriteTextFormat::~WriteTextFormat()
	{
		if (format != nullptr)
		{
			format->Release();
		}
	}

	WriteTextFormat::WriteTextFormat(WriteTextFormat&& other) noexcept :
		format{ other.format }
	{
		other.format = nullptr;
	}

	WriteTextFormat& WriteTextFormat::operator=(WriteTextFormat&& other) noexcept
	{
		if (format != nullptr)
		{
			format->Release();
		}
		format = other.format;
		other.format = nullptr;
		return *this;
	}

	void WriteTextFormat::SetTextAlignment(DWRITE_TEXT_ALIGNMENT alignment) const
	{
		const HRESULT result = format->SetTextAlignment(alignment);

		if (FAILED(result))
		{
			throw _com_error(result);
		}
	}

	void WriteTextFormat::SetParagraphAlignment(DWRITE_PARAGRAPH_ALIGNMENT alignment) const
	{
		const HRESULT result = format->SetParagraphAlignment(alignment);

		if (FAILED(result))
		{
			throw _com_error(result);
		}
	}
}