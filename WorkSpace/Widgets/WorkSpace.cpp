#include "WorkSpaceApp.h"
#include "WorkSpace.h"

LRESULT WorkSpace::WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	switch (uMsg)
	{
	case WM_DESTROY:
		PostQuitMessage(0);
		return 0;

	case WM_PAINT:
	{
		PAINTSTRUCT ps;
		HDC hdc = BeginPaint(hwnd, &ps);

		FillRect(hdc, &ps.rcPaint, reinterpret_cast<HBRUSH>(COLOR_WINDOW + 1));

		EndPaint(hwnd, &ps);

		return 0;
	}
	}

	return DefWindowProc(hwnd, uMsg, wParam, lParam);
}

WorkSpace::WorkSpace() :
	CHWND{
	0,
	CLASS_NAME,
	L"Work Space",
	WS_OVERLAPPEDWINDOW,
	CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT,
	nullptr,
	nullptr,
	WorkSpaceApp::GetCurrent()->GetHInstance(),
	nullptr
	},
	testView{ this->Get() }
{
	testView.SetDescription(L"Hello Win32!");
}