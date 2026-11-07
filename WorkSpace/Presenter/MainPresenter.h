#ifndef MAINPRESENTER_H
#define MAINPRESENTER_H

#include <string_view>
#include "../Model/ProjectInfo.h"

struct AppData;
class IMainView;

class MainPresenter {
public:
	MainPresenter(AppData* appdata, IMainView* view);

	void SetProjectView(const ProjectInfo& info);

private:
	AppData* appdata;
	IMainView* view;
};

#endif