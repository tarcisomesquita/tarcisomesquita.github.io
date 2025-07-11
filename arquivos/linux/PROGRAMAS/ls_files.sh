#!/bin/bash
# esse programa equivale ao comando:
# find "$@" -type f -print

function interage {
   eval LIXO=\(\"\$E_${N}\"\/\*\)
   
   eval ARQUIVOS_${N}=\(\"\$\{LIXO\[\@\]\}\"\)
   
   if eval [ \$P_$N -eq 0 ] ; then
      i=0
      while true ; do
         if [ -d "${LIXO[$i]}" ] ; then
            i=$(($i+1))
            continue
         elif [ "${LIXO[$i]}" ] ; then 
            echo \'"${LIXO[$i]}"\'
         else
            break
         fi
         i=$(($i+1))
      done
   fi
   
   eval i=\$P_${N}
   while true ; do
      if [ -d "${LIXO[$i]}" ] ; then
         eval P_${N}=$i
         #eval echo \"P_${N}=\$P_${N}\"
         echo ""
         N=$(($N + 1))
         eval P_${N}=0
         eval E_${N}=\"${LIXO[$i]}\"
         interage
      elif [ "${LIXO[$i]}" ] ; then 
         i=$(($i+1))
         continue
      else
         break
      fi
      i=$(($i+1))
   done
   
   if [ $N -gt 0 ] ; then
      N=$(($N - 1))
      eval P_${N}=\$\(\(\$P_${N} + 1\)\)
      interage
      #echo "TEM MAIS"
   fi
   
   exit 0
}


if [ ! -d "$@" ] ; then
   /bin/echo "\"$@\" não é um diretório"
   exit 1 ;
fi

N=0
eval P_${N}=0
eval E_${N}=\"$@\"

interage

exit 0

