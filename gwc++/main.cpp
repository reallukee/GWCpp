/*
    GWC++ (Graphic Window for Console Application)

    - Questo progetto è sotto lincenza MIT (https://mit-license.org)
    - Questo progetto è disponibile su GitHub (https://github.com/reallukee/GWCpp)
    - Maggiori informazioni sono diponibili nel file README.md

    ATUORE:			Realluke
    DESCRIZIONE:	File di test
    DATA:			09/03/22
*/


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
    GWCpp::GWC^ Form = gcnew GWCpp::GWC();

    // Creo la finestra.
    Form->StartWindow();

    // Cambio le impostazioni della finestra.
    Form->WindowTitle = "GWC++ Test";
    Form->WindowIcon = nullptr;
    Form->WindowIconVisible = false;
    Form->WindowLocation = System::Drawing::Point(50, 50);
    Form->WindowColor = Color::FromArgb(240, 240, 240);
    Form->WindowImage = nullptr;
    Form->WindowSize = System::Drawing::Size(850, 505);
    Form->WindowSizeState = FormWindowState::Normal;
    Form->WindowMinimumSize = System::Drawing::Size(0, 0);
    Form->WindowMaximumSize = System::Drawing::Size(0, 0);
    Form->WindowOpacity = 1.00;
    Form->WindowAlwaysOnTop = false;
    Form->WindowInTaskbar = true;
    Form->WindowButtons = true;
    Form->WindowMinimizeButton = true;
    Form->WindowMaximizeButton = true;

    // Cambio le impostazioni di disegno.
    Form->PenColor = Color::Red;
    Form->PenWidth = 10.0F;
    Form->FillColor = Color::Red;
    Form->FontName = "Comic Sans";
    Form->FontSize = 25.0F;

    // Scrivo del testo.
    Form->DrawText("GWC++", 100, 100);

    Console::ReadKey();

    // Chiudo la finestra.
    Form->CloseWindow();

    return 0;
}
