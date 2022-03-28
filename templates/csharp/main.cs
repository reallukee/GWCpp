using System;
using GWCpp;

namespace CSharp
{
    internal class ProgramMain
    {
        static void Main()
        {
            Console.Title = "GWC++ Application";
            Console.WriteLine("GWC++ Application");
            MGWC Wd = new MGWC(850, 505, "GWC++ Application");
            Wd.StartWindow();

            // Your code...

            Console.WriteLine("Press any key to continue...");
            Console.ReadKey();
            Wd.CloseWindow();
        }
    }
}
