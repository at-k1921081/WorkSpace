#include "comdef.h"

#include "../WinCodecs/WICBitmapDecoder.h"
#include "../WinCodecs/WICFormatConverter.h"

#include "Bitmap.h"

namespace win32::d2d
{
	Bitmap::Bitmap() noexcept : bitmap{ nullptr } {}

	Bitmap::Bitmap(std::wstring_view uri, const RenderTarget& rt, const wic::ImagingFactory& imagingFactory)
	{
		const auto decoder = wic::BitmapDecoder(imagingFactory, uri);

		const auto source = decoder.GetFrame(0);

		const auto converter = wic::FormatConverter(imagingFactory);
		converter.Initialize(source, WICBitmapDitherTypeNone, 0.0f, WICBitmapPaletteTypeCustom);

		const HRESULT hr = rt.Get()->CreateBitmapFromWicBitmap(converter.Get(), nullptr, &bitmap);

		if (FAILED(hr))
		{
			throw _com_error(hr);
		}
	}

	Bitmap::~Bitmap()
	{
		if (bitmap != nullptr)
		{
			bitmap->Release();
		}
	}

	Bitmap::Bitmap(Bitmap&& other) noexcept :
		bitmap{ other.bitmap }
	{
		other.bitmap = nullptr;
	}

	Bitmap& Bitmap::operator=(Bitmap&& other) noexcept
	{
		if (bitmap != nullptr)
		{
			bitmap->Release();
		}
		bitmap = other.bitmap;
		other.bitmap = nullptr;
		return *this;
	}
}