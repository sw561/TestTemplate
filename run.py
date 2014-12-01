#!/usr/bin/env python

from program import *
from analyse import *
import sys

if len(sys.argv)>1: debug = sys.argv[1]
else: debug = 0

d = dict()
p = Program("Data",d,debug,1)

# Load data from text file ready for plots
p.data = p.data()
wrapper(p,plot,"plot1",".png")
