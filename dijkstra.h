/*
Author: Zhou Yuchao
Date:12/7/2013
This is just the header file for the functions implemented in dijkstra.cpp
*/

#ifndef _DIJKSTRA_H
#define _DIJKSTRA_H

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include <vector>
#include "map.h"
#include "minHeap.h"

class dijkstra
{
public:
	vector<string> flag;
	vector<float> distance;
	vector<int> previous;
	map *mapOfAssignment;
	//minHeap heap;
	
	//constructor
	dijkstra(map *m, int townSize);
	~dijkstra();

	//judge the destination is know or unknow
	bool isKnown(int *knownArr, int arrayLength);
	//update the distance between the destination
	void updateDistance(int destination,int* distanceArr,int* knownArr);
	//return the nearest destination
	int getNearest(int start,int* distanceArr,int* knownArr);
	//return the shortest path
	//int* getPath(int start);
	void getStart(int start, string type);
};

#endif 
