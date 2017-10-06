import time
import RPi.GPIO as GPIO
GPIO.setmode(GPIO.BCM)
GPIO.setup(18,GPIO.OUT)

p = GPIO.PWM(18,50)  
p.start(0)
try:
    while 1:
        for dc in range(0, 101, 1):
            p.ChangeDutyCycle(dc)
            time.sleep(0.02)
        for dc in range(100,-1,-1):
            p.ChangeDutyCycle(dc)
            time.sleep(0.02)
except KeyboardInterrupt:
    pass
p.stop()
GPIO.cleanup()
