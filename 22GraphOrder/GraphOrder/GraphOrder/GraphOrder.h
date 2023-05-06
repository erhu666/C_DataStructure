#pragma once
#include <stdio.h>
#include<malloc.h>
#include<assert.h>
#define Default_Vertex_Size 20
#define T char
typedef struct Edge
{
	int dest;
	struct Edge* link;
}Edge;

typedef struct Vertex {
	T data;
	Edge* adj;
}Vertex;
typedef struct GraphLnk {
	int MaxVertices;
	int NumVertices;
	int NumEdges;
	Vertex* NodeTable;
}GraphLnk;
void InitGraph(GraphLnk* g);
int GetVertexPos(GraphLnk* g, T v);

