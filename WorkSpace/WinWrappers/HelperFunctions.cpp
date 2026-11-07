#include <stdexcept>

#include "Windows.h"

#include "HelperFunctions.h"

namespace win32
{
	std::string GetLastErrorStr()
	{
		const auto error = GetLastError();

		LPWSTR str = nullptr;
		const size_t size = FormatMessageW(
			FORMAT_MESSAGE_ALLOCATE_BUFFER | FORMAT_MESSAGE_FROM_SYSTEM | FORMAT_MESSAGE_IGNORE_INSERTS,
			0,
			error,
			0,
			reinterpret_cast<LPWSTR>(&str),
			0,
			nullptr);

		std::wstring wstr;

		try
		{
			wstr = std::wstring(str, size);
		}
		catch (std::exception&)
		{
			LocalFree(str);
			throw;
		}
		LocalFree(str);

		return WStrToStr(wstr);
	}

	std::string WStrToStr(std::wstring_view wstr)
	{
		const int size = WideCharToMultiByte(CP_UTF8, 0, wstr.data(), wstr.size(), nullptr, 0, nullptr, NULL);

		std::string str;
		str.resize(size);

		WideCharToMultiByte(CP_UTF8, 0, wstr.data(), wstr.size(), str.data(), str.size(), nullptr, NULL);

		return str;
	}

	void ThrowLastError(std::string_view message)
	{
		std::string error;
		error.assign(message).append(" ").append(GetLastErrorStr());

		throw std::runtime_error(error);
	}
}