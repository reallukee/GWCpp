#include <iostream>

// Importo lo spazio dei nomi.
#include "../gwc++/ngwc++.h"

int main()
{
    // Istanza di GWC.
    NGWCpp::NGWC* Form = new NGWCpp::NGWC(850, 505, "GWC++ Test", 50, 50);

    // Creo la finestra.
    Form->StartWindow();

    // Cambio le impostazioni di disegno.
    Form->SetPenColor(COLORN{ 255, 0, 0 });
    Form->SetPenWidth(5.0F);

    // Scrivo del testo.
    Form->DrawRectangle(10, 10, 100, 100);

    system("pause");

    // Chiudo la finestra.
    Form->CloseWindow();
}
