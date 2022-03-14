/*
	GWC++ (Graphic Window for Console Application)
	
	- Questo progetto è sotto lincenza MIT (https://mit-license.org)
	- Questo progetto è disponibile su GitHub (https://github.com/reallukee/GWCpp)
	- Maggiori informazioni sono diponibili nel file README.md

	ATUORE:			Realluke
	DESCRIZIONE:	Classe gestita PGWC
	DATA:			14/03/22
*/


#pragma once
#pragma managed


using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;
using namespace System::Threading;
using namespace System::Runtime::InteropServices;
using namespace Microsoft::VisualBasic;


namespace GWCpp
{
	public value struct GPoint
	{
		int X;
		int Y;

		GPoint(int X, int Y)
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


	public value struct GSize
	{
		int W;
		int H;

		GSize(int W, int H)
		{
			if (W >= 0)
			{
				this->W = W;
			}
			else
			{
				this->W = 0;
			}

			if (H >= 0)
			{
				this->H = H;
			}
			else
			{
				this->H = 0;
			}
		}
	};


	public value struct GColor
	{
		int R;
		int G;
		int B;

		GColor(int R, int G, int B)
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


	public enum class GMouseButtons
	{
		None = 0,
		Left = 1048576,
		Right = 2097152,
		Middle = 4194304
	};


	public enum class GWindowState
	{
		Normal = 0,
		Minimized = 1,
		Maximized = 2
	};


	private ref class PGWC : public Form
	{

		/*
			Costruttori e distruttori.
		*/

	public:

		// Costruttori.
		PGWC() : Form()
		{
			InitializeComponent(850, 505, "GWC++ Window", 50, 50);
			GWCThread = gcnew Thread(gcnew ThreadStart(this, &PGWC::InitializeWindow));
			GWCThread->SetApartmentState(ApartmentState::STA);
		}

		PGWC(int W, int H) : Form()
		{
			InitializeComponent(W, H, "GWC++ Window", 50, 50);
			GWCThread = gcnew Thread(gcnew ThreadStart(this, &PGWC::InitializeWindow));
			GWCThread->SetApartmentState(ApartmentState::STA);
		}

		PGWC(int W, int H, String^ Title) : Form()
		{
			InitializeComponent(W, H, Title, 50, 50);
			GWCThread = gcnew Thread(gcnew ThreadStart(this, &PGWC::InitializeWindow));
			GWCThread->SetApartmentState(ApartmentState::STA);
		}

		PGWC(int W, int H, String^ Title, int X, int Y) : Form()
		{
			InitializeComponent(W, H, Title, X, Y);
			GWCThread = gcnew Thread(gcnew ThreadStart(this, &PGWC::InitializeWindow));
			GWCThread->SetApartmentState(ApartmentState::STA);
		}

		// Distruttore.
		~PGWC()
		{
			if (Components)
			{
				delete Components;
			}
		}



	private:

		// Abilitazione del designer di Visual Studio.
		System::ComponentModel::Container^ Components;

		// Thread della finestra.
		Thread^ GWCThread;

		// Canvas.
		System::Drawing::Drawing2D::GraphicsState^ Canvas;

		// Inizializzatore componenti.
		void InitializeComponent(int W, int H, String^ Title, int X, int Y)
		{
			// Abilitazione del designer di Visual Studio.
			this->Components = gcnew System::ComponentModel::Container();

			// Sospensione layout.
			this->SuspendLayout();

			// Proprietà finestra.
			this->WindowStarted = false;
			this->WindowClosed = true;
			Form::Text = Title;
			Form::Icon = nullptr;
			Form::ShowIcon = false;
			Form::Location = System::Drawing::Point(X, Y);
			Form::BackColor = Color::FromArgb(240, 240, 240);
			Form::BackgroundImage = nullptr;
			Form::Size = System::Drawing::Size(W, H);
			Form::ClientSize = System::Drawing::Size(W, H);
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

			// Eventi finestra.
			this->MouseDown += gcnew MouseEventHandler(this, &PGWC::GWC_MouseDown);
			this->MouseUp += gcnew MouseEventHandler(this, &PGWC::GWC_MouseUp);
			this->KeyDown += gcnew KeyEventHandler(this, &PGWC::GWC_KeyDown);
			this->KeyUp += gcnew KeyEventHandler(this, &PGWC::GWC_KeyUp);

			// Ripresa layout.
			this->ResumeLayout(false);
		}

		// Inizializzatore finestra.
		void InitializeWindow()
		{
			Application::EnableVisualStyles();
			Application::SetCompatibleTextRenderingDefault(false);
			Application::Run(this);
		}



		/*
			Metodi finestra.
		*/

	public:

		// Start Window.
		void StartWindow()
		{
			GWCThread->Start();
			GWCThread->Sleep(50);
			WindowStarted = true;
		}

		// Close Window.
		void CloseWindow()
		{
			GWCThread->Sleep(50);
			GWCThread->Abort();
			WindowClosed = true;
		}

		// Suspend Window.
		void SuspendWindow()
		{
			GWCThread->Sleep(10);
			GWCThread->Suspend();
		}

		// Resume Window.
		void ResumeWindow()
		{
			GWCThread->Sleep(10);
			GWCThread->Resume();
		}

		// Get Max X.
		int GetMaxX()
		{
			return Form::Size.Width - 1;
		}

		// Get Real Max X.
		int GetRealMaxX()
		{
			return Form::ClientSize.Width - 1;
		}

		// Get Max Y.
		int GetMaxY()
		{
			return Form::Size.Height - 1;
		}

		// Get Real Max Y.
		int GetRealMaxY()
		{
			return Form::ClientSize.Height - 1;
		}



		// Show Window.

	private:

		delegate void ShowWindowD();

		void ShowWindowT() 
		{ 
			this->Show(); 
		}

	public:

		void Show()
		{
			Form::Show();
		}

		void ShowWindow()
		{
			ShowWindowD^ D;
			D = gcnew ShowWindowD(this, &PGWC::ShowWindowT);
			this->Invoke(D);
			delete D;
		}



		// Hide Window.

	private:

		delegate void HideWindowD();
		
		void HideWindowT() 
		{ 
			this->Hide(); 
		}

	public:

		void Hide()
		{
			Form::Hide();
		}

		void HideWindow()
		{
			HideWindowD^ D;
			D = gcnew HideWindowD(this, &PGWC::HideWindowT);
			this->Invoke(D);
			delete D;
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



		// Window Title.

	private:

		delegate void WindowTitleD(String^ Value);
		
		void WindowTitleT(String^ Value) 
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
				WindowTitleD^ D;
				D = gcnew WindowTitleD(this, &PGWC::WindowTitleT);
				this->Invoke(D, Value);
				this->WindowTitle_ = Value;
				delete D;
			}
		}



		// Window Icon.

	private:

		delegate void WindowIconD(System::Drawing::Icon^ Value);

		void WindowIconT(System::Drawing::Icon^ Value) 
		{ 
			Form::Icon = Value; 
		}

		System::Drawing::Icon^ WindowIcon_;

	public:

		property System::Drawing::Icon^ Icon
		{
			virtual System::Drawing::Icon^ get() sealed 
			{ 
				return nullptr; 
			};

			virtual void set(System::Drawing::Icon^ Value) sealed 
			{ 
				return; 
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
				WindowIconD^ D;
				D = gcnew WindowIconD(this, &PGWC::WindowIconT);
				this->Invoke(D, Value);
				this->WindowIcon_ = Value;
				delete D;
			}
		}



		// Window Icon Visible.

	private:

		delegate void WindowIconVisibleD(bool Value);
		
		void WindowIconVisibleT(bool Value) 
		{ 
			Form::ShowIcon = Value; 
		}
		
		bool WindowIconVisible_;

	public:

		property bool ShowIcon
		{
			virtual bool get() 
			{ 
				return false; 
			}
			
			virtual void set(bool value) 
			{ 
				return; 
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
				WindowIconVisibleD^ D;
				D = gcnew WindowIconVisibleD(this, &PGWC::WindowIconVisibleT);
				this->Invoke(D, Value);
				this->WindowIconVisible_ = Value;
				delete D;
			}
		}



		// Window Location.

	private:

		delegate void WindowLocationD(Point Value);
		
		void WindowLocationT(Point Value) 
		{ 
			Form::Location = Value; 
		}
		
		GPoint WindowLocation_;

	public:

		property Point Location
		{
			virtual Point get() sealed 
			{ 
				return Point(0, 0); 
			};

			virtual void set(Point Value) sealed 
			{ 
				return; 
			}
		}

		property GPoint WindowLocation
		{
			GPoint get() 
			{ 
				return WindowLocation_; 
			}

			void set(GPoint Value)
			{
				WindowLocationD^ D;
				D = gcnew WindowLocationD(this, &PGWC::WindowLocationT);
				this->Invoke(D, gcnew Point(Value.X, Value.Y));
				this->WindowLocation_ = Value;
				delete D;
			}
		}



		// Window Color.

	private:

		delegate void WindowColorD(Color Value);
		
		void WindowColorT(Color Value) 
		{ 
			Form::BackColor = Value; 
		}
		
		GColor WindowColor_;

	public:

		virtual property Color BackColor
		{
			Color get() override 
			{ 
				return Form::BackColor; 
			
			}
			void set(Color Value) override 
			{ 
				Form::BackColor = Value; 
			}
		}

		property GColor WindowColor
		{
			GColor get() 
			{ 
				return WindowColor_; 
			}

			void set(GColor Value)
			{
				WindowColorD^ D;
				D = gcnew WindowColorD(this, &PGWC::WindowColorT);
				this->Invoke(D, Color::FromArgb(Value.R, Value.G, Value.B));
				this->WindowColor_ = Value;
				delete D;
			}
		}



		// Window Image.

	private:

		delegate void WindowImageD(Image^ Value);
		
		void WindowImageT(Image^ Value) 
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
				WindowImageD^ D;
				D = gcnew WindowImageD(this, &PGWC::WindowImageT);
				this->Invoke(D, Value);
				this->WindowImage_ = Value;
				delete D;
			}
		}



		// Window Size.

	private:

		delegate void WindowSizeD(System::Drawing::Size Value);
		
		void WindowSizeT(System::Drawing::Size Value) 
		{ 
			Form::Size = Value; 
		}

		GSize WindowSize_;

	public:

		property System::Drawing::Size Size
		{
			virtual System::Drawing::Size get() sealed 
			{ 
				return System::Drawing::Size(0, 0); 
			};

			virtual void set(System::Drawing::Size Value) sealed 
			{ 
				return; 
			}
		}

		property GSize WindowSize
		{
			GSize get()
			{ 
				return WindowSize_; 
			}

			void set(GSize Value)
			{
				WindowSizeD^ D;
				D = gcnew WindowSizeD(this, &PGWC::WindowSizeT);
				this->Invoke(D, gcnew System::Drawing::Size(Value.W, Value.H));
				this->WindowSize_ = Value;
				delete D;
			}
		}



		// Window Real Size.

	private:

		delegate void WindowRealSizeD(System::Drawing::Size Value);

		void WindowRealSizeT(System::Drawing::Size Value)
		{
			Form::ClientSize = Value;
		}

		GSize WindowRealSize_;

	public:

		property System::Drawing::Size ClientSize
		{
			virtual System::Drawing::Size get() sealed
			{
				return System::Drawing::Size(0, 0);
			};

			virtual void set(System::Drawing::Size Value) sealed
			{
				return;
			}
		}

		property GSize WindowRealSize
		{
			GSize get()
			{
				return WindowRealSize_;
			}

			void set(GSize Value)
			{
				WindowRealSizeD^ D;
				D = gcnew WindowRealSizeD(this, &PGWC::WindowRealSizeT);
				this->Invoke(D, gcnew System::Drawing::Size(Value.W, Value.H));
				this->WindowRealSize_ = Value;
				delete D;
			}
		}



		// Window Size State.
	
	private:

		delegate void WindowSizeStateD(FormWindowState Value);

		void WindowSizeStateT(FormWindowState Value)
		{
			Form::WindowState = Value;
		}

		GWindowState WindowSizeState_;

	public:

		property FormWindowState WindowState
		{
			virtual FormWindowState get() sealed
			{
				return FormWindowState::Normal;
			};

			virtual void set(FormWindowState Value) sealed
			{
				return;
			}
		}

		property GWindowState WindowSizeState
		{
			GWindowState get()
			{
				return WindowSizeState_;
			}

			void set(GWindowState Value)
			{
				WindowSizeStateD^ D;
				D = gcnew WindowSizeStateD(this, &PGWC::WindowSizeStateT);
				this->Invoke(D, (FormWindowState)Value);
				this->WindowSizeState_ = Value;
				delete D;
			}
		}



		// Window Minimum Size.

	private:

		delegate void WindowMinimumSizeD(System::Drawing::Size Value);

		void WindowMinimumSizeT(System::Drawing::Size Value) 
		{ 
			Form::MinimumSize = Value; 
		}

		GSize WindowMinimumSize_;

	public:

		virtual property System::Drawing::Size MinimumSize
		{
			System::Drawing::Size get() override 
			{ 
				return Form::MinimumSize; 
			}

			void set(System::Drawing::Size Value) override 
			{ 
				Form::MinimumSize = Value; 
			}
		}

		property GSize WindowMinimumSize
		{
			GSize get() 
			{ 
				return WindowMinimumSize_; 
			}

			void set(GSize Value)
			{
				WindowMinimumSizeD^ D;
				D = gcnew WindowMinimumSizeD(this, &PGWC::WindowMinimumSizeT);
				this->Invoke(D, System::Drawing::Size(Value.W, Value.H));
				this->WindowMinimumSize_ = Value;
				delete D;
			}
		}



		// Window Maximum Size.

	private:

		delegate void WindowMaximumSizeD(System::Drawing::Size Value);

		void WindowMaximumSizeT(System::Drawing::Size Value) 
		{ 
			Form::MaximumSize = Value; 
		}

		GSize WindowMaximumSize_;

	public:

		virtual property System::Drawing::Size MaximumSize
		{
			System::Drawing::Size get() override 
			{ 
				return Form::MaximumSize; 
			}

			void set(System::Drawing::Size Value) override 
			{ 
				Form::MaximumSize = Value; 
			}
		}

		property GSize WindowMaximumSize
		{
			GSize get() 
			{ 
				return WindowMaximumSize_; 
			}

			void set(GSize Value)
			{
				WindowMaximumSizeD^ D;
				D = gcnew WindowMaximumSizeD(this, &PGWC::WindowMaximumSizeT);
				this->Invoke(D, System::Drawing::Size(Value.W, Value.H));
				this->WindowMaximumSize_ = Value;
				delete D;
			}
		}



		// Window Opacity.

	private:

		delegate void WindowOpacityD(double Value);
		
		void WindowOpacityT(double Value) 
		{ 
			Form::Opacity = Value; 
		}

		double WindowOpacity_;

	public:

		property double Opacity
		{
			virtual double get() sealed 
			{ 
				return 1.00; 
			};

			virtual void set(double Value) sealed 
			{ 
				return;
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
				WindowOpacityD^ D;
				D = gcnew WindowOpacityD(this, &PGWC::WindowOpacityT);
				this->Invoke(D, Value);
				this->WindowOpacity_ = Value;
				delete D;
			}
		}



		// Window Always On Top.

	private:

		delegate void WindowAlwaysOnTopD(bool Value);
		
		void WindowAlwaysOnTopT(bool Value) 
		{ 
			Form::TopMost = Value; 
		}

		bool WindowAlwaysOnTop_;

	public:

		property bool TopMost
		{
			virtual bool get() sealed 
			{ 
				return false; 
			};

			virtual void set(bool Value) sealed 
			{ 
				return; 
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
				WindowAlwaysOnTopD^ D;
				D = gcnew WindowAlwaysOnTopD(this, &PGWC::WindowAlwaysOnTopT);
				this->Invoke(D, Value);
				this->WindowAlwaysOnTop_ = Value;
				delete D;
			}
		}



		// Window In Taskbar.

	private:

		delegate void WindowInTaskbarD(bool Value);
		void WindowInTaskbarT(bool Value) { Form::ShowInTaskbar; }
		bool WindowInTaskbar_;

	public:

		property bool ShowInTaskbar
		{
			virtual bool get() sealed { return false; };
			virtual void set(bool Value) sealed { return; }
		}

		property bool WindowInTaskbar
		{
			bool get() { return WindowInTaskbar_; }

			void set(bool Value)
			{
				WindowInTaskbarD^ D;
				D = gcnew WindowInTaskbarD(this, &PGWC::WindowInTaskbarT);
				this->Invoke(D, Value);
				this->WindowInTaskbar_ = Value;
				delete D;
			}
		}



		// Window Buttons.
	
	private:

		delegate void WindowButtonsD(bool Value);

		void WindowButtonsT(bool Value)
		{
			Form::ControlBox = Value;
		}

		bool WindowButtons_;

	public:

		property bool ControlBox
		{
			virtual bool get() sealed { return false; }
			virtual void set(bool Value) sealed { return; }
		}

		property bool WindowButtons
		{
			bool get() 
			{
				return WindowButtons_;
			}

			void set(bool Value)
			{
				WindowButtonsD^ D;
				D = gcnew WindowButtonsD(this, &PGWC::WindowButtonsT);
				this->Invoke(D, Value);
				this->WindowButtons_ = Value;
				delete D;
			}
		}



		// Window Minimize Button.

	private:

		delegate void WindowMinimizeButtonD(bool Value);

		void WindowMinimizeButtonT(bool Value) 
		{ 
			Form::MinimizeBox = Value; 
		}

		bool WindowMinimizeButton_;

	public:

		property bool MinimizeBox
		{
			virtual bool get() sealed 
			{ 
				return false; 
			};

			virtual void set(bool Value) sealed 
			{ 
				return; 
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
				WindowMinimizeButtonD^ D;
				D = gcnew WindowMinimizeButtonD(this, &PGWC::WindowMinimizeButtonT);
				this->Invoke(D, Value);
				this->WindowMinimizeButton_ = Value;
				delete D;
			}
		}



		// Window Maximize Button.
		
	private:

		delegate void WindowMaximizeButtonD(bool Value);
		
		void WindowMaximizeButtonT(bool Value) 
		{
			Form::MaximizeBox = Value; 
		}

		bool WindowMaximizeButton_;

	public:

		property bool MaximizeBox
		{
			virtual bool get() sealed 
			{ 
				return false;
			};

			virtual void set(bool Value) sealed 
			{ 
				return;
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
				WindowMaximizeButtonD^ D;
				D = gcnew WindowMaximizeButtonD(this, &PGWC::WindowMaximizeButtonT);
				this->Invoke(D, Value);
				this->WindowMaximizeButton_ = Value;
				delete D;
			}
		}



		/*
			Proprietà disegno.
		*/

		// Pen Color.

	private:

		GColor PenColor_;

	public:

		void DefaultPenColor() 
		{ 
			PenColor_ = GColor(0, 0, 0);
		}

		property GColor PenColor
		{
			GColor get() 
			{ 
				return PenColor_; 
			}

			void set(GColor Value) 
			{	
				PenColor_ = Value; 
			}
		}



		// Pen Width.

	private:
		
		float PenWidth_;

	public:

		void DefaultPenWidth() 
		{ 
			PenWidth = 2.5F; 
		}

		property float PenWidth
		{ 
			float get() 
			{ 
				return PenWidth_;	
			}

			void set(float Value) 
			{ 
				PenWidth_ = Value; 
			}
		}



		// Fill Color.

	private:

		GColor FillColor_;

	public:

		void DefaultFillColor() 
		{ 
			FillColor = GColor(0, 0, 0);
		}

		property GColor FillColor
		{
			GColor get() 
			{ 
				return FillColor_;
			}

			void set(GColor Value) 
			{ 
				FillColor_ = Value;
			}
		}



		// Font Name.

	private:

		String^ FontName_;

	public:

		void DefaultFontName() 
		{ 
			FontName = "Comic Sans"; 
		}

		property String^ FontName
		{
			String^ get() 
			{ 
				return FontName_; 
			}

			void set(String^ Value) 
			{ 
				FontName_ = Value;
			}
		}



		// Font Size.

	private:

		float FontSize_;

	public:

		void DefaultFontSize() 
		{ 
			FontSize = 15.0F; 
		}

		property float FontSize
		{
			float get() 
			{ 
				return FontSize_; 
			}

			void set(float Value) 
			{ 
				FontSize_ = Value; 
			}
		}



		/*
			Metodi disegno.
		*/

	public:

		// Clear Window.
		void ClearWindow()
		{
			Graphics^ G = this->CreateGraphics();
			G->Clear(Color::FromArgb(WindowColor.R, WindowColor.G, WindowColor.B));
			delete G;
		}

		// Save Canvas.
		void SaveCanvas()
		{
			Graphics^ G = this->CreateGraphics();
			this->Canvas = G->Save();
			delete G;
		}

		// Restore Canvas.
		void RestoreCanvas()
		{
			Graphics^ G = this->CreateGraphics();
			G->Restore(this->Canvas);
			delete G;
		}

		// Draw Pixel.
		void DrawPixel(int X, int Y)
		{
			Graphics^ G = this->CreateGraphics();
			G->FillRectangle(gcnew SolidBrush(Color::FromArgb(FillColor.R, FillColor.G, FillColor.B)), X, Y, 1, 1);
			delete G;
		}

		// Draw Line.
		void DrawLine(int X1, int Y1, int X2, int Y2)
		{
			Graphics^ G = this->CreateGraphics();
			G->DrawLine(gcnew Pen(Color::FromArgb(PenColor.R, PenColor.G, PenColor.B), PenWidth), X1, Y1, X2, Y2);
			delete G;
		}

		// Draw Arc.
		void DrawArc(int X, int Y, int W, int H, int A, int B)
		{
			Graphics^ G = this->CreateGraphics();
			G->DrawArc(gcnew Pen(Color::FromArgb(PenColor.R, PenColor.G, PenColor.B), PenWidth), X, Y, W, H, A, B);
			delete G;
		}

		// Draw Bezier.
		void DrawBezier(float X1, float Y1, float X2, float Y2, float X3, float Y3, float X4, float Y4)
		{
			Graphics^ G = this->CreateGraphics();
			G->DrawBezier(gcnew Pen(Color::FromArgb(PenColor.R, PenColor.G, PenColor.B), PenWidth), X1, Y1, X2, Y2, X3, Y3, X4, Y4);
			delete G;
		}

		// Draw String.
		void DrawString(String^ S, int X, int Y)
		{
			Graphics^ G = this->CreateGraphics();
			G->DrawString(S, gcnew System::Drawing::Font(FontName, FontSize), gcnew SolidBrush(Color::FromArgb(PenColor.R, PenColor.G, PenColor.B)), Point(X, Y));
			delete G;
		}

		// Draw Image.
		void DrawImage(Image^ I, int X, int Y)
		{
			Graphics^ G = this->CreateGraphics();
			G->DrawImage(I, X, Y);
			delete G;
		}

		// Draw Image From File.
		void DrawImageFromFile(String^ F, int X, int Y)
		{
			Graphics^ G = this->CreateGraphics();

			try
			{
				Image^ I = Image::FromFile(F);
				G->DrawImage(I, X, Y);
			}
			catch (Exception^ Ex)
			{
				throw Ex;
			}
			
			delete G;
		}

		// Draw Icon.
		void DrawIcon(System::Drawing::Icon^ I, int X, int Y)
		{
			Graphics^ G = this->CreateGraphics();
			G->DrawIcon(I, X, Y);
			delete G;
		}

		// Draw Icon From File.
		void DrawIconFromFile(String^ F, int X, int Y)
		{
			Graphics^ G = this->CreateGraphics();

			try
			{
				System::Drawing::Icon^ I = gcnew System::Drawing::Icon(F);
				G->DrawIcon(I, X, Y);
			}
			catch (Exception^ Ex)
			{
				throw Ex;
			}

			delete G;
		}

		// Draw Square.
		void DrawSquare(int X, int Y, int L)
		{
			Graphics^ G = this->CreateGraphics();
			G->DrawRectangle(gcnew Pen(Color::FromArgb(PenColor.R, PenColor.G, PenColor.B), PenWidth), X, Y, L, L);
			delete G;
		}

		// Draw Full Square.
		void DrawFullSquare(int X, int Y, int L)
		{
			Graphics^ G = this->CreateGraphics();
			G->FillRectangle(gcnew SolidBrush(Color::FromArgb(FillColor.R, FillColor.G, FillColor.B)), X, Y, L, L);
			delete G;
		}

		// Draw Rectangle.
		void DrawRectangle(int X, int Y, int W, int H)
		{
			Graphics^ G = this->CreateGraphics();
			G->DrawRectangle(gcnew Pen(Color::FromArgb(PenColor.R, PenColor.G, PenColor.B), PenWidth), X, Y, W, H);
			delete G;
		}

		// Draw Full Rectangle.
		void DrawFullRectangle(int X, int Y, int W, int H)
		{
			Graphics^ G = this->CreateGraphics();
			G->FillRectangle(gcnew SolidBrush(Color::FromArgb(FillColor.R, FillColor.G, FillColor.B)), X, Y, W, H);
			delete G;
		}

		// Draw Ellipse.
		void DrawEllipse(int X, int Y, int W, int H)
		{
			Graphics^ G = this->CreateGraphics();
			G->DrawEllipse(gcnew Pen(Color::FromArgb(PenColor.R, PenColor.G, PenColor.B), PenWidth), X, Y, W, H);
			delete G;
		}

		// Draw Full Ellipse.
		void DrawFullEllipse(int X, int Y, int W, int H)
		{
			Graphics^ G = this->CreateGraphics();
			G->FillEllipse(gcnew SolidBrush(Color::FromArgb(FillColor.R, FillColor.G, FillColor.B)), X, Y, W, H);
			delete G;
		}

		// Draw Circle.
		void DrawCircle(int X, int Y, int R)
		{
			Graphics^ G = this->CreateGraphics();
			G->DrawEllipse(gcnew Pen(Color::FromArgb(PenColor.R, PenColor.G, PenColor.B), PenWidth), X - R, Y - R, R * 2, R * 2);
			delete G;
		}

		// Draw Full Circle.
		void DrawFullCircle(int X, int Y, int R)
		{
			Graphics^ G = this->CreateGraphics();
			G->FillEllipse(gcnew SolidBrush(Color::FromArgb(FillColor.R, FillColor.G, FillColor.B)), X - R, Y - R, R * 2, R * 2);
			delete G;
		}

		// Draw Curve.
		void DrawCurve(array<Point>^ P)
		{
			Graphics^ G = this->CreateGraphics();
			G->DrawCurve(gcnew Pen(Color::FromArgb(PenColor.R, PenColor.G, PenColor.B), PenWidth), P);
			delete G;
		}

		// Draw Closed Curve.
		void DrawClosedCurve(array<Point>^ P)
		{
			Graphics^ G = this->CreateGraphics();
			G->DrawClosedCurve(gcnew Pen(Color::FromArgb(PenColor.R, PenColor.G, PenColor.B), PenWidth), P);
			delete G;
		}

		// Draw Polygon.
		void DrawPolygon(array<Point>^ P)
		{
			Graphics^ G = this->CreateGraphics();
			G->DrawPolygon(gcnew Pen(Color::FromArgb(PenColor.R, PenColor.G, PenColor.B), PenWidth), P);
			delete G;
		}

		// Draw Full Polygon.
		void DrawFullPolygon(array<Point>^ P)
		{
			Graphics^ G = this->CreateGraphics();
			G->FillPolygon(gcnew SolidBrush(Color::FromArgb(FillColor.R, FillColor.G, FillColor.B)), P);
			delete G;
		}

		// Draw Pie.
		void DrawPie(int X, int Y, int W, int H, int A, int B)
		{
			Graphics^ G = this->CreateGraphics();
			G->DrawPie(gcnew Pen(Color::FromArgb(PenColor.R, PenColor.G, PenColor.B), PenWidth), X, Y, W, H, A, B);
			delete G;
		}

		// Draw Full Pie.
		void DrawFullPie(int X, int Y, int W, int H, int A, int B)
		{
			Graphics^ G = this->CreateGraphics();
			G->FillPie(gcnew SolidBrush(Color::FromArgb(FillColor.R, FillColor.G, FillColor.B)), X, Y, W, H, A, B);
			delete G;
		}

		// Draw From Screen.
		void DrawFromScreen(int X1, int Y1, int X2, int Y2, int W, int H)
		{
			Graphics^ G = this->CreateGraphics();
			G->CopyFromScreen(Point(X1, Y1), Point(X2, Y2), System::Drawing::Size(W, H));
			delete G;
		}



		/*
			Metodi evento.
		*/

		// Mouse Down.

	private:

		bool MouseDownPending;
		Point MouseDownPoint;
		GMouseButtons MouseDownButton;

		void GWC_MouseDown(Object^ Sender, MouseEventArgs^ E)
		{
			if (MouseDownPending == false)
			{
				return;
			}

			switch (E->Button)
			{
			case System::Windows::Forms::MouseButtons::Left:
				MouseDownPoint = Point(E->X, E->Y);
				MouseDownPending = false;
				break;

			case System::Windows::Forms::MouseButtons::Right:
				MouseDownPoint = Point(E->X, E->Y);
				MouseDownPending = false;
				break;

			case System::Windows::Forms::MouseButtons::Middle:
				MouseDownPoint = Point(E->X, E->Y);
				MouseDownPending = false;
				break;

			case System::Windows::Forms::MouseButtons::None:
				MouseDownPoint = Point(E->X, E->Y);
				MouseDownPending = false;
				break;

			default:
				break;
			}
		}

	public:

		Point RequestMouseDown(GMouseButtons B)
		{
			MouseDownPending = true;
			MouseDownButton = B;

			while (MouseDownPending)
			{
				GWCThread->Sleep(10);
			}

			return MouseDownPoint;
		}

		Point RequestMouseDown()
		{
			MouseDownPending = true;
			MouseDownButton = GMouseButtons::None;

			while (MouseDownPending)
			{
				GWCThread->Sleep(10);
			}

			return MouseDownPoint;
		}



		// Mouse Up.

	private:

		bool MouseUpPending;
		Point MouseUpPoint;
		GMouseButtons MouseUpButton;

		void GWC_MouseUp(Object^ Sender, MouseEventArgs^ E)
		{
			if (MouseUpPending == false)
			{
				return;
			}

			switch (E->Button)
			{
			case System::Windows::Forms::MouseButtons::Left:
				MouseUpPoint = Point(E->X, E->Y);
				MouseUpPending = false;
				break;

			case System::Windows::Forms::MouseButtons::Right:
				MouseUpPoint = Point(E->X, E->Y);
				MouseUpPending = false;
				break;

			case System::Windows::Forms::MouseButtons::Middle:
				MouseUpPoint = Point(E->X, E->Y);
				MouseUpPending = false;
				break;

			case System::Windows::Forms::MouseButtons::None:
				MouseUpPoint = Point(E->X, E->Y);
				MouseUpPending = false;
				break;

			default:
				break;
			}
		}

	public:

		Point RequestMouseUp(GMouseButtons B)
		{
			MouseUpPending = true;
			MouseUpButton = B;

			while (MouseUpPending)
			{
				GWCThread->Sleep(10);
			}

			return MouseUpPoint;
		}

		Point RequestMouseUp()
		{
			MouseUpPending = true;
			MouseUpButton = GMouseButtons::None;

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

	};
}
