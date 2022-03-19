/*
    GWC++ (Graphic Window for Console Application)

    - Questo progetto è sotto lincenza MIT (https://mit-license.org)
    - Questo progetto è disponibile su GitHub (https://github.com/reallukee/GWCpp)
    - Maggiori informazioni sono diponibili nel file README.md

    ATUORE:			Realluke
    DESCRIZIONE:	UMani (Unmanaged Main)
    DATA:			14/03/22
*/


#include "pch.h"
#pragma unmanaged

// Includo NGWC++
#include "ugwc++.h"

void UMain()
{
    // Istanza di NGWC
    GWCpp::UGWC* Window = new GWCpp::UGWC(850, 505, "NGWC++ Test", 50, 50);

    // Creo la finestra
    Window->StartWindow();

    // Cambio le impostazioni di disegno
    Window->SetPenColor(GWCpp::UGColor{ 255, 0, 0 });
    Window->SetFontName("Comic Sans");
    Window->SetPenWidth(25.0F);

    // Scrivo del testo
    Window->DrawString("GWC++", 250, 100);

    system("pause");

    // Chiudo la finestra
    Window->CloseWindow();

    // Elimino l'istanza
    delete Window;
}
