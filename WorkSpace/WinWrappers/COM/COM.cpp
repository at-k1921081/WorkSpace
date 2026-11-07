#include "comdef.h"

#include "COM.h"

namespace win32::com
{
	COM::COM(DWORD dwCoInit)
	{
		const auto result = CoInitializeEx(nullptr, dwCoInit);

		if (FAILED(result))
		{
			throw _com_error(result);
		}
	}

	COM::~COM()
	{
		CoUninitialize();
	}
}