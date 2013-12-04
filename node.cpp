/*
Author: Zhou Yuchao
Date:12/03/2013
Implementation of the node of the adjacent list. Also called vertex
*/

#include<iostream>
#include<string>
#include "node.h"

//constructor
node::node()
{
	destination = 0;
	roadDistance = 0;
	speed = 0;
	next = NULL;
}

//constructor
node::node(int end, float distance, float s)
{
	destination = end;
	roadDistance = distance;
	speed = s;
	next = NULL;
}

//destructor
node::~node()
{
	
}

//set the destination
void node::setDestination(int end)
{
	destination = end;
}

//set the distance to the destination
void node::setDistance(float distance)
{
	roadDistance = distance;
}

//set the speed
void node::setSpeed(float s)
{
	speed = s;
}

//return the destination
int node::getDestination()
{
	return destination;
}

//return the distance to the destination
float node::getDistance()
{
	return roadDistance;
}

//return the speed
float node::getSpeed()
{
	return speed;
}
