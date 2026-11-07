#include "comdef.h"

#include "Direct2DFactory.h"

namespace win32::d2d
{
	Factory::Factory(D2D1_FACTORY_TYPE type)
	{
		const HRESULT hr = D2D1CreateFactory(type, &factory);

		if (FAILED(hr))
		{
			throw _com_error(hr);
		}
	}

	Factory::~Factory()
	{
		if (factory != nullptr)
		{
			factory->Release();
		}
	}

	Factory::Factory(Factory&& other) noexcept :
		factory{ other.factory }
	{
		other.factory = nullptr;
	}

	Factory& Factory::operator=(Factory&& other) noexcept
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