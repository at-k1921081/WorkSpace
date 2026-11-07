#ifndef D2DBITMAP_H
#define D2DBITMAP_H

#include <string_view>

#include "d2d1.h"

#include "RenderTarget.h"
#include "../WinCodecs/WICImagingFactory.h"

namespace win32::d2d
{
	class Bitmap {
	public:
		Bitmap() noexcept;
		Bitmap(std::wstring_view uri, const RenderTarget& rt, const wic::ImagingFactory& imagingFactory);
		~Bitmap();

		Bitmap(const Bitmap&) = delete;
		Bitmap& operator=(const Bitmap&) = delete;
		Bitmap(Bitmap&& other) noexcept;
		Bitmap& operator=(Bitmap&& other) noexcept;

		ID2D1Bitmap* Get() const noexcept { return bitmap; }

	private:
		ID2D1Bitmap* bitmap;
	};
}

#endif