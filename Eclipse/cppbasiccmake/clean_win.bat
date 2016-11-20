echo root=%~dp0
set root=%~dp0

if exist "%root%build\debug" (
  del /F /S /Q "%root%build\debug\*.*"
  for /d %%x in (%root%build\debug\*) do @rd /s /q "%%x"
)

if exist "%root%build\release" (
  del /F /S /Q "%root%build\release\*.*"
  for /d %%x in (%root%build\release\*) do @rd /s /q "%%x"
)