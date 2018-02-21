import os
import subprocess
import time

def USB_Reader():
    for x in range (0,31):
	cmd = ["cat","/dev/ttyUSB0"]
	subprocess.check_output(cmd)
	time.sleep(2)
	print('------------')


USB_Reader()
