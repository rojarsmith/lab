@echo off
set APPLICATION_ROOT=%1
cmd /C "set PATH=%TOUCHGFX_HOME%\env\MinGW\msys\1.0\Ruby193\bin;%TOUCHGFX_HOME%\env\MinGW\msys\1.0\bin;%TOUCHGFX_HOME%\env\MinGW\bin;%PATH% & %TOUCHGFX_HOME%\env\MinGW\msys\1.0\bin\make.exe -f %APPLICATION_ROOT%/simulator/gcc/Makefile assets"
exit /b 0
