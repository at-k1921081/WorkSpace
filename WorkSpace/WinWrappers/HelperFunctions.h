#ifndef HELPERFUNCTIONS_H
#define HELPERFUNCTIONS_H

#include <string>
#include <string_view>

namespace win32
{
	std::string GetLastErrorStr();
	std::string WStrToStr(std::wstring_view wstr);

	void ThrowLastError(std::string_view message);
}

#endif