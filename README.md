# GWC++

![Oh no! Anyway...](./assets/banner.png "GWC++")

GWC++ o Graphic Window for Console Application è una libreria scritta in C++/CLI che mette a disposizione dei form personalizzati da utilizzare come tela da dipinto per applicazioni console .NET e C++ native per Windows.

> ⚠ GWC++ è **SOLO** un esperimento, ne sconsiglio quindi l'utilizzo. 



# Indice

**Contenuti interni**

- [Rilasci](#rilasci)
- [Esempi](#esempi)
- [Strumenti](#strumenti)
- [Autore](#autore)
- [Licenza](#licenza)

**Contenuti esterni**

- [Documentazione](./DOCS.md)



# Rilasci

> ⚠ Una versione stabile di GWC++ verrà presto rilasciata.

| Architettura<br /> versione | Ultima versione<br/> (Stabile) | Ultima versione<br/> (Anteprima)                                           |
| :-------------------------: | :----------------------------: | :------------------------------------------------------------------------: |
| x64                         | -                              | [Download](https://github.com/reallukee/GWCpp/releases/tag/v0.0.3-preview) |
| x86                         | -                              | [Download](https://github.com/reallukee/GWCpp/releases/tag/v0.0.3-preview) |



# Esempi

## Applicazione console C#

```csharp
// main.cs

// Importo lo spazio dei nomi.
using GWCpp;

// Codice ...

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

// Codice ...
```

## Applicazione console VB .NET

```vb
' main.vb

' Importo lo spazio dei nomi.
Imports GWCpp

' Codice ...

' Istanza di GWC.
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

' Codice ...
```

## Applicazione console C++/CLI

```cpp
// main.cpp

// Importo lo spazio dei nomi.
using namespace GWCpp;

// Codice ...

// Istanza di GWC.
GWC^ Form = gcnew GWC(850, 505, "GWC++ Test", 50, 50);

// Creo la finestra.
Form->StartWindow();

// Cambio le impostazioni di disegno.
Form->PenColor = Color::Red;
Form->FontName = "Comic Sans";
Form->FontSize = 25.0F;

// Scrivo del testo.
Form->DrawText("GWC++", 250, 100);

Console::ReadKey();

// Chiudo la finestra.
Form->CloseWindow();

// Codice ...
```

## Applicazione console C++

```cpp
// main.cpp

// Importo lo spazio dei nomi.
#include "ngwc++.h"

// Codice ...

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

// Codice ...
```



# Strumenti

- GWC++
    - [Visual Studio 2022](https://visualstudio.microsoft.com/it/vs/)
    - [MSVC v143](https://docs.microsoft.com/it-it/cpp/build/reference/compiling-a-c-cpp-program?view=msvc-170)
    - [.NET Framework 4.8](https://dotnet.microsoft.com/en-us/download/dotnet-framework/net48)

- CPPTest
    - [Visual Studio 2022](https://visualstudio.microsoft.com/it/vs/)
    - [MSVC v143](https://docs.microsoft.com/it-it/cpp/build/reference/compiling-a-c-cpp-program?view=msvc-170)

- CSTest
    - [Visual Studio 2022](https://visualstudio.microsoft.com/it/vs/)
    - [.NET Framework 4.8](https://dotnet.microsoft.com/en-us/download/dotnet-framework/net48)

- VBText
    - [Visual Studio 2022](https://visualstudio.microsoft.com/it/vs/)
    - [.NET Framework 4.8](https://dotnet.microsoft.com/en-us/download/dotnet-framework/net48)



# Autore

- [@reallukee](https://github.com/reallukee)



# Licenza

GWC++ è sotto licenza [MIT](https://mit-license.org/).
