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

with open("../src/container/vectors.cpp","a") as f:
    for _class in classes:
        f.write("void vstance::add_var(const std::string &s, "+classes[_class]+" v){\n")
        f.write("\tdebug(\"adding %s to vstance\",s.c_str());\n")
        f.write("\tfor(auto i = container.begin();i != container.end();i++)\n")
        f.write("\t\t(*i)->emplace_back(s,v);\n")
        f.write("}\n\n")

exit(0)
with open("../src/variable/vcontainer.cpp","a") as f:
    for _class in classes:
        f.write("void vcontainer::emplace_back(const std::string &s, "+classes[_class]+" v){\n")
        f.write("\tdebug(\"emplacing "+_class+" at the end of vcontainer\");\n")
        f.write("\tvariable *location = get_new_location();\n")
        f.write("\tnew (location) "+_class+"(s,v);\n")
        f.write("}\n\n")

