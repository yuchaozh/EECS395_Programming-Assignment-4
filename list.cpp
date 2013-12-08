/*
Author: Zhou Yuchao
Date:12/03/2013
Implement the adjacent list. the node in the adjacent list is called vertex = node
*/

#include <string>
#include <iostream>
#include "list.h"

using namespace std;

//constructor
list::list()
{
	first = new node();
	listSize = 0;
	first->next = NULL;
}

//destructor
list::~list()
{	
	node* current;
	while(first)
	{
		current = first->next;
		delete first;
		first = current;
	}
}

//insert the vertex at the front of the adjacent list
void list::insert_at_front(int e, float d, float s)
{
	node* vertex = new node(e, d, s);
	vertex->next = first->next;
	first->next = vertex;
	listSize++;
}

//print out the adjacent list
void list::print()
{
	node* current = first->next;
	while(current)
	{
		cout<<current->getDestination()<<"  "
		<<current->getDistance()<<"  "
		<<current->getSpeed()<<endl;
		current = current->next;
	}
	cout<<endl;
}

int list::getListSize()
{
	return listSize;
}















