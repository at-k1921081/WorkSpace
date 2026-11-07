#ifndef MAINVIEW_H
#define MAINVIEW_H

#include "IMainView.h"
#include "../Widgets/WorkSpace.h"

class MainView : public IMainView {
public:
	MainView(int nCmdShow);

	virtual void SetProjectView(std::wstring_view imgUri, std::wstring_view title) override;

private:
	WorkSpace window;
};

#endif