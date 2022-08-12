/*
	GWC++ (Graphic Window for Console Application)

	- Questo progetto è sotto lincenza MIT (https://mit-license.org)
	- Questo progetto è disponibile su GitHub (https://github.com/reallukee/GWCpp)
	- Maggiori informazioni sono diponibili nel file README.md


	ATUORE:			Realluke | Aka Luca Pollicino
	DESCRIZIONE:	Classe GWC (Formalmente GWC 3.0) Nucleo di GWC++.
	DATA:			24/04/22
	VERSIONE:		1.1.1
*/

#pragma once
#pragma managed

using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Collections::Generic;
using namespace System::Data;
using namespace System::Drawing;
using namespace System::Drawing::Drawing2D;
using namespace System::Threading;
using namespace System::Runtime::InteropServices;
using namespace System::Windows::Forms;
using namespace Microsoft::VisualBasic;

#include "mcomp.h"
using namespace GWCpp;

namespace GWCpp
{
	ref class GWC : public Form
	{

		/*
			### Costruttori
			Costruttori
		*/

		#pragma region Costruttori

	public:

		GWC() : Form()
		{
			try
			{
				InitializeComponent(850, 505, "GWC++ Window", 50, 50);
				GWCThread = gcnew Thread(gcnew ThreadStart(this, &GWC::InitializeWindow));
				GWCThread->SetApartmentState(ApartmentState::STA);
			}
			catch (Exception^ Ex)
			{
				Interaction::MsgBox(Ex->Message, MsgBoxStyle::OkOnly | MsgBoxStyle::Critical, "GWC++");
				throw Ex;
			}
		}

		GWC(int Width, int Height) : Form()
		{
			try
			{
				InitializeComponent(Width, Height, "GWC++ Window", 50, 50);
				GWCThread = gcnew Thread(gcnew ThreadStart(this, &GWC::InitializeWindow));
				GWCThread->SetApartmentState(ApartmentState::STA);
			}
			catch (Exception^ Ex)
			{
				Interaction::MsgBox(Ex->Message, MsgBoxStyle::OkOnly | MsgBoxStyle::Critical, "GWC++");
				throw Ex;
			}
		}

		GWC(int Width, int Height, String^ Title) : Form()
		{
			try
			{
				InitializeComponent(Width, Height, Title, 50, 50);
				GWCThread = gcnew Thread(gcnew ThreadStart(this, &GWC::InitializeWindow));
				GWCThread->SetApartmentState(ApartmentState::STA);
			}
			catch (Exception^ Ex)
			{
				Interaction::MsgBox(Ex->Message, MsgBoxStyle::OkOnly | MsgBoxStyle::Critical, "GWC++");
				throw Ex;
			}
		}

		GWC(int Width, int Height, String^ Title, int X, int Y) : Form()
		{
			try
			{
				InitializeComponent(Width, Height, Title, X, Y);
				GWCThread = gcnew Thread(gcnew ThreadStart(this, &GWC::InitializeWindow));
				GWCThread->SetApartmentState(ApartmentState::STA);
			}
			catch (Exception^ Ex)
			{
				Interaction::MsgBox(Ex->Message, MsgBoxStyle::OkOnly | MsgBoxStyle::Critical, "GWC++");
				throw Ex;
			}
		}

		#pragma endregion



		/*
			### Inizializzatori
			Inizializzatori
		*/

		#pragma region Inizializzatori

	private:

		Thread^ GWCThread;

		void InitializeComponent(int Width, int Height, String^ Title, int X, int Y)
		{
			Resources::ResourceManager^ RM = gcnew Resources::ResourceManager(L"GWCpp.gwc++", this->GetType()->Assembly);
			System::Drawing::Icon^ AppIcon = safe_cast<System::Drawing::Icon^>(RM->GetObject("Icon"));
			System::ComponentModel::Container^ Components = gcnew System::ComponentModel::Container();
			
			this->WindowStarted = false;												// WindowStarted
			this->WindowClosed = true;													// WindowClosed
			this->WindowSuspended = false;												// WindowSuspended
			this->WindowVisible = false;												// WindowVisible
			this->ResizeRedraw = false;													// ResizeRedraw
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;			// AutoScaleMode

			this->Text = Title;											// WindowTitle
			this->Icon = AppIcon;										// WindowIcon
			this->ShowIcon = true;										// WindowIconVisible
			this->Location = System::Drawing::Point(X, Y);				// WindowLocation
			this->BackColor = Color::FromArgb(240, 240, 240);			// WindowColor
			this->BackgroundImage = nullptr;							// WindowImage
			this->Size = System::Drawing::Size(Width, Height);			// WindowSize
			this->ClientSize = this->ClientSize;						// WindowRealSize
			this->WindowState = FormWindowState::Normal;				// WindowSizeState
			this->MinimumSize = System::Drawing::Size(0, 0);			// WindowMinimumSize
			this->MaximumSize = System::Drawing::Size(0, 0);			// WindowMaximumSize
			this->Opacity = 1.00;										// WindowOpacity
			this->TopMost = false;										// WindowAlwaysOnTop
			this->ShowInTaskbar = false;								// WindowInTaskBar
			this->ControlBox = true;									// WindowButtons
			this->MinimizeBox = true;									// WindowMinimizeButton
			this->MaximizeBox = true;									// WindowMaximizeButton
			this->DefaultPenColor();									// PenColor
			this->DefaultPenWidth();									// PenWidth
			this->DefaultFillColor();									// FillColor
			this->DefaultHStringAlignment();							// HStringAlignment
			this->DefaultVStringAlignment();							// VStringAlignment
			this->DefaultFontName();									// FontName
			this->DefaultFontSize();									// FontSize

			this->Paint += gcnew PaintEventHandler(this, &GWC::GWC_Paint);				// Evento 'Paint'
			this->MouseDown += gcnew MouseEventHandler(this, &GWC::GWC_MouseDown);		// Evento 'MouseDown'
			this->MouseUp += gcnew MouseEventHandler(this, &GWC::GWC_MouseUp);			// Evento 'MouseUp'
			this->MouseMove += gcnew MouseEventHandler(this, &GWC::GWC_MouseMove);		// Evento 'MouseMove'
			this->KeyDown += gcnew KeyEventHandler(this, &GWC::GWC_KeyDown);			// Evento 'KeyDown'
			this->KeyUp += gcnew KeyEventHandler(this, &GWC::GWC_KeyUp);				// Evento 'KeyUp'
			
			delete RM;
		}

		void InitializeWindow()
		{
			Application::EnableVisualStyles();
			Application::SetCompatibleTextRenderingDefault(false);
			Application::Run(this);
		}

		#pragma endregion



		/*
			### Metodi Conversione
			Metodi di conversione
		*/

		#pragma region Metodi Conversione

	public:

		// MPoint <=> Point
		
		MPoint PointToMPoint(Point Value)
		{
			return MPoint(Value.X, Value.Y);
		}

		Point MPointToPoint(MPoint Value)
		{
			return Point(Value.X, Value.Y);
		}



		// MColor <=> Color

		MColor ColorToMColor(Color Value)
		{
			return MColor(Value.R, Value.G, Value.B);
		}

		Color MColorToColor(MColor Value)
		{
			return Color::FromArgb(Value.R, Value.G, Value.B);
		}



		// MSize <=> Size

		MSize SizeToMSize(System::Drawing::Size Value)
		{
			return MSize(Value.Width, Value.Height);
		}

		System::Drawing::Size MSizeToSize(MSize Value)
		{
			return System::Drawing::Size(Value.Width, Value.Height);
		}

		#pragma endregion



		/*
			### Metodi Evento
			Metodi di evento
		*/

		#pragma region Metodi Evento

	private:

		Bitmap^ Canvas;

	protected:

		void OnShown(EventArgs^ E) override
		{
			WindowStarted = true;
			WindowClosed = false;
			Form::OnShown(E);
		}

		void OnFormClosing(FormClosingEventArgs^ E) override
		{
			WindowStarted = false;
			WindowClosed = true;
			Form::OnFormClosing(E);
		}

	private:

		bool Drawing = false;

		void GWC_Paint(Object^ Sender, PaintEventArgs^ E)
		{
			Drawing = true;

			if (Canvas != nullptr)
			{
				Graphics^ G = E->Graphics;
				int X = E->ClipRectangle.X;
				int Y = E->ClipRectangle.Y;
				int Width = E->ClipRectangle.Width;
				int Height = E->ClipRectangle.Height;
				System::Drawing::Rectangle R = System::Drawing::Rectangle(X, Y, Width, Height);
				Bitmap^ B = Canvas->Clone(R, Canvas->PixelFormat);
				G->DrawImage(B, X, Y);
				delete B;
				delete G;
			}

			Drawing = false;
		}

		bool IsDrawing()
		{
			return Drawing;
		}

		#pragma endregion



		/*
			### Metodi Interattivi
			Metodi di interazione I/O
		*/

		#pragma region Metodi Interattivi

	public:

		String^ InputBox(String^ Prompt, String^ Title, String^ DefaultResponse, int X, int Y)
		{
			return Interaction::InputBox(Prompt, Title, DefaultResponse, X, Y);
		}

		MOutputBoxResult OutputBox(String^ Prompt, MOutputBoxStyle Style, String^ Title)
		{
			return (MOutputBoxResult)Interaction::MsgBox(Prompt, (MsgBoxStyle)Style, Title);
		}

		#pragma endregion



		/*
			### Metodi Finestra
			Metodi della finestra
		*/

		#pragma region Metodi Finestra

	public:

		/*
			### Start Window
		*/

		bool StartWindow()
		{
			if (WindowStarted == false && WindowClosed)
			{
				try
				{
					GWCThread->Start();
					GWCThread->Sleep(50);
					WindowStarted = true;

					if (Canvas == nullptr)
					{
						int Width = Screen::PrimaryScreen->Bounds.Width;
						int Height = Screen::PrimaryScreen->Bounds.Height;
						Canvas = gcnew Bitmap(Width, Height);
					}
				}
				catch (Exception^ Ex)
				{
					Interaction::MsgBox(Ex->Message, MsgBoxStyle::OkOnly | MsgBoxStyle::Critical, "GWC++");
					throw Ex;
					return false;
				}

				return true;
			}

			return false;
		}



		/*
			### Close Window
		*/

		bool CloseWindow()
		{
			if (WindowStarted && WindowClosed == false)
			{
				try
				{
					GWCThread->Sleep(50);
					GWCThread->Abort();
					WindowClosed = true;

					if (Canvas != nullptr)
					{
						delete Canvas;
					}
				}
				catch (Exception^ Ex)
				{
					Interaction::MsgBox(Ex->Message, MsgBoxStyle::OkOnly | MsgBoxStyle::Critical, "GWC++");
					throw Ex;
					return false;
				}

				return true;
			}

			return false;
		}



		/*
			### Suspend Window
		*/

		bool SuspendWindow()
		{
			if (WindowStarted && WindowClosed == false && WindowSuspended == false)
			{
				try
				{
					GWCThread->Suspend();
					WindowSuspended = true;
				}
				catch (Exception^ Ex)
				{
					Interaction::MsgBox(Ex->Message, MsgBoxStyle::OkOnly | MsgBoxStyle::Critical, "GWC++");
					throw Ex;
					return false;				
				}

				return true;
			}

			return false;
		}



		/*
			### Resume Window
		*/

		bool ResumeWindow()
		{
			if (WindowStarted && WindowClosed == false && WindowSuspended)
			{
				try
				{
					GWCThread->Resume();
					WindowSuspended = false;
				}
				catch (Exception^ Ex)
				{
					Interaction::MsgBox(Ex->Message, MsgBoxStyle::OkOnly | MsgBoxStyle::Critical, "GWC++");
					throw Ex;
					return false;				
				}

				return true;
			}

			return false;
		}



		/*
			### Pause Window
		*/

		bool PauseWindow(int Time)
		{
			if (WindowStarted && WindowClosed == false && WindowSuspended == false)
			{
				try
				{
					GWCThread->Sleep(Time);
				}
				catch (Exception^ Ex)
				{
					Interaction::MsgBox(Ex->Message, MsgBoxStyle::OkOnly | MsgBoxStyle::Critical, "GWC++");
					throw Ex;
					return false;				
				}

				return true;
			}
			
			return false;
		}



		/*
			### Redraw
		*/

	private:

		delegate void RedrawDel(System::Drawing::Rectangle R);

		void RedrawExc(System::Drawing::Rectangle R)
		{
			Invalidate(R);
		}

	public:

		bool RedrawWindow(int X, int Y, int Width, int Height)
		{
			while (IsDrawing());
			
			if (WindowStarted && WindowClosed == false)
			{
				try
				{
					RedrawDel^ D = gcnew RedrawDel(this, &GWC::RedrawExc);
					this->Invoke(D, System::Drawing::Rectangle(X, Y, Width, Height));
					delete D;
				}
				catch (Exception^ Ex)
				{
					Interaction::MsgBox(Ex->Message, MsgBoxStyle::OkOnly | MsgBoxStyle::Critical, "GWC++");
					throw Ex;
					return false;
				}

				return true;
			}

			return false;
		}

		bool RedrawWindow()
		{
			while (IsDrawing());
			
			if (WindowStarted && WindowClosed == false)
			{
				try
				{
					RedrawDel^ D = gcnew RedrawDel(this, &GWC::RedrawExc);
					this->Invoke(D, System::Drawing::Rectangle(0, 0, GetWindowMaxX() + 1, GetWindowMaxY() + 1));
					delete D;
				}
				catch (Exception^ Ex)
				{
					Interaction::MsgBox(Ex->Message, MsgBoxStyle::OkOnly | MsgBoxStyle::Critical, "GWC++");
					throw Ex;
					return false;
				}

				return true;
			}

			return false;
		}



		/*
			### Show Window
		*/

	private:

		delegate void ShowWindowDel();

		void ShowWindowExc()
		{
			Form::Show();
		}

	public:

		bool ShowWindow()
		{
			if (WindowStarted && WindowClosed == false)
			{
				try
				{
					ShowWindowDel^ D = gcnew ShowWindowDel(this, &GWC::ShowWindowExc);
					this->Invoke(D);
					WindowVisible = true;
					delete D;
				}
				catch (Exception^ Ex)
				{
					Interaction::MsgBox(Ex->Message, MsgBoxStyle::OkOnly | MsgBoxStyle::Critical, "GWC++");
					throw Ex;
					return false;
				}

				return true;
			}

			return false;
		}



		/*
			### Hide Window
		*/

	private:

		delegate void HideWindowDel();

		void HideWindowExc()
		{
			Form::Hide();
		}

	public:

		bool HideWindow()
		{
			if (WindowStarted && WindowClosed == false)
			{
				try
				{
					HideWindowDel^ D = gcnew HideWindowDel(this, &GWC::HideWindowExc);
					this->Invoke(D);
					WindowVisible = false;
					delete D;
				}
				catch (Exception^ Ex)
				{
					Interaction::MsgBox(Ex->Message, MsgBoxStyle::OkOnly | MsgBoxStyle::Critical, "GWC++");
					throw Ex;
					return false;
				}

				return true;
			}

			return false;
		}



		/*
			### Get Window (Real) Max [X | Y]
		*/

		int GetWindowMaxX()
		{
			if (WindowStarted && WindowClosed == false)
			{
				try
				{
					return Form::Size.Width - 1;
				}
				catch (Exception^ Ex)
				{
					Interaction::MsgBox(Ex->Message, MsgBoxStyle::OkOnly | MsgBoxStyle::Critical, "GWC++");
					throw Ex;
					return false;
				}
			}

			return -1;
		}

		int GetWindowMaxY()
		{
			if (WindowStarted && WindowClosed == false)
			{
				try
				{
					return Form::Size.Height - 1;
				}
				catch (Exception^ Ex)
				{
					Interaction::MsgBox(Ex->Message, MsgBoxStyle::OkOnly | MsgBoxStyle::Critical, "GWC++");
					throw Ex;
					return false;
				}
			}

			return -1;
		}

		int GetWindowRealMaxX()
		{
			if (WindowStarted && WindowClosed == false)
			{
				try
				{
					return Form::ClientSize.Width - 1;
				}
				catch (Exception^ Ex)
				{
					Interaction::MsgBox(Ex->Message, MsgBoxStyle::OkOnly | MsgBoxStyle::Critical, "GWC++");
					throw Ex;
					return false;
				}
			}

			return -1;
		}

		int GetWindowRealMaxY()
		{
			if (WindowStarted && WindowClosed == false)
			{
				try
				{
					return Form::ClientSize.Height - 1;
				}
				catch (Exception^ Ex)
				{
					Interaction::MsgBox(Ex->Message, MsgBoxStyle::OkOnly | MsgBoxStyle::Critical, "GWC++");
					throw Ex;
					return false;
				}
			}

			return -1;
		}



		/*
			### Get Screen (Real) Max [X | Y]
		*/

		int GetScreenMaxX()
		{
			if (WindowStarted && WindowClosed == false)
			{
				try
				{
					return Screen::PrimaryScreen->Bounds.Width;
				}
				catch (Exception^ Ex)
				{
					Interaction::MsgBox(Ex->Message, MsgBoxStyle::OkOnly | MsgBoxStyle::Critical, "GWC++");
					throw Ex;
					return false;
				}
			}

			return -1;
		}

		int GetScreenMaxY()
		{
			if (WindowStarted && WindowClosed == false)
			{
				try
				{
					return Screen::PrimaryScreen->Bounds.Height;
				}
				catch (Exception^ Ex)
				{
					Interaction::MsgBox(Ex->Message, MsgBoxStyle::OkOnly | MsgBoxStyle::Critical, "GWC++");
					throw Ex;
					return false;
				}
			}

			return -1;
		}

		int GetScreenRealMaxX()
		{
			if (WindowStarted && WindowClosed == false)
			{
				try
				{
					return Screen::PrimaryScreen->WorkingArea.Width;
				}
				catch (Exception^ Ex)
				{
					Interaction::MsgBox(Ex->Message, MsgBoxStyle::OkOnly | MsgBoxStyle::Critical, "GWC++");
					throw Ex;
					return false;
				}
			}

			return -1;
		}

		int GetScreenRealMaxY()
		{
			if (WindowStarted && WindowClosed == false)
			{
				try
				{
					return Screen::PrimaryScreen->WorkingArea.Height;
				}
				catch (Exception^ Ex)
				{
					Interaction::MsgBox(Ex->Message, MsgBoxStyle::OkOnly | MsgBoxStyle::Critical, "GWC++");
					throw Ex;
					return false;
				}
			}

			return -1;
		}



		/*
			### Mouse Down
		*/

	private:

		bool MouseDownPending;
		MPoint MouseDownPoint;
		MMouseButtons MouseDownButton;

		void GWC_MouseDown(Object^ Sender, MouseEventArgs^ E)
		{
			if (MouseDownPending == false)
			{
				return;
			}

			switch (E->Button)
			{
			case System::Windows::Forms::MouseButtons::Left:
				MouseDownPoint = MPoint(E->X, E->Y);
				MouseDownPending = false;
				break;

			case System::Windows::Forms::MouseButtons::Right:
				MouseDownPoint = MPoint(E->X, E->Y);
				MouseDownPending = false;
				break;

			case System::Windows::Forms::MouseButtons::Middle:
				MouseDownPoint = MPoint(E->X, E->Y);
				MouseDownPending = false;
				break;

			case System::Windows::Forms::MouseButtons::None:
				MouseDownPoint = MPoint(E->X, E->Y);
				MouseDownPending = false;
				break;

			default:
				break;
			}
		}

	public:

		MPoint RequestMouseDown(MMouseButtons B)
		{
			if (WindowStarted && WindowClosed == false)
			{
				MouseDownPending = true;
				MouseDownButton = B;

				while (MouseDownPending)
				{
					GWCThread->Sleep(10);
				}

				return MouseDownPoint;
			}

			return MPoint(0, 0);
		}

		MPoint RequestMouseDown()
		{
			if (WindowStarted && WindowClosed == false)
			{
				MouseDownPending = true;
				MouseDownButton = MMouseButtons::None;
				
				while (MouseDownPending)
				{
					GWCThread->Sleep(10);
				}
				
				return MouseDownPoint;
			}

			return MPoint(0, 0);
		}



		/*
			### Mouse Up
		*/

	private:

		bool MouseUpPending;
		MPoint MouseUpPoint;
		MMouseButtons MouseUpButton;

		void GWC_MouseUp(Object^ Sender, MouseEventArgs^ E)
		{
			if (MouseUpPending == false)
			{
				return;
			}

			switch (E->Button)
			{
			case System::Windows::Forms::MouseButtons::Left:
				MouseUpPoint = MPoint(E->X, E->Y);
				MouseUpPending = false;
				break;

			case System::Windows::Forms::MouseButtons::Right:
				MouseUpPoint = MPoint(E->X, E->Y);
				MouseUpPending = false;
				break;

			case System::Windows::Forms::MouseButtons::Middle:
				MouseUpPoint = MPoint(E->X, E->Y);
				MouseUpPending = false;
				break;

			case System::Windows::Forms::MouseButtons::None:
				MouseUpPoint = MPoint(E->X, E->Y);
				MouseUpPending = false;
				break;

			default:
				break;
			}
		}

	public:

		MPoint RequestMouseUp(MMouseButtons B)
		{
			if (WindowStarted && WindowClosed == false)
			{
				MouseUpPending = true;
				MouseUpButton = B;

				while (MouseUpPending)
				{
					GWCThread->Sleep(10);
				}

				return MouseUpPoint;
			}

			return MPoint(0, 0);
		}

		MPoint RequestMouseUp()
		{
			if (WindowStarted && WindowClosed == false)
			{
				MouseUpPending = true;
				MouseUpButton = MMouseButtons::None;

				while (MouseUpPending)
				{
					GWCThread->Sleep(10);
				}

				return MouseUpPoint;
			}

			return MPoint(0, 0);
		}



		/*
			### Key Down
		*/

	private:

		bool KeyDownPending;
		int KeyDownChar;

		void GWC_KeyDown(Object^ Sender, KeyEventArgs^ E)
		{
			if (E != nullptr && KeyDownPending)
			{
				try
				{
					KeyDownChar = Convert::ToInt32(E->KeyCode);
					KeyDownPending = false;
				}
				catch (Exception^ Ex)
				{
					Interaction::MsgBox(Ex->Message, MsgBoxStyle::OkOnly | MsgBoxStyle::Critical, "GWC++");
					throw Ex;
				}
			}
		}

	public:

		Char RequestKeyDown(Char C)
		{
			if (WindowStarted && WindowClosed == false)
			{
				Char R;

				do
				{
					R = RequestKeyDown();
				} while (R != C);

				return R;
			}

			return (char)0;
		}

		Char RequestKeyDown()
		{
			if (WindowStarted && WindowClosed == false)
			{
				KeyDownPending = true;

				while (KeyDownPending) 
				{
					GWCThread->Sleep(10);
				}

				return (Char)KeyDownChar;
			}

			return (char)0;
		}



		/*
			### Key Up
		*/

	private:

		bool KeyUpPending;
		int KeyUpChar;

		void GWC_KeyUp(Object^ Sender, KeyEventArgs^ E)
		{
			if (E != nullptr && KeyUpPending)
			{
				try
				{
					KeyUpChar = Convert::ToInt32(E->KeyCode);
					KeyUpPending = false;
				}
				catch (Exception^ Ex)
				{
					Interaction::MsgBox(Ex->Message, MsgBoxStyle::OkOnly | MsgBoxStyle::Critical, "GWC++");
					throw Ex;
				}
			}
		}

	public:

		Char RequestKeyUp(Char C)
		{
			if (WindowStarted && WindowClosed == false)
			{
				Char R;

				do
				{
					R = RequestKeyUp();
				} while (R != C);

				return R;
			}

			return (char)0;
		}

		Char RequestKeyUp()
		{
			if (WindowStarted && WindowClosed == false)
			{
				KeyUpPending = true;
				
				while (KeyUpPending)
				{
					GWCThread->Sleep(10);
				}
				
				return (Char)KeyUpChar;
			}

			return (char)0;
		}

		#pragma endregion



		/*
			### Proprietà Finestra
			Proprietà della finestra
		*/

		#pragma region Proprietà Finestra

		/*
			### Window Started
		*/

	private:

		bool WindowStarted_;

	public:

		property bool WindowStarted
		{
			bool get()
			{
				return WindowStarted_;
			}

		private: void set(bool Value)
		{
			WindowStarted_ = Value;
		}
		}



		/*
			### Window Closed
		*/

	private:

		bool WindowClosed_;

	public:

		property bool WindowClosed
		{
			bool get()
			{
				return WindowClosed_;
			}

		private: void set(bool Value)
		{
			WindowClosed_ = Value;
		}
		}



		/*
			### Window Suspended
		*/

	private:

		bool WindowSuspended_;

	public:

		property bool WindowSuspended
		{
			bool get()
			{
				return WindowSuspended_;
			}
			
		private: void set(bool Value)
		{
			WindowSuspended_ = Value;
		}
		}



		/*
			### Window Visible
		*/

	private:

		bool WindowVisible_;

	public:

		property bool WindowVisible
		{
			bool get()
			{
				return WindowVisible_;
			}

		private: void set(bool Value)
		{
			WindowVisible_ = Value;
		}
		}



		/*
			### Mouse Location
		*/

	private:

		MPoint MouseLocation_;

		void GWC_MouseMove(Object^ Sender, MouseEventArgs^ E)
		{
			MouseLocation_ = MPoint(E->X, E->Y);
		}

	public:

		property MPoint MouseLocation
		{
			MPoint get()
			{
				if (WindowStarted && WindowClosed == false)
				{
					return MouseLocation_;
				}

				return MPoint(0, 0);
			}

			void set(MPoint Value)
			{
				if (WindowStarted && WindowClosed == false)
				{
					Form::Cursor->Position = MPointToPoint(MouseLocation);
					MouseLocation_ = Value;
				}
			}
		}

		property int MouseX
		{
			int get()
			{
				if (WindowStarted && WindowClosed == false)
				{
					return MouseLocation.X;
				}

				return -1;
			}

			void set(int Value)
			{
				if (WindowStarted && WindowClosed == false)
				{
					MouseLocation = MPoint(Value, MouseLocation.Y);
					Form::Cursor->Position = MPointToPoint(MouseLocation);
				}
			}
		}

		property int MouseY
		{
			int get()
			{
				if (WindowStarted && WindowClosed == false)
				{
					return MouseLocation.Y;
				}

				return -1;
			}

			void set(int Value)
			{
				if (WindowStarted && WindowClosed == false)
				{
					MouseLocation = MPoint(MouseLocation.X, Value);
					Form::Cursor->Position = MPointToPoint(MouseLocation);
				}
			}
		}

		

		/*
			### Window Title
		*/

	private:

		delegate void WindowTitleDel(String^ Value);

		void WindowTitleExc(String^ Value)
		{
			this->Text = Value;
		}

		String^ WindowTitle_;

	public:

		virtual property String^ Text
		{
			String^ get() override
			{
				return Form::Text;
			}

			void set(String^ Value) override
			{
				this->WindowTitle_ = Value;
				Form::Text = Value;
			}
		}

		property String^ WindowTitle
		{
			String^ get()
			{
				return WindowTitle_;
			}

			void set(String^ Value)
			{
				if (WindowStarted && WindowClosed == false)
				{
					WindowTitleDel^ D = gcnew WindowTitleDel(this, &GWC::WindowTitleExc);
					this->Invoke(D, Value);
					this->WindowTitle_ = Value;
					delete D;
				}
			}
		}

		void DefaultWindowTitle()
		{
			WindowTitle = "GWC++ Window";
		}



		/*
			### Window Icon
		*/

	private:

		delegate void WindowIconDel(System::Drawing::Icon^ Value);

		void WindowIconExc(System::Drawing::Icon^ Value)
		{
			Form::Icon = Value;
		}

		System::Drawing::Icon^ WindowIcon_;

	public:

		property System::Drawing::Icon^ Icon
		{
			virtual System::Drawing::Icon^ get() sealed
			{
				return Form::Icon;
			}

			virtual void set(System::Drawing::Icon^ Value) sealed
			{
				this->WindowIcon_ = Value;
				Form::Icon = Value;
			}
		}

		property System::Drawing::Icon^ WindowIcon
		{
			System::Drawing::Icon^ get()
			{
				return WindowIcon_;
			}

			void set(System::Drawing::Icon^ Value)
			{
				if (WindowStarted && WindowClosed == false)
				{
					WindowIconDel^ D = gcnew WindowIconDel(this, &GWC::WindowIconExc);
					this->Invoke(D, Value);
					this->WindowIcon_ = Value;
					delete D;
				}
			}
		}

		void DefaultWindowIcon()
		{
			WindowIcon = nullptr;
		}



		/*
			### Window Icon Visible
		*/

	private:

		delegate void WindowIconVisibleDel(bool Value);

		void WindowIconVisibleExc(bool Value)
		{
			Form::ShowIcon = Value;
		}

		bool WindowIconVisible_;

	public:

		property bool ShowIcon
		{
			virtual bool get()
			{
				return Form::ShowIcon;
			}

			virtual void set(bool Value)
			{
				this->WindowIconVisible_ = Value;
				Form::ShowIcon = Value;
			}
		}

		property bool WindowIconVisible
		{
			bool get()
			{
				return WindowIconVisible_;
			}

			void set(bool Value)
			{
				if (WindowStarted && WindowClosed == false)
				{
					WindowIconVisibleDel^ D = gcnew WindowIconVisibleDel(this, &GWC::WindowIconVisibleExc);
					this->Invoke(D, Value);
					this->WindowIconVisible_ = Value;
					delete D;
				}
			}
		}

		void DefaultWindowIconVisible()
		{
			WindowIconVisible = true;
		}



		/*
			### Window Location
		*/

	private:

		delegate void WindowLocationDel(Point Value);

		void WindowLocationExc(Point Value)
		{
			Form::Location = Value;
		}

		MPoint WindowLocation_;

	public:

		property Point Location
		{
			virtual Point get() sealed
			{
				return Form::Location;
			}

			virtual void set(Point Value) sealed
			{
				this->WindowLocation_ = PointToMPoint(Value);
				Form::Location = Value;
			}
		}

		property MPoint WindowLocation
		{
			MPoint get()
			{
				return WindowLocation_;
			}

			void set(MPoint Value)
			{
				if (WindowStarted && WindowClosed == false)
				{
					WindowLocationDel^ D = gcnew WindowLocationDel(this, &GWC::WindowLocationExc);
					this->Invoke(D, MPointToPoint(Value));
					this->WindowLocation_ = Value;
					delete D;
				}
			}
		}

		property int WindowX
		{
			int get()
			{
				return WindowLocation.X;
			}

			void set(int Value)
			{
				WindowLocation = MPoint(Value, WindowLocation.Y);
			}
		}

		property int WindowY
		{
			int get()
			{
				return WindowLocation.Y;
			}

			void set(int Value)
			{
				WindowLocation = MPoint(WindowLocation.X, Value);
			}
		}

		void DefaultWindowLocation()
		{
			WindowLocation = MPoint(0, 0);
		}

		void DefaultWindowX() 
		{
			WindowX = 0;
		}

		void DefaultWindowY()
		{
			WindowY = 0;
		}



		/*
			### Window Color
		*/

	private:

		delegate void WindowColorDel(Color Value);

		void WindowColorExc(Color Value)
		{
			this->BackColor = Value;
		}

		MColor WindowColor_;

	public:

		virtual property Color BackColor
		{
			Color get() override { return Form::BackColor; }

			void set(Color Value) override
			{
				this->WindowColor_ = ColorToMColor(Value);
				Form::BackColor = Value;
			}
		}

		property MColor WindowColor
		{
			MColor get()
			{
				return WindowColor_;
			}

			void set(MColor Value)
			{
				if (WindowStarted && WindowClosed == false)
				{
					WindowColorDel^ D = gcnew WindowColorDel(this, &GWC::WindowColorExc);
					this->Invoke(D, MColorToColor(Value));
					this->WindowColor_ = Value;
					delete D;
				}
			}
		}

		void DefaultWindowColor() 
		{
			WindowColor = MColor(240, 240, 240);
		}



		/*
			### Window Image
		*/

	private:

		delegate void WindowImageDel(Image^ Value);

		void WindowImageExc(Image^ Value)
		{
			Form::BackgroundImage = Value;
		}

		Image^ WindowImage_;

	public:

		virtual property Image^ BackgroundImage
		{
			Image^ get() override 
			{
				return Form::BackgroundImage;
			}

			void set(Image^ Value) override
			{
				this->WindowImage_ = Value;
				Form::BackgroundImage = Value;
			}
		}

		property Image^ WindowImage
		{
			Image^ get()
			{
				return WindowImage_;
			}

			void set(Image^ Value)
			{
				if (WindowStarted && WindowClosed == false)
				{
					WindowImageDel^ D = gcnew WindowImageDel(this, &GWC::WindowImageExc);
					this->Invoke(D, Value);
					this->WindowImage_ = Value;
					delete D;
				}
			}
		}

		void DefaultWindowImage()
		{
			WindowImage = nullptr;
		}



		/*
			### Window Size
		*/

	private:

		delegate void WindowSizeDel(System::Drawing::Size Value);

		void WindowSizeExc(System::Drawing::Size Value)
		{
			Form::Size = Value;
		}

		MSize WindowSize_;

	public:

		property System::Drawing::Size Size
		{
			virtual System::Drawing::Size get() sealed
			{
				return Form::Size;
			}

			virtual void set(System::Drawing::Size Value) sealed
			{
				this->WindowSize_ = SizeToMSize(Value);
				Form::Size = Value;
			}
		}

		property MSize WindowSize
		{
			MSize get()
			{
				return WindowSize_;
			}

			void set(MSize Value)
			{
				if (WindowStarted && WindowClosed == false)
				{
					WindowSizeDel^ D = gcnew WindowSizeDel(this, &GWC::WindowSizeExc);
					this->Invoke(D, MSizeToSize(Value));
					this->WindowSize_ = Value;
					delete D;
				}
			}
		}

		property int WindowWidth
		{
			int get()
			{
				return WindowSize.Width;
			}

			void set(int Value)
			{
				WindowSize = MSize(Value, WindowSize.Height);
			}
		}

		property int WindowHeight
		{
			int get()
			{
				return WindowSize.Height;
			}

			void set(int Value)
			{
				WindowSize = MSize(WindowSize.Width, Value);
			}
		}

		void DefaultWindowSize()
		{
			WindowSize = MSize(850, 505);
		}

		void DefaultWindowWidth()
		{
			WindowWidth = 850;
		}

		void DefaultWindowHeight()
		{
			WindowHeight = 505;
		}



		/*
			### Window Real Size
		*/

	private:

		delegate void WindowRealSizeDel(System::Drawing::Size Value);

		void WindowRealSizeExc(System::Drawing::Size Value)
		{
			Form::ClientSize = Value;
		}

		MSize WindowRealSize_;

	public:

		property System::Drawing::Size ClientSize
		{
			virtual System::Drawing::Size get() sealed
			{
				return Form::ClientSize;
			}

			virtual void set(System::Drawing::Size Value) sealed
			{
				this->WindowRealSize_ = SizeToMSize(Value);
				Form::ClientSize = Value;
			}
		}

		property MSize WindowRealSize
		{
			MSize get()
			{
				return WindowRealSize_;
			}

			void set(MSize Value)
			{
				if (WindowStarted && WindowClosed == false)
				{
					WindowRealSizeDel^ D = gcnew WindowRealSizeDel(this, &GWC::WindowRealSizeExc);
					this->Invoke(D, MSizeToSize(Value));
					this->WindowRealSize_ = Value;
					delete D;
				}
			}
		}

		property int WindowRealWidth
		{
			int get()
			{
				return WindowRealSize.Width;
			}

			void set(int Value)
			{
				WindowRealSize = MSize(Value, WindowRealSize.Height);
			}
		}

		property int WindowRealHeight
		{
			int get()
			{
				return WindowRealSize.Height;
			}

			void set(int Value)
			{
				WindowRealSize = MSize(WindowRealSize.Width, Value);
			}
		}

		void DefaultWindowRealSize()
		{
			WindowRealSize = MSize(850, 505);
		}

		void DefaultWindowRealWidth()
		{
			WindowRealWidth = 850;
		}

		void DefaultWindowRealHeight()
		{
			WindowRealHeight = 505;
		}



		/*
			### Window Size State
		*/

	private:

		delegate void WindowSizeStateDel(FormWindowState Value);

		void WindowSizeStateExc(FormWindowState Value)
		{
			Form::WindowState = Value;
		}

		MWindowState WindowSizeState_;

	public:

		property FormWindowState WindowState
		{
			virtual FormWindowState get() sealed
			{
				return FormWindowState::Normal;
			};

			virtual void set(FormWindowState Value) sealed
			{
				this->WindowSizeState_ = (MWindowState)Value;
				Form::WindowState = Value;
			}
		}

		property MWindowState WindowSizeState
		{
			MWindowState get()
			{
				return WindowSizeState_;
			}

			void set(MWindowState Value)
			{
				if (WindowStarted && WindowClosed == false)
				{
					WindowSizeStateDel^ D = gcnew WindowSizeStateDel(this, &GWC::WindowSizeStateExc);
					this->Invoke(D, (FormWindowState)Value);
					this->WindowSizeState_ = Value;
					delete D;
				}
			}
		}

		void DefaultWindowSizeState()
		{
			WindowSizeState = MWindowState::Normal;
		}



		/*
			### Window Minimum Size
		*/

	private:

		delegate void WindowMinimumSizeDel(System::Drawing::Size Value);

		void WindowMinimumSizeExc(System::Drawing::Size Value)
		{
			Form::MinimumSize = Value;
		}

		MSize WindowMinimumSize_;

	public:

		virtual property System::Drawing::Size MinimumSize
		{
			System::Drawing::Size get() override
			{
				return Form::MinimumSize;
			}

			void set(System::Drawing::Size Value) override
			{
				this->WindowMinimumSize_ = SizeToMSize(Value);
				Form::MinimumSize = Value;
			}
		}

		property MSize WindowMinimumSize
		{
			MSize get()
			{
				return WindowMinimumSize_;
			}

			void set(MSize Value)
			{
				if (WindowStarted && WindowClosed == false)
				{
					WindowMinimumSizeDel^ D = gcnew WindowMinimumSizeDel(this, &GWC::WindowMinimumSizeExc);
					this->Invoke(D, MSizeToSize(Value));
					this->WindowMinimumSize_ = Value;
					delete D;
				}
			}
		}

		void DefaultWindowMinimumSize()
		{
			WindowMinimumSize = MSize(0, 0);
		}



		/*
			### Window Maximum Size
		*/

	private:

		delegate void WindowMaximumSizeDel(System::Drawing::Size Value);

		void WindowMaximumSizeExc(System::Drawing::Size Value)
		{
			Form::MaximumSize = Value;
		}

		MSize WindowMaximumSize_;

	public:

		virtual property System::Drawing::Size MaximumSize
		{
			System::Drawing::Size get() override
			{
				return Form::MaximumSize;
			}

			void set(System::Drawing::Size Value) override
			{
				this->WindowMaximumSize_ = SizeToMSize(Value);
				Form::MaximumSize = Value;
			}
		}

		property MSize WindowMaximumSize
		{
			MSize get()
			{
				return WindowMaximumSize_;
			}

			void set(MSize Value)
			{
				if (WindowStarted && WindowClosed == false)
				{
					WindowMaximumSizeDel^ D = gcnew WindowMaximumSizeDel(this, &GWC::WindowMaximumSizeExc);
					this->Invoke(D, MSizeToSize(Value));
					this->WindowMaximumSize_ = Value;
					delete D;
				}
			}
		}

		void DefaultWindowMaximumSize()
		{
			WindowMaximumSize = MSize(0, 0);
		}



		/*
			### Window Opacity
		*/

	private:

		delegate void WindowOpacityDel(double Value);

		void WindowOpacityExc(double Value)
		{
			Form::Opacity = Value;
		}

		double WindowOpacity_;

	public:

		property double Opacity
		{
			virtual double get() sealed
			{
				return Form::Opacity;
			}

			virtual void set(double Value) sealed
			{
				this->WindowOpacity_ = Value;
				Form::Opacity = Value;
			}
		}

		property double WindowOpacity
		{
			double get()
			{
				return WindowOpacity_;
			}

			void set(double Value)
			{
				if (WindowStarted && WindowClosed == false)
				{
					WindowOpacityDel^ D = gcnew WindowOpacityDel(this, &GWC::WindowOpacityExc);
					this->Invoke(D, Value);
					this->WindowOpacity_ = Value;
					delete D;
				}
			}
		}

		void DefaultWindowOpacity()
		{
			WindowOpacity = 1.00;
		}



		/*
			### Window Always On Top
		*/

	private:

		delegate void WindowAlwaysOnTopDel(bool Value);

		void WindowAlwaysOnTopExc(bool Value)
		{
			Form::TopMost = Value;
		}

		bool WindowAlwaysOnTop_;

	public:

		property bool TopMost
		{
			virtual bool get() sealed
			{
				return Form::TopMost;
			}

			virtual void set(bool Value) sealed
			{
				this->WindowAlwaysOnTop_ = Value;
				Form::TopMost = Value;
			}
		}

		property bool WindowAlwaysOnTop
		{
			bool get()
			{
				return WindowAlwaysOnTop_;
			}

			void set(bool Value)
			{
				if (WindowStarted && WindowClosed == false)
				{
					WindowAlwaysOnTopDel^ D;
					D = gcnew WindowAlwaysOnTopDel(this, &GWC::WindowAlwaysOnTopExc);
					this->Invoke(D, Value);
					this->WindowAlwaysOnTop_ = Value;
					delete D;
				}
			}
		}

		void DefaultWindowAlwaysOnTop()
		{
			WindowAlwaysOnTop = false;
		}



		/*
			### Window In Taskbar
		*/

	private:

		delegate void WindowInTaskbaRedrawDel(bool Value);

		void WindowInTaskbaRedrawExc(bool Value)
		{
			Form::ShowInTaskbar;
		}

		bool WindowInTaskbar_;

	public:

		property bool ShowInTaskbar
		{
			virtual bool get() sealed
			{
				return Form::ShowInTaskbar;
			}

			virtual void set(bool Value) sealed
			{
				this->WindowInTaskbar_ = Value;
				Form::ShowInTaskbar = Value;
			}
		}

		property bool WindowInTaskbar
		{
			bool get() 
			{
				return WindowInTaskbar_;
			}

			void set(bool Value)
			{
				if (WindowStarted && WindowClosed == false)
				{
					WindowInTaskbaRedrawDel^ D;
					D = gcnew WindowInTaskbaRedrawDel(this, &GWC::WindowInTaskbaRedrawExc);
					this->Invoke(D, Value);
					this->WindowInTaskbar_ = Value;
					delete D;
				}
			}
		}

		void DefaultWindowInTaskbar()
		{
			WindowInTaskbar = false;
		}



		/*
			### Window Buttons
		*/

	private:

		delegate void WindowButtonsDel(bool Value);

		void WindowButtonsExc(bool Value)
		{
			Form::ControlBox = Value;
		}

		bool WindowButtons_;

	public:

		property bool ControlBox
		{
			virtual bool get() sealed 
			{
				return Form::ControlBox;
			}

			virtual void set(bool Value) sealed
			{
				this->WindowButtons_ = Value;
				Form::ControlBox = Value;
			}
		}

		property bool WindowButtons
		{
			bool get()
			{
				return WindowButtons_;
			}

			void set(bool Value)
			{
				if (WindowStarted && WindowClosed == false)
				{
					WindowButtonsDel^ D = gcnew WindowButtonsDel(this, &GWC::WindowButtonsExc);
					this->Invoke(D, Value);
					this->WindowButtons_ = Value;
					delete D;
				}
			}
		}

		void DefaultWindowButtons()
		{
			WindowButtons = true;
		}



		/*
			### Window Minimize Button
		*/

	private:

		delegate void WindowMinimizeButtonDel(bool Value);

		void WindowMinimizeButtonExc(bool Value)
		{
			Form::MinimizeBox = Value;
		}

		bool WindowMinimizeButton_;

	public:

		property bool MinimizeBox
		{
			virtual bool get() sealed
			{
				return Form::MinimizeBox;
			}

			virtual void set(bool Value) sealed
			{
				this->WindowMinimizeButton_ = Value;
				Form::MinimizeBox = Value;
			}
		}

		property bool WindowMinimizeButton
		{
			bool get() 
			{
				return WindowMinimizeButton_;
			}

			void set(bool Value)
			{
				if (WindowStarted && WindowClosed == false)
				{
					WindowMinimizeButtonDel^ D = gcnew WindowMinimizeButtonDel(this, &GWC::WindowMinimizeButtonExc);
					this->Invoke(D, Value);
					this->WindowMinimizeButton_ = Value;
					delete D;
				}
			}
		}

		void DefaultWindowMinimizeButton()
		{
			WindowMinimizeButton = true;
		}



		/*
			### Window Maximize Button
		*/

	private:

		delegate void WindowMaximizeButtonDel(bool Value);

		void WindowMaximizeButtonExc(bool Value)
		{
			Form::MaximizeBox = Value;
		}

		bool WindowMaximizeButton_;

	public:

		property bool MaximizeBox
		{
			virtual bool get() sealed
			{
				return Form::MaximizeBox;
			}

			virtual void set(bool Value) sealed
			{
				this->WindowMaximizeButton_ = Value;
				Form::MaximizeBox = Value;
			}
		}

		property bool WindowMaximizeButton
		{
			bool get() 
			{
				return WindowMaximizeButton_;
			}

			void set(bool Value)
			{
				if (WindowStarted && WindowClosed == false)
				{
					WindowMaximizeButtonDel^ D = gcnew WindowMaximizeButtonDel(this, &GWC::WindowMaximizeButtonExc);
					this->Invoke(D, Value);
					this->WindowMaximizeButton_ = Value;
					delete D;
				}
			}
		}

		void DefaultWindowMaximizeButton()
		{
			WindowMaximizeButton = true;
		}

		#pragma endregion



		/*
			### Metodi Disegno
			Metodi del disegno

			WP Vs. WoP

			I metodi WP (With Paint) creano degli oggetti graifici utilizzando l'evento 'Paint' della
			finestra di GWC++ mentre i metodi WoP (Without Paint) creano degli oggetti graifici
			utilizzando la funzione 'CreateGraphics()'. I metodi WoP rimangono per compaitibilità.
		*/
		
		#pragma region Metodi Disegno

	private:

		GraphicsState^ CanvasState;
		Pen^ GWCPen;
		SolidBrush^ GWCBrush;
		System::Drawing::Font^ GWCFont;

	public:

		/*
			### Save Canvas
		*/

		void SaveCanvas()
		{
			if (WindowStarted && WindowClosed == false)
			{
				while (IsDrawing());
				Graphics^ G = Graphics::FromImage(Canvas);
				CanvasState = G->Save();
				delete G;
			}
		}



		void SaveCanvasWoP()
		{
			if (WindowStarted && WindowClosed == false)
			{
				Graphics^ G = this->CreateGraphics();
				CanvasState = G->Save();
				delete G;
			}
		}



		/*
			### Restore Canvas
		*/

		void RestoreCanvas()
		{
			if (WindowStarted && WindowClosed == false)
			{
				while (IsDrawing());
				Graphics^ G = Graphics::FromImage(Canvas);
				G->Restore(CanvasState);
				delete G;
			}
		}



		void RestoreCanvasWoP()
		{
			if (WindowStarted && WindowClosed == false)
			{
				Graphics^ G = this->CreateGraphics();
				G->Restore(CanvasState);
				delete G;
			}
		}



		/*
			### Ex Flood Fill
		*/

		bool ExFloodFill(int X, int Y, MColor NewColor, MColor ExColor)
		{
			if (WindowStarted && WindowClosed == false)
			{
				while (IsDrawing());

				try
				{
					if (Canvas->GetPixel(X, Y) != MColorToColor(ExColor) && Canvas->GetPixel(X, Y) != MColorToColor(NewColor))
					{
						Canvas->SetPixel(X, Y, MColorToColor(NewColor));
						ExFloodFill(X + 1, Y, NewColor, ExColor);
						ExFloodFill(X - 1, Y, NewColor, ExColor);
						ExFloodFill(X, Y + 1, NewColor, ExColor);
						ExFloodFill(X, Y - 1, NewColor, ExColor);
					}

					return true;
				}
				catch (Exception^ Ex)
				{
					Interaction::MsgBox(Ex->Message, MsgBoxStyle::OkOnly | MsgBoxStyle::Critical, "GWC++");
					throw Ex;
				}
			}
			
			return false;
		}



		/*
			### In Flood Fill
		*/

		bool ExFloodFill(int X, int Y, MColor NewColor, MColor InColor)
		{
			if (WindowStarted && WindowClosed == false)
			{
				while (IsDrawing());

				try
				{
					if (Canvas->GetPixel(X, Y) == MColorToColor(InColor) && Canvas->GetPixel(X, Y) != MColorToColor(NewColor))
					{
						Canvas->SetPixel(X, Y, MColorToColor(NewColor));
						ExFloodFill(X + 1, Y, NewColor, InColor);
						ExFloodFill(X - 1, Y, NewColor, InColor);
						ExFloodFill(X, Y + 1, NewColor, InColor);
						ExFloodFill(X, Y - 1, NewColor, InColor);
					}

					return true;
				}
				catch (Exception^ Ex)
				{
					Interaction::MsgBox(Ex->Message, MsgBoxStyle::OkOnly | MsgBoxStyle::Critical, "GWC++");
					throw Ex;
				}
			}

			return false;
		}



		/*
			### Clear Window
		*/

		void ClearWindow(MColor C)
		{
			if (WindowStarted && WindowClosed == false)
			{
				while (IsDrawing());
				Graphics^ G = Graphics::FromImage(Canvas);
				G->Clear(MColorToColor(C));
				delete G;
				RedrawWindow();
			}
		}

		void ClearWindow()
		{
			if (WindowStarted && WindowClosed == false)
			{
				while (IsDrawing());
				Graphics^ G = Graphics::FromImage(Canvas);
				G->Clear(MColorToColor(WindowColor));
				delete G;
				RedrawWindow();
			}
		}



		void ClearWindowWoP(MColor C)
		{
			if (WindowStarted && WindowClosed == false)
			{
				Graphics^ G = this->CreateGraphics();
				G->Clear(MColorToColor(C));
				delete G;
			}
		}

		void ClearWindowWoP()
		{
			if (WindowStarted && WindowClosed == false)
			{
				Graphics^ G = this->CreateGraphics();
				G->Clear(MColorToColor(WindowColor));
				delete G;
			}
		}



		/*
			### Draw Line
		*/

		void DrawLine(int X1, int Y1, int X2, int Y2)
		{
			if (WindowStarted && WindowClosed == false)
			{
				while (IsDrawing());
				Graphics^ G = Graphics::FromImage(Canvas);
				G->DrawLine(GWCPen, X1, Y1, X2, Y2);
				delete G;
				RedrawWindow(X1, Y1, X2 - X1, Y2 - Y1);
			}
		}



		void DrawLineWoP(int X1, int Y1, int X2, int Y2)
		{
			if (WindowStarted && WindowClosed == false)
			{
				while (IsDrawing());
				Graphics^ G = this->CreateGraphics();
				G->DrawLine(GWCPen, X1, Y1, X2, Y2);
				delete G;
			}
		}



		/*
			### Draw Arc
		*/

		void DrawArc(int X, int Y, int Width, int Height, int A, int B)
		{
			if (WindowStarted && WindowClosed == false)
			{
				while (IsDrawing());
				Graphics^ G = Graphics::FromImage(Canvas);
				G->DrawArc(GWCPen, X, Y, Width, Height, A, B);
				delete G;
				RedrawWindow(X, Y, Width, Height);
			}
		}



		void DrawArcWoP(int X, int Y, int Width, int Height, int A, int B)
		{
			if (WindowStarted && WindowClosed == false)
			{
				Graphics^ G = this->CreateGraphics();
				G->DrawArc(GWCPen, X, Y, Width, Height, A, B);
				delete G;
			}
		}



		/*
			### Draw Bezier
		*/

		void DrawBezier(float X1, float Y1, float X2, float Y2, float X3, float Y3, float X4, float Y4)
		{
			if (WindowStarted && WindowClosed == false)
			{
				while (IsDrawing());
				Graphics^ G = Graphics::FromImage(Canvas);
				G->DrawBezier(GWCPen, X1, Y1, X2, Y2, X3, Y3, X4, Y4);
				delete G;
				RedrawWindow();
			}
		}



		void DrawBezierWoP(float X1, float Y1, float X2, float Y2, float X3, float Y3, float X4, float Y4)
		{
			if (WindowStarted && WindowClosed == false)
			{
				Graphics^ G = this->CreateGraphics();
				G->DrawBezier(GWCPen, X1, Y1, X2, Y2, X3, Y3, X4, Y4);
				delete G;
			}
		}



		/*
			### Draw Pixel
		*/

		void DrawPixel(int X, int Y)
		{
			if (WindowStarted && WindowClosed == false)
			{
				while (IsDrawing());
				Graphics^ G = Graphics::FromImage(Canvas);
				G->FillRectangle(GWCBrush, X, Y, 1, 1);
				delete G;
				RedrawWindow(X, Y, 1, 1);
			}
		}



		void DrawPixelWoP(int X, int Y)
		{
			if (WindowStarted && WindowClosed == false)
			{
				Graphics^ G = this->CreateGraphics();
				G->FillRectangle(GWCBrush, X, Y, 1, 1);
				delete G;
			}
		}



		/*
			### Draw String
		*/

		void DrawString(String^ Str, int X, int Y)
		{
			if (WindowStarted && WindowClosed == false)
			{
				while (IsDrawing());
				Graphics^ G = Graphics::FromImage(Canvas);
				StringFormat^ GWCStringFormat = gcnew StringFormat();
				GWCStringFormat->Alignment = (StringAlignment)HStringAlignment;
				GWCStringFormat->LineAlignment = (StringAlignment)VStringAlignment;
				G->DrawString(Str, GWCFont, GWCBrush, X, Y, GWCStringFormat);
				delete G;
				RedrawWindow();
			}
		}

		void DrawString(String^ Str, int X, int Y, int Width, int Height)
		{
			if (WindowStarted && WindowClosed == false)
			{
				while (IsDrawing());
				Graphics^ G = Graphics::FromImage(Canvas);
				StringFormat^ GWCStringFormat = gcnew StringFormat();
				GWCStringFormat->Alignment = (StringAlignment)HStringAlignment;
				GWCStringFormat->LineAlignment = (StringAlignment)VStringAlignment;
				G->DrawString(Str, GWCFont, GWCBrush, RectangleF(X, Y, Width, Height), GWCStringFormat);
				delete G;
				RedrawWindow(X, Y, Width, Height);
			}
		}



		void DrawStringWoP(String^ Str, int X, int Y)
		{
			if (WindowStarted && WindowClosed == false)
			{
				Graphics^ G = this->CreateGraphics();
				StringFormat^ GWCStringFormat = gcnew StringFormat();
				GWCStringFormat->Alignment = (StringAlignment)HStringAlignment;
				GWCStringFormat->LineAlignment = (StringAlignment)VStringAlignment;
				G->DrawString(Str, GWCFont, GWCBrush, X, Y, GWCStringFormat);
				delete G;
			}
		}

		void DrawStringWoP(String^ Str, int X, int Y, int Width, int Height)
		{
			if (WindowStarted && WindowClosed == false)
			{
				Graphics^ G = this->CreateGraphics();
				StringFormat^ GWCStringFormat = gcnew StringFormat();
				GWCStringFormat->Alignment = (StringAlignment)HStringAlignment;
				GWCStringFormat->LineAlignment = (StringAlignment)VStringAlignment;
				G->DrawString(Str, GWCFont, GWCBrush, RectangleF(X, Y, Width, Height), GWCStringFormat);
				delete G;
			}
		}



		/*
			### Draw Image
		*/

		void DrawImage(Image^ Image, int X, int Y)
		{
			if (WindowStarted && WindowClosed == false)
			{
				while (IsDrawing());
				Graphics^ G = Graphics::FromImage(Canvas);
				G->DrawImage(Image, X, Y);
				delete G;
				RedrawWindow(X, Y, Image->Width, Image->Height);
			}
		}

		void DrawImage(Image^ Image, int X, int Y, int Width, int Height)
		{
			if (WindowStarted && WindowClosed == false)
			{
				while (IsDrawing());
				Graphics^ G = Graphics::FromImage(Canvas);
				G->DrawImage(Image, X, Y, Width, Height);
				delete G;
				RedrawWindow(X, Y, Width, Height);
			}
		}

		void DrawImage(String^ FileName, int X, int Y)
		{
			if (WindowStarted && WindowClosed == false)
			{
				while (IsDrawing());

				try
				{
					Image^ Image = Image::FromFile(FileName);
					Graphics^ G = Graphics::FromImage(Canvas);
					G->DrawImage(Image, X, Y);
					delete G;
					RedrawWindow(X, Y, Image->Width, Image->Height);
				}
				catch (Exception^ Ex)
				{
					Interaction::MsgBox(Ex->Message, MsgBoxStyle::OkOnly | MsgBoxStyle::Critical, "GWC++");
					throw Ex;
					return;
				}
			}
		}

		void DrawImage(String^ FileName, int X, int Y, int Width, int Height)
		{
			if (WindowStarted && WindowClosed == false)
			{
				while (IsDrawing());

				try
				{
					Image^ Image = Image::FromFile(FileName);
					Graphics^ G = Graphics::FromImage(Canvas);
					G->DrawImage(Image, X, Y, Width, Height);
					delete G;
					RedrawWindow(X, Y, Width, Height);
				}
				catch (Exception^ Ex)
				{
					Interaction::MsgBox(Ex->Message, MsgBoxStyle::OkOnly | MsgBoxStyle::Critical, "GWC++");
					throw Ex;
					return;
				}
			}
		}



		void DrawImageWoP(Image^ Image, int X, int Y)
		{
			if (WindowStarted && WindowClosed == false)
			{
				Graphics^ G = this->CreateGraphics();
				G->DrawImage(Image, X, Y);
				delete G;
			}
		}

		void DrawImageWoP(Image^ Image, int X, int Y, int Width, int Height)
		{
			if (WindowStarted && WindowClosed == false)
			{
				Graphics^ G = this->CreateGraphics();
				G->DrawImage(Image, X, Y, Width, Height);
				delete G;
			}
		}

		void DrawImageWoP(String^ FileName, int X, int Y)
		{
			if (WindowStarted && WindowClosed == false)
			{
				try
				{
					Image^ Image = Image::FromFile(FileName);
					Graphics^ G = this->CreateGraphics();
					G->DrawImage(Image, X, Y);
					delete G;
				}
				catch (Exception^ Ex)
				{
					Interaction::MsgBox(Ex->Message, MsgBoxStyle::OkOnly | MsgBoxStyle::Critical, "GWC++");
					throw Ex;
					return;
				}
			}
		}

		void DrawImageWoP(String^ FileName, int X, int Y, int Width, int Height)
		{
			if (WindowStarted && WindowClosed == false)
			{
				try
				{
					Image^ Image = Image::FromFile(FileName);
					Graphics^ G = this->CreateGraphics();
					G->DrawImage(Image, X, Y, Width, Height);
					delete G;
				}
				catch (Exception^ Ex)
				{
					Interaction::MsgBox(Ex->Message, MsgBoxStyle::OkOnly | MsgBoxStyle::Critical, "GWC++");
					throw Ex;
					return;
				}
			}
		}



		/*
			### Draw Icon
		*/

		void DrawIcon(System::Drawing::Icon^ Icon, int X, int Y)
		{
			if (WindowStarted && WindowClosed == false)
			{
				while (IsDrawing());
				Graphics^ G = Graphics::FromImage(Canvas);
				G->DrawIcon(Icon, X, Y);
				delete G;
				RedrawWindow(X, Y, Icon->Width, Icon->Height);
			}
		}

		void DrawIcon(System::Drawing::Icon^ Icon, int X, int Y, int Width, int Height)
		{
			if (WindowStarted && WindowClosed == false)
			{
				while (IsDrawing());
				Graphics^ G = Graphics::FromImage(Canvas);
				G->DrawIcon(Icon, System::Drawing::Rectangle(X, Y, Width, Height));
				delete G;
				RedrawWindow(X, Y, Width, Height);
			}
		}

		void DrawIcon(String^ FileName, int X, int Y)
		{
			if (WindowStarted && WindowClosed == false)
			{
				while (IsDrawing());

				try
				{
					System::Drawing::Icon^ Icon = gcnew System::Drawing::Icon(FileName);
					Graphics^ G = Graphics::FromImage(Canvas);
					G->DrawIcon(Icon, X, Y);
					delete G;
					RedrawWindow(X, Y, Icon->Width, Icon->Height);
				}
				catch (Exception^ Ex)
				{
					Interaction::MsgBox(Ex->Message, MsgBoxStyle::OkOnly | MsgBoxStyle::Critical, "GWC++");
					throw Ex;
					return;
				}
			}
		}

		void DrawIcon(String^ FileName, int X, int Y, int Width, int Height)
		{
			if (WindowStarted && WindowClosed == false)
			{
				while (IsDrawing());

				try
				{
					System::Drawing::Icon^ Icon = gcnew System::Drawing::Icon(FileName);
					Graphics^ G = Graphics::FromImage(Canvas);
					G->DrawIcon(Icon, System::Drawing::Rectangle(X, Y, Width, Height));
					delete G;
					RedrawWindow(X, Y, Width, Height);
				}
				catch (Exception^ Ex)
				{
					Interaction::MsgBox(Ex->Message, MsgBoxStyle::OkOnly | MsgBoxStyle::Critical, "GWC++");
					throw Ex;
					return;
				}
			}
		}



		void DrawIconWoP(System::Drawing::Icon^ Icon, int X, int Y)
		{
			if (WindowStarted && WindowClosed == false)
			{
				Graphics^ G = this->CreateGraphics();
				G->DrawIcon(Icon, X, Y);
				delete G;
			}
		}

		void DrawIconWoP(System::Drawing::Icon^ Icon, int X, int Y, int Width, int Height)
		{
			if (WindowStarted && WindowClosed == false)
			{
				Graphics^ G = this->CreateGraphics();
				G->DrawIcon(Icon, System::Drawing::Rectangle(X, Y, Width, Height));
				delete G;
			}
		}

		void DrawIconWoP(String^ FileName, int X, int Y)
		{
			if (WindowStarted && WindowClosed == false)
			{
				try
				{
					System::Drawing::Icon^ Icon = gcnew System::Drawing::Icon(FileName);
					Graphics^ G = this->CreateGraphics();
					G->DrawIcon(Icon, X, Y);
					delete G;
				}
				catch (Exception^ Ex)
				{
					Interaction::MsgBox(Ex->Message, MsgBoxStyle::OkOnly | MsgBoxStyle::Critical, "GWC++");
					throw Ex;
					return;
				}
			}
		}

		void DrawIconWoP(String^ FileName, int X, int Y, int Width, int Height)
		{
			if (WindowStarted && WindowClosed == false)
			{
				try
				{
					System::Drawing::Icon^ Icon = gcnew System::Drawing::Icon(FileName);
					Graphics^ G = this->CreateGraphics();
					G->DrawIcon(Icon, System::Drawing::Rectangle(X, Y, Width, Height));
					delete G;
				}
				catch (Exception^ Ex)
				{
					Interaction::MsgBox(Ex->Message, MsgBoxStyle::OkOnly | MsgBoxStyle::Critical, "GWC++");
					throw Ex;
					return;
				}
			}
		}



		/*
			### Draw Square
		*/

		void DrawSquare(int X, int Y, int L)
		{
			if (WindowStarted && WindowClosed == false)
			{
				while (IsDrawing());
				Graphics^ G = Graphics::FromImage(Canvas);
				G->DrawRectangle(GWCPen, X, Y, L, L);
				delete G;
				RedrawWindow(X, Y, L, L);
			}
		}

		void DrawFullSquare(int X, int Y, int L)
		{
			if (WindowStarted && WindowClosed == false)
			{
				while (IsDrawing());
				Graphics^ G = Graphics::FromImage(Canvas);
				G->FillRectangle(GWCBrush, X, Y, L, L);
				delete G;
				RedrawWindow(X, Y, L, L);
			}
		}



		void DrawSquareWoP(int X, int Y, int L)
		{
			if (WindowStarted && WindowClosed == false)
			{
				Graphics^ G = this->CreateGraphics();
				G->DrawRectangle(GWCPen, X, Y, L, L);
				delete G;
			}
		}

		void DrawFullSquareWoP(int X, int Y, int L)
		{
			if (WindowStarted && WindowClosed == false)
			{
				Graphics^ G = this->CreateGraphics();
				G->FillRectangle(GWCBrush, X, Y, L, L);
				delete G;
			}
		}



		/*
			### Draw Rectangle
		*/

		void DrawRectangle(int X, int Y, int Width, int Height)
		{
			if (WindowStarted && WindowClosed == false)
			{
				while (IsDrawing());
				Graphics^ G = Graphics::FromImage(Canvas);
				G->DrawRectangle(GWCPen, X, Y, Width, Height);
				delete G;
				RedrawWindow(X, Y, Width, Height);
			}
		}

		void DrawFullRectangle(int X, int Y, int Width, int Height)
		{
			if (WindowStarted && WindowClosed == false)
			{
				while (IsDrawing());
				Graphics^ G = Graphics::FromImage(Canvas);
				G->FillRectangle(GWCBrush, X, Y, Width, Height);
				delete G;
				RedrawWindow(X, Y, Width, Height);
			}
		}



		void DrawRectangleWoP(int X, int Y, int Width, int Height)
		{
			if (WindowStarted && WindowClosed == false)
			{
				Graphics^ G = this->CreateGraphics();
				G->DrawRectangle(GWCPen, X, Y, Width, Height);
				delete G;
			}
		}

		void DrawFullRectangleWoP(int X, int Y, int Width, int Height)
		{
			if (WindowStarted && WindowClosed == false)
			{
				Graphics^ G = this->CreateGraphics();
				G->FillRectangle(GWCBrush, X, Y, Width, Height);
				delete G;
			}
		}



		/*
			### Draw Ellipse
		*/

		void DrawEllipse(int X, int Y, int Width, int Height)
		{
			if (WindowStarted && WindowClosed == false)
			{
				while (IsDrawing());
				Graphics^ G = Graphics::FromImage(Canvas);
				G->DrawEllipse(GWCPen, X, Y, Width, Height);
				delete G;
				RedrawWindow(X, Y, Width, Height);
			}
		}

		void DrawFullEllipse(int X, int Y, int Width, int Height)
		{
			if (WindowStarted && WindowClosed == false)
			{
				while (IsDrawing());
				Graphics^ G = Graphics::FromImage(Canvas);
				G->FillEllipse(GWCBrush, X, Y, Width, Height);
				delete G;
				RedrawWindow(X, Y, Width, Height);
			}
		}



		void DrawEllipseWoP(int X, int Y, int Width, int Height)
		{
			if (WindowStarted && WindowClosed == false)
			{
				Graphics^ G = this->CreateGraphics();
				G->DrawEllipse(GWCPen, X, Y, Width, Height);
				delete G;
			}
		}

		void DrawFullEllipseWoP(int X, int Y, int Width, int Height)
		{
			if (WindowStarted && WindowClosed == false)
			{
				Graphics^ G = this->CreateGraphics();
				G->FillEllipse(GWCBrush, X, Y, Width, Height);
				delete G;
			}
		}



		/*
			### Draw Circle
		*/

		void DrawCircle(int X, int Y, int R)
		{
			if (WindowStarted && WindowClosed == false)
			{
				while (IsDrawing());
				Graphics^ G = Graphics::FromImage(Canvas);
				G->DrawEllipse(GWCPen, X - R, Y - R, R * 2, R * 2);
				delete G;
				RedrawWindow(X - R, Y - R, R * 2, R * 2);
			}
		}

		void DrawFullCircle(int X, int Y, int R)
		{
			if (WindowStarted && WindowClosed == false)
			{
				while (IsDrawing());
				Graphics^ G = Graphics::FromImage(Canvas);
				G->FillEllipse(GWCBrush, X - R, Y - R, R * 2, R * 2);
				delete G;
				RedrawWindow(X - R, Y - R, R * 2, R * 2);
			}
		}



		void DrawCircleWoP(int X, int Y, int R)
		{
			if (WindowStarted && WindowClosed == false)
			{
				Graphics^ G = this->CreateGraphics();
				G->DrawEllipse(GWCPen, X - R, Y - R, R * 2, R * 2);
				delete G;
			}
		}

		void DrawFullCircleWoP(int X, int Y, int R)
		{
			if (WindowStarted && WindowClosed == false)
			{
				Graphics^ G = this->CreateGraphics();
				G->FillEllipse(GWCBrush, X - R, Y - R, R * 2, R * 2);
				delete G;
			}
		}

		#pragma endregion



		/*
			### Proprietà Disegno
			Proprietà del disegno
		*/

		#pragma region Proprietà Disegno

		/*
			### Pen Color
		*/

	private:

		MColor PenColor_ = MColor(0, 0, 0);

	public:

		property MColor PenColor
		{
			MColor get()
			{
				if (WindowStarted && WindowClosed == false)
				{
					return PenColor_;
				}
			}

			void set(MColor Value)
			{
				if (WindowStarted && WindowClosed == false)
				{
					GWCPen = gcnew Pen(MColorToColor(Value), PenWidth);
					PenColor_ = Value;
				}
			}
		}

		void DefaultPenColor()
		{
			PenColor_ = MColor(0, 0, 0);
		}



		/*
			### Pen Width
		*/

	private:

		float PenWidth_ = 2.5F;

	public:

		property float PenWidth
		{
			float get()
			{
				if (WindowStarted && WindowClosed == false)
				{
					return PenWidth_;
				}
			}

			void set(float Value)
			{
				if (WindowStarted && WindowClosed == false)
				{
					GWCPen = gcnew Pen(MColorToColor(PenColor), Value);
					PenWidth_ = Value;
				}
			}
		}

		void DefaultPenWidth()
		{
			PenWidth = 2.5F;
		}



		/*
			### Fill Color
		*/

	private:

		MColor FillColor_ = MColor(0, 0, 0);

	public:

		property MColor FillColor
		{
			MColor get()
			{
				if (WindowStarted && WindowClosed == false)
				{
					return FillColor_;
				}
			}

			void set(MColor Value)
			{
				if (WindowStarted && WindowClosed == false)
				{
					GWCBrush = gcnew SolidBrush(MColorToColor(Value));
					FillColor_ = Value;
				}
			}
		}

		void DefaultFillColor()
		{
			FillColor = MColor(0, 0, 0);
		}



		/*
			### H String Alignment
		*/

	private:

		MStringAlignment HStringAlignment_ = MStringAlignment::Near;

	public:

		property MStringAlignment HStringAlignment
		{
			MStringAlignment get()
			{
				if (WindowStarted && WindowClosed == false)
				{
					return HStringAlignment_;
				}
			}

			void set(MStringAlignment Value)
			{
				if (WindowStarted && WindowClosed == false)
				{
					HStringAlignment_ = Value;
				}
			}
		}

		void DefaultHStringAlignment()
		{
			HStringAlignment = MStringAlignment::Near;
		}



		/*
			### V String Alignment
		*/

	private:

		MStringAlignment VStringAlignment_ = MStringAlignment::Near;

	public:

		property MStringAlignment VStringAlignment
		{
			MStringAlignment get()
			{
				if (WindowStarted && WindowClosed == false)
				{
					return VStringAlignment_;
				}
			}
			
			void set(MStringAlignment Value)
			{
				if (WindowStarted && WindowClosed == false)
				{
					VStringAlignment_ = Value;
				}
			}
		}

		void DefaultVStringAlignment()
		{
			VStringAlignment = MStringAlignment::Near;
		}



		/*
			### Font Name
		*/

	private:

		String^ FontName_ = "Comic Sans";

	public:

		property String^ FontName
		{
			String^ get()
			{
				if (WindowStarted && WindowClosed == false)
				{
					return FontName_;
				}
			}

			void set(String^ Value)
			{
				if (WindowStarted && WindowClosed == false)
				{
					GWCFont = gcnew System::Drawing::Font(Value, FontSize);
					FontName_ = Value;
				}
			}
		}

		void DefaultFontName() 
		{
			FontName = "Comic Sans";
		}



		/*
			### Font Size
		*/

	private:

		float FontSize_ = 15.0F;

	public:

		property float FontSize
		{
			float get()
			{
				if (WindowStarted && WindowClosed == false)
				{
					return FontSize_;
				}
			}

			void set(float Value)
			{
				if (WindowStarted && WindowClosed == false)
				{
					GWCFont = gcnew System::Drawing::Font(FontName, Value);
					FontSize_ = Value;
				}
			}
		}

		void DefaultFontSize()
		{
			FontSize = 15.0F;
		}

		#pragma endregion

	};
}
