#ifndef WRITEFACTORY_H
#define WRITEFACTORY_H

#include "dwrite.h"

namespace win32::dw
{
	class WriteFactory {
	public:
		WriteFactory(DWRITE_FACTORY_TYPE type);
		~WriteFactory();

		WriteFactory(const WriteFactory&) = delete;
		WriteFactory& operator=(const WriteFactory&) = delete;
		WriteFactory(WriteFactory&& other) noexcept;
		WriteFactory& operator=(WriteFactory&& other) noexcept;

		IDWriteFactory* Get() const noexcept { return factory; }

	private:
		IDWriteFactory* factory;
	};
}

#endif