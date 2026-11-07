#ifndef WICFORMATCONVERTER_H
#define WICFORMATCONVERTER_H

#include "wincodec.h"

namespace win32::wic
{
	class ImagingFactory;
	class BitmapFrameDecode;

	class FormatConverter {
	public:
		FormatConverter(const ImagingFactory& factory);
		~FormatConverter();

		FormatConverter(const FormatConverter&) = delete;
		FormatConverter& operator=(const FormatConverter&) = delete;
		FormatConverter(FormatConverter&& other) noexcept;
		FormatConverter& operator=(FormatConverter&& other) noexcept;

		void Initialize(const BitmapFrameDecode& decode, WICBitmapDitherType ditherType, double alphaThresholdPercet, WICBitmapPaletteType paletteType) const;

		IWICFormatConverter* Get() const noexcept { return converter; }

	private:
		IWICFormatConverter* converter;
	};
}

#endif