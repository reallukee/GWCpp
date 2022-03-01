Imports System
Imports System.Drawing

' Importo lo spazio dei nomi.
Imports GWCpp

Namespace VBTest

    Module VBTest

        Sub Main()
            Dim Form As New GWC(850, 505, "GWC++ Test", 50, 50)

            ' Creo la finestra.
            Form.StartWindow()

            ' Cambio le impostazioni di disegno.
            Form.PenColor = Color.Red
            Form.FontName = "Comic Sans"
            Form.FontSize = 25.0F

            ' Scrivo del testo.
            Form.DrawText("GWC++", 250, 100)

            Console.ReadKey()

            ' Chiudo la finestra.
            Form.CloseWindow()
        End Sub

    End Module

End Namespace
