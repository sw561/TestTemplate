#!/usr/bin/env python

from program import *

# Folder in which to store input and output files
folder = "Data"

# Checks folder exists, and that the program has been compiled
init(folder)

for a in [0,10]:
	for factor in [1,2]:
		d = dict()
		d["a"]=a
		d["factor"]=factor

		p = Program(folder,d)
		print p.data()
		print ""
