/*
Author: Zhou Yuchao
Date:12/02/2013
In store the location name and the list of each outgoing edges
*/

#ifndef _MAP_H
#define _MAP_H

#include <string>
#include "town.h"

class map
{
public:
	//constructor
	map();
	map(int mapSize);
	//destructor
	~map();
	
	//add destination
	void addDestination(int cellNumber, string name);
	
	//add vertex in the map
	void addVertex(int start, int end, double distance, double speed, double time);
	
	//get the size of the map
	int getMapSize();
	
	int roadsNumber;
	int mapSize;
	town *maps;
};
#endif
