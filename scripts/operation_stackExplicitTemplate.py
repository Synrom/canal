operations = [
	"Add",
	"Minus",
	"Divide",
	"Times",
	"Or",
	"And",
	"Xor",
	"Shl",
	"Shr",
	"Neg",
	"Dec",
	"Inc",
	"Call",
	"Equal",
	"Ret"
]

with open("../src/operation/operation_stack.cpp","a") as f:
    for operation in operations:
        f.write("template void operation_stack::insert<"+operation+">(const "+operation+" &value,rope &r);\n")
        f.write("template void operation_stack::insert<"+operation+">(const "+operation+" &value,std::vector<rope> &ropes);\n")
