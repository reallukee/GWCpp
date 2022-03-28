#include <iostream>
#include "hgwc++.h"

using namespace std;
using namespace GWCpp;

int main()
{
    system("title GWC++ Application");
    cout << "GWC++ Application" << endl;
    UGWC* Wd = new UGWC(850, 505, "GWC++ Application");
    Wd->StartWindow();

    // Your code...

    cout << "Press any key to continue..." << endl;
    system("pause");
    Wd->CloseWindow();
    delete Wd;
}
