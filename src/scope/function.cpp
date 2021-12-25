#include <vector>
#include <string>
#include <utility>

#include <canal/function.h>
#include <canal/container.h>
#include <canal/debugger.h>

function NULL_Function("NULL");

function::function(const std::string &s): stances(this) {
	
	debug("creating function %s",s.c_str());
	
	name = s;
	current_vstance = stances.add();
	current_vstance->add_new_container();



}

function::function(function &&mv) : operations(std::move(mv.operations)), stances(this){
	
	debug("moving function %s",mv.name.c_str());
	warning("moving function %s, which is not intended usually",mv.name.c_str());

	name = std::move(mv.name);
	pvariables = std::move(mv.pvariables);
	
	stances = std::move(mv.stances);
	vcontainers = std::move(vcontainers);
	current_vstance = mv.current_vstance;

}

function::~function(){
	debug("destroying function %s",name.c_str());
}


