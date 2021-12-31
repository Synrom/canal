
methods = {
	"Plus":"+",
	"Minus":"-",
	"Times":"*",
	"Divide":"/",
	"And":"&",
	"Or":"|",
	"Xor":"^",
}

with open("../src/variable/pointer.cpp","a") as f:
    for method in methods:
        f.write("void pointer::"+method+"(variable *where, variable *what){\n")
        f.write("\terror_conditional(!what, \"in pointer::"+method+" what is NULL\");\n\n")
        f.write("\tif(where == this || !where){\n")
        f.write("\t\tdebug(\"pointer::"+method+" where == this\");\n")
        f.write("\t\tvalue.unsignedlonglong "+methods[method]+"= what->value.unsignedlonglong;\n")
        f.write("\t}else{\n")
        f.write("\t\tdebug(\"pointer::"+method+" where != this\");\n")
        f.write("\t\tnew (where) pointer(\"\", (unsigned long long) (value.unsignedlonglong "+methods[method]+" what->value.unsignedlonglong), size);\n")
        f.write("\t}\n")
        f.write("}\n")






