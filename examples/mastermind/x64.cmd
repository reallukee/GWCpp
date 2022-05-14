cd %~dp0

if not exist "..\x64\Release\std-gwc++.dll" (
    copy "..\..\x64\Release\std-gwc++.dll" "..\x64\Release\std-gwc++.dll"
)

if not exist "..\x64\Debug\std-gwc++.dll" (
    copy "..\..\x64\Release\std-gwc++.dll" "..\x64\Debug\std-gwc++.dll"
)

exit
