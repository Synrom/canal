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

void vstance_vector::pop(){
	debug("poping last element of vstance_vector");
	vector.pop_back();
}

vstance::vstance(vstance *p, vcontainer_vector *c, vstance_vector *s): parent(p) , vcontainer_space(c) , stance_space(s){
	debug("creating vstance");
}

void vstance::add_new_container(){
	debug("add new container to stance");
	if(container.size() != 0){
		debug("creating copy of first container");
		vcontainer *first_container = container.front();
		copy_container(first_container);
	}else{
		vcontainer *new_container = vcontainer_space->add();
		error_conditional(!new_container, "vcontainer_vector returned NULL for add");
	
		container.push_back(new_container);
	}

}

void vstance::add_existing_container(vcontainer *c){
	debug("add existing container %p to stance",c);
	container.push_back(c);
	if(parent)
		parent->add_existing_container(c);
}

vcontainer* vstance::copy_container(vcontainer *c){
	debug("copying container to stance");

	vcontainer *new_container = vcontainer_space->add();
	error_conditional(!new_container, "vcontainer_vector returned NULL for add");

	container.push_back(new_container);

	*new_container = *c;
	return new_container;
}

unsigned int vstance::container_quantity(){
	debug("getting container quantity %ld from current vstance",container.size());
	return container.size();
}

vstance *vstance::get_parent(){
	debug("getting parent %p of vstance",parent);
	return parent;
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

void vstance::reset(){
	debug("resetting vstance");
	
	debug("deleting all the stances except mine");
	while(&(stance_space->vector.back()) != this)
		stance_space->pop();

	warning_conditional(stance_space->vector.size() > 1, "stance_space of function after reset is bigger then 1");

	while(children.size() >= 1)
		children.pop_back();


	debug("deleting all containers except the first");
	while(&(vcontainer_space->vector.back()) != container.front())
		vcontainer_space->vector.pop_back();

	while(container.size() > 1)
		container.pop_back();
	
	warning_conditional(vcontainer_space->vector.size() > 1, "stance_space of function after reset is bigger then 1");
	error_conditional(container.front() != &(vcontainer_space->vector.front()), "container.front != &vcontainer.front in stance after reset");
}

void vstance::print(){
	printf("\nVSTANCE STRUCTURE:\n\n");
	print_structure();
	printf("\n");
	for(auto i = container.begin();i != container.end();i++){
		(*i)->print();
		printf("\n");
	}

}

void vstance::print_structure(){
	printf("{%lu,[",container.size());
	for(auto i = children.begin();i != children.end();i++){
		(*i)->print_structure();
		printf(",");
	}
	if(children.size() > 0)
		printf("\b");
	printf("]}");
}

void vstance::add_switches(unsigned int count){
	debug("adding %u switches to vstance",count);

	debug("adding the switches");
	for(int i = 0;i < count;i++){
		children.push_back(stance_space->add(this));
		for(auto ci = container.begin();ci != container.end();ci++)
			children.back()->copy_container(*ci);
	}

	debug("adding container pointers to parent stances");
	auto si = children.rbegin();
	for(int i = 0;i < count;i++,si++){
		for(auto ci = (*si)->container.begin();ci != (*si)->container.end();ci++)
			add_existing_container(*ci);
	}
}

unsigned int vstance::children_size(){
	debug("returning children size %u",children.size());
	return children.size();
}

vstance *vstance::get_child(unsigned int p){
	debug("returning child %p at position %u",children[p],p);
	return children[p];
}

vstance *vstance::get_following_neighbor(){
	debug("getting following neighbor of %p",this);

	error_conditional(!parent, "trying to get neighbor of root vstance");

	unsigned int this_position = 0;
	while(parent->get_child(this_position) != this && this_position <= parent->children_size())
		this_position++;

	error_conditional(this_position >= parent->children_size(), "couldnt find this in parent->children");
	error_conditional(this_position == parent->children_size() - 1, "trying to get neighbor of latest added children of vstance");

	return parent->get_child(this_position + 1);
}














