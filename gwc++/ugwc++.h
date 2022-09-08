/*
	GWC++ (Graphic Window for Console Application)

	- Questo progetto è sotto lincenza MIT (https://mit-license.org)
	- Questo progetto è disponibile su GitHub (https://github.com/reallukee/GWCpp)
	- Maggiori informazioni sono diponibili nel file README.md


	ATUORE:			Realluke | Aka Luca Pollicino
	DESCRIZIONE:	Classe UGWC
	DATA:			24/04/22
	VERSIONE:		1.1.2
*/

#pragma once
#pragma unmanaged

#include <string>
#include <Windows.h>

#ifdef TONATIVE
#define DECLSPECIFIER __declspec(dllexport)
#define EXPIMP_TEMPLATE
#else
#define DECLSPECIFIER __declspec(dllimport)
#define EXPIMP_TEMPLATE extern
#endif

#include "ucomp.h"
using namespace std;
using namespace GWCpp;

namespace GWCpp
{
	class DECLSPECIFIER UGWC
	{

	private:

		void* GWCAdress;

	public:

		/*
			### Costruttori e distruttori
			Costruttori e distruttori
		*/

		#pragma region Costruttori

		UGWC();
		UGWC(int, int);
		UGWC(int, int, string);
		UGWC(int, int, string, int, int);
		~UGWC();

		#pragma endregion



		/*
			### Metodi Interattivi
			Metodi di interazione I/O
		*/

		#pragma region MetodiInterattivi

		string InputBox(string, string, string, int, int);
		UOutputBoxResult OutputBox(string, UOutputBoxStyle, string);

		#pragma endregion



		/*
			### Metodi Finestra
			Metodi della finestra.
		*/

		#pragma region MetodiFinestra

		bool StartWindow();
		bool CloseWindow();
		bool SuspendWindow();
		bool ResumeWindow();
		bool PauseWindow(int);
		bool RedrawWindow(int, int, int, int);
		bool RedrawWindow();
		bool ShowWindow();
		bool HideWindow();
		int GetWindowMaxX();
		int GetWindowMaxY();
		int GetWindowRealMaxX();
		int GetWindowRealMaxY();
		int GetScreenMaxX();
		int GetScreenMaxY();
		int GetScreenRealMaxX();
		int GetScreenRealMaxY();
		UPoint RequestMouseDown(UMouseButtons);
		UPoint RequestMouseDown();
		UPoint RequestMouseUp(UMouseButtons);
		UPoint RequestMouseUp();
		char RequestKeyDown(char C);
		char RequestKeyDown();
		char RequestKeyUp(char C);
		char RequestKeyUp();

		#pragma endregion



		/*
			### Proprietà finestra.
			Proprietà della finestra
		*/

		#pragma region ProprietàFinestra

		bool GetWindowStarted();
		bool GetWindowClosed();
		bool GetWindowSuspended();
		bool GetWindowVisible();
		UPoint GetMouseLocation();
		void SetMouseLocation(UPoint);
		int GetMouseX();
		void SetMouseX(int);
		int GetMouseY();
		void SetMouseY(int);
		string GetWindowTitle();
		void SetWindowTitle(string);
		void DefaultWindowTitle();
		HICON GetWindowIcon();
		void SetWindowIcon(HICON);
		void DefaultWindowIcon();
		bool GetWindowIconVisible();
		void SetWindowIconVisible(bool);
		void DefaultWindowIconVisible();
		UPoint GetWindowLocation();
		void SetWindowLocation(UPoint);
		int GetWindowX();
		void SetWindowX(int);
		int GetWindowY();
		void SetWindowY(int);
		void DefaultWindowLocation();
		void DefaultWindowX();
		void DefaultWindowY();
		UColor GetWindowColor();
		void SetWindowColor(UColor);
		void DefaultWindowColor();
		HBITMAP GetWindowImage();
		void SetWindowImage(HBITMAP);
		void DefaultWindowImage();
		USize GetWindowSize();
		void SetWindowSize(USize);
		int GetWindowWidth();
		void SetWindowWidth(int);
		int GetWindowHeight();
		void SetWindowHeight(int);
		void DefaultWindowSize();
		void DefaultWindowWidth();
		void DefaultWindowHeight();
		USize GetWindowRealSize();
		void SetWindowRealSize(USize);
		int GetWindowRealWidth();
		void SetWindowRealWidth(int);
		int GetWindowRealHeight();
		void SetWindowRealHeight(int);
		void DefaultWindowRealSize();
		void DefaultWindowRealWidth();
		void DefaultWindowRealHeight();
		UWindowState GetWindowSizeState();
		void SetWindowSizeState(UWindowState);
		void DefaultWindowSizeState();
		USize GetWindowMinimumSize();
		void SetWindowMinimumSize(USize);
		void DefaultWindowMinimumSize();
		USize GetWindowMaximumSize();
		void SetWindowMaximumSize(USize);
		void DefaultWindowMaximumSize();
		double GetWindowOpacity();
		void SetWindowOpacity(double);
		void DefaultWindowOpacity();
		bool GetWindowAlwaysOnTop();
		void SetWindowAlwaysOnTop(bool);
		void DefaultWindowAlwaysOnTop();
		bool GetWindowInTaskbar();
		void SetWindowInTaskbar(bool);
		void DefaultWindowInTaskBar();
		bool GetWindowButtons();
		void SetWindowButtons(bool);
		void DefaultWindowButtons();
		bool GetWindowMinimizeButton();
		void SetWindowMinimizeButton(bool);
		void DefaultWindowMinimizeButton();
		bool GetWindowMaximizeButton();
		void SetWindowMaximizeButton(bool);
		void DefaultWindowMaximizeButton();

		#pragma endregion



		/*
			### Metodi disegno
			Metodi del disegno
		*/

		#pragma region MetodiDisegno

		void SaveCanvas();
		void SaveCanvasWoP();
		void RestoreCanvas();
		void RestoreCanvasWoP();
		void ClearWindow(UColor);
		void ClearWindow();
		void ClearWindowWoP(UColor);
		void ClearWindowWoP();
		void DrawLine(int, int, int, int);
		void DrawLineWoP(int, int, int, int);
		void DrawArc(int, int, int, int, int, int);
		void DrawArcWoP(int, int, int, int, int, int);
		void DrawBezier(float, float, float, float, float, float, float, float);
		void DrawBezierWoP(float, float, float, float, float, float, float, float);	
		void DrawPixel(int, int);
		void DrawPixelWoP(int, int);
		void DrawString(string, int, int);
		void DrawString(string, int, int, int, int);
		void DrawStringWoP(string, int, int);
		void DrawStringWoP(string, int, int, int, int);
		void DrawImage(HBITMAP, int, int);
		void DrawImage(HBITMAP, int, int, int, int);
		void DrawImage(string, int, int);
		void DrawImage(string, int, int, int, int);
		void DrawImageWoP(HBITMAP, int, int);
		void DrawImageWoP(HBITMAP, int, int, int, int);
		void DrawImageWoP(string, int, int);
		void DrawImageWoP(string, int, int, int, int);
		void DrawIcon(HICON, int, int);
		void DrawIcon(HICON, int, int, int, int);
		void DrawIcon(string, int, int);
		void DrawIcon(string, int, int, int, int);
		void DrawIconWoP(HICON, int, int);
		void DrawIconWoP(HICON, int, int, int, int);
		void DrawIconWoP(string, int, int);
		void DrawIconWoP(string, int, int, int, int);
		void DrawSquare(int, int, int);
		void DrawFullSquare(int, int, int);
		void DrawSquareWoP(int, int, int);
		void DrawFullSquareWoP(int, int, int);
		void DrawRectangle(int, int, int, int);
		void DrawFullRectangle(int, int, int, int);
		void DrawRectangleWoP(int, int, int, int);
		void DrawFullRectangleWoP(int, int, int, int);
		void DrawEllipse(int, int, int, int);
		void DrawFullEllipse(int, int, int, int);
		void DrawEllipseWoP(int, int, int, int);
		void DrawFullEllipseWoP(int, int, int, int);
		void DrawCircle(int, int, int);
		void DrawFullCircle(int, int, int);
		void DrawCircleWoP(int, int, int);
		void DrawFullCircleWoP(int, int, int);

		#pragma endregion



		/*
			### Proprietà disegno
			Proprietà del disegno
		*/

		#pragma region ProprietàDisegno

		UColor GetPenColor();
		void SetPenColor(UColor);
		void DefaultPenColor();
		float GetPenWidth();
		void SetPenWidth(float);
		void DefaultPenWidth();
		UColor GetFillColor();
		void SetFillColor(UColor);
		void DefaultFillColor();
		UStringAlignment GetHStringAlignment();
		void SetHStringAlignment(UStringAlignment);
		void DefaultHStringAlignment();
		UStringAlignment GetVStringAlignment();
		void SetVStringAlignment(UStringAlignment);
		void DefaultVStringAlignment();
		string GetFontName();
		void SetFontName(string);
		void DefaultFontName();
		float GetFontSize();
		void SetFontSize(float);
		void DefaultFontSize();

		#pragma endregion

	};
}
