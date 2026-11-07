#ifndef WRITETEXTFORMAT_H
#define WRITETEXTFORMAT_H

#include "dwrite.h"

namespace win32::dw
{
	class WriteFactory;

	class WriteTextFormat {
	public:
		WriteTextFormat(
			const WriteFactory& factory,
			_In_z_ WCHAR const* fontFamilyName,
			_In_opt_ IDWriteFontCollection* fontCollection,
			DWRITE_FONT_WEIGHT fontWeight,
			DWRITE_FONT_STYLE fontStyle,
			DWRITE_FONT_STRETCH fontStretch,
			FLOAT fontSize,
			_In_z_ WCHAR const* localeName
		);

		~WriteTextFormat();

		WriteTextFormat(const WriteTextFormat&) = delete;
		WriteTextFormat& operator=(const WriteTextFormat&) = delete;
		WriteTextFormat(WriteTextFormat&& other) noexcept;
		WriteTextFormat& operator=(WriteTextFormat&& other) noexcept;

		void SetTextAlignment(DWRITE_TEXT_ALIGNMENT alignment) const;
		void SetParagraphAlignment(DWRITE_PARAGRAPH_ALIGNMENT alignment) const;

		IDWriteTextFormat* Get() const noexcept { return format; }

	private:
		IDWriteTextFormat* format;
	};
}

#endif