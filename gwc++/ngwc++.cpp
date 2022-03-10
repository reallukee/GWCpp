/*
    GWC++ (Graphic Window for Console Application)

    - Questo progetto è sotto lincenza MIT (https://mit-license.org)
    - Questo progetto è disponibile su GitHub (https://github.com/reallukee/GWCpp)
    - Maggiori informazioni sono diponibili nel file README.md

    ATUORE:			Realluke
    DESCRIZIONE:	Classe gestita NGWC
    DATA:			09/03/22
*/


#include "pch.h"
#include "ngwc++.h"
#include "gwc++.h"
#include <msclr\marshal_cppstd.h>


#pragma managed


namespace NGWCpp
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



    /*
        Funzioni di conversione
    */

    String^ UStringToMString(std::string Str)
    {
        String^ Context = gcnew String(Str.c_str());
        return Context;
    }


    std::string MStringToUString(String^ Str)
    {
        msclr::interop::marshal_context Context;
        return Context.marshal_as<std::string>(Str);
    }



    /*
        Costruttori e distruttori
    */

    // Costruttori
    NGWC::NGWC()
    {
        GWCpp::GWC^ T = gcnew GWCpp::GWC(850, 505, "GWC++ Window", 50, 50);
        NGWCAdress = GCHandle::ToIntPtr(GCHandle::Alloc(T)).ToPointer();
    }
    
    NGWC::NGWC(int W, int H)
    {
        GWCpp::GWC^ T = gcnew GWCpp::GWC(W, H, "GWC++ Window", 50, 50);
        NGWCAdress = GCHandle::ToIntPtr(GCHandle::Alloc(T)).ToPointer();
    }

    NGWC::NGWC(int W, int H, std::string Title)
    {
        GWCpp::GWC^ T = gcnew GWCpp::GWC(W, H, gcnew String(Title.c_str()), 50, 50);
        NGWCAdress = GCHandle::ToIntPtr(GCHandle::Alloc(T)).ToPointer();
    }

    NGWC::NGWC(int W, int H, std::string Title, int X, int Y)
    {
        GWCpp::GWC^ T = gcnew GWCpp::GWC(W, H, gcnew String(Title.c_str()), X, Y);
        NGWCAdress = GCHandle::ToIntPtr(GCHandle::Alloc(T)).ToPointer();
    }

    // Distruttore
    NGWC::~NGWC()
    {
        GCHandle Handle = GCHandle::FromIntPtr(IntPtr(NGWCAdress));
        Handle.Free();
    }



    /*
        Metodi finestra
    */

    // Start Window
    void NGWC::StartWindow()
    {
        GCHandle Handle = GCHandle::FromIntPtr(IntPtr(NGWCAdress));
        GWCpp::GWC^ T = safe_cast<GWCpp::GWC^>(Handle.Target);
        T->StartWindow();
    }

    // Close Window
    void NGWC::CloseWindow()
    {
        GCHandle Handle = GCHandle::FromIntPtr(IntPtr(NGWCAdress));
        GWCpp::GWC^ T = safe_cast<GWCpp::GWC^>(Handle.Target);
        T->CloseWindow();
    }

    // Suspend Window
    void NGWC::SuspendWindow()
    {
        GCHandle Handle = GCHandle::FromIntPtr(IntPtr(NGWCAdress));
        GWCpp::GWC^ T = safe_cast<GWCpp::GWC^>(Handle.Target);
        T->SuspendWindow();
    }
    
    // Resume Window
    void NGWC::ResumeWindow()
    {
        GCHandle Handle = GCHandle::FromIntPtr(IntPtr(NGWCAdress));
        GWCpp::GWC^ T = safe_cast<GWCpp::GWC^>(Handle.Target);
        T->ResumeWindow();
    }

    // Show Window
    void NGWC::ShowWindow()
    {
        GCHandle Handle = GCHandle::FromIntPtr(IntPtr(NGWCAdress));
        GWCpp::GWC^ T = safe_cast<GWCpp::GWC^>(Handle.Target);
        T->ShowWindow();
    }

    // Hide Window
    void NGWC::HideWindow()
    {
        GCHandle Handle = GCHandle::FromIntPtr(IntPtr(NGWCAdress));
        GWCpp::GWC^ T = safe_cast<GWCpp::GWC^>(Handle.Target);
        T->HideWindow();
    }



    /*
        Proprietà finestra
    */

    // Window Title
    std::string NGWC::GetWindowTitle()
    {
        GCHandle Handle = GCHandle::FromIntPtr(IntPtr(NGWCAdress));
        GWCpp::GWC^ T = safe_cast<GWCpp::GWC^>(Handle.Target);
        return MStringToUString(T->WindowTitle);
    }

    void NGWC::SetWindowTitle(std::string Value)
    {
        GCHandle Handle = GCHandle::FromIntPtr(IntPtr(NGWCAdress));
        GWCpp::GWC^ T = safe_cast<GWCpp::GWC^>(Handle.Target);
        T->WindowTitle = UStringToMString(Value);
    }

    // Window Icon Visible
    bool NGWC::GetWindowIconVisible()
    {
        GCHandle Handle = GCHandle::FromIntPtr(IntPtr(NGWCAdress));
        GWCpp::GWC^ T = safe_cast<GWCpp::GWC^>(Handle.Target);
        return T->WindowIconVisible;
    }

    void NGWC::SetWindowIconVisible(bool Value)
    {
        GCHandle Handle = GCHandle::FromIntPtr(IntPtr(NGWCAdress));
        GWCpp::GWC^ T = safe_cast<GWCpp::GWC^>(Handle.Target);
        T->WindowIconVisible = Value;
    }

    // Window Location
    NPOINT NGWC::GetWindowLocation()
    {
        GCHandle Handle = GCHandle::FromIntPtr(IntPtr(NGWCAdress));
        GWCpp::GWC^ T = safe_cast<GWCpp::GWC^>(Handle.Target);
        return NPOINT{T->WindowLocation.X, T->WindowLocation.Y};
    }

    void NGWC::SetWindowLocation(NPOINT Value)
    {
        GCHandle Handle = GCHandle::FromIntPtr(IntPtr(NGWCAdress));
        GWCpp::GWC^ T = safe_cast<GWCpp::GWC^>(Handle.Target);
        T->WindowLocation = Point(Value.X, Value.Y);
    }

    // Window Color
    NCOLOR NGWC::GetWindowColor()
    {
        GCHandle Handle = GCHandle::FromIntPtr(IntPtr(NGWCAdress));
        GWCpp::GWC^ T = safe_cast<GWCpp::GWC^>(Handle.Target);
        return NCOLOR{ T->WindowColor.R, T->WindowColor.G, T->WindowColor.B };
    }

    void NGWC::SetWindowColor(NCOLOR Value)
    {
        GCHandle Handle = GCHandle::FromIntPtr(IntPtr(NGWCAdress));
        GWCpp::GWC^ T = safe_cast<GWCpp::GWC^>(Handle.Target);
        T->WindowColor = Color::FromArgb(Value.R, Value.G, Value.B);
    }

    // Window Size
    NSIZE NGWC::GetWindowSize()
    {
        GCHandle Handle = GCHandle::FromIntPtr(IntPtr(NGWCAdress));
        GWCpp::GWC^ T = safe_cast<GWCpp::GWC^>(Handle.Target);
        return NSIZE{ T->WindowSize.Width, T->WindowSize.Height };
    }

    void NGWC::SetWindowSize(NSIZE Value)
    {
        GCHandle Handle = GCHandle::FromIntPtr(IntPtr(NGWCAdress));
        GWCpp::GWC^ T = safe_cast<GWCpp::GWC^>(Handle.Target);
        T->WindowSize = Size(Value.W, Value.H);
    }
    
    // Window Size State
    int NGWC::GetWindowSizeState()
    {
        GCHandle Handle = GCHandle::FromIntPtr(IntPtr(NGWCAdress));
        GWCpp::GWC^ T = safe_cast<GWCpp::GWC^>(Handle.Target);
        return (int)T->WindowSizeState;
    }

    void NGWC::SetWindowSizeState(int Value)
    {
        GCHandle Handle = GCHandle::FromIntPtr(IntPtr(NGWCAdress));
        GWCpp::GWC^ T = safe_cast<GWCpp::GWC^>(Handle.Target);
        T->WindowSizeState = (FormWindowState)Value;
    }

    // Window Minimum Size
    NSIZE NGWC::GetWindowMinimumSize()
    {
        GCHandle Handle = GCHandle::FromIntPtr(IntPtr(NGWCAdress));
        GWCpp::GWC^ T = safe_cast<GWCpp::GWC^>(Handle.Target);
        return NSIZE{ T->WindowMinimumSize.Width, T->WindowMinimumSize.Height };
    }

    void NGWC::SetWindowMinimumSize(NSIZE Value)
    {
        GCHandle Handle = GCHandle::FromIntPtr(IntPtr(NGWCAdress));
        GWCpp::GWC^ T = safe_cast<GWCpp::GWC^>(Handle.Target);
        T->WindowMinimumSize = Size(Value.W, Value.H);
    }

    // Window Maximum Size
    NSIZE NGWC::GetWindowMaximumSize()
    {
        GCHandle Handle = GCHandle::FromIntPtr(IntPtr(NGWCAdress));
        GWCpp::GWC^ T = safe_cast<GWCpp::GWC^>(Handle.Target);
        return NSIZE{ T->WindowMaximumSize.Width, T->WindowMaximumSize.Height };
    }

    void NGWC::SetWindowMaximumSize(NSIZE Value)
    {
        GCHandle Handle = GCHandle::FromIntPtr(IntPtr(NGWCAdress));
        GWCpp::GWC^ T = safe_cast<GWCpp::GWC^>(Handle.Target);
        T->WindowMaximumSize = Size(Value.W, Value.H);
    }

    // Window Opacity
    double NGWC::GetWindowOpacity()
    {
        GCHandle Handle = GCHandle::FromIntPtr(IntPtr(NGWCAdress));
        GWCpp::GWC^ T = safe_cast<GWCpp::GWC^>(Handle.Target);
        return T->WindowOpacity;
    }

    void NGWC::SetWindowOpacity(double Value)
    {
        GCHandle Handle = GCHandle::FromIntPtr(IntPtr(NGWCAdress));
        GWCpp::GWC^ T = safe_cast<GWCpp::GWC^>(Handle.Target);
        T->WindowOpacity = Value;
    }

    // Window Always On Top
    bool NGWC::GetWindowAlwaysOnTop()
    {
        GCHandle Handle = GCHandle::FromIntPtr(IntPtr(NGWCAdress));
        GWCpp::GWC^ T = safe_cast<GWCpp::GWC^>(Handle.Target);
        return T->WindowAlwaysOnTop;
    }

    void NGWC::SetWindowAlwaysOnTop(bool Value)
    {
        GCHandle Handle = GCHandle::FromIntPtr(IntPtr(NGWCAdress));
        GWCpp::GWC^ T = safe_cast<GWCpp::GWC^>(Handle.Target);
        T->WindowAlwaysOnTop = Value;
    }

    // Window In Taskbar
    bool NGWC::GetWindowInTaskbar()
    {
        GCHandle Handle = GCHandle::FromIntPtr(IntPtr(NGWCAdress));
        GWCpp::GWC^ T = safe_cast<GWCpp::GWC^>(Handle.Target);
        return T->WindowInTaskbar;
    }

    void NGWC::SetWindowInTaskbar(bool Value)
    {
        GCHandle Handle = GCHandle::FromIntPtr(IntPtr(NGWCAdress));
        GWCpp::GWC^ T = safe_cast<GWCpp::GWC^>(Handle.Target);
        T->WindowInTaskbar = Value;
    }

    // Window Buttons
    bool NGWC::GetWindowButtons()
    {
        GCHandle Handle = GCHandle::FromIntPtr(IntPtr(NGWCAdress));
        GWCpp::GWC^ T = safe_cast<GWCpp::GWC^>(Handle.Target);
        return T->WindowButtons;
    }

    void NGWC::SetWindowButtons(bool Value)
    {
        GCHandle Handle = GCHandle::FromIntPtr(IntPtr(NGWCAdress));
        GWCpp::GWC^ T = safe_cast<GWCpp::GWC^>(Handle.Target);
        T->WindowButtons = Value;
    }

    // Window Minimize Button
    bool NGWC::GetWindowMinimizeButton()
    {
        GCHandle Handle = GCHandle::FromIntPtr(IntPtr(NGWCAdress));
        GWCpp::GWC^ T = safe_cast<GWCpp::GWC^>(Handle.Target);
        return T->WindowMinimizeButton;
    }

    void NGWC::SetWindowMinimizeButton(bool Value)
    {
        GCHandle Handle = GCHandle::FromIntPtr(IntPtr(NGWCAdress));
        GWCpp::GWC^ T = safe_cast<GWCpp::GWC^>(Handle.Target);
        T->WindowMinimizeButton = Value;
    }

    // Window Maximize Button
    bool NGWC::GetWindowMaximizeButton()
    {
        GCHandle Handle = GCHandle::FromIntPtr(IntPtr(NGWCAdress));
        GWCpp::GWC^ T = safe_cast<GWCpp::GWC^>(Handle.Target);
        return T->WindowMaximizeButton;
    }

    void NGWC::SetWindowMaximizeButton(bool Value)
    {
        GCHandle Handle = GCHandle::FromIntPtr(IntPtr(NGWCAdress));
        GWCpp::GWC^ T = safe_cast<GWCpp::GWC^>(Handle.Target);
        T->WindowMaximizeButton = Value;
    }



    /*
        Proprietà disegno
    */

    // Pen Color
    void NGWC::DefaultPenColor()
    {
        GCHandle Handle = GCHandle::FromIntPtr(IntPtr(NGWCAdress));
        GWCpp::GWC^ T = safe_cast<GWCpp::GWC^>(Handle.Target);
        T->DefaultPenColor();
    }

    NCOLOR NGWC::GetPenColor()
    {
        GCHandle Handle = GCHandle::FromIntPtr(IntPtr(NGWCAdress));
        GWCpp::GWC^ T = safe_cast<GWCpp::GWC^>(Handle.Target);
        return NCOLOR{ T->PenColor.R, T->PenColor.G, T->PenColor.B };
    }

    void NGWC::SetPenColor(NCOLOR Value)
    {
        GCHandle Handle = GCHandle::FromIntPtr(IntPtr(NGWCAdress));
        GWCpp::GWC^ T = safe_cast<GWCpp::GWC^>(Handle.Target);
        T->PenColor = Color::FromArgb(Value.R, Value.G, Value.B);
    }

    // Pen Width
    void NGWC::DefaultPenWidth()
    {
        GCHandle Handle = GCHandle::FromIntPtr(IntPtr(NGWCAdress));
        GWCpp::GWC^ T = safe_cast<GWCpp::GWC^>(Handle.Target);
        T->DefaultPenWidth();
    }

    float NGWC::GetPenWidth()
    {
        GCHandle Handle = GCHandle::FromIntPtr(IntPtr(NGWCAdress));
        GWCpp::GWC^ T = safe_cast<GWCpp::GWC^>(Handle.Target);
        return T->PenWidth;
    }

    void NGWC::SetPenWidth(float Value)
    {
        GCHandle Handle = GCHandle::FromIntPtr(IntPtr(NGWCAdress));
        GWCpp::GWC^ T = safe_cast<GWCpp::GWC^>(Handle.Target);
        T->PenWidth = Value;
    }

    // Fill Color
    void NGWC::DefaultFillColor()
    {
        GCHandle Handle = GCHandle::FromIntPtr(IntPtr(NGWCAdress));
        GWCpp::GWC^ T = safe_cast<GWCpp::GWC^>(Handle.Target);
        T->DefaultFillColor();
    }

    NCOLOR NGWC::GetFillColor()
    {
        GCHandle Handle = GCHandle::FromIntPtr(IntPtr(NGWCAdress));
        GWCpp::GWC^ T = safe_cast<GWCpp::GWC^>(Handle.Target);
        return NCOLOR{ T->FillColor.R, T->FillColor.G, T->FillColor.B };
    }

    void NGWC::SetFillColor(NCOLOR Value)
    {
        GCHandle Handle = GCHandle::FromIntPtr(IntPtr(NGWCAdress));
        GWCpp::GWC^ T = safe_cast<GWCpp::GWC^>(Handle.Target);
        T->FillColor = Color::FromArgb(Value.R, Value.G, Value.B);
    }

    // Font Name
    void NGWC::DefaultFontName()
    {
        GCHandle Handle = GCHandle::FromIntPtr(IntPtr(NGWCAdress));
        GWCpp::GWC^ T = safe_cast<GWCpp::GWC^>(Handle.Target);
        T->DefaultFontName();
    }

    std::string NGWC::GetFontName()
    {
        GCHandle Handle = GCHandle::FromIntPtr(IntPtr(NGWCAdress));
        GWCpp::GWC^ T = safe_cast<GWCpp::GWC^>(Handle.Target);
        return MStringToUString(T->FontName);     
    }

    void NGWC::SetFontName(std::string Value)
    {
        GCHandle Handle = GCHandle::FromIntPtr(IntPtr(NGWCAdress));
        GWCpp::GWC^ T = safe_cast<GWCpp::GWC^>(Handle.Target);
        T->FontName = UStringToMString(Value);
    }

    // Font Size
    void NGWC::DefaultFontSize()
    {
        GCHandle Handle = GCHandle::FromIntPtr(IntPtr(NGWCAdress));
        GWCpp::GWC^ T = safe_cast<GWCpp::GWC^>(Handle.Target);
        T->DefaultFontSize();
    }

    float NGWC::GetFontSize()
    {
        GCHandle Handle = GCHandle::FromIntPtr(IntPtr(NGWCAdress));
        GWCpp::GWC^ T = safe_cast<GWCpp::GWC^>(Handle.Target);
        return T->FontSize;
    }

    void NGWC::SetFontSize(float Value)
    {
        GCHandle Handle = GCHandle::FromIntPtr(IntPtr(NGWCAdress));
        GWCpp::GWC^ T = safe_cast<GWCpp::GWC^>(Handle.Target);
        T->FontSize = Value;
    }



    /*
        Metodo disegno
    */

    // Clear Window
    void NGWC::ClearWindow()
    {
        GCHandle Handle = GCHandle::FromIntPtr(IntPtr(NGWCAdress));
        GWCpp::GWC^ T = safe_cast<GWCpp::GWC^>(Handle.Target);
        T->ClearWindow();
    }

    // Save Canvas
    void NGWC::SaveCanvas()
    {
        GCHandle Handle = GCHandle::FromIntPtr(IntPtr(NGWCAdress));
        GWCpp::GWC^ T = safe_cast<GWCpp::GWC^>(Handle.Target);
        T->SaveCanvas();
    }

    // Restore Canvas
    void NGWC::RestoreCanvas()
    {
        GCHandle Handle = GCHandle::FromIntPtr(IntPtr(NGWCAdress));
        GWCpp::GWC^ T = safe_cast<GWCpp::GWC^>(Handle.Target);
        T->RestoreCanvas();
    }

    // Draw Pixel
    void NGWC::DrawPixel(int X, int Y)
    {
        GCHandle Handle = GCHandle::FromIntPtr(IntPtr(NGWCAdress));
        GWCpp::GWC^ T = safe_cast<GWCpp::GWC^>(Handle.Target);
        T->DrawPixel(X, Y);
    }

    // Draw Line
    void NGWC::DrawLine(int X1, int Y1, int X2, int Y2)
    {
        GCHandle Handle = GCHandle::FromIntPtr(IntPtr(NGWCAdress));
        GWCpp::GWC^ T = safe_cast<GWCpp::GWC^>(Handle.Target);
        T->DrawLine(X1, Y1, X2, Y2);
    }

    // Draw Arc
    void NGWC::DrawArc(int X, int Y, int W, int H, int A, int B)
    {
        GCHandle Handle = GCHandle::FromIntPtr(IntPtr(NGWCAdress));
        GWCpp::GWC^ T = safe_cast<GWCpp::GWC^>(Handle.Target);
        T->DrawArc(X, Y, W, H, A, B);
    }

    // Draw Bezier
    void NGWC::DrawBezier(float X1, float Y1, float X2, float Y2, float X3, float Y3, float X4, float Y4)
    {
        GCHandle Handle = GCHandle::FromIntPtr(IntPtr(NGWCAdress));
        GWCpp::GWC^ T = safe_cast<GWCpp::GWC^>(Handle.Target);
        T->DrawBezier(X1, Y1, X2, Y2, X3, Y3, X4, Y4);
    }

    // Draw String
    void NGWC::DrawString(std::string S, int X, int Y)
    {
        GCHandle Handle = GCHandle::FromIntPtr(IntPtr(NGWCAdress));
        GWCpp::GWC^ T = safe_cast<GWCpp::GWC^>(Handle.Target);
        T->DrawString(gcnew String(S.c_str()), X, Y);
    }

    // Draw Image From File
    void NGWC::DrawImageFromFile(std::string F, int X, int Y)
    {
        GCHandle Handle = GCHandle::FromIntPtr(IntPtr(NGWCAdress));
        GWCpp::GWC^ T = safe_cast<GWCpp::GWC^>(Handle.Target);
        T->DrawImageFromFile(gcnew String(F.c_str()), X, Y);
    }

    // Draw Icon From File
    void NGWC::DrawIconFromFile(std::string F, int X, int Y)
    {
        GCHandle Handle = GCHandle::FromIntPtr(IntPtr(NGWCAdress));
        GWCpp::GWC^ T = safe_cast<GWCpp::GWC^>(Handle.Target);
        T->DrawIconFromFile(gcnew String(F.c_str()), X, Y);
    }

    // Draw Square
    void NGWC::DrawSquare(int X, int Y, int L)
    {
        GCHandle Handle = GCHandle::FromIntPtr(IntPtr(NGWCAdress));
        GWCpp::GWC^ T = safe_cast<GWCpp::GWC^>(Handle.Target);
        T->DrawSquare(X, Y, L);
    }

    // Draw Fill Square
    void NGWC::DrawFillSquare(int X, int Y, int L)
    {
        GCHandle Handle = GCHandle::FromIntPtr(IntPtr(NGWCAdress));
        GWCpp::GWC^ T = safe_cast<GWCpp::GWC^>(Handle.Target);
        T->DrawFillSquare(X, Y, L);
    }

    // Draw Rectangle
    void NGWC::DrawRectangle(int X, int Y, int W, int H)
    {
        GCHandle Handle = GCHandle::FromIntPtr(IntPtr(NGWCAdress));
        GWCpp::GWC^ T = safe_cast<GWCpp::GWC^>(Handle.Target);
        T->DrawRectangle(X, Y, W, H);
    }

    // Draw Fill Rectangle
    void NGWC::DrawFillRectangle(int X, int Y, int W, int H)
    {
        GCHandle Handle = GCHandle::FromIntPtr(IntPtr(NGWCAdress));
        GWCpp::GWC^ T = safe_cast<GWCpp::GWC^>(Handle.Target);
        T->DrawFillRectangle(X, Y, W, H);
    }

    // Draw Ellipse
    void NGWC::DrawEllipse(int X, int Y, int W, int H)
    {
        GCHandle Handle = GCHandle::FromIntPtr(IntPtr(NGWCAdress));
        GWCpp::GWC^ T = safe_cast<GWCpp::GWC^>(Handle.Target);
        T->DrawEllipse(X, Y, W, H);
    }

    // Draw Fill Ellipse
    void NGWC::DrawFillEllipse(int X, int Y, int W, int H)
    {
        GCHandle Handle = GCHandle::FromIntPtr(IntPtr(NGWCAdress));
        GWCpp::GWC^ T = safe_cast<GWCpp::GWC^>(Handle.Target);
        T->DrawFillEllipse(X, Y, W, H);
    }

    // Draw Circle
    void NGWC::DrawCircle(int X, int Y, int R)
    {
        GCHandle Handle = GCHandle::FromIntPtr(IntPtr(NGWCAdress));
        GWCpp::GWC^ T = safe_cast<GWCpp::GWC^>(Handle.Target);
        T->DrawCircle(X, Y, R);
    }

    // Draw Fill Circle
    void NGWC::DrawFillCircle(int X, int Y, int R)
    {
        GCHandle Handle = GCHandle::FromIntPtr(IntPtr(NGWCAdress));
        GWCpp::GWC^ T = safe_cast<GWCpp::GWC^>(Handle.Target);
        T->DrawFillCircle(X, Y, R);
    }

    // Draw Pie
    void NGWC::DrawPie(int X, int Y, int W, int H, int A, int B)
    {
        GCHandle Handle = GCHandle::FromIntPtr(IntPtr(NGWCAdress));
        GWCpp::GWC^ T = safe_cast<GWCpp::GWC^>(Handle.Target);
        T->DrawPie(X, Y, W, H, A, B);
    }

    // Draw Fill Pie
    void NGWC::DrawFillPie(int X, int Y, int W, int H, int A, int B)
    {
        GCHandle Handle = GCHandle::FromIntPtr(IntPtr(NGWCAdress));
        GWCpp::GWC^ T = safe_cast<GWCpp::GWC^>(Handle.Target);
        T->DrawFillPie(X, Y, W, H, A, B);
    }

    // Draw From Screen
    void NGWC::DrawFromScreen(int X1, int Y1, int X2, int Y2, int W, int H)
    {
        GCHandle Handle = GCHandle::FromIntPtr(IntPtr(NGWCAdress));
        GWCpp::GWC^ T = safe_cast<GWCpp::GWC^>(Handle.Target);
        T->DrawFromScreen(X1, Y1, X2, Y2, W, H);
    }



    /*
        Metodi evento
    */

    // Mouse Down
    NPOINT NGWC::RequestMouseDown(int B)
    {
        GCHandle Handle = GCHandle::FromIntPtr(IntPtr(NGWCAdress));
        GWCpp::GWC^ T = safe_cast<GWCpp::GWC^>(Handle.Target);
        return NPOINT{ T->RequestMouseDown((MouseButtons)B).X, T->RequestMouseDown((MouseButtons)B).Y };
    }

    NPOINT NGWC::RequestMoudeDown()
    {
        GCHandle Handle = GCHandle::FromIntPtr(IntPtr(NGWCAdress));
        GWCpp::GWC^ T = safe_cast<GWCpp::GWC^>(Handle.Target);
        return NPOINT{ T->RequestMouseDown().X, T->RequestMouseDown().Y };
    }

    // Mouse Up
    NPOINT NGWC::RequestMouseUp(int B)
    {
        GCHandle Handle = GCHandle::FromIntPtr(IntPtr(NGWCAdress));
        GWCpp::GWC^ T = safe_cast<GWCpp::GWC^>(Handle.Target);
        return NPOINT{ T->RequestMouseUp((MouseButtons)B).X, T->RequestMouseUp((MouseButtons)B).Y };
    }

    NPOINT NGWC::RequestMouseUp()
    {
        GCHandle Handle = GCHandle::FromIntPtr(IntPtr(NGWCAdress));
        GWCpp::GWC^ T = safe_cast<GWCpp::GWC^>(Handle.Target);
        return NPOINT{ T->RequestMouseUp().X, T->RequestMouseUp().Y };
    }

    // key Down
    char NGWC::RequestKeyDown(char C)
    {
        GCHandle Handle = GCHandle::FromIntPtr(IntPtr(NGWCAdress));
        GWCpp::GWC^ T = safe_cast<GWCpp::GWC^>(Handle.Target);
        return T->RequestKeyUp(C);
    }

    char NGWC::RequestKeyDown()
    {
        GCHandle Handle = GCHandle::FromIntPtr(IntPtr(NGWCAdress));
        GWCpp::GWC^ T = safe_cast<GWCpp::GWC^>(Handle.Target);
        return T->RequestKeyUp();
    }

    // Key Up
    char NGWC::RequestKeyUp(char C)
    {
        GCHandle Handle = GCHandle::FromIntPtr(IntPtr(NGWCAdress));
        GWCpp::GWC^ T = safe_cast<GWCpp::GWC^>(Handle.Target);
        return T->RequestKeyUp(C);
    }

    char NGWC::RequestKeyUp()
    {
        GCHandle Handle = GCHandle::FromIntPtr(IntPtr(NGWCAdress));
        GWCpp::GWC^ T = safe_cast<GWCpp::GWC^>(Handle.Target);
        return T->RequestKeyUp();
    }

}
