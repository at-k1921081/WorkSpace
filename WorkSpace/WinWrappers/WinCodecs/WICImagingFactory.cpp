#include "comdef.h"

#include "WICImagingFactory.h"

namespace win32::wic
{
	ImagingFactory::ImagingFactory()
	{
		const HRESULT result = CoCreateInstance(CLSID_WICImagingFactory, nullptr, CLSCTX_INPROC_SERVER, IID_PPV_ARGS(&factory));

		if (FAILED(result))
		{
			throw _com_error(result);
		}
	}

	ImagingFactory::~ImagingFactory()
	{
		if (factory != nullptr)
		{
			factory->Release();
		}
	}

	ImagingFactory::ImagingFactory(ImagingFactory&& other) noexcept :
		factory{ other.factory }
	{
		other.factory = nullptr;
	}

	ImagingFactory& ImagingFactory::operator=(ImagingFactory&& other) noexcept
	{
		if (factory != nullptr)
		{
			factory->Release();
		}
		factory = other.factory;
		other.factory = nullptr;
		return *this;
	}
}