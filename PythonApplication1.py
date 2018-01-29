#test app;lication
import socket
sock = socket.socket()

host = "192.168.1.82"
port = 8080

sock.connect((host,port));
message = "Hello World;)"
sock.send(message)

data =""
while len(data) < len(message):
	data += sock.recv(1)

print (data)
sock.close()