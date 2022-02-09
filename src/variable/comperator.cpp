#include <canal/debugger.h>
#include <canal/variable.h>

bool signedchar::isBigger(variable *cmp){
	debug("signedchar::isBigger");
	return value.signedchar > cmp->value.signedchar;
}
bool signedchar::isSmaller(variable *cmp){
	debug("signedchar::isSmaller");
	return value.signedchar < cmp->value.signedchar;
}
bool signedchar::isEqual(variable *cmp){
	debug("signedchar::isEqual");
	return value.signedchar == cmp->value.signedchar;
}
bool unsignedchar::isBigger(variable *cmp){
	debug("unsignedchar::isBigger");
	return value.unsignedchar > cmp->value.unsignedchar;
}
bool unsignedchar::isSmaller(variable *cmp){
	debug("unsignedchar::isSmaller");
	return value.unsignedchar < cmp->value.unsignedchar;
}
bool unsignedchar::isEqual(variable *cmp){
	debug("unsignedchar::isEqual");
	return value.unsignedchar == cmp->value.unsignedchar;
}
bool signedshort::isBigger(variable *cmp){
	debug("signedshort::isBigger");
	return value.signedshort > cmp->value.signedshort;
}
bool signedshort::isSmaller(variable *cmp){
	debug("signedshort::isSmaller");
	return value.signedshort < cmp->value.signedshort;
}
bool signedshort::isEqual(variable *cmp){
	debug("signedshort::isEqual");
	return value.signedshort == cmp->value.signedshort;
}
bool unsignedshort::isBigger(variable *cmp){
	debug("unsignedshort::isBigger");
	return value.unsignedshort > cmp->value.unsignedshort;
}
bool unsignedshort::isSmaller(variable *cmp){
	debug("unsignedshort::isSmaller");
	return value.unsignedshort < cmp->value.unsignedshort;
}
bool unsignedshort::isEqual(variable *cmp){
	debug("unsignedshort::isEqual");
	return value.unsignedshort == cmp->value.unsignedshort;
}
bool signedint::isBigger(variable *cmp){
	debug("signedint::isBigger");
	return value.signedint > cmp->value.signedint;
}
bool signedint::isSmaller(variable *cmp){
	debug("signedint::isSmaller");
	return value.signedint < cmp->value.signedint;
}
bool signedint::isEqual(variable *cmp){
	debug("signedint::isEqual");
	return value.signedint == cmp->value.signedint;
}
bool unsignedint::isBigger(variable *cmp){
	debug("unsignedint::isBigger");
	return value.unsignedint > cmp->value.unsignedint;
}
bool unsignedint::isSmaller(variable *cmp){
	debug("unsignedint::isSmaller");
	return value.unsignedint < cmp->value.unsignedint;
}
bool unsignedint::isEqual(variable *cmp){
	debug("unsignedint::isEqual");
	return value.unsignedint == cmp->value.unsignedint;
}
bool signedlong::isBigger(variable *cmp){
	debug("signedlong::isBigger");
	return value.signedlong > cmp->value.signedlong;
}
bool signedlong::isSmaller(variable *cmp){
	debug("signedlong::isSmaller");
	return value.signedlong < cmp->value.signedlong;
}
bool signedlong::isEqual(variable *cmp){
	debug("signedlong::isEqual");
	return value.signedlong == cmp->value.signedlong;
}
bool unsignedlong::isBigger(variable *cmp){
	debug("unsignedlong::isBigger");
	return value.unsignedlong > cmp->value.unsignedlong;
}
bool unsignedlong::isSmaller(variable *cmp){
	debug("unsignedlong::isSmaller");
	return value.unsignedlong < cmp->value.unsignedlong;
}
bool unsignedlong::isEqual(variable *cmp){
	debug("unsignedlong::isEqual");
	return value.unsignedlong == cmp->value.unsignedlong;
}
bool signedlonglong::isBigger(variable *cmp){
	debug("signedlonglong::isBigger");
	return value.signedlonglong > cmp->value.signedlonglong;
}
bool signedlonglong::isSmaller(variable *cmp){
	debug("signedlonglong::isSmaller");
	return value.signedlonglong < cmp->value.signedlonglong;
}
bool signedlonglong::isEqual(variable *cmp){
	debug("signedlonglong::isEqual");
	return value.signedlonglong == cmp->value.signedlonglong;
}
bool unsignedlonglong::isBigger(variable *cmp){
	debug("unsignedlonglong::isBigger");
	return value.unsignedlonglong > cmp->value.unsignedlonglong;
}
bool unsignedlonglong::isSmaller(variable *cmp){
	debug("unsignedlonglong::isSmaller");
	return value.unsignedlonglong < cmp->value.unsignedlonglong;
}
bool unsignedlonglong::isEqual(variable *cmp){
	debug("unsignedlonglong::isEqual");
	return value.unsignedlonglong == cmp->value.unsignedlonglong;
}
bool _float::isBigger(variable *cmp){
	debug("_float::isBigger");
	return value._float > cmp->value._float;
}
bool _float::isSmaller(variable *cmp){
	debug("_float::isSmaller");
	return value._float < cmp->value._float;
}
bool _float::isEqual(variable *cmp){
	debug("_float::isEqual");
	return value._float == cmp->value._float;
}
bool _double::isBigger(variable *cmp){
	debug("_double::isBigger");
	return value._double > cmp->value._double;
}
bool _double::isSmaller(variable *cmp){
	debug("_double::isSmaller");
	return value._double < cmp->value._double;
}
bool _double::isEqual(variable *cmp){
	debug("_double::isEqual");
	return value._double == cmp->value._double;
}
bool longdouble::isBigger(variable *cmp){
	debug("longdouble::isBigger");
	return value.longdouble > cmp->value.longdouble;
}
bool longdouble::isSmaller(variable *cmp){
	debug("longdouble::isSmaller");
	return value.longdouble < cmp->value.longdouble;
}
bool longdouble::isEqual(variable *cmp){
	debug("longdouble::isEqual");
	return value.longdouble == cmp->value.longdouble;
}

bool pointer::isBigger(variable *cmp){
	debug("pointer::isBigger");
	return value.unsignedlonglong < cmp->value.unsignedlonglong;
}

bool pointer::isSmaller(variable *cmp){
	debug("pointer::isSmaller");
	return value.unsignedlonglong > cmp->value.unsignedlonglong;
}

bool pointer::isEqual(variable *cmp){
	debug("pointer::isEqual");
	return value.unsignedlonglong == cmp->value.unsignedlonglong;
}
