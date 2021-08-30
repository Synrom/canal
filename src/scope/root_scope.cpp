
#include <vector>
#include <string>

#include <canal/root_scope.h>

function *root_scope::findFunction(const std::string &s){
	
	for(auto fit = functions.begin();fit != functions.end();fit++){

		if((*fit).name == s)
			return & (*fit);

	}

	return NULL;
}
