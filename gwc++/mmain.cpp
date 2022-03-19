/*
    GWC++ (Graphic Window for Console Application)

    - Questo progetto è sotto lincenza MIT (https://mit-license.org)
    - Questo progetto è disponibile su GitHub (https://github.com/reallukee/GWCpp)
    - Maggiori informazioni sono diponibili nel file README.md

    ATUORE:			Realluke
    DESCRIZIONE:	MMain (Managed Main)
    DATA:			14/03/22
*/


#include "pch.h"
#pragma managed

// Includo GWC++
#include "mgwc++.h"

void MMain()
{
    GWCpp::MGWC^ Window = gcnew GWCpp::MGWC(850, 505, "GWC++ Test", 50, 50);

    // Creo la finestra.
    Window->StartWindow();

    // Cambio le impostazioni di disegno.
    Window->PenColor = GWCpp::MGColor(255, 0, 0);
    Window->FontName = "Comic Sans";
    Window->FontSize = 25.0F;

    Window->DrawPixel(100, 100);

    // Scrivo del testo.
    Window->DrawString("GWC++", 250, 100);

    Console::ReadKey();

    // Chiudo la finestra.
    Window->CloseWindow();
}
