from numpy import loadtxt
from os import system,path
import sys

# A class to create input files, call an external executable, open output file
# and do post-computation analysis such as plotting

# This should also check whether the program has already been run with that input file.
# If it has, it should recover the previously produced data.

class Program:
	# compiled has one value for all class instances
	compiled = False

	def __init__(self,folder,d,debug=0,overwrite=False):
		self.folder = folder
		self.d = d # Dictionary containing modified parameters
		self.debug = debug
		self.overwrite = overwrite

		# Create folder if necessary
		if not path.isdir(folder):
			system("mkdir "+folder)

		# Define file names
		self.name = self.name()
		if self.name=="": self.input_name = ""
		else: self.input_name = self.folder+"/"+self.name+"input"
		self.out_name = self.folder+"/"+self.name+"out"
		
		# Create input file if necessary
		if self.name!="" and not path.exists(self.input_name):
			self.create_input()

		# Check whether it's been run before, then compile and run
		if self.overwrite or not path.exists(self.out_name):
			if not Program.compiled:
				fail=system("make")
				if fail: exit()
				Program.compiled = True
			fail=system("./main "+self.out_name+" "+str(self.debug)+" "+self.input_name)
			if fail: exit()
	
	def data(self):
		return loadtxt(self.out_name)
			
	def name(self):
		s = ""
		for key in sorted(self.d.keys()):
			if s!="": s+="_"
			s+=key+str(self.d[key])
		return s
	
	def create_input(self):
		f=open(self.input_name,"w")
		for key in self.d:
			f.write(key+" "+str(self.d[key])+"\n")
		f.close()

# Functions for compiling / running of tests
def test(name):
	fail=system("make "+name+"_test")
	if fail: return
	print ""
	system("./"+name+"_test")

def alltest(names,argv):
	for i in range(1,len(argv)):
		test(argv[i])
	
	if len(argv) == 1:
		for name in names: test(name)
