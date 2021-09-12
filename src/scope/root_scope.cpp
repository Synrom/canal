
#include <vector>
#include <string>

#include <canal/root_scope.h>
#include <canal/debugger.h>

function *root_scope::findFunction(const std::string &s){
	debug("> root_scope::findFunction");
	
	for(auto fit = functions.begin();fit != functions.end();fit++){

		if((*fit).name == s)
			return & (*fit);

	}

	warning("function was not found in root");	
	return NULL;
}
