#include <vector>
#include <string>
#include <utility>

#include <canal/function.h>
#include <canal/debugger.h>

function NULL_Function("NULL");

function::function(const std::string &s): stances(this) {
	
	debug("creating function %s",s.c_str());
	
	name = s;
	current_vstance = stances.add();


}

function::function(function &&mv) : operations(std::move(mv.operations)), stances(this){
	
	debug("moving function %s",mv.name.c_str());

	name = std::move(mv.name);
	lvariables = std::move(mv.lvariables);
	pvariables = std::move(mv.pvariables);
	
	stances = std::move(mv.stances);
	vcontainers = std::move(vcontainers);
	current_vstance = mv.current_vstance;

}

function::~function(){
	debug("destroying function %s",name.c_str());
}

variable* function::findVariable(const std::string &v_name){
	debug("finding function %s",v_name.c_str());

	for(auto i = lvariables.begin();i != lvariables.end(); i++){
		if(i->name == v_name){
			debug("found %s variable in container",v_name.c_str());
			return i;
		}
	}

	for(auto i = pvariables.begin();i != pvariables.end(); i++){
		if(i->name == v_name){
			debug("found %s variable in container",v_name.c_str());
			return i;
		}
	}

	debug("didnt found %s variable in container",v_name.c_str());
	return NULL;

}

