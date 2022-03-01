#include "pch.h"
#include "gwc++.h"


using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;
using namespace System::Threading;


int Main()
{
    GWCpp::GWC^ Form = gcnew GWCpp::GWC(850, 505, "GWC++ Test", 50, 50);

    // Creo la finestra.
    Form->StartWindow();

    // Cambio le impostazioni della finestra.
    Form->WindowTitle = "GWC++ Window";
    Form->WindowIcon = gcnew Icon("app.ico");
    Form->WindowLocation = Point(50, 50);
    Form->WindowColor = Color::Gainsboro;
    Form->WindowSize = Size(850, 505);
    Form->WindowMinimumSize = Size(850, 505);
    Form->WindowMaximumSize = Size(0, 0);

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
