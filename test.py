#!/usr/bin/env python

from os import system
import sys

def test(name):
	fail=system("make "+name+"_test")
	if fail: return
	print ""
	system("./"+name+"_test")

for i in range(1,len(sys.argv)):
	test(sys.argv[i])

# If no command line arguments are given run tests
# for all files in the list "names"
if len(sys.argv)==1:
	names = ["demo"]
	for i in names:
		test(i)

