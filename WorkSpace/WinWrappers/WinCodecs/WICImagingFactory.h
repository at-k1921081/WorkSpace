#ifndef WICIMAGINGFACTORY_H
#define WICIMAGINGFACTORY_H

#include "wincodec.h"

namespace win32::wic
{
	class ImagingFactory {
	public:
		ImagingFactory();
		~ImagingFactory();

		ImagingFactory(const ImagingFactory&) = delete;
		ImagingFactory& operator=(const ImagingFactory&) = delete;
		ImagingFactory(ImagingFactory&& other) noexcept;
		ImagingFactory& operator=(ImagingFactory&& other) noexcept;

		IWICImagingFactory* Get() const noexcept { return factory; }

	private:
		IWICImagingFactory* factory;
	};
}

#endif