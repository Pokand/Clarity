#include "SurceHeder.h"


Graphics::Graphics() {
	pfactory = NULL;
	rendertarget = NULL;
	brush = NULL;
	brushButn = NULL;
	OnPanel1 = false;
	pRander = NULL;
}
Graphics::~Graphics() {
	if (pfactory) pfactory->Release();
	if (rendertarget) rendertarget->Release();
}
bool Graphics::Init(HWND windowhandle) {
	HRESULT res = D2D1CreateFactory(D2D1_FACTORY_TYPE_SINGLE_THREADED, &pfactory);
	if (res != S_OK) return false;

	RECT rc;
	GetClientRect(windowhandle, &rc);

	pfactory->CreateHwndRenderTarget(D2D1::RenderTargetProperties(), D2D1::HwndRenderTargetProperties( windowhandle, D2D1::SizeU(rc.right, rc.bottom)), & rendertarget);

	if (res != S_OK) return false;

	return true;
}

void Graphics::ClearScreen(float r, float g, float b) {
	rendertarget->Clear(D2D1::ColorF(r, g, b));
	
}
void Graphics::DrawCircle(float x, float y, float rad, float r, float g, float b, float a) {

	rendertarget->CreateSolidColorBrush(D2D1::ColorF(r, g, b, a), &brush);

	rendertarget->DrawEllipse(D2D1::Ellipse(D2D1::Point2F(x, y), rad, rad), brush, 3.0f);
	

	brush->Release();
}

void Graphics::DrawPanel(float x, float y, float x1, float y1, float r, float g, float b, float a) {
	
	rendertarget->CreateSolidColorBrush(D2D1::ColorF(r, g, b, a), &brush);
	
	rendertarget->DrawLine(D2D1::Point2F(x, y), D2D1::Point2F(x1, y1), brush, 5.0f);
	rendertarget->DrawLine(D2D1::Point2F(x, y + 10), D2D1::Point2F(x1, y1 + 10), brush, 5.0f);
	rendertarget->DrawLine(D2D1::Point2F(x, y + 20), D2D1::Point2F(x1, y1 + 20), brush, 5.0f);

	brush->Release();
}


void Graphics::Panel(float r, float g, float b, float r1, float g1, float b1) {

	rendertarget->CreateSolidColorBrush(D2D1::ColorF(r, g, b, 0.5f), &brush);
	rendertarget->CreateSolidColorBrush(D2D1::ColorF(r1, g1, b1), &brushButn);

	rendertarget->DrawRectangle(D2D1::Rect(10, 50, 150, 562), brush, 0.1f);
	rendertarget->FillRectangle(D2D1::Rect(10, 50, 150, 562), brush);

	rendertarget->DrawRectangle(D2D1::RectF(25.0f, 60.0f, 135.0f, 126.0f), brushButn, 1.0f);
	rendertarget->FillRectangle(D2D1::RectF(25.0f, 60.0f, 135.0f, 126.0f), brushButn);


	rendertarget->DrawRectangle(D2D1::RectF(25.0f, 136.0f, 135.0f, 202.0f), brushButn, 1.0f);
	rendertarget->FillRectangle(D2D1::RectF(25.0f, 136.0f, 135.0f, 202.0f), brushButn);

	rendertarget->DrawRectangle(D2D1::RectF(25.0f, 212.0f, 135.0f, 276.0f), brushButn, 1.0f);
	rendertarget->FillRectangle(D2D1::RectF(25.0f, 212.0f, 135.0f, 276.0f), brushButn);

	rendertarget->DrawRectangle(D2D1::RectF(25.0f, 286.0f, 135.0f, 352.0f), brushButn, 1.0f);
	rendertarget->FillRectangle(D2D1::RectF(25.0f, 286.0f, 135.0f, 352.0f), brushButn);


	brush->Release();
	brushButn->Release();

}

void Graphics::Taimer(float x, float y, float r, float g, float b) {

	rendertarget->CreateSolidColorBrush(D2D1::ColorF(r, g, b), &brush);
	rendertarget->CreateSolidColorBrush(D2D1::ColorF(0, 0, 0, 1), &brushButn);

	rendertarget->FillEllipse(D2D1::Ellipse(D2D1::Point2(x, y), 70, 70), brush);
	rendertarget->DrawEllipse(D2D1::Ellipse(D2D1::Point2(x, y), 70, 70), brushButn,2.0f);

	
}