operators_param = [
	"operatorPlus",
	"operatorMinus",
	"operatorTimes",
	"operatorDivide",
	"operatorAnd",
	"operatorOr",
	"operatorXor",
]

operators_noparam = [
	"operatorNeg",
	"operatorInc",
	"operatorDec"
]

	

types = [
	"UnsignedInt",
	"SignedInt",
	"UnsignedChar",
	"SignedChar",
	"Double",
	"Float",
	"UnsignedShort",
	"SignedShort",
	"UnsignedLong",
	"SignedLong",
	"UnsignedLonglong",
	"SignedLonglong",
	"LongDouble"
]

for operator in operators_param:
	for type in types:
		print("variable "+operator+type+"(const variable &);")

for operator in operators_noparam:
	for type in types:
		print("variable "+operator+type+"();")

