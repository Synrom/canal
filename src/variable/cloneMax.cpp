#include <canal/debugger.h>
#include <canal/variable.h>
#include <new>
#include <limits>
#include <climits>
#include <float.h>

void signedint::cloneMax(variable *location){
	debug("cloning max of signedint to %p",location);
	new (location) signedint("",INT_MAX);
}

void unsignedint::cloneMax(variable *location){
	debug("cloning max of unsignedint to %p",location);
	new (location) unsignedint("",UINT_MAX);
}

void signedchar::cloneMax(variable *location){
	debug("cloning max of signedchar to %p",location);
	new (location) signedchar("",SCHAR_MAX);
}

void unsignedchar::cloneMax(variable *location){
	debug("cloning max of unsignedchar to %p",location);
	new (location) unsignedchar("",UCHAR_MAX);
}

void signedshort::cloneMax(variable *location){
	debug("cloning max of signedshort to %p",location);
	new (location) signedshort("",SHRT_MAX);
}

void unsignedshort::cloneMax(variable *location){
	debug("cloning max of unsignedshort to %p",location);
	new (location) unsignedshort("",USHRT_MAX);
}

void signedlong::cloneMax(variable *location){
	debug("cloning max of signedlong to %p",location);
	new (location) signedlong("",LONG_MAX);
}

void unsignedlong::cloneMax(variable *location){
	debug("cloning max of unsignedlong to %p",location);
	new (location) unsignedlong("",ULONG_MAX);
}

void unsignedlonglong::cloneMax(variable *location){
	debug("cloning max of unsignedlonglong to %p",location);
	new (location) unsignedlonglong("",ULLONG_MAX);
}

void signedlonglong::cloneMax(variable *location){
	debug("cloning max of signedlonglong to %p",location);
	new (location) signedlonglong("",LLONG_MAX);
}

void _float::cloneMax(variable *location){
	debug("cloning max of float to %p",location);
	new (location) _float("",FLT_MAX);
}

void _double::cloneMax(variable *location){
	debug("cloning max of double to %p",location);
	new (location) _double("",DBL_MAX);
}

void longdouble::cloneMax(variable *location){
	debug("cloning max of double to %p",location);
	new (location) longdouble("",LDBL_MAX);
}

