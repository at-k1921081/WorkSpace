#ifndef PROJECTVIEW_H
#define PROJECTVIEW_H

#include <string>

#include "../WinWrappers/CHWND.h"

class ProjectView : public win32::CHWND {
public:
	ProjectView(HWND parent);

	void SetImageUri(std::wstring_view uri);
	const std::wstring& GetImageUri() const noexcept;

	void SetDescription(std::wstring_view description);
	const std::wstring& GetDescription() const noexcept;

	static LRESULT WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);
	static constexpr LPCWSTR CLASS_NAME = L"ProjectView";

private:
	std::wstring imagePath;
	std::wstring description;
};

#endif