#include <stdio.h>
#include <limits.h>
#include <string.h>
#include <stdbool.h>
#include "vertex.h"
#include "edge.h"
#include "graph.h"
#include "key.h"
#include "tree.h"

//takes in a graph, the number of edges, and keys, then initilizes keys and returns the number of keys
int findVertexes(Graph InputGraph, int edgeCount, Keys KeyList){
	int n = 0;
	int edgeCount2 = edgeCount;
	edgeCount++;
	for(int x = 0; x < edgeCount; x++){
		bool startflag;
		startflag = inKey(InputGraph[x].start, edgeCount, KeyList);

		if (startflag == false){
			strcpy(KeyList[n].vertex, InputGraph[x].start);
			KeyList[n].weight = INT_MAX;
			KeyList[n].active = 1;
			n++;
		}
	}
	edgeCount2++;

	for(int t = 0; t < edgeCount2; t++){
		bool endflag;
		endflag = inKey(InputGraph[t].end, edgeCount, KeyList);

		if (endflag == false){
			strcpy(KeyList[n].vertex, InputGraph[t].end);
			KeyList[n].weight = INT_MAX;
			KeyList[n].active = 1;
			n++;
		}
	}
return n;
}

//Takes in a vertex, the number of edges in a graph, and Keys, and returns if the vertex is in the key.
bool inKey(Vertex current, int edgeCount, Keys KeyList){
	bool flag = false;
	for(int i = 0; i < edgeCount; i++){
		if (strcmp(current, KeyList[i].vertex) == 0){
			flag = true;
		}
	}
	return flag;
}

//Used for debugging, not implemented in program. Prints out list of keys.
void printKeys(int keyCount, Keys KeyList){
	printf("number of keys: %d\n", keyCount);
	//print out array to check values are correct
	for(int x = 0; x < keyCount; x++){
		printf("vertex: %s\n", KeyList[x].vertex);
		printf("weight: %d\n", KeyList[x].weight);
		printf("parent: %s\n", KeyList[x].parent);
		printf("active: %d\n\n", KeyList[x].active);
	}
}

//takes in keys and the number of keys, and returns if Q is empty
bool Qempty(Keys KeyList, int keyCount){
	bool flag = true;
	for(int x = 0; x < keyCount; x++){
		if(KeyList[x].active == 1){
			flag = false;
		}
	}
	return flag;
}


//takes in keylist and number of keys, returns the index number of the minimum U in Q
int extractMinfromQ(Keys KeyList, int keyCount){
	int min = INT_MAX;
	int minVertex;
	for(int x = 0; x < keyCount; x++){
		if(KeyList[x].active == 1){
		if (KeyList[x].weight < min){
			minVertex = x;
			min = KeyList[minVertex].weight;
		}
	}
	}
	return minVertex;
}

//takes in keys, number of keys, and a vertex. Then returns if that vertex is in Q
bool inQ(Keys KeyList, int keyCount, Vertex vertex){
	bool flag = false;
	for(int x = 0; x < keyCount; x++){
		if( strcmp(vertex, KeyList[x].vertex) == 0){
			if (KeyList[x].active == 1){
			flag = true;
		}
		}
	}
	return flag;
}

//takes in keys, number of keys, and the vertex. Returns the weight of the vertex in keys
int getkeyVweight(Keys KeyList, int keyCount, Vertex V){
	int returnValue;
	for(int i = 0; i < keyCount; i++){
		if( strcmp(V, KeyList[i].vertex) == 0)
			returnValue = KeyList[i].weight;
		}
		return returnValue;
	}

//takes in keys, number of keys, and the vertex. Returns the index number of V in the list keys
int getIndexOfVInKey(Keys KeyList, int keyCount, Vertex V){
	for(int i = 0; i < keyCount; i++){
		if( strcmp(V, KeyList[i].vertex) == 0){
				return i;
		}
	}
}