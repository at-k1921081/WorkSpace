#include "comdef.h"
#include "WICBitmapDecoder.h"
#include "WICBitmapFrameDecode.h"

namespace win32::wic
{
	BitmapFrameDecode::BitmapFrameDecode(const BitmapDecoder& decoder, UINT frame)
	{
		const HRESULT hr = decoder.Get()->GetFrame(frame, &decode);

		if (FAILED(hr))
		{
			throw _com_error(hr);
		}
	}

	BitmapFrameDecode::~BitmapFrameDecode()
	{
		if (decode != nullptr)
		{
			decode->Release();
		}
	}

	BitmapFrameDecode::BitmapFrameDecode(BitmapFrameDecode&& other) noexcept :
		decode{ other.decode }
	{
		other.decode = nullptr;
	}

	BitmapFrameDecode& BitmapFrameDecode::operator=(BitmapFrameDecode&& other) noexcept
	{
		if (decode != nullptr)
		{
			decode->Release();
		}
		decode = other.decode;
		other.decode = nullptr;
		return *this;
	}
}