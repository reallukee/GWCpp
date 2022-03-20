# GWC++

![Oh no! Anyway...](./assets/banner.png "GWC++")

GWC++ o Graphic Window for Console Application è una libreria scritta in C++/CLI che mette a disposizione dei form personalizzati da utilizzare come tela da dipinto per applicazioni console .NET e C++ native per Windows.

> ⚠ GWC++ è **SOLO** un esperimento. Ne consiglio l'utilizzo solo per divertimento.



# Indice

**Contenuti interni**

- [Rilasci](#rilasci)
- [Esempi](#esempi)
- [Compilazione](#compilazione)
- [Strumenti](#strumenti)
- [Autore](#autore)
- [Licenza](#licenza)


**Contenuti esterni**

- [Documentazione](./DOCS.md)



# Rilasci

> 🎉 Una versione *"stabile"* di GWC++ è disponibile!

| Architettura<br /> versione | Ultima versione<br/> (Stabile)                                     | Ultima versione<br/> (Anteprima)                                   |
| :-------------------------: | :----------------------------------------------------------------: | :----------------------------------------------------------------: |
| x64                         | [Download](https://github.com/reallukee/GWCpp/releases/tag/v1.0.0) | [Download](https://github.com/reallukee/GWCpp/releases/tag/v1.0.0) |
| x86                         | [Download](https://github.com/reallukee/GWCpp/releases/tag/v1.0.0) | [Download](https://github.com/reallukee/GWCpp/releases/tag/v1.0.0) |

> ⚠ Per poter eseguire GWC++ è necessario [.NET Framework 4.8 Runtime](https://dotnet.microsoft.com/en-us/download/dotnet-framework/net48).



# Esempi

## Premesse

GWC++ offre la classe `MGWC` (Managed GWC) per le applicazioni console .NET e `UGWC` (Unmanaged GWC) per le applicazioni C++ native per Windows. Utilizzare la classe adatta al tipo di linguaggio e applicazione che si sta sviluppando. Nel caso di C++/CLI è possibile utilizzare entrambe le classi indistintamente.

## Applicazione console C#

```csharp
// main.cs

// Importo lo spazio dei nomi.
using GWCpp;

// Codice ...

// Istanza di MGWC.
MGWC Window = new MGWC(850, 505, "MGWC++ Window", 50, 50);

// Creo la finestra.
Window.StartWindow();

// Cambio le impostazioni di disegno.
Window.PenColor = new MGColor(255, 0, 0);
Window.FontName = "Comic Sans";
Window.FontSize = 25.0F;

// Scrivo del testo.
Window.DrawString("MGWC++", 250, 100);

Console.ReadKey();

// Chiudo la finestra.
Window.CloseWindow();

// Codice ...
```

## Applicazione console VB .NET

```vb
' main.vb

' Importo lo spazio dei nomi.
Imports GWCpp

' Codice ...

' Istanza di MGWC.
Dim Window As New MGWC(850, 505, "MGWC++ Window", 50, 50)

' Creo la finestra.
Window.StartWindow()

' Cambio le impostazioni di disegno.
Window.PenColor = New MGColor(255, 0, 0)
Window.FontName = "Comic Sans"
Window.FontSize = 25.0F

' Scrivo del testo.
Window.DrawString("MGWC++", 250, 100)

Console.ReadKey()

' Chiudo la finestra.
Window.CloseWindow()

' Codice ...
```

## Applicazione console C++/CLI

```cpp
// main.cpp

// Importo lo spazio dei nomi.
using namespace GWCpp;

// Codice ...

// Istanza di MGWC.
MGWC^ Window = gcnew MGWC(850, 505, "MGWC++ Window", 50, 50);

// Creo la finestra.
Window->StartWindow();

// Cambio le impostazioni di disegno.
Window->PenColor = gcnew MGColor(255, 0, 0);
Window->FontName = "Comic Sans";
Window->FontSize = 25.0F;

// Scrivo del testo.
Window->DrawString("MGWC++", 250, 100);

Console::ReadKey();

// Chiudo la finestra.
Window->CloseWindow();

// Codice ...
```

## Applicazione console C++

```cpp
// main.cpp

// Importo lo spazio dei nomi.
#include "ugwc++.h"

// Codice ...

// Istanza di UGWC.
GWCpp::UGWC* Window = new GWCpp::UGWC(850, 505, "UGWC++ Window", 50, 50);

// Creo la finestra.
Window->StartWindow();

// Cambio le impostazioni di disegno.
Window->SetPenColor(GWCpp::UGCOLOR{ 255, 0, 0 });
Window->SetFontName("Comic Sans");
Window->SetFontSize(25.0F);

// Scrivo del testo.
Window->DrawString("UGWC++", 250, 100);

system("pause");

// Chiudo la finestra.
Window->CloseWindow();

// Codice ...
```



# Compilazione

1. Installare l'ultima versione di [Visual Studio](https://visualstudio.microsoft.com/it/vs/).

    - Installare il carico di lavoro `Sviluppo di applicazioni desktop con C++`.
    - Installare il carico di lavoro `Sviluppo per desktop .NET`.
    - Installare il componente facoltativo `Supporto C++/CLI per Build Tools v143`.
    - Installare il componente facoltativo `.NET Framework 4.8 SDK`.

2. Clonare la repository.

    ```git
    git clone https://github.com/reallukee/GWCpp.git
    ```

3. Aprire con Visual Studio il file `gwc++.sln` o eseguire lo script `build.cmd`.



# Strumenti

- [Visual Studio 2022](https://visualstudio.microsoft.com/it/vs/)
- [MSVC v143](https://docs.microsoft.com/it-it/cpp/build/reference/compiling-a-c-cpp-program?view=msvc-170)
- [.NET Framework 4.8](https://dotnet.microsoft.com/en-us/download/dotnet-framework/net48)



# Autore

- [@reallukee](https://github.com/reallukee)



# Licenza

GWC++ è sotto licenza [MIT](./LICENSE).
