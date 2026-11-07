#ifndef APPDATA_H
#define APPDATA_H

#include <vector>
#include <unordered_map>
#include <string>

#include "ProjectInfo.h"
#include "../WinWrappers/WinCodecs/WICBitmapFrameDecode.h"

struct AppData {
	std::vector<ProjectInfo> projects;
	std::unordered_map<std::wstring, win32::wic::BitmapFrameDecode> images;
};

#endif