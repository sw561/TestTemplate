#!/usr/bin/env python

from program import *
import sys

if len(sys.argv)>1: debug = sys.argv[1]
else: debug = 0

p = Program("Data",dict(),debug,1)
print p.data()
