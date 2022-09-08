/*
    GWC++ (Graphic Window for Console Application)

    - Questo progetto è sotto lincenza MIT (https://mit-license.org)
    - Questo progetto è disponibile su GitHub (https://github.com/reallukee/GWCpp)
    - Maggiori informazioni sono diponibili nel file README.md


    ATUORE:			Realluke | Aka Luca Pollicino
    DESCRIZIONE:	Classe UGWC
    DATA:			04/08/22
    VERSIONE:		1.1.2
*/

#include "pch.h"
#include "ugwc++.h"
#include "gwc++.h"
#include <msclr\marshal_cppstd.h>

#pragma managed

namespace GWCpp
{

    /*
        ### Costruttori e distruttori
        Costruttori e distruttori
    */

    #pragma region Costruttori

    UGWC::UGWC()
    {
        GWCpp::GWC^ T = gcnew GWCpp::GWC(850, 505, "GWC++ Window", 50, 50);
        GWCAdress = GCHandle::ToIntPtr(GCHandle::Alloc(T)).ToPointer();
    }

    UGWC::UGWC(int Width, int Height)
    {
        GWCpp::GWC^ T = gcnew GWCpp::GWC(Width, Height, "GWC++ Window", 50, 50);
        GWCAdress = GCHandle::ToIntPtr(GCHandle::Alloc(T)).ToPointer();
    }

    UGWC::UGWC(int Width, int Height, string Title)
    {
        GWCpp::GWC^ T = gcnew GWCpp::GWC(Width, Height, gcnew String(Title.c_str()), 50, 50);
        GWCAdress = GCHandle::ToIntPtr(GCHandle::Alloc(T)).ToPointer();
    }

    UGWC::UGWC(int Width, int Height, string Title, int X, int Y)
    {
        GWCpp::GWC^ T = gcnew GWCpp::GWC(Width, Height, gcnew String(Title.c_str()), X, Y);
        GWCAdress = GCHandle::ToIntPtr(GCHandle::Alloc(T)).ToPointer();
    }

    UGWC::~UGWC()
    {
        GCHandle Handle = GCHandle::FromIntPtr(IntPtr(GWCAdress));
        Handle.Free();
    }

    #pragma endregion



    /*
        ### Metodi conversione
        Metodi di conversione
    */
    
    #pragma region MetodiConversione

    // MString <=> UString.
    String^ UStringToMString(string Str)
    {
        msclr::interop::marshal_context Context;
        return Context.marshal_as<String^>(Str);
    }

    string MStringToUString(String^ Str)
    {
        msclr::interop::marshal_context Context;
        return Context.marshal_as<string>(Str);
    }

    // MPoint <=> UPoint.
    MPoint UPointToMPoint(UPoint Value)
    {
        return MPoint(Value.X, Value.Y);
    }

    UPoint MPointToUPoint(MPoint Value)
    {
        return UPoint{ Value.X, Value.Y };
    }

    // MColor <=> UColor.
    MColor UColorToMColor(UColor Value)
    {
        return MColor(Value.R, Value.G, Value.B);
    }

    UColor MColorToUColor(MColor Value)
    {
        return UColor{ Value.R, Value.G, Value.B };
    }

    // MSize <=> USize.
    MSize USizeToMSize(USize Value)
    {
        return MSize(Value.Width, Value.Height);
    }

    USize MSizeToUSize(MSize Value)
    {
        return USize{ Value.Width, Value.Height };
    }
    
    #pragma endregion



    /*
        ### Metodi Interattivi
        Metodi di interazione I/O
    */

    #pragma region MetodiInterattivi

    string UGWC::InputBox(string Prompt, string Title, string DefaultResponse, int X, int Y)
    {
        GCHandle Handle = GCHandle::FromIntPtr(IntPtr(GWCAdress));
        GWCpp::GWC^ T = safe_cast<GWCpp::GWC^>(Handle.Target);
        return MStringToUString(T->InputBox(UStringToMString(Prompt), UStringToMString(Title), UStringToMString(DefaultResponse), X, Y));
    }

    UOutputBoxResult UGWC::OutputBox(string Prompt, UOutputBoxStyle Style, string Title)
    {
        GCHandle Handle = GCHandle::FromIntPtr(IntPtr(GWCAdress));
        GWCpp::GWC^ T = safe_cast<GWCpp::GWC^>(Handle.Target);
        return (UOutputBoxResult)T->OutputBox(UStringToMString(Prompt), (MOutputBoxStyle)Style, UStringToMString(Title));
    }

    #pragma endregion



    /*
        ### Metodi Finestra
        Metodi della finestra.
    */

    #pragma region MetodiFinestra

    bool UGWC::StartWindow()
    {
        GCHandle Handle = GCHandle::FromIntPtr(IntPtr(GWCAdress));
        GWCpp::GWC^ T = safe_cast<GWCpp::GWC^>(Handle.Target);
        return T->StartWindow();
    }



    bool UGWC::CloseWindow()
    {
        GCHandle Handle = GCHandle::FromIntPtr(IntPtr(GWCAdress));
        GWCpp::GWC^ T = safe_cast<GWCpp::GWC^>(Handle.Target);
        return T->CloseWindow();
    }



    bool UGWC::SuspendWindow()
    {
        GCHandle Handle = GCHandle::FromIntPtr(IntPtr(GWCAdress));
        GWCpp::GWC^ T = safe_cast<GWCpp::GWC^>(Handle.Target);
        return T->SuspendWindow();
    }



    bool UGWC::ResumeWindow()
    {
        GCHandle Handle = GCHandle::FromIntPtr(IntPtr(GWCAdress));
        GWCpp::GWC^ T = safe_cast<GWCpp::GWC^>(Handle.Target);
        return T->ResumeWindow();
    }



    bool UGWC::PauseWindow(int Time)
    {
        GCHandle Handle = GCHandle::FromIntPtr(IntPtr(GWCAdress));
        GWCpp::GWC^ T = safe_cast<GWCpp::GWC^>(Handle.Target);
        return T->PauseWindow(Time);
    }



    bool UGWC::RedrawWindow(int X, int Y, int Width, int Height)
    {
        GCHandle Handle = GCHandle::FromIntPtr(IntPtr(GWCAdress));
        GWCpp::GWC^ T = safe_cast<GWCpp::GWC^>(Handle.Target);
        return T->RedrawWindow(X, Y, Width, Height);
    }

    bool UGWC::RedrawWindow()
    {
        GCHandle Handle = GCHandle::FromIntPtr(IntPtr(GWCAdress));
        GWCpp::GWC^ T = safe_cast<GWCpp::GWC^>(Handle.Target);
        return T->RedrawWindow();
    }



    bool UGWC::ShowWindow()
    {
        GCHandle Handle = GCHandle::FromIntPtr(IntPtr(GWCAdress));
        GWCpp::GWC^ T = safe_cast<GWCpp::GWC^>(Handle.Target);
        return T->ShowWindow();
    }



    bool UGWC::HideWindow()
    {
        GCHandle Handle = GCHandle::FromIntPtr(IntPtr(GWCAdress));
        GWCpp::GWC^ T = safe_cast<GWCpp::GWC^>(Handle.Target);
        return T->HideWindow();
    }



    int UGWC::GetWindowMaxX()
    {
        GCHandle Handle = GCHandle::FromIntPtr(IntPtr(GWCAdress));
        GWCpp::GWC^ T = safe_cast<GWCpp::GWC^>(Handle.Target);
        return T->GetWindowMaxX();
    }

    int UGWC::GetWindowRealMaxX()
    {
        GCHandle Handle = GCHandle::FromIntPtr(IntPtr(GWCAdress));
        GWCpp::GWC^ T = safe_cast<GWCpp::GWC^>(Handle.Target);
        return T->GetWindowRealMaxX();
    }

    int UGWC::GetWindowMaxY()
    {
        GCHandle Handle = GCHandle::FromIntPtr(IntPtr(GWCAdress));
        GWCpp::GWC^ T = safe_cast<GWCpp::GWC^>(Handle.Target);
        return T->GetWindowMaxY();
    }

    int UGWC::GetWindowRealMaxY()
    {
        GCHandle Handle = GCHandle::FromIntPtr(IntPtr(GWCAdress));
        GWCpp::GWC^ T = safe_cast<GWCpp::GWC^>(Handle.Target);
        return T->GetWindowRealMaxY();
    }



    int UGWC::GetScreenMaxX()
    {
        GCHandle Handle = GCHandle::FromIntPtr(IntPtr(GWCAdress));
        GWCpp::GWC^ T = safe_cast<GWCpp::GWC^>(Handle.Target);
        return T->GetScreenMaxX();
    }

    int UGWC::GetScreenRealMaxX()
    {
        GCHandle Handle = GCHandle::FromIntPtr(IntPtr(GWCAdress));
        GWCpp::GWC^ T = safe_cast<GWCpp::GWC^>(Handle.Target);
        return T->GetScreenRealMaxX();
    }

    int UGWC::GetScreenMaxY()
    {
        GCHandle Handle = GCHandle::FromIntPtr(IntPtr(GWCAdress));
        GWCpp::GWC^ T = safe_cast<GWCpp::GWC^>(Handle.Target);
        return T->GetScreenMaxY();
    }

    int UGWC::GetScreenRealMaxY()
    {
        GCHandle Handle = GCHandle::FromIntPtr(IntPtr(GWCAdress));
        GWCpp::GWC^ T = safe_cast<GWCpp::GWC^>(Handle.Target);
        return T->GetScreenRealMaxY();
    }



    UPoint UGWC::RequestMouseDown(UMouseButtons B)
    {
        GCHandle Handle = GCHandle::FromIntPtr(IntPtr(GWCAdress));
        GWCpp::GWC^ T = safe_cast<GWCpp::GWC^>(Handle.Target);
        return UPoint{ T->RequestMouseDown((GWCpp::MMouseButtons)B).X, T->RequestMouseDown((GWCpp::MMouseButtons)B).Y };
    }

    UPoint UGWC::RequestMouseDown()
    {
        GCHandle Handle = GCHandle::FromIntPtr(IntPtr(GWCAdress));
        GWCpp::GWC^ T = safe_cast<GWCpp::GWC^>(Handle.Target);
        return UPoint{ T->RequestMouseDown().X, T->RequestMouseDown().Y };
    }



    UPoint UGWC::RequestMouseUp(UMouseButtons B)
    {
        GCHandle Handle = GCHandle::FromIntPtr(IntPtr(GWCAdress));
        GWCpp::GWC^ T = safe_cast<GWCpp::GWC^>(Handle.Target);
        return UPoint{ T->RequestMouseUp((GWCpp::MMouseButtons)B).X, T->RequestMouseUp((GWCpp::MMouseButtons)B).Y };
    }

    UPoint UGWC::RequestMouseUp()
    {
        GCHandle Handle = GCHandle::FromIntPtr(IntPtr(GWCAdress));
        GWCpp::GWC^ T = safe_cast<GWCpp::GWC^>(Handle.Target);
        return UPoint{ T->RequestMouseUp().X, T->RequestMouseUp().Y };
    }



    char UGWC::RequestKeyDown(char C)
    {
        GCHandle Handle = GCHandle::FromIntPtr(IntPtr(GWCAdress));
        GWCpp::GWC^ T = safe_cast<GWCpp::GWC^>(Handle.Target);
        return T->RequestKeyUp(C);
    }

    char UGWC::RequestKeyDown()
    {
        GCHandle Handle = GCHandle::FromIntPtr(IntPtr(GWCAdress));
        GWCpp::GWC^ T = safe_cast<GWCpp::GWC^>(Handle.Target);
        return T->RequestKeyUp();
    }



    char UGWC::RequestKeyUp(char C)
    {
        GCHandle Handle = GCHandle::FromIntPtr(IntPtr(GWCAdress));
        GWCpp::GWC^ T = safe_cast<GWCpp::GWC^>(Handle.Target);
        return T->RequestKeyUp(C);
    }

    char UGWC::RequestKeyUp()
    {
        GCHandle Handle = GCHandle::FromIntPtr(IntPtr(GWCAdress));
        GWCpp::GWC^ T = safe_cast<GWCpp::GWC^>(Handle.Target);
        return T->RequestKeyUp();
    }

    #pragma endregion

    

    /*
        ### Proprietà finestra.
        Proprietà della finestra
    */

    #pragma region ProprietàFinestra

    bool UGWC::GetWindowStarted()
    {
        GCHandle Handle = GCHandle::FromIntPtr(IntPtr(GWCAdress));
        GWCpp::GWC^ T = safe_cast<GWCpp::GWC^>(Handle.Target);
        return T->WindowStarted;
    }



    bool UGWC::GetWindowClosed()
    {
        GCHandle Handle = GCHandle::FromIntPtr(IntPtr(GWCAdress));
        GWCpp::GWC^ T = safe_cast<GWCpp::GWC^>(Handle.Target);
        return T->WindowClosed;
    }



    bool UGWC::GetWindowSuspended()
    {
        GCHandle Handle = GCHandle::FromIntPtr(IntPtr(GWCAdress));
        GWCpp::GWC^ T = safe_cast<GWCpp::GWC^>(Handle.Target);
        return T->WindowSuspended;
    }



    bool UGWC::GetWindowVisible()
    {
        GCHandle Handle = GCHandle::FromIntPtr(IntPtr(GWCAdress));
        GWCpp::GWC^ T = safe_cast<GWCpp::GWC^>(Handle.Target);
        return T->WindowVisible;
    }



    UPoint UGWC::GetMouseLocation()
    {
        GCHandle Handle = GCHandle::FromIntPtr(IntPtr(GWCAdress));
        GWCpp::GWC^ T = safe_cast<GWCpp::GWC^>(Handle.Target);
        return MPointToUPoint(T->MouseLocation);
    }

    void UGWC::SetMouseLocation(UPoint Value)
    {
        GCHandle Handle = GCHandle::FromIntPtr(IntPtr(GWCAdress));
        GWCpp::GWC^ T = safe_cast<GWCpp::GWC^>(Handle.Target);
        T->MouseLocation = UPointToMPoint(Value);
    }

    int UGWC::GetMouseX()
    {
        GCHandle Handle = GCHandle::FromIntPtr(IntPtr(GWCAdress));
        GWCpp::GWC^ T = safe_cast<GWCpp::GWC^>(Handle.Target);
        return T->MouseX;
    }

    void UGWC::SetMouseX(int Value)
    {
        GCHandle Handle = GCHandle::FromIntPtr(IntPtr(GWCAdress));
        GWCpp::GWC^ T = safe_cast<GWCpp::GWC^>(Handle.Target);
        T->MouseX = Value;
    }

    int UGWC::GetMouseY()
    {
        GCHandle Handle = GCHandle::FromIntPtr(IntPtr(GWCAdress));
        GWCpp::GWC^ T = safe_cast<GWCpp::GWC^>(Handle.Target);
        return T->MouseY;
    }

    void UGWC::SetMouseY(int Value) 
    {
        GCHandle Handle = GCHandle::FromIntPtr(IntPtr(GWCAdress));
        GWCpp::GWC^ T = safe_cast<GWCpp::GWC^>(Handle.Target);
        T->MouseY = Value;
    }



    string UGWC::GetWindowTitle()
    {
        GCHandle Handle = GCHandle::FromIntPtr(IntPtr(GWCAdress));
        GWCpp::GWC^ T = safe_cast<GWCpp::GWC^>(Handle.Target);
        return MStringToUString(T->WindowTitle);
    }

    void UGWC::SetWindowTitle(string Value)
    {
        GCHandle Handle = GCHandle::FromIntPtr(IntPtr(GWCAdress));
        GWCpp::GWC^ T = safe_cast<GWCpp::GWC^>(Handle.Target);
        T->WindowTitle = UStringToMString(Value);
    }

    void UGWC::DefaultWindowTitle()
    {
        GCHandle Handle = GCHandle::FromIntPtr(IntPtr(GWCAdress));
        GWCpp::GWC^ T = safe_cast<GWCpp::GWC^>(Handle.Target);
        T->DefaultWindowTitle();
    }



    HICON UGWC::GetWindowIcon()
    {
        GCHandle Handle = GCHandle::FromIntPtr(IntPtr(GWCAdress));
        GWCpp::GWC^ T = safe_cast<GWCpp::GWC^>(Handle.Target);
        return (HICON)T->WindowIcon->Handle.ToPointer();
    }

    void UGWC::SetWindowIcon(HICON Value)
    {
        GCHandle Handle = GCHandle::FromIntPtr(IntPtr(GWCAdress));
        GWCpp::GWC^ T = safe_cast<GWCpp::GWC^>(Handle.Target);
        T->WindowIcon = Icon::FromHandle((IntPtr)Value);
    }

    void UGWC::DefaultWindowIcon()
    {
        GCHandle Handle = GCHandle::FromIntPtr(IntPtr(GWCAdress));
        GWCpp::GWC^ T = safe_cast<GWCpp::GWC^>(Handle.Target);
        T->DefaultWindowIcon();
    }
    


    bool UGWC::GetWindowIconVisible()
    {
        GCHandle Handle = GCHandle::FromIntPtr(IntPtr(GWCAdress));
        GWCpp::GWC^ T = safe_cast<GWCpp::GWC^>(Handle.Target);
        return T->WindowIconVisible;
    }

    void UGWC::SetWindowIconVisible(bool Value)
    {
        GCHandle Handle = GCHandle::FromIntPtr(IntPtr(GWCAdress));
        GWCpp::GWC^ T = safe_cast<GWCpp::GWC^>(Handle.Target);
        T->WindowIconVisible = Value;
    }

    void UGWC::DefaultWindowIconVisible()
    {
        GCHandle Handle = GCHandle::FromIntPtr(IntPtr(GWCAdress));
        GWCpp::GWC^ T = safe_cast<GWCpp::GWC^>(Handle.Target);
        T->DefaultWindowIconVisible();
    }



    UPoint UGWC::GetWindowLocation()
    {
        GCHandle Handle = GCHandle::FromIntPtr(IntPtr(GWCAdress));
        GWCpp::GWC^ T = safe_cast<GWCpp::GWC^>(Handle.Target);
        return UPoint{ T->WindowLocation.X, T->WindowLocation.Y };
    }

    void UGWC::SetWindowLocation(UPoint Value)
    {
        GCHandle Handle = GCHandle::FromIntPtr(IntPtr(GWCAdress));
        GWCpp::GWC^ T = safe_cast<GWCpp::GWC^>(Handle.Target);
        T->WindowLocation = GWCpp::MPoint(Value.X, Value.Y);
    }

    int UGWC::GetWindowX()
    {
        GCHandle Handle = GCHandle::FromIntPtr(IntPtr(GWCAdress));
        GWCpp::GWC^ T = safe_cast<GWCpp::GWC^>(Handle.Target);
        return T->WindowX;
    }

    void UGWC::SetWindowX(int Value)
    {
        GCHandle Handle = GCHandle::FromIntPtr(IntPtr(GWCAdress));
        GWCpp::GWC^ T = safe_cast<GWCpp::GWC^>(Handle.Target);
        T->WindowX = Value;
    }

    int UGWC::GetWindowY()
    {
        GCHandle Handle = GCHandle::FromIntPtr(IntPtr(GWCAdress));
        GWCpp::GWC^ T = safe_cast<GWCpp::GWC^>(Handle.Target);
        return T->WindowY;
    }

    void UGWC::SetWindowY(int Value)
    {
        GCHandle Handle = GCHandle::FromIntPtr(IntPtr(GWCAdress));
        GWCpp::GWC^ T = safe_cast<GWCpp::GWC^>(Handle.Target);
        T->WindowY = Value;
    }

    void UGWC::DefaultWindowLocation()
    {
        GCHandle Handle = GCHandle::FromIntPtr(IntPtr(GWCAdress));
        GWCpp::GWC^ T = safe_cast<GWCpp::GWC^>(Handle.Target);
        T->DefaultWindowLocation();
    }

    void UGWC::DefaultWindowX()
    {
        GCHandle Handle = GCHandle::FromIntPtr(IntPtr(GWCAdress));
        GWCpp::GWC^ T = safe_cast<GWCpp::GWC^>(Handle.Target);
        T->DefaultWindowX();
    }

    void UGWC::DefaultWindowY()
    {
        GCHandle Handle = GCHandle::FromIntPtr(IntPtr(GWCAdress));
        GWCpp::GWC^ T = safe_cast<GWCpp::GWC^>(Handle.Target);
        T->DefaultWindowY();
    }



    UColor UGWC::GetWindowColor()
    {
        GCHandle Handle = GCHandle::FromIntPtr(IntPtr(GWCAdress));
        GWCpp::GWC^ T = safe_cast<GWCpp::GWC^>(Handle.Target);
        return UColor{ T->WindowColor.R, T->WindowColor.G, T->WindowColor.B };
    }

    void UGWC::SetWindowColor(UColor Value)
    {
        GCHandle Handle = GCHandle::FromIntPtr(IntPtr(GWCAdress));
        GWCpp::GWC^ T = safe_cast<GWCpp::GWC^>(Handle.Target);
        T->WindowColor = GWCpp::MColor(Value.R, Value.G, Value.B);
    }

    void UGWC::DefaultWindowColor()
    {
        GCHandle Handle = GCHandle::FromIntPtr(IntPtr(GWCAdress));
        GWCpp::GWC^ T = safe_cast<GWCpp::GWC^>(Handle.Target);
        T->DefaultWindowColor();
    }



    HBITMAP UGWC::GetWindowImage()
    {
        GCHandle Handle = GCHandle::FromIntPtr(IntPtr(GWCAdress));
        GWCpp::GWC^ T = safe_cast<GWCpp::GWC^>(Handle.Target);
        return (HBITMAP)((Bitmap^)T->WindowImage)->GetHbitmap().ToPointer();
    }

    void UGWC::SetWindowImage(HBITMAP Value)
    {
        GCHandle Handle = GCHandle::FromIntPtr(IntPtr(GWCAdress));
        GWCpp::GWC^ T = safe_cast<GWCpp::GWC^>(Handle.Target);
        T->WindowImage = Image::FromHbitmap((IntPtr)Value);
    }

    void UGWC::DefaultWindowImage()
    {
        GCHandle Handle = GCHandle::FromIntPtr(IntPtr(GWCAdress));
        GWCpp::GWC^ T = safe_cast<GWCpp::GWC^>(Handle.Target);
        T->DefaultWindowImage();
    }
    


    USize UGWC::GetWindowSize()
    {
        GCHandle Handle = GCHandle::FromIntPtr(IntPtr(GWCAdress));
        GWCpp::GWC^ T = safe_cast<GWCpp::GWC^>(Handle.Target);
        return USize{ T->WindowSize.Width, T->WindowSize.Height };
    }

    void UGWC::SetWindowSize(USize Value)
    {
        GCHandle Handle = GCHandle::FromIntPtr(IntPtr(GWCAdress));
        GWCpp::GWC^ T = safe_cast<GWCpp::GWC^>(Handle.Target);
        T->WindowSize = GWCpp::MSize(Value.Width, Value.Height);
    }

    int UGWC::GetWindowWidth()
    {
        GCHandle Handle = GCHandle::FromIntPtr(IntPtr(GWCAdress));
        GWCpp::GWC^ T = safe_cast<GWCpp::GWC^>(Handle.Target);
        return T->WindowWidth;
    }

    void UGWC::SetWindowWidth(int Value)
    {
        GCHandle Handle = GCHandle::FromIntPtr(IntPtr(GWCAdress));
        GWCpp::GWC^ T = safe_cast<GWCpp::GWC^>(Handle.Target);
        T->WindowWidth = Value;
    }

    int UGWC::GetWindowHeight()
    {
        GCHandle Handle = GCHandle::FromIntPtr(IntPtr(GWCAdress));
        GWCpp::GWC^ T = safe_cast<GWCpp::GWC^>(Handle.Target);
        return T->WindowHeight;
    }

    void UGWC::SetWindowHeight(int Value)
    {
        GCHandle Handle = GCHandle::FromIntPtr(IntPtr(GWCAdress));
        GWCpp::GWC^ T = safe_cast<GWCpp::GWC^>(Handle.Target);
        T->WindowHeight = Value;
    }

    void UGWC::DefaultWindowSize()
    {
        GCHandle Handle = GCHandle::FromIntPtr(IntPtr(GWCAdress));
        GWCpp::GWC^ T = safe_cast<GWCpp::GWC^>(Handle.Target);
        T->DefaultWindowSize();
    }

    void UGWC::DefaultWindowWidth()
    {
        GCHandle Handle = GCHandle::FromIntPtr(IntPtr(GWCAdress));
        GWCpp::GWC^ T = safe_cast<GWCpp::GWC^>(Handle.Target);
        T->DefaultWindowWidth();
    }

    void UGWC::DefaultWindowHeight()
    {
        GCHandle Handle = GCHandle::FromIntPtr(IntPtr(GWCAdress));
        GWCpp::GWC^ T = safe_cast<GWCpp::GWC^>(Handle.Target);
        T->DefaultWindowHeight();
    }



    USize UGWC::GetWindowRealSize()
    {
        GCHandle Handle = GCHandle::FromIntPtr(IntPtr(GWCAdress));
        GWCpp::GWC^ T = safe_cast<GWCpp::GWC^>(Handle.Target);
        return USize{ T->WindowRealSize.Width, T->WindowRealSize.Height };
    }

    void UGWC::SetWindowRealSize(USize Value)
    {
        GCHandle Handle = GCHandle::FromIntPtr(IntPtr(GWCAdress));
        GWCpp::GWC^ T = safe_cast<GWCpp::GWC^>(Handle.Target);
        T->WindowRealSize = GWCpp::MSize(Value.Width, Value.Height);
    }

    int UGWC::GetWindowRealWidth()
    {
        GCHandle Handle = GCHandle::FromIntPtr(IntPtr(GWCAdress));
        GWCpp::GWC^ T = safe_cast<GWCpp::GWC^>(Handle.Target);
        return T->WindowRealWidth;
    }

    void UGWC::SetWindowRealWidth(int Value)
    {
        GCHandle Handle = GCHandle::FromIntPtr(IntPtr(GWCAdress));
        GWCpp::GWC^ T = safe_cast<GWCpp::GWC^>(Handle.Target);
        T->WindowRealWidth = Value;
    }

    int UGWC::GetWindowRealHeight()
    {
        GCHandle Handle = GCHandle::FromIntPtr(IntPtr(GWCAdress));
        GWCpp::GWC^ T = safe_cast<GWCpp::GWC^>(Handle.Target);
        return T->WindowRealHeight;
    }

    void UGWC::SetWindowRealHeight(int Value)
    {
        GCHandle Handle = GCHandle::FromIntPtr(IntPtr(GWCAdress));
        GWCpp::GWC^ T = safe_cast<GWCpp::GWC^>(Handle.Target);
        T->WindowRealHeight = Value;
    }

    void UGWC::DefaultWindowRealSize()
    {
        GCHandle Handle = GCHandle::FromIntPtr(IntPtr(GWCAdress));
        GWCpp::GWC^ T = safe_cast<GWCpp::GWC^>(Handle.Target);
        T->DefaultWindowRealSize();
    }

    void UGWC::DefaultWindowRealWidth()
    {
        GCHandle Handle = GCHandle::FromIntPtr(IntPtr(GWCAdress));
        GWCpp::GWC^ T = safe_cast<GWCpp::GWC^>(Handle.Target);
        T->DefaultWindowRealWidth();
    }

    void UGWC::DefaultWindowRealHeight()
    {
        GCHandle Handle = GCHandle::FromIntPtr(IntPtr(GWCAdress));
        GWCpp::GWC^ T = safe_cast<GWCpp::GWC^>(Handle.Target);
        T->DefaultWindowRealHeight();
    }



    UWindowState UGWC::GetWindowSizeState()
    {
        GCHandle Handle = GCHandle::FromIntPtr(IntPtr(GWCAdress));
        GWCpp::GWC^ T = safe_cast<GWCpp::GWC^>(Handle.Target);
        return (UWindowState)T->WindowSizeState;
    }

    void UGWC::SetWindowSizeState(UWindowState Value)
    {
        GCHandle Handle = GCHandle::FromIntPtr(IntPtr(GWCAdress));
        GWCpp::GWC^ T = safe_cast<GWCpp::GWC^>(Handle.Target);
        T->WindowSizeState = (GWCpp::MWindowState)Value;
    }

    void UGWC::DefaultWindowSizeState()
    {
        GCHandle Handle = GCHandle::FromIntPtr(IntPtr(GWCAdress));
        GWCpp::GWC^ T = safe_cast<GWCpp::GWC^>(Handle.Target);
        T->DefaultWindowSizeState();
    }



    USize UGWC::GetWindowMinimumSize()
    {
        GCHandle Handle = GCHandle::FromIntPtr(IntPtr(GWCAdress));
        GWCpp::GWC^ T = safe_cast<GWCpp::GWC^>(Handle.Target);
        return USize{ T->WindowMinimumSize.Width, T->WindowMinimumSize.Height };
    }

    void UGWC::SetWindowMinimumSize(USize Value)
    {
        GCHandle Handle = GCHandle::FromIntPtr(IntPtr(GWCAdress));
        GWCpp::GWC^ T = safe_cast<GWCpp::GWC^>(Handle.Target);
        T->WindowMinimumSize = GWCpp::MSize(Value.Width, Value.Height);
    }

    void UGWC::DefaultWindowMinimumSize()
    {
        GCHandle Handle = GCHandle::FromIntPtr(IntPtr(GWCAdress));
        GWCpp::GWC^ T = safe_cast<GWCpp::GWC^>(Handle.Target);
        T->DefaultWindowMinimumSize();
    }



    USize UGWC::GetWindowMaximumSize()
    {
        GCHandle Handle = GCHandle::FromIntPtr(IntPtr(GWCAdress));
        GWCpp::GWC^ T = safe_cast<GWCpp::GWC^>(Handle.Target);
        return USize{ T->WindowMaximumSize.Width, T->WindowMaximumSize.Height };
    }

    void UGWC::SetWindowMaximumSize(USize Value)
    {
        GCHandle Handle = GCHandle::FromIntPtr(IntPtr(GWCAdress));
        GWCpp::GWC^ T = safe_cast<GWCpp::GWC^>(Handle.Target);
        T->WindowMaximumSize = GWCpp::MSize(Value.Width, Value.Height);
    }

    void UGWC::DefaultWindowMaximumSize()
    {
        GCHandle Handle = GCHandle::FromIntPtr(IntPtr(GWCAdress));
        GWCpp::GWC^ T = safe_cast<GWCpp::GWC^>(Handle.Target);
        T->DefaultWindowMaximumSize();
    }



    double UGWC::GetWindowOpacity()
    {
        GCHandle Handle = GCHandle::FromIntPtr(IntPtr(GWCAdress));
        GWCpp::GWC^ T = safe_cast<GWCpp::GWC^>(Handle.Target);
        return T->WindowOpacity;
    }

    void UGWC::SetWindowOpacity(double Value)
    {
        GCHandle Handle = GCHandle::FromIntPtr(IntPtr(GWCAdress));
        GWCpp::GWC^ T = safe_cast<GWCpp::GWC^>(Handle.Target);
        T->WindowOpacity = Value;
    }

    void UGWC::DefaultWindowOpacity()
    {
        GCHandle Handle = GCHandle::FromIntPtr(IntPtr(GWCAdress));
        GWCpp::GWC^ T = safe_cast<GWCpp::GWC^>(Handle.Target);
        T->DefaultWindowOpacity();
    }



    bool UGWC::GetWindowAlwaysOnTop()
    {
        GCHandle Handle = GCHandle::FromIntPtr(IntPtr(GWCAdress));
        GWCpp::GWC^ T = safe_cast<GWCpp::GWC^>(Handle.Target);
        return T->WindowAlwaysOnTop;
    }

    void UGWC::SetWindowAlwaysOnTop(bool Value)
    {
        GCHandle Handle = GCHandle::FromIntPtr(IntPtr(GWCAdress));
        GWCpp::GWC^ T = safe_cast<GWCpp::GWC^>(Handle.Target);
        T->WindowAlwaysOnTop = Value;
    }

    void UGWC::DefaultWindowAlwaysOnTop()
    {
        GCHandle Handle = GCHandle::FromIntPtr(IntPtr(GWCAdress));
        GWCpp::GWC^ T = safe_cast<GWCpp::GWC^>(Handle.Target);
        T->DefaultWindowAlwaysOnTop();
    }



    bool UGWC::GetWindowInTaskbar()
    {
        GCHandle Handle = GCHandle::FromIntPtr(IntPtr(GWCAdress));
        GWCpp::GWC^ T = safe_cast<GWCpp::GWC^>(Handle.Target);
        return T->WindowInTaskbar;
    }

    void UGWC::SetWindowInTaskbar(bool Value)
    {
        GCHandle Handle = GCHandle::FromIntPtr(IntPtr(GWCAdress));
        GWCpp::GWC^ T = safe_cast<GWCpp::GWC^>(Handle.Target);
        T->WindowInTaskbar = Value;
    }

    void UGWC::DefaultWindowInTaskBar()
    {
        GCHandle Handle = GCHandle::FromIntPtr(IntPtr(GWCAdress));
        GWCpp::GWC^ T = safe_cast<GWCpp::GWC^>(Handle.Target);
        T->DefaultWindowInTaskbar();
    }


    
    bool UGWC::GetWindowButtons()
    {
        GCHandle Handle = GCHandle::FromIntPtr(IntPtr(GWCAdress));
        GWCpp::GWC^ T = safe_cast<GWCpp::GWC^>(Handle.Target);
        return T->WindowButtons;
    }

    void UGWC::SetWindowButtons(bool Value)
    {
        GCHandle Handle = GCHandle::FromIntPtr(IntPtr(GWCAdress));
        GWCpp::GWC^ T = safe_cast<GWCpp::GWC^>(Handle.Target);
        T->WindowButtons = Value;
    }

    void UGWC::DefaultWindowButtons()
    {
        GCHandle Handle = GCHandle::FromIntPtr(IntPtr(GWCAdress));
        GWCpp::GWC^ T = safe_cast<GWCpp::GWC^>(Handle.Target);
        T->DefaultWindowButtons();
    }



    bool UGWC::GetWindowMinimizeButton()
    {
        GCHandle Handle = GCHandle::FromIntPtr(IntPtr(GWCAdress));
        GWCpp::GWC^ T = safe_cast<GWCpp::GWC^>(Handle.Target);
        return T->WindowMinimizeButton;
    }

    void UGWC::SetWindowMinimizeButton(bool Value)
    {
        GCHandle Handle = GCHandle::FromIntPtr(IntPtr(GWCAdress));
        GWCpp::GWC^ T = safe_cast<GWCpp::GWC^>(Handle.Target);
        T->WindowMinimizeButton = Value;
    }

    void UGWC::DefaultWindowMinimizeButton()
    {
        GCHandle Handle = GCHandle::FromIntPtr(IntPtr(GWCAdress));
        GWCpp::GWC^ T = safe_cast<GWCpp::GWC^>(Handle.Target);
        T->DefaultWindowMinimizeButton();
    }



    bool UGWC::GetWindowMaximizeButton()
    {
        GCHandle Handle = GCHandle::FromIntPtr(IntPtr(GWCAdress));
        GWCpp::GWC^ T = safe_cast<GWCpp::GWC^>(Handle.Target);
        return T->WindowMaximizeButton;
    }

    void UGWC::SetWindowMaximizeButton(bool Value)
    {
        GCHandle Handle = GCHandle::FromIntPtr(IntPtr(GWCAdress));
        GWCpp::GWC^ T = safe_cast<GWCpp::GWC^>(Handle.Target);
        T->WindowMaximizeButton = Value;
    }

    void UGWC::DefaultWindowMaximizeButton()
    {
        GCHandle Handle = GCHandle::FromIntPtr(IntPtr(GWCAdress));
        GWCpp::GWC^ T = safe_cast<GWCpp::GWC^>(Handle.Target);
        T->DefaultWindowMaximizeButton();
    }
    
    #pragma endregion



    /*
        ### Metodi disegno
        Metodi del disegno
    */

    #pragma region MetodiDisegno

    void UGWC::SaveCanvas()
    {
        GCHandle Handle = GCHandle::FromIntPtr(IntPtr(GWCAdress));
        GWCpp::GWC^ T = safe_cast<GWCpp::GWC^>(Handle.Target);
        T->SaveCanvas();
    }

    void UGWC::SaveCanvasWoP()
    {
        GCHandle Handle = GCHandle::FromIntPtr(IntPtr(GWCAdress));
        GWCpp::GWC^ T = safe_cast<GWCpp::GWC^>(Handle.Target);
        T->SaveCanvasWoP();
    }



    void UGWC::RestoreCanvas()
    {
        GCHandle Handle = GCHandle::FromIntPtr(IntPtr(GWCAdress));
        GWCpp::GWC^ T = safe_cast<GWCpp::GWC^>(Handle.Target);
        T->RestoreCanvas();
    }

    void UGWC::RestoreCanvasWoP()
    {
        GCHandle Handle = GCHandle::FromIntPtr(IntPtr(GWCAdress));
        GWCpp::GWC^ T = safe_cast<GWCpp::GWC^>(Handle.Target);
        T->RestoreCanvasWoP();
    }



    void UGWC::ClearWindow(UColor Color)
    {
        GCHandle Handle = GCHandle::FromIntPtr(IntPtr(GWCAdress));
        GWCpp::GWC^ T = safe_cast<GWCpp::GWC^>(Handle.Target);
        T->ClearWindow(UColorToMColor(Color));
    }

    void UGWC::ClearWindow()
    {
        GCHandle Handle = GCHandle::FromIntPtr(IntPtr(GWCAdress));
        GWCpp::GWC^ T = safe_cast<GWCpp::GWC^>(Handle.Target);
        T->ClearWindow();
    }

    void UGWC::ClearWindowWoP(UColor Color)
    {
        GCHandle Handle = GCHandle::FromIntPtr(IntPtr(GWCAdress));
        GWCpp::GWC^ T = safe_cast<GWCpp::GWC^>(Handle.Target);
        T->ClearWindowWoP(UColorToMColor(Color));
    }

    void UGWC::ClearWindowWoP()
    {
        GCHandle Handle = GCHandle::FromIntPtr(IntPtr(GWCAdress));
        GWCpp::GWC^ T = safe_cast<GWCpp::GWC^>(Handle.Target);
        T->ClearWindowWoP();
    }



    void UGWC::DrawLine(int X1, int Y1, int X2, int Y2)
    {
        GCHandle Handle = GCHandle::FromIntPtr(IntPtr(GWCAdress));
        GWCpp::GWC^ T = safe_cast<GWCpp::GWC^>(Handle.Target);
        T->DrawLine(X1, Y1, X2, Y2);
    }

    void UGWC::DrawLineWoP(int X1, int Y1, int X2, int Y2)
    {
        GCHandle Handle = GCHandle::FromIntPtr(IntPtr(GWCAdress));
        GWCpp::GWC^ T = safe_cast<GWCpp::GWC^>(Handle.Target);
        T->DrawLineWoP(X1, Y1, X2, Y2);
    }



    void UGWC::DrawArc(int X, int Y, int Width, int Height, int A, int B)
    {
        GCHandle Handle = GCHandle::FromIntPtr(IntPtr(GWCAdress));
        GWCpp::GWC^ T = safe_cast<GWCpp::GWC^>(Handle.Target);
        T->DrawArc(X, Y, Width, Height, A, B);
    }

    void UGWC::DrawArcWoP(int X, int Y, int Width, int Height, int A, int B)
    {
        GCHandle Handle = GCHandle::FromIntPtr(IntPtr(GWCAdress));
        GWCpp::GWC^ T = safe_cast<GWCpp::GWC^>(Handle.Target);
        T->DrawArcWoP(X, Y, Width, Height, A, B);
    }



    void UGWC::DrawBezier(float X1, float Y1, float X2, float Y2, float X3, float Y3, float X4, float Y4)
    {
        GCHandle Handle = GCHandle::FromIntPtr(IntPtr(GWCAdress));
        GWCpp::GWC^ T = safe_cast<GWCpp::GWC^>(Handle.Target);
        T->DrawBezier(X1, Y1, X2, Y2, X3, Y3, X4, Y4);
    }

    void UGWC::DrawBezierWoP(float X1, float Y1, float X2, float Y2, float X3, float Y3, float X4, float Y4)
    {
        GCHandle Handle = GCHandle::FromIntPtr(IntPtr(GWCAdress));
        GWCpp::GWC^ T = safe_cast<GWCpp::GWC^>(Handle.Target);
        T->DrawBezierWoP(X1, Y1, X2, Y2, X3, Y3, X4, Y4);
    }



    void UGWC::DrawPixel(int X, int Y)
    {
        GCHandle Handle = GCHandle::FromIntPtr(IntPtr(GWCAdress));
        GWCpp::GWC^ T = safe_cast<GWCpp::GWC^>(Handle.Target);
        T->DrawPixel(X, Y);
    }

    void UGWC::DrawPixelWoP(int X, int Y)
    {
        GCHandle Handle = GCHandle::FromIntPtr(IntPtr(GWCAdress));
        GWCpp::GWC^ T = safe_cast<GWCpp::GWC^>(Handle.Target);
        T->DrawPixelWoP(X, Y);
    }



    void UGWC::DrawString(string Stringa, int X, int Y)
    {
        GCHandle Handle = GCHandle::FromIntPtr(IntPtr(GWCAdress));
        GWCpp::GWC^ T = safe_cast<GWCpp::GWC^>(Handle.Target);
        T->DrawString(gcnew String(Stringa.c_str()), X, Y);
    }

    void UGWC::DrawString(string Stringa, int X, int Y, int Width, int Height)
    {
        GCHandle Handle = GCHandle::FromIntPtr(IntPtr(GWCAdress));
        GWCpp::GWC^ T = safe_cast<GWCpp::GWC^>(Handle.Target);
        T->DrawString(gcnew String(Stringa.c_str()), X, Y, Width, Height);
    }

    void UGWC::DrawStringWoP(string Stringa, int X, int Y)
    {
        GCHandle Handle = GCHandle::FromIntPtr(IntPtr(GWCAdress));
        GWCpp::GWC^ T = safe_cast<GWCpp::GWC^>(Handle.Target);
        T->DrawStringWoP(gcnew String(Stringa.c_str()), X, Y);
    }

    void UGWC::DrawStringWoP(string Stringa, int X, int Y, int Width, int Height)
    {
        GCHandle Handle = GCHandle::FromIntPtr(IntPtr(GWCAdress));
        GWCpp::GWC^ T = safe_cast<GWCpp::GWC^>(Handle.Target);
        T->DrawStringWoP(gcnew String(Stringa.c_str()), X, Y, Width, Height);
    }



    void UGWC::DrawImage(HBITMAP Image, int X, int Y)
    {
        GCHandle Handle = GCHandle::FromIntPtr(IntPtr(GWCAdress));
        GWCpp::GWC^ T = safe_cast<GWCpp::GWC^>(Handle.Target);
        T->DrawImage(Image::FromHbitmap((IntPtr)Image), X, Y);
    }

    void UGWC::DrawImage(HBITMAP Image, int X, int Y, int Width, int Height)
    {
        GCHandle Handle = GCHandle::FromIntPtr(IntPtr(GWCAdress));
        GWCpp::GWC^ T = safe_cast<GWCpp::GWC^>(Handle.Target);
        T->DrawImage(Image::FromHbitmap((IntPtr)Image), X, Y, Width, Height);
    }

    void UGWC::DrawImage(string FileName, int X, int Y)
    {
        GCHandle Handle = GCHandle::FromIntPtr(IntPtr(GWCAdress));
        GWCpp::GWC^ T = safe_cast<GWCpp::GWC^>(Handle.Target);
        T->DrawImage(gcnew String(FileName.c_str()), X, Y);
    }

    void UGWC::DrawImage(string FileName, int X, int Y, int Width, int Height)
    {
        GCHandle Handle = GCHandle::FromIntPtr(IntPtr(GWCAdress));
        GWCpp::GWC^ T = safe_cast<GWCpp::GWC^>(Handle.Target);
        T->DrawImage(gcnew String(FileName.c_str()), X, Y, Width, Height);
    }

    void UGWC::DrawImageWoP(HBITMAP Image, int X, int Y)
    {
        GCHandle Handle = GCHandle::FromIntPtr(IntPtr(GWCAdress));
        GWCpp::GWC^ T = safe_cast<GWCpp::GWC^>(Handle.Target);
        T->DrawImageWoP(Image::FromHbitmap((IntPtr)Image), X, Y);
    }

    void UGWC::DrawImageWoP(HBITMAP Image, int X, int Y, int Width, int Height)
    {
        GCHandle Handle = GCHandle::FromIntPtr(IntPtr(GWCAdress));
        GWCpp::GWC^ T = safe_cast<GWCpp::GWC^>(Handle.Target);
        T->DrawImageWoP(Image::FromHbitmap((IntPtr)Image), X, Y, Width, Height);
    }

    void UGWC::DrawImageWoP(string FileName, int X, int Y)
    {
        GCHandle Handle = GCHandle::FromIntPtr(IntPtr(GWCAdress));
        GWCpp::GWC^ T = safe_cast<GWCpp::GWC^>(Handle.Target);
        T->DrawImageWoP(gcnew String(FileName.c_str()), X, Y);
    }

    void UGWC::DrawImageWoP(string FileName, int X, int Y, int Width, int Height)
    {
        GCHandle Handle = GCHandle::FromIntPtr(IntPtr(GWCAdress));
        GWCpp::GWC^ T = safe_cast<GWCpp::GWC^>(Handle.Target);
        T->DrawImageWoP(gcnew String(FileName.c_str()), X, Y, Width, Height);
    }



    void UGWC::DrawIcon(HICON Icon, int X, int Y)
    {
        GCHandle Handle = GCHandle::FromIntPtr(IntPtr(GWCAdress));
        GWCpp::GWC^ T = safe_cast<GWCpp::GWC^>(Handle.Target);
        T->DrawIcon(System::Drawing::Icon::FromHandle((IntPtr)Icon), X, Y);
    }

    void UGWC::DrawIcon(HICON Icon, int X, int Y, int Width, int Height)
    {
        GCHandle Handle = GCHandle::FromIntPtr(IntPtr(GWCAdress));
        GWCpp::GWC^ T = safe_cast<GWCpp::GWC^>(Handle.Target);
        T->DrawIcon(System::Drawing::Icon::FromHandle((IntPtr)Icon), X, Y, Width, Height);
    }

    void UGWC::DrawIcon(string FileName, int X, int Y)
    {
        GCHandle Handle = GCHandle::FromIntPtr(IntPtr(GWCAdress));
        GWCpp::GWC^ T = safe_cast<GWCpp::GWC^>(Handle.Target);
        T->DrawIcon(gcnew String(FileName.c_str()), X, Y);
    }

    void UGWC::DrawIcon(string FileName, int X, int Y, int Width, int Height)
    {
        GCHandle Handle = GCHandle::FromIntPtr(IntPtr(GWCAdress));
        GWCpp::GWC^ T = safe_cast<GWCpp::GWC^>(Handle.Target);
        T->DrawIcon(gcnew String(FileName.c_str()), X, Y, Width, Height);
    }

    void UGWC::DrawIconWoP(HICON Icon, int X, int Y)
    {
        GCHandle Handle = GCHandle::FromIntPtr(IntPtr(GWCAdress));
        GWCpp::GWC^ T = safe_cast<GWCpp::GWC^>(Handle.Target);
        T->DrawIconWoP(System::Drawing::Icon::FromHandle((IntPtr)Icon), X, Y);
    }

    void UGWC::DrawIconWoP(HICON Icon, int X, int Y, int Width, int Height)
    {
        GCHandle Handle = GCHandle::FromIntPtr(IntPtr(GWCAdress));
        GWCpp::GWC^ T = safe_cast<GWCpp::GWC^>(Handle.Target);
        T->DrawIconWoP(System::Drawing::Icon::FromHandle((IntPtr)Icon), X, Y, Width, Height);
    }

    void UGWC::DrawIconWoP(string FileName, int X, int Y)
    {
        GCHandle Handle = GCHandle::FromIntPtr(IntPtr(GWCAdress));
        GWCpp::GWC^ T = safe_cast<GWCpp::GWC^>(Handle.Target);
        T->DrawIconWoP(gcnew String(FileName.c_str()), X, Y);
    }

    void UGWC::DrawIconWoP(string FileName, int X, int Y, int Width, int Height)
    {
        GCHandle Handle = GCHandle::FromIntPtr(IntPtr(GWCAdress));
        GWCpp::GWC^ T = safe_cast<GWCpp::GWC^>(Handle.Target);
        T->DrawIconWoP(gcnew String(FileName.c_str()), X, Y, Width, Height);
    }



    void UGWC::DrawSquare(int X, int Y, int L)
    {
        GCHandle Handle = GCHandle::FromIntPtr(IntPtr(GWCAdress));
        GWCpp::GWC^ T = safe_cast<GWCpp::GWC^>(Handle.Target);
        T->DrawSquare(X, Y, L);
    }

    void UGWC::DrawFullSquare(int X, int Y, int L)
    {
        GCHandle Handle = GCHandle::FromIntPtr(IntPtr(GWCAdress));
        GWCpp::GWC^ T = safe_cast<GWCpp::GWC^>(Handle.Target);
        T->DrawFullSquare(X, Y, L);
    }

    void UGWC::DrawSquareWoP(int X, int Y, int L)
    {
        GCHandle Handle = GCHandle::FromIntPtr(IntPtr(GWCAdress));
        GWCpp::GWC^ T = safe_cast<GWCpp::GWC^>(Handle.Target);
        T->DrawSquareWoP(X, Y, L);
    }

    void UGWC::DrawFullSquareWoP(int X, int Y, int L)
    {
        GCHandle Handle = GCHandle::FromIntPtr(IntPtr(GWCAdress));
        GWCpp::GWC^ T = safe_cast<GWCpp::GWC^>(Handle.Target);
        T->DrawFullSquareWoP(X, Y, L);
    }



    void UGWC::DrawRectangle(int X, int Y, int Width, int Height)
    {
        GCHandle Handle = GCHandle::FromIntPtr(IntPtr(GWCAdress));
        GWCpp::GWC^ T = safe_cast<GWCpp::GWC^>(Handle.Target);
        T->DrawRectangle(X, Y, Width, Height);
    }

    void UGWC::DrawFullRectangle(int X, int Y, int Width, int Height)
    {
        GCHandle Handle = GCHandle::FromIntPtr(IntPtr(GWCAdress));
        GWCpp::GWC^ T = safe_cast<GWCpp::GWC^>(Handle.Target);
        T->DrawFullRectangle(X, Y, Width, Height);
    }

    void UGWC::DrawRectangleWoP(int X, int Y, int Width, int Height)
    {
        GCHandle Handle = GCHandle::FromIntPtr(IntPtr(GWCAdress));
        GWCpp::GWC^ T = safe_cast<GWCpp::GWC^>(Handle.Target);
        T->DrawRectangleWoP(X, Y, Width, Height);
    }

    void UGWC::DrawFullRectangleWoP(int X, int Y, int Width, int Height)
    {
        GCHandle Handle = GCHandle::FromIntPtr(IntPtr(GWCAdress));
        GWCpp::GWC^ T = safe_cast<GWCpp::GWC^>(Handle.Target);
        T->DrawFullRectangleWoP(X, Y, Width, Height);
    }



    void UGWC::DrawEllipse(int X, int Y, int Width, int Height)
    {
        GCHandle Handle = GCHandle::FromIntPtr(IntPtr(GWCAdress));
        GWCpp::GWC^ T = safe_cast<GWCpp::GWC^>(Handle.Target);
        T->DrawEllipse(X, Y, Width, Height);
    }

    void UGWC::DrawFullEllipse(int X, int Y, int Width, int Height)
    {
        GCHandle Handle = GCHandle::FromIntPtr(IntPtr(GWCAdress));
        GWCpp::GWC^ T = safe_cast<GWCpp::GWC^>(Handle.Target);
        T->DrawFullEllipse(X, Y, Width, Height);
    }

    void UGWC::DrawEllipseWoP(int X, int Y, int Width, int Height)
    {
        GCHandle Handle = GCHandle::FromIntPtr(IntPtr(GWCAdress));
        GWCpp::GWC^ T = safe_cast<GWCpp::GWC^>(Handle.Target);
        T->DrawEllipseWoP(X, Y, Width, Height);
    }

    void UGWC::DrawFullEllipseWoP(int X, int Y, int Width, int Height)
    {
        GCHandle Handle = GCHandle::FromIntPtr(IntPtr(GWCAdress));
        GWCpp::GWC^ T = safe_cast<GWCpp::GWC^>(Handle.Target);
        T->DrawFullEllipseWoP(X, Y, Width, Height);
    }



    void UGWC::DrawCircle(int X, int Y, int R)
    {
        GCHandle Handle = GCHandle::FromIntPtr(IntPtr(GWCAdress));
        GWCpp::GWC^ T = safe_cast<GWCpp::GWC^>(Handle.Target);
        T->DrawCircle(X, Y, R);
    }

    void UGWC::DrawFullCircle(int X, int Y, int R)
    {
        GCHandle Handle = GCHandle::FromIntPtr(IntPtr(GWCAdress));
        GWCpp::GWC^ T = safe_cast<GWCpp::GWC^>(Handle.Target);
        T->DrawFullCircle(X, Y, R);
    }

    void UGWC::DrawCircleWoP(int X, int Y, int R)
    {
        GCHandle Handle = GCHandle::FromIntPtr(IntPtr(GWCAdress));
        GWCpp::GWC^ T = safe_cast<GWCpp::GWC^>(Handle.Target);
        T->DrawCircleWoP(X, Y, R);
    }

    void UGWC::DrawFullCircleWoP(int X, int Y, int R)
    {
        GCHandle Handle = GCHandle::FromIntPtr(IntPtr(GWCAdress));
        GWCpp::GWC^ T = safe_cast<GWCpp::GWC^>(Handle.Target);
        T->DrawFullCircleWoP(X, Y, R);
    }

    #pragma endregion



    /*
        ### Proprietà disegno
        Proprietà del disegno
    */

    #pragma region ProprietàDisegno
    
    UColor UGWC::GetPenColor()
    {
        GCHandle Handle = GCHandle::FromIntPtr(IntPtr(GWCAdress));
        GWCpp::GWC^ T = safe_cast<GWCpp::GWC^>(Handle.Target);
        return UColor{ T->PenColor.R, T->PenColor.G, T->PenColor.B };
    }

    void UGWC::SetPenColor(UColor Value)
    {
        GCHandle Handle = GCHandle::FromIntPtr(IntPtr(GWCAdress));
        GWCpp::GWC^ T = safe_cast<GWCpp::GWC^>(Handle.Target);
        T->PenColor = GWCpp::MColor(Value.R, Value.G, Value.B);
    }

    void UGWC::DefaultPenColor()
    {
        GCHandle Handle = GCHandle::FromIntPtr(IntPtr(GWCAdress));
        GWCpp::GWC^ T = safe_cast<GWCpp::GWC^>(Handle.Target);
        T->DefaultPenColor();
    }



    float UGWC::GetPenWidth()
    {
        GCHandle Handle = GCHandle::FromIntPtr(IntPtr(GWCAdress));
        GWCpp::GWC^ T = safe_cast<GWCpp::GWC^>(Handle.Target);
        return T->PenWidth;
    }

    void UGWC::SetPenWidth(float Value)
    {
        GCHandle Handle = GCHandle::FromIntPtr(IntPtr(GWCAdress));
        GWCpp::GWC^ T = safe_cast<GWCpp::GWC^>(Handle.Target);
        T->PenWidth = Value;
    }

    void UGWC::DefaultPenWidth()
    {
        GCHandle Handle = GCHandle::FromIntPtr(IntPtr(GWCAdress));
        GWCpp::GWC^ T = safe_cast<GWCpp::GWC^>(Handle.Target);
        T->DefaultPenWidth();
    }



    UColor UGWC::GetFillColor()
    {
        GCHandle Handle = GCHandle::FromIntPtr(IntPtr(GWCAdress));
        GWCpp::GWC^ T = safe_cast<GWCpp::GWC^>(Handle.Target);
        return UColor{ T->FillColor.R, T->FillColor.G, T->FillColor.B };
    }

    void UGWC::SetFillColor(UColor Value)
    {
        GCHandle Handle = GCHandle::FromIntPtr(IntPtr(GWCAdress));
        GWCpp::GWC^ T = safe_cast<GWCpp::GWC^>(Handle.Target);
        T->FillColor = GWCpp::MColor(Value.R, Value.G, Value.B);
    }

    void UGWC::DefaultFillColor()
    {
        GCHandle Handle = GCHandle::FromIntPtr(IntPtr(GWCAdress));
        GWCpp::GWC^ T = safe_cast<GWCpp::GWC^>(Handle.Target);
        T->DefaultFillColor();
    }



    UStringAlignment UGWC::GetHStringAlignment()
    {
        GCHandle Handle = GCHandle::FromIntPtr(IntPtr(GWCAdress));
        GWCpp::GWC^ T = safe_cast<GWCpp::GWC^>(Handle.Target);
        return (UStringAlignment)T->HStringAlignment;
    }

    void UGWC::SetHStringAlignment(UStringAlignment Value)
    {
        GCHandle Handle = GCHandle::FromIntPtr(IntPtr(GWCAdress));
        GWCpp::GWC^ T = safe_cast<GWCpp::GWC^>(Handle.Target);
        T->HStringAlignment = (MStringAlignment)Value;
    }

    void UGWC::DefaultHStringAlignment()
    {
        GCHandle Handle = GCHandle::FromIntPtr(IntPtr(GWCAdress));
        GWCpp::GWC^ T = safe_cast<GWCpp::GWC^>(Handle.Target);
        T->DefaultHStringAlignment();
    }



    UStringAlignment UGWC::GetVStringAlignment()
    {
        GCHandle Handle = GCHandle::FromIntPtr(IntPtr(GWCAdress));
        GWCpp::GWC^ T = safe_cast<GWCpp::GWC^>(Handle.Target);
        return (UStringAlignment)T->VStringAlignment;
    }

    void UGWC::SetVStringAlignment(UStringAlignment Value)
    {
        GCHandle Handle = GCHandle::FromIntPtr(IntPtr(GWCAdress));
        GWCpp::GWC^ T = safe_cast<GWCpp::GWC^>(Handle.Target);
        T->VStringAlignment = (MStringAlignment)Value;
    }

    void UGWC::DefaultVStringAlignment()
    {
        GCHandle Handle = GCHandle::FromIntPtr(IntPtr(GWCAdress));
        GWCpp::GWC^ T = safe_cast<GWCpp::GWC^>(Handle.Target);
        T->DefaultVStringAlignment();
    }



    string UGWC::GetFontName()
    {
        GCHandle Handle = GCHandle::FromIntPtr(IntPtr(GWCAdress));
        GWCpp::GWC^ T = safe_cast<GWCpp::GWC^>(Handle.Target);
        return MStringToUString(T->FontName);
    }

    void UGWC::SetFontName(string Value)
    {
        GCHandle Handle = GCHandle::FromIntPtr(IntPtr(GWCAdress));
        GWCpp::GWC^ T = safe_cast<GWCpp::GWC^>(Handle.Target);
        T->FontName = UStringToMString(Value);
    }

    void UGWC::DefaultFontName()
    {
        GCHandle Handle = GCHandle::FromIntPtr(IntPtr(GWCAdress));
        GWCpp::GWC^ T = safe_cast<GWCpp::GWC^>(Handle.Target);
        T->DefaultFontName();
    }



    float UGWC::GetFontSize()
    {
        GCHandle Handle = GCHandle::FromIntPtr(IntPtr(GWCAdress));
        GWCpp::GWC^ T = safe_cast<GWCpp::GWC^>(Handle.Target);
        return T->FontSize;
    }

    void UGWC::SetFontSize(float Value)
    {
        GCHandle Handle = GCHandle::FromIntPtr(IntPtr(GWCAdress));
        GWCpp::GWC^ T = safe_cast<GWCpp::GWC^>(Handle.Target);
        T->FontSize = Value;
    }
    
    void UGWC::DefaultFontSize()
    {
        GCHandle Handle = GCHandle::FromIntPtr(IntPtr(GWCAdress));
        GWCpp::GWC^ T = safe_cast<GWCpp::GWC^>(Handle.Target);
        T->DefaultFontSize();
    }

    #pragma endregion

}
