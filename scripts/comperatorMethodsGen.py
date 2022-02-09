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
        "isBigger":">",
        "isSmaller":"<",
        "isEqual":"==",
}


with open("../src/variable/comperator.cpp","w") as f:
    f.write("#include <canal/debugger.h>\n#include <canal/variable.h>\n\n")
    for _class in classes:
        for method in methods:
            f.write("bool "+_class+"::"+method+"(variable *cmp){\n")
            f.write("\tdebug(\""+_class+"::"+method+"\");\n")
            f.write("\treturn value."+_class+" "+methods[method]+" cmp->value."+_class+";\n")
            f.write("}\n")


