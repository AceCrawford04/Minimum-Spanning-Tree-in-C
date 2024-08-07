#include <stdio.h>
#include <limits.h>
#include <string.h>
#include <stdbool.h>
#include "vertex.h"
#include "edge.h"
#include "graph.h"
#include "key.h"
#include "tree.h"

void printTree(Keys KeyList, int keyCount){
	int totalWeight = 0;
	for(int x = 0; x < keyCount; x++){
		printf("%s is the child of %s\n", KeyList[x].vertex, KeyList[x].parent);
		totalWeight = totalWeight + KeyList[x].weight;

	}
	printf("The total weight of the tree is:%d \n", totalWeight);
}