//File: graph.c
//Ace Crawford 
//Fall 2023, Transy
//PPL
//print graph is for debug purposes, not implemented in program.

#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include "vertex.h"
#include "edge.h"
#include "graph.h"
#include "tree.h"

#define MAX 1000

//Takes in a graph, and a key where the vertexes and root have already been initilized, makes the shortest undirected graph
void MST(Graph InputGraph, Keys KeyList, int edgeCount, int keyCount){
	int weightUV;
		int keyV;
		int indexOfV;
		Vertex v;
		int indexOfMinU;
		bool connected = false;
		int keyCount2 = keyCount;
	while(Qempty(KeyList, keyCount) != true){

		for(int x = 0; x < keyCount; x++){
			indexOfMinU = extractMinfromQ(KeyList, keyCount);
			for(int i = 0; i < edgeCount; i++){
				bool connected = false;

				if(strcmp(KeyList[indexOfMinU].vertex, InputGraph[i].start) == 0 ){// u connected to v
					strcpy(v, InputGraph[i].end);
					connected = true;
				}
				if(strcmp(KeyList[indexOfMinU].vertex, InputGraph[i].end) == 0 ){
					strcpy(v, InputGraph[i].start);
					connected = true;
				}
				if(connected == true){
					if( inQ(KeyList, keyCount, v) == true){//v is in Q
						weightUV = getWeight(InputGraph, edgeCount, KeyList[indexOfMinU].vertex, v);
						keyV = getkeyVweight(KeyList, keyCount, v);
						if(weightUV < keyV){
							indexOfV = getIndexOfVInKey(KeyList, keyCount, v);
							strcpy(KeyList[indexOfV].parent, KeyList[indexOfMinU].vertex);
							KeyList[indexOfV].weight = weightUV;
						}
					}
				}
				}
	KeyList[indexOfMinU].active = 0;
	}
	
}
}

//Takes in a filename and a Graph, and initilizes the graph with the values from the input file
int makeGraph(char * fileName, Graph InputGraph){
	FILE * file;
	file = fopen(fileName, "r");//https://www.tutorialspoint.com/c_standard_library/c_function_fopen.htm

	int response;
	int i = 0;
	int numberOfEdges = 0;
	int edgeCount = 0;
	
	response = fscanf(file, "%s", InputGraph[i].start);
	
	while (response != EOF) {
		//does not work :(
		if (file == NULL) {
			printf("Error: Cannot open file.\n");
		}
		else{
			response = fscanf(file, "%s %d", InputGraph[i].end, &InputGraph[i].weight);
			i++;
			response = fscanf(file, "%s", InputGraph[i].start); 
			edgeCount++;
			}
	}
	return edgeCount;
	}

	//Takes in a graph and the number of edges for that graph
	//Made for debug purposes, not used in actual program, but it does work!
	void printGraph(Graph InputGraph, int edgeCount){
	printf("number of edges: %d\n", edgeCount);
	//print out array to check values are correct
	for(int x = 0; x < edgeCount; x++){
		printf("start: %s\n", InputGraph[x].start);
		printf("end: %s\n", InputGraph[x].end);
		printf("weight: %d\n\n", InputGraph[x].weight);
	}


}


//takes in how many keys there are, keys, and the vertex root, then initilizes the root in keys
bool setRoot(int keyCount, Keys KeyList, Vertex root){
	bool flag = false;
	for(int x = 0; x < keyCount; x++){
		if( strcmp(KeyList[x].vertex, root) == 0){
			flag = true;
			KeyList[x].weight = 0;
			strcpy(KeyList[x].parent, "NULL");
		}
	}
	return flag;
}