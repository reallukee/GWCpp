/*
	GWC++ (Graphic Window for Console Application)

	- Questo progetto è sotto lincenza MIT (https://mit-license.org)
	- Questo progetto è disponibile su GitHub (https://github.com/reallukee/GWCpp)
	- Maggiori informazioni sono diponibili nel file README.md

	ATUORE:			Realluke
	DESCRIZIONE:	Classe UGWC
	DATA:			24/03/22
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


namespace GWCpp
{
	struct UGPoint
	{
		int X;
		int Y;
	};


	struct UGSize
	{
		int Width;
		int Height;
	};


	struct UGColor
	{
		int R;
		int G;
		int B;
	};


	enum UGMouseButtons
	{
		None = 0,
		Left = 1048576,
		Right = 2097152,
		Middle = 4194304
	};


	enum UGWindowState
	{
		Normal = 0,
		Minimized = 1,
		Maximized = 2
	};


	enum UGOutputBoxStyle
	{
		ApplicationModal = 0,
		DefaultButton1 = 0,
		OkOnly = 0,
		OkCancel = 1,
		AbortRetryIgnore = 2,
		YesNoCancel = 3,
		YesNo = 4,
		RetryCancel = 5,
		Critical = 16,
		Question = 32,
		Exclamation = 48,
		Information = 64,
		DefaultButton2 = 256,
		DefaultButton3 = 512,
		SystemModal = 4096,
		MsgBoxHelp = 16384,
		MsgBoxSetForeground = 65536,
		MsgBoxRight = 524288,
		MsgBoxRtlReading = 1048576
	};


	enum UGOutputBoxResult
	{
		OK = 1,
		Cancel = 2,
		Abort = 3,
		Retry = 4,
		Ignore = 5,
		Yes = 6,
		No = 7
	};


	class DECLSPECIFIER UGWC
	{

	private:

		void* UGWCAdress;

	public:

		/*
			Costruttori e distruttori
		*/

		UGWC();
		UGWC(int Width, int Height);
		UGWC(int Width, int Height, std::string);
		UGWC(int Width, int Height, std::string Title, int X, int Y);
		~UGWC();



		/*
			Interazioni.
		*/

		std::string InputBox(std::string Prompt, std::string Title, std::string DefaultResponse, int X, int Y);
		UGOutputBoxResult OutputBox(std::string Prompt, UGOutputBoxStyle Style, std::string Title);



		/*
			Metodi finestra
		*/

		bool StartWindow();
		bool CloseWindow();
		bool SuspendWindow();
		bool ResumeWindow();
		bool PauseWindow(int Time);
		bool ShowWindow();
		bool HideWindow();
		int GetWindowMaxX();
		int GetWindowRealMaxX();
		int GetWindowMaxY();
		int GetWindowRealMaxY();
		int GetScreenMaxX();
		int GetScreenRealMaxX();
		int GetScreenMaxY();
		int GetScreenRealMaxY();
		bool CreateCanvasState(std::string Name);
		bool DeleteCanvasState(std::string Name);
		bool SaveCanvasState(std::string Name);
		bool LoadCanvasState(std::string Name);
		UGPoint RequestMouseDown(UGMouseButtons B);
		UGPoint RequestMouseDown();
		UGPoint RequestMouseUp(UGMouseButtons B);
		UGPoint RequestMouseUp();
		char RequestKeyDown(char C);
		char RequestKeyDown();
		char RequestKeyUp(char C);
		char RequestKeyUp();



		/*
			Proprietà finestra
		*/

		bool GetWindowStarted();
		bool GetWindowClosed();
		bool GetWindowSuspended();
		UGPoint GetMouseLocation();
		void SetMouseLocation(UGPoint Value);
		int GetMouseX();
		void SetMouseX(int Value);
		int GetMouseY();
		void SetMouseY(int Value);
		std::string GetWindowTitle();
		void SetWindowTitle(std::string Value);
		void DefaultWindowTitle();
		// Icon^ GetWindowIcon();
		// void SetWindowIcon(Icon^ Value);
		// void DefaultWindowIcon();
		bool GetWindowIconVisible();
		void SetWindowIconVisible(bool Value);
		void DefaultWindowIconVisible();
		UGPoint GetWindowLocation();
		void SetWindowLocation(UGPoint Value);
		int GetWindowX();
		void SetWindowX(int Value);
		int GetWindowY();
		void SetWindowY(int Value);
		void DefaultWindowLocation();
		void DefaultWindowX();
		void DefaultWindowY();
		UGColor GetWindowColor();
		void SetWindowColor(UGColor Value);
		void DefaultWindowColor();
		// Image^ GetWindowImage();
		// void SetWindowImage(Image^ Value);
		// void DefaultWindowImage();
		UGSize GetWindowSize();
		void SetWindowSize(UGSize Value);
		int GetWindowWidth();
		void SetWindowWidth(int Value);
		int GetWindowHeight();
		void SetWindowHeight(int Value);
		void DefaultWindowSize();
		void DefaultWindowWidth();
		void DefaultWindowHeight();
		UGSize GetWindowRealSize();
		void SetWindowRealSize(UGSize Value);
		int GetWindowRealWidth();
		void SetWindowRealWidth(int Value);
		int GetWindowRealHeight();
		void SetWindowRealHeight(int Value);
		void DefaultWindowRealSize();
		void DefaultWindowRealWidth();
		void DefaultWindowRealHeight();
		UGWindowState GetWindowSizeState();
		void SetWindowSizeState(UGWindowState Value);
		void DefaultWindowSizeState();
		UGSize GetWindowMinimumSize();
		void SetWindowMinimumSize(UGSize Value);
		void DefaultWindowMinimumSize();
		UGSize GetWindowMaximumSize();
		void SetWindowMaximumSize(UGSize Value);
		void DefaultWindowMaximumSize();
		double GetWindowOpacity();
		void SetWindowOpacity(double Value);
		void DefaultWindowOpacity();
		bool GetWindowAlwaysOnTop();
		void SetWindowAlwaysOnTop(bool Value);
		void DefaultWindowAlwaysOnTop();
		bool GetWindowInTaskbar();
		void SetWindowInTaskbar(bool Value);
		void DefaultWindowInTaskBar();
		bool GetWindowButtons();
		void SetWindowButtons(bool Value);
		void DefaultWindowButtons();
		bool GetWindowMinimizeButton();
		void SetWindowMinimizeButton(bool Value);
		void DefaultWindowMinimizeButton();
		bool GetWindowMaximizeButton();
		void SetWindowMaximizeButton(bool Value);
		void DefaultWindowMaximizeButton();



		/*
			Proprietà disegno
		*/

		UGColor GetPenColor();
		void SetPenColor(UGColor Value);
		void DefaultPenColor();
		float GetPenWidth();
		void SetPenWidth(float Value);
		void DefaultPenWidth();
		UGColor GetFillColor();
		void SetFillColor(UGColor Value);
		void DefaultFillColor();
		std::string GetFontName();
		void SetFontName(std::string Value);
		void DefaultFontName();
		float GetFontSize();
		void SetFontSize(float Value);
		void DefaultFontSize();



		/*
			Metodi disegno
		*/

		void ClearWindow(UGColor Color);
		void SaveCanvas();
		void RestoreCanvas();
		void DrawPixel(int X, int Y);
		void DrawLine(int X1, int Y1, int X2, int Y2);
		void DrawArc(int X, int Y, int Width, int Height, int A, int B);
		void DrawBezier(float X1, float Y1, float X2, float Y2, float X3, float Y3, float X4, float Y4);
		void DrawString(std::string S, int X, int Y);
		// void DrawImage(Image^ Image, int X, int Y);
		void DrawImageFromFile(std::string FileName, int X, int Y);
		// void DrawIcon(Icon^ Icon, int X, int Y);
		void DrawIconFromFile(std::string FileName, int X, int Y);
		void DrawRectangle(int X, int Y, int Width, int Height);
		void DrawSquare(int X, int Y, int L);
		void DrawFullSquare(int X, int Y, int L);
		void DrawFullRectangle(int X, int Y, int Width, int Height);
		void DrawEllipse(int X, int Y, int Width, int Height);
		void DrawFullEllipse(int X, int Y, int Width, int Height);
		void DrawCircle(int X, int Y, int R);
		void DrawFullCircle(int X, int Y, int R);
		// void DrawCurve(array<UGPoint>^ P);
		// DrawClosedCurve(array<UGPoint>^ P);
		// void DrawPolygon(array<UGPoint>^ P);
		// void DrawFullPolygon(array<UGPoint>^ P);
		void DrawPie(int X, int Y, int Width, int Height, int A, int B);
		void DrawFullPie(int X, int Y, int Width, int Height, int A, int B);
		void DrawFromScreen(int X1, int Y1, int X2, int Y2, int Width, int Height);

	};
}
