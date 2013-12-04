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
	float roadDistance;
	//store the speed
	float speed;
	node *next;

	//constrctor
	node();
	node(int end,float distance, float speed);
	
	//destructor
	~node();
	
	//set the destination
	void setDestination(int end);  
	
	//set the distance to the destination
	void setDistance(float distance); 
	
	//set the speed
	void setSpeed(float s);
	
	//return the destination
	int getDestination();  
	
	//return the distance to the destination
	float getDistance(); 
	
	//return the speed
	float getSpeed();
};
#endif
