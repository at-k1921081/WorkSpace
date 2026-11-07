#ifndef WICBITMAPDECODER_H
#define WICBITMAPDECODER_H

#include <string_view>
#include "wincodec.h"

#include "WICBitmapFrameDecode.h"

namespace win32::wic
{
	class ImagingFactory;

	class BitmapDecoder {
	public:
		BitmapDecoder(const ImagingFactory& factory, std::wstring_view uri, DWORD desiredAccess = GENERIC_READ,
			WICDecodeOptions decodeOptions = WICDecodeMetadataCacheOnLoad);
		~BitmapDecoder();

		BitmapDecoder(const BitmapDecoder&) = delete;
		BitmapDecoder& operator=(const BitmapDecoder&) = delete;
		BitmapDecoder(BitmapDecoder&& other) noexcept;
		BitmapDecoder& operator=(BitmapDecoder&& other) noexcept;

		BitmapFrameDecode GetFrame(UINT frame) const;

		IWICBitmapDecoder* Get() const noexcept { return decoder; }

	private:
		IWICBitmapDecoder* decoder;
	};
}

#endif