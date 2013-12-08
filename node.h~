/*
Author: Zhou Yuchao
Date:12/03/2013
The node of the adjacent list. Also called vertex
*/

#ifndef _NODE_H
#define _NODE_H

class node
{
public:
	//store the index of destination in the array_cell
	int destination;
	//store the distance to the destination
	double roadDistance;
	//store the speed
	double speed;
	double time;
	node *next;

	//constrctor
	node();
	node(int end, double distance, double speed, double time);
	
	//destructor
	~node();
	
	//set the destination
	void setDestination(int end);  
	
	//set the distance to the destination
	void setDistance(double distance); 
	
	//set the speed
	void setSpeed(double s);
	
	void setTime(double t);
	
	//return the destination
	int getDestination();  
	
	//return the distance to the destination
	double getDistance(); 
	
	//return the speed
	double getSpeed();
	
	double getTime();
};
#endif
