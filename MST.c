//File: MST.c
//Ace Crawford 
//Fall 2023, Transy
//PPL
//MST can take in a max of 1,000 processes

#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include "MST.h"
#include "vertex.h"
#include "edge.h"
#include "graph.h"
#include "key.h"
#include "tree.h"

#define MAX 1000

int main(int argc, char** argv) {

	Graph InputGraph;
	Vertex Root;
	Keys KeyList;
	//bool verbose = false;
	char fileName[20];
	int edgeCount;
	int keyCount;
	bool rootInGraph = false;

	//checking ensure the user entered the correct amount of arguments
	if (argc > 3) {
		printf("Error: Too many command line arguments entered \n");
		printf("MST should take in a file name, and a root \n");
	}

	else if (argc < 3) {
		printf("Error: Not enough command line arguments entered \n");
		printf("MST should take in a file name, and a root \n");
	}

	else{


		strcpy(fileName, argv[1]);

		printf("File name: %s\n", fileName);
	
		strcpy(Root, argv[2]);
		printf("Root of the graph: %s\n", Root);

		edgeCount = makeGraph(fileName, InputGraph);

		keyCount = findVertexes(InputGraph, edgeCount, KeyList);

		rootInGraph = setRoot(keyCount, KeyList, Root);

	if(rootInGraph == false){
		printf("Error: The root: %s is not in the graph.\n", Root);
	}
	else{

		MST(InputGraph, KeyList, edgeCount, keyCount);

		printTree(KeyList, keyCount);
	}

	}

}
