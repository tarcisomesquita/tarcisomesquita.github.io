#! /usr/bin/python3
import socket
TCP_IP = "127.0.0.1"
TCP_PORT = 9091
BUFFER_SIZE = 100
s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
s.bind((TCP_IP, TCP_PORT))
s.listen (1)
conn, addr = s.accept()
print ('Connection address: ', addr )
while 1:
   data=conn.recv(BUFFER_SIZE)
   if not data:break
   print ("Received data: ", data)
   conn.send(data) #echo
conn.close
