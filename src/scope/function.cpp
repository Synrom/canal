#include <vector>
#include <string>
#include <utility>

#include <canal/function.h>
#include <canal/container.h>
#include <canal/debugger.h>
#include <canal/operation.h>

function NULL_Function("NULL");

function::function(const std::string &s): stances(this) {
	
	debug("creating function %s",s.c_str());
	
	name = s;
	current_vstance = stances.add();
	current_vstance->add_new_container();

	locals.set_identifier(&identifier);
	results.set_identifier(&identifier);


}

function::function(function &&mv) : operations(std::move(mv.operations)), 
	stances(this), results(std::move(mv.results)), identifier(std::move(mv.identifier)), locals(std::move(mv.locals)){
	
	debug("moving function %s",mv.name.c_str());
	warning("moving function %s, which is not intended usually",mv.name.c_str());

	name = std::move(mv.name);
	pvariables = std::move(mv.pvariables);
	
	stances = std::move(mv.stances);
	vcontainers = std::move(vcontainers);
	current_vstance = mv.current_vstance;
	
	locals.set_identifier(&identifier);
	results.set_identifier(&identifier);

}

function::~function(){
	debug("destroying function %s",name.c_str());
}

void function::print(){
	printf("\nprinting function %s(",name.c_str());
	for(auto i = pvariables.begin();i != pvariables.end();i++)
		printf("%s, ",(*i).c_str());
	printf("){\n");
	operations.reset();
	operation *next;
	while((next = operations.getNext()) != NULL)
		next->print();
	operations.reset();
	printf("}\n\n");
	
}

void function::print_simple(){
	printf("\nprinting function %s(",name.c_str());
	for(auto i = pvariables.begin();i != pvariables.end();i++)
		printf("%s, ",(*i).c_str());
	printf("){\n");
	operations.reset();
	operation *next;
	while((next = operations.getNext()) != NULL)
		next->print_simple();
	operations.reset();
	printf("}\n\n");
	
}
