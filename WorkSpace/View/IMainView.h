#ifndef IMAINVIEW_H
#define IMAINVIEW_H

#include <string_view>

class IMainView {
public:
	virtual ~IMainView() = default;

	virtual void SetProjectView(std::wstring_view imgUri, std::wstring_view title) = 0;
};

#endif