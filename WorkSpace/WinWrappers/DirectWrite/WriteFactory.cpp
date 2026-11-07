#include "comdef.h"
#include "WriteFactory.h"

namespace win32::dw
{
	WriteFactory::WriteFactory(DWRITE_FACTORY_TYPE type)
	{
		const HRESULT result = DWriteCreateFactory(type, __uuidof(IDWriteFactory), reinterpret_cast<IUnknown**>(&factory));

		if (FAILED(result))
		{
			throw _com_error(result);
		}
	}

	WriteFactory::~WriteFactory()
	{
		if (factory != nullptr)
		{
			factory->Release();
		}
	}

	WriteFactory::WriteFactory(WriteFactory&& other) noexcept :
		factory{ other.factory }
	{
		other.factory = nullptr;
	}

	WriteFactory& WriteFactory::operator=(WriteFactory&& other) noexcept
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