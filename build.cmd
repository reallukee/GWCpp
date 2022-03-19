@echo off

@title Script di compilazione di GWC++
echo Script di compilazione di GWC++

@echo,
echo   * Compila GWC++ x64 (x64)
echo   * Compila GWC++ x86 (x86)
echo   * Compila CSTest (CSTest)
echo   * Compila VBTest (VBTest)
echo   * Esci (Quit)
@echo,


:loop

    set /p op="##$: "

    if %op%==x64 (
        if exist "C:\Program Files\Microsoft Visual Studio\2022\Community\Msbuild\Current\Bin" (
            cd "C:\Program Files\Microsoft Visual Studio\2022\Community\Msbuild\Current\Bin"
            msbuild %~dp0/gwc++/gwc++.vcxproj /p:configuration=debug /p:platform=x64
            msbuild %~dp0/gwc++/gwc++.vcxproj /p:configuration=release /p:platform=x64
        ) else (
            echo MSBuild non è stato trovate oppure è installato in un percorso diverso!
        )
    )

    if %op%==x86 (
        if exist "C:\Program Files\Microsoft Visual Studio\2022\Community\Msbuild\Current\Bin" (
            cd "C:\Program Files\Microsoft Visual Studio\2022\Community\Msbuild\Current\Bin"
            msbuild %~dp0/gwc++/gwc++.vcxproj /p:configuration=debug /p:platform=x86
            msbuild %~dp0/gwc++/gwc++.vcxproj /p:configuration=release /p:platform=x86
        ) else (
            echo MSBuild non è stato trovate oppure è installato in un percorso diverso!
        )
    )

    if %op%==CSTest (
        cd %~dp0
        dotnet build -c release .\cstest\cstest.csproj
        dotnet build -c debug .\cstest\cstest.csproj
    )

    if %op%==VBTest (
        cd %~dp0
        dotnet build -c release .\VBtest\VBtest.vbproj
        dotnet build -c debug .\VBtest\VBtest.vbproj
    )

    if %op%==Quit (
        goto quit
    )

goto loop

:quit
