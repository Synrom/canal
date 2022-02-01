#include <vector>
#include <string>

#include <canal/variable.h>
#include <canal/container.h>
#include <canal/debugger.h>
#include <canal/function.h>

vcontainer *vcontainer_vector::add(){
	debug("adding vcontainer to vcontainer_vector");
	vector.emplace_back();
	return &(vector.back());
}

vstance *vstance_vector::add(){
	debug("adding vstance to vstance_vector");
	vector.emplace_back((vstance *)NULL, &(freference->vcontainers), &(freference->stances));
	return &(vector.back());
}

vstance *vstance_vector::add(vstance *parent){
	debug("adding vstance to vstance_vector");
	vector.emplace_back(parent, &(freference->vcontainers), &(freference->stances));
	return &(vector.back());
}

vstance_vector::vstance_vector(function *f){
	debug("creating vstance vector");
	freference = f;
}

vstance::vstance(vstance *p, vcontainer_vector *c, vstance_vector *s): parent(p) , vcontainer_space(c) , stance_space(s){
	debug("creating vstance");
}

void vstance::add_new_container(){
	debug("add new container to stance");
	container.push_back(vcontainer_space->add());
}

void vstance::add_existing_container(vcontainer *c){
	debug("add existing container %p to stance",c);
	container.push_back(c);
}

vcontainer* vstance::copy_container(vcontainer *c){
	debug("copying container to stance");

	vcontainer *new_container = vcontainer_space->add();
	error_conditional(!new_container, "vcontainer_vector returned NULL for add");

	container.push_back(new_container);

	*new_container = *c;
	return new_container;
}




void vstance::add_var(const std::string &s, signed char v){
	debug("adding %s to vstance",s.c_str());
	for(auto i = container.begin();i != container.end();i++)
		(*i)->emplace_back(s,v);
}

void vstance::add_var(const std::string &s, unsigned char v){
	debug("adding %s to vstance",s.c_str());
	for(auto i = container.begin();i != container.end();i++)
		(*i)->emplace_back(s,v);
}

void vstance::add_var(const std::string &s, signed short v){
	debug("adding %s to vstance",s.c_str());
	for(auto i = container.begin();i != container.end();i++)
		(*i)->emplace_back(s,v);
}

void vstance::add_var(const std::string &s, unsigned short v){
	debug("adding %s to vstance",s.c_str());
	for(auto i = container.begin();i != container.end();i++)
		(*i)->emplace_back(s,v);
}

void vstance::add_var(const std::string &s, signed int v){
	debug("adding %s to vstance",s.c_str());
	for(auto i = container.begin();i != container.end();i++)
		(*i)->emplace_back(s,v);
}

void vstance::add_var(const std::string &s, unsigned int v){
	debug("adding %s to vstance",s.c_str());
	for(auto i = container.begin();i != container.end();i++)
		(*i)->emplace_back(s,v);
}

void vstance::add_var(const std::string &s, signed long v){
	debug("adding %s to vstance",s.c_str());
	for(auto i = container.begin();i != container.end();i++)
		(*i)->emplace_back(s,v);
}

void vstance::add_var(const std::string &s, unsigned long v){
	debug("adding %s to vstance",s.c_str());
	for(auto i = container.begin();i != container.end();i++)
		(*i)->emplace_back(s,v);
}

void vstance::add_var(const std::string &s, signed long long v){
	debug("adding %s to vstance",s.c_str());
	for(auto i = container.begin();i != container.end();i++)
		(*i)->emplace_back(s,v);
}

void vstance::add_var(const std::string &s, unsigned long long v){
	debug("adding %s to vstance",s.c_str());
	for(auto i = container.begin();i != container.end();i++)
		(*i)->emplace_back(s,v);
}

void vstance::add_var(const std::string &s, unsigned long long v, unsigned int size){
	debug("adding %s to vstance",s.c_str());
	for(auto i = container.begin();i != container.end();i++)
		(*i)->emplace_back(s,v,size);
}

void vstance::add_var(const std::string &s, float v){
	debug("adding %s to vstance",s.c_str());
	for(auto i = container.begin();i != container.end();i++)
		(*i)->emplace_back(s,v);
}

void vstance::add_var(const std::string &s, double v){
	debug("adding %s to vstance",s.c_str());
	for(auto i = container.begin();i != container.end();i++)
		(*i)->emplace_back(s,v);
}

void vstance::add_var(const std::string &s, long double v){
	debug("adding %s to vstance",s.c_str());
	for(auto i = container.begin();i != container.end();i++)
		(*i)->emplace_back(s,v);
}

std::vector<variable *> vstance::get_var(const std::string &name){

	debug("finding %s in vstance",name.c_str());	

	std::vector<variable *> result;

	auto i = container.begin();
	int position = (*i)->find(name);

	error_conditional(position < 0,"vcontainer->find returned negative position");

	for(i = container.begin();i != container.end();i++){

		result.emplace_back((*i)->get_pointer(position));
		error_conditional((result.back())->name != name,"vcontainer has the variable %s at the position for %s", (result.back())->name.c_str(), name.c_str() );

	}

	return result;
}

variable *vstance::get_latest_added_var(){
	debug("getting latest added var from vstance");
	auto ret = container.front()->last();
	return *ret;
}
