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
	time = 0;
	next = NULL;
}

//constructor
node::node(int end, double distance, double s, double t)
{
	destination = end;
	roadDistance = distance;
	speed = s;
	time = t;
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
void node::setDistance(double distance)
{
	roadDistance = distance;
}

//set the speed
void node::setSpeed(double s)
{
	speed = s;
}

void node::setTime(double t)
{
	time = t;
}

//return the destination
int node::getDestination()
{
	return destination;
}

//return the distance to the destination
double node::getDistance()
{
	return roadDistance;
}

//return the speed
double node::getSpeed()
{
	return speed;
}

double node::getTime()
{
	return time;
}
