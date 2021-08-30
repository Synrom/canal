classes = [
	"signedchar",
	"unsignedchar",
	"signedshort",
	"unsignedshort",
	"signedint",
	"unsignedint",
	"signedlong",
	"unsignedlong",
	"signedlonglong",
	"unsignedlonglong",
	"_float",
	"_double",
	"longdouble"
]

methods = [
	("Plus","+"),
	("Minus","-"),
	("Times","*"),
	("Divide","/"),
	("And","&"),
	("Or","|"),
	("Xor","^")
]


for _class in classes:
	with open("../src/variable/"+_class+".cpp","w") as f:
		f.write("\n")
		for method in methods:
			f.write("variable *"+_class+"::"+method[0]+"(variable *v){\n")
			f.write("\treturn new "+_class+"(rvalue, value."+_class+" "+method[1]+" v->value."+_class+");\n")
			f.write("}\n")
			f.write("\n")
		for method in [("Inc","++"),("Dec","--")]:
			f.write("variable *"+_class+"::"+method[0]+"(){\n")
			f.write("\tvalue."+_class+method[1]+";\n")
			f.write("\treturn this;\n")
			f.write("}\n")
			f.write("\n")
		for method in [("Neg","~")]:
			f.write("variable *"+_class+"::"+method[0]+"(){\n")
			f.write("\treturn new "+_class+"(rvalue, ~(value."+_class+"));\n")
			f.write("}\n")
			f.write("\n")
			
