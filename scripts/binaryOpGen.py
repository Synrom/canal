operators_param = {
	"Add":"Plus",
	"Minus":"Minus",
	"Times":"Times",
	"Divide":"Divide",
	"And":"And",
	"Or":"Or",
	"Xor":"Xor",
}

operators_noparam = [
	"Inc",
	"Dec"
]

operators_empty = [
    "Call",
    "Equal",
    "Ret",
    #"Switch",
    #"Next_Switch",
    #"End_Switch"
]

with open("../src/operation/operation.cpp","a") as f:
    for operation in operators_param:
        f.write(operation+"::"+operation+"(const std::string &left, const std::string &right, function &f) : operation(operation::"+operation+",left,right,f) { \n")
        f.write("\tdebug(\"creating "+operation+" operation\");\n")
        f.write("}\n\n")
        f.write("void "+operation+"::executeOperation(variable *left, variable *right, variable *where){\n")
        f.write("\tdebug(\"calling "+operation+" operation\");\n")
        f.write("\tleft->"+operators_param[operation]+"(where, right);\n")
        f.write("}\n\n")
    for operation in operators_noparam:
        f.write(operation+"::"+operation+"(const std::string &left, function &f) : operation(operation::"+operation+",left,\"\",f) { \n")
        f.write("\tdebug(\"creating "+operation+" operation\");\n")
        f.write("}\n\n")
        f.write("void "+operation+"::executeOperation(variable *left, variable *right, variable *where){\n")
        f.write("\twarning(\"calling "+operation+" executeOperation which is really weird\");\n")
        f.write("}\n\n")
    f.write("Neg::Neg(const std::string &left, function &f) : operation(operation::"+operation+",left,\"\",f) { \n")
    f.write("\tdebug(\"creating Neg operation\");\n")
    f.write("}\n\n")
    f.write("void Neg::executeOperation(variable *left, variable *right, variable *where){\n")
    f.write("\twarning(\"calling Neg executeOperation which is really weird\");\n")
    f.write("}\n\n")
    

