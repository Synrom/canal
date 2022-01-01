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
	"Dec",
    "Neg",
    "Call",
    "Equal",
    "Ret",
]

operators_empty = [
    #"Switch",
    #"Next_Switch",
    #"End_Switch"
]

with open("../src/operation/operation_stack.cpp","a") as f:
    for operation in operators_param:
        f.write("void operation_stack::push_back(const "+operation+" &cpy){\n")
        f.write("\tdebug(\"adding "+operation+" to operation_stack\");\n")
        f.write("\tnew (get_new_location()) "+operation+"(cpy);\n")
        f.write("}\n\n")
    for operation in operators_noparam:
        f.write("void operation_stack::push_back(const "+operation+" &cpy){\n")
        f.write("\tdebug(\"adding "+operation+" to operation_stack\");\n")
        f.write("\tnew (get_new_location()) "+operation+"(cpy);\n")
        f.write("}\n\n")
