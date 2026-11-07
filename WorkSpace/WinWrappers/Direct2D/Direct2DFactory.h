#ifndef DIRECT2DFACTORY_H
#define DIRECT2DFACTORY_H

#include "Windows.h"
#include "d2d1.h"

namespace win32::d2d
{
	class Factory {
	public:
		Factory(D2D1_FACTORY_TYPE type);

		~Factory();

		Factory(const Factory&) = delete;
		Factory& operator=(const Factory&) = delete;
		Factory(Factory&& other) noexcept;
		Factory& operator=(Factory&& other) noexcept;

		ID2D1Factory* Get() const noexcept { return factory; }

	private:
		ID2D1Factory* factory;
	};
}

#endif