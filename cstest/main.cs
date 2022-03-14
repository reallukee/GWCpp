/*
	CSTest

	- Questo progetto è sotto lincenza MIT (https://mit-license.org)
	- Questo progetto è disponibile su GitHub (https://github.com/reallukee/GWCpp)
	- Maggiori informazioni sono diponibili nel file README.md

	ATUORE:			Realluke
	DESCRIZIONE:	CSTest
	DATA:			14/03/22
*/


using System;
using System.Drawing;

// Importo lo spazio dei nomi
using GWCpp;

namespace CSText
{
    internal class CSTest
    {
        static void Main()
        {
            // Istanza di GWC
            GWC Form = new GWC(850, 505, "GWC++ Test", 50, 50);

            // Creo la finestra
            Form.StartWindow();

            // Cambio le impostazioni di disegno
            Form.PenColor = new GColor(255, 0, 0);
            Form.FontName = "Comic Sans";
            Form.FontSize = 25.0F;

            // Scrivo del testo
            Form.DrawString("GWC++", 250, 100);

            Console.ReadKey();

            // Chiudo la finestra
            Form.CloseWindow();
        }
    }
}
