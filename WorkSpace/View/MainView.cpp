#include "../Widgets/ProjectView.h"

#include "MainView.h"

MainView::MainView(int nCmdShow) :
	window{}
{
	window.Show(nCmdShow);
}

void MainView::SetProjectView(std::wstring_view imgUri, std::wstring_view title)
{
	ProjectView& view = window.testView;

	view.SetImageUri(imgUri);
	view.SetDescription(title);
}