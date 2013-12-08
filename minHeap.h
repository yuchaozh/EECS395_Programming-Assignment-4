/*
Author: Zhou Yuchao
Date:12/04/2013
Min Heap
*/

#ifndef _MINHEAP_H
#define _MINHEAP_H

#include <iostream>
#include <string>
#include "node.h"

using namespace std;

class minHeap
{
public:
	minHeap(int size);
	~minHeap();
	bool isEmpty();
	void deleteMin();
	void shiftDown(int nodeIndex);
	void insert(int end, float distance, float speed);
	void shiftUp(int nodeIndex);
	node getMinimum();
	int getLeftChildIndex(int nodeIndex);
	int getRightChildIndex(int nodeIndex);
	int getParentIndex(int nodeIndex);
	
	node* data;
	int arraySize;
	int heapSize;
};
#endif 
