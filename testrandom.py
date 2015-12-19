#!/usr/bin/env python

import os
import random
from time import sleep


def rndmp3 ():
    randomfile = random.choice(os.listdir("mp3"))
    file = ' mp3/'+ randomfile
    print file
    os.system ('mpg123 -g 100' + file)

rndmp3 ()

sleep(0.1);