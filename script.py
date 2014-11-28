#!/usr/bin/env python

from program import *

folder = "Data"

init(folder)

for G in [0,10]:#range(0,100,10):
	for factor in [2]:
		d = dict()
		d["a"]=G
		d["factor"]=factor

		data = Program(folder,d).data()
		print data
		print ""
