#include <iostream>

#include "comdef.h"

#include "Widgets/WorkSpaceApp.h"
//#include "Widgets/WorkSpace.h"
#include "WinWrappers/WinCodecs/WICBitmapDecoder.h"
#include "View/MainView.h"
#include "Model/AppData.h"
#include "Presenter/MainPresenter.h"

int WINAPI wWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, PWSTR pCmdLine, int nCmdShow)
{
	try
	{
		WorkSpaceApp app(pCmdLine, hInstance);

		AppData appdata;

		appdata.projects.push_back(ProjectInfo{
			L"C:\\Users\\Alex\\Desktop\\Alex\\16639.jpg",
			L"My first project",
			L"My first project ever created with WorkSpace."
			});

		win32::wic::BitmapDecoder decoder(app.GetImagingFactory(), appdata.projects[0].imagePath);
		appdata.images.insert({ appdata.projects[0].imagePath, decoder.GetFrame(0) });

		MainView mainView = MainView(nCmdShow);

		MainPresenter mainPresenter = MainPresenter(&appdata, &mainView);

		mainPresenter.SetProjectView(appdata.projects[0]);

		app.SetResource("AppData", &appdata);
		app.SetResource("MainPresenter", &mainPresenter);

		mainPresenter.SetProjectView(appdata.projects[0]);

		app.Run();

		return 0;
	}
	catch (_com_error& e)
	{
		MessageBoxW(nullptr, e.ErrorMessage(), L"Exception", MB_OK);
		std::wcerr << e.ErrorMessage() << '\n';
		return -1;
	}
	catch (std::exception& e)
	{
		MessageBoxA(nullptr, e.what(), "Exception", MB_OK);
		std::cerr << e.what() << '\n';
		return -1;
	}
	catch (...)
	{
		MessageBoxW(nullptr, L"Unknown error occured\n", L"Error", MB_OK);
		std::cerr << "Unknown error occured\n";
		return -2;
	}
}