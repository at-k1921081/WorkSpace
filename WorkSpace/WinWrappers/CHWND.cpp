#include <stdexcept>

#include "HelperFunctions.h"

#include "CHWND.h"

namespace win32
{
    CHWND::CHWND() noexcept :
        hwnd{ nullptr }
    {}

    CHWND::CHWND(
        _In_ DWORD dwExStyle,
        _In_opt_ LPCWSTR lpClassName,
        _In_opt_ LPCWSTR lpWindowName,
        _In_ DWORD dwStyle,
        _In_ int X,
        _In_ int Y,
        _In_ int nWidth,
        _In_ int nHeight,
        _In_opt_ HWND hWndParent,
        _In_opt_ HMENU hMenu,
        _In_opt_ HINSTANCE hInstance,
        _In_opt_ LPVOID lpParam
    ) :
        hwnd{ CreateWindowExW(dwExStyle, lpClassName, lpWindowName, dwStyle, X, Y, nWidth, nHeight, hWndParent, hMenu, hInstance, lpParam) }
    {
        if (hwnd == nullptr)
        {
            ThrowLastError("Failed to create window");
        }

        SetWindowLongPtrW(hwnd, GWLP_USERDATA, reinterpret_cast<LONG_PTR>(this));
    }

    CHWND::~CHWND()
    {
        DestroyWindow(hwnd);
    }

    CHWND::CHWND(CHWND&& other) noexcept :
        hwnd{ other.hwnd }
    {
        other.hwnd = nullptr;
    }

    CHWND& CHWND::operator=(CHWND&& other) noexcept
    {
        DestroyWindow(hwnd);
        hwnd = other.hwnd;
        other.hwnd = nullptr;
        return *this;
    }

    void CHWND::Show(int nCmdShow) const
    {
        ShowWindow(hwnd, nCmdShow);
    }
}