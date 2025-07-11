#!/bin/bash

kill `pidof NetworkManager`
kill `pidof wpa_supplicant`
kill `pidof dhclient3`

hostname noone
echo "noone" > /etc/hostname
echo "noone" > /proc/sys/kernel/hostname
cat > /etc/hosts << eof
127.0.0.1 localhost
127.0.1.1 noone
eof

ifconfig wlan0 down
ifconfig wlan0 hw ether 00:01:02:03:04:05
ifconfig wlan0 up
ifconfig wlan0 192.168.33.12 netmask 255.255.255.0

# talvez isso tenha que ser feito com a interface down
iwconfig wlan0 essid "PP"
iwconfig wlan0 channel 6
iwconfig wlan0 ap 00:01:02:03:04:01
iwconfig wlan0 key open
iwconfig wlan0 mode Managed

route del default
route add default wlan0
route add default gw 192.168.33.1

cat > /etc/resolv.conf << EOF
nameserver 208.67.222.222
nameserver 208.67.220.220
EOF

/etc/init.d/networking restart

ping -c 5 192.168.33.1
tracepath www.google.com

