#ifndef WORKSPACE_H
#define WORKSPACE_H

#include "../WinWrappers/CHWND.h"
#include "ProjectView.h"

class WorkSpace : public win32::CHWND {
public:
	WorkSpace();

	static LRESULT WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);
	static constexpr LPCWSTR CLASS_NAME = L"WorkSpace";

	ProjectView testView;
};

#endif