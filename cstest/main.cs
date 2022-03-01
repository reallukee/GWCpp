using System;
using System.Drawing;

// Importo lo spazio dei nomi.
using GWCpp;

namespace CSText
{
    internal class CSTest
    {
        static void Main()
        {
            // Istanza di GWC.
            GWC Form = new GWC(850, 505, "GWC++ Test", 50, 50);

            // Creo la finestra.
            Form.StartWindow();

            // Cambio le impostazioni di disegno.
            Form.PenColor = Color.Red;
            Form.FontName = "Comic Sans";
            Form.FontSize = 25.0F;

            // Scrivo del testo.
            Form.DrawText("GWC++", 250, 100);

            Console.ReadKey();

            // Chiudo la finestra.
            Form.CloseWindow();
        }
    }
}
