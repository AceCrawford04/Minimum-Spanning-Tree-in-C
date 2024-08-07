//File: graph.h
//Ace Crawford 
//Fall 2023, Transy
//PPL

#ifndef GRAPH_H
#define GRAPH_H

#define MAX 1000

typedef Edge Graph[MAX];

#include "key.h"
#include "vertex.h"

#define GRAPH_H


int makeGraph(char * fileName, Graph Inputgraph);
void printGraph(Graph InputGraph, int edgeCount);
bool setRoot(int keyCount, Keys KeyList, Vertex root);
void MST(Graph InputGraph, Keys KeyList, int edgeCount, int keyCount);

#endif