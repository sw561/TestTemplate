#!/usr/bin/env python

from program import *
from analyse import *

for a in [0,10]:
	for factor in [1,2]:
		d = dict()
		d["a"]=a
		d["factor"]=factor

		p = Program("Data",d)
		print p.name

		# Plotting or further analysis:
		p.data = p.data()
		wrapper(p,plot,"plot1",".png")
