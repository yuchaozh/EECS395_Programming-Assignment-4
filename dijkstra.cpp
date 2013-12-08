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
	//heap(15);
	flag.resize(size);
	distance.resize(size);
	previous.resize(size);
	for (int i = 0; i < flag.size(); i++)
	{
		flag[i] = "F";
		cout<<flag[i]<<"  ";
	}
	cout<<endl;
	for (int i = 0; i < distance.size(); i++)
	{
		distance[i] = 9999;
		cout<<distance[i]<<"  ";
	}
	cout<<endl;
}

dijkstra::~dijkstra()
{

}

void dijkstra::getStart(int start, string type)
{
	minHeap heap(15);
	int deletedNodeIndex;
	float shortestDistance;
	for (int i = 0; i < previous.size(); i++)
	{
		previous[i] = start;
		cout<<previous[i]<<"  ";
	}
	cout<<endl;
	//minHeap heap(m.maps[tripStart].getList()->getListSize());
	distance[start] = 0;
	heap.insert(start, 0, 0);
	cout<<"begin: insert "<<start<<" into heap"<<endl;
	while(heap.isEmpty() == false)
	{
		//cout<<heap.getMinimum().destination<<endl;
		deletedNodeIndex = heap.getMinimum().destination;
		heap.deleteMin();
		//cout<<"deletedNodeIndex: "<<deletedNodeIndex<<endl;
		//cout<<"deletedNodeIndex: "<<deletedNodeIndex<<endl;
		flag[deletedNodeIndex] = "T";
		node* r;
		r = mapOfAssignment->maps[deletedNodeIndex].edges->first->next;
		while(r!=0)
		{
			//cout<<"distance to the node( "<<r->getDestination()<<" ) "<<r->getDistance()<<endl;
			//shortestDistance = distance[deletedNodeIndex] + r->getDistance();
			shortestDistance = distance[deletedNodeIndex] + r->getDistance();
			if ((flag[r->getDestination()] == "F") && (shortestDistance < distance[r->getDestination()]))
			{
				distance[r->getDestination()] = shortestDistance;
				//cout<<"distance changed( "<<r->getDestination()<<" ) "<<shortestDistance<<endl;
				previous[r->getDestination()] = deletedNodeIndex;
				//cout<<"previous changed( "<<r->getDestination()<<" )"<<previous[r->getDestination()]<<endl;
				heap.insert(r->getDestination(), shortestDistance, r->getSpeed());
				//cout<<"insert "<<r->getDestination()<<" into the heap"<<" shortestDistance: "<<shortestDistance<<endl;
				
			}
			r = r->next;
		}
		//cout<<heap.getMinimum().destination<<endl;
	}
	
	
	
	cout<<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"<<endl;
	for (int i = 0; i < flag.size(); i++)
	{
		cout<<"node: "<<i<<"   distance: "<<distance[i]<<"   previous: "<<previous[i]<<"  flag: "<<flag[i]<<endl;
	}
}
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
