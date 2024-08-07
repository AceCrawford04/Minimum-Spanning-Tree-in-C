MST: MSTdriver.o graph.o edge.o vertex.o key.o tree.o
	g++ MSTdriver.o graph.o edge.o vertex.o key.o tree.o -o MST

MSTdriver: MSTdriver.c
	g++ -c MSTdriver.c -o MSTdriver

edge: edge.c edge.h 
	g++ -c edge.c -o edge

graph: graph.c graph.h
	g++ -c graph.c -o graph

key: key.c key.h 
	g++ -c key.c -o key

tree: tree.c tree.h 
	g++ -c tree.c -o tree
