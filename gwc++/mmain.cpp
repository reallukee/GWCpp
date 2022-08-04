/*
    GWC++ (Graphic Window for Console Application)

    - Questo progetto è sotto lincenza MIT (https://mit-license.org)
    - Questo progetto è disponibile su GitHub (https://github.com/reallukee/GWCpp)
    - Maggiori informazioni sono diponibili nel file README.md


    ATUORE:			Realluke | Aka Luca Pollicino
    DESCRIZIONE:	MMain (Managed Main)
    DATA:			05/04/22
    VERSIONE:		1.1.1
*/

#include "pch.h"
#pragma managed

// Includo MGWC++.
#include "mgwc++.h"

void MMain()
{
    // Utilizzo MGWC.
    GWCpp::MGWC^ Wd = gcnew GWCpp::MGWC(850, 505, "GWC++ Window", 50, 50);

    // Creo la finestra.
    Wd->StartWindow();

    // Cambio le impostazioni di disegno.
    Wd->FillColor = MRed;
    Wd->FontName = "MS Comic Sans";
    Wd->FontSize = 25.0F;

    // Scrivo del testo.
    Wd->DrawString("GWC++", 32, 32);

    Console::ReadKey();

    // Chiudo la finestra.
    Wd->CloseWindow();
}
