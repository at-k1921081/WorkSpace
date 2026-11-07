#include "WorkSpace.h"
#include "ProjectView.h"

#include "WorkSpaceApp.h"

WorkSpaceApp::WorkSpaceApp(LPCWSTR pCmdLine, HINSTANCE hInstance) :
	Application{ pCmdLine, hInstance }
{
	classes.emplace_back(WorkSpace::WindowProc, hInstance, WorkSpace::CLASS_NAME);
	classes.emplace_back(ProjectView::WindowProc, hInstance, ProjectView::CLASS_NAME);
}