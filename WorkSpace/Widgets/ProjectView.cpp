#include "WorkSpaceApp.h"
#include "../WinWrappers/Direct2D/RenderTarget.h"
#include "../WinWrappers/Direct2D/SolidColorBrush.h"
#include "../WinWrappers/DirectWrite/WriteTextFormat.h"
#include "../WinWrappers/WinCodecs/WICBitmapFrameDecode.h"
#include "../WinWrappers/Direct2D/Bitmap.h"
#include "ProjectView.h"

using namespace win32;
using namespace win32::d2d;
using namespace win32::dw;

LRESULT ProjectView::WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	WorkSpaceApp* app = static_cast<WorkSpaceApp*>(WorkSpaceApp::GetCurrent());
	ProjectView& pv = reinterpret_cast<ProjectView&>(*reinterpret_cast<ProjectView*>(GetWindowLongPtrW(hwnd, GWLP_USERDATA)));

	RECT rc;
	GetClientRect(hwnd, &rc);

	switch (uMsg)
	{
	case WM_PAINT:
	{
		const RenderTarget rt = RenderTarget(
			app->GetD2DFactory(),
			D2D1::RenderTargetProperties(),
			D2D1::HwndRenderTargetProperties(hwnd, D2D1::SizeU(rc.right - rc.left, rc.bottom - rc.top))
		);

		const WriteTextFormat wf = WriteTextFormat(
			app->GetWriteFactory(),
			L"Segoe UI",
			nullptr,
			DWRITE_FONT_WEIGHT_NORMAL,
			DWRITE_FONT_STYLE_NORMAL,
			DWRITE_FONT_STRETCH_NORMAL,
			14.0f,
			L"en-us"
		);

		wf.SetTextAlignment(DWRITE_TEXT_ALIGNMENT_CENTER);
		wf.SetParagraphAlignment(DWRITE_PARAGRAPH_ALIGNMENT_CENTER);

		const SolidColorBrush brush = SolidColorBrush(rt, D2D1::ColorF(D2D1::ColorF::Yellow));
		const auto blackBrush = SolidColorBrush(rt, D2D1::ColorF(D2D1::ColorF::Black));

		rt.BeginDraw();
		rt.Clear(D2D1::ColorF(D2D1::ColorF::AliceBlue));

		if (!pv.GetImageUri().empty())
		{
			win32::d2d::Bitmap bitmap(pv.GetImageUri(), rt, app->GetImagingFactory());
			rt.DrawBitmap(bitmap, D2D1::RectF(rc.left, rc.top, rc.right, rc.bottom - 100.0f));
		}

		rt.DrawTextW(pv.GetDescription(), wf, D2D1::RectF(rc.left, rc.bottom - 100, rc.right, rc.bottom), blackBrush);

		rt.EndDraw();

		return 0;
	}
	}

	return DefWindowProc(hwnd, uMsg, wParam, lParam);
}

ProjectView::ProjectView(HWND parent) :
	CHWND{
		0,
		CLASS_NAME,
		L"ProjectView",
		WS_CHILD | WS_VISIBLE,
		100,
		100,
		200,
		200,
		parent,
		nullptr,
		WorkSpaceApp::GetCurrent()->GetHInstance(),
		nullptr
	}
{

}

void ProjectView::SetImageUri(std::wstring_view uri)
{
	this->imagePath = uri;
	InvalidateRect(Get(), nullptr, TRUE);
}

const std::wstring& ProjectView::GetImageUri() const noexcept
{
	return imagePath;
}

void ProjectView::SetDescription(std::wstring_view description)
{
	this->description = description;
}

const std::wstring& ProjectView::GetDescription() const noexcept
{
	return description;
}