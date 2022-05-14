/*
    Mastermind con GWC++

    - Questo progetto è sotto lincenza MIT (https://mit-license.org)
    - Questo progetto è disponibile su GitHub (https://github.com/reallukee/GWCpp)
    - Maggiori informazioni sono diponibili nel file README.md


    ATUORE:			Realluke | Aka Luca Pollicino
    DESCRIZIONE:	Mastermind
    DATA:			24/04/22
    VERSIONE:		1.0.0
*/

#include <iostream>
#include <ctime>
#include <cstdlib>
#include <sstream>
#include "..\..\gwc++\hgwc++.h"

using namespace std;
using namespace GWCpp;

int main()
{
    int Segreto[4] = { 0, 0, 0, 0 };
    int SegretoVerificato[4] = { 1, 1, 1, 1 };
    int SegretoFix[4] = { 0, 0, 0, 0 };
    int Tentativo[4] = { 0, 0, 0, 0 };
    int TentativoVerificato[4] = { 0, 0, 0, 0 };
    int TentativoFix[4] = { 0, 0, 0, 0 };

    UColor Colori[6] = {
        UColor{ 220, 20, 60 },
        UColor{ 0, 100, 0 },
        UColor{ 255, 215, 0 },
        UColor{ 30, 145, 255 },
        UColor{ 0, 255, 0 },
        UColor{ 255, 255, 0 }
    };

    srand(time(0));
    rand() % 66666;

    for (int I = 0; I < 4; I++)
    {
        int N = rand() % 4;
        SegretoVerificato[N] = 0;
        Segreto[I] = N;
    }

    for (int I = 0; I < 4; I++)
    {
        int C = 0;

        for (int J = 0; J < 4; J++)
        {
            if (Segreto[J] == I)
            {
                C++;
            }
        }

        TentativoVerificato[I] = C;
    }

    // HICON AppIcon = (HICON)LoadImage(0, L"..\\..\\assets\\mario.ico", IMAGE_ICON, 0, 0, LR_LOADFROMFILE);
    UGWC* Wd = new UGWC(560, 900, "Mastermind");
    Wd->StartWindow();
    // Wd->SetWindowIcon(AppIcon);
    Wd->SetWindowColor(UColor{ 0, 0, 0 });
    Wd->SetWindowMinimumSize(Wd->GetWindowSize());
    Wd->SetWindowMaximumSize(Wd->GetWindowSize());
    Wd->SetWindowMinimizeButton(false);
    Wd->SetWindowMaximizeButton(false);
    Wd->SetHStringAlignment(UStringAlignment::Center);
    Wd->SetVStringAlignment(UStringAlignment::Center);
    Wd->SetFontName("Consolas");
    Wd->SetFillColor(UColor{ 0, 0, 255 });
    Wd->SetFontSize(50.0);
    Wd->DrawString("Mastermind", 0, 300, 560, 100);
    Wd->SetFillColor(UColor{ 255, 255, 255 });
    Wd->SetFontSize(20.0);
    Wd->DrawString("Premi un tasto!", 0, 400, 560, 50);
    Wd->RequestKeyDown();
    Wd->ClearWindow();

    for (int X = 0; X < 4; X++)
    {
        Wd->SetFillColor(UColor{ 30, 30, 30 });
        Wd->DrawFullCircle(60 + X * 72, 60, 30);
    }

    for (int Y = 0; Y < 10; Y++)
    {
        for (int X = 0; X < 4; X++)
        {
            Wd->SetFillColor(UColor{ 30, 30, 30 });
            Wd->DrawFullCircle(60 + X * 72, 150 + Y * 72, 30);
        }

        for (int X = 0; X < 4; X++)
        {
            Wd->SetFillColor(UColor{ 30, 30, 30 });
            Wd->DrawFullCircle(360 + X * 48, 150 + Y * 72, 15);
        }
    }

    bool Vittoria = false;

    for (int Tentativi = 10; Tentativi > 0 && Vittoria == false; Tentativi--)
    {
        int Giusto = 0;
        int Errato = 0;

        for (int I = 0; I < 4; I++)
        {
            Wd->SetFillColor(UColor{ 255, 255, 255 });
            Wd->DrawFullCircle(60 + I * 72, 150 + (Tentativi - 1) * 72, 30);

            char CaratteriValidi[4] = { '1', '2', '3', '4' };
            bool CarattereValido = false;

            while (!CarattereValido)
            {
                char C = Wd->RequestKeyDown();

                if (C == 'q' || C == 'Q')
                {
                    Wd->CloseWindow();
                    delete Wd;
                    return 0;
                }

                for (int J = 0; J < 4; J++)
                {
                    if (C == CaratteriValidi[J])
                    {
                        CarattereValido = true;
                        Tentativo[I] = C - 1 - 48;
                    }
                }
            }

            Wd->SetFillColor(Colori[Tentativo[I]]);
            Wd->DrawFullCircle(60 + I * 72, 150 + (Tentativi - 1) * 72, 30);
        }

        for (int I = 0; I < 4; I++)
        {
            int A = 0;
            int B = 0;

            for (int y = 0; y < 4; y++)
            {
                if (Segreto[y] == I)
                {
                    A++;
                }

                if (Tentativo[y] == I)
                {
                    B++;
                }
            }

            SegretoFix[I] = A;
            TentativoFix[I] = B;
        }

        for (int I = 0; I < 4; I++)
        {
            if (Segreto[I] == Tentativo[I])
            {
                TentativoVerificato[Tentativo[I]]--;
                Giusto++;
            }
        }

        for (int I = 0; I < 4; I++)
        {
            for (int J = 0; J < 4; J++)
            {
                if (TentativoVerificato[Tentativo[I]] > 0 && Segreto[J] == Tentativo[I])
                {
                    TentativoVerificato[Tentativo[I]]--;
                    Errato++;
                }
            }
        }

        for (int I = 0; I < 4; I++)
        {
            if (SegretoFix[I] >= TentativoFix[I] && TentativoFix[I] > 0 && SegretoFix[I] > 0)
            {
                Errato -= (SegretoFix[I] - TentativoFix[I]);
            }
        }

        for (int X = 0; X < Giusto; X++)
        {
            Wd->SetFillColor(Colori[4]);
            Wd->DrawFullCircle(360 + X * 48, 150 + (Tentativi - 1) * 72, 15);
        }

        for (int X = Giusto; X < Giusto + Errato; X++)
        {
            Wd->SetFillColor(Colori[5]);
            Wd->DrawFullCircle(360 + X * 48, 150 + (Tentativi - 1) * 72, 15);
        }

        if (Giusto == 4)
        {
            Vittoria = true;
        }

        for (int I = 0; I < 4; I++)
        {
            int C = 0;

            for (int J = 0; J < 4; J++)
            {
                if (Segreto[J] == I)
                {
                    C++;
                }
            }

            TentativoVerificato[I] = C;
        }
    }

    if (Vittoria)
    {
        Wd->ClearWindow();
        Wd->SetFillColor(UColor{ 0, 255, 0 });
        Wd->SetFontSize(50.0);
        Wd->DrawString("Hai vinto!", 0, 350, 560, 100);
    }
    else
    {
        Wd->ClearWindow();
        Wd->SetFillColor(UColor{ 255, 0, 0 });
        Wd->SetFontSize(50.0);
        Wd->DrawString("Hai perso!", 0, 350, 560, 100);
    }

    Wd->SetFillColor(UColor{ 255, 255, 255 });
    Wd->SetFontSize(20.0);
    Wd->DrawString("Premi un tasto!", 0, 400, 560, 100);
    Wd->RequestKeyDown();
    Wd->CloseWindow();
    delete Wd;
    return 0;
}
