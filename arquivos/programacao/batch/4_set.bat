@echo off

set teste=testando
echo %teste%

echo digite algo
set /p entrada=

echo você digitou: %entrada%


set /p entrada=<1_cmd.txt


echo A primeira linha do arquivo 1_cmd.txt: %entrada%


set v1=3
set v2=2
set /a v3 = %v1% / %v2%
echo %v3%

pause > nul
