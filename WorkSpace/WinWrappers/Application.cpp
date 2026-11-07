#include <cassert>

#include "Windows.h"

#include "Application.h"

#pragma comment(lib, "d2d1.lib")
#pragma comment(lib, "dwrite.lib")
#pragma comment(lib, "windowscodecs.lib")

namespace win32
{
	Application* Application::current = nullptr;

	Application::Application(LPCWSTR pCmdLine, HINSTANCE hInstance) :
		hInstance{ hInstance },
		com{ COINIT_APARTMENTTHREADED | COINIT_DISABLE_OLE1DDE },
		d2dFactory{ D2D1_FACTORY_TYPE_SINGLE_THREADED },
		writeFactory{ DWRITE_FACTORY_TYPE_SHARED }
	{
		if (current != nullptr)
		{
			return;
		}

		int argc;
		const auto args = CommandLineToArgvW(pCmdLine, &argc);

		try
		{
			cmdArgs.reserve(argc);

			for (int i = 0; i < argc; ++i)
			{
				cmdArgs.push_back(args[i]);
			}
		}
		catch (std::exception&)
		{
			LocalFree(args);
			throw;
		}
		LocalFree(args);

		current = this;
	}

	Application::~Application()
	{
		current = nullptr;
	}

	void Application::Run()
	{
		MSG msg{};

		while (GetMessage(&msg, nullptr, 0, 0) > 0)
		{
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}
	}

	std::span<const std::wstring_view> Application::GetCommandLineArgs() const noexcept
	{
		return cmdArgs;
	}

	Application* Application::GetCurrent()
	{
		assert(current != nullptr);

		return current;
	}

	void Application::SetResource(const std::string& resource, void* data)
	{
		resources[resource] = data;
	}

	void* Application::GetResource(const std::string& resource) const
	{
		return resources.at(resource);
	}
}