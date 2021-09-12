
#include <vector>
#include <string>

#include <canal/function.h>
#include <canal/file.h>
#include <canal/root_scope.h>
#include <canal/debugger.h>


function *file::findFunction(const std::string &s){
	debug("> file::findFunction");

	for(function *fit : functions){
		
		if(fit->name == s)
			return fit;

	}

	debug("> function not found in file trying root");

	if(root != NULL)
		return ((root_scope *)root)->findFunction(s);
	
	error("root von file ist NULL");	
	return NULL;
}



