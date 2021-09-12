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


for _class in classes:
	with open("../src/variable/"+_class+".cpp","a") as f:
		f.write("\n")
		f.write("void "+_class+"::copy_to_pointer(variable *place){\n")
		f.write("\tnew(place) "+_class+"(variable::rvalue,value."+_class+")\n")
		f.write("}\n")
