@echo off

set var=teste

if %var%==tudo (
   echo todos
) else (
   echo var eh %var%
   echo fim
)


set v1=1
set v2=2
if /i %v1% LSS %v2% echo %v1% is less than %v2%

pause > nul
