cd %~dp0

if not exist "..\x86\Release\std-gwc++x86.dll" (
    copy "std-gwc++.dll" "..\x86\Release\std-gwc++x86.dll"
)

if not exist "..\x86\Debug\std-gwc++x86.dll" (
    copy "std-gwc++.dll" "..\x86\Debug\std-gwc++x86.dll"
)

exit
