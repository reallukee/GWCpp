#include "pch.h"
#include "ngwc++.h"
#include "gwc++.h"


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


namespace NGWCpp
{

    /*
        Costruttori e distruttori.
    */

    // Costruttore.
    NGWC::NGWC(int W, int H, std::string Title, int X, int Y)
    {
        GWCpp::GWC^ T = gcnew GWCpp::GWC(W, H, gcnew String(Title.c_str()), X, Y);
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
    void NGWC::StartWindow()
    {
        GCHandle Handle = GCHandle::FromIntPtr(IntPtr(NGWCAdress));
        GWCpp::GWC^ T = safe_cast<GWCpp::GWC^>(Handle.Target);
        T->StartWindow();
    }

    // Close Window.
    void NGWC::CloseWindow()
    {
        GCHandle Handle = GCHandle::FromIntPtr(IntPtr(NGWCAdress));
        GWCpp::GWC^ T = safe_cast<GWCpp::GWC^>(Handle.Target);
        T->CloseWindow();
    }

    // Suspend Window.
    void NGWC::SuspendWindow()
    {
        GCHandle Handle = GCHandle::FromIntPtr(IntPtr(NGWCAdress));
        GWCpp::GWC^ T = safe_cast<GWCpp::GWC^>(Handle.Target);
        T->SuspendWindow();
    }
    
    // Resume Window.
    void NGWC::ResumeWindow()
    {
        GCHandle Handle = GCHandle::FromIntPtr(IntPtr(NGWCAdress));
        GWCpp::GWC^ T = safe_cast<GWCpp::GWC^>(Handle.Target);
        T->ResumeWindow();
    }

    // Show Window.
    void NGWC::ShowWindow()
    {
        GCHandle Handle = GCHandle::FromIntPtr(IntPtr(NGWCAdress));
        GWCpp::GWC^ T = safe_cast<GWCpp::GWC^>(Handle.Target);
        T->ShowWindow();
    }

    // Hide Window.
    void NGWC::HideWindow()
    {
        GCHandle Handle = GCHandle::FromIntPtr(IntPtr(NGWCAdress));
        GWCpp::GWC^ T = safe_cast<GWCpp::GWC^>(Handle.Target);
        T->HideWindow();
    }



    /*
        Proprietà disegno.
    */

    // Pen Color.
    void NGWC::DefaultPenColor()
    {
        GCHandle Handle = GCHandle::FromIntPtr(IntPtr(NGWCAdress));
        GWCpp::GWC^ T = safe_cast<GWCpp::GWC^>(Handle.Target);
        T->DefaultPenColor();
    }

    COLORN NGWC::GetPenColor()
    {
        GCHandle Handle = GCHandle::FromIntPtr(IntPtr(NGWCAdress));
        GWCpp::GWC^ T = safe_cast<GWCpp::GWC^>(Handle.Target);
        return COLORN{ T->PenColor.R, T->PenColor.G, T->PenColor.B };
    }

    void NGWC::SetPenColor(COLORN Value)
    {
        GCHandle Handle = GCHandle::FromIntPtr(IntPtr(NGWCAdress));
        GWCpp::GWC^ T = safe_cast<GWCpp::GWC^>(Handle.Target);
        T->PenColor = Color::FromArgb(Value.R, Value.G, Value.B);
    }
    
    // Pen Width.
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

    // Fill Color.
    void NGWC::DefaultFillColor()
    {
        GCHandle Handle = GCHandle::FromIntPtr(IntPtr(NGWCAdress));
        GWCpp::GWC^ T = safe_cast<GWCpp::GWC^>(Handle.Target);
        T->DefaultFillColor();
    }

    COLORN NGWC::GetFillColor()
    {
        GCHandle Handle = GCHandle::FromIntPtr(IntPtr(NGWCAdress));
        GWCpp::GWC^ T = safe_cast<GWCpp::GWC^>(Handle.Target);
        return COLORN{ T->FillColor.R, T->FillColor.G, T->FillColor.B };
    }

    void NGWC::SetFillColor(COLORN Value)
    {
        GCHandle Handle = GCHandle::FromIntPtr(IntPtr(NGWCAdress));
        GWCpp::GWC^ T = safe_cast<GWCpp::GWC^>(Handle.Target);
        T->FillColor = Color::FromArgb(Value.R, Value.G, Value.B);
    }

    // Font Size.
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
        Proprietà finestra.
    */

    // Window Icon Visible.
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

    // Window Location.
    POINTN NGWC::GetWindowLocation()
    {
        GCHandle Handle = GCHandle::FromIntPtr(IntPtr(NGWCAdress));
        GWCpp::GWC^ T = safe_cast<GWCpp::GWC^>(Handle.Target);
        return POINTN{T->WindowLocation.X, T->WindowLocation.Y};
    }

    void NGWC::SetWindowLocation(POINTN Value)
    {
        GCHandle Handle = GCHandle::FromIntPtr(IntPtr(NGWCAdress));
        GWCpp::GWC^ T = safe_cast<GWCpp::GWC^>(Handle.Target);
        T->WindowLocation = Point(Value.X, Value.Y);
    }

    // Window Color.
    COLORN NGWC::GetWindowColor()
    {
        GCHandle Handle = GCHandle::FromIntPtr(IntPtr(NGWCAdress));
        GWCpp::GWC^ T = safe_cast<GWCpp::GWC^>(Handle.Target);
        return COLORN{ T->WindowColor.R, T->WindowColor.G, T->WindowColor.B };
    }

    void NGWC::SetWindowColor(COLORN Value)
    {
        GCHandle Handle = GCHandle::FromIntPtr(IntPtr(NGWCAdress));
        GWCpp::GWC^ T = safe_cast<GWCpp::GWC^>(Handle.Target);
        T->WindowColor = Color::FromArgb(Value.R, Value.G, Value.B);
    }

    // Window Size.
    SIZEN NGWC::GetWindowSize()
    {
        GCHandle Handle = GCHandle::FromIntPtr(IntPtr(NGWCAdress));
        GWCpp::GWC^ T = safe_cast<GWCpp::GWC^>(Handle.Target);
        return SIZEN{ T->WindowSize.Width, T->WindowSize.Height };
    }

    void NGWC::SetWindowSize(SIZEN Value)
    {
        GCHandle Handle = GCHandle::FromIntPtr(IntPtr(NGWCAdress));
        GWCpp::GWC^ T = safe_cast<GWCpp::GWC^>(Handle.Target);
        T->WindowSize = Size(Value.W, Value.H);
    }

    // Window Minimum Size.
    SIZEN NGWC::GetWindowMinimumSize()
    {
        GCHandle Handle = GCHandle::FromIntPtr(IntPtr(NGWCAdress));
        GWCpp::GWC^ T = safe_cast<GWCpp::GWC^>(Handle.Target);
        return SIZEN{ T->WindowMinimumSize.Width, T->WindowMinimumSize.Height };
    }

    void NGWC::SetWindowMinimumSize(SIZEN Value)
    {
        GCHandle Handle = GCHandle::FromIntPtr(IntPtr(NGWCAdress));
        GWCpp::GWC^ T = safe_cast<GWCpp::GWC^>(Handle.Target);
        T->WindowMinimumSize = Size(Value.W, Value.H);
    }

    // Window Maximum Size.
    SIZEN NGWC::GetWindowMaximumSize()
    {
        GCHandle Handle = GCHandle::FromIntPtr(IntPtr(NGWCAdress));
        GWCpp::GWC^ T = safe_cast<GWCpp::GWC^>(Handle.Target);
        return SIZEN{ T->WindowMaximumSize.Width, T->WindowMaximumSize.Height };
    }

    void NGWC::SetWindowMaximumSize(SIZEN Value)
    {
        GCHandle Handle = GCHandle::FromIntPtr(IntPtr(NGWCAdress));
        GWCpp::GWC^ T = safe_cast<GWCpp::GWC^>(Handle.Target);
        T->WindowMaximumSize = Size(Value.W, Value.H);
    }

    // Window Opacity.
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

    // Window Always On Top.
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

    // Window In Taskbar.
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

    // Window Minimize Button.
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

    // Window Maximize Button.
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
        Metodo disegno.
    */

    void NGWC::ClearWindow()
    {
        GCHandle Handle = GCHandle::FromIntPtr(IntPtr(NGWCAdress));
        GWCpp::GWC^ T = safe_cast<GWCpp::GWC^>(Handle.Target);
        T->ClearWindow();
    }

    void NGWC::DrawFromScreen(int X1, int Y1, int X2, int Y2, int W, int H)
    {
        GCHandle Handle = GCHandle::FromIntPtr(IntPtr(NGWCAdress));
        GWCpp::GWC^ T = safe_cast<GWCpp::GWC^>(Handle.Target);
        T->DrawFromScreen(X1, Y1, X2, Y2, W, H);
    }

    void NGWC::SaveCanvas()
    {
        GCHandle Handle = GCHandle::FromIntPtr(IntPtr(NGWCAdress));
        GWCpp::GWC^ T = safe_cast<GWCpp::GWC^>(Handle.Target);
        T->SaveCanvas();
    }

    void NGWC::RestoreCanvas()
    {
        GCHandle Handle = GCHandle::FromIntPtr(IntPtr(NGWCAdress));
        GWCpp::GWC^ T = safe_cast<GWCpp::GWC^>(Handle.Target);
        T->RestoreCanvas();
    }

    void NGWC::DrawLine(int X1, int Y1, int X2, int Y2)
    {
        GCHandle Handle = GCHandle::FromIntPtr(IntPtr(NGWCAdress));
        GWCpp::GWC^ T = safe_cast<GWCpp::GWC^>(Handle.Target);
        T->DrawLine(X1, Y1, X2, Y2);
    }

    void NGWC::DrawArc(int X, int Y, int W, int H, int A, int B)
    {
        GCHandle Handle = GCHandle::FromIntPtr(IntPtr(NGWCAdress));
        GWCpp::GWC^ T = safe_cast<GWCpp::GWC^>(Handle.Target);
        T->DrawArc(X, Y, W, H, A, B);
    }

    void NGWC::DrawBezier(int X1, int Y1, int X2, int Y2, int X3, int Y3, int X4, int Y4)
    {
        GCHandle Handle = GCHandle::FromIntPtr(IntPtr(NGWCAdress));
        GWCpp::GWC^ T = safe_cast<GWCpp::GWC^>(Handle.Target);
        T->DrawBezier(X1, Y1, X2, Y2, X3, Y3, X4, Y4);
    }

    void NGWC::DrawText(std::string S, int X, int Y)
    {
        GCHandle Handle = GCHandle::FromIntPtr(IntPtr(NGWCAdress));
        GWCpp::GWC^ T = safe_cast<GWCpp::GWC^>(Handle.Target);
        T->DrawText(gcnew String(S.c_str()), X, Y);
    }

    void NGWC::DrawImageFromFile(std::string F, int X, int Y)
    {
        GCHandle Handle = GCHandle::FromIntPtr(IntPtr(NGWCAdress));
        GWCpp::GWC^ T = safe_cast<GWCpp::GWC^>(Handle.Target);
        T->DrawImageFromFile(gcnew String(F.c_str()), X, Y);
    }

    void NGWC::DrawIconFromFile(std::string F, int X, int Y)
    {
        GCHandle Handle = GCHandle::FromIntPtr(IntPtr(NGWCAdress));
        GWCpp::GWC^ T = safe_cast<GWCpp::GWC^>(Handle.Target);
        T->DrawIconFromFile(gcnew String(F.c_str()), X, Y);
    }

    void NGWC::DrawRectangle(int X, int Y, int W, int H)
    {
        GCHandle Handle = GCHandle::FromIntPtr(IntPtr(NGWCAdress));
        GWCpp::GWC^ T = safe_cast<GWCpp::GWC^>(Handle.Target);
        T->DrawRectangle(X, Y, W, H);
    }

    void NGWC::DrawFillRectangle(int X, int Y, int W, int H)
    {
        GCHandle Handle = GCHandle::FromIntPtr(IntPtr(NGWCAdress));
        GWCpp::GWC^ T = safe_cast<GWCpp::GWC^>(Handle.Target);
        T->DrawFillRectangle(X, Y, W, H);
    }

    void NGWC::DrawEllipse(int X, int Y, int W, int H)
    {
        GCHandle Handle = GCHandle::FromIntPtr(IntPtr(NGWCAdress));
        GWCpp::GWC^ T = safe_cast<GWCpp::GWC^>(Handle.Target);
        T->DrawEllipse(X, Y, W, H);
    }

    void NGWC::DrawFillEllipse(int X, int Y, int W, int H)
    {
        GCHandle Handle = GCHandle::FromIntPtr(IntPtr(NGWCAdress));
        GWCpp::GWC^ T = safe_cast<GWCpp::GWC^>(Handle.Target);
        T->DrawFillEllipse(X, Y, W, H);
    }

    void NGWC::DrawPie(int X, int Y, int W, int H, int A, int B)
    {
        GCHandle Handle = GCHandle::FromIntPtr(IntPtr(NGWCAdress));
        GWCpp::GWC^ T = safe_cast<GWCpp::GWC^>(Handle.Target);
        T->DrawPie(X, Y, W, H, A, B);
    }

    void NGWC::DrawFillPie(int X, int Y, int W, int H, int A, int B)
    {
        GCHandle Handle = GCHandle::FromIntPtr(IntPtr(NGWCAdress));
        GWCpp::GWC^ T = safe_cast<GWCpp::GWC^>(Handle.Target);
        T->DrawFillPie(X, Y, W, H, A, B);
    }



    /*
        Metodi evento.
    */

    // Mouse Down.
    POINT NGWC::RequestMouseDown(int B)
    {
        GCHandle Handle = GCHandle::FromIntPtr(IntPtr(NGWCAdress));
        GWCpp::GWC^ T = safe_cast<GWCpp::GWC^>(Handle.Target);
        return POINT{ T->RequestMouseDown(B).X, T->RequestMouseDown(B).Y };
    }

    // Mouse Up.
    POINT NGWC::RequestMouseUp(int B)
    {
        GCHandle Handle = GCHandle::FromIntPtr(IntPtr(NGWCAdress));
        GWCpp::GWC^ T = safe_cast<GWCpp::GWC^>(Handle.Target);
        return POINT{ T->RequestMouseUp(B).X, T->RequestMouseUp(B).Y };
    }

    // key Down.
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

    // Key Up.
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



    /*
        Metodi vari.
    */

    void NGWC::Default()
    {
        GCHandle Handle = GCHandle::FromIntPtr(IntPtr(NGWCAdress));
        GWCpp::GWC^ T = safe_cast<GWCpp::GWC^>(Handle.Target);
        T->Default();
    }

    int NGWC::GetScreenMaxX()
    {
        GCHandle Handle = GCHandle::FromIntPtr(IntPtr(NGWCAdress));
        GWCpp::GWC^ T = safe_cast<GWCpp::GWC^>(Handle.Target);
        return T->GetScreenMaxX();
    }

    int NGWC::GetScreenMaxY()
    {
        GCHandle Handle = GCHandle::FromIntPtr(IntPtr(NGWCAdress));
        GWCpp::GWC^ T = safe_cast<GWCpp::GWC^>(Handle.Target);
        return T->GetScreenMaxY();
    }

    int NGWC::GetWindowMaxX()
    {
        GCHandle Handle = GCHandle::FromIntPtr(IntPtr(NGWCAdress));
        GWCpp::GWC^ T = safe_cast<GWCpp::GWC^>(Handle.Target);
        return T->GetWindowMaxX();
    }

    int NGWC::GetWindowMaxY()
    {
        GCHandle Handle = GCHandle::FromIntPtr(IntPtr(NGWCAdress));
        GWCpp::GWC^ T = safe_cast<GWCpp::GWC^>(Handle.Target);
        return T->GetWindowMaxY();
    }

}
