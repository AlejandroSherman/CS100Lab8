#ifndef _LISTCONTAINER_HPP_
#define _LISTCONTAINER_HPP_
#include "container.hpp"
#include <list>
using namespace std;
class ListContainer : public Container{
private:
	list<Base*> listcon;
public:
	ListContainer(){};
	ListContainer(Sort* temp){sort_function = temp; }
	void add_element(Base* element){listcon.push_back(element);}
	void print();
	void sort(){if(sort_function == NULL)throw "No sort function set!"; sort_function->sort(this);}
	void swap(int i, int j);
	Base* at(int i);
	int size(){return listcon.size();}
};
#endif
