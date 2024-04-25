import serial
import time 
from picamera2 import Picamera2, Preview
from libcamera import controls

picam2 = Picamera2()
camera_config = picam2.create_preview_configuration()
picam2.configure(camera_config)
#picam2.start_preview(Preview.QTGL)
picam2.set_controls({"AfMode": controls.AfModeEnum.Continuous}) # Step4
picam2.start()
time.sleep(5)

ser = serial.Serial (port="/dev/ttyS0", baudrate=9600)    #Open port ttyS0 with baud rate 9600
time.sleep(0.1) #wait for serial to open
while True:
    if (ser.inWaiting() > 0):
        time.sleep(0.01) 
        # read the bytes 
        received_data = ser.read(ser.inWaiting()).decode('ascii') 
        print(received_data)
        
        f = open("/home/user/Rover/Temperature/arduino_temperature_python.txt", "a")
        current_time = time.strftime("%H:%M:%S", time.localtime())
        f.write(current_time)
        f.write(",")
        f.write(received_data)
        f.write("\n")
        f.close()
        dateFilename = time.strftime("%H:%M:%S", time.localtime()) 
        strFilename = "/home/user/Rover/Pictures/" + dateFilename + ".jpg"
        picam2.capture_file(strFilename) 


    time.sleep(0.01)         
    
