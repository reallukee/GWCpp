# GWC++
![Alt TExt](./assets/banner.png "GWC++")

GWC++ è una libreria scritta in C++/CLI che mette a disposizione dei Form personalizzati da utilizzare come tela da dipinto per applicazioni Console .NET. GWC++ è utilizza [.NET Framework 4.8]().

> ⚠ GWC++ è **SOLO** un esperimento, ne sconsiglio quindi l'utilizzo.



# Indice
- [Esempi]() 🧭
- [Documentazione]() 📚
- [Licenza]() 📃



## Esempi 🧭

### C#
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

### VB .NET
```vb
' main.vb

' Importo lo spazio dei nomi.
Import GWCpp;

' Codice ...

' Istanza di GWC.
Dim Form As New GWC(850, 505, "GWC++ Test", 50, 50)

// Creo la finestra.
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

### C++/CLI
```cpp
// main.cpp

// Importo lo spazio dei nomi.
using namespace GWCpp;

// Codice ...

// Istanza di GWC.
GWCpp::GWC^ Form = gcnew GWCpp::GWC(850, 505, "GWC++ Test", 50, 50);

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

...
```



# Documentazione 📚

## Funzioni
### Finestra
- `StartWindow` Crea la finestra.
- `CloseWindow` Chiude la finastra.
- `ShowWindow` Mostra la finestra.
- `HideWindow` Nasconde la finestra.
- `RequestMouseDown` Richiede la pressione del mouse.
- `RequestMouseUp` Richiede il rilascio del mouse.
- `RequestKeyDown` Richiede la pressione di un tasto.
- `RequestKeyUp` Richiede il rilascio di un tasto.

### Disegno
- `DefaultPenColor` Imposta il colore della penna al suo valore di base.
- `DefaultPenWidth` Imposta la dimensione della penna al suo valore di base.
- `DefaultFillColor` Imposta il colore di riempimento al suo valore di base.
- `DefaultFontName` Imposta il nome del font al suo valore di base.
- `DefaultFontSize` Imposta la dimensione del font al suo valore di base.
- `ClearWindow` Rimuove tutti i disegni.
- `DrawLine` Esegue la scrittura di una linea.
- `DrawArc` Esegue la scrittura di un arco.
- `DrawText` Esegue la scrittura di un testo.
- `DrawImage` Esegue la scrittura di un'immagine.
- `DrawIcon` Esegue la scruttura di un'icona.
- `DrawRectangle` Esegue la scruttura di un rettangolo.
- `DrawFillRectangle` Esegue la scruttura di un rettangolo pieno.
- `DrawEllipse` Esegue la scruttura di un ellisse.
- `DrawFillEllipse` Esegue la scruttura di un ellisse pieno.
- `DrawCircle` Esegue la scruttura di un cerchio.
- `DrawFillCircle` Esegue la scruttura di un cerchio pieno.
- `DrawPolygon` Esegue la scruttura di un poligono.
- `DrawFillPolygon` Esegue la scruttura di un poligono pieno.
- `DrawPie` Esegue la scruttura di una torta.
- `DrawFillPie` Esegue la scruttura di una torta piena.

### Varie
- `GetMaxScreenX` Ottiene la massima ascissa dello schermo.
- `GetMaxScreenY` Ottiene la massima ordinata dello schermo.
- `GetMaxWindowX` Ottiene la massima ascissa della finestra.
- `GetMaxWindowY` Ottiene la massima ordimata della finestra.

## Proprietà
### Finestra
- `WindowTitle` Ottiene o imposta il titolo della finestra.
- `WindowIcon` Ottiene o imposta l'icona della finestra.
- `WindowLocation` Ottiene o imposta la località della finestra.
- `WindowColor` Ottiene o imposta il colore di sfondo della finestra.
- `WindowSize` Ottiene o imposta le dimensioni della finestra.
- `WindowMinimumSize` Ottiene o imposta le dimensioni minime della finestra.
- `WindowMaximumSize` Ottiene o imposta le dimensioni massime della finestra.

### Disegno
- `PenColor` Ottiene o imposta il colore della penna.
- `PenWidth` Ottiene o imposta lo spessore della penna.
- `FillColor` Ottiene o imposta il colore di riempimento.
- `FontName` Ottiene o imposta il nome del font.
- `FontSize` Ottiene o imposta la dimensione del



# Licenza 📃
[MIT]()
