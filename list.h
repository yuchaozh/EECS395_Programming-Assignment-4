/*
Author: Zhou Yuchao
Date:12/03/2013
The adjacent list.
*/

#ifndef _LIST_H
#define _LIST_H

#include "node.h"

class list
{	
public:
	node * first;
	int listSize;

	//constructor
	list();
	
	//destructor
	~list();
	
	//insert the connection at front
	void insert_at_front(int e, float d, float s);
	
	//get the size of the list
	int getListSize();
	
	//print out the list
	void print();
};
#endif
