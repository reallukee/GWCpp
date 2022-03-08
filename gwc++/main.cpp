#include "pch.h"
#include "gwc++.h"


using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;
using namespace System::Threading;
using namespace System::Runtime::InteropServices;
using namespace Microsoft::VisualBasic;


int Main()
{
    // Nuova istanza di GWC.
    GWCpp::GWC^ Form = gcnew GWCpp::GWC(850, 505, "GWC++ Test", 50, 50);

    // Creo la finestra.
    Form->StartWindow();

    // Cambio le impostazioni della finestra.
    Form->WindowTitle = "GWC++ Window";
    Form->WindowIcon = gcnew Icon("app.ico");
    Form->WindowIconVisible = true;
    Form->WindowLocation = Point(50, 50);
    Form->WindowColor = Color::Gainsboro;
    Form->WindowImage = nullptr;
    Form->WindowSize = Size(850, 505);
    Form->WindowMinimumSize = Size(850, 505);
    Form->WindowMaximumSize = Size(0, 0);
    Form->Opacity = 1.00;
    Form->TopMost = false;
    Form->ShowInTaskbar = true;
    Form->MinimizeBox = true;
    Form->MaximizeBox = true;

    // Cambio le impostazioni di disegno.
    Form->PenColor = Color::Red;
    Form->PenWidth = 10.0F;
    Form->FillColor = Color::Red;
    Form->FontName = "Comic Sans";
    Form->FontSize = 25.0F;

    // Scrivo del testo.
    Form->DrawText("GWC++", 250, 100);

    Console::ReadKey();

    // Chiudo la finestra.
    Form->CloseWindow();

    return 0;
}
