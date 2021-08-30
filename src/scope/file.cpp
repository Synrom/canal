
#include <vector>
#include <string>

#include <canal/function.h>
#include <canal/file.h>
#include <canal/root_scope.h>


function *file::findFunction(const std::string &s){
	for(function *fit : functions){
		
		if(fit->name == s)
			return fit;

	}

	if(root != NULL)
		return ((root_scope *)root)->findFunction(s);
	
	return NULL;
}



