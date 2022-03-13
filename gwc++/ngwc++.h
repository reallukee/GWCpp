/*
	GWC++ (Graphic Window for Console Application)

	- Questo progetto è sotto lincenza MIT (https://mit-license.org)
	- Questo progetto è disponibile su GitHub (https://github.com/reallukee/GWCpp)
	- Maggiori informazioni sono diponibili nel file README.md

	ATUORE:			Realluke
	DESCRIZIONE:	Classe non gestita NGWC
	DATA:			13/03/22
*/


#pragma once
#pragma unmanaged


#include <string>
#include "windows.h"


#ifdef TONATIVE
#define DECLSPECIFIER __declspec(dllexport)
#define EXPIMP_TEMPLATE
#else
#define DECLSPECIFIER __declspec(dllimport)
#define EXPIMP_TEMPLATE extern
#endif


#ifndef NPOINTS
#define NPOINTS

struct NPOINT
{
	int X;
	int Y;
};

#endif


#ifndef NSIZES
#define NSIZES

struct NSIZE
{
	int W;
	int H;
};

#endif


#ifndef NCOLORS
#define NCOLORS

struct NCOLOR
{
	int R;
	int G;
	int B;
};

#endif


namespace NGWCpp
{
	class DECLSPECIFIER NGWC
	{

	public:

		/*
			Costruttori e distruttori
		*/

		NGWC();
		NGWC(int W, int H);
		NGWC(int W, int H, std::string);
		NGWC(int W, int H, std::string Title, int X, int Y);
		~NGWC();



		/*
			Metodi finestra
		*/

		void StartWindow();
		void CloseWindow();
		void ShowWindow();
		void HideWindow();
		void SuspendWindow();
		void ResumeWindow();



		/*
			Proprietà finestra
		*/

		std::string GetWindowTitle();
		void SetWindowTitle(std::string value);
		// Icon^ GetWindowIcon();
		// void SetWindowIcon(Icon^ Value);
		bool GetWindowIconVisible();
		void SetWindowIconVisible(bool Value);
		NPOINT GetWindowLocation();
		void SetWindowLocation(NPOINT Value);
		NCOLOR GetWindowColor();
		void SetWindowColor(NCOLOR Value);
		// Image^ GetWindowImage();
		// void SetWindowImage(Image^ Value);
		NSIZE GetWindowSize();
		void SetWindowSize(NSIZE Value);
		int GetWindowSizeState();
		void SetWindowSizeState(int Value);
		NSIZE GetWindowMinimumSize();
		void SetWindowMinimumSize(NSIZE Value);
		NSIZE GetWindowMaximumSize();
		void SetWindowMaximumSize(NSIZE Value);
		double GetWindowOpacity();
		void SetWindowOpacity(double Value);
		bool GetWindowAlwaysOnTop();
		void SetWindowAlwaysOnTop(bool Value);
		bool GetWindowInTaskbar();
		void SetWindowInTaskbar(bool Value);
		bool GetWindowButtons();
		void SetWindowButtons(bool Value);
		bool GetWindowMinimizeButton();
		void SetWindowMinimizeButton(bool Value);
		bool GetWindowMaximizeButton();
		void SetWindowMaximizeButton(bool Value);



		/*
			Proprietà disegno
		*/

		void DefaultPenColor();
		NCOLOR GetPenColor();
		void SetPenColor(NCOLOR Value);
		void DefaultPenWidth();
		float GetPenWidth();
		void SetPenWidth(float Value);
		void DefaultFillColor();
		NCOLOR GetFillColor();
		void SetFillColor(NCOLOR Value);
		void DefaultFontName();
		std::string GetFontName();
		void SetFontName(std::string Value);
		void DefaultFontSize();
		float GetFontSize();
		void SetFontSize(float Value);



		/*
			Metodi disegno
		*/

		void ClearWindow();
		void SaveCanvas();
		void RestoreCanvas();
		void DrawPixel(int X, int Y);
		void DrawLine(int X1, int Y1, int X2, int Y2);
		void DrawArc(int X, int Y, int W, int H, int A, int B);
		void DrawBezier(float X1, float Y1, float X2, float Y2, float X3, float Y3, float X4, float Y4);
		void DrawString(std::string S, int X, int Y);
		// void DrawImage(Image^ I, int X, int Y);
		void DrawImageFromFile(std::string F, int X, int Y);
		// void DrawIcon(Icon^ I, int X, int Y);
		void DrawIconFromFile(std::string F, int X, int Y);
		void DrawRectangle(int X, int Y, int W, int H);
		void DrawSquare(int X, int Y, int L);
		void DrawFillSquare(int X, int Y, int L);
		void DrawFillRectangle(int X, int Y, int W, int H);
		void DrawEllipse(int X, int Y, int W, int H);
		void DrawFillEllipse(int X, int Y, int W, int H);
		void DrawCircle(int X, int Y, int R);
		void DrawFillCircle(int X, int Y, int R);
		// void DrawCurve(array<Point>^ P);
		// DrawClosedCurve(array<Point>^ P);
		// void DrawPolygon(array<Point>^ P);
		// void DrawFillPolygon(array<Point>^ P);
		void DrawPie(int X, int Y, int W, int H, int A, int B);
		void DrawFillPie(int X, int Y, int W, int H, int A, int B);
		void DrawFromScreen(int X1, int Y1, int X2, int Y2, int W, int H);



		/*
			Metodi evento
		*/

		NPOINT RequestMouseDown(int B);
		NPOINT RequestMoudeDown();
		NPOINT RequestMouseUp(int B);
		NPOINT RequestMouseUp();
		char RequestKeyDown(char C);
		char RequestKeyDown();
		char RequestKeyUp(char C);
		char RequestKeyUp();

	private:

		void* NGWCAdress;

	};
}
