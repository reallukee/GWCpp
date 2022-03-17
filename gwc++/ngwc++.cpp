/*
    GWC++ (Graphic Window for Console Application)

    - Questo progetto è sotto lincenza MIT (https://mit-license.org)
    - Questo progetto è disponibile su GitHub (https://github.com/reallukee/GWCpp)
    - Maggiori informazioni sono diponibili nel file README.md

    ATUORE:			Realluke
    DESCRIZIONE:	Classe gestita NGWC
    DATA:			14/03/22
*/


#include "pch.h"
#include "ngwc++.h"
#include "pgwc++.h"
#include <msclr\marshal_cppstd.h>


#pragma managed


namespace NGWCpp
{

    /*
        Funzioni di conversione.
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
        Costruttori e distruttori.
    */

    // Costruttori.
    NGWC::NGWC()
    {
        GWCpp::PGWC^ T = gcnew GWCpp::PGWC(850, 505, "GWC++ Window", 50, 50);
        NGWCAdress = GCHandle::ToIntPtr(GCHandle::Alloc(T)).ToPointer();
    }

    NGWC::NGWC(int W, int H)
    {
        GWCpp::PGWC^ T = gcnew GWCpp::PGWC(W, H, "GWC++ Window", 50, 50);
        NGWCAdress = GCHandle::ToIntPtr(GCHandle::Alloc(T)).ToPointer();
    }

    NGWC::NGWC(int W, int H, std::string Title)
    {
        GWCpp::PGWC^ T = gcnew GWCpp::PGWC(W, H, gcnew String(Title.c_str()), 50, 50);
        NGWCAdress = GCHandle::ToIntPtr(GCHandle::Alloc(T)).ToPointer();
    }

    NGWC::NGWC(int W, int H, std::string Title, int X, int Y)
    {
        GWCpp::PGWC^ T = gcnew GWCpp::PGWC(W, H, gcnew String(Title.c_str()), X, Y);
        NGWCAdress = GCHandle::ToIntPtr(GCHandle::Alloc(T)).ToPointer();
    }

    // Distruttore.
    NGWC::~NGWC()
    {
        GCHandle Handle = GCHandle::FromIntPtr(IntPtr(NGWCAdress));
        Handle.Free();
    }



    /*
        Metodi finestra.
    */

    // Start Window.
    bool NGWC::StartWindow()
    {
        GCHandle Handle = GCHandle::FromIntPtr(IntPtr(NGWCAdress));
        GWCpp::PGWC^ T = safe_cast<GWCpp::PGWC^>(Handle.Target);
        return T->StartWindow();
    }

    // Close Window.
    bool NGWC::CloseWindow()
    {
        GCHandle Handle = GCHandle::FromIntPtr(IntPtr(NGWCAdress));
        GWCpp::PGWC^ T = safe_cast<GWCpp::PGWC^>(Handle.Target);
        return T->CloseWindow();
    }

    // Suspend Window.
    bool NGWC::SuspendWindow()
    {
        GCHandle Handle = GCHandle::FromIntPtr(IntPtr(NGWCAdress));
        GWCpp::PGWC^ T = safe_cast<GWCpp::PGWC^>(Handle.Target);
        return T->SuspendWindow();
    }

    // Resume Window.
    bool NGWC::ResumeWindow()
    {
        GCHandle Handle = GCHandle::FromIntPtr(IntPtr(NGWCAdress));
        GWCpp::PGWC^ T = safe_cast<GWCpp::PGWC^>(Handle.Target);
        return T->ResumeWindow();
    }

    // Show Window.
    bool NGWC::ShowWindow()
    {
        GCHandle Handle = GCHandle::FromIntPtr(IntPtr(NGWCAdress));
        GWCpp::PGWC^ T = safe_cast<GWCpp::PGWC^>(Handle.Target);
        return T->ShowWindow();
    }

    // Hide Window.
    bool NGWC::HideWindow()
    {
        GCHandle Handle = GCHandle::FromIntPtr(IntPtr(NGWCAdress));
        GWCpp::PGWC^ T = safe_cast<GWCpp::PGWC^>(Handle.Target);
        return T->HideWindow();
    }

    // Get Max X.
    int NGWC::GetMaxX()
    {
        GCHandle Handle = GCHandle::FromIntPtr(IntPtr(NGWCAdress));
        GWCpp::PGWC^ T = safe_cast<GWCpp::PGWC^>(Handle.Target);
        return T->GetMaxX();
    }

    // Get Real Max X.
    int NGWC::GetRealMaxX()
    {
        GCHandle Handle = GCHandle::FromIntPtr(IntPtr(NGWCAdress));
        GWCpp::PGWC^ T = safe_cast<GWCpp::PGWC^>(Handle.Target);
        return T->GetRealMaxX();
    }

    // Get Max Y.
    int NGWC::GetMaxY()
    {
        GCHandle Handle = GCHandle::FromIntPtr(IntPtr(NGWCAdress));
        GWCpp::PGWC^ T = safe_cast<GWCpp::PGWC^>(Handle.Target);
        return T->GetMaxY();
    }

    // Get Real Max Y.
    int NGWC::GetRealMaxY()
    {
        GCHandle Handle = GCHandle::FromIntPtr(IntPtr(NGWCAdress));
        GWCpp::PGWC^ T = safe_cast<GWCpp::PGWC^>(Handle.Target);
        return T->GetRealMaxY();
    }



    /*
        Proprietà finestra.
    */

    // Window Started.
    bool NGWC::GetWindowStarted()
    {
        GCHandle Handle = GCHandle::FromIntPtr(IntPtr(NGWCAdress));
        GWCpp::PGWC^ T = safe_cast<GWCpp::PGWC^>(Handle.Target);
        return T->WindowStarted;
    }

    // Window Closed.
    bool NGWC::GetWindowClosed()
    {
        GCHandle Handle = GCHandle::FromIntPtr(IntPtr(NGWCAdress));
        GWCpp::PGWC^ T = safe_cast<GWCpp::PGWC^>(Handle.Target);
        return T->WindowClosed;
    }

    // Window Title.
    std::string NGWC::GetWindowTitle()
    {
        GCHandle Handle = GCHandle::FromIntPtr(IntPtr(NGWCAdress));
        GWCpp::PGWC^ T = safe_cast<GWCpp::PGWC^>(Handle.Target);
        return MStringToUString(T->WindowTitle);
    }

    void NGWC::SetWindowTitle(std::string Value)
    {
        GCHandle Handle = GCHandle::FromIntPtr(IntPtr(NGWCAdress));
        GWCpp::PGWC^ T = safe_cast<GWCpp::PGWC^>(Handle.Target);
        T->WindowTitle = UStringToMString(Value);
    }

    // Window Icon Visible.
    bool NGWC::GetWindowIconVisible()
    {
        GCHandle Handle = GCHandle::FromIntPtr(IntPtr(NGWCAdress));
        GWCpp::PGWC^ T = safe_cast<GWCpp::PGWC^>(Handle.Target);
        return T->WindowIconVisible;
    }

    void NGWC::SetWindowIconVisible(bool Value)
    {
        GCHandle Handle = GCHandle::FromIntPtr(IntPtr(NGWCAdress));
        GWCpp::PGWC^ T = safe_cast<GWCpp::PGWC^>(Handle.Target);
        T->WindowIconVisible = Value;
    }

    // Window Location.
    NGPoint NGWC::GetWindowLocation()
    {
        GCHandle Handle = GCHandle::FromIntPtr(IntPtr(NGWCAdress));
        GWCpp::PGWC^ T = safe_cast<GWCpp::PGWC^>(Handle.Target);
        return NGPoint{ T->WindowLocation.X, T->WindowLocation.Y };
    }

    void NGWC::SetWindowLocation(NGPoint Value)
    {
        GCHandle Handle = GCHandle::FromIntPtr(IntPtr(NGWCAdress));
        GWCpp::PGWC^ T = safe_cast<GWCpp::PGWC^>(Handle.Target);
        T->WindowLocation = GWCpp::GPoint(Value.X, Value.Y);
    }

    // Window Color.
    NGColor NGWC::GetWindowColor()
    {
        GCHandle Handle = GCHandle::FromIntPtr(IntPtr(NGWCAdress));
        GWCpp::PGWC^ T = safe_cast<GWCpp::PGWC^>(Handle.Target);
        return NGColor{ T->WindowColor.R, T->WindowColor.G, T->WindowColor.B };
    }

    void NGWC::SetWindowColor(NGColor Value)
    {
        GCHandle Handle = GCHandle::FromIntPtr(IntPtr(NGWCAdress));
        GWCpp::PGWC^ T = safe_cast<GWCpp::PGWC^>(Handle.Target);
        T->WindowColor = GWCpp::GColor(Value.R, Value.G, Value.B);
    }

    // Window Size.
    NGSize NGWC::GetWindowSize()
    {
        GCHandle Handle = GCHandle::FromIntPtr(IntPtr(NGWCAdress));
        GWCpp::PGWC^ T = safe_cast<GWCpp::PGWC^>(Handle.Target);
        return NGSize{ T->WindowSize.W, T->WindowSize.H };
    }

    void NGWC::SetWindowSize(NGSize Value)
    {
        GCHandle Handle = GCHandle::FromIntPtr(IntPtr(NGWCAdress));
        GWCpp::PGWC^ T = safe_cast<GWCpp::PGWC^>(Handle.Target);
        T->WindowSize = GWCpp::GSize(Value.W, Value.H);
    }

    // Window Real Size.
    NGSize NGWC::GetWindowRealSize()
    {
        GCHandle Handle = GCHandle::FromIntPtr(IntPtr(NGWCAdress));
        GWCpp::PGWC^ T = safe_cast<GWCpp::PGWC^>(Handle.Target);
        return NGSize{ T->WindowRealSize.W, T->WindowRealSize.H };
    }

    void NGWC::SetWindowRealSize(NGSize Value)
    {
        GCHandle Handle = GCHandle::FromIntPtr(IntPtr(NGWCAdress));
        GWCpp::PGWC^ T = safe_cast<GWCpp::PGWC^>(Handle.Target);
        T->WindowRealSize = GWCpp::GSize(Value.W, Value.H);
    }

    // Window Size State.
    NGWindowState NGWC::GetWindowSizeState()
    {
        GCHandle Handle = GCHandle::FromIntPtr(IntPtr(NGWCAdress));
        GWCpp::PGWC^ T = safe_cast<GWCpp::PGWC^>(Handle.Target);
        return (NGWindowState)T->WindowSizeState;
    }

    void NGWC::SetWindowSizeState(NGWindowState Value)
    {
        GCHandle Handle = GCHandle::FromIntPtr(IntPtr(NGWCAdress));
        GWCpp::PGWC^ T = safe_cast<GWCpp::PGWC^>(Handle.Target);
        T->WindowSizeState = (GWCpp::GWindowState)Value;
    }

    // Window Minimum Size.
    NGSize NGWC::GetWindowMinimumSize()
    {
        GCHandle Handle = GCHandle::FromIntPtr(IntPtr(NGWCAdress));
        GWCpp::PGWC^ T = safe_cast<GWCpp::PGWC^>(Handle.Target);
        return NGSize{ T->WindowMinimumSize.W, T->WindowMinimumSize.H };
    }

    void NGWC::SetWindowMinimumSize(NGSize Value)
    {
        GCHandle Handle = GCHandle::FromIntPtr(IntPtr(NGWCAdress));
        GWCpp::PGWC^ T = safe_cast<GWCpp::PGWC^>(Handle.Target);
        T->WindowMinimumSize = GWCpp::GSize(Value.W, Value.H);
    }

    // Window Maximum Size.
    NGSize NGWC::GetWindowMaximumSize()
    {
        GCHandle Handle = GCHandle::FromIntPtr(IntPtr(NGWCAdress));
        GWCpp::PGWC^ T = safe_cast<GWCpp::PGWC^>(Handle.Target);
        return NGSize{ T->WindowMaximumSize.W, T->WindowMaximumSize.H };
    }

    void NGWC::SetWindowMaximumSize(NGSize Value)
    {
        GCHandle Handle = GCHandle::FromIntPtr(IntPtr(NGWCAdress));
        GWCpp::PGWC^ T = safe_cast<GWCpp::PGWC^>(Handle.Target);
        T->WindowMaximumSize = GWCpp::GSize(Value.W, Value.H);
    }

    // Window Opacity.
    double NGWC::GetWindowOpacity()
    {
        GCHandle Handle = GCHandle::FromIntPtr(IntPtr(NGWCAdress));
        GWCpp::PGWC^ T = safe_cast<GWCpp::PGWC^>(Handle.Target);
        return T->WindowOpacity;
    }

    void NGWC::SetWindowOpacity(double Value)
    {
        GCHandle Handle = GCHandle::FromIntPtr(IntPtr(NGWCAdress));
        GWCpp::PGWC^ T = safe_cast<GWCpp::PGWC^>(Handle.Target);
        T->WindowOpacity = Value;
    }

    // Window Always On Top.
    bool NGWC::GetWindowAlwaysOnTop()
    {
        GCHandle Handle = GCHandle::FromIntPtr(IntPtr(NGWCAdress));
        GWCpp::PGWC^ T = safe_cast<GWCpp::PGWC^>(Handle.Target);
        return T->WindowAlwaysOnTop;
    }

    void NGWC::SetWindowAlwaysOnTop(bool Value)
    {
        GCHandle Handle = GCHandle::FromIntPtr(IntPtr(NGWCAdress));
        GWCpp::PGWC^ T = safe_cast<GWCpp::PGWC^>(Handle.Target);
        T->WindowAlwaysOnTop = Value;
    }

    // Window In Taskbar.
    bool NGWC::GetWindowInTaskbar()
    {
        GCHandle Handle = GCHandle::FromIntPtr(IntPtr(NGWCAdress));
        GWCpp::PGWC^ T = safe_cast<GWCpp::PGWC^>(Handle.Target);
        return T->WindowInTaskbar;
    }

    void NGWC::SetWindowInTaskbar(bool Value)
    {
        GCHandle Handle = GCHandle::FromIntPtr(IntPtr(NGWCAdress));
        GWCpp::PGWC^ T = safe_cast<GWCpp::PGWC^>(Handle.Target);
        T->WindowInTaskbar = Value;
    }

    // Window Buttons.
    bool NGWC::GetWindowButtons()
    {
        GCHandle Handle = GCHandle::FromIntPtr(IntPtr(NGWCAdress));
        GWCpp::PGWC^ T = safe_cast<GWCpp::PGWC^>(Handle.Target);
        return T->WindowButtons;
    }

    void NGWC::SetWindowButtons(bool Value)
    {
        GCHandle Handle = GCHandle::FromIntPtr(IntPtr(NGWCAdress));
        GWCpp::PGWC^ T = safe_cast<GWCpp::PGWC^>(Handle.Target);
        T->WindowButtons = Value;
    }

    // Window Minimize Button.
    bool NGWC::GetWindowMinimizeButton()
    {
        GCHandle Handle = GCHandle::FromIntPtr(IntPtr(NGWCAdress));
        GWCpp::PGWC^ T = safe_cast<GWCpp::PGWC^>(Handle.Target);
        return T->WindowMinimizeButton;
    }

    void NGWC::SetWindowMinimizeButton(bool Value)
    {
        GCHandle Handle = GCHandle::FromIntPtr(IntPtr(NGWCAdress));
        GWCpp::PGWC^ T = safe_cast<GWCpp::PGWC^>(Handle.Target);
        T->WindowMinimizeButton = Value;
    }

    // Window Maximize Button.
    bool NGWC::GetWindowMaximizeButton()
    {
        GCHandle Handle = GCHandle::FromIntPtr(IntPtr(NGWCAdress));
        GWCpp::PGWC^ T = safe_cast<GWCpp::PGWC^>(Handle.Target);
        return T->WindowMaximizeButton;
    }

    void NGWC::SetWindowMaximizeButton(bool Value)
    {
        GCHandle Handle = GCHandle::FromIntPtr(IntPtr(NGWCAdress));
        GWCpp::PGWC^ T = safe_cast<GWCpp::PGWC^>(Handle.Target);
        T->WindowMaximizeButton = Value;
    }



    /*
        Proprietà disegno.
    */

    // Pen Color.
    void NGWC::DefaultPenColor()
    {
        GCHandle Handle = GCHandle::FromIntPtr(IntPtr(NGWCAdress));
        GWCpp::PGWC^ T = safe_cast<GWCpp::PGWC^>(Handle.Target);
        T->DefaultPenColor();
    }

    NGColor NGWC::GetPenColor()
    {
        GCHandle Handle = GCHandle::FromIntPtr(IntPtr(NGWCAdress));
        GWCpp::PGWC^ T = safe_cast<GWCpp::PGWC^>(Handle.Target);
        return NGColor{ T->PenColor.R, T->PenColor.G, T->PenColor.B };
    }

    void NGWC::SetPenColor(NGColor Value)
    {
        GCHandle Handle = GCHandle::FromIntPtr(IntPtr(NGWCAdress));
        GWCpp::PGWC^ T = safe_cast<GWCpp::PGWC^>(Handle.Target);
        T->PenColor = GWCpp::GColor(Value.R, Value.G, Value.B);
    }

    // Pen Width.
    void NGWC::DefaultPenWidth()
    {
        GCHandle Handle = GCHandle::FromIntPtr(IntPtr(NGWCAdress));
        GWCpp::PGWC^ T = safe_cast<GWCpp::PGWC^>(Handle.Target);
        T->DefaultPenWidth();
    }

    float NGWC::GetPenWidth()
    {
        GCHandle Handle = GCHandle::FromIntPtr(IntPtr(NGWCAdress));
        GWCpp::PGWC^ T = safe_cast<GWCpp::PGWC^>(Handle.Target);
        return T->PenWidth;
    }

    void NGWC::SetPenWidth(float Value)
    {
        GCHandle Handle = GCHandle::FromIntPtr(IntPtr(NGWCAdress));
        GWCpp::PGWC^ T = safe_cast<GWCpp::PGWC^>(Handle.Target);
        T->PenWidth = Value;
    }

    // Fill Color.
    void NGWC::DefaultFillColor()
    {
        GCHandle Handle = GCHandle::FromIntPtr(IntPtr(NGWCAdress));
        GWCpp::PGWC^ T = safe_cast<GWCpp::PGWC^>(Handle.Target);
        T->DefaultFillColor();
    }

    NGColor NGWC::GetFillColor()
    {
        GCHandle Handle = GCHandle::FromIntPtr(IntPtr(NGWCAdress));
        GWCpp::PGWC^ T = safe_cast<GWCpp::PGWC^>(Handle.Target);
        return NGColor{ T->FillColor.R, T->FillColor.G, T->FillColor.B };
    }

    void NGWC::SetFillColor(NGColor Value)
    {
        GCHandle Handle = GCHandle::FromIntPtr(IntPtr(NGWCAdress));
        GWCpp::PGWC^ T = safe_cast<GWCpp::PGWC^>(Handle.Target);
        T->FillColor = GWCpp::GColor(Value.R, Value.G, Value.B);
    }

    // Font Name.
    void NGWC::DefaultFontName()
    {
        GCHandle Handle = GCHandle::FromIntPtr(IntPtr(NGWCAdress));
        GWCpp::PGWC^ T = safe_cast<GWCpp::PGWC^>(Handle.Target);
        T->DefaultFontName();
    }

    std::string NGWC::GetFontName()
    {
        GCHandle Handle = GCHandle::FromIntPtr(IntPtr(NGWCAdress));
        GWCpp::PGWC^ T = safe_cast<GWCpp::PGWC^>(Handle.Target);
        return MStringToUString(T->FontName);
    }

    void NGWC::SetFontName(std::string Value)
    {
        GCHandle Handle = GCHandle::FromIntPtr(IntPtr(NGWCAdress));
        GWCpp::PGWC^ T = safe_cast<GWCpp::PGWC^>(Handle.Target);
        T->FontName = UStringToMString(Value);
    }

    // Font Size.
    void NGWC::DefaultFontSize()
    {
        GCHandle Handle = GCHandle::FromIntPtr(IntPtr(NGWCAdress));
        GWCpp::PGWC^ T = safe_cast<GWCpp::PGWC^>(Handle.Target);
        T->DefaultFontSize();
    }

    float NGWC::GetFontSize()
    {
        GCHandle Handle = GCHandle::FromIntPtr(IntPtr(NGWCAdress));
        GWCpp::PGWC^ T = safe_cast<GWCpp::PGWC^>(Handle.Target);
        return T->FontSize;
    }

    void NGWC::SetFontSize(float Value)
    {
        GCHandle Handle = GCHandle::FromIntPtr(IntPtr(NGWCAdress));
        GWCpp::PGWC^ T = safe_cast<GWCpp::PGWC^>(Handle.Target);
        T->FontSize = Value;
    }



    /*
        Metodo disegno.
    */

    // Clear Window.
    void NGWC::ClearWindow()
    {
        GCHandle Handle = GCHandle::FromIntPtr(IntPtr(NGWCAdress));
        GWCpp::PGWC^ T = safe_cast<GWCpp::PGWC^>(Handle.Target);
        T->ClearWindow();
    }

    // Save Canvas.
    void NGWC::SaveCanvas()
    {
        GCHandle Handle = GCHandle::FromIntPtr(IntPtr(NGWCAdress));
        GWCpp::PGWC^ T = safe_cast<GWCpp::PGWC^>(Handle.Target);
        T->SaveCanvas();
    }

    // Restore Canvas.
    void NGWC::RestoreCanvas()
    {
        GCHandle Handle = GCHandle::FromIntPtr(IntPtr(NGWCAdress));
        GWCpp::PGWC^ T = safe_cast<GWCpp::PGWC^>(Handle.Target);
        T->RestoreCanvas();
    }

    // Draw Pixel.
    void NGWC::DrawPixel(int X, int Y)
    {
        GCHandle Handle = GCHandle::FromIntPtr(IntPtr(NGWCAdress));
        GWCpp::PGWC^ T = safe_cast<GWCpp::PGWC^>(Handle.Target);
        T->DrawPixel(X, Y);
    }

    // Draw Line.
    void NGWC::DrawLine(int X1, int Y1, int X2, int Y2)
    {
        GCHandle Handle = GCHandle::FromIntPtr(IntPtr(NGWCAdress));
        GWCpp::PGWC^ T = safe_cast<GWCpp::PGWC^>(Handle.Target);
        T->DrawLine(X1, Y1, X2, Y2);
    }

    // Draw Arc.
    void NGWC::DrawArc(int X, int Y, int W, int H, int A, int B)
    {
        GCHandle Handle = GCHandle::FromIntPtr(IntPtr(NGWCAdress));
        GWCpp::PGWC^ T = safe_cast<GWCpp::PGWC^>(Handle.Target);
        T->DrawArc(X, Y, W, H, A, B);
    }

    // Draw Bezier.
    void NGWC::DrawBezier(float X1, float Y1, float X2, float Y2, float X3, float Y3, float X4, float Y4)
    {
        GCHandle Handle = GCHandle::FromIntPtr(IntPtr(NGWCAdress));
        GWCpp::PGWC^ T = safe_cast<GWCpp::PGWC^>(Handle.Target);
        T->DrawBezier(X1, Y1, X2, Y2, X3, Y3, X4, Y4);
    }

    // Draw String.
    void NGWC::DrawString(std::string S, int X, int Y)
    {
        GCHandle Handle = GCHandle::FromIntPtr(IntPtr(NGWCAdress));
        GWCpp::PGWC^ T = safe_cast<GWCpp::PGWC^>(Handle.Target);
        T->DrawString(gcnew String(S.c_str()), X, Y);
    }

    // Draw Image From File.
    void NGWC::DrawImageFromFile(std::string F, int X, int Y)
    {
        GCHandle Handle = GCHandle::FromIntPtr(IntPtr(NGWCAdress));
        GWCpp::PGWC^ T = safe_cast<GWCpp::PGWC^>(Handle.Target);
        T->DrawImageFromFile(gcnew String(F.c_str()), X, Y);
    }

    // Draw Icon From File.
    void NGWC::DrawIconFromFile(std::string F, int X, int Y)
    {
        GCHandle Handle = GCHandle::FromIntPtr(IntPtr(NGWCAdress));
        GWCpp::PGWC^ T = safe_cast<GWCpp::PGWC^>(Handle.Target);
        T->DrawIconFromFile(gcnew String(F.c_str()), X, Y);
    }

    // Draw Square.
    void NGWC::DrawSquare(int X, int Y, int L)
    {
        GCHandle Handle = GCHandle::FromIntPtr(IntPtr(NGWCAdress));
        GWCpp::PGWC^ T = safe_cast<GWCpp::PGWC^>(Handle.Target);
        T->DrawSquare(X, Y, L);
    }

    // Draw Fill Square.
    void NGWC::DrawFullSquare(int X, int Y, int L)
    {
        GCHandle Handle = GCHandle::FromIntPtr(IntPtr(NGWCAdress));
        GWCpp::PGWC^ T = safe_cast<GWCpp::PGWC^>(Handle.Target);
        T->DrawFullSquare(X, Y, L);
    }

    // Draw Rectangle.
    void NGWC::DrawRectangle(int X, int Y, int W, int H)
    {
        GCHandle Handle = GCHandle::FromIntPtr(IntPtr(NGWCAdress));
        GWCpp::PGWC^ T = safe_cast<GWCpp::PGWC^>(Handle.Target);
        T->DrawRectangle(X, Y, W, H);
    }

    // Draw Fill Rectangle.
    void NGWC::DrawFullRectangle(int X, int Y, int W, int H)
    {
        GCHandle Handle = GCHandle::FromIntPtr(IntPtr(NGWCAdress));
        GWCpp::PGWC^ T = safe_cast<GWCpp::PGWC^>(Handle.Target);
        T->DrawFullRectangle(X, Y, W, H);
    }

    // Draw Ellipse.
    void NGWC::DrawEllipse(int X, int Y, int W, int H)
    {
        GCHandle Handle = GCHandle::FromIntPtr(IntPtr(NGWCAdress));
        GWCpp::PGWC^ T = safe_cast<GWCpp::PGWC^>(Handle.Target);
        T->DrawEllipse(X, Y, W, H);
    }

    // Draw Fill Ellipse.
    void NGWC::DrawFullEllipse(int X, int Y, int W, int H)
    {
        GCHandle Handle = GCHandle::FromIntPtr(IntPtr(NGWCAdress));
        GWCpp::PGWC^ T = safe_cast<GWCpp::PGWC^>(Handle.Target);
        T->DrawFullEllipse(X, Y, W, H);
    }

    // Draw Circle.
    void NGWC::DrawCircle(int X, int Y, int R)
    {
        GCHandle Handle = GCHandle::FromIntPtr(IntPtr(NGWCAdress));
        GWCpp::PGWC^ T = safe_cast<GWCpp::PGWC^>(Handle.Target);
        T->DrawCircle(X, Y, R);
    }

    // Draw Fill Circle.
    void NGWC::DrawFullCircle(int X, int Y, int R)
    {
        GCHandle Handle = GCHandle::FromIntPtr(IntPtr(NGWCAdress));
        GWCpp::PGWC^ T = safe_cast<GWCpp::PGWC^>(Handle.Target);
        T->DrawFullCircle(X, Y, R);
    }

    // Draw Pie.
    void NGWC::DrawPie(int X, int Y, int W, int H, int A, int B)
    {
        GCHandle Handle = GCHandle::FromIntPtr(IntPtr(NGWCAdress));
        GWCpp::PGWC^ T = safe_cast<GWCpp::PGWC^>(Handle.Target);
        T->DrawPie(X, Y, W, H, A, B);
    }

    // Draw Fill Pie.
    void NGWC::DrawFullPie(int X, int Y, int W, int H, int A, int B)
    {
        GCHandle Handle = GCHandle::FromIntPtr(IntPtr(NGWCAdress));
        GWCpp::PGWC^ T = safe_cast<GWCpp::PGWC^>(Handle.Target);
        T->DrawFullPie(X, Y, W, H, A, B);
    }

    // Draw From Screen.
    void NGWC::DrawFromScreen(int X1, int Y1, int X2, int Y2, int W, int H)
    {
        GCHandle Handle = GCHandle::FromIntPtr(IntPtr(NGWCAdress));
        GWCpp::PGWC^ T = safe_cast<GWCpp::PGWC^>(Handle.Target);
        T->DrawFromScreen(X1, Y1, X2, Y2, W, H);
    }



    /*
        Metodi evento.
    */

    // Mouse Down.
    NGPoint NGWC::RequestMouseDown(NGMouseButtons B)
    {
        GCHandle Handle = GCHandle::FromIntPtr(IntPtr(NGWCAdress));
        GWCpp::PGWC^ T = safe_cast<GWCpp::PGWC^>(Handle.Target);
        return NGPoint{ T->RequestMouseDown((GWCpp::GMouseButtons)B).X, T->RequestMouseDown((GWCpp::GMouseButtons)B).Y };
    }

    NGPoint NGWC::RequestMoudeDown()
    {
        GCHandle Handle = GCHandle::FromIntPtr(IntPtr(NGWCAdress));
        GWCpp::PGWC^ T = safe_cast<GWCpp::PGWC^>(Handle.Target);
        return NGPoint{ T->RequestMouseDown().X, T->RequestMouseDown().Y };
    }

    // Mouse Up.
    NGPoint NGWC::RequestMouseUp(NGMouseButtons B)
    {
        GCHandle Handle = GCHandle::FromIntPtr(IntPtr(NGWCAdress));
        GWCpp::PGWC^ T = safe_cast<GWCpp::PGWC^>(Handle.Target);
        return NGPoint{ T->RequestMouseUp((GWCpp::GMouseButtons)B).X, T->RequestMouseUp((GWCpp::GMouseButtons)B).Y };
    }

    NGPoint NGWC::RequestMouseUp()
    {
        GCHandle Handle = GCHandle::FromIntPtr(IntPtr(NGWCAdress));
        GWCpp::PGWC^ T = safe_cast<GWCpp::PGWC^>(Handle.Target);
        return NGPoint{ T->RequestMouseUp().X, T->RequestMouseUp().Y };
    }

    // key Down.
    char NGWC::RequestKeyDown(char C)
    {
        GCHandle Handle = GCHandle::FromIntPtr(IntPtr(NGWCAdress));
        GWCpp::PGWC^ T = safe_cast<GWCpp::PGWC^>(Handle.Target);
        return T->RequestKeyUp(C);
    }

    char NGWC::RequestKeyDown()
    {
        GCHandle Handle = GCHandle::FromIntPtr(IntPtr(NGWCAdress));
        GWCpp::PGWC^ T = safe_cast<GWCpp::PGWC^>(Handle.Target);
        return T->RequestKeyUp();
    }

    // Key Up.
    char NGWC::RequestKeyUp(char C)
    {
        GCHandle Handle = GCHandle::FromIntPtr(IntPtr(NGWCAdress));
        GWCpp::PGWC^ T = safe_cast<GWCpp::PGWC^>(Handle.Target);
        return T->RequestKeyUp(C);
    }

    char NGWC::RequestKeyUp()
    {
        GCHandle Handle = GCHandle::FromIntPtr(IntPtr(NGWCAdress));
        GWCpp::PGWC^ T = safe_cast<GWCpp::PGWC^>(Handle.Target);
        return T->RequestKeyUp();
    }

}
