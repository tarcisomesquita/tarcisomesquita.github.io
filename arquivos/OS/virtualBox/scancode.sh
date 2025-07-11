#!/bin/bash

# ./scancode.sh "$(cat FILE.txt)"

# sudo showkey -s

CMD="VBoxManage controlvm \"W7\" keyboardputscancode "
for i in $(seq 0 1 $((${#1} - 1))) ; do
  LETRA="${1:$i:1}"
    if [ "$LETRA" == 'a' ] ; then
       CMD="$CMD 1e 9e"
  elif [ "$LETRA" == 'b' ] ; then
       CMD="$CMD 30 b0"
  elif [ "$LETRA" == 'c' ] ; then
       CMD="$CMD 2e ae"
  elif [ "$LETRA" == 'd' ] ; then
       CMD="$CMD 20 a0"
  elif [ "$LETRA" == 'e' ] ; then
       CMD="$CMD 12 92"
  elif [ "$LETRA" == 'f' ] ; then
       CMD="$CMD 21 a1"
  elif [ "$LETRA" == 'g' ] ; then
       CMD="$CMD 22 a2"
  elif [ "$LETRA" == 'h' ] ; then
       CMD="$CMD 23 a3"
  elif [ "$LETRA" == 'i' ] ; then
       CMD="$CMD 17 97"
  elif [ "$LETRA" == 'j' ] ; then
       CMD="$CMD 24 a4"
  elif [ "$LETRA" == 'k' ] ; then
       CMD="$CMD 25 a5"
  elif [ "$LETRA" == 'l' ] ; then
       CMD="$CMD 26 a6"
  elif [ "$LETRA" == 'm' ] ; then
       CMD="$CMD 32 b2"
  elif [ "$LETRA" == 'n' ] ; then
       CMD="$CMD 31 b1"
  elif [ "$LETRA" == 'o' ] ; then
       CMD="$CMD 18 98"
  elif [ "$LETRA" == 'p' ] ; then
       CMD="$CMD 19 99"
  elif [ "$LETRA" == 'q' ] ; then
       CMD="$CMD 10 90"
  elif [ "$LETRA" == 'r' ] ; then
       CMD="$CMD 13 93"
  elif [ "$LETRA" == 's' ] ; then
       CMD="$CMD 1f 9f"
  elif [ "$LETRA" == 't' ] ; then
       CMD="$CMD 14 94"
  elif [ "$LETRA" == 'u' ] ; then
       CMD="$CMD 16 96"
  elif [ "$LETRA" == 'v' ] ; then
       CMD="$CMD 2f af"
  elif [ "$LETRA" == 'w' ] ; then
       CMD="$CMD 11 91"
  elif [ "$LETRA" == 'x' ] ; then
       CMD="$CMD 2d ad"
  elif [ "$LETRA" == 'y' ] ; then
       CMD="$CMD 15 95"
  elif [ "$LETRA" == 'z' ] ; then
       CMD="$CMD 2c ac"
  elif [ "$LETRA" == '0' ] ; then
       CMD="$CMD 0b 8b"
  elif [ "$LETRA" == '1' ] ; then
       CMD="$CMD 02 82"
  elif [ "$LETRA" == '2' ] ; then
       CMD="$CMD 03 83"
  elif [ "$LETRA" == '3' ] ; then
       CMD="$CMD 04 84"
  elif [ "$LETRA" == '4' ] ; then
       CMD="$CMD 05 85"
  elif [ "$LETRA" == '5' ] ; then
       CMD="$CMD 06 86"
  elif [ "$LETRA" == '6' ] ; then
       CMD="$CMD 07 87"
  elif [ "$LETRA" == '7' ] ; then
       CMD="$CMD 08 88"
  elif [ "$LETRA" == '8' ] ; then
       CMD="$CMD 09 89"
  elif [ "$LETRA" == '9' ] ; then
       CMD="$CMD 0a 8a"
  elif [ "$LETRA" == ' ' ] ; then
       CMD="$CMD 39 b9"
  elif [ "$LETRA" == '-' ] ; then
       CMD="$CMD 0c 8c"
  elif [ "$LETRA" == '=' ] ; then
       CMD="$CMD 0d 8d"
  elif [ "$LETRA" == '[' ] ; then
       CMD="$CMD 1b 9b"
  elif [ "$LETRA" == ']' ] ; then
       CMD="$CMD 2b ab"
  elif [ "$LETRA" == ';' ] ; then
       CMD="$CMD 35 b5"
  elif [ "$LETRA" == ',' ] ; then
       CMD="$CMD 33 b3"
  elif [ "$LETRA" == '.' ] ; then
       CMD="$CMD 34 b4"
  elif [ "$LETRA" == '/' ] ; then
       CMD="$CMD 73 f3"
  elif [ "$LETRA" == "'" ] ; then
       CMD="$CMD 29 a9"
  elif [ "$LETRA" == 'A' ] ; then
       CMD="$CMD 2a 1e 9e aa"
  elif [ "$LETRA" == 'B' ] ; then
       CMD="$CMD 2a 30 b0 aa"
  elif [ "$LETRA" == 'C' ] ; then
       CMD="$CMD 2a 2e ae aa"
  elif [ "$LETRA" == 'D' ] ; then
       CMD="$CMD 2a 20 a0 aa"
  elif [ "$LETRA" == 'E' ] ; then
       CMD="$CMD 2a 12 92 aa"
  elif [ "$LETRA" == 'F' ] ; then
       CMD="$CMD 2a 21 a1 aa"
  elif [ "$LETRA" == 'G' ] ; then
       CMD="$CMD 2a 22 a2 aa"
  elif [ "$LETRA" == 'H' ] ; then
       CMD="$CMD 2a 23 a3 aa"
  elif [ "$LETRA" == 'I' ] ; then
       CMD="$CMD 2a 17 97 aa"
  elif [ "$LETRA" == 'J' ] ; then
       CMD="$CMD 2a 24 a4 aa"
  elif [ "$LETRA" == 'K' ] ; then
       CMD="$CMD 2a 25 a5 aa"
  elif [ "$LETRA" == 'L' ] ; then
       CMD="$CMD 2a 26 a6 aa"
  elif [ "$LETRA" == 'M' ] ; then
       CMD="$CMD 2a 32 b2 aa"
  elif [ "$LETRA" == 'N' ] ; then
       CMD="$CMD 2a 31 b1 aa"
  elif [ "$LETRA" == 'O' ] ; then
       CMD="$CMD 2a 18 98 aa"
  elif [ "$LETRA" == 'P' ] ; then
       CMD="$CMD 2a 19 99 aa"
  elif [ "$LETRA" == 'Q' ] ; then
       CMD="$CMD 2a 10 90 aa"
  elif [ "$LETRA" == 'R' ] ; then
       CMD="$CMD 2a 13 93 aa"
  elif [ "$LETRA" == 'S' ] ; then
       CMD="$CMD 2a 1f 9f aa"
  elif [ "$LETRA" == 'T' ] ; then
       CMD="$CMD 2a 14 94 aa"
  elif [ "$LETRA" == 'U' ] ; then
       CMD="$CMD 2a 16 96 aa"
  elif [ "$LETRA" == 'V' ] ; then
       CMD="$CMD 2a 2f af aa"
  elif [ "$LETRA" == 'W' ] ; then
       CMD="$CMD 2a 11 91 aa"
  elif [ "$LETRA" == 'X' ] ; then
       CMD="$CMD 2a 2d ad aa"
  elif [ "$LETRA" == 'Y' ] ; then
       CMD="$CMD 2a 15 95 aa"
  elif [ "$LETRA" == 'Z' ] ; then
       CMD="$CMD 2a 2c ac aa"
  elif [ "$LETRA" == '"' ] ; then
       CMD="$CMD 2a 29 a9 aa"
  elif [ "$LETRA" == '$' ] ; then
       CMD="$CMD 2a 05 85 aa"
  elif [ "$LETRA" == '(' ] ; then
       CMD="$CMD 2a 0a 8a aa"
  elif [ "$LETRA" == ')' ] ; then
       CMD="$CMD 2a 0b 8b aa"
  elif [ "$LETRA" == '!' ] ; then
       CMD="$CMD 2a 02 82 aa"
  elif [ "$LETRA" == '@' ] ; then
       CMD="$CMD 2a 03 83 aa"
  elif [ "$LETRA" == '#' ] ; then
       CMD="$CMD 2a 04 84 aa"
  elif [ "$LETRA" == '$' ] ; then
       CMD="$CMD 2a 05 85 aa"
  elif [ "$LETRA" == '%' ] ; then
       CMD="$CMD 2a 06 86 aa"
  elif [ "$LETRA" == '*' ] ; then
       CMD="$CMD 2a 09 89 aa"
  elif [ "$LETRA" == '(' ] ; then
       CMD="$CMD 2a 0a 8a aa"
  elif [ "$LETRA" == ')' ] ; then
       CMD="$CMD 2a 0b 8b aa"
  elif [ "$LETRA" == '+' ] ; then
       CMD="$CMD 2a 0d 8d aa"
  elif [ "$LETRA" == '_' ] ; then
       CMD="$CMD 2a 0c 8c aa"
  elif [ "$LETRA" == '<' ] ; then
       CMD="$CMD 2a 33 b3 aa"
  elif [ "$LETRA" == '>' ] ; then
       CMD="$CMD 2a 34 b4 aa"
  elif [ "$LETRA" == ':' ] ; then
       CMD="$CMD 2a 35 b5 aa"
  elif [ "$LETRA" == '?' ] ; then
       CMD="$CMD 2a 73 f3 aa"
  elif [ "$LETRA" == '{' ] ; then
       CMD="$CMD 2a 1b 9b aa"
  elif [ "$LETRA" == '}' ] ; then
       CMD="$CMD 2a 2b ab aa"
  elif [ "$LETRA" == '|' ] ; then
       CMD="$CMD 2a 56 d6 aa"
  else
     # falta á ã â ç
     echo "A letra não está codificada:" $(echo -n "$LETRA" | xxd | cut -c11-)
  fi
done

CMD="$CMD 1c 9c"
eval "$CMD" 

exit 0

