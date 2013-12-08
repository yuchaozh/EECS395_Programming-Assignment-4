/*
Author: Zhou Yuchao
Date:12/7/2013
This code is to implement the dijkstra class.
*/

#include <string>
#include <vector>
#include <iostream>
#include "dijkstra.h"
#include "minHeap.h"

using namespace std;

//constructor
dijkstra::dijkstra(map *m, int size)
{
	this->mapOfAssignment=m;
	flag.resize(size);
	distance.resize(size);
	previous.resize(size);
	for (int i = 0; i < flag.size(); i++)
	{
		flag[i] = "F";
	}
	for (int i = 0; i < distance.size(); i++)
	{
		distance[i] = 9999;
	}
}

dijkstra::~dijkstra()
{

}

void dijkstra::getStart(int start, string type, int end)
{
	minHeap heap(30);
	int deletedNodeIndex;
	float shortestDistance;
	for (int i = 0; i < previous.size(); i++)
	{
		previous[i] = start;
	}
	distance[start] = 0;
	heap.insert(start, 0, 0, 0);
	while(heap.isEmpty() == false)
	{
		deletedNodeIndex = heap.getMinimum().destination;
		heap.deleteMin();
		flag[deletedNodeIndex] = "T";
		node* r;
		r = mapOfAssignment->maps[deletedNodeIndex].edges->first->next;
		while(r!=0)
		{
			shortestDistance = distance[deletedNodeIndex] + r->getDistance();
			if ((flag[r->getDestination()] == "F") && (shortestDistance < distance[r->getDestination()]))
			{
				distance[r->getDestination()] = shortestDistance;
				previous[r->getDestination()] = deletedNodeIndex;
				heap.insert(r->getDestination(), shortestDistance, r->getSpeed(), r->getTime());
			}
			r = r->next;
		}
	}
	cout<<endl;
	cout<<"Shortest distance from "<<mapOfAssignment->maps[start].getDestinationName()<<" to "<<mapOfAssignment->maps[end].getDestinationName()<<"."<<endl;
	
	vector<int> sequence;
	int search = previous[end];
	double total;
	sequence.push_back(end);
	sequence.push_back(search);
	while(previous[search] != start)
	{
		sequence.push_back(previous[search]);
		search = previous[search];
	}
	sequence.push_back(start);
	int previousNode;
	cout<<"Start at "<<mapOfAssignment->maps[start].getDestinationName()<<endl;
	for (int i = sequence.size() - 2; i >= 0; i--)
	{
		previousNode = sequence[i + 1];
		cout<<"Continue to: "<<mapOfAssignment->maps[sequence[i]].getDestinationName()<<" ( "<<mapOfAssignment->maps[previousNode].getList()->searchDistance(sequence[i])<<" miles) "<<endl;
		total = total + mapOfAssignment->maps[previousNode].getList()->searchDistance(sequence[i]);
	}
	cout<<"Total distance: "<<total<<" miles"<<endl;
}
	
//time
void dijkstra::getStartTime(int start, int end)
{
	minHeap heap(30);
	int deletedNodeIndex;
	float shortestDistance;
	for (int i = 0; i < previous.size(); i++)
	{
		previous[i] = start;
	}
	distance[start] = 0;
	heap.insert(start, 0, 0, 0);
	while(heap.isEmpty() == false)
	{
		deletedNodeIndex = heap.getMinimum().destination;
		heap.deleteMin();
		flag[deletedNodeIndex] = "T";
		node* r;
		r = mapOfAssignment->maps[deletedNodeIndex].edges->first->next;
		while(r!=0)
		{
			shortestDistance = distance[deletedNodeIndex] + r->getTime();
			if ((flag[r->getDestination()] == "F") && (shortestDistance < distance[r->getDestination()]))
			{
				distance[r->getDestination()] = shortestDistance;
				previous[r->getDestination()] = deletedNodeIndex;
				heap.insert(r->getDestination(), shortestDistance, r->getSpeed(), r->getTime());
			}
			r = r->next;
		}
	}
	cout<<endl;
	cout<<"Shortest driving time from "<<mapOfAssignment->maps[start].getDestinationName()<<" to "<<mapOfAssignment->maps[end].getDestinationName()<<"."<<endl;
	vector<int> sequence;
	int search = previous[end];
	double totalTime;
	sequence.push_back(end);
	sequence.push_back(search);
	while(previous[search] != start)
	{
		sequence.push_back(previous[search]);
		search = previous[search];
	}
	sequence.push_back(start);
	int previousNode;
	cout<<"Start at "<<mapOfAssignment->maps[start].getDestinationName()<<endl;
	for (int i = sequence.size() - 2; i >= 0; i--)
	{
		previousNode = sequence[i + 1];
		double hour = mapOfAssignment->maps[previousNode].getList()->searchTime(sequence[i]);
		int mins = mapOfAssignment->maps[previousNode].getList()->searchTime(sequence[i]) * 60;
		int secs = mapOfAssignment->maps[previousNode].getList()->searchTime(sequence[i]) * 3600 - mins * 60;
		cout<<"Continue to: "<<mapOfAssignment->maps[sequence[i]].getDestinationName()<<" ( "<<mins<<" mins "<<secs<<" secs) "<<endl;
		totalTime = totalTime + hour;
	}
	int totalMins = totalTime * 60;
	int totalSecs = totalTime * 3600 - totalMins* 60;
	cout<<"Total time: "<<totalMins<<" mins "<<totalSecs<<" secs"<<endl;
}
	
	
	
	
	
	
	
	
	
	
	
	
	
	
