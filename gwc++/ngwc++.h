#pragma once
#pragma unmanaged


#include <string>
#include "windows.h"
#include "gwc++.h"


#ifdef TONATIVE
#define DECLSPECIFIER __declspec(dllexport)
#define EXPIMP_TEMPLATE
#else
#define DECLSPECIFIER __declspec(dllimport)
#define EXPIMP_TEMPLATE extern
#endif


#ifndef POINT_S
#define POINT_S

struct POINTN
{
	int X;
	int Y;
};

#endif


#ifndef SIZE_S
#define SIZE_S

struct SIZEN
{
	int W;
	int H;
};

#endif


#ifndef COLOR_S
#define COLOR_S

struct COLORN
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
			Costruttori e distruttori.
		*/

		NGWC(int W, int H, std::wstring Title, int X, int Y);
		~NGWC();



		/*
			Metodi finestra.
		*/

		void StartWindow();
		void CloseWindow();
		void ShowWindow();
		void HideWindow();



		/*
			Proprietà finestra.
		*/

		// std::string GetWindowTitle();
		// void SetWindowTitle(std::string value);
		// Icon^ GetWindowIcon();
		// void SetWindowIcon(Icon^ Value);
		POINTN GetWindowLocation();
		void SetWindowLocation(POINTN Value);
		COLORN GetWindowColor();
		void SetWindowColor(COLORN Value);
		// Image^ GetWindowImage();
		// void SetWindowImage(Image^ Value);
		SIZEN GetWindowSize();
		void SetWindowSize(SIZEN Value);
		SIZEN GetWindowMinimumSize();
		void SetWindowMinimumSize(SIZEN Value);
		SIZEN GetWindowMaximumSize();
		void SetWindowMaximumSize(SIZEN Value);
		double GetWindowOpacity();
		void SetWindowOpacity(double Value);
		bool GetWindowAlwaysOnTop();
		void SetWindowAlwaysOnTop(bool Value);
		bool GetWindowInTaskbar();
		void SetWindowInTaskbar(bool Value);
		bool GetWindowMinimizeButton();
		void SetWindowMinimizeButton(bool Value);
		bool GetWindowMaximizeButton();
		void SetWindowMaximizeButton(bool Value);


		/*
			Proprietà disegno.
		*/

		void DefaultPenColor();
		COLORN GetPenColor();
		void SetPenColor(COLORN Value);
		void DefaultPenWidth();
		float GetPenWidth();
		void SetPenWidth(float Value);
		void DefaultFillColor();
		COLORN GetFillColor();
		void SetFillColor(COLORN Value);
		// void DefaultFontName();
		// std::wstring GetFontName();
		// void SetFontName(std::wstring Value);
		void DefaultFontSize();
		float GetFontSize();
		void SetFontSize(float Value);



		/*
			Metodo disegno.
		*/

		void ClearWindow();
		void DrawLine(int X1, int Y1, int X2, int Y2);
		void DrawArc(int X, int Y, int W, int H, int A, int B);
		void DrawText(std::wstring S, int X, int Y);
		// void DrawImage(Image^ I, int X, int Y);
		// void DrawIcon(Icon^ I, int X, int Y);
		void DrawRectangle(int X, int Y, int W, int H);
		void DrawFillRectangle(int X, int Y, int W, int H);
		void DrawEllipse(int X, int Y, int W, int H);
		void DrawFillEllipse(int X, int Y, int W, int H);
		// void DrawPolygon(array<Point>^ P)
		// void DrawFillPolygon(array<Point>^ P)
		void DrawPie(int X, int Y, int W, int H, int A, int B);
		void DrawFillPie(int X, int Y, int W, int H, int A, int B);



		/*
			Metodi evento.
		*/

		POINT RequestMouseDown(int B);
		POINT RequestMouseUp(int B);
		char RequestKeyDown(char C);
		char RequestKeyDown();
		char RequestKeyUp(char C);
		char RequestKeyUp();



		/*
			Metodi vari.
		*/

		int GetScreenMaxX();
		int GetScreenMaxY();
		int GetWindowMaxX();
		int GetWindowMaxY();

	private:

		void* NGWCAdress;

	};
}
