#!/usr/bin/bash

if [ "$#" -ne 1 ]; then
  echo "Uso: baixar.sh <URL>"
  exit 1
fi

NAME=${1#https://developer.mozilla.org/en-US/docs/}; # remove início da string
echo "Salvando em old/${NAME//\//%}.html";           # ${NAME//\//%} substitui todos os / por %

wget -q -O - "$1" | \
sed 's/\(<article[^>]*>\)/\n\1\n/; s|\(</article>\)|\n\1\n|;' | \
sed -n '/<article/,/article>/{p}' > old/${NAME//\//%}.html

exit $?
