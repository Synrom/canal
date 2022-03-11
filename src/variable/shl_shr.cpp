#include <canal/debugger.h>
#include <canal/variable.h>

void signedchar::Shl(variable *where, variable *what){
	error_conditional(!what, "in signedchar::Shl what is NULL");

	if(where == this || !where){
		debug("signedchar::Shl where == this");
		value.signedchar <<= what->value.signedchar;
	}else{
		debug("signedchar::Shl where != this");
		new (where) signedchar("", (signed char) (value.signedchar << what->value.signedchar));
	}
}

void signedchar::Shr(variable *where, variable *what){
	error_conditional(!what, "in signedchar::Shr what is NULL");

	if(where == this || !where){
		debug("signedchar::Shr where == this");
		value.signedchar >>= what->value.signedchar;
	}else{
		debug("signedchar::Shr where != this");
		new (where) signedchar("", (signed char) (value.signedchar >> what->value.signedchar));
	}
}
void unsignedchar::Shl(variable *where, variable *what){
	error_conditional(!what, "in unsignedchar::Shl what is NULL");

	if(where == this || !where){
		debug("unsignedchar::Shl where == this");
		value.unsignedchar <<= what->value.unsignedchar;
	}else{
		debug("unsignedchar::Shl where != this");
		new (where) unsignedchar("", (unsigned char) (value.unsignedchar << what->value.unsignedchar));
	}
}

void unsignedchar::Shr(variable *where, variable *what){
	error_conditional(!what, "in unsignedchar::Shr what is NULL");

	if(where == this || !where){
		debug("unsignedchar::Shr where == this");
		value.unsignedchar >>= what->value.unsignedchar;
	}else{
		debug("unsignedchar::Shr where != this");
		new (where) unsignedchar("", (unsigned char) (value.unsignedchar >> what->value.unsignedchar));
	}
}
void signedshort::Shl(variable *where, variable *what){
	error_conditional(!what, "in signedshort::Shl what is NULL");

	if(where == this || !where){
		debug("signedshort::Shl where == this");
		value.signedshort <<= what->value.signedshort;
	}else{
		debug("signedshort::Shl where != this");
		new (where) signedshort("", (signed short) (value.signedshort << what->value.signedshort));
	}
}

void signedshort::Shr(variable *where, variable *what){
	error_conditional(!what, "in signedshort::Shr what is NULL");

	if(where == this || !where){
		debug("signedshort::Shr where == this");
		value.signedshort >>= what->value.signedshort;
	}else{
		debug("signedshort::Shr where != this");
		new (where) signedshort("", (signed short) (value.signedshort >> what->value.signedshort));
	}
}
void unsignedshort::Shl(variable *where, variable *what){
	error_conditional(!what, "in unsignedshort::Shl what is NULL");

	if(where == this || !where){
		debug("unsignedshort::Shl where == this");
		value.unsignedshort <<= what->value.unsignedshort;
	}else{
		debug("unsignedshort::Shl where != this");
		new (where) unsignedshort("", (unsigned short) (value.unsignedshort << what->value.unsignedshort));
	}
}

void unsignedshort::Shr(variable *where, variable *what){
	error_conditional(!what, "in unsignedshort::Shr what is NULL");

	if(where == this || !where){
		debug("unsignedshort::Shr where == this");
		value.unsignedshort >>= what->value.unsignedshort;
	}else{
		debug("unsignedshort::Shr where != this");
		new (where) unsignedshort("", (unsigned short) (value.unsignedshort >> what->value.unsignedshort));
	}
}
void signedint::Shl(variable *where, variable *what){
	error_conditional(!what, "in signedint::Shl what is NULL");

	if(where == this || !where){
		debug("signedint::Shl where == this");
		value.signedint <<= what->value.signedint;
	}else{
		debug("signedint::Shl where != this");
		new (where) signedint("", (signed int) (value.signedint << what->value.signedint));
	}
}

void signedint::Shr(variable *where, variable *what){
	error_conditional(!what, "in signedint::Shr what is NULL");

	if(where == this || !where){
		debug("signedint::Shr where == this");
		value.signedint >>= what->value.signedint;
	}else{
		debug("signedint::Shr where != this");
		new (where) signedint("", (signed int) (value.signedint >> what->value.signedint));
	}
}
void unsignedint::Shl(variable *where, variable *what){
	error_conditional(!what, "in unsignedint::Shl what is NULL");

	if(where == this || !where){
		debug("unsignedint::Shl where == this");
		value.unsignedint <<= what->value.unsignedint;
	}else{
		debug("unsignedint::Shl where != this");
		new (where) unsignedint("", (unsigned int) (value.unsignedint << what->value.unsignedint));
	}
}

void unsignedint::Shr(variable *where, variable *what){
	error_conditional(!what, "in unsignedint::Shr what is NULL");

	if(where == this || !where){
		debug("unsignedint::Shr where == this");
		value.unsignedint >>= what->value.unsignedint;
	}else{
		debug("unsignedint::Shr where != this");
		new (where) unsignedint("", (unsigned int) (value.unsignedint >> what->value.unsignedint));
	}
}
void signedlong::Shl(variable *where, variable *what){
	error_conditional(!what, "in signedlong::Shl what is NULL");

	if(where == this || !where){
		debug("signedlong::Shl where == this");
		value.signedlong <<= what->value.signedlong;
	}else{
		debug("signedlong::Shl where != this");
		new (where) signedlong("", (signed long) (value.signedlong << what->value.signedlong));
	}
}

void signedlong::Shr(variable *where, variable *what){
	error_conditional(!what, "in signedlong::Shr what is NULL");

	if(where == this || !where){
		debug("signedlong::Shr where == this");
		value.signedlong >>= what->value.signedlong;
	}else{
		debug("signedlong::Shr where != this");
		new (where) signedlong("", (signed long) (value.signedlong >> what->value.signedlong));
	}
}
void unsignedlong::Shl(variable *where, variable *what){
	error_conditional(!what, "in unsignedlong::Shl what is NULL");

	if(where == this || !where){
		debug("unsignedlong::Shl where == this");
		value.unsignedlong <<= what->value.unsignedlong;
	}else{
		debug("unsignedlong::Shl where != this");
		new (where) unsignedlong("", (unsigned long) (value.unsignedlong << what->value.unsignedlong));
	}
}

void unsignedlong::Shr(variable *where, variable *what){
	error_conditional(!what, "in unsignedlong::Shr what is NULL");

	if(where == this || !where){
		debug("unsignedlong::Shr where == this");
		value.unsignedlong >>= what->value.unsignedlong;
	}else{
		debug("unsignedlong::Shr where != this");
		new (where) unsignedlong("", (unsigned long) (value.unsignedlong >> what->value.unsignedlong));
	}
}
void signedlonglong::Shl(variable *where, variable *what){
	error_conditional(!what, "in signedlonglong::Shl what is NULL");

	if(where == this || !where){
		debug("signedlonglong::Shl where == this");
		value.signedlonglong <<= what->value.signedlonglong;
	}else{
		debug("signedlonglong::Shl where != this");
		new (where) signedlonglong("", (signed long long) (value.signedlonglong << what->value.signedlonglong));
	}
}

void signedlonglong::Shr(variable *where, variable *what){
	error_conditional(!what, "in signedlonglong::Shr what is NULL");

	if(where == this || !where){
		debug("signedlonglong::Shr where == this");
		value.signedlonglong >>= what->value.signedlonglong;
	}else{
		debug("signedlonglong::Shr where != this");
		new (where) signedlonglong("", (signed long long) (value.signedlonglong >> what->value.signedlonglong));
	}
}
void unsignedlonglong::Shl(variable *where, variable *what){
	error_conditional(!what, "in unsignedlonglong::Shl what is NULL");

	if(where == this || !where){
		debug("unsignedlonglong::Shl where == this");
		value.unsignedlonglong <<= what->value.unsignedlonglong;
	}else{
		debug("unsignedlonglong::Shl where != this");
		new (where) unsignedlonglong("", (unsigned long long) (value.unsignedlonglong << what->value.unsignedlonglong));
	}
}

void unsignedlonglong::Shr(variable *where, variable *what){
	error_conditional(!what, "in unsignedlonglong::Shr what is NULL");

	if(where == this || !where){
		debug("unsignedlonglong::Shr where == this");
		value.unsignedlonglong >>= what->value.unsignedlonglong;
	}else{
		debug("unsignedlonglong::Shr where != this");
		new (where) unsignedlonglong("", (unsigned long long) (value.unsignedlonglong >> what->value.unsignedlonglong));
	}
}
void _float::Shl(variable *where, variable *what){
	error_conditional(!what, "in _float::Shl what is NULL");
	warning("calling << on float variable which is weird");

	if(where == this || !where){
		debug("_float::Shl where == this");
	}else{
		debug("_float::Shl where != this");
		new (where) _float("", (float) (value._float));
	}
}

void _float::Shr(variable *where, variable *what){
	error_conditional(!what, "in _float::Shr what is NULL");
	warning("calling >> on float variable which is weird");

	if(where == this || !where){
		debug("_float::Shr where == this");
	}else{
		debug("_float::Shr where != this");
		new (where) _float("", (float) (value._float));
	}
}
void _double::Shl(variable *where, variable *what){
	error_conditional(!what, "in _double::Shl what is NULL");
	warning("calling << on double variable which is weird");

	if(where == this || !where){
		debug("_double::Shl where == this");
	}else{
		debug("_double::Shl where != this");
		new (where) _double("", (double) (value._double));
	}
}

void _double::Shr(variable *where, variable *what){
	error_conditional(!what, "in _double::Shr what is NULL");
	warning("calling >> on double variable which is weird");

	if(where == this || !where){
		debug("_double::Shr where == this");
	}else{
		debug("_double::Shr where != this");
		new (where) _double("", (double) (value._double));
	}
}
void longdouble::Shl(variable *where, variable *what){
	error_conditional(!what, "in longdouble::Shl what is NULL");
	warning("calling << on long double variable which is weird");

	if(where == this || !where){
		debug("longdouble::Shl where == this");
	}else{
		debug("longdouble::Shl where != this");
		new (where) longdouble("", (long double) (value.longdouble));
	}
}

void longdouble::Shr(variable *where, variable *what){
	error_conditional(!what, "in longdouble::Shr what is NULL");
	warning("calling >> on long double variable which is weird");

	if(where == this || !where){
		debug("longdouble::Shr where == this");
	}else{
		debug("longdouble::Shr where != this");
		new (where) longdouble("", (long double) (value.longdouble));
	}
}

void pointer::Shl(variable *where, variable *what){
	error_conditional(!what, "in pointer::Shl what is NULL");
	warning("pointer << got called which is weird");

	unsigned long long difference = (value.unsignedlonglong << what->value.unsignedlonglong) - value.unsignedlonglong;

	if(where == this || !where){
		debug("pointer::Shl where == this");
		value.unsignedlonglong -= difference;
	}else{
		debug("pointer::Plus where != this");
		new (where) pointer("", type, (unsigned long long) (value.unsignedlonglong - difference), size);
	}
}

void pointer::Shr(variable *where, variable *what){
	error_conditional(!what, "in pointer::Shr what is NULL");
	warning("pointer >> got called which is weird");

	unsigned long long difference = value.unsignedlonglong - (value.unsignedlonglong >> what->value.unsignedlonglong);

	if(where == this || !where){
		debug("pointer::Shl where == this");
		value.unsignedlonglong += difference;
	}else{
		debug("pointer::Plus where != this");
		new (where) pointer("", type, (unsigned long long) (value.unsignedlonglong + difference), size);
	}
}
