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


namespace GWCpp
{
	public value struct MGPoint
	{
		int X;
		int Y;

		MGPoint(int X, int Y)
		{
			if (X >= 0)
			{
				this->X = X;
			}
			else
			{
				this->X = 0;
			}

			if (Y >= 0)
			{
				this->Y = Y;
			}
			else
			{
				this->Y = 0;
			}
		}
	};


	public value struct MGSize
	{
		int Width;
		int Height;

		MGSize(int Width, int Height)
		{
			if (Width >= 0)
			{
				this->Width = Width;
			}
			else
			{
				this->Width = 0;
			}

			if (Height >= 0)
			{
				this->Height = Height;
			}
			else
			{
				this->Height = 0;
			}
		}
	};


	public value struct MGColor
	{
		int R;
		int G;
		int B;

		MGColor(int R, int G, int B)
		{
			if (R >= 0 || R <= 255)
			{
				this->R = R;
			}
			else
			{
				this->R = 0;
			}

			if (G >= 0 || G <= 255)
			{
				this->G = G;
			}
			else
			{
				this->G = 0;
			}

			if (B >= 0 || B <= 255)
			{
				this->B = B;
			}
			else
			{
				this->B = 0;
			}
		}
	};


	public enum class MGMouseButtons
	{
		None = 0,
		Left = 1048576,
		Right = 2097152,
		Middle = 4194304
	};


	public enum class MGWindowState
	{
		Normal = 0,
		Minimized = 1,
		Maximized = 2
	};


	private ref class GWC : public Form
	{

		/*
			Costruttori e distruttore.
		*/

		// Costruttore.

	public:

		GWC() : Form()
		{
			InitializeComponent(850, 505, "GWC++ Window", 50, 50);
			GWCThread = gcnew Thread(gcnew ThreadStart(this, &GWC::InitializeWindow));
			GWCThread->SetApartmentState(ApartmentState::STA);
		}

		GWC(int Width, int Height) : Form()
		{
			InitializeComponent(Width, Height, "GWC++ Window", 50, 50);
			GWCThread = gcnew Thread(gcnew ThreadStart(this, &GWC::InitializeWindow));
			GWCThread->SetApartmentState(ApartmentState::STA);
		}

		GWC(int Width, int Height, String^ Title) : Form()
		{
			InitializeComponent(Width, Height, Title, 50, 50);
			GWCThread = gcnew Thread(gcnew ThreadStart(this, &GWC::InitializeWindow));
			GWCThread->SetApartmentState(ApartmentState::STA);
		}

		GWC(int Width, int Height, String^ Title, int X, int Y) : Form()
		{
			InitializeComponent(Width, Height, Title, X, Y);
			GWCThread = gcnew Thread(gcnew ThreadStart(this, &GWC::InitializeWindow));
			GWCThread->SetApartmentState(ApartmentState::STA);
		}



		// Distruttore.

	public:

		~GWC()
		{
			if (Components)
			{
				delete Components;
			}
		}



		/*
			Inizializzatori.
		*/

	private:

		// Components.
		System::ComponentModel::Container^ Components;

		// GWCThread.
		Thread^ GWCThread;

		// Initialize Component.
		void InitializeComponent(int Width, int Height, String^ Title, int X, int Y)
		{
			// Sospensione layout.
			this->SuspendLayout();

			// Proprietà finestra.
			this->WindowStarted = false;
			this->WindowClosed = true;
			Form::Text = "GWC++ Window";
			Form::Icon = nullptr;
			Form::ShowIcon = false;
			Form::Location = System::Drawing::Point(X, Y);
			Form::BackColor = Color::FromArgb(240, 240, 240);
			Form::BackgroundImage = nullptr;
			Form::Size = System::Drawing::Size(Width, Height);
			Form::ClientSize = System::Drawing::Size(Width, Height);
			Form::WindowState = FormWindowState::Normal;
			Form::MinimumSize = System::Drawing::Size(0, 0);
			Form::MaximumSize = System::Drawing::Size(0, 0);
			Form::Opacity = 1.00;
			Form::TopMost = false;
			Form::ShowInTaskbar = true;
			Form::ControlBox = true;
			Form::MinimizeBox = true;
			Form::MaximizeBox = true;

			// Proprietà disegno.
			this->DefaultPenColor();
			this->DefaultPenWidth();
			this->DefaultFillColor();
			this->DefaultFontName();
			this->DefaultFontSize();

			// Assegnazione eventi.
			this->MouseDown += gcnew MouseEventHandler(this, &GWC::GWC_MouseDown);
			this->MouseUp += gcnew MouseEventHandler(this, &GWC::GWC_MouseUp);
			this->KeyDown += gcnew KeyEventHandler(this, &GWC::GWC_KeyDown);
			this->KeyUp += gcnew KeyEventHandler(this, &GWC::GWC_KeyUp);

			// Ripresa layout.
			this->ResumeLayout(false);
		}

		// Initialize Window.
		void InitializeWindow()
		{
			Application::EnableVisualStyles();
			Application::SetCompatibleTextRenderingDefault(false);
			Application::Run(this);
		}

		

		/*
			Metodi di conversione.
		*/

	public:

		// Point To MGPoint.
		MGPoint PointToMGPoint(Point Value)
		{
			return MGPoint(Value.X, Value.Y);
		}

		// MGPoint To Point.
		Point MGPointToPoint(MGPoint Value)
		{
			return Point(Value.X, Value.Y);
		}

		// Color To MGColor.
		MGColor ColorToMGColor(Color Value)
		{
			return MGColor(Value.R, Value.G, Value.B);
		}

		// MGColor To Color.
		Color MGColorToColor(MGColor Value)
		{
			return Color::FromArgb(Value.R, Value.G, Value.B);
		}

		// Size To MGSize.
		MGSize SizeToMGSize(System::Drawing::Size Value)
		{
			return MGSize(Value.Width, Value.Height);
		}

		// MGSize To Size.
		System::Drawing::Size MGSizeToSize(MGSize Value)
		{
			return System::Drawing::Size(Value.Width, Value.Height);
		}



		/*
			Metodi finestra.
		*/

	private:

		Dictionary<String^, GraphicsState^> CanvasStates;

	public:

		// Start Window.
		bool StartWindow()
		{
			try
			{
				GWCThread->Start();
				GWCThread->Sleep(50);
				WindowStarted = true;
			}
			catch (Exception^ Ex)
			{
				return false;
			}

			return true;
		}



		// Close Window.
		bool CloseWindow()
		{
			try
			{
				GWCThread->Sleep(50);
				GWCThread->Abort();
				WindowClosed = true;
			}
			catch (Exception^ Ex)
			{
				return false;
			}

			return true;
		}



		// Suspend Window.
		bool SuspendWindow()
		{
			try
			{
				GWCThread->Suspend();
			}
			catch (Exception^ Ex)
			{
				return false;
			}
			finally
			{
				WindowSuspended = true;
			}

			return true;
		}



		// Resume Window.
		bool ResumeWindow()
		{
			try
			{
				GWCThread->Resume();
			}
			catch (Exception^ Ex)
			{
				return false;
			}
			finally
			{
				WindowSuspended = false;
			}

			return true;
		}



		// Pause Window.
		bool PauseWindow(int Time)
		{
			try
			{
				GWCThread->Sleep(Time);
			}
			catch (Exception^ Ex)
			{
				return false;
			}

			return true;
		}



		// Get Window Max X.
		int GetWindowMaxX()
		{
			try
			{
				return Form::Size.Width - 1;
			}
			catch (Exception^ Ex)
			{
				throw Ex;;
			}
		}

		// Get Window Real Max X.
		int GetWindowRealMaxX()
		{
			try
			{
				return Form::ClientSize.Width - 1;
			}
			catch (Exception^ Ex)
			{
				throw Ex;
			}
		}

		// Get Window Max Y.
		int GetWindowMaxY()
		{
			try
			{
				return Form::Size.Height - 1;
			}
			catch (Exception^ Ex)
			{
				throw Ex;
			}
		}

		// Get Window Real Max Y.
		int GetWindowRealMaxY()
		{
			try
			{
				return Form::ClientSize.Height - 1;
			}
			catch (Exception^ Ex)
			{
				throw Ex;
			}
		}



		// Get Screen Max X.
		int GetScreenMaxX()
		{
			try
			{
				return Screen::PrimaryScreen->Bounds.Width;
			}
			catch (Exception^ Ex)
			{
				throw Ex;
			}
		}

		// Get Screen Real Max X.
		int GetScreenRealMaxX()
		{
			try
			{
				return Screen::PrimaryScreen->WorkingArea.Width;
			}
			catch (Exception^ Ex)
			{
				throw Ex;
			}
		}

		// Get Screen Max Y.
		int GetScreenMaxY()
		{
			try
			{
				return Screen::PrimaryScreen->Bounds.Height;
			}
			catch (Exception^ Ex)
			{
				throw Ex;
			}
		}

		// Get Screen Real Max Y.
		int GetScreenRealMaxY()
		{
			try
			{
				return Screen::PrimaryScreen->WorkingArea.Height;
			}
			catch (Exception^ Ex)
			{
				throw Ex;
			}
		}



		// Create Canvas State.
		bool CreateCanvasState(String^ Name)
		{
			try
			{
				Graphics^ G = this->CreateGraphics();
				CanvasStates.Add(Name, G->Save());
				delete G;
			}
			catch (Exception^ Ex)
			{
				return false;
			}

			return true;
		}



		// Delete Canvas State.
		bool DeleteCanvasState(String^ Name)
		{
			try
			{
				Graphics^ G = this->CreateGraphics();
				CanvasStates.Remove(Name);
				delete G;
			}
			catch (Exception^ Ex)
			{
				return false;
			}

			return true;
		}



		// Save Canvas State.
		bool SaveCanvasState(String^ Name)
		{
			try
			{
				Graphics^ G = this->CreateGraphics();
				CanvasStates[Name] = G->Save();
				delete G;
			}
			catch (Exception^ Ex)
			{
				return false;
			}

			return true;
		}



		// Load Canvas State.
		bool LoadCanvasState(String^ Name)
		{
			try
			{
				Graphics^ G = this->CreateGraphics();
				G->Restore(CanvasStates[Name]);
				delete G;
			}
			catch (Exception^ Ex)
			{
				return false;
			}

			return true;
		}



		// Show Window.

	private:

		delegate void ShowWindowDel();

		void ShowWindowExc()
		{
			Form::Show();
		}

	public:

		bool ShowWindow()
		{
			try
			{
				ShowWindowDel^ D;
				D = gcnew ShowWindowDel(this, &GWC::ShowWindowExc);
				this->Invoke(D);
				delete D;
			}
			catch (Exception^ Ex)
			{
				return false;
			}

			return true;
		}



		// Hide Window.

	private:

		delegate void HideWindowDel();

		void HideWindowExc()
		{
			Form::Hide();
		}

	public:

		bool HideWindow()
		{
			try
			{
				HideWindowDel^ D;
				D = gcnew HideWindowDel(this, &GWC::HideWindowExc);
				this->Invoke(D);
				delete D;
			}
			catch (Exception^ Ex)
			{
				return false;
			}

			return true;
		}



		// Mouse Down.

	private:

		bool MouseDownPending;
		MGPoint MouseDownPoint;
		MGMouseButtons MouseDownButton;

		void GWC_MouseDown(Object^ Sender, MouseEventArgs^ E)
		{
			if (MouseDownPending == false)
			{
				return;
			}

			switch (E->Button)
			{
			case System::Windows::Forms::MouseButtons::Left:
				MouseDownPoint = MGPoint(E->X, E->Y);
				MouseDownPending = false;
				break;

			case System::Windows::Forms::MouseButtons::Right:
				MouseDownPoint = MGPoint(E->X, E->Y);
				MouseDownPending = false;
				break;

			case System::Windows::Forms::MouseButtons::Middle:
				MouseDownPoint = MGPoint(E->X, E->Y);
				MouseDownPending = false;
				break;

			case System::Windows::Forms::MouseButtons::None:
				MouseDownPoint = MGPoint(E->X, E->Y);
				MouseDownPending = false;
				break;

			default:
				break;
			}
		}

	public:

		MGPoint RequestMouseDown(MGMouseButtons B)
		{
			MouseDownPending = true;
			MouseDownButton = B;

			while (MouseDownPending)
			{
				GWCThread->Sleep(10);
			}

			return MouseDownPoint;
		}

		MGPoint RequestMouseDown()
		{
			MouseDownPending = true;
			MouseDownButton = MGMouseButtons::None;

			while (MouseDownPending)
			{
				GWCThread->Sleep(10);
			}

			return MouseDownPoint;
		}



		// Mouse Up.

	private:

		bool MouseUpPending;
		MGPoint MouseUpPoint;
		MGMouseButtons MouseUpButton;

		void GWC_MouseUp(Object^ Sender, MouseEventArgs^ E)
		{
			if (MouseUpPending == false)
			{
				return;
			}

			switch (E->Button)
			{
			case System::Windows::Forms::MouseButtons::Left:
				MouseUpPoint = MGPoint(E->X, E->Y);
				MouseUpPending = false;
				break;

			case System::Windows::Forms::MouseButtons::Right:
				MouseUpPoint = MGPoint(E->X, E->Y);
				MouseUpPending = false;
				break;

			case System::Windows::Forms::MouseButtons::Middle:
				MouseUpPoint = MGPoint(E->X, E->Y);
				MouseUpPending = false;
				break;

			case System::Windows::Forms::MouseButtons::None:
				MouseUpPoint = MGPoint(E->X, E->Y);
				MouseUpPending = false;
				break;

			default:
				break;
			}
		}

	public:

		MGPoint RequestMouseUp(MGMouseButtons B)
		{
			MouseUpPending = true;
			MouseUpButton = B;

			while (MouseUpPending)
			{
				GWCThread->Sleep(10);
			}

			return MouseUpPoint;
		}

		MGPoint RequestMouseUp()
		{
			MouseUpPending = true;
			MouseUpButton = MGMouseButtons::None;

			while (MouseUpPending)
			{
				GWCThread->Sleep(10);
			}

			return MouseUpPoint;
		}



		// Key Down.

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
					return;
				}
			}
		}

	public:

		Char RequestKeyDown(Char C)
		{
			Char R;

			do
			{
				R = RequestKeyDown();
			} while (R != C);

			return R;
		}

		Char RequestKeyDown()
		{
			KeyDownPending = true;

			while (KeyDownPending)
			{
				GWCThread->Sleep(10);
			}

			return (Char)KeyDownChar;
		}



		// Key Up.

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
					return;
				}
			}
		}

	public:

		Char RequestKeyUp(Char C)
		{
			Char R;

			do
			{
				R = RequestKeyUp();
			} while (R != C);

			return R;
		}

		Char RequestKeyUp()
		{
			KeyUpPending = true;

			while (KeyUpPending)
			{
				GWCThread->Sleep(10);
			}

			return (Char)KeyUpChar;
		}



		/*
			Proprietà finestra.
		*/

		// Window Started.

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



		// Window Closed.

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



		// Window Suspended.
		
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



		// Window Title.

	private:

		delegate void WindowTitleDel(String^ Value);

		void WindowTitleExc(String^ Value)
		{
			this->Text = Value;
		}

		String^ WindowTitle_;

	public:

		property String^ WindowTitle
		{
			String^ get()
			{
				return WindowTitle_;
			}

			void set(String^ Value)
			{
				try
				{
					WindowTitleDel^ D;
					D = gcnew WindowTitleDel(this, &GWC::WindowTitleExc);
					this->Invoke(D, Value);
					this->WindowTitle_ = Value;
					delete D;
				}
				catch (Exception^ Ex)
				{
					throw Ex;
				}
			}
		}

		void DefaultWindowTitle()
		{
			WindowTitle = "GWC++ Window";
		}



		// Window Icon.

	private:

		delegate void WindowIconDel(System::Drawing::Icon^ Value);

		void WindowIconExc(System::Drawing::Icon^ Value)
		{
			Form::Icon = Value;
		}

		System::Drawing::Icon^ WindowIcon_;

	public:

		property System::Drawing::Icon^ WindowIcon
		{
			System::Drawing::Icon^ get()
			{
				return WindowIcon_;
			};

			void set(System::Drawing::Icon^ Value)
			{
				try
				{
					WindowIconDel^ D;
					D = gcnew WindowIconDel(this, &GWC::WindowIconExc);
					this->Invoke(D, Value);
					this->WindowIcon_ = Value;
					delete D;
				}
				catch (Exception^ Ex)
				{
					throw Ex;
				}
			}
		}

		void DefaultWindowIcon()
		{
			WindowIcon = nullptr;
		}



		// Window Icon Visible.
	
	private:

		delegate void WindowIconVisibleDel(bool Value);

		void WindowIconVisibleExc(bool Value)
		{
			Form::ShowIcon = Value;
		}

		bool WindowIconVisible_;

	public:

		property bool WindowIconVisible
		{
			bool get()
			{
				return WindowIconVisible_;
			}

			void set(bool Value)
			{
				try
				{
					WindowIconVisibleDel^ D;
					D = gcnew WindowIconVisibleDel(this, &GWC::WindowIconVisibleExc);
					this->Invoke(D, Value);
					this->WindowIconVisible_ = Value;
					delete D;
				}
				catch (Exception^ Ex)
				{
					throw Ex;
				}
			}
		}

		void DefaultWindowIconVisible()
		{
			WindowIconVisible = true;
		}



		// Window Location.

	private:

		delegate void WindowLocationDel(Point Value);

		void WindowLocationExc(Point Value)
		{
			Form::Location = Value;
		}

		MGPoint WindowLocation_;

	public:

		property MGPoint WindowLocation
		{
			MGPoint get()
			{
				return WindowLocation_;
			}

			void set(MGPoint Value)
			{
				try
				{
					WindowLocationDel^ D;
					D = gcnew WindowLocationDel(this, &GWC::WindowLocationExc);
					this->Invoke(D, MGPointToPoint(Value));
					this->WindowLocation_ = Value;
					delete D;
				}
				catch (Exception^ Ex)
				{
					throw Ex;
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
				WindowLocation = MGPoint(Value, WindowLocation.Y);
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
				WindowLocation = MGPoint(WindowLocation.X, Value);
			}
		}

		void DefaultWindowLocation()
		{
			WindowLocation = MGPoint(0, 0);
		}	

		void DefaultWindowX()
		{
			WindowX = 0;
		}

		void DefaultWindowY()
		{
			WindowY = 0;
		}



		// Window Color.

	private:

		delegate void WindowColorDel(Color Value);

		void WindowColorExc(Color Value)
		{
			Form::BackColor = Value;
		}

		MGColor WindowColor_;
		
	public:	

		property MGColor WindowColor
		{
			MGColor get()
			{
				return WindowColor_;
			}

			void set(MGColor Value)
			{
				try
				{
					WindowColorDel^ D;
					D = gcnew WindowColorDel(this, &GWC::WindowColorExc);
					this->Invoke(D, MGColorToColor(Value));
					this->WindowColor_ = Value;
					delete D;
				}
				catch (Exception^ Ex)
				{
					throw Ex;
				}
			}
		}

		void DefaultWindowColor()
		{
			WindowColor = MGColor(0, 0, 0);
		}



		// Window Image.

	private:

		delegate void WindowImageDel(Image^ Value);

		void WindowImageExc(Image^ Value)
		{
			Form::BackgroundImage = Value;
		}

		Image^ WindowImage_;

	public:

		property Image^ WindowImage
		{
			Image^ get()
			{
				return WindowImage_;
			}

			void set(Image^ Value)
			{
				try
				{
					WindowImageDel^ D;
					D = gcnew WindowImageDel(this, &GWC::WindowImageExc);
					this->Invoke(D, Value);
					this->WindowImage_ = Value;
					delete D;
				}
				catch (Exception^ Ex)
				{
					throw Ex;
				}
			}
		}

		void DefaultWindowImage()
		{
			WindowImage = nullptr;
		}



		// Window Size.

	private:

		delegate void WindowSizeDel(System::Drawing::Size Value);

		void WindowSizeExc(System::Drawing::Size Value)
		{
			Form::Size = Value;
		}

		MGSize WindowSize_;

	public:

		property MGSize WindowSize
		{
			MGSize get()
			{
				return WindowSize_;
			}

			void set(MGSize Value)
			{
				try
				{
					WindowSizeDel^ D;
					D = gcnew WindowSizeDel(this, &GWC::WindowSizeExc);
					this->Invoke(D, MGSizeToSize(Value));
					this->WindowSize_ = Value;
					delete D;
				}
				catch (Exception^ Ex)
				{
					throw Ex;
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
				WindowSize = MGSize(Value, WindowSize.Height);
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
				WindowSize = MGSize(WindowSize.Width, Value);
			}
		}

		void DefaultWindowSize()
		{
			WindowSize = MGSize(850, 505);
		}

		void DefaultWindowWidth()
		{
			WindowWidth = 850;
		}

		void DefaultWindowHeight()
		{
			WindowHeight = 505;
		}



		// Window Real Size.

	private:

		delegate void WindowRealSizeDel(System::Drawing::Size Value);

		void WindowRealSizeExc(System::Drawing::Size Value)
		{
			Form::ClientSize = Value;
		}

		MGSize WindowRealSize_;

	public:

		property MGSize WindowRealSize
		{
			MGSize get()
			{
				return WindowRealSize_;
			}

			void set(MGSize Value)
			{
				try
				{
					WindowRealSizeDel^ D;
					D = gcnew WindowRealSizeDel(this, &GWC::WindowRealSizeExc);
					this->Invoke(D, MGSizeToSize(Value));
					this->WindowRealSize_ = Value;
					delete D;
				}
				catch (Exception^ Ex)
				{
					throw Ex;
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
				WindowRealSize = MGSize(Value, WindowRealSize.Height);
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
				WindowRealSize = MGSize(WindowRealSize.Width, Value);
			}
		}

		void DefaultWindowRealSize()
		{
			WindowRealSize = MGSize(850, 505);
		}

		void DefaultWindowRealWidth()
		{
			WindowRealWidth = 850;
		}

		void DefaultWindowRealHeight()
		{
			WindowRealHeight = 505;
		}



		// Window Size State.

	private:

		delegate void WindowSizeStateDel(FormWindowState Value);

		void WindowSizeStateExc(FormWindowState Value)
		{
			Form::WindowState = Value;
		}

		MGWindowState WindowSizeState_;

	public:

		property MGWindowState WindowSizeState
		{
			MGWindowState get()
			{
				return WindowSizeState_;
			}

			void set(MGWindowState Value)
			{
				try
				{
					WindowSizeStateDel^ D;
					D = gcnew WindowSizeStateDel(this, &GWC::WindowSizeStateExc);
					this->Invoke(D, (FormWindowState)Value);
					this->WindowSizeState_ = Value;
					delete D;
				}
				catch (Exception^ Ex)
				{
					throw Ex;
				}
			}
		}

		void DefaultWindowSizeState()
		{
			WindowSizeState = MGWindowState::Normal;
		}



		// Window Minimum Size.

	private:

		delegate void WindowMinimumSizeDel(System::Drawing::Size Value);

		void WindowMinimumSizeExc(System::Drawing::Size Value)
		{
			Form::MinimumSize = Value;
		}

		MGSize WindowMinimumSize_;

	public:

		property MGSize WindowMinimumSize
		{
			MGSize get()
			{
				return WindowMinimumSize_;
			}

			void set(MGSize Value)
			{
				try
				{
					WindowMinimumSizeDel^ D;
					D = gcnew WindowMinimumSizeDel(this, &GWC::WindowMinimumSizeExc);
					this->Invoke(D, MGSizeToSize(Value));
					this->WindowMinimumSize_ = Value;
					delete D;
				}
				catch (Exception^ Ex)
				{
					throw Ex;
				}
			}
		}

		void DefaultWindowMinimumSize()
		{
			WindowMinimumSize = MGSize(0, 0);
		}



		// Window Maximum Size.

	private:

		delegate void WindowMaximumSizeDel(System::Drawing::Size Value);

		void WindowMaximumSizeExc(System::Drawing::Size Value)
		{
			Form::MaximumSize = Value;
		}

		MGSize WindowMaximumSize_;

	public:

		property MGSize WindowMaximumSize
		{
			MGSize get()
			{
				return WindowMaximumSize_;
			}

			void set(MGSize Value)
			{
				try
				{
					WindowMaximumSizeDel^ D;
					D = gcnew WindowMaximumSizeDel(this, &GWC::WindowMaximumSizeExc);
					this->Invoke(D, MGSizeToSize(Value));
					this->WindowMaximumSize_ = Value;
					delete D;
				}
				catch (Exception^ Ex)
				{
					throw Ex;
				}
			}
		}

		void DefaultWindowMaximumSize()
		{
			WindowMaximumSize = MGSize(0, 0);
		}



		// Window Opacity.

	private:

		delegate void WindowOpacityDel(double Value);

		void WindowOpacityExc(double Value)
		{
			Form::Opacity = Value;
		}

		double WindowOpacity_;

	public:

		property double WindowOpacity
		{
			double get()
			{
				return WindowOpacity_;
			}

			void set(double Value)
			{
				try
				{
					WindowOpacityDel^ D;
					D = gcnew WindowOpacityDel(this, &GWC::WindowOpacityExc);
					this->Invoke(D, Value);
					this->WindowOpacity_ = Value;
					delete D;
				}
				catch (Exception^ Ex)
				{
					throw Ex;
				}
			}
		}

		void DefaultWindowOpacity()
		{
			WindowOpacity = 1.00;
		}



		// Window Always On Top.

	private:

		delegate void WindowAlwaysOnTopDel(bool Value);

		void WindowAlwaysOnTopExc(bool Value)
		{
			Form::TopMost = Value;
		}

		bool WindowAlwaysOnTop_;

	public:

		property bool WindowAlwaysOnTop
		{
			bool get()
			{
				return WindowAlwaysOnTop_;
			}

			void set(bool Value)
			{
				try
				{
					WindowAlwaysOnTopDel^ D;
					D = gcnew WindowAlwaysOnTopDel(this, &GWC::WindowAlwaysOnTopExc);
					this->Invoke(D, Value);
					this->WindowAlwaysOnTop_ = Value;
					delete D;
				}
				catch (Exception^ Ex)
				{
					throw Ex;
				}
			}
		}

		void DefaultWindowAlwaysOnTop()
		{
			WindowAlwaysOnTop = false;
		}



		// Window In Taskbar.

	private:

		delegate void WindowInTaskbarDel(bool Value);

		void WindowInTaskbarExc(bool Value)
		{
			Form::ShowInTaskbar;
		}

		bool WindowInTaskbar_;

	public:

		property bool WindowInTaskbar
		{
			bool get()
			{
				return WindowInTaskbar_;
			}

			void set(bool Value)
			{
				try
				{
					WindowInTaskbarDel^ D;
					D = gcnew WindowInTaskbarDel(this, &GWC::WindowInTaskbarExc);
					this->Invoke(D, Value);
					this->WindowInTaskbar_ = Value;
					delete D;
				}
				catch (Exception^ Ex)
				{
					throw Ex;
				}
			}
		}

		void DefaultWindowInTaskbar()
		{
			WindowInTaskbar = true;
		}



		// Window Buttons.

	private:

		delegate void WindowButtonsDel(bool Value);

		void WindowButtonsExc(bool Value)
		{
			Form::ControlBox = Value;
		}

	public:

		bool WindowButtons_;

		property bool WindowButtons
		{
			bool get()
			{
				return WindowButtons_;
			}

			void set(bool Value)
			{
				try
				{
					WindowButtonsDel^ D;
					D = gcnew WindowButtonsDel(this, &GWC::WindowButtonsExc);
					this->Invoke(D, Value);
					this->WindowButtons_ = Value;
					delete D;
				}
				catch (Exception^ Ex)
				{
					throw Ex;
				}
			}
		}

		void DefaultWindowButtons()
		{
			WindowButtons = true;
		}



		// Window Minimize Button.

	private:

		delegate void WindowMinimizeButtonDel(bool Value);

		void WindowMinimizeButtonExc(bool Value)
		{
			Form::MinimizeBox = Value;
		}

		bool WindowMinimizeButton_;

	public:

		property bool WindowMinimizeButton
		{
			bool get()
			{
				return WindowMinimizeButton_;
			}

			void set(bool Value)
			{
				try
				{
					WindowMinimizeButtonDel^ D;
					D = gcnew WindowMinimizeButtonDel(this, &GWC::WindowMinimizeButtonExc);
					this->Invoke(D, Value);
					this->WindowMinimizeButton_ = Value;
					delete D;
				}
				catch (Exception^ Ex)
				{
					throw Ex;
				}
			}
		}

		void DefaultWindowMinimizeButton()
		{
			WindowMinimizeButton = true;
		}



		// Window Maximize Button.

	private:

		delegate void WindowMaximizeButtonDel(bool Value);

		void WindowMaximizeButtonExc(bool Value)
		{
			Form::MaximizeBox = Value;
		}

		bool WindowMaximizeButton_;

	public:

		property bool WindowMaximizeButton
		{
			bool get()
			{
				return WindowMaximizeButton_;
			}

			void set(bool Value)
			{
				try
				{
					WindowMaximizeButtonDel^ D;
					D = gcnew WindowMaximizeButtonDel(this, &GWC::WindowMaximizeButtonExc);
					this->Invoke(D, Value);
					this->WindowMaximizeButton_ = Value;
					delete D;
				}
				catch (Exception^ Ex)
				{
					throw Ex;
				}
			}
		}

		void DefaultWindowMaximizeButton()
		{
			WindowMaximizeButton = true;
		}



		/*
			Metodi disegno.
		*/

	private:

		// Canvas.
		System::Drawing::Drawing2D::GraphicsState^ Canvas;

		// GcnewPen.
		Pen^ GcnewPen;

		// GcnewSolidBrush.
		SolidBrush^ GcnewSolidBrush;

		// GcnewFont.
		System::Drawing::Font^ GcnewFont;

	public:

		// Clear Window.
		void ClearWindow()
		{
			try
			{
				Graphics^ G = this->CreateGraphics();
				G->Clear(MGColorToColor(WindowColor));
				delete G;
			}
			catch (Exception^ Ex)
			{
				throw Ex;
			}
		}



		// Save Canvas.
		void SaveCanvas()
		{
			try
			{
				Graphics^ G = this->CreateGraphics();
				this->Canvas = G->Save();
				delete G;
			}
			catch (Exception^ Ex)
			{
				throw Ex;
			}
		}



		// Restore Canvas.
		void RestoreCanvas()
		{
			try
			{
				Graphics^ G = this->CreateGraphics();
				G->Restore(this->Canvas);
				delete G;
			}
			catch (Exception^ Ex)
			{
				throw Ex;
			}
		}



		// Draw Pixel.
		void DrawPixel(int X, int Y)
		{
			try
			{
				Graphics^ G = this->CreateGraphics();
				G->DrawRectangle(GcnewPen, X, Y, 1, 1);
				delete G;
			}
			catch (Exception^ Ex)
			{
				throw Ex;
			}
		}



		// Draw Line.
		void DrawLine(int X1, int Y1, int X2, int Y2)
		{
			try
			{
				Graphics^ G = this->CreateGraphics();
				G->DrawLine(GcnewPen, X1, Y1, X2, Y2);
				delete G;
			}
			catch (Exception^ Ex)
			{
				throw Ex;
			}
		}



		// Draw Arc.
		void DrawArc(int X, int Y, int Width, int Height, int A, int B)
		{
			try
			{
				Graphics^ G = this->CreateGraphics();
				G->DrawArc(GcnewPen, X, Y, Width, Height, A, B);
				delete G;
			}
			catch (Exception^ Ex)
			{
				throw Ex;
			}
		}



		// Draw Bezier.
		void DrawBezier(float X1, float Y1, float X2, float Y2, float X3, float Y3, float X4, float Y4)
		{
			try
			{
				Graphics^ G = this->CreateGraphics();
				G->DrawBezier(GcnewPen, X1, Y1, X2, Y2, X3, Y3, X4, Y4);
				delete G;
			}
			catch (Exception^ Ex)
			{
				throw Ex;
			}
		}



		// Draw String.
		void DrawString(String^ S, int X, int Y)
		{
			try
			{
				Graphics^ G = this->CreateGraphics();
				G->DrawString(S, GcnewFont, GcnewSolidBrush, Point(X, Y));
				delete G;
			}
			catch (Exception^ Ex)
			{
				throw Ex;
			}
		}



		// Draw Image.
		void DrawImage(Image^ Image, int X, int Y)
		{
			try
			{
				Graphics^ G = this->CreateGraphics();
				G->DrawImage(Image, X, Y);
				delete G;
			}
			catch (Exception^ Ex)
			{
				throw Ex;
			}
		}



		// Draw Image From File.
		void DrawImageFromFile(String^ FileName, int X, int Y)
		{
			try
			{			
				Graphics^ G = this->CreateGraphics();
				Image^ Image = Image::FromFile(FileName);
				G->DrawImage(Image, X, Y);
				delete G;
			}
			catch (Exception^ Ex)
			{
				throw Ex;
			}		
		}



		// Draw Icon.
		void DrawIcon(System::Drawing::Icon^ Icon, int X, int Y)
		{
			try
			{
				Graphics^ G = this->CreateGraphics();
				G->DrawIcon(Icon, X, Y);
				delete G;
			}
			catch (Exception^ Ex)
			{
				throw Ex;
			}
		}



		// Draw Icon From File.
		void DrawIconFromFile(String^ FileName, int X, int Y)
		{
			try
			{
				Graphics^ G = this->CreateGraphics();
				System::Drawing::Icon^ Icon = gcnew System::Drawing::Icon(FileName);
				G->DrawIcon(Icon, X, Y);
				delete G;
			}
			catch (Exception^ Ex)
			{
				throw Ex;
			}
		}



		// Draw Square.
		void DrawSquare(int X, int Y, int L)
		{
			try
			{
				Graphics^ G = this->CreateGraphics();
				G->DrawRectangle(GcnewPen, X, Y, L, L);
				delete G;
			}
			catch (Exception^ Ex)
			{
				throw Ex;
			}
		}



		// Draw Full Square.
		void DrawFullSquare(int X, int Y, int L)
		{
			try
			{
				Graphics^ G = this->CreateGraphics();
				G->FillRectangle(GcnewSolidBrush, X, Y, L, L);
				delete G;
			}
			catch (Exception^ Ex)
			{
				throw Ex;
			}
		}



		// Draw Rectangle.
		void DrawRectangle(int X, int Y, int Width, int Height)
		{
			try
			{
				Graphics^ G = this->CreateGraphics();
				G->DrawRectangle(GcnewPen, X, Y, Width, Height);
				delete G;
			}
			catch (Exception^ Ex)
			{
				throw Ex;
			}
		}



		// Draw Full Rectangle.
		void DrawFullRectangle(int X, int Y, int Width, int Height)
		{
			try
			{
				Graphics^ G = this->CreateGraphics();
				G->FillRectangle(GcnewSolidBrush, X, Y, Width, Height);
				delete G;
			}
			catch (Exception^ Ex)
			{
				throw Ex;
			}
		}



		// Draw Ellipse.
		void DrawEllipse(int X, int Y, int Width, int Height)
		{
			try
			{
				Graphics^ G = this->CreateGraphics();
				G->DrawEllipse(GcnewPen, X, Y, Width, Height);
				delete G;
			}
			catch (Exception^ Ex)
			{
				throw Ex;
			}
		}



		// DrawFullEllipse.
		void DrawFullEllipse(int X, int Y, int Width, int Height)
		{
			try
			{
				Graphics^ G = this->CreateGraphics();
				G->FillEllipse(GcnewSolidBrush, X, Y, Width, Height);
				delete G;
			}
			catch (Exception^ Ex)
			{
				throw Ex;
			}
		}



		// DrawCircle.
		void DrawCircle(int X, int Y, int R)
		{
			try
			{
				Graphics^ G = this->CreateGraphics();
				G->DrawEllipse(GcnewPen, X - R, Y - R, R * 2, R * 2);
				delete G;
			}
			catch (Exception^ Ex)
			{
				throw Ex;
			}
		}



		// DrawFullCircle.
		void DrawFullCircle(int X, int Y, int R)
		{
			try
			{
				Graphics^ G = this->CreateGraphics();
				G->FillEllipse(GcnewSolidBrush, X - R, Y - R, R * 2, R * 2);
				delete G;
			}
			catch (Exception^ Ex)
			{
				throw Ex;
			}
		}



		// Draw Curve.
		void DrawCurve(array<MGPoint>^ Points)
		{
			try
			{
				Graphics^ G = this->CreateGraphics();
				array<Point>^ Temp = gcnew array<Point>(Points->Length);

				for (int I = 0; I < Points->Length; I++)
				{
					Temp[I] = MGPointToPoint(Points[I]);
				}

				G->DrawCurve(GcnewPen, Temp);
				delete G;
			}
			catch (Exception^ Ex)
			{
				throw Ex;
			}
		}



		// Draw Closed Curve.
		void DrawClosedCurve(array<MGPoint>^ Points)
		{
			try
			{
				Graphics ^ G = this->CreateGraphics();
				array<Point>^ Temp = gcnew array<Point>(Points->Length);

				for (int I = 0; I < Points->Length; I++)
				{
					Temp[I] = MGPointToPoint(Points[I]);
				}

				G->DrawClosedCurve(GcnewPen, Temp);
				delete G;
			}
			catch (Exception^ Ex)
			{
				throw Ex;
			}
		}



		// Draw Polygon.
		void DrawPolygon(array<MGPoint>^ Points)
		{
			try
			{
				Graphics^ G = this->CreateGraphics();
				array<Point>^ Temp = gcnew array<Point>(Points->Length);

				for (int I = 0; I < Points->Length; I++)
				{
					Temp[I] = MGPointToPoint(Points[I]);
				}

				G->DrawPolygon(GcnewPen, Temp);
				delete G;
			}
			catch (Exception^ Ex)
			{
				throw Ex;
			}
		}



		// Draw Full Polygon.
		void DrawFullPolygon(array<MGPoint>^ Points)
		{
			try
			{
				Graphics^ G = this->CreateGraphics();
				array<Point>^ Temp = gcnew array<Point>(Points->Length);

				for (int I = 0; I < Points->Length; I++)
				{
					Temp[I] = MGPointToPoint(Points[I]);
				}

				G->FillPolygon(GcnewSolidBrush, Temp);
				delete G;
			}
			catch (Exception^ Ex)
			{
				throw Ex;
			}
		}



		// Draw Pie.
		void DrawPie(int X, int Y, int Width, int Height, int A, int B)
		{
			try
			{
				Graphics^ G = this->CreateGraphics();
				G->DrawPie(GcnewPen, X, Y, Width, Height, A, B);
				delete G;
			}
			catch (Exception^ Ex)
			{
				throw Ex;
			}
		}



		// Draw Full Pie.
		void DrawFullPie(int X, int Y, int Width, int Height, int A, int B)
		{
			try
			{
				Graphics^ G = this->CreateGraphics();
				G->FillPie(GcnewSolidBrush, X, Y, Width, Height, A, B);
				delete G;
			}
			catch (Exception^ Ex)
			{
				throw Ex;
			}
		}


		// Draw From Screen.
		void DrawFromScreen(int X1, int Y1, int X2, int Y2, int Width, int Height)
		{
			try
			{
				Graphics^ G = this->CreateGraphics();
				G->CopyFromScreen(Point(X1, Y1), Point(X2, Y2), System::Drawing::Size(Width, Height));
				delete G;
			}
			catch (Exception^ Ex)
			{
				throw Ex;
			}
		}



		/*
			Proprietà disegno.
		*/

		// Pen Color.

	private:

		MGColor PenColor_ = MGColor(0, 0, 0);

	public:

		property MGColor PenColor
		{
			MGColor get()
			{
				return PenColor_;
			}

			void set(MGColor Value)
			{
				GcnewPen = gcnew Pen(MGColorToColor(Value), PenWidth);
				PenColor_ = Value;
			}
		}

		void DefaultPenColor()
		{
			PenColor_ = MGColor(0, 0, 0);
		}



		// Pen Width.

	private:

		float PenWidth_ = 2.5F;

	public:

		property float PenWidth
		{
			float get()
			{
				return PenWidth_;
			}

			void set(float Value)
			{
				GcnewPen = gcnew Pen(MGColorToColor(PenColor), Value);
				PenWidth_ = Value;
			}
		}

		void DefaultPenWidth()
		{
			PenWidth = 2.5F;
		}



		// Fill Color.

	private:

		MGColor FillColor_ = MGColor(0, 0, 0);

	public:

		property MGColor FillColor
		{
			MGColor get()
			{
				return FillColor_;
			}

			void set(MGColor Value)
			{
				GcnewSolidBrush = gcnew SolidBrush(MGColorToColor(Value));
				FillColor_ = Value;
			}
		}

		void DefaultFillColor()
		{
			FillColor = MGColor(0, 0, 0);
		}



		// Font Name.

	private:

		String^ FontName_ = "Comic Sans";

	public:

		property String^ FontName
		{
			String^ get()
			{
				return FontName_;
			}

			void set(String^ Value)
			{
				GcnewFont = gcnew System::Drawing::Font(Value, FontSize);
				FontName_ = Value;
			}
		}

		void DefaultFontName()
		{
			FontName = "Comic Sans";
		}



		// Font Size.

	private:

		float FontSize_ = 15.0F;

	public:

		property float FontSize
		{
			float get()
			{
				return FontSize_;
			}

			void set(float Value)
			{
				GcnewFont = gcnew System::Drawing::Font(FontName, Value);
				FontSize_ = Value;
			}
		}

		void DefaultFontSize()
		{
			FontSize = 15.0F;
		}

	};
}
