//File: edge.h
//Ace Crawford 
//Fall 2023, Transy
//PPL
#ifndef EDGE_H
#define EDGE_H

	typedef struct Edge {
		Vertex start;
		Vertex end;
		int weight;
	} Edge;

#include "graph.h"
#include "key.h"

	int getWeight(Graph InputGraph, int edgeCount, Vertex u, Vertex v);


#endif