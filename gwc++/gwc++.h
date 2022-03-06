#pragma once
#pragma managed


#using <System.dll>
#using <System.ComponentModel.dll>
#using <System.Collections.dll>
#using <System.Windows.Forms.dll>
#using <System.Data.dll>
#using <System.Drawing.dll>
#using <System.Threading.dll>
#using <System.Runtime.InteropServices.dll>
#using <Microsoft.VisualBasic.dll>


namespace GWCpp
{
	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Threading;
	using namespace System::Runtime::InteropServices;
	using namespace Microsoft::VisualBasic;


	public ref class GWC : public Form
	{

		/*
			Costruttori e distruttori.
		*/

	public:

		// Costruttore.
		GWC(int W, int H, String^ Title, int X, int Y) : Form()
		{
			InitializeComponent(W, H, Title, X, Y);
			GWCThread = gcnew Thread(gcnew ThreadStart(this, &GWC::InitializeWindow));
			GWCThread->SetApartmentState(ApartmentState::STA);
		}

		// Distruttore.
		~GWC()
		{
			
		}



	private:

		// Thread finestra.
		Thread^ GWCThread;

		// Indicatore chiamata.
		bool CalledByMe = false;

		// Inizializzatore componenti.
		void InitializeComponent(int W, int H, String^ Title, int X, int Y)
		{
			// Sospensione layout.
			this->SuspendLayout();

			// Imposto 'CalledByMe' su 'true'.
			CalledByMe = true;

			// Proprietà finestra.
			Form::Text = Title;
			Form::Icon = nullptr;
			Form::Location = System::Drawing::Point(X, Y);
			Form::BackColor = Color::Gainsboro;
			Form::BackgroundImage = nullptr;
			Form::Size = System::Drawing::Size(W, H);
			Form::MinimumSize = System::Drawing::Size(0, 0);
			Form::MaximumSize = System::Drawing::Size(0, 0);
			Form::Opacity = 1.00;
			Form::TopMost = false;
			Form::ShowInTaskbar = true;
			Form::MinimizeBox = true;
			Form::MaximizeBox = true;

			// Proprietà disegno.
			this->DefaultPenColor();
			this->DefaultPenWidth();
			this->DefaultFillColor();
			this->DefaultFontName();
			this->DefaultFontSize();

			// Eventi finestra.
			this->MouseDown += gcnew MouseEventHandler(this, &GWC::GWC_MouseDown);
			this->MouseUp += gcnew MouseEventHandler(this, &GWC::GWC_MouseUp);
			this->KeyDown += gcnew KeyEventHandler(this, &GWC::GWC_KeyDown);
			this->KeyUp += gcnew KeyEventHandler(this, &GWC::GWC_KeyUp);

			// Imposto 'CalledByMe' su 'false'.
			CalledByMe = false;

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
		}

		// Close Window.
		void CloseWindow()
		{
			GWCThread->Sleep(50);
			GWCThread->Abort();
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



		// Show Window.

	private:

		delegate void ShowWindowD();
		void ShowWindowT() { this->Show(); }

	public:

		void Show()
		{
			if (CalledByMe == false)
			{
				throw gcnew NotSupportedException();
			}

			Form::Show();
			CalledByMe = false;
		}

		void ShowWindow()
		{
			ShowWindowD^ D;
			D = gcnew ShowWindowD(this, &GWC::ShowWindowT);
			CalledByMe = true;
			this->Invoke(D);
			delete D;
		}



		// Hide Window.

	private:

		delegate void HideWindowD();
		void HideWindowT() { this->Hide(); }

	public:

		void Hide()
		{
			if (CalledByMe == false)
			{
				throw gcnew NotSupportedException();
			}

			Form::Hide();
			CalledByMe = false;
		}

		void HideWindow()
		{
			HideWindowD^ D;
			D = gcnew HideWindowD(this, &GWC::HideWindowT);
			CalledByMe = true;
			this->Invoke(D);
			delete D;
		}



		// Window Title.

	private:

		delegate void WindowTitleD(String^ Value);
		void WindowTitleT(String^ Value) { this->Text = Value; }
		String^ WindowTitle_;

	public:

		virtual property String^ Text
		{
			String^ get() override { return Form::Text; }
			void set(String^ Value) override { Form::Text = Value; }
		}

		property String^ WindowTitle
		{
			String^ get() { return WindowTitle_; }

			void set(String^ Value)
			{
				WindowTitleD^ D;
				D = gcnew WindowTitleD(this, &GWC::WindowTitleT);
				this->Invoke(D, Value);
				this->WindowTitle_ = Value;
				delete D;
			}
		}



		// Window Icon.

	private:

		delegate void WindowIconD(System::Drawing::Icon^ Value);
		void WindowIconT(System::Drawing::Icon^ Value) { Form::Icon = Value; }
		System::Drawing::Icon^ WindowIcon_;

	public:

		property System::Drawing::Icon^ Icon
		{
			virtual System::Drawing::Icon^ get() sealed { return nullptr; };
			virtual void set(System::Drawing::Icon^ Value) sealed { return; }
		}

		property System::Drawing::Icon^ WindowIcon
		{
			System::Drawing::Icon^ get() { return WindowIcon_; };

			void set(System::Drawing::Icon^ Value)
			{
				WindowIconD^ D;
				D = gcnew WindowIconD(this, &GWC::WindowIconT);
				this->Invoke(D, Value);
				this->WindowIcon_ = Value;
				delete D;
			}
		}



		// Window Location.

	private:

		delegate void WindowLocationD(Point Value);
		void WindowLocationT(Point Value) { Form::Location = Value; }
		Point WindowLocation_;

	public:

		property Point Location
		{
			virtual Point get() sealed { return Point(0, 0); };
			virtual void set(Point Value) sealed { return; }
		}

		property Point WindowLocation
		{
			Point get() { return WindowLocation_; }

			void set(Point Value)
			{
				WindowLocationD^ D;
				D = gcnew WindowLocationD(this, &GWC::WindowLocationT);
				this->Invoke(D, Value);
				this->WindowLocation_ = Value;
				delete D;
			}
		}



		// Window Color.

	private:

		delegate void WindowColorD(Color Value);
		void WindowColorT(Color Value) { Form::BackColor = Value; }
		Color WindowColor_;

	public:

		virtual property Color BackColor
		{
			Color get() override { return Form::BackColor; }
			void set(Color Value) override { Form::BackColor = Value; }
		}

	public:
		property Color WindowColor
		{
			Color get() { return WindowColor_; }

			void set(Color Value)
			{
				WindowColorD^ D;
				D = gcnew WindowColorD(this, &GWC::WindowColorT);
				CalledByMe = true;
				this->Invoke(D, Value);
				this->WindowColor_ = Value;
				delete D;
			}
		}



		// Window Image.

	private:

		delegate void WindowImageD(Image^ Value);
		void WindowImageT(Image^ Value) { Form::BackgroundImage = Value; }
		Image^ WindowImage_;

	public:

		virtual property Image^ BackgroundImage
		{
			Image^ get() override { return Form::BackgroundImage; }
			void set(Image^ Value) override { Form::BackgroundImage = Value; }
		}

		property Image^ WindowImage
		{
			Image^ get() { return WindowImage_; }

			void set(Image^ Value)
			{
				WindowImageD^ D;
				D = gcnew WindowImageD(this, &GWC::WindowImageT);
				this->Invoke(D, Value);
				this->WindowImage_ = Value;
				delete D;
			}
		}



		// Window Size.

	private:

		delegate void WindowSizeD(System::Drawing::Size Value);
		void WindowSizeT(System::Drawing::Size Value) { Form::Size = Value; }
		System::Drawing::Size WindowSize_;

	public:

		property System::Drawing::Size Size
		{
			virtual System::Drawing::Size get() sealed { return System::Drawing::Size(0, 0); };
			virtual void set(System::Drawing::Size Value) sealed { return; }
		}

		property System::Drawing::Size WindowSize
		{
			System::Drawing::Size get() { return WindowSize_; }

			void set(System::Drawing::Size Value)
			{
				WindowSizeD^ D;
				D = gcnew WindowSizeD(this, &GWC::WindowSizeT);
				this->Invoke(D, Value);
				this->WindowSize_ = Value;
				delete D;
			}
		}



		// Minimum Size.

	private:

		delegate void WindowMinimumSizeD(System::Drawing::Size Value);
		void WindowMinimumSizeT(System::Drawing::Size Value) { Form::MinimumSize = Value; }
		System::Drawing::Size WindowMinimumSize_;

	public:

		virtual property System::Drawing::Size MinimumSize
		{
			System::Drawing::Size get() override { return Form::MinimumSize; }
			void set(System::Drawing::Size Value) override { Form::MinimumSize = Value; }
		}

		property System::Drawing::Size WindowMinimumSize
		{
			System::Drawing::Size get() { return WindowMinimumSize_; }

			void set(System::Drawing::Size Value)
			{
				WindowMinimumSizeD^ D;
				D = gcnew WindowMinimumSizeD(this, &GWC::WindowMinimumSizeT);
				this->Invoke(D, Value);
				this->WindowMinimumSize_ = Value;
				delete D;
			}
		}



		// Maximum Size.

	private:

		delegate void WindowMaximumSizeD(System::Drawing::Size Value);
		void WindowMaximumSizeT(System::Drawing::Size Value) { Form::MaximumSize = Value; }
		System::Drawing::Size WindowMaximumSize_;

	public:

		virtual property System::Drawing::Size MaximumSize
		{
			System::Drawing::Size get() override { return Form::MaximumSize; }
			void set(System::Drawing::Size Value) override { Form::MaximumSize = Value; }
		}

		property System::Drawing::Size WindowMaximumSize
		{
			System::Drawing::Size get() { return WindowMaximumSize_; }

			void set(System::Drawing::Size Value)
			{
				WindowMaximumSizeD^ D;
				D = gcnew WindowMaximumSizeD(this, &GWC::WindowMaximumSizeT);
				this->Invoke(D, Value);
				this->WindowMaximumSize_ = Value;
				delete D;
			}
		}



		// Window Opacity.

	private:

		delegate void WindowOpacityD(double Value);
		void WindowOpacityT(double Value) { Form::Opacity = Value; }
		double WindowOpacity_;

	public:

		property double Opacity
		{
			virtual double get() sealed { return 1.00; };
			virtual void set(double Value) sealed { return; }
		}

		property double WindowOpacity
		{
			double get() { return WindowOpacity_; }

			void set(double Value)
			{
				WindowOpacityD^ D;
				D = gcnew WindowOpacityD(this, &GWC::WindowOpacityT);
				this->Invoke(D, Value);
				this->WindowOpacity_ = Value;
				delete D;
			}
		}



		// Window Always On Top.

	private:

		delegate void WindowAlwaysOnTopD(bool Value);
		void WindowAlwaysOnTopT(bool Value) { Form::TopMost = Value; }
		bool WindowAlwaysOnTop_;

	public:

		property bool TopMost
		{
			virtual bool get() sealed { return false; };
			virtual void set(bool Value) sealed { return; }
		}

		property bool WindowAlwaysOnTop
		{
			bool get() { return WindowAlwaysOnTop_; }

			void set(bool Value)
			{
				WindowAlwaysOnTopD^ D;
				D = gcnew WindowAlwaysOnTopD(this, &GWC::WindowAlwaysOnTopT);
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
				D = gcnew WindowInTaskbarD(this, &GWC::WindowInTaskbarT);
				this->Invoke(D, Value);
				this->WindowInTaskbar_ = Value;
				delete D;
			}
		}



		// Window Minimize Button.

	private:

		delegate void WindowMinimizeButtonD(bool Value);
		void WindowMinimizeButtonT(bool Value) { Form::MinimizeBox = Value; }
		bool WindowMinimizeButton_;

	public:

		property bool MinimizeBox
		{
			virtual bool get() sealed { return false; };
			virtual void set(bool Value) sealed { return; }
		}

		property bool WindowMinimizeButton
		{
			bool get() { return WindowMinimizeButton_; }

			void set(bool Value)
			{
				WindowMinimizeButtonD^ D;
				D = gcnew WindowMinimizeButtonD(this, &GWC::WindowMinimizeButtonT);
				this->Invoke(D, Value);
				this->WindowMinimizeButton_ = Value;
				delete D;
			}
		}



		// Window Maximize Button.
		
	private:

		delegate void WindowMaximizeButtonD(bool Value);
		void WindowMaximizeButtonT(bool Value) {Form::MaximizeBox = Value; }
		bool WindowMaximizeButton_;

	public:

		property bool MaximizeBox
		{
			virtual bool get() sealed { return false; };
			virtual void set(bool Value) sealed { return; }
		}

		property bool WindowMaximizeButton
		{
			bool get() { return WindowMaximizeButton_; }

			void set(bool Value)
			{
				WindowMaximizeButtonD^ D;
				D = gcnew WindowMaximizeButtonD(this, &GWC::WindowMaximizeButtonT);
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

		Color PenColor_;

	public:

		void DefaultPenColor() { PenColor_ = Color::Black; }

		property Color PenColor
		{
			Color get() { return PenColor_; }
			void set(Color Value) {	PenColor_ = Value; }
		}



		// Pen Width.

	private:
		
		float PenWidth_;

	public:

		void DefaultPenWidth() { PenWidth = 2.5F; }
		property float PenWidth
		{ 
			float get() { return PenWidth_;	}
			void set(float Value) { PenWidth_ = Value; }
		}



		// Fill Color.

	private:

		Color FillColor_;

	public:

		void DefaultFillColor() { FillColor = Color::Black; }

		property Color FillColor
		{
			Color get() { return FillColor_; }
			void set(Color Value) { FillColor_ = Value; }
		}



		// Font Name.

	private:

		String^ FontName_;

	public:

		void DefaultFontName() { FontName = "Comic Sans"; }

		property String^ FontName
		{
			String^ get() { return FontName_; }
			void set(String^ Value) { FontName_ = Value; }
		}



		// Font Size.

	private:

		float FontSize_;

	public:

		void DefaultFontSize() { FontSize = 15.0F; }

		property float FontSize
		{
			float get() { return FontSize_; }
			void set(float Value) { FontSize_ = Value; }
		}



		/*
			Metodi disegno.
		*/

	public:

		void ClearWindow()
		{
			Graphics^ G = this->CreateGraphics();
			G->Clear(WindowColor);
			delete G;
		}


		void DrawLine(int X1, int Y1, int X2, int Y2)
		{
			Graphics^ G = this->CreateGraphics();
			G->DrawLine(gcnew Pen(PenColor, PenWidth), X1, Y1, X2, Y2);
			delete G;
		}


		void DrawArc(int X, int Y, int W, int H, int A, int B)
		{
			Graphics^ G = this->CreateGraphics();
			G->DrawArc(gcnew Pen(PenColor, PenWidth), X, Y, W, H, A, B);
			delete G;
		}


		void DrawText(String^ S, int X, int Y)
		{
			Graphics^ G = this->CreateGraphics();
			G->DrawString(S, gcnew System::Drawing::Font(FontName, FontSize), gcnew SolidBrush(PenColor), Point(X, Y));
			delete G;
		}


		void DrawImage(Image^ I, int X, int Y)
		{
			Graphics^ G = this->CreateGraphics();
			G->DrawImage(I, X, Y);
			delete G;
		}


		void DrawIcon(System::Drawing::Icon^ I, int X, int Y)
		{
			Graphics^ G = this->CreateGraphics();
			G->DrawIcon(I, X, Y);
			delete G;
		}


		void DrawRectangle(int X, int Y, int W, int H)
		{
			Graphics^ G = this->CreateGraphics();
			G->DrawRectangle(gcnew Pen(PenColor, PenWidth), X, Y, W, H);
			delete G;
		}


		void DrawFillRectangle(int X, int Y, int W, int H)
		{
			Graphics^ G = this->CreateGraphics();
			G->FillRectangle(gcnew SolidBrush(FillColor), X, Y, W, H);
			delete G;
		}


		void DrawEllipse(int X, int Y, int W, int H)
		{
			Graphics^ G = this->CreateGraphics();
			G->DrawEllipse(gcnew Pen(PenColor, PenWidth), X, Y, W, H);
			delete G;
		}


		void DrawFillEllipse(int X, int Y, int W, int H)
		{
			Graphics^ G = this->CreateGraphics();
			G->FillEllipse(gcnew SolidBrush(FillColor), X, Y, W, H);
			delete G;
		}


		void DrawPolygon(array<Point>^ P)
		{
			Graphics^ G = this->CreateGraphics();
			G->DrawPolygon(gcnew Pen(PenColor, PenWidth), P);
			delete G;
		}


		void DrawFillPolygon(array<Point>^ P)
		{
			Graphics^ G = this->CreateGraphics();
			G->FillPolygon(gcnew SolidBrush(FillColor), P);
			delete G;
		}


		void DrawPie(int X, int Y, int W, int H, int A, int B)
		{
			Graphics^ G = this->CreateGraphics();
			G->DrawPie(gcnew Pen(PenColor, PenWidth), X, Y, W, H, A, B);
			delete G;
		}


		void DrawFillPie(int X, int Y, int W, int H, int A, int B)
		{
			Graphics^ G = this->CreateGraphics();
			G->FillPie(gcnew SolidBrush(FillColor), X, Y, W, H, A, B);
			delete G;
		}



		/*
			Metodi evento.
		*/

		// Mouse Down.

	private:

		bool MouseDownPending;
		Point MouseDownPoint;
		int MouseDownButton;

		void GWC_MouseDown(Object^ Sender, MouseEventArgs^ E)
		{
			if (E->Button != System::Windows::Forms::MouseButtons::None)
			{
				if (MouseDownPending == false)
				{
					return;
				}

				if (MouseDownButton == 0 && E->Button == System::Windows::Forms::MouseButtons::Left)
				{
					MouseDownPoint = Point(E->X, E->Y);
					MouseDownButton = -1;
					MouseDownPending = false;
				}

				if (MouseDownButton == 1 && E->Button == System::Windows::Forms::MouseButtons::Right)
				{
					MouseDownPoint = Point(E->X, E->Y);
					MouseDownButton = -1;
					MouseDownPending = false;
				}

				if (MouseDownButton == 2 && E->Button == System::Windows::Forms::MouseButtons::Middle)
				{
					MouseDownPoint = Point(E->X, E->Y);
					MouseDownButton = -1;
					MouseDownPending = false;
				}
			}
		}

	public:

		Point RequestMouseDown(int B)
		{
			MouseDownPending = true;
			MouseDownButton = B;

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
		int MouseUpButton;

		void GWC_MouseUp(Object^ Sender, MouseEventArgs^ E)
		{
			if (E->Button != System::Windows::Forms::MouseButtons::None)
			{
				if (MouseUpPending == false)
				{
					return;
				}

				if (MouseUpButton == 0 && E->Button == System::Windows::Forms::MouseButtons::Left)
				{
					MouseUpPoint = Point(E->X, E->Y);
					MouseUpButton = -1;
					MouseUpPending = false;
				}

				if (MouseUpButton == 1 && E->Button == System::Windows::Forms::MouseButtons::Right)
				{
					MouseUpPoint = Point(E->X, E->Y);
					MouseUpButton = -1;
					MouseUpPending = false;
				}

				if (MouseUpButton == 2 && E->Button == System::Windows::Forms::MouseButtons::Middle)
				{
					MouseUpPoint = Point(E->X, E->Y);
					MouseUpButton = -1;
					MouseUpPending = false;
				}
			}
		}

	public:

		Point RequestMouseUp(int B)
		{
			MouseUpPending = true;
			MouseUpButton = B;

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
			Metodi vari.
		*/

	public:
			
		int GetScreenMaxX() { return System::Windows::Forms::Screen::PrimaryScreen->Bounds.Width - 1; }
		int GetScreenMaxY() { return System::Windows::Forms::Screen::PrimaryScreen->Bounds.Height - 1; }
		int GetWindowMaxX() { return Form::ClientSize.Width - 1; }
		int GetWindowMaxY() { return Form::ClientSize.Height - 1; }

	};
}
