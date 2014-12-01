data = file("param_list.txt","r")

dec = file("param_decl.h.auto","w")
defi = file("param_defi.h.auto","w")
proc = file("param_proc.h.auto","w")
proc.write("FIRST_")

for line in data:
	_type,name,value = line.split()
	dec.write(_type+" "+name+";\n")
	defi.write(name+" = "+value+";\n")
	proc.write("PARAM("+name+")\n")

dec.close()
defi.close()
proc.close()
