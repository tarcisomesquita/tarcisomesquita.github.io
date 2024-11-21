#!/bin/bash
for P in $(sudo apt-get --assume-no install $1 2>&1  | grep -A5 NOVOS | grep '^ ' | sed ':I; $bF; N; bI; :F; s/\n//g'); do 
   grep -h -A20 "^Package: ${P}$" /var/lib/apt/lists/archive.ubuntu.com_ubuntu_dists_artful_*_Packages 2>/dev/null | grep -m 1 Filename | cut -d' ' -f2 | \
   sed 's,^,wget old-releases.ubuntu.com/ubuntu/,';
done
