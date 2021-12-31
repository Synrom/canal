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

methods = {
	"Plus":"+",
	"Minus":"-",
	"Times":"*",
	"Divide":"/",
	"And":"&",
	"Or":"|",
	"Xor":"^",
}

methods_solo = {
    "Inc":"++",
    "Dec":"--",
}

for _class in classes:
    with open("../src/variable/"+_class+".cpp","a") as f:
        for method in methods_solo:
            f.write("void "+_class+"::"+method+"(){\n")
            f.write("\tdebug(\""+_class+"::"+method+"\");\n")
            f.write("\tvalue."+_class+methods_solo[method]+";\n")
            f.write("}\n")
        f.write("void "+_class+"::Neg(variable *where){\n")
        f.write("\tdebug(\""+_class+"::Neg\");\n")
        f.write("\terror_conditional(!where, \"in "+_class+"::Neg where is NULL\");\n\n")
        f.write("\tnew (where) "+_class+"(\"\", ("+classes[_class]+") (~value."+_class+"));\n")
        f.write("}\n")


exit(0)

for _class in classes:
    with open("../src/variable/"+_class+".cpp","w") as f:
        f.write("#include <string>\n#include <canal/variable.h>\n#include <canal/debugger.h>\n#include <new>\n")
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
        f.write(_class+"::~"+_class+"(){\n")
        f.write("\tdebug(\"destructing "+_class+" object\");\n")
        f.write("}\n")
        f.write("\n")
        for method in methods:
            f.write("void "+_class+"::"+method+"(variable *where, variable *what){\n")
            f.write("\terror_conditional(!what, \"in "+_class+"::"+method+" what is NULL\");\n\n")
            f.write("\tif(where == this || !where){\n")
            f.write("\t\tdebug(\""+_class+"::"+method+" where == this\");\n")
            f.write("\t\tvalue."+_class+" "+methods[method]+"= what->value."+_class+";\n")
            f.write("\t}else{\n")
            f.write("\t\tdebug(\""+_class+"::"+method+" where != this\");\n")
            f.write("\t\tnew (where) "+_class+"(\"\", ("+classes[_class]+") (value."+_class+" "+methods[method]+" what->value."+_class+"));\n")
            f.write("\t}\n")
            f.write("}\n")






