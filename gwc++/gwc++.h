/*
	GWC++ (Graphic Window for Console Application)

	- Questo progetto è sotto lincenza MIT (https://mit-license.org)
	- Questo progetto è disponibile su GitHub (https://github.com/reallukee/GWCpp)
	- Maggiori informazioni sono diponibili nel file README.md

	ATUORE:			Realluke
	DESCRIZIONE:	Classe gestita GWC
	DATA:			13/03/22
*/


#pragma once
#pragma managed


#include "pgwc++.h"


namespace GWCpp
{
	public ref class GWC
	{

	public:

		/*
			Costruttori e distruttori
		*/

		// Costruttori
		GWC()
		{
			PGWC = gcnew GWCpp::PGWC();
		}

		GWC(int W, int H)
		{
			PGWC = gcnew GWCpp::PGWC(W, H);
		}

		GWC(int W, int H, String^ Title)
		{
			PGWC = gcnew GWCpp::PGWC(W, H, Title);
		}

		GWC(int W, int H, String^ Title, int X, int Y)
		{
			PGWC = gcnew GWCpp::PGWC(W, H, Title, X, Y);
		}

		// Distruttore
		~GWC()
		{
			//~PGWC();
		}



		/*
			Metodi finestra
		*/

		// Start Window
		void StartWindow()
		{
			PGWC->StartWindow();
		}

		// Close Window
		void CloseWindow()
		{		
			PGWC->CloseWindow();
		}

		// Suspend Window
		void SuspendWindow()
		{
			PGWC->SuspendWindow();
		}

		// Resume Window
		void ResumeWindow()
		{
			PGWC->ResumeWindow();
		}

		// Show Window
		void ShowWindow()
		{
			PGWC->ShowWindow();
		}

		// Hide Window
		void HideWindow()
		{
			PGWC->HideWindow();
		}



		/*
			Proprietà finestra
		*/

		// Window Title
		property String^ WindowTitle
		{
			String^ get()
			{
				return PGWC->WindowTitle;
			}

			void set(String^ Value)
			{
				PGWC->WindowTitle = Value;
			}
		}

		// Window Icon Visible
		property bool WindowIconVisible
		{
			bool get()
			{
				return PGWC->WindowIconVisible;
			}

			void set(bool Value)
			{
				PGWC->WindowIconVisible = Value;
			}
		}

		// Window Icon
		property Icon^ WindowIcon
		{
			Icon^ get()
			{
				return PGWC->WindowIcon;
			}

			void set(Icon^ Value)
			{
				PGWC->WindowIcon = Value;
			}
		}

		// Window Location
		property Point WindowLocation
		{
			Point get()
			{
				return PGWC->WindowLocation;
			}

			void set(Point Value)
			{
				PGWC->WindowLocation = Value;
			}
		}

		// Window Color
		property Color WindowColor
		{
			Color get()
			{
				return PGWC->WindowColor;
			}

			void set(Color Value)
			{
				PGWC->WindowColor = Value;
			}
		}

		// Window Image
		property Image^ WindowImage
		{
			Image^ get()
			{
				return PGWC->WindowImage;
			}

			void set(Image^ Value)
			{
				PGWC->WindowImage = Value;
			}
		}

		// Window Size
		property Size WindowSize
		{
			Size get()
			{
				return PGWC->WindowSize;
			}

			void set(Size Value)
			{
				PGWC->WindowSize = Value;
			}
		}

		// Window Size State
		property FormWindowState WindowSizeState
		{
			FormWindowState get()
			{
				return PGWC->WindowSizeState;
			}

			void set(FormWindowState Value)
			{
				PGWC->WindowSizeState = Value;
			}
		}

		// Window Minimum Size
		property Size WindowMinimumSize
		{
			Size get()
			{
				return PGWC->WindowMinimumSize;
			}

			void set(Size Value)
			{
				PGWC->WindowMinimumSize = Value;
			}
		}

		// Window Maximum Size
		property Size WindowMaximumSize
		{
			Size get()
			{
				return PGWC->WindowMaximumSize;
			}

			void set(Size Value)
			{
				PGWC->WindowMaximumSize = Value;
			}
		}

		// Window Opacity
		property double WindowOpacity
		{
			double get()
			{
				return PGWC->WindowOpacity;
			}

			void set(Double Value)
			{
				PGWC->WindowOpacity = Value;
			}
		}

		// Window Always On Top
		property bool WindowAlwaysOnTop
		{
			bool get()
			{
				return PGWC->WindowAlwaysOnTop;
			}

			void set(bool Value)
			{
				PGWC->WindowAlwaysOnTop = Value;
			}
		}

		// Window In Taskbar
		property bool WindowInTaskbar
		{
			bool get()
			{
				return PGWC->WindowInTaskbar;
			}

			void set(bool Value)
			{
				PGWC->WindowInTaskbar = Value;
			}
		}

		// Window Buttons
		property bool WindowButtons
		{
			bool get()
			{
				return PGWC->WindowButtons;
			}

			void set(bool Value)
			{
				PGWC->WindowButtons = Value;
			}
		}

		// Window Minimize Button
		property bool WindowMinimizeButton
		{
			bool get()
			{
				return PGWC->WindowMinimizeButton;
			}

			void set(bool Value)
			{
				PGWC->WindowMinimizeButton = Value;
			}
		}

		// Window Maximize Button
		property bool WindowMaximizeButton
		{
			bool get()
			{
				return PGWC->WindowMaximizeButton;
			}

			void set(bool Value)
			{
				PGWC->WindowMaximizeButton = Value;
			}
		}



		/*
			Proprietà disegno
		*/

		// Pen Color
		void DefaultPenColor()
		{
			PGWC->DefaultPenColor();
		}

		property Color PenColor
		{
			Color get()
			{
				return PGWC->PenColor;
			}

			void set(Color Value)
			{
				PGWC->PenColor = Value;
			}
		}

		// Pen Width
		void DefaultPenWidth()
		{
			PGWC->DefaultPenWidth();
		}

		property float PenWidth
		{
			float get()
			{
				return PGWC->PenWidth;
			}

			void set(float Value)
			{
				PGWC->PenWidth = Value;
			}
		}

		// Fill Color
		void DefaultFillColor()
		{

			PGWC->DefaultFillColor();
		}

		property Color FillColor
		{
			Color get()
			{
				return PGWC->FillColor;
			}

			void set(Color Value)
			{
				PGWC->FillColor = Value;
			}
		}

		// Font Name
		void DefaultFontName()
		{

			PGWC->DefaultFontName();
		}

		property String^ FontName
		{
			String^ get()
			{
				return PGWC->FontName;
			}

			void set(String^ Value)
			{
				PGWC->FontName = Value;
			}
		}

		// Font Size
		void DefaultFontSize()
		{

			PGWC->DefaultFontSize();
		}

		property float FontSize
		{
			float get()
			{
				return PGWC->FontSize;
			}

			void set(float Value)
			{
				PGWC->FontSize = Value;
			}
		}



		/*
			Metodo disegno
		*/

		// Clear Window
		void ClearWindow()
		{
			PGWC->ClearWindow();
		}

		// Save Canvas
		void SaveCanvas()
		{
			PGWC->SaveCanvas();
		}

		// Restore Canvas
		void RestoreCanvas()
		{
			PGWC->RestoreCanvas();
		}

		// Draw Pixel
		void DrawPixel(int X, int Y)
		{
			PGWC->DrawPixel(X, Y);
		}

		// Draw Line
		void DrawLine(int X1, int Y1, int X2, int Y2)
		{
			PGWC->DrawLine(X1, Y1, X2, Y2);
		}

		// Draw Arc
		void DrawArc(int X, int Y, int W, int H, int A, int B)
		{
			PGWC->DrawArc(X, Y, W, H, A, B);
		}

		// Draw Bezier
		void DrawBezier(float X1, float Y1, float X2, float Y2, float X3, float Y3, float X4, float Y4)
		{
			PGWC->DrawBezier(X1, Y1, X2, Y2, X3, Y3, X4, Y4);
		}

		// Draw String
		void DrawString(String^ S, int X, int Y)
		{
			PGWC->DrawString(S, X, Y);
		}

		// Draw Image
		void DrawImage(Image^ I, int X, int Y)
		{
			PGWC->DrawImage(I, X, Y);
		}

		// Draw Image From File
		void DrawImageFromFile(String^ F, int X, int Y)
		{
			PGWC->DrawImageFromFile(F, X, Y);
		}

		// Draw Icon
		void DrawIcon(Icon^ I, int X, int Y)
		{
			PGWC->DrawIcon(I, X, Y);
		}

		// Draw Icon From File
		void DrawIconFromFile(String^ F, int X, int Y)
		{
			PGWC->DrawIconFromFile(F, X, Y);
		}

		// Draw Square
		void DrawSquare(int X, int Y, int L)
		{
			PGWC->DrawSquare(X, Y, L);
		}

		// Draw Fill Square
		void DrawFillSquare(int X, int Y, int L)
		{
			PGWC->DrawFillSquare(X, Y, L);
		}

		// Draw Rectangle
		void DrawRectangle(int X, int Y, int W, int H)
		{
			PGWC->DrawRectangle(X, Y, W, H);
		}

		// Draw Fill Rectangle
		void DrawFillRectangle(int X, int Y, int W, int H)
		{
			PGWC->DrawFillRectangle(X, Y, W, H);
		}

		// Draw Ellipse
		void DrawEllipse(int X, int Y, int W, int H)
		{
			PGWC->DrawEllipse(X, Y, W, H);
		}

		// Draw Fill Ellipse
		void DrawFillEllipse(int X, int Y, int W, int H)
		{
			PGWC->DrawFillEllipse(X, Y, W, H);
		}

		// Draw Circle
		void DrawCircle(int X, int Y, int R)
		{
			PGWC->DrawCircle(X, Y, R);
		}

		// Draw Fill Circle
		void DrawFillCircle(int X, int Y, int R)
		{
			PGWC->DrawFillCircle(X, Y, R);
		}

		// Draw Curve
		void DrawCurve(array<Point>^ P)
		{
			PGWC->DrawCurve(P);
		}

		// Draw Closed Curve
		void DrawClosedCurve(array<Point>^ P)
		{
			PGWC->DrawClosedCurve(P);
		}

		// Draw Polygon
		void DrawPolygon(array<Point>^ P)
		{
			PGWC->DrawPolygon(P);
		}

		// Draw Fill Polygon
		void DrawFillPolygon(array<Point>^ P)
		{
			PGWC->DrawFillPolygon(P);
		}

		// Draw Pie
		void DrawPie(int X, int Y, int W, int H, int A, int B)
		{
			PGWC->DrawPie(X, Y, W, H, A, B);
		}

		// Draw Fill Pie
		void DrawFillPie(int X, int Y, int W, int H, int A, int B)
		{
			PGWC->DrawFillPie(X, Y, W, H, A, B);
		}

		// Draw From Screen
		void DrawFromScreen(int X1, int Y1, int X2, int Y2, int W, int H)
		{
			PGWC->DrawFromScreen(X1, Y1, X2, Y2, W, H);
		}



		/*
			Metodi evento
		*/

		// Mouse Down
		Point RequestMouseDown(MouseButtons B)
		{
			return PGWC->RequestMouseDown(B);
		}

		Point RequestMoudeDown()
		{
			return PGWC->RequestMouseDown();
		}

		// Mouse Up
		Point RequestMouseUp(MouseButtons B)
		{
			return PGWC->RequestMouseUp(B);
		}

		Point RequestMouseUp()
		{
			return PGWC->RequestMouseUp();
		}

		// key Down
		char RequestKeyDown(char C)
		{
			return PGWC->RequestKeyDown(C);
		}

		char RequestKeyDown()
		{
			return PGWC->RequestKeyDown();
		}

		// Key Up
		char RequestKeyUp(char C)
		{
			return PGWC->RequestKeyUp(C);
		}

		char RequestKeyUp()
		{
			return PGWC->RequestKeyUp();
		}

	private:

		GWCpp::PGWC^ PGWC;

	};
}