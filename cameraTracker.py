import cv2
import numpy as np
import serial
import time


face_cascade = cv2.CascadeClassifier('haarcascade_frontalface_default.xml')
cap = cv2.VideoCapture(0)
cap.set(3, 480)
cap.set(4, 480)

_, frame = cap.read()
rows, cols, _ = frame.shape

x_medium = int(cols / 2)
center = int(cols / 2)
position = 1500 # degrees
arduino = serial.Serial(port='COM4', baudrate=115200, timeout=.1)

def readWrite(data):
    arduino.write(data)
    time.sleep(0.005)
    readData = arduino.readline() 
    print("Received Data")
    print(readData)

while True:
    _, frame = cap.read()
    gray = cv2.cvtColor(frame, cv2.COLOR_BGR2GRAY)
    faces = face_cascade.detectMultiScale(gray, 1.3, 5)

    

    for(x,y,w,h) in faces:
        cv2.rectangle(frame, (x,y), (x+w, y+h), (255,0,0), 2)
        roi_gray = gray[y:y+h, x:x+w]
        roi_color = frame[y:y+h, x:x+w]

        x_medium = int((x + x + w) / 2)
        y_medium = int((y + y + h) / 2)
        if x and y and w and h :
            print("Face Detected..")
            if x_medium < center -30:
                position += 20
                print("Move Left")
                readWrite(b'4')
            elif x_medium > center + 30:
                position -= 20
                print("Move Right")
                readWrite(b'3')
            elif y_medium < center -30:
                position += 20
                print("Move Up")
                readWrite(b'1')
            elif y_medium > center + 30:
                position -= 20
                print("Move Down")
                readWrite(b'2')
            else:
                print("STOP")
                readWrite(b'0')
        break

    cv2.imshow("Frame", frame)
    key = cv2.waitKey(1)
    
    if key == 27:
        break

    # Move servo motor
    # if x_medium < center -30:
    #     position += 20
    #     print("Camera position Left")
    # elif x_medium > center + 30:
    #     position -= 20
    #     print("Camera position Right")
	
    # if position > 2500:
    #     position -= 20
    # elif position < 500:
	#     position += 20

    #print(position)
    #pwm.setServoPosition(0, position)
    
cap.release()
cv2.destroyAllWindows()
