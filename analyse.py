import pylab as py
from os import path,system

def wrapper(p,plotf,name,extension):
	filename = "Plots/"+p.name+name+extension

	if not path.isdir("Plots"): system("mkdir Plots")
	
	if p.overwrite or not path.exists(filename):
		plotf(p,filename)

def plot(p,filename):
	py.plot([0,1],[p.data*i for i in range(2)])
	print "Making plot"
	py.savefig(filename)
	py.clf()

