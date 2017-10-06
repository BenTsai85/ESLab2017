import RPi.GPIO as GPIO
from time import sleep

GPIO.setmode(GPIO.BCM)
GPIO.setup(4, GPIO.IN)

while (1):
    GPIO.wait_for_edge(4, GPIO.FALLING)
    print "Pressed"
