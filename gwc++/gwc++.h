/*
	GWC++ (Graphic Window for Console Application)
	
	- Questo progetto è sotto lincenza MIT (https://mit-license.org)
	- Questo progetto è disponibile su GitHub (https://github.com/reallukee/GWCpp)
	- Maggiori informazioni sono diponibili nel file README.md

	ATUORE:			Realluke
	DESCRIZIONE:	Classe gestita GWC
	DATA:			20/03/22
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


	public enum class MGMessageBoxStyle
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


	public enum class MGMessageBoxResult
	{
		OK = 1,
		Cancel = 2,
		Abort = 3,
		Retry = 4,
		Ignore = 5,
		Yes = 6,
		No = 7
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
			// Gestione risorse.
			Resources::ResourceManager^ RM = gcnew Resources::ResourceManager(L"GWCpp.gwc++", this->GetType()->Assembly);

			// Icona GWC++.
			System::Drawing::Icon^ AppIcon = safe_cast<System::Drawing::Icon^>(RM->GetObject("icon"));

			// Components.
			System::ComponentModel::Container^ Components = gcnew System::ComponentModel::Container();

			// Sospensione layout.
			this->SuspendLayout();

			// Proprietà finestra private.
			this->WindowStarted = false;
			this->WindowClosed = true;
			this->WindowSuspended = false;
			this->ResizeRedraw = false;
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;

			// Proprietà finestra pubbliche.
			this->Text = "GWC++ Window";
			this->Icon = AppIcon;
			this->ShowIcon = true;
			this->Location = System::Drawing::Point(X, Y);
			this->BackColor = Color::FromArgb(240, 240, 240);
			this->BackgroundImage = nullptr;
			this->Size = System::Drawing::Size(Width, Height);
			this->ClientSize = System::Drawing::Size(Width, Height);
			this->WindowState = FormWindowState::Normal;
			this->MinimumSize = System::Drawing::Size(0, 0);
			this->MaximumSize = System::Drawing::Size(0, 0);
			this->Opacity = 1.00;
			this->TopMost = false;
			this->ShowInTaskbar = false;
			this->ControlBox = true;
			this->MinimizeBox = true;
			this->MaximizeBox = true;

			// Proprietà disegno.
			this->DefaultPenColor();
			this->DefaultPenWidth();
			this->DefaultFillColor();
			this->DefaultFontName();
			this->DefaultFontSize();

			// Assegnazione eventi.
			this->MouseDown += gcnew MouseEventHandler(this, &GWC::GWC_MouseDown);
			this->MouseUp += gcnew MouseEventHandler(this, &GWC::GWC_MouseUp);
			this->MouseMove += gcnew MouseEventHandler(this, &GWC::GWC_MouseMove);
			this->KeyDown += gcnew KeyEventHandler(this, &GWC::GWC_KeyDown);
			this->KeyUp += gcnew KeyEventHandler(this, &GWC::GWC_KeyUp);

			// Ripresa layout.
			this->ResumeLayout(false);

			// Gestione risorse.
			delete RM;
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
			Metodi evento.
		*/

	protected:

		// On Shown.
		void OnShown(EventArgs^ E) override
		{
			WindowStarted = true;
			WindowClosed = false;
			Form::OnShown(E);
		}

		// On Form Closing.
		void OnFormClosing(FormClosingEventArgs^ E) override
		{
			WindowStarted = false;
			WindowClosed = true;
			Form::OnFormClosing(E);
		}



		/*
			Interazioni.
		*/

	public:

		// Input Box.
		void InputBox(String^ Prompt, String^ Title, String^ DefaultResponse, int X, int Y)
		{
			Interaction::InputBox(Prompt, Title, DefaultResponse, X, Y);
		}

		// Message Box.
		MGMessageBoxResult MessageBox(String^ Prompt, MGMessageBoxStyle Style, String^ Title)
		{
			return (MGMessageBoxResult)Interaction::MsgBox(Prompt, (MsgBoxStyle)Style, Title);
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
			if (WindowStarted == false && WindowClosed == true)
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
			else
			{
				return false;
			}
		}



		// Close Window.
		bool CloseWindow()
		{
			if (WindowStarted == true && WindowClosed == false)
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
			else
			{
				return false;
			}
		}



		// Suspend Window.
		bool SuspendWindow()
		{
			if (WindowStarted == true && WindowClosed == false && WindowSuspended == false)
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
			else
			{
				return false;
			}
		}



		// Resume Window.
		bool ResumeWindow()
		{
			if (WindowStarted == true && WindowClosed == false && WindowSuspended == true)
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
			else
			{
				return false;
			}
		}



		// Pause Window.
		bool PauseWindow(int Time)
		{
			if (WindowStarted == true && WindowClosed == false && WindowSuspended == false)
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
			else
			{
				return false;
			}
		}



		// Get Window Max X.
		int GetWindowMaxX()
		{
			if (WindowStarted == true && WindowClosed == false)
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
			else
			{
				return -104;
			}
		}

		// Get Window Real Max X.
		int GetWindowRealMaxX()
		{
			if (WindowStarted == true && WindowClosed == false)
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
			else
			{
				return -104;
			}
		}

		// Get Window Max Y.
		int GetWindowMaxY()
		{
			if (WindowStarted == true && WindowClosed == false)
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
			else
			{
				return -104;
			}
		}

		// Get Window Real Max Y.
		int GetWindowRealMaxY()
		{
			if (WindowStarted == true && WindowClosed == false)
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
			else
			{
				return -104;
			}
		}



		// Get Screen Max X.
		int GetScreenMaxX()
		{
			if (WindowStarted == true && WindowClosed == false)
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
			else
			{
				return -104;
			}
		}

		// Get Screen Real Max X.
		int GetScreenRealMaxX()
		{
			if (WindowStarted == true && WindowClosed == false)
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
			else
			{
				return -104;
			}
		}

		// Get Screen Max Y.
		int GetScreenMaxY()
		{
			if (WindowStarted == true && WindowClosed == false)
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
			else
			{
				return -104;
			}
		}

		// Get Screen Real Max Y.
		int GetScreenRealMaxY()
		{
			if (WindowStarted == true && WindowClosed == false)
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
			else
			{
				return -104;
			}
		}



		// Create Canvas State.
		bool CreateCanvasState(String^ Name)
		{
			if (WindowStarted == true && WindowClosed == false)
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
			else
			{
				return false;
			}
		}



		// Delete Canvas State.
		bool DeleteCanvasState(String^ Name)
		{
			if (WindowStarted == true && WindowClosed == false)
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
			else
			{
				return false;
			}
		}



		// Save Canvas State.
		bool SaveCanvasState(String^ Name)
		{
			if (WindowStarted == true && WindowClosed == false)
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
			else
			{
				return false;
			}
		}



		// Load Canvas State.
		bool LoadCanvasState(String^ Name)
		{
			if (WindowStarted == true && WindowClosed == false)
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
			else
			{
				return false;
			}
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
			if (WindowStarted == true && WindowClosed == false)
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
			else
			{
				return false;
			}
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
			if (WindowStarted == true && WindowClosed == false)
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
			else
			{
				return false;
			}
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
			if (WindowStarted == true && WindowClosed == false)
			{
				MouseDownPending = true;
				MouseDownButton = B;

				while (MouseDownPending)
				{
					GWCThread->Sleep(10);
				}

				return MouseDownPoint;
			}
			else
			{
				return MGPoint(-104, -104);
			}
		}

		MGPoint RequestMouseDown()
		{
			if (WindowStarted == true && WindowClosed == false)
			{
				MouseDownPending = true;
				MouseDownButton = MGMouseButtons::None;

				while (MouseDownPending)
				{
					GWCThread->Sleep(10);
				}

				return MouseDownPoint;
			}
			else
			{
				return MGPoint(-104, -104);
			}
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
			if (WindowStarted == true && WindowClosed == false)
			{
				MouseUpPending = true;
				MouseUpButton = B;

				while (MouseUpPending)
				{
					GWCThread->Sleep(10);
				}

				return MouseUpPoint;
			}
			else
			{
				return MGPoint(-104, -104);
			}
		}

		MGPoint RequestMouseUp()
		{
			if (WindowStarted == true && WindowClosed == false)
			{
				MouseUpPending = true;
				MouseUpButton = MGMouseButtons::None;

				while (MouseUpPending)
				{
					GWCThread->Sleep(10);
				}

				return MouseUpPoint;
			}
			else
			{
				return MGPoint(-104, -104);
			}
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
			if (WindowStarted == true && WindowClosed == false)
			{
				Char R;

				do
				{
					R = RequestKeyDown();
				} while (R != C);

				return R;
			}
			else 
			{
				return (char)0;
			}
		}

		Char RequestKeyDown()
		{
			if (WindowStarted == true && WindowClosed == false)
			{
				KeyDownPending = true;

				while (KeyDownPending)
				{
					GWCThread->Sleep(10);
				}

				return (Char)KeyDownChar;
			}
			else
			{
				return (char)0;
			}
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
			if (WindowStarted == true && WindowClosed == false)
			{
				Char R;

				do
				{
					R = RequestKeyUp();
				} while (R != C);

				return R;
			}
			else
			{
				return (char)0;
			}
		}

		Char RequestKeyUp()
		{
			if (WindowStarted == true && WindowClosed == false)
			{
				KeyUpPending = true;

				while (KeyUpPending)
				{
					GWCThread->Sleep(10);
				}

				return (Char)KeyUpChar;
			}
			else
			{
				return (char)0;
			}
		}



		// Mouse Location.

	private:
		
		MGPoint MouseLocation_;

		void GWC_MouseMove(Object^ Sender, MouseEventArgs^ E)
		{
			MouseLocation_ = MGPoint(E->X, E->Y);
		}

	public:

		property MGPoint MouseLocation
		{
			MGPoint get()
			{
				if (WindowStarted == true && WindowClosed == false)
				{
					return MouseLocation_;
				}
				else
				{
					return MGPoint(-104, -104);
				}
			}

			void set(MGPoint Value)
			{
				if (WindowStarted == true && WindowClosed == false)
				{
					Form::Cursor->Position = MGPointToPoint(MouseLocation);
					MouseLocation_ = Value;
				}
			}
		}

		property int MouseX
		{
			int get()
			{
				if (WindowStarted == true && WindowClosed == false)
				{
					return MouseLocation.X;
				}
				else
				{
					return -104;
				}
			}

			void set(int Value)
			{
				if (WindowStarted == true && WindowClosed == false)
				{
					MouseLocation = MGPoint(Value, MouseLocation.Y);
					Form::Cursor->Position = MGPointToPoint(MouseLocation);
				}
			}
		}

		property int MouseY
		{
			int get()
			{
				if (WindowStarted == true && WindowClosed == false)
				{
					return MouseLocation.Y;
				}
				else
				{
					return -104;
				}
			}

			void set(int Value)
			{
				if (WindowStarted == true && WindowClosed == false)
				{
					MouseLocation = MGPoint(MouseLocation.X, Value);
					Form::Cursor->Position = MGPointToPoint(MouseLocation);
				}
			}
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
				if (WindowStarted == true && WindowClosed == false)
				{
					WindowTitleDel^ D;
					D = gcnew WindowTitleDel(this, &GWC::WindowTitleExc);
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



		// Window Icon.

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
			};

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
			};

			void set(System::Drawing::Icon^ Value)
			{
				if (WindowStarted == true && WindowClosed == false)
				{
					WindowIconDel^ D;
					D = gcnew WindowIconDel(this, &GWC::WindowIconExc);
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



		// Window Icon Visible.
	
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
				if (WindowStarted == true && WindowClosed == false)
				{
					WindowIconVisibleDel^ D;
					D = gcnew WindowIconVisibleDel(this, &GWC::WindowIconVisibleExc);
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



		// Window Location.

	private:

		delegate void WindowLocationDel(Point Value);

		void WindowLocationExc(Point Value)
		{
			Form::Location = Value;
		}

		MGPoint WindowLocation_;

	public:

		property Point Location
		{
			virtual Point get() sealed
			{
				return Form::Location;
			};

			virtual void set(Point Value) sealed
			{
				this->WindowLocation_ = PointToMGPoint(Value);
				Form::Location = Value;
			}
		}

		property MGPoint WindowLocation
		{
			MGPoint get()
			{
				return WindowLocation_;
			}

			void set(MGPoint Value)
			{
				if (WindowStarted == true && WindowClosed == false)
				{
					WindowLocationDel^ D;
					D = gcnew WindowLocationDel(this, &GWC::WindowLocationExc);
					this->Invoke(D, MGPointToPoint(Value));
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
			this->BackColor = Value;
		}

		MGColor WindowColor_;
		
	public:	

		virtual property Color BackColor
		{
			Color get() override
			{
				return Form::BackColor;
			}

			void set(Color Value) override
			{
				this->WindowColor_ = ColorToMGColor(Value);
				Form::BackColor = Value;
			}
		}

		property MGColor WindowColor
		{
			MGColor get()
			{
				return WindowColor_;
			}

			void set(MGColor Value)
			{
				if (WindowStarted == true && WindowClosed == false)
				{
					WindowColorDel^ D;
					D = gcnew WindowColorDel(this, &GWC::WindowColorExc);
					this->Invoke(D, MGColorToColor(Value));
					this->WindowColor_ = Value;
					delete D;
				}
			}
		}

		void DefaultWindowColor()
		{
			WindowColor = MGColor(240, 240, 240);
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
				if (WindowStarted == true && WindowClosed == false)
				{
					WindowImageDel^ D;
					D = gcnew WindowImageDel(this, &GWC::WindowImageExc);
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



		// Window Size.

	private:

		delegate void WindowSizeDel(System::Drawing::Size Value);

		void WindowSizeExc(System::Drawing::Size Value)
		{
			Form::Size = Value;
		}

		MGSize WindowSize_;

	public:

		property System::Drawing::Size Size
		{
			virtual System::Drawing::Size get() sealed
			{
				return Form::Size;
			};

			virtual void set(System::Drawing::Size Value) sealed
			{
				this->WindowSize_ = SizeToMGSize(Value);
				Form::Size = Value;
			}
		}

		property MGSize WindowSize
		{
			MGSize get()
			{
				return WindowSize_;
			}

			void set(MGSize Value)
			{
				if (WindowStarted == true && WindowClosed == false)
				{
					WindowSizeDel^ D;
					D = gcnew WindowSizeDel(this, &GWC::WindowSizeExc);
					this->Invoke(D, MGSizeToSize(Value));
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

		property System::Drawing::Size ClientSize
		{
			virtual System::Drawing::Size get() sealed
			{
				return Form::ClientSize;
			};

			virtual void set(System::Drawing::Size Value) sealed
			{
				this->WindowRealSize_ = SizeToMGSize(Value);
				Form::ClientSize = Value;
			}
		}

		property MGSize WindowRealSize
		{
			MGSize get()
			{
				return WindowRealSize_;
			}

			void set(MGSize Value)
			{
				if (WindowStarted == true && WindowClosed == false)
				{
					WindowRealSizeDel^ D;
					D = gcnew WindowRealSizeDel(this, &GWC::WindowRealSizeExc);
					this->Invoke(D, MGSizeToSize(Value));
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

		property FormWindowState WindowState
		{
			virtual FormWindowState get() sealed
			{
				return FormWindowState::Normal;
			};

			virtual void set(FormWindowState Value) sealed
			{
				this->WindowSizeState_ = (MGWindowState)Value;
				Form::WindowState = Value;
			}
		}

		property MGWindowState WindowSizeState
		{
			MGWindowState get()
			{
				return WindowSizeState_;
			}

			void set(MGWindowState Value)
			{
				if (WindowStarted == true && WindowClosed == false)
				{
					WindowSizeStateDel^ D;
					D = gcnew WindowSizeStateDel(this, &GWC::WindowSizeStateExc);
					this->Invoke(D, (FormWindowState)Value);
					this->WindowSizeState_ = Value;
					delete D;
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

		virtual property System::Drawing::Size MinimumSize
		{
			System::Drawing::Size get() override
			{
				return Form::MinimumSize;
			}

			void set(System::Drawing::Size Value) override
			{
				this->WindowMinimumSize_ = SizeToMGSize(Value);
				Form::MinimumSize = Value;
			}
		}

		property MGSize WindowMinimumSize
		{
			MGSize get()
			{
				return WindowMinimumSize_;
			}

			void set(MGSize Value)
			{
				if (WindowStarted == true && WindowClosed == false)
				{
					WindowMinimumSizeDel^ D;
					D = gcnew WindowMinimumSizeDel(this, &GWC::WindowMinimumSizeExc);
					this->Invoke(D, MGSizeToSize(Value));
					this->WindowMinimumSize_ = Value;
					delete D;
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

		virtual property System::Drawing::Size MaximumSize
		{
			System::Drawing::Size get() override
			{
				return Form::MaximumSize;
			}

			void set(System::Drawing::Size Value) override
			{
				this->WindowMaximumSize_ = SizeToMGSize(Value);
				Form::MaximumSize = Value;
			}
		}

		property MGSize WindowMaximumSize
		{
			MGSize get()
			{
				return WindowMaximumSize_;
			}

			void set(MGSize Value)
			{
				if (WindowStarted == true && WindowClosed == false)
				{
					WindowMaximumSizeDel^ D;
					D = gcnew WindowMaximumSizeDel(this, &GWC::WindowMaximumSizeExc);
					this->Invoke(D, MGSizeToSize(Value));
					this->WindowMaximumSize_ = Value;
					delete D;
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

		property double Opacity
		{
			virtual double get() sealed
			{
				return Form::Opacity;
			};

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
				if (WindowStarted == true && WindowClosed == false)
				{
					WindowOpacityDel^ D;
					D = gcnew WindowOpacityDel(this, &GWC::WindowOpacityExc);
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



		// Window Always On Top.

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
			};

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
				if (WindowStarted == true && WindowClosed == false)
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



		// Window In Taskbar.

	private:

		delegate void WindowInTaskbarDel(bool Value);

		void WindowInTaskbarExc(bool Value)
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
			};

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
				if (WindowStarted == true && WindowClosed == false)
				{
					WindowInTaskbarDel^ D;
					D = gcnew WindowInTaskbarDel(this, &GWC::WindowInTaskbarExc);
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



		// Window Buttons.

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
				if (WindowStarted == true && WindowClosed == false)
				{
					WindowButtonsDel^ D;
					D = gcnew WindowButtonsDel(this, &GWC::WindowButtonsExc);
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



		// Window Minimize Button.

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
			};

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
				if (WindowStarted == true && WindowClosed == false)
				{
					WindowMinimizeButtonDel^ D;
					D = gcnew WindowMinimizeButtonDel(this, &GWC::WindowMinimizeButtonExc);
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



		// Window Maximize Button.

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
			};

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
				if (WindowStarted == true && WindowClosed == false)
				{
					WindowMaximizeButtonDel^ D;
					D = gcnew WindowMaximizeButtonDel(this, &GWC::WindowMaximizeButtonExc);
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
		void ClearWindow(MGColor Color)
		{
			if (WindowStarted == true && WindowClosed == false)
			{
				Graphics^ G = this->CreateGraphics();
				G->Clear(MGColorToColor(Color));
				delete G;
			}
		}



		// Save Canvas.
		void SaveCanvas()
		{
			if (WindowStarted == true && WindowClosed == false)
			{
				Graphics^ G = this->CreateGraphics();
				this->Canvas = G->Save();
				delete G;
			}
		}



		// Restore Canvas.
		void RestoreCanvas()
		{
			if (WindowStarted == true && WindowClosed == false)
			{
				Graphics^ G = this->CreateGraphics();
				G->Restore(this->Canvas);
				delete G;
			}
		}



		// Draw Pixel.
		void DrawPixel(int X, int Y)
		{
			if (WindowStarted == true && WindowClosed == false)
			{
				Graphics^ G = this->CreateGraphics();
				G->FillRectangle(GcnewSolidBrush, X, Y, 1, 1);
				delete G;
			}
		}



		// Draw Line.
		void DrawLine(int X1, int Y1, int X2, int Y2)
		{
			if (WindowStarted == true && WindowClosed == false)
			{
				Graphics^ G = this->CreateGraphics();
				G->DrawLine(GcnewPen, X1, Y1, X2, Y2);
				delete G;
			}
		}



		// Draw Arc.
		void DrawArc(int X, int Y, int Width, int Height, int A, int B)
		{
			if (WindowStarted == true && WindowClosed == false)
			{
				Graphics^ G = this->CreateGraphics();
				G->DrawArc(GcnewPen, X, Y, Width, Height, A, B);
				delete G;
			}
		}



		// Draw Bezier.
		void DrawBezier(float X1, float Y1, float X2, float Y2, float X3, float Y3, float X4, float Y4)
		{
			if (WindowStarted == true && WindowClosed == false)
			{
				Graphics^ G = this->CreateGraphics();
				G->DrawBezier(GcnewPen, X1, Y1, X2, Y2, X3, Y3, X4, Y4);
				delete G;
			}
		}



		// Draw String.
		void DrawString(String^ S, int X, int Y)
		{
			if (WindowStarted == true && WindowClosed == false)
			{
				Graphics^ G = this->CreateGraphics();
				G->DrawString(S, GcnewFont, gcnew SolidBrush(MGColorToColor(PenColor)), Point(X, Y));
				delete G;
			}
		}



		// Draw Image.
		void DrawImage(Image^ Image, int X, int Y)
		{
			if (WindowStarted == true && WindowClosed == false)
			{
				Graphics^ G = this->CreateGraphics();
				G->DrawImage(Image, X, Y);
				delete G;
			}
		}



		// Draw Image From File.
		void DrawImageFromFile(String^ FileName, int X, int Y)
		{
			try 
			{
				if (WindowStarted == true && WindowClosed == false)
				{			
					Graphics^ G = this->CreateGraphics();
					Image^ Image = Image::FromFile(FileName);
					G->DrawImage(Image, X, Y);
					delete G;
				}
			}
			catch (Exception^ Ex)
			{
				throw Ex;
			}		
		}



		// Draw Icon.
		void DrawIcon(System::Drawing::Icon^ Icon, int X, int Y)
		{
			if (WindowStarted == true && WindowClosed == false)
			{
				Graphics^ G = this->CreateGraphics();
				G->DrawIcon(Icon, X, Y);
				delete G;
			}
		}



		// Draw Icon From File.
		void DrawIconFromFile(String^ FileName, int X, int Y)
		{
			try
			{
				if (WindowStarted == true && WindowClosed == false)
				{
					Graphics^ G = this->CreateGraphics();
					System::Drawing::Icon^ Icon = gcnew System::Drawing::Icon(FileName);
					G->DrawIcon(Icon, X, Y);
					delete G;
				}
			}
			catch (Exception^ Ex)
			{
				throw Ex;
			}
		}



		// Draw Square.
		void DrawSquare(int X, int Y, int L)
		{
			if (WindowStarted == true && WindowClosed == false)
			{
				Graphics^ G = this->CreateGraphics();
				G->DrawRectangle(GcnewPen, X, Y, L, L);
				delete G;
			}
		}



		// Draw Full Square.
		void DrawFullSquare(int X, int Y, int L)
		{
			if (WindowStarted == true && WindowClosed == false)
			{
				Graphics^ G = this->CreateGraphics();
				G->FillRectangle(GcnewSolidBrush, X, Y, L, L);
				delete G;
			}
		}



		// Draw Rectangle.
		void DrawRectangle(int X, int Y, int Width, int Height)
		{
			if (WindowStarted == true && WindowClosed == false)
			{
				Graphics^ G = this->CreateGraphics();
				G->DrawRectangle(GcnewPen, X, Y, Width, Height);
				delete G;
			}
		}



		// Draw Full Rectangle.
		void DrawFullRectangle(int X, int Y, int Width, int Height)
		{
			if (WindowStarted == true && WindowClosed == false)
			{
				Graphics^ G = this->CreateGraphics();
				G->FillRectangle(GcnewSolidBrush, X, Y, Width, Height);
				delete G;
			}
		}



		// Draw Ellipse.
		void DrawEllipse(int X, int Y, int Width, int Height)
		{
			if (WindowStarted == true && WindowClosed == false)
			{
				Graphics^ G = this->CreateGraphics();
				G->DrawEllipse(GcnewPen, X, Y, Width, Height);
				delete G;
			}
		}



		// DrawFullEllipse.
		void DrawFullEllipse(int X, int Y, int Width, int Height)
		{
			if (WindowStarted == true && WindowClosed == false)
			{
				Graphics^ G = this->CreateGraphics();
				G->FillEllipse(GcnewSolidBrush, X, Y, Width, Height);
				delete G;
			}
		}



		// DrawCircle.
		void DrawCircle(int X, int Y, int R)
		{
			if (WindowStarted == true && WindowClosed == false)
			{
				Graphics^ G = this->CreateGraphics();
				G->DrawEllipse(GcnewPen, X - R, Y - R, R * 2, R * 2);
				delete G;
			}
		}



		// DrawFullCircle.
		void DrawFullCircle(int X, int Y, int R)
		{
			if (WindowStarted == true && WindowClosed == false)
			{
				Graphics^ G = this->CreateGraphics();
				G->FillEllipse(GcnewSolidBrush, X - R, Y - R, R * 2, R * 2);
				delete G;
			}
		}



		// Draw Curve.
		void DrawCurve(array<MGPoint>^ Points)
		{
			if (WindowStarted == true && WindowClosed == false)
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
		}



		// Draw Closed Curve.
		void DrawClosedCurve(array<MGPoint>^ Points)
		{
			if (WindowStarted == true && WindowClosed == false)
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
		}



		// Draw Polygon.
		void DrawPolygon(array<MGPoint>^ Points)
		{
			if (WindowStarted == true && WindowClosed == false)
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
		}



		// Draw Full Polygon.
		void DrawFullPolygon(array<MGPoint>^ Points)
		{
			if (WindowStarted == true && WindowClosed == false)
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
		}



		// Draw Pie.
		void DrawPie(int X, int Y, int Width, int Height, int A, int B)
		{
			if (WindowStarted == true && WindowClosed == false)
			{
				Graphics^ G = this->CreateGraphics();
				G->DrawPie(GcnewPen, X, Y, Width, Height, A, B);
				delete G;
			}
		}



		// Draw Full Pie.
		void DrawFullPie(int X, int Y, int Width, int Height, int A, int B)
		{
			if (WindowStarted == true && WindowClosed == false)
			{
				Graphics^ G = this->CreateGraphics();
				G->FillPie(GcnewSolidBrush, X, Y, Width, Height, A, B);
				delete G;
			}
		}


		// Draw From Screen.
		void DrawFromScreen(int X1, int Y1, int X2, int Y2, int Width, int Height)
		{
			if (WindowStarted == true && WindowClosed == false)
			{
				Graphics^ G = this->CreateGraphics();
				G->CopyFromScreen(Point(X1, Y1), Point(X2, Y2), System::Drawing::Size(Width, Height));
				delete G;
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
