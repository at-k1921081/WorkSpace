#ifndef SOLIDCOLORBRUSH_H
#define SOLIDCOLORBRUSH_H

#include "d2d1.h"

namespace win32::d2d
{
	class RenderTarget;

	class SolidColorBrush {
	public:
		SolidColorBrush(const RenderTarget& rt, D2D1_COLOR_F color);
		~SolidColorBrush();

		SolidColorBrush(const SolidColorBrush&) = delete;
		SolidColorBrush& operator=(const SolidColorBrush&) = delete;
		SolidColorBrush(SolidColorBrush&& other) noexcept;
		SolidColorBrush& operator=(SolidColorBrush&& other) noexcept;

		ID2D1SolidColorBrush* Get() const noexcept { return brush; }

	private:
		ID2D1SolidColorBrush* brush;
	};
}

#endif