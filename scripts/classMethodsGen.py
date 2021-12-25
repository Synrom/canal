classes = {
        "signedchar":"signed char",
        "unsignedchar":"unsigned char",
        "signedshort":"signed short",
        "unsignedshort":"unsigned short",
        "signedint":"signed int",
        "unsignedint":"unsigned int",
        "signedlong":"signed long",
        "unsignedlong":"unsigned long",
        "signedlonglong":"signed long long",
        "unsignedlonglong":"unsigned long long",
        "_float":"float",
        "_double":"double",
        "longdouble":"long double",
}

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
        f.write("#include <string>\n#include <canal/variable.h>\n#include <canal/debugger.h>\n")
        f.write("\n")
        f.write(_class+"::"+_class+"(const std::string &s,"+classes[_class]+" v) : variable(s){\n")
        f.write("\ttype = variable::"+_class+";\n")
        f.write("\tsize = sizeof("+classes[_class]+");\n")
        f.write("\tvalue."+_class+" = v;\n")
        f.write("\tdebug(\"creating an "+_class+"\");\n")
        f.write("}\n")
        f.write("\n")
        f.write(_class+"::"+_class+"(const variable *v) : variable(v->name) {\n")
        f.write("\tdebug(\"constructing "+_class+" from variable\");\n")
        f.write("\tsize = sizeof("+classes[_class]+");\n")
        f.write("\ttype = variable::"+_class+";\n")
        f.write("\tvalue."+_class+" = v->value."+_class+";\n")
        f.write("}\n")
        f.write("\n")



