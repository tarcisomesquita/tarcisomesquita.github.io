#! /usr/bin/python3
import socket
#ip = raw_input("Enter the ip: ")
#port = input("Enter the port: ")
#s.connect((ip, port))

s = socket.socket()
s.connect(("127.0.0.1", 9091))
answer = s.recv(1024)
print(answer)
s.close
