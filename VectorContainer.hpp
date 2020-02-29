#ifndef _VECTORCONTAINER_H_
#define _VECTORCONTAINER_H_
#include "container.hpp"
#include <vector>
using namespace std;
class VectorContainer : public Container{
private:
	vector<Base*> vectcon;
public:
	VectorContainer(){};
  VectorContainer(Sort* temp){sort_function = temp; }
	void add_element(Base* element){vectcon.push_back(element);}
	void print();
	void sort(){if(sort_function == NULL)throw "No sort function set!"; sort_function->sort(this);}
	void swap(int i, int j);
	Base* at(int i);
	int size(){return vectcon.size();}
};
#endif
