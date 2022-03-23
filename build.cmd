@echo off

@title Script di compilazione di GWC++
echo Script di compilazione di GWC++

@echo,
echo   * Compila GWC++ x64 (x64)
echo   * Compila GWC++ x86 (x86)
echo   * Esci (Quit)
@echo,

:loop

    set /p op="##$: "

    if %op%==x64 (
        if exist "C:\Program Files\Microsoft Visual Studio\2022\Community\Msbuild\Current\Bin" (
            cd "C:\Program Files\Microsoft Visual Studio\2022\Community\Msbuild\Current\Bin"
            msbuild %~dp0/gwc++.sln -nologo -v:q -p:warninglevel=0 -p:configuration=Debug -p:platform=x64
            msbuild %~dp0/gwc++.sln -nologo -v:q -p:warninglevel=0 -p:configuration=Release -p:platform=x64
            msbuild %~dp0/gwc++.sln -nologo -v:q -p:warninglevel=0 -p:configuration=Cil -p:platform=x64
            echo Compilazione completata!
        ) else (
            echo MSBuild non è stato trovate oppure è installato in un percorso diverso!
        )
    )

    if %op%==x86 (
        if exist "C:\Program Files\Microsoft Visual Studio\2022\Community\Msbuild\Current\Bin" (
            cd "C:\Program Files\Microsoft Visual Studio\2022\Community\Msbuild\Current\Bin"
            msbuild %~dp0/gwc++.sln -nologo -v:q -p:warninglevel=0 -p:configuration=Debug -p:platform=x86
            msbuild %~dp0/gwc++.sln -nologo -v:q -p:warninglevel=0 -p:configuration=Release -p:platform=x86
            msbuild %~dp0/gwc++.sln -nologo -v:q -p:warninglevel=0 -p:configuration=Cil -p:platform=x86
            echo Compilazione completata!
        ) else (
            echo MSBuild non è stato trovate oppure è installato in un percorso diverso!
        )
    )

    if %op%==Quit (
        goto quit
    )

goto loop

:quit
