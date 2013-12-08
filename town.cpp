/*
Author: Zhou Yuchao
Date:12/03/2013
Implement the town (the cell of the array)
*/

#include "town.h"

//constructor
town::town()
{
	edges = new list();
	destinationName = "";
}

//destructor
town::~town()
{
	delete edges;
}

//set the name of the destination in the cell
void town::setDestinationName(string name)
{
	destinationName = name;
}

//set the information of vertex into the adjacent list
void town::setList(int end, double distance, double speed, double time)
{
	edges->insert_at_front(end, distance, speed, time);
}

//return the name of the destination
string town::getDestinationName()
{
	return destinationName;
}

//return the adjacent list
list* town::getList()
{
	return edges;
}
