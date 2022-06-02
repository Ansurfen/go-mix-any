@echo off

set py3dll = python3.dll
set py310dll = python310.dll
set target = callc.dll

gcc -fdiagnostics-color=always -g %target% -L D:\python10\libs\* -fPIC -shared -o %target%

if exist %py3dll% (
    if not exist %py310dll% echo "Fail to find python310.dll"
) else (
    echo "Fail to find python3.dll" 
)

