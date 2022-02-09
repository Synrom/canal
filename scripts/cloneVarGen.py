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
        "pointer":"unsignedlonglong"
}

methods = {
        "isBigger":">",
        "isSmaller":"<",
        "isEqual":"==",
}


with open("../src/variable/clone.cpp","w") as f:
    f.write("#include <canal/debugger.h>\n#include <canal/variable.h>\n#include <new>\n\n")
    for _class in classes:
        f.write("void "+_class+"::clone(variable *where){\n")
        f.write("\tdebug(\"cloning %p to %p\",this,where);\n")
        f.write("\tnew (where) "+_class+"(this);\n")
        f.write("}\n")


