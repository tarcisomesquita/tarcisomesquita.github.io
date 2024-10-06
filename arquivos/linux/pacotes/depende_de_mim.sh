#!/bin/bash
if [ -z $1 ] ; then
   echo "Uso: $0 NOME_DO_PACOTE"
   exit 1
fi

# arquivos do pacote ficam listados em /var/lib/dpkg/info/*.list

cat /var/lib/dpkg/status | egrep '(^Depends:|^Package)' | egrep -B1 "$1 " | egrep '^Package' | cut -d' ' -f2 | sort
exit 0

