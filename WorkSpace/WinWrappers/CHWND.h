#ifndef CHWND_H
#define CHWND_H

#include "Windows.h"

namespace win32
{
    class CHWND {
    public:
        CHWND() noexcept;

        CHWND(
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
        );

        ~CHWND();

        CHWND(const CHWND&) = delete;
        CHWND& operator=(const CHWND&) = delete;
        CHWND(CHWND&& other) noexcept;
        CHWND& operator=(CHWND&& other) noexcept;

        void Show(int nCmdShow) const;

        HWND Get() const noexcept { return hwnd; }

    private:
        HWND hwnd;
    };
}

#endif