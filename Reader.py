import time
import serial
from pyHEC.pyHEC import PyHEC

def USB_Reader():
    ser = serial.Serial("/dev/ttyUSB0", 9600)
    hec = PyHEC("bb127acf-7732-429c-9b41-c867f9a9878e", "http://52.53.229.125")
    #event = {"text":"this is a message in a bottle", "whatever_else":"blabla"}

    while ser:
	#with open('data.txt','a')as hammerTime:
	#	hammerTime.write(ser.readline())
	str = ser.readline()
	result = str.split(",")

	event = {"Power":result[0], "Current":result[1]}
	hec.send(event)
	print(str)
	print(result[0])
	print(result[1])
	print("-----------")
    ser.close()




def runner():
    flag = True
    while flag == True:
	USB_Reader()


runner()
