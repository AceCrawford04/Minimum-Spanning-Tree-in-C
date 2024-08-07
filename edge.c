//File: edge.cpp
//Ace Crawford 
//Fall 2023, Transy
//PPL

#include <stdio.h>
#include <limits.h>
#include <string.h>
#include <stdbool.h>
#include "vertex.h"
#include "edge.h"
#include "graph.h"
#include "tree.h"

int getWeight(Graph InputGraph, int edgeCount, Vertex u, Vertex v){
	int i;
		for(i = 0; i < edgeCount; i++){
		if(strcmp(InputGraph[i].start, u) == 0 && strcmp(InputGraph[i].end, v) == 0) {
				return InputGraph[i].weight;
		}
		if(strcmp(InputGraph[i].end, u) == 0 && strcmp(InputGraph[i].start, v) == 0) {
				return InputGraph[i].weight;

	}
	}
}




