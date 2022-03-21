/*
    GWC++ (Graphic Window for Console Application)

    - Questo progetto è sotto lincenza MIT (https://mit-license.org)
    - Questo progetto è disponibile su GitHub (https://github.com/reallukee/GWCpp)
    - Maggiori informazioni sono diponibili nel file README.md

    ATUORE:			Realluke
    DESCRIZIONE:	Classe gestita UGWC
    DATA:			20/03/22
*/


#include "pch.h"
#include "ugwc++.h"
#include "gwc++.h"
#include <msclr\marshal_cppstd.h>


#pragma managed


namespace GWCpp
{

    /*
        Costruttori e distruttori.
    */

    // Costruttori.
    UGWC::UGWC()
    {
        GWCpp::GWC^ T = gcnew GWCpp::GWC(850, 505, "GWC++ Window", 50, 50);
        UGWCAdress = GCHandle::ToIntPtr(GCHandle::Alloc(T)).ToPointer();
    }

    UGWC::UGWC(int Width, int Height)
    {
        GWCpp::GWC^ T = gcnew GWCpp::GWC(Width, Height, "GWC++ Window", 50, 50);
        UGWCAdress = GCHandle::ToIntPtr(GCHandle::Alloc(T)).ToPointer();
    }

    UGWC::UGWC(int Width, int Height, std::string Title)
    {
        GWCpp::GWC^ T = gcnew GWCpp::GWC(Width, Height, gcnew String(Title.c_str()), 50, 50);
        UGWCAdress = GCHandle::ToIntPtr(GCHandle::Alloc(T)).ToPointer();
    }

    UGWC::UGWC(int Width, int Height, std::string Title, int X, int Y)
    {
        GWCpp::GWC^ T = gcnew GWCpp::GWC(Width, Height, gcnew String(Title.c_str()), X, Y);
        UGWCAdress = GCHandle::ToIntPtr(GCHandle::Alloc(T)).ToPointer();
    }

    // Distruttore.
    UGWC::~UGWC()
    {
        GCHandle Handle = GCHandle::FromIntPtr(IntPtr(UGWCAdress));
        Handle.Free();
    }



    /*
        Metodi di conversione.
    */

    // UString To MString.
    String^ UStringToMString(std::string Str)
    {
        String^ Context = gcnew String(Str.c_str());
        return Context;
    }

    // MString To UString.
    std::string MStringToUString(String^ Str)
    {
        msclr::interop::marshal_context Context;
        return Context.marshal_as<std::string>(Str);
    }

    // UGPoint To MGPoint.
    MGPoint UGPointToMGPoint(UGPoint Value)
    {
        return MGPoint(Value.X, Value.Y);
    }

    // MGPoint To UGPoint.
    UGPoint MGPointToUGPoint(MGPoint Value)
    {
        return UGPoint{ Value.X, Value.Y };
    }

    // UGColor To MGColor.
    MGColor UGColorToMGColor(UGColor Value)
    {
        return MGColor(Value.R, Value.G, Value.B);
    }

    // MGColor To UGColor.
    UGColor MGColorToUGColor(MGColor Value)
    {
        return UGColor{ Value.R, Value.G, Value.B };
    }

    // UGSize To MGSize.
    MGSize UGSizeToMGSize(UGSize Value)
    {
        return MGSize(Value.Width, Value.Height);
    }

    // MGSize To UGSize.
    UGSize MGSizeToUGSize(MGSize Value)
    {
        return UGSize{ Value.Width, Value.Height };
    }



    /*
        Interazioni.
    */

    // Input Box.
    void UGWC::InputBox(std::string Prompt, std::string Title, std::string DefaultResponse, int X, int Y)
    {
        GCHandle Handle = GCHandle::FromIntPtr(IntPtr(UGWCAdress));
        GWCpp::GWC^ T = safe_cast<GWCpp::GWC^>(Handle.Target);
        T->InputBox(UStringToMString(Prompt), UStringToMString(Title), UStringToMString(DefaultResponse), X, Y);
    }

    // Message Box.
    UGOutputBoxResult UGWC::OutputBox(std::string Prompt, UGOutputBoxStyle Style, std::string Title)
    {
        GCHandle Handle = GCHandle::FromIntPtr(IntPtr(UGWCAdress));
        GWCpp::GWC^ T = safe_cast<GWCpp::GWC^>(Handle.Target);
        return (UGOutputBoxResult)T->OutputBox(UStringToMString(Prompt), (MGOutputBoxStyle)Style, UStringToMString(Title));
    }



    /*
        Metodi finestra.
    */

    // Start Window.
    bool UGWC::StartWindow()
    {
        GCHandle Handle = GCHandle::FromIntPtr(IntPtr(UGWCAdress));
        GWCpp::GWC^ T = safe_cast<GWCpp::GWC^>(Handle.Target);
        return T->StartWindow();
    }

    // Close Window.
    bool UGWC::CloseWindow()
    {
        GCHandle Handle = GCHandle::FromIntPtr(IntPtr(UGWCAdress));
        GWCpp::GWC^ T = safe_cast<GWCpp::GWC^>(Handle.Target);
        return T->CloseWindow();
    }

    // Suspend Window.
    bool UGWC::SuspendWindow()
    {
        GCHandle Handle = GCHandle::FromIntPtr(IntPtr(UGWCAdress));
        GWCpp::GWC^ T = safe_cast<GWCpp::GWC^>(Handle.Target);
        return T->SuspendWindow();
    }

    // Resume Window.
    bool UGWC::ResumeWindow()
    {
        GCHandle Handle = GCHandle::FromIntPtr(IntPtr(UGWCAdress));
        GWCpp::GWC^ T = safe_cast<GWCpp::GWC^>(Handle.Target);
        return T->ResumeWindow();
    }

    // Pause Window.
    bool UGWC::PauseWindow(int Time)
    {
        GCHandle Handle = GCHandle::FromIntPtr(IntPtr(UGWCAdress));
        GWCpp::GWC^ T = safe_cast<GWCpp::GWC^>(Handle.Target);
        return T->PauseWindow(Time);
    }

    // Show Window.
    bool UGWC::ShowWindow()
    {
        GCHandle Handle = GCHandle::FromIntPtr(IntPtr(UGWCAdress));
        GWCpp::GWC^ T = safe_cast<GWCpp::GWC^>(Handle.Target);
        return T->ShowWindow();
    }

    // Hide Window.
    bool UGWC::HideWindow()
    {
        GCHandle Handle = GCHandle::FromIntPtr(IntPtr(UGWCAdress));
        GWCpp::GWC^ T = safe_cast<GWCpp::GWC^>(Handle.Target);
        return T->HideWindow();
    }

    // Get Window Max X.
    int UGWC::GetWindowMaxX()
    {
        GCHandle Handle = GCHandle::FromIntPtr(IntPtr(UGWCAdress));
        GWCpp::GWC^ T = safe_cast<GWCpp::GWC^>(Handle.Target);
        return T->GetWindowMaxX();
    }

    // Get Window Real Max X.
    int UGWC::GetWindowRealMaxX()
    {
        GCHandle Handle = GCHandle::FromIntPtr(IntPtr(UGWCAdress));
        GWCpp::GWC^ T = safe_cast<GWCpp::GWC^>(Handle.Target);
        return T->GetWindowRealMaxX();
    }

    // Get Window Max Y.
    int UGWC::GetWindowMaxY()
    {
        GCHandle Handle = GCHandle::FromIntPtr(IntPtr(UGWCAdress));
        GWCpp::GWC^ T = safe_cast<GWCpp::GWC^>(Handle.Target);
        return T->GetWindowMaxY();
    }

    // Get Window Real Max Y.
    int UGWC::GetWindowRealMaxY()
    {
        GCHandle Handle = GCHandle::FromIntPtr(IntPtr(UGWCAdress));
        GWCpp::GWC^ T = safe_cast<GWCpp::GWC^>(Handle.Target);
        return T->GetWindowRealMaxY();
    }

    // Get Screen Max X.
    int UGWC::GetScreenMaxX()
    {
        GCHandle Handle = GCHandle::FromIntPtr(IntPtr(UGWCAdress));
        GWCpp::GWC^ T = safe_cast<GWCpp::GWC^>(Handle.Target);
        return T->GetScreenMaxX();
    }

    // Get Screen Real Max X.
    int UGWC::GetScreenRealMaxX()
    {
        GCHandle Handle = GCHandle::FromIntPtr(IntPtr(UGWCAdress));
        GWCpp::GWC^ T = safe_cast<GWCpp::GWC^>(Handle.Target);
        return T->GetScreenRealMaxX();
    }

    // Get Screen Max Y.
    int UGWC::GetScreenMaxY()
    {
        GCHandle Handle = GCHandle::FromIntPtr(IntPtr(UGWCAdress));
        GWCpp::GWC^ T = safe_cast<GWCpp::GWC^>(Handle.Target);
        return T->GetScreenMaxY();
    }

    // Get Screen Real Max Y.
    int UGWC::GetScreenRealMaxY()
    {
        GCHandle Handle = GCHandle::FromIntPtr(IntPtr(UGWCAdress));
        GWCpp::GWC^ T = safe_cast<GWCpp::GWC^>(Handle.Target);
        return T->GetScreenRealMaxY();
    }

    // Create Canvas State.
    bool UGWC::CreateCanvasState(std::string Name)
    {
        GCHandle Handle = GCHandle::FromIntPtr(IntPtr(UGWCAdress));
        GWCpp::GWC^ T = safe_cast<GWCpp::GWC^>(Handle.Target);
        return T->CreateCanvasState(UStringToMString(Name));
    }

    // Delete Canvas State.
    bool UGWC::DeleteCanvasState(std::string Name)
    {
        GCHandle Handle = GCHandle::FromIntPtr(IntPtr(UGWCAdress));
        GWCpp::GWC^ T = safe_cast<GWCpp::GWC^>(Handle.Target);
        return T->DeleteCanvasState(UStringToMString(Name));
    }

    // Save Canvas State.
    bool UGWC::SaveCanvasState(std::string Name)
    {
        GCHandle Handle = GCHandle::FromIntPtr(IntPtr(UGWCAdress));
        GWCpp::GWC^ T = safe_cast<GWCpp::GWC^>(Handle.Target);
        return T->SaveCanvasState(UStringToMString(Name));
    }

    // Load Canvas State.
    bool UGWC::LoadCanvasState(std::string Name)
    {
        GCHandle Handle = GCHandle::FromIntPtr(IntPtr(UGWCAdress));
        GWCpp::GWC^ T = safe_cast<GWCpp::GWC^>(Handle.Target);
        return T->LoadCanvasState(UStringToMString(Name));
    }

    // Mouse Down.
    UGPoint UGWC::RequestMouseDown(UGMouseButtons B)
    {
        GCHandle Handle = GCHandle::FromIntPtr(IntPtr(UGWCAdress));
        GWCpp::GWC^ T = safe_cast<GWCpp::GWC^>(Handle.Target);
        return UGPoint{ T->RequestMouseDown((GWCpp::MGMouseButtons)B).X, T->RequestMouseDown((GWCpp::MGMouseButtons)B).Y };
    }

    UGPoint UGWC::RequestMoudeDown()
    {
        GCHandle Handle = GCHandle::FromIntPtr(IntPtr(UGWCAdress));
        GWCpp::GWC^ T = safe_cast<GWCpp::GWC^>(Handle.Target);
        return UGPoint{ T->RequestMouseDown().X, T->RequestMouseDown().Y };
    }

    // Mouse Up.
    UGPoint UGWC::RequestMouseUp(UGMouseButtons B)
    {
        GCHandle Handle = GCHandle::FromIntPtr(IntPtr(UGWCAdress));
        GWCpp::GWC^ T = safe_cast<GWCpp::GWC^>(Handle.Target);
        return UGPoint{ T->RequestMouseUp((GWCpp::MGMouseButtons)B).X, T->RequestMouseUp((GWCpp::MGMouseButtons)B).Y };
    }

    UGPoint UGWC::RequestMouseUp()
    {
        GCHandle Handle = GCHandle::FromIntPtr(IntPtr(UGWCAdress));
        GWCpp::GWC^ T = safe_cast<GWCpp::GWC^>(Handle.Target);
        return UGPoint{ T->RequestMouseUp().X, T->RequestMouseUp().Y };
    }

    // key Down.
    char UGWC::RequestKeyDown(char C)
    {
        GCHandle Handle = GCHandle::FromIntPtr(IntPtr(UGWCAdress));
        GWCpp::GWC^ T = safe_cast<GWCpp::GWC^>(Handle.Target);
        return T->RequestKeyUp(C);
    }

    char UGWC::RequestKeyDown()
    {
        GCHandle Handle = GCHandle::FromIntPtr(IntPtr(UGWCAdress));
        GWCpp::GWC^ T = safe_cast<GWCpp::GWC^>(Handle.Target);
        return T->RequestKeyUp();
    }

    // Key Up.
    char UGWC::RequestKeyUp(char C)
    {
        GCHandle Handle = GCHandle::FromIntPtr(IntPtr(UGWCAdress));
        GWCpp::GWC^ T = safe_cast<GWCpp::GWC^>(Handle.Target);
        return T->RequestKeyUp(C);
    }

    char UGWC::RequestKeyUp()
    {
        GCHandle Handle = GCHandle::FromIntPtr(IntPtr(UGWCAdress));
        GWCpp::GWC^ T = safe_cast<GWCpp::GWC^>(Handle.Target);
        return T->RequestKeyUp();
    }

    

    /*
        Proprietà finestra.
    */

    // Window Started.
    bool UGWC::GetWindowStarted()
    {
        GCHandle Handle = GCHandle::FromIntPtr(IntPtr(UGWCAdress));
        GWCpp::GWC^ T = safe_cast<GWCpp::GWC^>(Handle.Target);
        return T->WindowStarted;
    }

    // Window Closed.
    bool UGWC::GetWindowClosed()
    {
        GCHandle Handle = GCHandle::FromIntPtr(IntPtr(UGWCAdress));
        GWCpp::GWC^ T = safe_cast<GWCpp::GWC^>(Handle.Target);
        return T->WindowClosed;
    }

    // Window Suspended.
    bool UGWC::GetWindowSuspended()
    {
        GCHandle Handle = GCHandle::FromIntPtr(IntPtr(UGWCAdress));
        GWCpp::GWC^ T = safe_cast<GWCpp::GWC^>(Handle.Target);
        return T->WindowSuspended;
    }

    // Mouse Location.
    UGPoint UGWC::GetMouseLocation()
    {
        GCHandle Handle = GCHandle::FromIntPtr(IntPtr(UGWCAdress));
        GWCpp::GWC^ T = safe_cast<GWCpp::GWC^>(Handle.Target);
        return MGPointToUGPoint(T->MouseLocation);
    }

    void UGWC::SetMouseLocation(UGPoint Value)
    {
        GCHandle Handle = GCHandle::FromIntPtr(IntPtr(UGWCAdress));
        GWCpp::GWC^ T = safe_cast<GWCpp::GWC^>(Handle.Target);
        T->MouseLocation = UGPointToMGPoint(Value);
    }

    int UGWC::GetMouseX()
    {
        GCHandle Handle = GCHandle::FromIntPtr(IntPtr(UGWCAdress));
        GWCpp::GWC^ T = safe_cast<GWCpp::GWC^>(Handle.Target);
        return T->MouseX;
    }

    void UGWC::SetMouseX(int Value)
    {
        GCHandle Handle = GCHandle::FromIntPtr(IntPtr(UGWCAdress));
        GWCpp::GWC^ T = safe_cast<GWCpp::GWC^>(Handle.Target);
        T->MouseX = Value;
    }

    int UGWC::GetMouseY()
    {
        GCHandle Handle = GCHandle::FromIntPtr(IntPtr(UGWCAdress));
        GWCpp::GWC^ T = safe_cast<GWCpp::GWC^>(Handle.Target);
        return T->MouseY;
    }

    void UGWC::SetMouseY(int Value) 
    {
        GCHandle Handle = GCHandle::FromIntPtr(IntPtr(UGWCAdress));
        GWCpp::GWC^ T = safe_cast<GWCpp::GWC^>(Handle.Target);
        T->MouseY = Value;
    }

    // Window Title.
    std::string UGWC::GetWindowTitle()
    {
        GCHandle Handle = GCHandle::FromIntPtr(IntPtr(UGWCAdress));
        GWCpp::GWC^ T = safe_cast<GWCpp::GWC^>(Handle.Target);
        return MStringToUString(T->WindowTitle);
    }

    void UGWC::SetWindowTitle(std::string Value)
    {
        GCHandle Handle = GCHandle::FromIntPtr(IntPtr(UGWCAdress));
        GWCpp::GWC^ T = safe_cast<GWCpp::GWC^>(Handle.Target);
        T->WindowTitle = UStringToMString(Value);
    }

    void UGWC::DefaultWindowTitle()
    {
        GCHandle Handle = GCHandle::FromIntPtr(IntPtr(UGWCAdress));
        GWCpp::GWC^ T = safe_cast<GWCpp::GWC^>(Handle.Target);
        T->DefaultWindowTitle();
    }

    // Window Icon Visible.
    bool UGWC::GetWindowIconVisible()
    {
        GCHandle Handle = GCHandle::FromIntPtr(IntPtr(UGWCAdress));
        GWCpp::GWC^ T = safe_cast<GWCpp::GWC^>(Handle.Target);
        return T->WindowIconVisible;
    }

    void UGWC::SetWindowIconVisible(bool Value)
    {
        GCHandle Handle = GCHandle::FromIntPtr(IntPtr(UGWCAdress));
        GWCpp::GWC^ T = safe_cast<GWCpp::GWC^>(Handle.Target);
        T->WindowIconVisible = Value;
    }

    void UGWC::DefaultWindowIconVisible()
    {
        GCHandle Handle = GCHandle::FromIntPtr(IntPtr(UGWCAdress));
        GWCpp::GWC^ T = safe_cast<GWCpp::GWC^>(Handle.Target);
        T->DefaultWindowIconVisible();
    }

    // Window Location.
    UGPoint UGWC::GetWindowLocation()
    {
        GCHandle Handle = GCHandle::FromIntPtr(IntPtr(UGWCAdress));
        GWCpp::GWC^ T = safe_cast<GWCpp::GWC^>(Handle.Target);
        return UGPoint{ T->WindowLocation.X, T->WindowLocation.Y };
    }

    void UGWC::SetWindowLocation(UGPoint Value)
    {
        GCHandle Handle = GCHandle::FromIntPtr(IntPtr(UGWCAdress));
        GWCpp::GWC^ T = safe_cast<GWCpp::GWC^>(Handle.Target);
        T->WindowLocation = GWCpp::MGPoint(Value.X, Value.Y);
    }

    int UGWC::GetWindowX()
    {
        GCHandle Handle = GCHandle::FromIntPtr(IntPtr(UGWCAdress));
        GWCpp::GWC^ T = safe_cast<GWCpp::GWC^>(Handle.Target);
        return T->WindowX;
    }

    void UGWC::SetWindowX(int Value)
    {
        GCHandle Handle = GCHandle::FromIntPtr(IntPtr(UGWCAdress));
        GWCpp::GWC^ T = safe_cast<GWCpp::GWC^>(Handle.Target);
        T->WindowX = Value;
    }

    int UGWC::GetWindowY()
    {
        GCHandle Handle = GCHandle::FromIntPtr(IntPtr(UGWCAdress));
        GWCpp::GWC^ T = safe_cast<GWCpp::GWC^>(Handle.Target);
        return T->WindowY;
    }

    void UGWC::SetWindowY(int Value)
    {
        GCHandle Handle = GCHandle::FromIntPtr(IntPtr(UGWCAdress));
        GWCpp::GWC^ T = safe_cast<GWCpp::GWC^>(Handle.Target);
        T->WindowY = Value;
    }

    void UGWC::DefaultWindowLocation()
    {
        GCHandle Handle = GCHandle::FromIntPtr(IntPtr(UGWCAdress));
        GWCpp::GWC^ T = safe_cast<GWCpp::GWC^>(Handle.Target);
        T->DefaultWindowLocation();
    }

    void UGWC::DefaultWindowX()
    {
        GCHandle Handle = GCHandle::FromIntPtr(IntPtr(UGWCAdress));
        GWCpp::GWC^ T = safe_cast<GWCpp::GWC^>(Handle.Target);
        T->DefaultWindowX();
    }

    void UGWC::DefaultWindowY()
    {
        GCHandle Handle = GCHandle::FromIntPtr(IntPtr(UGWCAdress));
        GWCpp::GWC^ T = safe_cast<GWCpp::GWC^>(Handle.Target);
        T->DefaultWindowY();
    }

    // Window Color.
    UGColor UGWC::GetWindowColor()
    {
        GCHandle Handle = GCHandle::FromIntPtr(IntPtr(UGWCAdress));
        GWCpp::GWC^ T = safe_cast<GWCpp::GWC^>(Handle.Target);
        return UGColor{ T->WindowColor.R, T->WindowColor.G, T->WindowColor.B };
    }

    void UGWC::SetWindowColor(UGColor Value)
    {
        GCHandle Handle = GCHandle::FromIntPtr(IntPtr(UGWCAdress));
        GWCpp::GWC^ T = safe_cast<GWCpp::GWC^>(Handle.Target);
        T->WindowColor = GWCpp::MGColor(Value.R, Value.G, Value.B);
    }

    void UGWC::DefaultWindowColor()
    {
        GCHandle Handle = GCHandle::FromIntPtr(IntPtr(UGWCAdress));
        GWCpp::GWC^ T = safe_cast<GWCpp::GWC^>(Handle.Target);
        T->DefaultWindowColor();
    }

    // Window Size.
    UGSize UGWC::GetWindowSize()
    {
        GCHandle Handle = GCHandle::FromIntPtr(IntPtr(UGWCAdress));
        GWCpp::GWC^ T = safe_cast<GWCpp::GWC^>(Handle.Target);
        return UGSize{ T->WindowSize.Width, T->WindowSize.Height };
    }

    void UGWC::SetWindowSize(UGSize Value)
    {
        GCHandle Handle = GCHandle::FromIntPtr(IntPtr(UGWCAdress));
        GWCpp::GWC^ T = safe_cast<GWCpp::GWC^>(Handle.Target);
        T->WindowSize = GWCpp::MGSize(Value.Width, Value.Height);
    }

    int UGWC::GetWindowWidth()
    {
        GCHandle Handle = GCHandle::FromIntPtr(IntPtr(UGWCAdress));
        GWCpp::GWC^ T = safe_cast<GWCpp::GWC^>(Handle.Target);
        return T->WindowWidth;
    }

    void UGWC::SetWindowWidth(int Value)
    {
        GCHandle Handle = GCHandle::FromIntPtr(IntPtr(UGWCAdress));
        GWCpp::GWC^ T = safe_cast<GWCpp::GWC^>(Handle.Target);
        T->WindowWidth = Value;
    }

    int UGWC::GetWindowHeight()
    {
        GCHandle Handle = GCHandle::FromIntPtr(IntPtr(UGWCAdress));
        GWCpp::GWC^ T = safe_cast<GWCpp::GWC^>(Handle.Target);
        return T->WindowHeight;
    }

    void UGWC::SetWindowHeight(int Value)
    {
        GCHandle Handle = GCHandle::FromIntPtr(IntPtr(UGWCAdress));
        GWCpp::GWC^ T = safe_cast<GWCpp::GWC^>(Handle.Target);
        T->WindowHeight = Value;
    }

    void UGWC::DefaultWindowSize()
    {
        GCHandle Handle = GCHandle::FromIntPtr(IntPtr(UGWCAdress));
        GWCpp::GWC^ T = safe_cast<GWCpp::GWC^>(Handle.Target);
        T->DefaultWindowSize();
    }

    void UGWC::DefaultWindowWidth()
    {
        GCHandle Handle = GCHandle::FromIntPtr(IntPtr(UGWCAdress));
        GWCpp::GWC^ T = safe_cast<GWCpp::GWC^>(Handle.Target);
        T->DefaultWindowWidth();
    }

    void UGWC::DefaultWindowHeight()
    {
        GCHandle Handle = GCHandle::FromIntPtr(IntPtr(UGWCAdress));
        GWCpp::GWC^ T = safe_cast<GWCpp::GWC^>(Handle.Target);
        T->DefaultWindowHeight();
    }

    // Window Real Size.
    UGSize UGWC::GetWindowRealSize()
    {
        GCHandle Handle = GCHandle::FromIntPtr(IntPtr(UGWCAdress));
        GWCpp::GWC^ T = safe_cast<GWCpp::GWC^>(Handle.Target);
        return UGSize{ T->WindowRealSize.Width, T->WindowRealSize.Height };
    }

    void UGWC::SetWindowRealSize(UGSize Value)
    {
        GCHandle Handle = GCHandle::FromIntPtr(IntPtr(UGWCAdress));
        GWCpp::GWC^ T = safe_cast<GWCpp::GWC^>(Handle.Target);
        T->WindowRealSize = GWCpp::MGSize(Value.Width, Value.Height);
    }

    int UGWC::GetWindowRealWidth()
    {
        GCHandle Handle = GCHandle::FromIntPtr(IntPtr(UGWCAdress));
        GWCpp::GWC^ T = safe_cast<GWCpp::GWC^>(Handle.Target);
        return T->WindowRealWidth;
    }

    void UGWC::SetWindowRealWidth(int Value)
    {
        GCHandle Handle = GCHandle::FromIntPtr(IntPtr(UGWCAdress));
        GWCpp::GWC^ T = safe_cast<GWCpp::GWC^>(Handle.Target);
        T->WindowRealWidth = Value;
    }

    int UGWC::GetWindowRealHeight()
    {
        GCHandle Handle = GCHandle::FromIntPtr(IntPtr(UGWCAdress));
        GWCpp::GWC^ T = safe_cast<GWCpp::GWC^>(Handle.Target);
        return T->WindowRealHeight;
    }

    void UGWC::SetWindowRealHeight(int Value)
    {
        GCHandle Handle = GCHandle::FromIntPtr(IntPtr(UGWCAdress));
        GWCpp::GWC^ T = safe_cast<GWCpp::GWC^>(Handle.Target);
        T->WindowRealHeight = Value;
    }

    void UGWC::DefaultWindowRealSize()
    {
        GCHandle Handle = GCHandle::FromIntPtr(IntPtr(UGWCAdress));
        GWCpp::GWC^ T = safe_cast<GWCpp::GWC^>(Handle.Target);
        T->DefaultWindowRealSize();
    }

    void UGWC::DefaultWindowRealWidth()
    {
        GCHandle Handle = GCHandle::FromIntPtr(IntPtr(UGWCAdress));
        GWCpp::GWC^ T = safe_cast<GWCpp::GWC^>(Handle.Target);
        T->DefaultWindowRealWidth();
    }

    void UGWC::DefaultWindowRealHeight()
    {
        GCHandle Handle = GCHandle::FromIntPtr(IntPtr(UGWCAdress));
        GWCpp::GWC^ T = safe_cast<GWCpp::GWC^>(Handle.Target);
        T->DefaultWindowRealHeight();
    }

    // Window Size State.
    UGWindowState UGWC::GetWindowSizeState()
    {
        GCHandle Handle = GCHandle::FromIntPtr(IntPtr(UGWCAdress));
        GWCpp::GWC^ T = safe_cast<GWCpp::GWC^>(Handle.Target);
        return (UGWindowState)T->WindowSizeState;
    }

    void UGWC::SetWindowSizeState(UGWindowState Value)
    {
        GCHandle Handle = GCHandle::FromIntPtr(IntPtr(UGWCAdress));
        GWCpp::GWC^ T = safe_cast<GWCpp::GWC^>(Handle.Target);
        T->WindowSizeState = (GWCpp::MGWindowState)Value;
    }

    void UGWC::DefaultWindowSizeState()
    {
        GCHandle Handle = GCHandle::FromIntPtr(IntPtr(UGWCAdress));
        GWCpp::GWC^ T = safe_cast<GWCpp::GWC^>(Handle.Target);
        T->DefaultWindowSizeState();
    }

    // Window Minimum Size.
    UGSize UGWC::GetWindowMinimumSize()
    {
        GCHandle Handle = GCHandle::FromIntPtr(IntPtr(UGWCAdress));
        GWCpp::GWC^ T = safe_cast<GWCpp::GWC^>(Handle.Target);
        return UGSize{ T->WindowMinimumSize.Width, T->WindowMinimumSize.Height };
    }

    void UGWC::SetWindowMinimumSize(UGSize Value)
    {
        GCHandle Handle = GCHandle::FromIntPtr(IntPtr(UGWCAdress));
        GWCpp::GWC^ T = safe_cast<GWCpp::GWC^>(Handle.Target);
        T->WindowMinimumSize = GWCpp::MGSize(Value.Width, Value.Height);
    }

    void UGWC::DefaultWindowMinimumSize()
    {
        GCHandle Handle = GCHandle::FromIntPtr(IntPtr(UGWCAdress));
        GWCpp::GWC^ T = safe_cast<GWCpp::GWC^>(Handle.Target);
        T->DefaultWindowMinimumSize();
    }

    // Window Maximum Size.
    UGSize UGWC::GetWindowMaximumSize()
    {
        GCHandle Handle = GCHandle::FromIntPtr(IntPtr(UGWCAdress));
        GWCpp::GWC^ T = safe_cast<GWCpp::GWC^>(Handle.Target);
        return UGSize{ T->WindowMaximumSize.Width, T->WindowMaximumSize.Height };
    }

    void UGWC::SetWindowMaximumSize(UGSize Value)
    {
        GCHandle Handle = GCHandle::FromIntPtr(IntPtr(UGWCAdress));
        GWCpp::GWC^ T = safe_cast<GWCpp::GWC^>(Handle.Target);
        T->WindowMaximumSize = GWCpp::MGSize(Value.Width, Value.Height);
    }

    void UGWC::DefaultWindowMaximumSize()
    {
        GCHandle Handle = GCHandle::FromIntPtr(IntPtr(UGWCAdress));
        GWCpp::GWC^ T = safe_cast<GWCpp::GWC^>(Handle.Target);
        T->DefaultWindowMaximumSize();
    }

    // Window Opacity.
    double UGWC::GetWindowOpacity()
    {
        GCHandle Handle = GCHandle::FromIntPtr(IntPtr(UGWCAdress));
        GWCpp::GWC^ T = safe_cast<GWCpp::GWC^>(Handle.Target);
        return T->WindowOpacity;
    }

    void UGWC::SetWindowOpacity(double Value)
    {
        GCHandle Handle = GCHandle::FromIntPtr(IntPtr(UGWCAdress));
        GWCpp::GWC^ T = safe_cast<GWCpp::GWC^>(Handle.Target);
        T->WindowOpacity = Value;
    }

    void UGWC::DefaultWindowOpacity()
    {
        GCHandle Handle = GCHandle::FromIntPtr(IntPtr(UGWCAdress));
        GWCpp::GWC^ T = safe_cast<GWCpp::GWC^>(Handle.Target);
        T->DefaultWindowOpacity();
    }

    // Window Always On Top.
    bool UGWC::GetWindowAlwaysOnTop()
    {
        GCHandle Handle = GCHandle::FromIntPtr(IntPtr(UGWCAdress));
        GWCpp::GWC^ T = safe_cast<GWCpp::GWC^>(Handle.Target);
        return T->WindowAlwaysOnTop;
    }

    void UGWC::SetWindowAlwaysOnTop(bool Value)
    {
        GCHandle Handle = GCHandle::FromIntPtr(IntPtr(UGWCAdress));
        GWCpp::GWC^ T = safe_cast<GWCpp::GWC^>(Handle.Target);
        T->WindowAlwaysOnTop = Value;
    }

    void UGWC::DefaultWindowAlwaysOnTop()
    {
        GCHandle Handle = GCHandle::FromIntPtr(IntPtr(UGWCAdress));
        GWCpp::GWC^ T = safe_cast<GWCpp::GWC^>(Handle.Target);
        T->DefaultWindowAlwaysOnTop();
    }

    // Window In Taskbar.
    bool UGWC::GetWindowInTaskbar()
    {
        GCHandle Handle = GCHandle::FromIntPtr(IntPtr(UGWCAdress));
        GWCpp::GWC^ T = safe_cast<GWCpp::GWC^>(Handle.Target);
        return T->WindowInTaskbar;
    }

    void UGWC::SetWindowInTaskbar(bool Value)
    {
        GCHandle Handle = GCHandle::FromIntPtr(IntPtr(UGWCAdress));
        GWCpp::GWC^ T = safe_cast<GWCpp::GWC^>(Handle.Target);
        T->WindowInTaskbar = Value;
    }

    void UGWC::DefaultWindowInTaskBar()
    {
        GCHandle Handle = GCHandle::FromIntPtr(IntPtr(UGWCAdress));
        GWCpp::GWC^ T = safe_cast<GWCpp::GWC^>(Handle.Target);
        T->DefaultWindowInTaskbar();
    }

    // Window Buttons.
    bool UGWC::GetWindowButtons()
    {
        GCHandle Handle = GCHandle::FromIntPtr(IntPtr(UGWCAdress));
        GWCpp::GWC^ T = safe_cast<GWCpp::GWC^>(Handle.Target);
        return T->WindowButtons;
    }

    void UGWC::SetWindowButtons(bool Value)
    {
        GCHandle Handle = GCHandle::FromIntPtr(IntPtr(UGWCAdress));
        GWCpp::GWC^ T = safe_cast<GWCpp::GWC^>(Handle.Target);
        T->WindowButtons = Value;
    }

    void UGWC::DefaultWindowButtons()
    {
        GCHandle Handle = GCHandle::FromIntPtr(IntPtr(UGWCAdress));
        GWCpp::GWC^ T = safe_cast<GWCpp::GWC^>(Handle.Target);
        T->DefaultWindowButtons();
    }

    // Window Minimize Button.
    bool UGWC::GetWindowMinimizeButton()
    {
        GCHandle Handle = GCHandle::FromIntPtr(IntPtr(UGWCAdress));
        GWCpp::GWC^ T = safe_cast<GWCpp::GWC^>(Handle.Target);
        return T->WindowMinimizeButton;
    }

    void UGWC::SetWindowMinimizeButton(bool Value)
    {
        GCHandle Handle = GCHandle::FromIntPtr(IntPtr(UGWCAdress));
        GWCpp::GWC^ T = safe_cast<GWCpp::GWC^>(Handle.Target);
        T->WindowMinimizeButton = Value;
    }

    void UGWC::DefaultWindowMinimizeButton()
    {
        GCHandle Handle = GCHandle::FromIntPtr(IntPtr(UGWCAdress));
        GWCpp::GWC^ T = safe_cast<GWCpp::GWC^>(Handle.Target);
        T->DefaultWindowMinimizeButton();
    }

    // Window Maximize Button.
    bool UGWC::GetWindowMaximizeButton()
    {
        GCHandle Handle = GCHandle::FromIntPtr(IntPtr(UGWCAdress));
        GWCpp::GWC^ T = safe_cast<GWCpp::GWC^>(Handle.Target);
        return T->WindowMaximizeButton;
    }

    void UGWC::SetWindowMaximizeButton(bool Value)
    {
        GCHandle Handle = GCHandle::FromIntPtr(IntPtr(UGWCAdress));
        GWCpp::GWC^ T = safe_cast<GWCpp::GWC^>(Handle.Target);
        T->WindowMaximizeButton = Value;
    }

    void UGWC::DefaultWindowMaximizeButton()
    {
        GCHandle Handle = GCHandle::FromIntPtr(IntPtr(UGWCAdress));
        GWCpp::GWC^ T = safe_cast<GWCpp::GWC^>(Handle.Target);
        T->DefaultWindowMaximizeButton();
    }
    


    /*
        Metodo disegno.
    */

    // Clear Window.
    void UGWC::ClearWindow(UGColor Color)
    {
        GCHandle Handle = GCHandle::FromIntPtr(IntPtr(UGWCAdress));
        GWCpp::GWC^ T = safe_cast<GWCpp::GWC^>(Handle.Target);
        T->ClearWindow(UGColorToMGColor(Color));
    }

    // Save Canvas.
    void UGWC::SaveCanvas()
    {
        GCHandle Handle = GCHandle::FromIntPtr(IntPtr(UGWCAdress));
        GWCpp::GWC^ T = safe_cast<GWCpp::GWC^>(Handle.Target);
        T->SaveCanvas();
    }

    // Restore Canvas.
    void UGWC::RestoreCanvas()
    {
        GCHandle Handle = GCHandle::FromIntPtr(IntPtr(UGWCAdress));
        GWCpp::GWC^ T = safe_cast<GWCpp::GWC^>(Handle.Target);
        T->RestoreCanvas();
    }

    // Draw Pixel.
    void UGWC::DrawPixel(int X, int Y)
    {
        GCHandle Handle = GCHandle::FromIntPtr(IntPtr(UGWCAdress));
        GWCpp::GWC^ T = safe_cast<GWCpp::GWC^>(Handle.Target);
        T->DrawPixel(X, Y);
    }

    // Draw Line.
    void UGWC::DrawLine(int X1, int Y1, int X2, int Y2)
    {
        GCHandle Handle = GCHandle::FromIntPtr(IntPtr(UGWCAdress));
        GWCpp::GWC^ T = safe_cast<GWCpp::GWC^>(Handle.Target);
        T->DrawLine(X1, Y1, X2, Y2);
    }

    // Draw Arc.
    void UGWC::DrawArc(int X, int Y, int Width, int Height, int A, int B)
    {
        GCHandle Handle = GCHandle::FromIntPtr(IntPtr(UGWCAdress));
        GWCpp::GWC^ T = safe_cast<GWCpp::GWC^>(Handle.Target);
        T->DrawArc(X, Y, Width, Height, A, B);
    }

    // Draw Bezier.
    void UGWC::DrawBezier(float X1, float Y1, float X2, float Y2, float X3, float Y3, float X4, float Y4)
    {
        GCHandle Handle = GCHandle::FromIntPtr(IntPtr(UGWCAdress));
        GWCpp::GWC^ T = safe_cast<GWCpp::GWC^>(Handle.Target);
        T->DrawBezier(X1, Y1, X2, Y2, X3, Y3, X4, Y4);
    }

    // Draw String.
    void UGWC::DrawString(std::string S, int X, int Y)
    {
        GCHandle Handle = GCHandle::FromIntPtr(IntPtr(UGWCAdress));
        GWCpp::GWC^ T = safe_cast<GWCpp::GWC^>(Handle.Target);
        T->DrawString(gcnew String(S.c_str()), X, Y);
    }

    // Draw Image From File.
    void UGWC::DrawImageFromFile(std::string FileName, int X, int Y)
    {
        GCHandle Handle = GCHandle::FromIntPtr(IntPtr(UGWCAdress));
        GWCpp::GWC^ T = safe_cast<GWCpp::GWC^>(Handle.Target);
        T->DrawImageFromFile(gcnew String(FileName.c_str()), X, Y);
    }

    // Draw Icon From File.
    void UGWC::DrawIconFromFile(std::string FileName, int X, int Y)
    {
        GCHandle Handle = GCHandle::FromIntPtr(IntPtr(UGWCAdress));
        GWCpp::GWC^ T = safe_cast<GWCpp::GWC^>(Handle.Target);
        T->DrawIconFromFile(gcnew String(FileName.c_str()), X, Y);
    }

    // Draw Square.
    void UGWC::DrawSquare(int X, int Y, int L)
    {
        GCHandle Handle = GCHandle::FromIntPtr(IntPtr(UGWCAdress));
        GWCpp::GWC^ T = safe_cast<GWCpp::GWC^>(Handle.Target);
        T->DrawSquare(X, Y, L);
    }

    // Draw Fill Square.
    void UGWC::DrawFullSquare(int X, int Y, int L)
    {
        GCHandle Handle = GCHandle::FromIntPtr(IntPtr(UGWCAdress));
        GWCpp::GWC^ T = safe_cast<GWCpp::GWC^>(Handle.Target);
        T->DrawFullSquare(X, Y, L);
    }

    // Draw Rectangle.
    void UGWC::DrawRectangle(int X, int Y, int Width, int Height)
    {
        GCHandle Handle = GCHandle::FromIntPtr(IntPtr(UGWCAdress));
        GWCpp::GWC^ T = safe_cast<GWCpp::GWC^>(Handle.Target);
        T->DrawRectangle(X, Y, Width, Height);
    }

    // Draw Fill Rectangle.
    void UGWC::DrawFullRectangle(int X, int Y, int Width, int Height)
    {
        GCHandle Handle = GCHandle::FromIntPtr(IntPtr(UGWCAdress));
        GWCpp::GWC^ T = safe_cast<GWCpp::GWC^>(Handle.Target);
        T->DrawFullRectangle(X, Y, Width, Height);
    }

    // Draw Ellipse.
    void UGWC::DrawEllipse(int X, int Y, int Width, int Height)
    {
        GCHandle Handle = GCHandle::FromIntPtr(IntPtr(UGWCAdress));
        GWCpp::GWC^ T = safe_cast<GWCpp::GWC^>(Handle.Target);
        T->DrawEllipse(X, Y, Width, Height);
    }

    // Draw Fill Ellipse.
    void UGWC::DrawFullEllipse(int X, int Y, int Width, int Height)
    {
        GCHandle Handle = GCHandle::FromIntPtr(IntPtr(UGWCAdress));
        GWCpp::GWC^ T = safe_cast<GWCpp::GWC^>(Handle.Target);
        T->DrawFullEllipse(X, Y, Width, Height);
    }

    // Draw Circle.
    void UGWC::DrawCircle(int X, int Y, int R)
    {
        GCHandle Handle = GCHandle::FromIntPtr(IntPtr(UGWCAdress));
        GWCpp::GWC^ T = safe_cast<GWCpp::GWC^>(Handle.Target);
        T->DrawCircle(X, Y, R);
    }

    // Draw Fill Circle.
    void UGWC::DrawFullCircle(int X, int Y, int R)
    {
        GCHandle Handle = GCHandle::FromIntPtr(IntPtr(UGWCAdress));
        GWCpp::GWC^ T = safe_cast<GWCpp::GWC^>(Handle.Target);
        T->DrawFullCircle(X, Y, R);
    }

    // Draw Pie.
    void UGWC::DrawPie(int X, int Y, int Width, int Height, int A, int B)
    {
        GCHandle Handle = GCHandle::FromIntPtr(IntPtr(UGWCAdress));
        GWCpp::GWC^ T = safe_cast<GWCpp::GWC^>(Handle.Target);
        T->DrawPie(X, Y, Width, Height, A, B);
    }

    // Draw Fill Pie.
    void UGWC::DrawFullPie(int X, int Y, int Width, int Height, int A, int B)
    {
        GCHandle Handle = GCHandle::FromIntPtr(IntPtr(UGWCAdress));
        GWCpp::GWC^ T = safe_cast<GWCpp::GWC^>(Handle.Target);
        T->DrawFullPie(X, Y, Width, Height, A, B);
    }

    // Draw From Screen.
    void UGWC::DrawFromScreen(int X1, int Y1, int X2, int Y2, int Width, int Height)
    {
        GCHandle Handle = GCHandle::FromIntPtr(IntPtr(UGWCAdress));
        GWCpp::GWC^ T = safe_cast<GWCpp::GWC^>(Handle.Target);
        T->DrawFromScreen(X1, Y1, X2, Y2, Width, Height);
    }



    /*
        Proprietà disegno.
    */

    // Pen Color.
    UGColor UGWC::GetPenColor()
    {
        GCHandle Handle = GCHandle::FromIntPtr(IntPtr(UGWCAdress));
        GWCpp::GWC^ T = safe_cast<GWCpp::GWC^>(Handle.Target);
        return UGColor{ T->PenColor.R, T->PenColor.G, T->PenColor.B };
    }

    void UGWC::SetPenColor(UGColor Value)
    {
        GCHandle Handle = GCHandle::FromIntPtr(IntPtr(UGWCAdress));
        GWCpp::GWC^ T = safe_cast<GWCpp::GWC^>(Handle.Target);
        T->PenColor = GWCpp::MGColor(Value.R, Value.G, Value.B);
    }

    void UGWC::DefaultPenColor()
    {
        GCHandle Handle = GCHandle::FromIntPtr(IntPtr(UGWCAdress));
        GWCpp::GWC^ T = safe_cast<GWCpp::GWC^>(Handle.Target);
        T->DefaultPenColor();
    }

    // Pen Width.
    float UGWC::GetPenWidth()
    {
        GCHandle Handle = GCHandle::FromIntPtr(IntPtr(UGWCAdress));
        GWCpp::GWC^ T = safe_cast<GWCpp::GWC^>(Handle.Target);
        return T->PenWidth;
    }

    void UGWC::SetPenWidth(float Value)
    {
        GCHandle Handle = GCHandle::FromIntPtr(IntPtr(UGWCAdress));
        GWCpp::GWC^ T = safe_cast<GWCpp::GWC^>(Handle.Target);
        T->PenWidth = Value;
    }

    void UGWC::DefaultPenWidth()
    {
        GCHandle Handle = GCHandle::FromIntPtr(IntPtr(UGWCAdress));
        GWCpp::GWC^ T = safe_cast<GWCpp::GWC^>(Handle.Target);
        T->DefaultPenWidth();
    }

    // Fill Color.
    UGColor UGWC::GetFillColor()
    {
        GCHandle Handle = GCHandle::FromIntPtr(IntPtr(UGWCAdress));
        GWCpp::GWC^ T = safe_cast<GWCpp::GWC^>(Handle.Target);
        return UGColor{ T->FillColor.R, T->FillColor.G, T->FillColor.B };
    }

    void UGWC::SetFillColor(UGColor Value)
    {
        GCHandle Handle = GCHandle::FromIntPtr(IntPtr(UGWCAdress));
        GWCpp::GWC^ T = safe_cast<GWCpp::GWC^>(Handle.Target);
        T->FillColor = GWCpp::MGColor(Value.R, Value.G, Value.B);
    }

    void UGWC::DefaultFillColor()
    {
        GCHandle Handle = GCHandle::FromIntPtr(IntPtr(UGWCAdress));
        GWCpp::GWC^ T = safe_cast<GWCpp::GWC^>(Handle.Target);
        T->DefaultFillColor();
    }

    // Font Name.
    std::string UGWC::GetFontName()
    {
        GCHandle Handle = GCHandle::FromIntPtr(IntPtr(UGWCAdress));
        GWCpp::GWC^ T = safe_cast<GWCpp::GWC^>(Handle.Target);
        return MStringToUString(T->FontName);
    }

    void UGWC::SetFontName(std::string Value)
    {
        GCHandle Handle = GCHandle::FromIntPtr(IntPtr(UGWCAdress));
        GWCpp::GWC^ T = safe_cast<GWCpp::GWC^>(Handle.Target);
        T->FontName = UStringToMString(Value);
    }

    void UGWC::DefaultFontName()
    {
        GCHandle Handle = GCHandle::FromIntPtr(IntPtr(UGWCAdress));
        GWCpp::GWC^ T = safe_cast<GWCpp::GWC^>(Handle.Target);
        T->DefaultFontName();
    }

    // Font Size.
    float UGWC::GetFontSize()
    {
        GCHandle Handle = GCHandle::FromIntPtr(IntPtr(UGWCAdress));
        GWCpp::GWC^ T = safe_cast<GWCpp::GWC^>(Handle.Target);
        return T->FontSize;
    }

    void UGWC::SetFontSize(float Value)
    {
        GCHandle Handle = GCHandle::FromIntPtr(IntPtr(UGWCAdress));
        GWCpp::GWC^ T = safe_cast<GWCpp::GWC^>(Handle.Target);
        T->FontSize = Value;
    }
    
    void UGWC::DefaultFontSize()
    {
        GCHandle Handle = GCHandle::FromIntPtr(IntPtr(UGWCAdress));
        GWCpp::GWC^ T = safe_cast<GWCpp::GWC^>(Handle.Target);
        T->DefaultFontSize();
    }

}
