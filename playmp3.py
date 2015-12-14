#!/usr/bin/env python

import os
from time import sleep

import RPi.GPIO as GPIO

GPIO.setmode(GPIO.BCM)
GPIO.setup(4, GPIO.IN)

while True:
    if (GPIO.input(4)== False):
        os.system('mpg123 -q mp3/jinglebells.mp3 &')

    sleep(0.1);