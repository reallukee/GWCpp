/*
    GWC++ (Graphic Window for Console Application)

    - Questo progetto è sotto lincenza MIT (https://mit-license.org)
    - Questo progetto è disponibile su GitHub (https://github.com/reallukee/GWCpp)
    - Maggiori informazioni sono diponibili nel file README.md

    ATUORE:			Realluke
    DESCRIZIONE:	Test
    DATA:			09/03/22
*/


#include "pch.h"
#pragma unmanaged


#include <iostream>
#include <time.h>
#include <stdlib.h>
#include <math.h>


// Includo NGWC++
#include "ngwc++.h"

// Dichiarazione di un puntatore NGWC
NGWCpp::NGWC* Form;


int Main()
{
    // Istanza di NGWC
    NGWCpp::NGWC* Form = new NGWCpp::NGWC(850, 505, "NGWC++ Test", 50, 50);

    // Creo la finestra
    Form->StartWindow();

    // Cambio le impostazioni di disegno
    Form->SetPenColor(NCOLOR{ 255, 0, 0 });
    Form->SetFontName("Comic Sans");
    Form->SetPenWidth(25.0F);

    // Scrivo del testo
    Form->DrawString("GWC++", 250, 100);

    system("pause");

    // Chiudo la finestra
    Form->CloseWindow();

    // Elimino l'istanza
    delete Form;

    return 0;
}
