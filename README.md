# GWC++

![Oh no! Anyway...](./assets/banner.png "GWC++")

GWC++ o Graphic Window for Console Application è una libreria scritta in C++/CLI che mette a disposizione dei form personalizzati da utilizzare come tela da dipinto per applicazioni console .NET e C++ native per Windows.

> ⚠ GWC++ è **SOLO** un esperimento, ne sconsiglio quindi l'utilizzo. 



# Indice

- [Rilasci](#rilasci)
- [Esempi](#esempi)
- [Documentazione](#documentazione)
- [Strumenti](#strumenti)
- [Autore](#autore)
- [Licenza](#licenza)



# Rilasci

> ⚠ Una versione stabile di GWC++ verrà presto rilasciata.

| Architettura<br /> versione | Ultima versione<br/> (Stabile) | Ultima versione<br/> (Anteprima)                                           |
| :-------------------------: | :----------------------------: | :------------------------------------------------------------------------: |
| x64                         | -                              | [Download](https://github.com/reallukee/GWCpp/releases/tag/v0.0.4-preview) |
| x86                         | -                              | [Download](https://github.com/reallukee/GWCpp/releases/tag/v0.0.4-preview) |



# Esempi

## Applicazione console C#

```csharp
// main.cs

// Importo lo spazio dei nomi.
using GWCpp;

// Codice ...

// Istanza di GWC.
GWC Window = new GWC(850, 505, "GWC++ Test", 50, 50);

// Creo la finestra.
Window.StartWindow();

// Cambio le impostazioni di disegno.
Window.PenColor = Color.Red;
Window.FontName = "Comic Sans";
Window.FontSize = 25.0F;

// Scrivo del testo.
Window.DrawText("GWC++", 250, 100);

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

' Istanza di GWC.
Dim Window As New GWC(850, 505, "GWC++ Test", 50, 50)

' Creo la finestra.
Window.StartWindow()

' Cambio le impostazioni di disegno.
Window.PenColor = Color.Red
Window.FontName = "Comic Sans"
Window.FontSize = 25.0F

' Scrivo del testo.
Window.DrawText("GWC++", 250, 100)

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

// Istanza di GWC.
GWC^ Window = gcnew GWC(850, 505, "GWC++ Test", 50, 50);

// Creo la finestra.
Window->StartWindow();

// Cambio le impostazioni di disegno.
Window->PenColor = Color::Red;
Window->FontName = "Comic Sans";
Window->FontSize = 25.0F;

// Scrivo del testo.
Window->DrawText("GWC++", 250, 100);

Console::ReadKey();

// Chiudo la finestra.
Window->CloseWindow();

// Codice ...
```

## Applicazione console C++

```cpp
// main.cpp

// Importo lo spazio dei nomi.
#include "ngwc++.h"

// Codice ...

// Istanza di NGWC.
NGWCpp::NGWC* Window = new NGWCpp::NGWC(850, 505, "NGWC++ Test", 50, 50);

// Creo la finestra.
Window->StartWindow();

// Cambio le impostazioni di disegno.
Window->SetPenColor(NCOLOR{ 255, 0, 0 });
Window->SetFontName("Comic Sans");
Window->SetPenWidth(25.0F);

// Scrivo del testo.
Window->DrawText("GWC++", 250, 100);

system("pause");

// Chiudo la finestra.
Window->CloseWindow();

// Codice ...
```



# Documentazione

## Metodi

> ⚠ Non tutti i metodi elencati in questa sezione sono presenti e utilizzabili all'interno della classe `NGWC` e quindi all'interno di applicazioni C++ native per Windows.

### Finestra

- `StartWindow`
- `CloseWindow`
- `SuspendWindow`
- `ResumeWindow`
- `ShowWindow`
- `HideWindow`
- `RequestMouseDown`
- `RequestMouseUp`
- `RequestKeyDown`
- `RequestKeyUp`

### Disegno

- `DefaultPenColor`
- `DefaultPenWidth`
- `DefaultFillColor`
- `DefaultFontName`
- `DefaultFontSize`
- `ClearWindow`
- `SaveCanvas`
- `RestoreCanvas`
- `DrawPixel`
- `DrawLine`
- `DrawArc`
- `DrawBezier`
- `DrawText`
- `DrawImage`
- `DrawImageFromFile`
- `DrawIcon`
- `DrawIconFromFile`
- `DrawSquare`
- `DrawFillSquare`
- `DrawRectangle`
- `DrawFillRectangle`
- `DrawEllipse`
- `DrawFillEllipse`
- `DrawCircle`
- `DrawFillCircle`
- `DrawCurve`
- `DrawClosedCurve`
- `DrawPolygon`
- `DrawFillPolygon`
- `DrawPie`
- `DrawFillPie`
- `DrawFromScreen`



## Proprietà

> ⚠ Non tutte le proprietà elencate in questa sezione sono presenti e utilizzabili all'interno della classe `NGWC` e quindi all'interno di applicazioni C++ native per Windows.

> ⚠ In C++ non esisteno le proprietà per questo motivo all'interno di `NGWC` è necessario chiamare le funzioni `Get<Nome proprietà>` per ottenere il valore della proprietà e `Set<Nome Proprietà>` per impostare il valore della proprietà.

```cpp
// C++/CLI
System::String^ Title = Window->WindowTitle;
Window->WindowTitle = "New Title";

// C++
std::string Window = Window->GetWindowTitle();
Window->SetWindowTitle("New Title");
```



### Finestra

- `WindowTitle`
- `WindowIcon`
- `WindowIconVisible`
- `WindowLocation`
- `WindowColor`
- `WindowImage`
- `WindowSize`
- `WindowSizeState`
- `WindowMinimumSize`
- `WindowMaximumSize`
- `WindowOpacity`
- `WindowAlwaysOnTop`
- `WindowInTaskbar`
- `WindowButtons`
- `WindowMinimizeButton`
- `WindowMaximizeButton`

### Disegno

- `PenColor`
- `PenWidth`
- `FillColor`
- `FontName`
- `FontSize`



## Strutture

> ⚠ Queste strutture sono scritte in C++ nativo.

- `NPOINT`
- `NSIZE`
- `NCOLOR`



# Strumenti

- GWC++
    - [Visual Studio 2022](https://visualstudio.microsoft.com/it/vs/)
    - [MSVC v143](https://docs.microsoft.com/it-it/cpp/build/reference/compiling-a-c-cpp-program?view=msvc-170)
    - [.NET Framework 4.8](https://dotnet.microsoft.com/en-us/download/dotnet-framework/net48)

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
