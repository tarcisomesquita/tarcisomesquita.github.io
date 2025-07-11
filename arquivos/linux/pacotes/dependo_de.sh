#!/bin/bash
if [ -z $1 ] ; then
   echo "Uso: $0 NOME_DO_PACOTE"
   exit 1
fi

# dpkg-query --status $1

cat /var/lib/dpkg/status | egrep '(^Package:|^Depends:)' | egrep -A1 -x "^Package: $1" | egrep -v '^Package' | cut -c10- | tr ',' '\n' | tr -d ' ' | cut -d'(' -f1 | sort

exit 0

