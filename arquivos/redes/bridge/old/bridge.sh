#!/bin/sh

ETH1=enp7s0
ETH2=enx00e04c36158d

iptables -t filter -F
iptables -t filter -I INPUT   -j DROP
iptables -t filter -I FORWARD -j ACCEPT
iptables -t filter -I OUTPUT  -j DROP
iptables -t filter -L -n -v --line-number

ip6tables -t filter -F
ip6tables -t filter -I INPUT   -j DROP
ip6tables -t filter -I FORWARD -j DROP
ip6tables -t filter -I OUTPUT  -j DROP

/etc/init.d/network-manager stop

rmmod r8169
rmmod r8152
rmmod ath9k

modprobe r8169
modprobe r8152

ip link set  dev $ETH1 down
ip link set  dev $ETH2 down

ip link set  dev $ETH1 name eth1
ip link set  dev $ETH2 name eth2

ip link set  dev eth1 down
ip link set  dev eth2 down
ip link set  dev br0  down

echo 0 > /proc/sys/net/ipv6/conf/eth1/disable_ipv6
echo 0 > /proc/sys/net/ipv6/conf/eth2/disable_ipv6
echo 1 > /proc/sys/net/ipv4/ip_forward

ip link set  dev eth1 address 00:e0:4c:36:15:81
ip link set  dev eth2 address 00:e0:4c:36:15:82

brctl delif br0 eth1
brctl delif br0 eth2

brctl delbr br0

brctl addbr br0

brctl addif br0 eth1
brctl addif br0 eth2

brctl setfd br0 0
brctl stp   br0 off

ip addr add  0.0.0.0/24 dev eth1
ip addr add  0.0.0.0/24 dev eth2
ip addr add  0.0.0.0/24 dev br0

ip link set  dev eth1 promisc on
ip link set  dev eth2 promisc on
ip link set  dev br0  promisc on

ip link set  dev eth1 up
ip link set  dev eth2 up
ip link set  dev br0  up

tcpdump -i eth1 -n -w eth1.pcap -C 200 -W 2 -U &
tcpdump -i eth2 -n -w eth2.pcap -C 200 -W 2 -U &

exit 0

