#include "comdef.h"

#include "../DirectWrite/WriteTextFormat.h"

#include "Bitmap.h"
#include "SolidColorBrush.h"
#include "RenderTarget.h"

namespace win32::d2d
{
	RenderTarget::RenderTarget(const Factory& factory, D2D1_RENDER_TARGET_PROPERTIES props, D2D1_HWND_RENDER_TARGET_PROPERTIES hwndProps)
	{
		const HRESULT hr = factory.Get()->CreateHwndRenderTarget(props, hwndProps, &rt);

		if (FAILED(hr))
		{
			throw _com_error(hr);
		}
	}

	RenderTarget::~RenderTarget()
	{
		rt->Release();
	}

	RenderTarget::RenderTarget(RenderTarget&& other) noexcept :
		rt{ other.rt }
	{
		other.rt = nullptr;
	}

	RenderTarget& RenderTarget::operator=(RenderTarget&& other) noexcept
	{
		if (rt != nullptr)
		{
			rt->Release();
		}
		rt = other.rt;
		other.rt = nullptr;
		return *this;
	}

	void RenderTarget::BeginDraw() const
	{
		rt->BeginDraw();
	}

	void RenderTarget::EndDraw() const
	{
		const HRESULT result = rt->EndDraw();

		if (FAILED(result))
		{
			throw _com_error(result);
		}
	}

	void RenderTarget::Clear(const D2D1_COLOR_F& clearColor) const
	{
		rt->Clear(&clearColor);
	}

	void RenderTarget::DrawRectangle(const D2D1_RECT_F& rect, const SolidColorBrush& brush) const
	{
		rt->DrawRectangle(rect, brush.Get());
	}

	void RenderTarget::FillRectangle(const D2D1_RECT_F& rect, const SolidColorBrush& brush) const
	{
		rt->FillRectangle(rect, brush.Get());
	}

	void RenderTarget::DrawBitmap(const Bitmap& bitmap, const D2D1_RECT_F& dst) const
	{
		rt->DrawBitmap(bitmap.Get(), dst);
	}

	void RenderTarget::DrawTextW(std::wstring_view text, const dw::WriteTextFormat& format, const D2D1_RECT_F& boundingRect, const SolidColorBrush& brush) const
	{
		rt->DrawTextW(text.data(), text.size(), format.Get(), boundingRect, brush.Get());
	}
}