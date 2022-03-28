Imports System
Imports GWCpp

Namespace VBNet

    Module ProgramMain

        Sub Main()
            Console.Title = "GWC++ Application"
            Console.WriteLine("GWC++ Application")
            Dim Wd As New MGWC(850, 505, "GWC++ Application")
            Wd.StartWindow()

            ' Your code...

            Console.WriteLine("Press any key to continue...")
            Console.ReadKey()
            Wd.CloseWindow()
        End Sub

    End Module

End Namespace
