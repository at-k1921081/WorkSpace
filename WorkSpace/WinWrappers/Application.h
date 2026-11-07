#ifndef APPLICATION_H
#define APPLICATION_H

#include <vector>
#include <span>
#include <string_view>
#include <string>
#include <unordered_map>

#include "Windows.h"

#include "Direct2D/Direct2DFactory.h"
#include "DirectWrite/WriteFactory.h"
#include "COM/COM.h"
#include "WinCodecs/WICImagingFactory.h"

namespace win32
{
	class Application {
	public:
		Application(LPCWSTR pCmdLine, HINSTANCE hInstance);
		~Application();

		void Run();

		std::span<const std::wstring_view> GetCommandLineArgs() const noexcept;

		static Application* GetCurrent();

		void SetResource(const std::string& resource, void* data);
		void* GetResource(const std::string& resource) const;

		HINSTANCE GetHInstance() const noexcept { return hInstance; }
		const d2d::Factory& GetD2DFactory() const noexcept { return d2dFactory; }
		const dw::WriteFactory& GetWriteFactory() const noexcept { return writeFactory; }
		const wic::ImagingFactory& GetImagingFactory() const noexcept { return imagingFactory; }

	private:
		static Application* current;
		HINSTANCE hInstance;

		std::vector<std::wstring_view> cmdArgs;
		std::unordered_map<std::string, void*> resources;

		com::COM com;
		d2d::Factory d2dFactory;
		dw::WriteFactory writeFactory;
		wic::ImagingFactory imagingFactory;
	};
}

#endif