#ifndef _LISTCONTAINER_CPP_
#define _LISTCONTAINER_CPP_
#include "ListContainer.hpp"
#include <iostream>
using namespace std;
void ListContainer::print(){
	list <Base*>::iterator it;
	for (it = listcon.begin(); it != listcon.end(); it++)
	{
		Base* a = *it;
		cout << a->stringify() << endl;
	}
}
//void ListContainer::sort(){
//}
void ListContainer::swap(int i, int j){
	//list<Base*>::iterator it1 = listcon.begin();
	//list<Base*>::iterator it2 = listcon.begin();
	//advance(it1, i);
	//advance(it2, j);
	//swap(*it1,*it2);
	list<Base*>::iterator it;
			int counter = 0;
			Base* temp1;
			Base* temp2;
			int counter2 = 0;
			for(it = listcon.begin(); it != listcon.end(); it++)
			{
			if(counter == i)
			{
			temp1 = *it;
			}
		  if(counter == j)
			{
			temp2 = *it;
			}
			counter++;
			counter2++;
			}
			counter = 0;
			counter2 = 0;
			for(it = listcon.begin(); it != listcon.end(); it++)
			{
			if(counter == i)
			{
			*it = temp2;
			}
		  if(counter == j)
			{
			*it = temp1;
			}
			counter++;
			counter2++;
			}
}
Base* ListContainer::at(int i){
	//list<Base*>::iterator it = listcon.begin();
	//return advance(it, i);
	list<Base*>::iterator it;
			int counter = 0;
			for(it = listcon.begin(); it != listcon.end(); it++)
			{
			if(counter == i)
			{
			return *it;
			}
			counter++;
			}
			return *it;
}
#endif
