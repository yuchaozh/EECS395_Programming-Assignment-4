/*
Author: Zhou Yuchao
Date:12/03/2013
Implementation of the shortest path
*/

#include <iostream>
#include <string>
#include <fstream>
#include <stdio.h>
#include <sstream>
#include <vector>
#include <stdlib.h>
#include <cstring>

#include "map.h"
#include "minHeap.h"
#include "dijkstra.h"

using namespace std;

int recordLine = 0;


//reconstruct the town name
string extracTownName(vector<string> town)
{
	string townName;
	for (int i = 0; i < town.size() - 1; i++)
	{
		townName = townName + town[i] + " ";
	}
	townName = townName + town[town.size() - 1];
	//out<<"townName: "<<townName<<"|"<<endl;
	return townName;
}	
			
		

int main()
{
	/**************deal with the town*****************/
	string line = "";
	string str = "";
	int townSize = 0;
	ifstream townFile;
	int tripStart;
    int tripEnd;
	townFile.open("Program4Fall2013locations.txt");
	vector<string> towns;
	while (getline(townFile, line))
    {
    	vector <string> input;
    	//split the line by space
		istringstream stream(line);    
		while(stream>>str)   
		{  
			input.push_back(str);
		}
		//get the townSize from the input file
		if (input.size() == 1)
		{
			//change string into int
			townSize = atoi(input[0].c_str());
		}
		if (input.size() == 0 || input[0] == "#" || input.size() == 1)
		{
			continue;
		}
		else
		{
			//store towns' name into vector towns
			towns.push_back(extracTownName(input));
		}
    }
    map m(townSize);
    for (int i = 0; i < towns.size(); i++)
    {
    	//cout<<towns[i]<<endl;
    	m.addDestination(i, towns[i]);
    	//cout<<m.maps[i].getDestinationName()<<endl;
    }
    townFile.close();
    
    /**************deal with the segement*****************/
    ifstream segmentsFile;
    int segmentsSize;
    //float 41.00 -> 41
    double segmentsNumber;
	segmentsFile.open("Program4Fall2013segments.txt");
    while (getline(segmentsFile, line))
    {
    	vector<double> segments;
    	vector <string> input;
    	//split the line by space
		istringstream stream(line);    
		while(stream>>str)   
		{  
			input.push_back(str);
		}
		//get the townSize from the input file
		if (input.size() == 1)
		{
			//change string into int
			segmentsSize = atoi(input[0].c_str());
		}
		if (input.size() == 0 || input[0] == "#" || input.size() == 1)
		{
			continue;
		}
		for (int i = 0; i < input.size(); i++)
		{
			segmentsNumber = atof(input[i].c_str());
			segments.push_back(segmentsNumber);
		}
		double times = segments[2]/segments[3];
		m.addVertex(segments[0], segments[1], segments[2], segments[3], (segments[2] / segments[3]));
    }
    segmentsFile.close();
    
    /**************deal with the trip*****************/
    ifstream tripsFile;
    tripsFile.open("Program4Fall2013trips.txt");
    while (getline(tripsFile, line))
    {
    	istringstream stream(line);   
    	vector <string> input; 
		while(stream>>str)   
		{  
			input.push_back(str);
		}
		if (input.size() == 0 || input[0] == "#" || input.size() == 1)
		{
			continue;
		}
		tripStart = atoi(input[0].c_str());
		tripEnd = atoi(input[1].c_str());
		if (input[2] == "D")
		{
			dijkstra d(&m, townSize);
			d.getStart(tripStart, "T", tripEnd);
		}
		
		if (input[2] == "T")
		{
			dijkstra d(&m, townSize);
			d.getStartTime(tripStart, tripEnd);
		}
		cout<<endl;
	}
	tripsFile.close();
}
