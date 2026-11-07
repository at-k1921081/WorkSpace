#include "../Model/AppData.h"
#include "../View/IMainView.h"

#include "MainPresenter.h"

MainPresenter::MainPresenter(AppData* appdata, IMainView* view) :
	appdata{ appdata }, view{ view }
{

}

void MainPresenter::SetProjectView(const ProjectInfo& info)
{
	view->SetProjectView(info.imagePath, info.title);
}