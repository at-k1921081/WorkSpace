#ifndef BITMAPFRAMEDECODE_H
#define BITMAPFRAMEDECODE_H

#include "wincodec.h"

namespace win32::wic
{
	class BitmapDecoder;

	class BitmapFrameDecode {
	public:
		BitmapFrameDecode(const BitmapDecoder& decoder, UINT frame);
		~BitmapFrameDecode();

		BitmapFrameDecode(const BitmapFrameDecode&) = delete;
		BitmapFrameDecode& operator=(const BitmapFrameDecode&) = delete;
		BitmapFrameDecode(BitmapFrameDecode&& other) noexcept;
		BitmapFrameDecode& operator=(BitmapFrameDecode&& other) noexcept;

		IWICBitmapFrameDecode* Get() const noexcept { return decode; }

	private:
		IWICBitmapFrameDecode* decode;
	};
}

#endif