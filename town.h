/*
Author: Zhou Yuchao
Date:12/03/2013
Store the information of destination. This is the node of the map_array
*/

#ifndef _TOWN_H
#define _TOWN_H

#include<iostream>
#include<string>
#include "list.h"
#include "node.h"

using namespace std;

class town
{
public:
	list *edges;
	
	//constructor
	town();
	
	//destructor
	~town();
	
	//set the name of the destination
	void setDestinationName(string name);
	
	//set the outgoing vertex in correspoing list
	void setList(int end, float distance, float speed);
	
	//return the name of the destination
	string getDestinationName();
	
	//return the list
	list* getList();
	
	string destinationName;
};
#endif
