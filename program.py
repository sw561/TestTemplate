from numpy import loadtxt
from os import system,path

# A class to create input files, call an external executable, open output file
# and do post-computation analysis such as plotting

# This should also check whether the program has already been run with that input file.
# If it has, it should recover the previously produced data.

class Program:
	# compiled has one value for all class instances
	compiled = False
	def __init__(self,folder,d):
		self.folder = folder
		self.d = d

		# Create folder if necessary
		if not path.isdir(folder):
			system("mkdir "+folder)

		# Define file names
		self.name = self.name()
		self.input_name = self.folder+"/"+self.name+"input.txt"
		self.out_name = self.folder+"/"+self.name+"out.txt"
		
		if not path.exists(self.input_name):
			self.create_input()

		if not path.exists(self.out_name):
			if not Program.compiled:
				system("make")
				Program.compiled = True
			self.run()
	
	def run(self):
		system("./main "+self.out_name+" 0 "+self.input_name)
	
	def data(self):
		return loadtxt(self.out_name)
			
	def name(self):
		s = ""
		for key in self.d:
			if s!="": s+="_"
			s+=key+str(self.d[key])
		return s
	
	def create_input(self):
		f=open("Data/"+self.name+"input.txt","w")
		for key in self.d:
			f.write(key+" "+str(self.d[key])+"\n")
		f.close()
