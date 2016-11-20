:: %1 : build mode.

echo root=%~dp0
set root=%~dp0

if not exist "%root%build" (
  mkdir "%root%build"
)

if not exist "%root%build\release" (
  mkdir "%root%build\release"
)

if not exist "%root%build\debug" (
  mkdir "%root%build\debug"
)


if "%1"=="release" (goto _BR)
if "%1"=="debug" (goto _BD) else (goto _BD)

:_BR
  echo Build for release
  goto END
  
:_BD
  echo Build for debug
  cd "%root%build\debug"
  cmake -G "MinGW Makefiles" -DCMAKE_BUILD_TYPE=Debug "%root%"
  make -j2
  goto END

:END