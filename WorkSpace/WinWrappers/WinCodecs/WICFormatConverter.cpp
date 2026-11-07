#include "comdef.h"
#include "WICImagingFactory.h"
#include "WICBitmapFrameDecode.h"
#include "WICFormatConverter.h"

namespace win32::wic
{
	FormatConverter::FormatConverter(const ImagingFactory& factory)
	{
		const HRESULT hr = factory.Get()->CreateFormatConverter(&converter);
		if (FAILED(hr))
		{
			throw _com_error(hr);
		}
	}

	FormatConverter::~FormatConverter()
	{
		if (converter != nullptr)
		{
			converter->Release();
		}
	}

	FormatConverter::FormatConverter(FormatConverter&& other) noexcept :
		converter{ other.converter }
	{
		other.converter = nullptr;
	}

	FormatConverter& FormatConverter::operator=(FormatConverter&& other) noexcept
	{
		if (converter != nullptr)
		{
			converter->Release();
		}
		converter = other.converter;
		other.converter = nullptr;
		return *this;
	}

	void FormatConverter::Initialize(const BitmapFrameDecode& decode, WICBitmapDitherType ditherType, double alphaThresholdPercet,
		WICBitmapPaletteType paletteType) const
	{
		const HRESULT hr = converter->Initialize(
			decode.Get(),
			GUID_WICPixelFormat32bppPBGRA,
			ditherType,
			nullptr,
			alphaThresholdPercet,
			paletteType
		);

		if (FAILED(hr))
		{
			throw _com_error(hr);
		}
	}
}