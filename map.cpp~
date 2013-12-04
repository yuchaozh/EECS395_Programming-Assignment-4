/*
Author: Zhou Yuchao
Date:12/03/2013
Implmentation of the map
*/

#include <string>
#include <iostream>
#include "map.h";

using namespace std;

//constructor
map::map()
{
	mapSize = 0;
	roadsNumber = 0;
	maps = NULL;
}

//constructor
map::map(int size)
{
	mapSize = size;
	maps = new town[mapSize];
}

//destrcutor
map::~map()
{
	delete[] maps;
}

//add destination in the map_array_cell
void map::addDestination(int number, string name)
{
	maps[number].setDestinationName(name);	
}

//add vertex in the adjacent list in the corresponding map_array_cell
void map::addVertex(int start, int end, float distance, float speed)
{
	maps[start].setList(end, distance, speed);
}

//return the size of the map
int map::getMapSize()
{
	return mapSize;
}
























	
