# GWC++

![Oh no! Anyway...](./assets/banner.png "GWC++")

GWC++ o Graphic Window for Console Application è una libreria scritta in C++/CLI che mette a disposizione dei form personalizzati da utilizzare come tela da dipinto per applicazioni console .NET e C++ native per Windows.

> ⚠ GWC++ è **SOLO** un esperimento, ne sconsiglio quindi l'utilizzo. 



# Indice

- [Rilasci](#rilasci)
- [Utilizzo](#utilizzo)
- [Documentazione](#documentazione)
- [Strumenti](#strumenti)
- [Autore](#autore)
- [Licenza](#licenza)



# Rilasci

> ⚠ Una versione stabile di GWC++ verrà presto rilasciata.

| Architettura<br /> versione | Ultima versione<br/> (Stabile) | Ultima versione<br/> (Anteprima)                                           |
| :-------------------------: | :----------------------------: | :------------------------------------------------------------------------: |
| x64                         | -                              | [Download](https://github.com/reallukee/GWCpp/releases/tag/v0.0.1-preview) |
| x86                         | -                              | [Download](https://github.com/reallukee/GWCpp/releases/tag/v0.0.1-preview) |



# Utilizzo

GWC++ mette a disposizione la classe `GWC` per le applicazioni console .NET e `NGWC` per le applicazioni console c++ native per Windows. Utilizzare la classe adatta alla tipologia di applicazione che si sta sviluppando. Vedi la [documentazione](#documentazione) per la disponibilità di metodi e funzioni.

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

// Istanza di GWC.
NGWCpp::NGWC* Form = new NGWCpp::NGWC(850, 505, "GWC++ Test", 50, 50);

// Creo la finestra.
Form->StartWindow();

// Cambio le impostazioni di disegno.
Form->SetPenColor(COLORN{ 255, 0, 0 });
Form->SetPenWidth(5.0F);

// Scrivo del testo.
Form->DrawRectangle(10, 10, 100, 100);

system("pause");

// Chiudo la finestra.
Form->CloseWindow();

// Codice ...
```



# Documentazione

## Funzioni

> ⚠ Non tutti i metodi elencati qui sotto sono presenti nella classe `NGWC` e quindi utilizzabili in applicazioni console C++ native per Windows. I metodi compatibili con applicazioni console C++ native Windows per sono indicati con il simbolo '✅' mentre quelli non compatibili con il simbolo '❎'. La disponibilità verrà estesa in futuro.

### Finestra

- ✅ `StartWindow()` Crea la finestra.
- ✅ `CloseWindow()` Chiude la finastra.
- ✅ `SuspendWindow()` Sospende la finestra.
- ✅ `ResumeWindow()` Riprende la finestra.
- ✅ `ShowWindow()` Mostra la finestra.
- ✅ `HideWindow()` Nasconde la finestra.
- ✅ `RequestMouseDown(int B)` Richiede la pressione di un tasto del mouse.
- ✅ `RequestMouseUp(int B)` Richiede il rilascio di un tasto del mouse.
- ✅ `RequestKeyDown(char C)` Richiede la pressione di un tasto preciso.
- ✅ `RequestKeyDown()` Richiede la pressione di un tasto.
- ✅ `RequestKeyUp(char C)` Richiede il rilascio di un tasto preciso.
- ✅ `RequestKeyUp()` Richiede il rilascio di un tasto.

### Disegno

- ✅ `DefaultPenColor()` Imposta il colore della penna al suo valore di base.
- ✅ `DefaultPenWidth()` Imposta la dimensione della penna al suo valore di base.
- ✅ `DefaultFillColor()` Imposta il colore di riempimento al suo valore di base.
- ❎ `DefaultFontName()` Imposta il nome del font al suo valore di base.
- ✅ `DefaultFontSize()` Imposta la dimensione del font al suo valore di base.
- ✅ `ClearWindow()` Rimuove tutti i disegni.
- ✅ `DrawFromScreen(int X1, int Y1, int X2, int Y2, int W, int H)` Disegna un rettangolo di pixel dallo schermo.
- ✅ `SaveCanvas()` Salva gli oggetti grafici presenti nella finestra.
- ✅ `RestoreCanvas()` Ripristina gli oggetti grafici presenti nella finestra.
- ✅ `DrawLine(int X1, int Y1, int X2, int Y2)` Esegue la scrittura di una linea.
- ✅ `DrawArc(int X, int Y, int W, int H, int A, int B)` Esegue la scrittura di un arco.
- ✅ `DrawBezier(int X1, int Y1, int X2, int Y2, int X3, int Y3, int X4, int Y4)` Disegna un bezier.
- ✅ `DrawText(string S, int X, int Y)` Disegna del testo.
- ❎ `DrawImage(Image I, int X, int Y)` Disegna un immagine.
- ❎ `DrawImageFromFile(String^ F, int X, int Y)` Disegna un immagine da un file.
- ❎ `DrawIcon(Icon I, int X, int Y)` Disegna un'icona.
- ❎ `DrawIconFromFile(String^ F, int X, int Y)` Disegna un'icona da un file.
- ✅ `DrawRectangle(int X, int Y, int W, int H)` Disegna un rettangolo.
- ✅ `DrawFillRectangle(int X, int Y, int W, int H)` Disegna un rettangolo pieno.
- ✅ `DrawEllipse(int X, int Y, int W, int H)` Disegna un ellisse.
- ✅ `DrawFillEllipse(int X, int Y, int W, int H)` Disegna un ellisse pieno.
- ❎ `DrawCurve(array<Point>^ P)` Disegna una curva.
- ❎ `DrawClosedCurve(array<Point>^ P)` Disegna una curva chiusa.
- ❎ `DrawPolygon(Point[] P)` Disegna un poligono.
- ❎ `DrawFillPolygon(Point[] P)` Disegna un poligono pieno.
- ✅ `DrawPie(int X, int Y, int W, int H, int A, int B)` Disegna una torta.
- ✅ `DrawFillPie(int X, int Y, int W, int H, int A, int B)` Disegna una torta piena.

### Varie

- ✅ `Default()` Imposta le proprietà della finestra al loro valore predefinito.
- ✅ `GetMaxScreenX()` Ottiene la massima ascissa dello schermo.
- ✅ `GetMaxScreenY()` Ottiene la massima ordinata dello schermo.
- ✅ `GetMaxWindowX()` Ottiene la massima ascissa della finestra.
- ✅ `GetMaxWindowY()` Ottiene la massima ordimata della finestra.



## Proprietà

> ⚠ Non tutti i metodi elencati qui sotto sono presenti nella classe `NGWC` e quindi utilizzabili in applicazioni console C++ native per Windows. I metodi compatibili con applicazioni console C++ native Windows per sono indicati con il simbolo '✅' mentre quelli non compatibili con il simbolo '❎'. La disponibilità verrà estesa in futuro.

> ⚠ In C++ non esisteno le proprietà per questo motivo all'interno di `NGWC` è necessario chiamare le funzioni `Get<Nome proprietà>` per ottenere il valore della proprietà e `Set<Nome Proprietà>` per impostare il valore della proprietà.

**Esempio**

```cpp
// C++/CLI
System::String^ Title = Form->WindowTitle;
Form->WindowTitle = "New Title";

// C++
std::string Title = Form->GetWindowTitle();
Form->SetWindowTitle("New Title");
```



### Finestra

- ❎ `WindowTitle` Ottiene o imposta il titolo della finestra.
- ❎ `WindowIcon` Ottiene o imposta l'icona della finestra.
- ✅ `WindowIconVisible` Ottiene o imposta la visibilità dell'icona della finestra.
- ✅ `WindowLocation` Ottiene o imposta la località della finestra.
- ✅ `WindowColor` Ottiene o imposta il colore di sfondo della finestra.
- ❎ `WindowImage` Ottiene o imposta l'immagine di sfondo della finestra.
- ✅ `WindowSize` Ottiene o imposta le dimensioni della finestra.
- ✅ `WindowMinimumSize` Ottiene o imposta le dimensioni minime della finestra.
- ✅ `WindowMaximumSize` Ottiene o imposta le dimensioni massime della finestra.
- ✅ `WindowOpacity` Ottiene o imposta l'opacità della finestra.
- ✅ `WindowAlwaysOnTop` Ottiene o imposta se la fienstra deve rimanere sempre in primo piano.
- ✅ `WindowInTaskbar` Ottiene o imposta la visibilità della finestra nella barra delle applicazioni.
- ✅ `WindowMinimizeButton` Ottiene o imposta lo stato del pulsante di minimizzazione.
- ✅ `WindowMaximizeButton` Ottiene o imposta lo stato del pulsante di maximizzazione. 

### Disegno

- ✅ `PenColor` Ottiene o imposta il colore della penna.
- ✅ `PenWidth` Ottiene o imposta lo spessore della penna.
- ✅ `FillColor` Ottiene o imposta il colore di riempimento.
- ❎ `FontName` Ottiene o imposta il nome del font.
- ✅ `FontSize` Ottiene o imposta la dimensione del font.



## Strutture

> ⚠ Queste strutture sono non gestite.

- `POINTN` Rappresenta un punto intero.
- `SIZEN` Rappresenta una dimensione bidimensionale.
- `COLORN` Rappresenta un colore in formato RGB.



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
