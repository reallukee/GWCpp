# Documentazione

# Indice

- [Concetti teorici](#concetti-teorici)
- [Funzionalità](#funzionalità)



# Concetti teorici

## STD (Standard) e CIL (Common Intermediate Language)

GWC++ è disponibile in edizione `STD` (Standard) e edizione `CIL` (Common Intermediate Language). La prima è compilata con l'opzione `/clr` ed è utilizzabile in applicazioni console .NET e C++ mentre la seconda è compilata con l'opzione `/clr:pure` ed è utilizzabile solo in applicazioni console .NET.

> ⚠ Entrambe le versioni di GWC++ richiedono Windows 7 o superiori e [.NET Framework 4.8 Runtime](https://dotnet.microsoft.com/en-us/download/dotnet-framework/net48) e [Pacchetto di ridistribuzione MVC++ 2015-2022](https://docs.microsoft.com/it-IT/cpp/windows/latest-supported-vc-redist?view=msvc-170#visual-studio-2015-2017-2019-and-2022). Solitamente sono installati ma potrebbe essere necessaria un'installazione manuale.



## MGWC (Managed GWC) e UGWC (Unmanaged GWC)

GWC++ offre la classe `MGWC` (Managed GWC) per le applicazioni console .NET e `UGWC` (Unmanaged GWC) per le applicazioni console C++ compilate con MSVC. Utilizzare la classe adatta al tipo di linguaggio e applicazione che si sta sviluppando. Nel caso di C++/CLI è possibile utilizzare entrambe le classi indistintamente.

> ⚠ Se si vuole utilizzare la classe `UGWC` è necessario utilizzare la edizione `STD` di GWC++ e aggiungere il file [hgwc++.h](./gwc++/hgwc++.h) all'interno del proprio progetto. Inserire `#include "hgwc++.h"` all'interno dei file di codice sorgente dove è necessario `UGWC`.



## WP (With Paint) e WoP (Without Paint)

GWC++ offre due metodologie di disegno. Il metodo `WP` (With Paint) utilizza l'evento `Paint` mentre il metodo `WoP` (Without Paint) non utilizza nessuno evento. La prima metodologia è la migliore in quanto assicura che gli oggetti grafici disegnati rimangano dopo un ridisegno della finestra mentre la seconda metodologia non da questa opportunità. È quindi possibile vedere i metodi WoP come temporanei mentre i metodi WP come permanenti.



# Funzionalità

> ## 🎉 MGWC e UGWC presentano ora le stesse funzionalità!

> ⚠ Il contenuto di questa pagina offre solo una visione di insieme dei metodi, delle proprietà, delle strutture e delle enumerazioni di GWC++.

Alcuni dei metodi e delle proprietà sono presenti solo all'interno della classe `MGWC`, all'interno della classe `UGWC` oppure all'interno di entrambe. La lista sottostante fornisce degli indicatori visivi per vedere la disponibilità per classe.

- 🟢 Solo in `MGWC`
- 🟣 Solo in `UGWC`
- 🔵 In entrambe

## Metodi

### Conversione

- 🟢 `PointToMPoint`
- 🟢 `MPointToPoint`
- 🟢 `ColorToMColor`
- 🟢 `MColorToColor`
- 🟢 `SizeToMSize`
- 🟢 `MSizeToSize`
- 🟣 `UStringToMString`
- 🟣 `MStringToUString`
- 🟣 `UPointToMPoint`
- 🟣 `MPointToUPoint`
- 🟣 `UColorToMColor`
- 🟣 `MColorToUColor`
- 🟣 `USizeToMSize`
- 🟣 `MSizeToUSize`

### Interazione

- 🔵 `InputBox`
- 🔵 `OutputBox`

### Finestra

- 🔵 `StartWindow`
- 🔵 `CloseWindow`
- 🔵 `SuspendWindow`
- 🔵 `ResumeWindow`
- 🔵 `PauseWindow`
- 🔵 `RedrawWindow`
- 🔵 `ShowWindow`
- 🔵 `HideWindow`
- 🔵 `GetWindowMaxX`
- 🔵 `GetWindowRealMaxX`
- 🔵 `GetWindowMaxY`
- 🔵 `GetWindowRealMaxY`
- 🔵 `GetScreenMaxX`
- 🔵 `GetScreenRealMaxX`
- 🔵 `GetScreenMaxY`
- 🔵 `GetScreenRealMaxY`
- 🔵 `CreateCanvasState`
- 🔵 `DeleteCanvasState`
- 🔵 `SaveCanvasState`
- 🔵 `LoadCanvasState`
- 🔵 `RequestMouseDown`
- 🔵 `RequestMouseUp`
- 🔵 `RequestKeyDown`
- 🔵 `RequestKeyUp`
- 🔵 `DefaultWindowTitle`
- 🔵 `DefaultWindowIconVisible`
- 🔵 `DefaultWindowIcon`
- 🔵 `DefaultWindowLocation`
- 🔵 `DefaultWindowX`
- 🔵 `DefaultWindowY`
- 🔵 `DefaultWindowColor`
- 🔵 `DefaultWindowImage`
- 🔵 `DefaultWindowSize`
- 🔵 `DefaultWindowWidth`
- 🔵 `DefaultWindowHeight`
- 🔵 `DefaultWindowRealSize`
- 🔵 `DefaultWindowRealWidth`
- 🔵 `DefaultWindowRealHeight`
- 🔵 `DefaultWindowSizeState`
- 🔵 `DefaultWindowMinimumSize`
- 🔵 `DefaultWindowMaximumSize`
- 🔵 `DefaultWindowOpacity`
- 🔵 `DefaultWindowAlwaysOnTop`
- 🔵 `DefaultWindowInTaskbar`
- 🔵 `DefaultWindowButtons`
- 🔵 `DefaultWindowMinimizeButton`
- 🔵 `DefaultWindowMaximizeButton`

### Disegno

- 🔵 `ClearWindow`
- 🔵 `ClearWindowWoP`
- 🔵 `SaveCanvas`
- 🔵 `SaveCanvasWoP`
- 🔵 `RestoreCanvas`
- 🔵 `RestoreCanvasWoP`
- 🔵 `DrawPixel`
- 🔵 `DrawPixelWoP`
- 🔵 `DrawLine`
- 🔵 `DrawLineWoP`
- 🔵 `DrawArc`
- 🔵 `DrawArcWoP`
- 🔵 `DrawBezier`
- 🔵 `DrawBezierWoP`
- 🔵 `DrawString`
- 🔵 `DrawStringWoP`
- 🔵 `DrawImage`
- 🔵 `DrawImageWoP`
- 🔵 `DrawIcon`
- 🔵 `DrawIconWoP`
- 🔵 `DrawSquare`
- 🔵 `DrawSquareWoP`
- 🔵 `DrawFullSquare`
- 🔵 `DrawFullSquareWoP`
- 🔵 `DrawRectangle`
- 🔵 `DrawRectangleWoP`
- 🔵 `DrawFullRectangle`
- 🔵 `DrawFullRectangleWoP`
- 🔵 `DrawEllipse`
- 🔵 `DrawEllipseWoP`
- 🔵 `DrawFullEllipse`
- 🔵 `DrawFullEllipseWoP`
- 🔵 `DrawCircle`
- 🔵 `DrawCircleWoP`
- 🔵 `DrawFullCircle`
- 🔵 `DrawFullCircleWoP`
- 🔵 `DefaultPenColor`
- 🔵 `DefaultPenWidth`
- 🔵 `DefaultFillColor`
- 🔵 `DefaultHStringAlignment`
- 🔵 `DefaultVStringAlignment`
- 🔵 `DefaultFontName`
- 🔵 `DefaultFontSize`



## Proprietà

> ⚠ In C++ non esistono le proprietà per questo motivo all'interno di `UGWC` è necessario chiamare le funzioni `Get<Nome proprietà>` per ottenere il valore della proprietà e `Set<Nome Proprietà>` per impostare il valore della proprietà.

```cpp
// C++/CLI
System::String^ Title = Window->WindowTitle;
Window->WindowTitle = "New Title";

// C++
std::string Window = Window->GetWindowTitle();
Window->SetWindowTitle("New Title");
```

### Finestra

- 🔵 `WindowStarted`
- 🔵 `WindowClosed`
- 🔵 `WindowSuspended`
- 🔵 `WindowVisible`
- 🔵 `MouseLocation`
- 🔵 `MouseX`
- 🔵 `MouseY`
- 🔵 `WindowTitle`
- 🔵 `WindowIconVisible`
- 🔵 `WindowIcon`
- 🔵 `WindowLocation`
- 🔵 `WindowX`
- 🔵 `WindowY`
- 🔵 `WindowColor`
- 🔵 `WindowImage`
- 🔵 `WindowSize`
- 🔵 `WindowWidth`
- 🔵 `WindowHeight`
- 🔵 `WindowRealSize`
- 🔵 `WindowRealWidth`
- 🔵 `WindowRealHeight`
- 🔵 `WindowSizeState`
- 🔵 `WindowMinimumSize`
- 🔵 `WindowMaximumSize`
- 🔵 `WindowOpacity`
- 🔵 `WindowAlwaysOnTop`
- 🔵 `WindowInTaskbar`
- 🔵 `WindowButtons`
- 🔵 `WindowMinimizeButton`
- 🔵 `WindowMaximizeButton`

### Disegno

- 🔵 `PenColor`
- 🔵 `PenWidth`
- 🔵 `FillColor`
- 🔵 `HStringAlignment`
- 🔵 `VStringAlignment`
- 🔵 `FontName`
- 🔵 `FontSize`



## Strutture

### Gestite

- `MPoint`
- `MSize`
- `MColor`

### Non gestite

- `UPoint`
- `USize`
- `UColor`



## Enumerazioni

### Gestite

- `MMouseButtons`
- `MWindowState`
- `MOutputBoxStyle`
- `MOutputBoxResult`
- `MStringAlignment`

### Non gestite

- `UMouseButtons`
- `UWindowState`
- `UOutputBoxStyle`
- `UOutputBoxResult`
- `UStringAlignment`
