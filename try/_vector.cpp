#include <iostream>
#include <vector>


class c1{
	int v;
};

class c2: public c1{
};


int main(){
	std::vector<int> v;
	v.push_back(1);
	v.push_back(3);
	v.push_back(5);
	for(auto i = v.begin(); i != v.end();i++)
		std::cout << *i << std::endl;

	int l = v[0];
	v[0] = v[2];
	v[2] = l;

	for(auto i = v.begin(); i != v.end();i++)
		std::cout << *i << std::endl;
	
	std::vector<c1> v2;
	v2. v2;
	v2.

	return 0;
}
