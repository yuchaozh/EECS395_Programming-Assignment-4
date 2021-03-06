/*
Author: Zhou Yuchao
Date:12/04/2013
implementation of the min heap
*/


#include "minHeap.h"

minHeap::minHeap(int size)
{
	data = new node[size];
    heapSize = 0;
    arraySize = size;
}

minHeap::~minHeap()
{
	delete[] data;
}

int minHeap::getLeftChildIndex(int nodeIndex)
{
	return 2 * nodeIndex + 1;
}

int minHeap::getRightChildIndex(int nodeIndex)
{
	return 2 * nodeIndex + 2;
}

int minHeap::getParentIndex(int nodeIndex)
{
	return (nodeIndex - 1) / 2;
}

node minHeap::getMinimum()
{
	if (isEmpty())
    	throw string("Heap is empty");
    else
        return data[0];
}

bool minHeap::isEmpty()
{
	return (heapSize == 0);
}

void minHeap::insert(int end, double distance, double speed, double time)
{
	if (heapSize == arraySize)
    	throw string("Heap's underlying storage is overflow");
    else
    {
    	//node* newNode = new node(end, distance, speed);
		heapSize++;
		data[heapSize - 1].destination = end;
		data[heapSize - 1].roadDistance = distance;
		data[heapSize - 1].speed = speed;
		data[heapSize - 1].time = time;
        shiftUp(heapSize - 1);
    }
}

void minHeap::shiftUp(int nodeIndex)
{
	int parentIndex;
	node tmp;
    if (nodeIndex != 0) 
    {
    	parentIndex = getParentIndex(nodeIndex);
        if (data[parentIndex].roadDistance > data[nodeIndex].roadDistance)
        {
        	tmp = data[parentIndex];
            data[parentIndex] = data[nodeIndex];
            data[nodeIndex] = tmp;
            shiftUp(parentIndex);
        }
    }
}

void minHeap::deleteMin()
{
	if (isEmpty())
    	throw string("Heap is empty");
    else 
    {
    	data[0] = data[heapSize - 1];
        heapSize--;
      	if (heapSize > 0)
        	shiftDown(0);
    }
    //return data[0].destination;
}

void minHeap::shiftDown(int nodeIndex)
{
	int leftChildIndex, rightChildIndex, minIndex;
	node tmp;
    leftChildIndex = getLeftChildIndex(nodeIndex);
    rightChildIndex = getRightChildIndex(nodeIndex);
    if (rightChildIndex >= heapSize) 
    {
    	if (leftChildIndex >= heapSize)
        	return;
        else
            minIndex = leftChildIndex;
    } 
    else 
    {
	    if (data[leftChildIndex].roadDistance <= data[rightChildIndex].roadDistance)
        	minIndex = leftChildIndex;
        else
            minIndex = rightChildIndex;
    }
    if (data[nodeIndex].roadDistance > data[minIndex].roadDistance) 
    {
    	tmp = data[minIndex];
        data[minIndex] = data[nodeIndex];
        data[nodeIndex] = tmp;
        shiftDown(minIndex);
    }
}

		
	
