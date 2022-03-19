/*
	GWC++ (Graphic Window for Console Application)

	- Questo progetto è sotto lincenza MIT (https://mit-license.org)
	- Questo progetto è disponibile su GitHub (https://github.com/reallukee/GWCpp)
	- Maggiori informazioni sono diponibili nel file README.md

	ATUORE:			Realluke
	DESCRIZIONE:	Classe gestita GWC
	DATA:			19/03/22
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
			Costruttori e distruttore.
		*/
		
		// Costruttore.
		MGWC()
		{
			GWC = gcnew GWCpp::GWC();
		}

		MGWC(int Width, int Height)
		{
			GWC = gcnew GWCpp::GWC(Width, Height);
		}

		MGWC(int Width, int Height, String^ Title)
		{
			GWC = gcnew GWCpp::GWC(Width, Height, Title);
		}

		MGWC(int Width, int Height, String^ Title, int X, int Y)
		{
			GWC = gcnew GWCpp::GWC(Width, Height, Title, X, Y);
		}

		// Distruttore.
		~MGWC()
		{
			// ~GWC();
		}



		/*
			Metodi di conversione.
		*/

		// Point To MGPoint.
		MGPoint PointToGPoint(Point Value)
		{
			return GWC->PointToMGPoint(Value);
		}

		// MGPoint To Point.
		Point GPointToPoint(MGPoint Value)
		{
			return GWC->MGPointToPoint(Value);
		}

		// Color To MGColor.
		MGColor ColorToGColor(Color Value)
		{
			return GWC->ColorToMGColor(Value);
		}

		// MGColor To Color.
		Color GColorToColor(MGColor Value)
		{
			return GWC->MGColorToColor(Value);
		}

		// Size To MGSize.
		MGSize SizeToGSize(System::Drawing::Size Value)
		{
			return GWC->SizeToMGSize(Value);
		}

		// MGSize To Size.
		System::Drawing::Size GSizeToSize(MGSize Value)
		{
			return GWC->MGSizeToSize(Value);
		}



		/*
			Metodi finestra.
		*/

		// Start Window.
		bool StartWindow()
		{
			return GWC->StartWindow();
		}

		// Close Window.
		bool CloseWindow()
		{		
			return GWC->CloseWindow();
		}

		// Suspend Window.
		bool SuspendWindow()
		{
			return GWC->SuspendWindow();
		}

		// Resume Window.
		bool ResumeWindow()
		{
			return GWC->ResumeWindow();
		}

		// Pause Window.
		bool PauseWindow(int Time)
		{
			return GWC->PauseWindow(Time);
		}

		// Get Window Max X.
		int GetWindowMaxX()
		{
			return GWC->GetWindowMaxX();
		}

		// Get Window Real Max X.
		int GetWindowRealMaxX()
		{
			return GWC->GetWindowRealMaxX();
		}

		// Get Window Max Y.
		int GetWindowMaxY()
		{
			return GWC->GetWindowMaxY();
		}

		// Get Window Real Max Y.
		int GetWindowRealMaxY()
		{
			return GWC->GetWindowRealMaxY();
		}

		// Get Screen Max X.
		int GetScreenMaxX()
		{
			return GWC->GetScreenMaxX();
		}

		// Get Screen Real Max X.
		int GetScreenRealMaxX()
		{
			return GWC->GetScreenRealMaxX();
		}

		// Get Screen Max Y.
		int GetScreenMaxY()
		{
			return GWC->GetScreenMaxY();
		}

		// Get Screen Real Max Y.
		int GetScreenRealMaxY()
		{
			return GWC->GetScreenRealMaxY();
		}

		// Show Window.
		bool ShowWindow()
		{
			return GWC->ShowWindow();
		}

		// Hide Window.
		bool HideWindow()
		{
			return GWC->HideWindow();
		}

		// Create Canvas State.
		bool CreateCanvasState(String^ Name)
		{
			return GWC->CreateCanvasState(Name);
		}

		// Delete Canvas State.
		bool DeleteCanvasState(String^ Name)
		{
			return GWC->DeleteCanvasState(Name);
		}

		// Save Canvas State.
		bool SaveCanvasState(String^ Name)
		{
			return GWC->SaveCanvasState(Name);
		}

		// Load Canvas State.
		bool LoadCanvasState(String^ Name)
		{
			return GWC->LoadCanvasState(Name);
		}
		
		// Mouse Down.
		MGPoint RequestMouseDown(MGMouseButtons B)
		{
			return GWC->RequestMouseDown(B);
		}

		MGPoint RequestMoudeDown()
		{
			return GWC->RequestMouseDown();
		}

		// Mouse Up.
		MGPoint RequestMouseUp(MGMouseButtons B)
		{
			return GWC->RequestMouseUp(B);
		}

		MGPoint RequestMouseUp()
		{
			return GWC->RequestMouseUp();
		}

		// key Down.
		Char RequestKeyDown(char C)
		{
			return GWC->RequestKeyDown(C);
		}

		Char RequestKeyDown()
		{
			return GWC->RequestKeyDown();
		}

		// Key Up.
		Char RequestKeyUp(char C)
		{
			return GWC->RequestKeyUp(C);
		}

		Char RequestKeyUp()
		{
			return GWC->RequestKeyUp();
		}



		/*
			Proprietà finestra.
		*/

		// Window Started.
		property bool WindowStarted
		{
			bool get()
			{
				return GWC->WindowStarted;
			}
		}

		// Window Closed.
		property bool WindowClosed
		{
			bool get()
			{
				return GWC->WindowClosed;
			}
		}

		// Window Suspended.
		property bool WindowSuspended
		{
			bool get()
			{
				return GWC->WindowSuspended;
			}
		}

		// Window Title.
		property String^ WindowTitle
		{
			String^ get()
			{
				return GWC->WindowTitle;
			}

			void set(String^ Value)
			{
				GWC->WindowTitle = Value;
			}
		}

		void DefaultWindwTitle()
		{
			GWC->DefaultWindowTitle();
		}

		// Window Icon Visible.
		property bool WindowIconVisible
		{
			bool get()
			{
				return GWC->WindowIconVisible;
			}

			void set(bool Value)
			{
				GWC->WindowIconVisible = Value;
			}
		}

		void DefaultWindowIconVisible()
		{
			GWC->DefaultWindowIconVisible();
		}

		// Window Icon.
		property Icon^ WindowIcon
		{
			Icon^ get()
			{
				return GWC->WindowIcon;
			}

			void set(Icon^ Value)
			{
				GWC->WindowIcon = Value;
			}
		}

		void DefaultWindowIcon()
		{
			GWC->DefaultWindowIcon();
		}

		// Window Location.
		property MGPoint WindowLocation
		{
			MGPoint get()
			{
				return GWC->WindowLocation;
			}

			void set(MGPoint Value)
			{
				GWC->WindowLocation = Value;
			}
		}

		property int WindowX
		{
			int get()
			{
				return GWC->WindowX;
			}

			void set(int Value)
			{
				GWC->WindowX = Value;
			}
		}

		property int WindowY
		{
			int get()
			{
				return GWC->WindowY;
			}

			void set(int Value)
			{
				GWC->WindowY = Value;
			}
		}

		void DefaultWindowLocation()
		{
			GWC->DefaultWindowLocation();
		}

		void DefaultWindowX()
		{
			GWC->DefaultWindowX();
		}

		void DefaultWindowY()
		{
			GWC->DefaultWindowY();
		}

		// Window Color.
		property MGColor WindowColor
		{
			MGColor get()
			{
				return GWC->WindowColor;
			}

			void set(MGColor Value)
			{
				GWC->WindowColor = Value;
			}
		}

		void DefaultWindowColor()
		{
			GWC->DefaultWindowColor();
		}

		// Window Image.
		property Image^ WindowImage
		{
			Image^ get()
			{
				return GWC->WindowImage;
			}

			void set(Image^ Value)
			{
				GWC->WindowImage = Value;
			}
		}

		void DefaultWindowImage()
		{
			GWC->DefaultWindowImage();
		}

		// Window Size.
		property MGSize WindowSize
		{
			MGSize get()
			{
				return GWC->WindowSize;
			}

			void set(MGSize Value)
			{
				GWC->WindowSize = Value;
			}
		}

		property int WindowWidth
		{
			int get()
			{
				return GWC->WindowWidth;
			}

			void set(int Value)
			{
				GWC->WindowWidth = Value;
			}
		}

		property int WindowHeight
		{
			int get()
			{
				return GWC->WindowHeight;
			}

			void set(int Value)
			{
				GWC->WindowHeight = Value;
			}
		}

		void DefaultWindowSize()
		{
			GWC->DefaultWindowSize();
		}

		void DefaultWindowWidth()
		{
			GWC->DefaultWindowWidth();
		}

		void DefaultWindowHeight()
		{
			GWC->DefaultWindowHeight();
		}

		// Window Real Size.
		property MGSize WindowRealSize
		{
			MGSize get()
			{
				return GWC->WindowRealSize;
			}

			void set(MGSize Value)
			{
				GWC->WindowRealSize = Value;
			}
		}

		property int WindowRealWidth
		{
			int get()
			{
				return GWC->WindowRealWidth;
			}

			void set(int Value)
			{
				GWC->WindowRealWidth = Value;
			}
		}

		property int WindowRealHeight
		{
			int get()
			{
				return GWC->WindowRealHeight;
			}

			void set(int Value)
			{
				GWC->WindowRealHeight = Value;
			}
		}

		void DefaultWindowRealSize()
		{
			GWC->DefaultWindowRealSize();
		}

		void DefaultWindowRealWidth()
		{
			GWC->DefaultWindowRealWidth();
		}

		void DefaultWindowRealHeight()
		{
			GWC->DefaultWindowRealHeight();
		}

		// Window Size State.
		property MGWindowState WindowSizeState
		{
			MGWindowState get()
			{
				return GWC->WindowSizeState;
			}

			void set(MGWindowState Value)
			{
				GWC->WindowSizeState = Value;
			}
		}

		void DefaultWindowSizeState()
		{
			GWC->DefaultWindowSizeState();
		}

		// Window Minimum Size.
		property MGSize WindowMinimumSize
		{
			MGSize get()
			{
				return GWC->WindowMinimumSize;
			}

			void set(MGSize Value)
			{
				GWC->WindowMinimumSize = Value;
			}
		}

		void DefaultWindowMinimumSize()
		{
			GWC->DefaultWindowMinimumSize();
		}

		// Window Maximum Size.
		property MGSize WindowMaximumSize
		{
			MGSize get()
			{
				return GWC->WindowMaximumSize;
			}

			void set(MGSize Value)
			{
				GWC->WindowMaximumSize = Value;
			}
		}

		void DefaultWindowMaximumSize()
		{
			GWC->DefaultWindowMaximumSize();
		}

		// Window Opacity.
		property double WindowOpacity
		{
			double get()
			{
				return GWC->WindowOpacity;
			}

			void set(Double Value)
			{
				GWC->WindowOpacity = Value;
			}
		}

		void DefaultWindowOpacity()
		{
			GWC->DefaultWindowOpacity();
		}

		// Window Always On Top.
		property bool WindowAlwaysOnTop
		{
			bool get()
			{
				return GWC->WindowAlwaysOnTop;
			}

			void set(bool Value)
			{
				GWC->WindowAlwaysOnTop = Value;
			}
		}

		void DefaultWindowAlwaysOnTop()
		{
			GWC->DefaultWindowAlwaysOnTop();
		}

		// Window In Taskbar.
		property bool WindowInTaskbar
		{
			bool get()
			{
				return GWC->WindowInTaskbar;
			}

			void set(bool Value)
			{
				GWC->WindowInTaskbar = Value;
			}
		}

		void DefaultWindowInTaskbar()
		{
			GWC->DefaultWindowInTaskbar();
		}

		// Window Buttons.
		property bool WindowButtons
		{
			bool get()
			{
				return GWC->WindowButtons;
			}

			void set(bool Value)
			{
				GWC->WindowButtons = Value;
			}
		}

		void DefaultWindowButtons()
		{
			GWC->DefaultWindowButtons();
		}

		// Window Minimize Button.
		property bool WindowMinimizeButton
		{
			bool get()
			{
				return GWC->WindowMinimizeButton;
			}

			void set(bool Value)
			{
				GWC->WindowMinimizeButton = Value;
			}
		}

		void DefaultWindowMinimizeButton()
		{
			GWC->DefaultWindowMinimizeButton();
		}

		// Window Maximize Button.
		property bool WindowMaximizeButton
		{
			bool get()
			{
				return GWC->WindowMaximizeButton;
			}

			void set(bool Value)
			{
				GWC->WindowMaximizeButton = Value;
			}
		}

		void DefaultWindowMaximizeButton()
		{
			GWC->DefaultWindowMaximizeButton();
		}



		/*
			Metodo disegno.
		*/

		// Clear Window.
		void ClearWindow()
		{
			GWC->ClearWindow();
		}

		// Save Canvas.
		void SaveCanvas()
		{
			GWC->SaveCanvas();
		}

		// Restore Canvas.
		void RestoreCanvas()
		{
			GWC->RestoreCanvas();
		}

		// Draw Pixel.
		void DrawPixel(int X, int Y)
		{
			GWC->DrawPixel(X, Y);
		}

		// Draw Line.
		void DrawLine(int X1, int Y1, int X2, int Y2)
		{
			GWC->DrawLine(X1, Y1, X2, Y2);
		}

		// Draw Arc.
		void DrawArc(int X, int Y, int Width, int Height, int A, int B)
		{
			GWC->DrawArc(X, Y, Width, Height, A, B);
		}

		// Draw Bezier.
		void DrawBezier(float X1, float Y1, float X2, float Y2, float X3, float Y3, float X4, float Y4)
		{
			GWC->DrawBezier(X1, Y1, X2, Y2, X3, Y3, X4, Y4);
		}

		// Draw String.
		void DrawString(String^ S, int X, int Y)
		{
			GWC->DrawString(S, X, Y);
		}

		// Draw Image.
		void DrawImage(Image^ Image, int X, int Y)
		{
			GWC->DrawImage(Image, X, Y);
		}

		// Draw Image From File.
		void DrawImageFromFile(String^ FileName, int X, int Y)
		{
			GWC->DrawImageFromFile(FileName, X, Y);
		}

		// Draw Icon.
		void DrawIcon(Icon^ Icon, int X, int Y)
		{
			GWC->DrawIcon(Icon, X, Y);
		}

		// Draw Icon From File.
		void DrawIconFromFile(String^ FileName, int X, int Y)
		{
			GWC->DrawIconFromFile(FileName, X, Y);
		}

		// Draw Square.
		void DrawSquare(int X, int Y, int L)
		{
			GWC->DrawSquare(X, Y, L);
		}

		// Draw Full Square.
		void DrawFullSquare(int X, int Y, int L)
		{
			GWC->DrawFullSquare(X, Y, L);
		}

		// Draw Rectangle.
		void DrawRectangle(int X, int Y, int Width, int Height)
		{
			GWC->DrawRectangle(X, Y, Width, Height);
		}

		// Draw Full Rectangle.
		void DrawFullRectangle(int X, int Y, int Width, int Height)
		{
			GWC->DrawFullRectangle(X, Y, Width, Height);
		}

		// Draw Ellipse.
		void DrawEllipse(int X, int Y, int Width, int Height)
		{
			GWC->DrawEllipse(X, Y, Width, Height);
		}

		// Draw Full Ellipse.
		void DrawFullEllipse(int X, int Y, int Width, int Height)
		{
			GWC->DrawFullEllipse(X, Y, Width, Height);
		}

		// Draw Circle.
		void DrawCircle(int X, int Y, int R)
		{
			GWC->DrawCircle(X, Y, R);
		}

		// Draw Full Circle.
		void DrawFullCircle(int X, int Y, int R)
		{
			GWC->DrawFullCircle(X, Y, R);
		}

		// Draw Curve.
		void DrawCurve(array<MGPoint>^ Points)
		{
			GWC->DrawCurve(Points);
		}

		// Draw Closed Curve.
		void DrawClosedCurve(array<MGPoint>^ Points)
		{
			GWC->DrawClosedCurve(Points);
		}

		// Draw Polygon.
		void DrawPolygon(array<MGPoint>^ Points)
		{
			GWC->DrawPolygon(Points);
		}

		// Draw Full Polygon.
		void DrawFullPolygon(array<MGPoint>^ Points)
		{
			GWC->DrawFullPolygon(Points);
		}

		// Draw Pie.
		void DrawPie(int X, int Y, int Width, int Height, int A, int B)
		{
			GWC->DrawPie(X, Y, Width, Height, A, B);
		}

		// Draw Full Pie.
		void DrawFullPie(int X, int Y, int Width, int Height, int A, int B)
		{
			GWC->DrawFullPie(X, Y, Width, Height, A, B);
		}

		// Draw From Screen.
		void DrawFromScreen(int X1, int Y1, int X2, int Y2, int Width, int Height)
		{
			GWC->DrawFromScreen(X1, Y1, X2, Y2, Width, Height);
		}



		/*
			Proprietà disegno.
		*/

		// Pen Color.
		property MGColor PenColor
		{
			MGColor get()
			{
				return GWC->PenColor;
			}

			void set(MGColor Value)
			{
				GWC->PenColor = Value;
			}
		}

		void DefaultPenColor()
		{
			GWC->DefaultPenColor();
		}

		// Pen Width.
		property float PenWidth
		{
			float get()
			{
				return GWC->PenWidth;
			}

			void set(float Value)
			{
				GWC->PenWidth = Value;
			}
		}

		void DefaultPenWidth()
		{
			GWC->DefaultPenWidth();
		}

		// Fill Color.
		property MGColor FillColor
		{
			MGColor get()
			{
				return GWC->FillColor;
			}

			void set(MGColor Value)
			{
				GWC->FillColor = Value;
			}
		}

		void DefaultFillColor()
		{
			GWC->DefaultFillColor();
		}

		// Font Name.
		property String^ FontName
		{
			String^ get()
			{
				return GWC->FontName;
			}

			void set(String^ Value)
			{
				GWC->FontName = Value;
			}
		}

		void DefaultFontName()
		{
			GWC->DefaultFontName();
		}

		// Font Size.
		property float FontSize
		{
			float get()
			{
				return GWC->FontSize;
			}

			void set(float Value)
			{
				GWC->FontSize = Value;
			}
		}

		void DefaultFontSize()
		{
			GWC->DefaultFontSize();
		}

	};
}
