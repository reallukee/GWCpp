#include <iostream>

// Importo lo spazio dei nomi.
#include "../gwc++/ngwc++.h"

int main()
{
    // Istanza di NGWC.
    NGWCpp::NGWC* Form = new NGWCpp::NGWC(850, 505, "NGWC++ Test", 50, 50);

    // Creo la finestra.
    Form->StartWindow();

    // Cambio le impostazioni di disegno.
    Form->SetPenColor(NCOLOR{ 255, 0, 0 });
    Form->SetFontName("Comic Sans");
    Form->SetPenWidth(25.0F);

    // Scrivo del testo.
    Form->DrawText("GWC++", 250, 100);

    system("pause");

    // Chiudo la finestra.
    Form->CloseWindow();
}
