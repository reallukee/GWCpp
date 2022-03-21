# Documentazione

> ⚠ Il contenuto di questa pagina offre solo una visione di insieme dei metodi, delle proprietà, delle strutture e delle enumerazioni di GWC++.

Alcuni dei metodi, delle proprietà sono presenti solo all'interno della classe `MGWC`, all'interno della classe `UGWC` oppure all'interno di entrambe. La lista sottostante fornisce degli indicatori visivi per vedere la disponibilità per classe.

- 🟢 Solo in `MGWC`
- 🟣 Solo in `UGWC`
- 🔵 In entrambe  



# Indice

- [Metodi](#metodi)
    - [Conversione](#conversione)
    - [Interazione](#interazione)
    - [Finestra](#finestra)
    - [Disegno](#disegno)
- [Proprietà](#proprietà)
    - [Finestra](#finestra-1)
    - [Disegno](#disegno-1)
- [Strutture](#strutture)
    - [Gestite](#gestite)
    - [Non gestite](#non-gestite)
- [Enumerazioni](#enumerazioni)
    - [Gestite](#gestite-1)
    - [Non gestite](#non-gestite-1)



## Metodi

### Conversione

- 🟢 `PointToMGPoint`
- 🟢 `MGPointToPoint`
- 🟢 `ColorToMGColor`
- 🟢 `MGColorToColor`
- 🟢 `SizeToMGSize`
- 🟢 `MGSizeToSize`
- 🟣 `UStringToMString`
- 🟣 `MStringToUString`
- 🟣 `UGPointToMGPoint`
- 🟣 `MGPointToUGPoint`
- 🟣 `UGColorToMGColor`
- 🟣 `MGColorToUGColor`
- 🟣 `UGSizeToMGSize`
- 🟣 `MGSizeToUGSize`

### Interazione

- 🔵 `InputBox`
- 🔵 `OutputBox`

### Finestra

- 🔵 `StartWindow`
- 🔵 `CloseWindow`
- 🔵 `SuspendWindow`
- 🔵 `ResumeWindow`
- 🔵 `PauseWindow`
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
- 🟢 `DefaultWindowIcon`
- 🔵 `DefaultWindowLocation`
- 🔵 `DefaultWindowX`
- 🔵 `DefaultWindowY`
- 🔵 `DefaultWindowColor`
- 🟢 `DefaultWindowImage`
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
- 🔵 `SaveCanvas`
- 🔵 `RestoreCanvas`
- 🔵 `DrawPixel`
- 🔵 `DrawLine`
- 🔵 `DrawArc`
- 🔵 `DrawBezier`
- 🔵 `DrawString`
- 🟢 `DrawImage`
- 🔵 `DrawImageFromFile`
- 🟢 `DrawIcon`
- 🔵 `DrawIconFromFile`
- 🔵 `DrawSquare`
- 🔵 `DrawFullSquare`
- 🔵 `DrawRectangle`
- 🔵 `DrawFullRectangle`
- 🔵 `DrawEllipse`
- 🔵 `DrawFullEllipse`
- 🔵 `DrawCircle`
- 🔵 `DrawFullCircle`
- 🟢 `DrawCurve`
- 🟢 `DrawClosedCurve`
- 🟢 `DrawPolygon`
- 🟢 `DrawFullPolygon`
- 🔵 `DrawPie`
- 🔵 `DrawFullPie`
- 🔵 `DefaultPenColor`
- 🔵 `DefaultPenWidth`
- 🔵 `DefaultFillColor`
- 🔵 `DefaultFontName`
- 🔵 `DefaultFontSize`



## Proprietà

> ⚠ In C++ non esisteno le proprietà per questo motivo all'interno di `UGWC` è necessario chiamare le funzioni `Get<Nome proprietà>` per ottenere il valore della proprietà e `Set<Nome Proprietà>` per impostare il valore della proprietà.

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
- 🔵 `MouseLocation`
- 🔵 `MouseX`
- 🔵 `MouseY`
- 🔵 `WindowTitle`
- 🔵 `WindowIconVisible`
- 🟢 `WindowIcon`
- 🔵 `WindowLocation`
- 🔵 `WindowX`
- 🔵 `WindowY`
- 🔵 `WindowColor`
- 🟢 `WindowImage`
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
- 🔵 `FontName`
- 🔵 `FontSize`



## Strutture

### Gestite

- `MGPoint`
- `MGSize`
- `MGColor`

### Non gestite

- `UGPoint`
- `UGSize`
- `UGColor`



## Enumerazioni

### Gestite

- `MGMouseButtons`
- `MGWindowState`
- `MGOutputBoxStyle`
- `MGOutputBoxResult`

### Non gestite

- `UGMouseButtons`
- `UGWindowState`
- `UGOutputBoxStyle`
- `UGOutputBoxResult`
