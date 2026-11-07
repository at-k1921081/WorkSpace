#ifndef WORKSPACEAPP_H
#define WORKSPACEAPP_H

#include <vector>

#include "../WinWrappers/Application.h"
#include "../WinWrappers/WindowClass.h"

class WorkSpaceApp : public win32::Application {
public:
	WorkSpaceApp(LPCWSTR pCmdLine, HINSTANCE hInstance);

private:
	std::vector<win32::WindowClass> classes;
};

#endif