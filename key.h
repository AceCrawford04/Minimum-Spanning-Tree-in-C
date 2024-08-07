//File: key.h
//Ace Crawford 
//Fall 2023, Transy
//PPL

#ifndef KEY_H
#define KEY_H

#include <stdbool.h>

#define MAX 1000

	typedef struct Key {
		Vertex vertex;
		int weight; //key
		Vertex parent;
		bool active;
	} Key;

	typedef Key Keys[MAX];
	int findVertexes(Graph InputGraph, int edgeCount, Keys KeyList);

	bool inKey(Vertex current, int edgeCount, Keys KeyList);
	void printKeys(int keyCount, Keys KeyList);
	bool Qempty(Keys KeyList, int keyCount);
	bool inQ(Keys KeyList, int keyCount, Vertex vertex);
	int getkeyVweight(Keys KeyList, int keyCount, Vertex V);
	int getIndexOfVInKey(Keys KeyList, int keyCount, Vertex V);
	int extractMinfromQ(Keys KeyList, int keyCount);



#endif