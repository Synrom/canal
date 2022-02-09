#include <canal/debugger.h>
#include <canal/variable.h>
#include <new>

void signedchar::clone(variable *where){
	debug("cloning %p to %p",this,where);
	new (where) signedchar(this);
}
void unsignedchar::clone(variable *where){
	debug("cloning %p to %p",this,where);
	new (where) unsignedchar(this);
}
void signedshort::clone(variable *where){
	debug("cloning %p to %p",this,where);
	new (where) signedshort(this);
}
void unsignedshort::clone(variable *where){
	debug("cloning %p to %p",this,where);
	new (where) unsignedshort(this);
}
void signedint::clone(variable *where){
	debug("cloning %p to %p",this,where);
	new (where) signedint(this);
}
void unsignedint::clone(variable *where){
	debug("cloning %p to %p",this,where);
	new (where) unsignedint(this);
}
void signedlong::clone(variable *where){
	debug("cloning %p to %p",this,where);
	new (where) signedlong(this);
}
void unsignedlong::clone(variable *where){
	debug("cloning %p to %p",this,where);
	new (where) unsignedlong(this);
}
void signedlonglong::clone(variable *where){
	debug("cloning %p to %p",this,where);
	new (where) signedlonglong(this);
}
void unsignedlonglong::clone(variable *where){
	debug("cloning %p to %p",this,where);
	new (where) unsignedlonglong(this);
}
void _float::clone(variable *where){
	debug("cloning %p to %p",this,where);
	new (where) _float(this);
}
void _double::clone(variable *where){
	debug("cloning %p to %p",this,where);
	new (where) _double(this);
}
void longdouble::clone(variable *where){
	debug("cloning %p to %p",this,where);
	new (where) longdouble(this);
}
void pointer::clone(variable *where){
	debug("cloning %p to %p",this,where);
	new (where) pointer(this);
}
