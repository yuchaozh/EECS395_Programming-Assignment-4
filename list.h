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

	//constructor
	list();
	
	//destructor
	~list();
	
	//insert the connection at front
	void insert_at_front(int e, float d, float s);
	
	//print out the list
	void print();
};
#endif
