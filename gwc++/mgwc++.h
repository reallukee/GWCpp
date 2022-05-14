/*
	GWC++ (Graphic Window for Console Application)

	- Questo progetto è sotto lincenza MIT (https://mit-license.org)
	- Questo progetto è disponibile su GitHub (https://github.com/reallukee/GWCpp)
	- Maggiori informazioni sono diponibili nel file README.md


	ATUORE:			Realluke | Aka Luca Pollicino
	DESCRIZIONE:	Classe MGWC
	DATA:			24/04/22
	VERSIONE:		1.1.0
*/

#pragma once
#pragma managed

#include "gwc++.h"

namespace GWCpp
{
	public ref class MGWC
	{

	private:

		GWCpp::GWC^ GWC;

	public:

		/*
			### Costruttori
			Costruttori
		*/

		#pragma region Costruttori
		
		MGWC() { GWC = gcnew GWCpp::GWC(); }
		MGWC(int Width, int Height) { GWC = gcnew GWCpp::GWC(Width, Height); }
		MGWC(int Width, int Height, String^ Title) { GWC = gcnew GWCpp::GWC(Width, Height, Title); }
		MGWC(int Width, int Height, String^ Title, int X, int Y){ GWC = gcnew GWCpp::GWC(Width, Height, Title, X, Y); }

		#pragma endregion



		/*
			### Metodi conversione
			Metodi di conversione
		*/

		#pragma region MetodiConversione

		MPoint PointToMPoint(Point Value) { return GWC->PointToMPoint(Value); }
		Point MPointToPoint(MPoint Value) { return GWC->MPointToPoint(Value); }
		MColor ColorToMColor(Color Value) { return GWC->ColorToMColor(Value); }
		Color MColorToColor(MColor Value) { return GWC->MColorToColor(Value); }
		MSize SizeToMSize(System::Drawing::Size Value) { return GWC->SizeToMSize(Value); }
		System::Drawing::Size MSizeToSize(MSize Value) { return GWC->MSizeToSize(Value); }

		#pragma endregion



		/*
			### Metodi Interattivi
			Metodi di interazione I/O
		*/

		#pragma region MetodiInterattivi

		String^ InputBox(String^ Prompt, String^ Title, String^ DefaultResponse, int X, int Y) { return GWC->InputBox(Prompt, Title, DefaultResponse, X, Y); }
		MOutputBoxResult OutputBox(String^ Prompt, MOutputBoxStyle Style, String^ Title) { return GWC->OutputBox(Prompt, Style, Title); }

		#pragma endregion



		/*
			### Metodi Finestra
			Metodi della finestra
		*/

		#pragma region MetodiFinestra

		bool StartWindow() { return GWC->StartWindow(); }
		bool CloseWindow() { return GWC->CloseWindow(); }
		bool SuspendWindow() { return GWC->SuspendWindow(); }
		bool ResumeWindow() { return GWC->ResumeWindow(); }
		bool PauseWindow(int Time) { return GWC->PauseWindow(Time); }
		bool RedrawWindow(int X, int Y, int Width, int Height) { return GWC->RedrawWindow(X, Y, Width, Height); }
		bool RedrawWindow() { return GWC->RedrawWindow(); }
		bool ShowWindow() { return GWC->ShowWindow(); }
		bool HideWindow() { return GWC->HideWindow(); }
		int GetWindowMaxX() { return GWC->GetWindowMaxX(); }
		int GetWindowRealMaxX() { return GWC->GetWindowRealMaxX(); }
		int GetWindowMaxY() { return GWC->GetWindowMaxY(); }
		int GetWindowRealMaxY() { return GWC->GetWindowRealMaxY(); }
		int GetScreenMaxX() { return GWC->GetScreenMaxX(); }
		int GetScreenRealMaxX() { return GWC->GetScreenRealMaxX(); }
		int GetScreenMaxY() { return GWC->GetScreenMaxY(); }
		int GetScreenRealMaxY() { return GWC->GetScreenRealMaxY(); }
		MPoint RequestMouseDown(MMouseButtons B) { return GWC->RequestMouseDown(B); }
		MPoint RequestMouseDown() { return GWC->RequestMouseDown(); }
		MPoint RequestMouseUp(MMouseButtons B) { return GWC->RequestMouseUp(B); }
		MPoint RequestMouseUp() { return GWC->RequestMouseUp(); }
		Char RequestKeyDown(char C) { return GWC->RequestKeyDown(C); }
		Char RequestKeyDown() { return GWC->RequestKeyDown(); }
		Char RequestKeyUp(char C) { return GWC->RequestKeyUp(C); }
		Char RequestKeyUp() { return GWC->RequestKeyUp(); }

		#pragma endregion



		/*
			### Proprietà finestra.
			Proprietà della finestra
		*/

		#pragma region ProprietàFinestra

		property bool WindowStarted
		{
			bool get() { return GWC->WindowStarted; }
		}



		property bool WindowClosed
		{
			bool get() { return GWC->WindowClosed; }
		}



		property bool WindowSuspended
		{
			bool get() { return GWC->WindowSuspended; }
		}



		property bool WindowVisible
		{
			bool get() { return GWC->WindowVisible; }
		}



		property MPoint MouseLocation
		{
			MPoint get() { return GWC->MouseLocation; }
			void set(MPoint Value) { GWC->MouseLocation = Value; }
		}

		property int MouseX
		{
			int get() { return GWC->MouseLocation.X; }
			void set(int Value) { GWC->MouseLocation = MPoint(Value, MouseLocation.Y); }
		}

		property int MouseY
		{
			int get() { return GWC->MouseLocation.Y; }
			void set(int Value) { GWC->MouseLocation = MPoint(MouseLocation.X, Value); }
		}
		


		property String^ WindowTitle
		{
			String^ get() { return GWC->WindowTitle; }
			void set(String^ Value) { GWC->WindowTitle = Value; }
		}

		void DefaultWindwTitle() { GWC->DefaultWindowTitle(); }



		property bool WindowIconVisible
		{
			bool get() { return GWC->WindowIconVisible; }
			void set(bool Value) { GWC->WindowIconVisible = Value; }
		}

		void DefaultWindowIconVisible() { GWC->DefaultWindowIconVisible(); }



		property Icon^ WindowIcon
		{
			Icon^ get() { return GWC->WindowIcon; }
			void set(Icon^ Value) { GWC->WindowIcon = Value; }
		}

		void DefaultWindowIcon() { GWC->DefaultWindowIcon(); }



		property MPoint WindowLocation
		{
			MPoint get() { return GWC->WindowLocation; }
			void set(MPoint Value) { GWC->WindowLocation = Value; }
		}

		property int WindowX
		{
			int get() { return GWC->WindowX; }
			void set(int Value) { GWC->WindowX = Value; }
		}

		property int WindowY
		{
			int get() { return GWC->WindowY; }
			void set(int Value) { GWC->WindowY = Value; }
		}

		void DefaultWindowLocation() { GWC->DefaultWindowLocation(); }
		void DefaultWindowX() { GWC->DefaultWindowX(); }
		void DefaultWindowY() { GWC->DefaultWindowY(); }



		property MColor WindowColor
		{
			MColor get() { return GWC->WindowColor; }
			void set(MColor Value) { GWC->WindowColor = Value; }
		}

		void DefaultWindowColor() { GWC->DefaultWindowColor(); }



		property Image^ WindowImage
		{
			Image^ get() { return GWC->WindowImage; }
			void set(Image^ Value) { GWC->WindowImage = Value; }
		}

		void DefaultWindowImage() { GWC->DefaultWindowImage(); }



		property MSize WindowSize
		{
			MSize get() { return GWC->WindowSize; }
			void set(MSize Value) { GWC->WindowSize = Value; }
		}

		property int WindowWidth
		{
			int get() { return GWC->WindowWidth; }
			void set(int Value) { GWC->WindowWidth = Value; }
		}

		property int WindowHeight
		{
			int get() { return GWC->WindowHeight; }
			void set(int Value) { GWC->WindowHeight = Value; }
		}

		void DefaultWindowSize() { GWC->DefaultWindowSize(); }
		void DefaultWindowWidth() { GWC->DefaultWindowWidth(); }
		void DefaultWindowHeight() { GWC->DefaultWindowHeight(); }



		property MSize WindowRealSize
		{
			MSize get() { return GWC->WindowRealSize; }
			void set(MSize Value) { GWC->WindowRealSize = Value; }
		}

		property int WindowRealWidth
		{
			int get() { return GWC->WindowRealWidth; }
			void set(int Value) { GWC->WindowRealWidth = Value; }
		}

		property int WindowRealHeight
		{
			int get() { return GWC->WindowRealHeight; }
			void set(int Value) { GWC->WindowRealHeight = Value; }
		}

		void DefaultWindowRealSize() { GWC->DefaultWindowRealSize(); }
		void DefaultWindowRealWidth() { GWC->DefaultWindowRealWidth(); }
		void DefaultWindowRealHeight() { GWC->DefaultWindowRealHeight(); }

		property MWindowState WindowSizeState
		{
			MWindowState get() { return GWC->WindowSizeState; }
			void set(MWindowState Value) { GWC->WindowSizeState = Value; }
		}

		void DefaultWindowSizeState() { GWC->DefaultWindowSizeState(); }



		property MSize WindowMinimumSize
		{
			MSize get() { return GWC->WindowMinimumSize; }
			void set(MSize Value) { GWC->WindowMinimumSize = Value; }
		}

		void DefaultWindowMinimumSize() { GWC->DefaultWindowMinimumSize(); }



		property MSize WindowMaximumSize
		{
			MSize get() { return GWC->WindowMaximumSize; }
			void set(MSize Value) { GWC->WindowMaximumSize = Value; }
		}

		void DefaultWindowMaximumSize() { GWC->DefaultWindowMaximumSize(); }



		property double WindowOpacity
		{
			double get() { return GWC->WindowOpacity; }
			void set(Double Value) { GWC->WindowOpacity = Value; }
		}

		void DefaultWindowOpacity() { GWC->DefaultWindowOpacity(); }



		property bool WindowAlwaysOnTop
		{
			bool get() { return GWC->WindowAlwaysOnTop; }
			void set(bool Value) { GWC->WindowAlwaysOnTop = Value; }
		}

		void DefaultWindowAlwaysOnTop() { GWC->DefaultWindowAlwaysOnTop(); }



		property bool WindowInTaskbar
		{
			bool get() { return GWC->WindowInTaskbar; }
			void set(bool Value) { GWC->WindowInTaskbar = Value; }
		}

		void DefaultWindowInTaskbar() { GWC->DefaultWindowInTaskbar(); }



		property bool WindowButtons
		{
			bool get() { return GWC->WindowButtons; }
			void set(bool Value) { GWC->WindowButtons = Value; }
		}

		void DefaultWindowButtons() { GWC->DefaultWindowButtons(); }



		property bool WindowMinimizeButton
		{
			bool get() { return GWC->WindowMinimizeButton; }
			void set(bool Value) { GWC->WindowMinimizeButton = Value; }
		}

		void DefaultWindowMinimizeButton() { GWC->DefaultWindowMinimizeButton(); }



		property bool WindowMaximizeButton
		{
			bool get() { return GWC->WindowMaximizeButton; }
			void set(bool Value) { GWC->WindowMaximizeButton = Value; }
		}

		void DefaultWindowMaximizeButton() { GWC->DefaultWindowMaximizeButton(); }

		#pragma endregion



		/*
			### Metodi disegno
			Metodi del disegno
		*/

		#pragma region MetodiDisegno

		void SaveCanvas() { GWC->SaveCanvas(); }
		void SaveCanvasWoP() { GWC->SaveCanvasWoP(); }
		void RestoreCanvas() { GWC->RestoreCanvas(); }
		void RestoreCanvasWoP() { GWC->RestoreCanvasWoP(); }
		void ClearWindow(MColor C) { GWC->ClearWindow(C); }
		void ClearWindow() { GWC->ClearWindow(); }
		void ClearWindowWoP(MColor C) { GWC->ClearWindowWoP(C); }
		void ClearWindowWoP() { GWC->ClearWindowWoP(); }
		void DrawLine(int X1, int Y1, int X2, int Y2) { GWC->DrawLine(X1, Y1, X2, Y2); }
		void DrawLineWoP(int X1, int Y1, int X2, int Y2) { GWC->DrawLineWoP(X1, Y1, X2, Y2); }
		void DrawArc(int X, int Y, int Width, int Height, int A, int B) { GWC->DrawArc(X, Y, Width, Height, A, B); }
		void DrawArcWoP(int X, int Y, int Width, int Height, int A, int B) { GWC->DrawArcWoP(X, Y, Width, Height, A, B); }
		void DrawBezier(float X1, float Y1, float X2, float Y2, float X3, float Y3, float X4, float Y4) { GWC->DrawBezier(X1, Y1, X2, Y2, X3, Y3, X4, Y4); }
		void DrawBezierWoP(float X1, float Y1, float X2, float Y2, float X3, float Y3, float X4, float Y4) { GWC->DrawBezierWoP(X1, Y1, X2, Y2, X3, Y3, X4, Y4); }
		void DrawPixel(int X, int Y) { GWC->DrawPixel(X, Y); }
		void DrawPixelWoP(int X, int Y) { GWC->DrawPixelWoP(X, Y); }
		void DrawString(String^ Stringa, int X, int Y) { GWC->DrawString(Stringa, X, Y); }
		void DrawString(String^ Stringa, int X, int Y, int Width, int Height) { GWC->DrawString(Stringa, X, Y, Width, Height); }
		void DrawStringWoP(String^ Stringa, int X, int Y) { GWC->DrawStringWoP(Stringa, X, Y); }
		void DrawStringWoP(String^ Stringa, int X, int Y, int Width, int Height) { GWC->DrawStringWoP(Stringa, X, Y, Width, Height); }
		void DrawImage(Image^ Image, int X, int Y) { GWC->DrawImage(Image, X, Y); }
		void DrawImage(Image^ Image, int X, int Y, int Width, int Height) { GWC->DrawImage(Image, X, Y, Width, Height); }
		void DrawImage(String^ FileName, int X, int Y) { GWC->DrawImage(FileName, X, Y); }
		void DrawImage(String^ FileName, int X, int Y, int Width, int Height) { GWC->DrawImage(FileName, X, Y, Width, Height); }
		void DrawImageWoP(Image^ Image, int X, int Y) { GWC->DrawImageWoP(Image, X, Y); }
		void DrawImageWoP(Image^ Image, int X, int Y, int Width, int Height) { GWC->DrawImageWoP(Image, X, Y, Width, Height); }
		void DrawImageWoP(String^ FileName, int X, int Y) { GWC->DrawImageWoP(FileName, X, Y); }
		void DrawImageWoP(String^ FileName, int X, int Y, int Width, int Height) { GWC->DrawImageWoP(FileName, X, Y, Width, Height); }
		void DrawIcon(Icon^ Icon, int X, int Y) { GWC->DrawIcon(Icon, X, Y); }
		void DrawIcon(Icon^ Icon, int X, int Y, int Width, int Height) { GWC->DrawIcon(Icon, X, Y, Width, Height); }
		void DrawIcon(String^ FileName, int X, int Y) { GWC->DrawIcon(FileName, X, Y); }
		void DrawIcon(String^ FileName, int X, int Y, int Width, int Height) { GWC->DrawIcon(FileName, X, Y, Width, Height); }
		void DrawIconWoP(Icon^ Icon, int X, int Y) { GWC->DrawIconWoP(Icon, X, Y); }
		void DrawIconWoP(Icon^ Icon, int X, int Y, int Width, int Height) { GWC->DrawIconWoP(Icon, X, Y, Width, Height); }
		void DrawIconWoP(String^ FileName, int X, int Y) { GWC->DrawIconWoP(FileName, X, Y); }
		void DrawIconWoP(String^ FileName, int X, int Y, int Width, int Height) { GWC->DrawIconWoP(FileName, X, Y, Width, Height); }
		void DrawSquare(int X, int Y, int L) { GWC->DrawSquare(X, Y, L); }
		void DrawFullSquare(int X, int Y, int L) { GWC->DrawFullSquare(X, Y, L); }
		void DrawSquareWoP(int X, int Y, int L) { GWC->DrawSquareWoP(X, Y, L); }
		void DrawFullSquareWoP(int X, int Y, int L) { GWC->DrawFullSquareWoP(X, Y, L); }
		void DrawRectangle(int X, int Y, int Width, int Height) { GWC->DrawRectangle(X, Y, Width, Height); }
		void DrawFullRectangle(int X, int Y, int Width, int Height) { GWC->DrawFullRectangle(X, Y, Width, Height); }
		void DrawRectangleWoP(int X, int Y, int Width, int Height) { GWC->DrawRectangleWoP(X, Y, Width, Height); }
		void DrawFullRectangleWoP(int X, int Y, int Width, int Height) { GWC->DrawFullRectangleWoP(X, Y, Width, Height); }
		void DrawEllipse(int X, int Y, int Width, int Height) { GWC->DrawEllipse(X, Y, Width, Height); }
		void DrawFullEllipse(int X, int Y, int Width, int Height) { GWC->DrawFullEllipse(X, Y, Width, Height); }
		void DrawEllipseWoP(int X, int Y, int Width, int Height) { GWC->DrawEllipseWoP(X, Y, Width, Height); }
		void DrawFullEllipseWoP(int X, int Y, int Width, int Height) { GWC->DrawFullEllipseWoP(X, Y, Width, Height); }
		void DrawCircle(int X, int Y, int R) { GWC->DrawCircle(X, Y, R); }
		void DrawFullCircle(int X, int Y, int R) { GWC->DrawFullCircle(X, Y, R); }
		void DrawCircleWoP(int X, int Y, int R) { GWC->DrawCircleWoP(X, Y, R); }
		void DrawFullCircleWoP(int X, int Y, int R) { GWC->DrawFullCircleWoP(X, Y, R); }
		
		#pragma endregion



		/*
			### Proprietà disegno
			Proprietà del disegno
		*/

		#pragma region ProprietàDisegno

		property MColor PenColor
		{
			MColor get() { return GWC->PenColor; }
			void set(MColor Value) { GWC->PenColor = Value; }
		}

		void DefaultPenColor() { GWC->DefaultPenColor(); }

		property float PenWidth
		{
			float get() { return GWC->PenWidth; }
			void set(float Value) { GWC->PenWidth = Value; }
		}

		void DefaultPenWidth() { GWC->DefaultPenWidth(); }

		property MColor FillColor
		{
			MColor get() { return GWC->FillColor; }
			void set(MColor Value) { GWC->FillColor = Value; }
		}

		void DefaultFillColor() { GWC->DefaultFillColor(); }

		property MStringAlignment HStringAlignment
		{
			MStringAlignment get() { return GWC->HStringAlignment; }
			void set(MStringAlignment Value) { GWC->HStringAlignment = Value; }
		}

		void DefaultHStringAlignment() { GWC->DefaultHStringAlignment(); }

		property MStringAlignment VStringAlignment
		{
			MStringAlignment get() { return GWC->VStringAlignment; }
			void set(MStringAlignment Value) { GWC->VStringAlignment = Value; }
		}

		void DefaultVStringAlignment() { GWC->DefaultVStringAlignment(); }

		property String^ FontName
		{
			String^ get() { return GWC->FontName; }
			void set(String^ Value) { GWC->FontName = Value; }
		}

		void DefaultFontName() { GWC->DefaultFontName(); }

		property float FontSize
		{
			float get() { return GWC->FontSize; }
			void set(float Value) { GWC->FontSize = Value; }
		}

		void DefaultFontSize() { GWC->DefaultFontSize(); }

		#pragma endregion

	};
}
