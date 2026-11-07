#include <stdexcept>

#include "HelperFunctions.h"

#include "WindowClass.h"

namespace win32
{
    WindowClass::WindowClass() noexcept :
        className{ nullptr },
        hInstance{ nullptr }
    {

    }

    WindowClass::WindowClass(WNDPROC lpfnWndProc, HINSTANCE hInstance, LPCWSTR lpszClassName) :
        className{ lpszClassName },
        hInstance{ hInstance }
    {
        WNDCLASSEXW wnd{};
        wnd.cbSize = sizeof(WNDCLASSEXW);
        wnd.lpfnWndProc = lpfnWndProc;
        wnd.hInstance = hInstance;
        wnd.lpszClassName = lpszClassName;

        const auto result = RegisterClassExW(&wnd);
        if (result == 0)
        {
            ThrowLastError("Failed to register class");
        }
    }

    WindowClass::WindowClass(
        UINT        cbSize,
        /* Win 3.x */
        UINT        style,
        WNDPROC     lpfnWndProc,
        int         cbClsExtra,
        int         cbWndExtra,
        HINSTANCE   hInstance,
        HICON       hIcon,
        HCURSOR     hCursor,
        HBRUSH      hbrBackground,
        LPCWSTR     lpszMenuName,
        LPCWSTR     lpszClassName,
        /* Win 4.0 */
        HICON hIconSm
    ) :
        className{ lpszClassName },
        hInstance{ hInstance }
    {
        const WNDCLASSEXW wnd{
            cbSize,
            style,
            lpfnWndProc,
            cbClsExtra,
            cbWndExtra,
            hInstance,
            hIcon,
            hCursor,
            hbrBackground,
            lpszMenuName,
            lpszClassName,
            hIconSm
        };

        const auto result = RegisterClassExW(&wnd);
        if (result == 0)
        {
            ThrowLastError("Failed to register class");
        }
    }

    WindowClass::~WindowClass()
    {
        UnregisterClassW(className, hInstance);
    }

    WindowClass::WindowClass(WindowClass&& other) noexcept :
        className{ other.className }, hInstance{ other.hInstance }
    {
        other.className = nullptr;
        other.hInstance = nullptr;
    }

    WindowClass& WindowClass::operator=(WindowClass&& other) noexcept
    {
        UnregisterClassW(className, hInstance);
        className = other.className;
        hInstance = other.hInstance;
        other.className = nullptr;
        other.hInstance = nullptr;
        return *this;
    }
}