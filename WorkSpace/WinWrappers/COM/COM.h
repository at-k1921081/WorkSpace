#ifndef COM_H
#define COM_H

#include "combaseapi.h"

namespace win32::com
{
	class COM {
	public:
		COM(DWORD dwCoInit);
		~COM();

		COM(const COM&) = delete;
		COM& operator=(const COM&) = delete;
		COM(COM&&) noexcept = delete;
		COM& operator=(COM&&) noexcept = delete;
	};
}

#endif