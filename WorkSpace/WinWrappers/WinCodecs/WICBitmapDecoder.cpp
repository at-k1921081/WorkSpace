#include "comdef.h"

#include "WICImagingFactory.h"

#include "WICBitmapDecoder.h"

namespace win32::wic
{
	BitmapDecoder::BitmapDecoder(const ImagingFactory& factory, std::wstring_view uri, DWORD desiredAccess, WICDecodeOptions decodeOptions)
	{
		const HRESULT result = factory.Get()->CreateDecoderFromFilename(uri.data(), nullptr, desiredAccess,
			decodeOptions, &decoder);

		if (FAILED(result))
		{
			throw _com_error(result);
		}
	}

	BitmapDecoder::~BitmapDecoder()
	{
		if (decoder != nullptr)
		{
			decoder->Release();
		}
	}

	BitmapDecoder::BitmapDecoder(BitmapDecoder&& other) noexcept :
		decoder{ other.decoder }
	{
		other.decoder = nullptr;
	}

	BitmapDecoder& BitmapDecoder::operator=(BitmapDecoder&& other) noexcept
	{
		if (decoder != nullptr)
		{
			decoder->Release();
		}
		decoder = other.decoder;
		other.decoder = nullptr;
		return *this;
	}

	BitmapFrameDecode BitmapDecoder::GetFrame(UINT frame) const
	{
		return BitmapFrameDecode(*this, frame);
	}
}