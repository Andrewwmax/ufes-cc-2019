import os
import serial
import time
import bluetooth, subprocess
from datetime import datetime

name = 'HC-06'
addr = 'FF:FF:FF:FF:FF:FF'
port = 1

# A senha
# Precisamos configurar manualmente na primeira vez 
# no prórpio S.O, por questões de incompatibilidade
passkey = '1234'

try:
    s = bluetooth.BluetoothSocket(bluetooth.RFCOMM)
    
    s.connect((addr,port))

	print 'connect on'

    b = 10;
    while True:
        time.sleep(0.01)
        tmp = s.recv(250)
		print('{},{}'.format(datetime.now().strftime("%Y-%m-%d %H:%M.%S"), tmp))

except bluetooth.btcommon.BluetoothError as err:
    pass
    s.close()
    print 'error'


# Opcional para conecxão via cabo usb, para o Arduino, definir a porta
# 
# ser = serial.Serial('/dev/tty0', 9600)
# while (ser.is_open):
#     print('{},{}'.format(datetime.now().strftime("%Y-%m-%d %H:%M.%S"), ser.readline()))
#     f = open("temp.csv", "a+")
#     f.write('{},{}'.format(datetime.now().strftime("%Y-%m-%d %H:%M.%S"), ser.readline()))
#     f.close()
# ser.close()