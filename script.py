#!/usr/bin/env python

from program import *
import sys

if len(sys.argv)>1: debug = sys.argv[1]
else: debug = 0

d = dict()

# d["factor"]=2

p = Program("Data",d,debug,True)
print p.name

# Plotting or further analysis:
p.data = p.data()
print p.data
