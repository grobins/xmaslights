#!/usr/bin/env python

import os, random
from time import sleep

import RPi.GPIO as GPIO

GPIO.setmode(GPIO.BCM)
GPIO.setup(4, GPIO.IN)

def rndmp3 ():
    randomfile = random.choice(os.listdir("mp3"))
    file = ' mp3/'+ randomfile
    os.system ('mpg123' + file)

while True:
    if (GPIO.input(4)== True):
        rndmp3 ()

    sleep(0.1);