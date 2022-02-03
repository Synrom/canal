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

with open("../src/variable/shl_shr.cpp","a") as f:
    for _class in classes:
        f.write("void "+_class+"::Shl(variable *where, variable *what){\n")
        f.write("\terror_conditional(!what, \"in "+_class+"::Shl what is NULL\");\n\n")
        f.write("\tif(where == this || !where){\n")
        f.write("\t\tdebug(\""+_class+"::Shl where == this\");\n")
        f.write("\t\tvalue."+_class+" <<= what->value."+_class+";\n")
        f.write("\t}else{\n")
        f.write("\t\tdebug(\""+_class+"::Shl where != this\");\n")
        f.write("\t\tnew (where) "+_class+"(\"\", ("+classes[_class]+") (value."+_class+" << what->value."+_class+"));\n")
        f.write("\t}\n")
        f.write("}\n\n")
        f.write("void "+_class+"::Shr(variable *where, variable *what){\n")
        f.write("\terror_conditional(!what, \"in "+_class+"::Shr what is NULL\");\n\n")
        f.write("\tif(where == this || !where){\n")
        f.write("\t\tdebug(\""+_class+"::Shr where == this\");\n")
        f.write("\t\tvalue."+_class+" >>= what->value."+_class+";\n")
        f.write("\t}else{\n")
        f.write("\t\tdebug(\""+_class+"::Shr where != this\");\n")
        f.write("\t\tnew (where) "+_class+"(\"\", ("+classes[_class]+") (value."+_class+" >> what->value."+_class+"));\n")
        f.write("\t}\n")
        f.write("}\n")
