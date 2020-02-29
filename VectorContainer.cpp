#ifndef _VECTORCONTAINER_CPP_
#define _VECTORCONTAINER_CPP_
#include "VectorContainer.hpp"
#include <iostream>

using namespace std;
void VectorContainer::print(){
	for(int i = 0; i < vectcon.size(); i++)
	{
		cout << vectcon.at(i)->stringify() << endl;
	}
}

//void VectorContainer::sort(){
 //sort_function->sort(this);
//}
void VectorContainer::swap(int i, int j){
	Base* a = vectcon.at(i);
	Base* b = vectcon.at(j);
	Base* c = a; 
	a = b; 
	b = c; 
	vectcon.at(i) = a;
	vectcon.at(j) = b;
}
Base* VectorContainer::at(int i)
{
	return vectcon.at(i);
}
#endif
