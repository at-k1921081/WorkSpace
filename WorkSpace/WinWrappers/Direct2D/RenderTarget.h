#ifndef RENDERTARGET_H
#define RENDERTARGET_H

#include <string_view>

#include "d2d1.h"

#include "Direct2DFactory.h"

namespace win32::dw
{
	class WriteTextFormat;
}

namespace win32::d2d
{
	class SolidColorBrush;
	class Bitmap;

	class RenderTarget {
	public:
		RenderTarget(const Factory& factory, D2D1_RENDER_TARGET_PROPERTIES props, D2D1_HWND_RENDER_TARGET_PROPERTIES hwndProps);

		~RenderTarget();

		RenderTarget(const RenderTarget&) = delete;
		RenderTarget& operator=(const RenderTarget&) = delete;
		RenderTarget(RenderTarget&& other) noexcept;
		RenderTarget& operator=(RenderTarget&& other) noexcept;

		void BeginDraw() const;
		void EndDraw() const;

		void Clear(const D2D1_COLOR_F& clearColor) const;

		void DrawRectangle(const D2D1_RECT_F& rect, const SolidColorBrush& brush) const;
		void FillRectangle(const D2D1_RECT_F& rect, const SolidColorBrush& brush) const;

		void DrawBitmap(const Bitmap& bitmap, const D2D1_RECT_F& dst) const;

		void DrawTextW(std::wstring_view text, const dw::WriteTextFormat& format, const D2D1_RECT_F& boundingRect, const SolidColorBrush& brush) const;

		ID2D1RenderTarget* Get() const noexcept { return rt; }

	private:
		ID2D1HwndRenderTarget* rt;
	};
}

#endif