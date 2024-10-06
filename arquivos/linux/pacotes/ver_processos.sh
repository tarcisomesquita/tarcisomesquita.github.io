i=1 ; 
LINHA="" ; 
while [ $i != 10 ] ; do 
   LINHA="$LINHA /proc/${i}*/cmdline"  ;  
   i=$(($i + 1)) ; 
done ; 

for j in $LINHA ; do 
   if [ `wc -m $j | cut -d" " -f1` != 0 ] ; then 
      echo $j | cut -d/ -f3 ;  
      cat -s $j &&  echo -e "\n" ; 
   fi ;  
done ;

