#ifndef WINDOWCLASS_H
#define WINDOWCLASS_H

#include "Windows.h"

namespace win32
{
    class WindowClass {
    public:
        WindowClass() noexcept;
        WindowClass(WNDPROC lpfnWndProc, HINSTANCE hInstance, LPCWSTR lpszClassName);
        WindowClass(
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
        );

        ~WindowClass();

        WindowClass(const WindowClass&) = delete;
        WindowClass& operator=(const WindowClass&) = delete;
        WindowClass(WindowClass&& other) noexcept;
        WindowClass& operator=(WindowClass&& other) noexcept;

    private:
        LPCWSTR className;
        HINSTANCE hInstance;
    };
}

#endif