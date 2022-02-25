#include <new>

#include <canal/debugger.h>
#include <canal/operation.h>


void Add::clone(operation *location) const {
	debug("cloning Add operation to %p",location);
	new (location) Add(freference);
}

void Minus::clone(operation *location) const {
	debug("cloning Minus operation to %p",location);
	new (location) Minus(freference);
}

void Divide::clone(operation *location) const {
	debug("cloning Divide operation to %p",location);
	new (location) Divide(freference);
}

void Times::clone(operation *location) const {
	debug("cloning Times operation to %p",location);
	new (location) Times(freference);
}

void Or::clone(operation *location) const {
	debug("cloning Or operation to %p",location);
	new (location) Or(freference);
}

void And::clone(operation *location) const {
	debug("cloning And operation to %p",location);
	new (location) And(freference);
}

void Xor::clone(operation *location) const {
	debug("cloning Xor operation to %p",location);
	new (location) Xor(freference);
}

void Neg::clone(operation *location) const {
	debug("cloning Neg operation to %p",location);
	new (location) Neg(freference);
}

void Dec::clone(operation *location) const {
	debug("cloning Dec operation to %p",location);
	new (location) Dec(freference);
}

void Inc::clone(operation *location) const {
	debug("cloning Inc operation to %p",location);
	new (location) Inc(freference);
}

void Call::clone(operation *location) const {
	debug("cloning Call operation to %p",location);
	new (location) Call(call,freference);
}

void Equal::clone(operation *location) const {
	debug("cloning Equal operation to %p",location);
	new (location) Equal(freference);
}

void Ret::clone(operation *location) const {
	debug("cloning Ret operation to %p",location);
	new (location) Ret(freference);
}

