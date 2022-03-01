#pragma once
#pragma managed


#using <System.dll>
#using <System.ComponentModel.dll>
#using <System.Collections.dll>
#using <System.Windows.Forms.dll>
#using <System.Data.dll>
#using <System.Drawing.dll>
#using <System.Threading.dll>
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
	using namespace Microsoft::VisualBasic;

	public ref class GWC : public Form
	{

	public:

		GWC(int W, int H, String^ Title, int X, int Y) : Form()
		{
			InitializeComponent(W, H, Title, X, Y);
			GWCThread = gcnew Thread(gcnew ThreadStart(this, &GWC::Initialize));
			GWCThread->SetApartmentState(ApartmentState::STA);
		}



	private:

		Thread^ GWCThread;
		bool CalledByMe = false;

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
			Form::Size = System::Drawing::Size(W, H);
			Form::MinimumSize = System::Drawing::Size(0, 0);
			Form::MaximumSize = System::Drawing::Size(0, 0);

			// Proprietà disegno.
			this->DefaultPenColor();
			this->DefaultPenWidth();
			this->DefaultFillColor();
			this->DefaultFontName();
			this->DefaultFontSize();

			// Eventi finestra.
			this->MouseDown += gcnew MouseEventHandler(this, &GWC::GWC_MouseDown);
			this->KeyDown += gcnew KeyEventHandler(this, &GWC::GWC_KeyDown);
			this->MouseUp += gcnew MouseEventHandler(this, &GWC::GWC_MouseUp);
			this->KeyUp += gcnew KeyEventHandler(this, &GWC::GWC_KeyUp);

			// Imposto 'CalledByMe' su 'false'.
			CalledByMe = false;

			// Ripresa layout.
			this->ResumeLayout(false);
		}

		void Initialize()
		{
			Application::EnableVisualStyles();
			Application::SetCompatibleTextRenderingDefault(false);
			Application::Run(this);
		}



	public:

		/*
			Start Window
		*/

		void StartWindow()
		{
			GWCThread->Start();
			GWCThread->Sleep(50);
		}

		/*
			Close Window
		*/

		void CloseWindow()
		{
			GWCThread->Sleep(50);
			GWCThread->Abort();
		}



		/*
			Show Window
		*/

	private:

		delegate void ShowWindowD();

		void ShowWindowT()
		{
			this->Show();
		}

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



		/*
			Hide Window
		*/

	private:

		delegate void HideWindowD();

		void HideWindowT()
		{
			this->Hide();
		}

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



		/*
			Window Title
		*/

	private:

		delegate void ChangeWindowTitleD(String^ Value);

		void ChangeWindowTitleT(String^ Value)
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
				ChangeWindowTitleD^ D;
				D = gcnew ChangeWindowTitleD(this, &GWC::ChangeWindowTitleT);
				this->Invoke(D, Value);
				this->WindowTitle_ = Value;
				delete D;
			}
		}



		/*
			Window Icon
		*/

	private:

		delegate void ChangeWindowIconD(System::Drawing::Icon^ Value);

		// Funzione reale.
		void ChangeWindowIconT(System::Drawing::Icon^ Value)
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
				ChangeWindowIconD^ D;
				D = gcnew ChangeWindowIconD(this, &GWC::ChangeWindowIconT);
				this->Invoke(D, Value);
				this->WindowIcon_ = Value;
				delete D;
			}
		}



		/*
			Window Location
		*/

	private:

		delegate void ChangeWindowLocationD(Point Value);

		void ChangeWindowLocationT(Point Value)
		{
			Form::Location = Value;
		}

		Point WindowLocation_;

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

		property Point WindowLocation
		{
			Point get()
			{
				return WindowLocation_;
			}

			void set(Point Value)
			{
				ChangeWindowLocationD^ D;
				D = gcnew ChangeWindowLocationD(this, &GWC::ChangeWindowLocationT);
				this->Invoke(D, Value);
				this->WindowLocation_ = Value;
				delete D;
			}
		}




		/*
			Window Color
		*/

	private:

		delegate void ChangeWindowColorD(Color Value);

		void ChangeWindowColorT(Color Value)
		{
			 Form::BackColor = Value;
		}

		Color WindowColor_;

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

	public:
		property Color WindowColor
		{
			Color get()
			{
				return WindowColor_;
			}

			void set(Color Value)
			{
				ChangeWindowColorD^ D;
				D = gcnew ChangeWindowColorD(this, &GWC::ChangeWindowColorT);
				CalledByMe = true;
				this->Invoke(D, Value);
				this->WindowColor_ = Value;
				delete D;
			}
		}



		/*
			Window Size
		*/

	private:

		delegate void ChangeWindowSizeD(System::Drawing::Size Value);

		void ChangeWindowSizeT(System::Drawing::Size Value)
		{
			Form::Size = Value;
		}

		System::Drawing::Size WindowSize_;

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

		property System::Drawing::Size WindowSize
		{
			System::Drawing::Size get()
			{
				return WindowSize_;
			}

			void set(System::Drawing::Size Value)
			{
				ChangeWindowSizeD^ D;
				D = gcnew ChangeWindowSizeD(this, &GWC::ChangeWindowSizeT);
				this->Invoke(D, Value);
				this->WindowSize_ = Value;
				delete D;
			}
		}



		/*
			Minimum Size
		*/

	private:

		delegate void ChangeWindowMinimumSizeD(System::Drawing::Size Value);

		void ChangeWindowMinimumSizeT(System::Drawing::Size Value)
		{
			Form::MinimumSize = Value;
		}

		System::Drawing::Size WindowMinimumSize_;

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

		property System::Drawing::Size WindowMinimumSize
		{
			System::Drawing::Size get()
			{
				return WindowMinimumSize_;
			}

			void set(System::Drawing::Size Value)
			{
				ChangeWindowMinimumSizeD^ D;
				D = gcnew ChangeWindowMinimumSizeD(this, &GWC::ChangeWindowMinimumSizeT);
				this->Invoke(D, Value);
				this->WindowMinimumSize_ = Value;
				delete D;
			}
		}



		/*
			Maximum Size
		*/

	private:

		delegate void ChangeWindowMaximumSizeD(System::Drawing::Size Value);

		void ChangeWindowMaximumSizeT(System::Drawing::Size Value)
		{
			Form::MaximumSize = Value;
		}

		System::Drawing::Size WindowMaximumSize_;

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

		property System::Drawing::Size WindowMaximumSize
		{
			System::Drawing::Size get()
			{
				return WindowMaximumSize_;
			}

			void set(System::Drawing::Size Value)
			{
				ChangeWindowMaximumSizeD^ D;
				D = gcnew ChangeWindowMaximumSizeD(this, &GWC::ChangeWindowMaximumSizeT);
				this->Invoke(D, Value);
				this->WindowMaximumSize_ = Value;
				delete D;
			}
		}



		/*
			Pen Color
		*/

	private:

		Color PenColor_;

	public:

		void DefaultPenColor()
		{
			PenColor_ = Color::Black;
		}

		property Color PenColor
		{
			Color get()
			{
				return PenColor_;
			}

			void set(Color Value)
			{
				PenColor_ = Value;
			}
		}



		/*
			Pen Width
		*/

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



		/*
			Fill Color
		*/

	private:

		Color FillColor_;

	public:

		void DefaultFillColor()
		{	
			FillColor = Color::Black;
		}

		property Color FillColor
		{
			Color get()
			{
				return FillColor_;
			}

			void set(Color Value)
			{
				FillColor_ = Value;
			}
		}



		/*
			Font Name
		*/

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



		/*
			Font Size
		*/

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
			Disegno
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


		void DrawCircle(int X, int Y, int R)
		{
			Graphics^ G = this->CreateGraphics();
			G->DrawEllipse(gcnew Pen(PenColor, PenWidth), Rectangle(X - R, Y - R, X + R, Y + R));
			delete G;
		}


		void DrawFillCircle(int X, int Y, int R)
		{
			Graphics^ G = this->CreateGraphics();
			G->FillEllipse(gcnew SolidBrush(FillColor), Rectangle(X - R, Y - R, X + R, Y + R));
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
			Mouse Down
		*/

	private:

		bool MouseDownPending;
		Point MouseDownPoint;

		void GWC_MouseDown(Object^ Sender, MouseEventArgs^ E)
		{
			if (E->Button != System::Windows::Forms::MouseButtons::None)
			{
				if (MouseDownPending)
				{
					MouseDownPoint = Point(E->X, E->Y);
					MouseDownPending = false;
				}
			}
		}

	public:

		Point RequestMouseDown()
		{
			MouseDownPending = true;

			while (MouseDownPending)
			{
				GWCThread->Sleep(10);
			}

			return MouseDownPoint;
		}



		/*
			Key Down
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
					return;
				}
			}
		}

	public:

		int RequestKeyDown()
		{
			KeyDownPending = true;

			while (KeyDownPending)
			{
				GWCThread->Sleep(10);
			}

			return KeyDownChar;
		}



		/*
			Mouse Up
		*/

	private:

		bool MouseUpPending;
		Point MouseUpPoint;

		void GWC_MouseUp(Object^ Sender, MouseEventArgs^ E)
		{
			if (E->Button != System::Windows::Forms::MouseButtons::None)
			{
				if (MouseUpPending)
				{
					MouseUpPoint = Point(E->X, E->Y);
					MouseUpPending = false;
				}
			}
		}

	public:

		Point RequestMouseUp()
		{
			MouseUpPending = true;

			while (MouseUpPending)
			{
				GWCThread->Sleep(10);
			}

			return MouseUpPoint;
		}



		/*
			Key Up
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
					return;
				}
			}
		}

	public:

		int RequestKeyUp()
		{
			KeyUpPending = true;

			while (KeyUpPending)
			{
				GWCThread->Sleep(10);
			}

			return KeyUpChar;
		}



		/*
			Funzioni Varie.
		*/

	public:
			
		int GetScreenMaxX()
		{
			return System::Windows::Forms::Screen::PrimaryScreen->Bounds.Width - 1;
		}

		int GetScreenMaxY()
		{
			return System::Windows::Forms::Screen::PrimaryScreen->Bounds.Height - 1;
		}

		int GetWindowMaxX()
		{
			return Form::Size.Width - 20;
		}

		int GetWindowMaxY()
		{
			return Form::Size.Height - 48;
		}

	};
}
