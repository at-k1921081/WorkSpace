#include "comdef.h"

#include "RenderTarget.h"

#include "SolidColorBrush.h"

namespace win32::d2d
{
	SolidColorBrush::SolidColorBrush(const RenderTarget& rt, D2D1_COLOR_F color)
	{
		const HRESULT result = rt.Get()->CreateSolidColorBrush(color, &brush);
		if (FAILED(result))
		{
			throw _com_error(result);
		}
	}

	SolidColorBrush::~SolidColorBrush()
	{
		if (brush != nullptr)
		{
			brush->Release();
		}
	}

	SolidColorBrush::SolidColorBrush(SolidColorBrush&& other) noexcept :
		brush{ other.brush }
	{
		other.brush = nullptr;
	}

	SolidColorBrush& SolidColorBrush::operator=(SolidColorBrush&& other) noexcept
	{
		if (brush != nullptr)
		{
			brush->Release();
		}
		brush = other.brush;
		other.brush = nullptr;
		return *this;
	}
}