/*
    GWC++ (Graphic Window for Console Application)

    - Questo progetto è sotto lincenza MIT (https://mit-license.org)
    - Questo progetto è disponibile su GitHub (https://github.com/reallukee/GWCpp)
    - Maggiori informazioni sono diponibili nel file README.md


    ATUORE:			Realluke | Aka Luca Pollicino
    DESCRIZIONE:	UMain (Unmanaged Main)
    DATA:			05/04/22
    VERSIONE:		1.1.2
*/

#include "pch.h"
#pragma unmanaged

// Includo UGWC++.
#include "ugwc++.h"

void UMain()
{
    // Istanza di UGWC.
    GWCpp::UGWC* Wd = new GWCpp::UGWC(850, 505, "GWC++ Window", 50, 50);

    // Creo la finestra.
    Wd->StartWindow();

    // Cambio le impostazioni di disegno.
    Wd->SetFillColor(URed);
    Wd->SetFontName("MS Comic Sans");
    Wd->SetFontSize(25.0F);

    // Scrivo del testo.
    Wd->DrawString("GWC++", 32, 32);

    system("pause");

    // Chiudo la finestra.
    Wd->CloseWindow();

    // Elimino l'istanza.
    delete Wd;
}
