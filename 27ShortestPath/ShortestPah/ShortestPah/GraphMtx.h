#pragma once
#pragma once
#include<stdio.h>
#include<malloc.h>
#include<assert.h>
#include<stdbool.h>

#define Default_Vertex_Size 10

#define T char
#define E int
#define MAX_COST 0X7FFFFFFF
typedef struct GraphMtx
{
	int MaxVertices;
	int NumVertices;
	int NumEdges;

	T* VerticesList;
	int** Edge;
}GraphMtx;

void InitGraph(GraphMtx* g);
int GetVertexPos(GraphMtx* g, T v);
void ShowGraph(GraphMtx* g);
void InsertVertex(GraphMtx* g, T v);
void InsertEdge(GraphMtx* g, T v1, T v2);
void RemoveVertex(GraphMtx* g, T v);
void RemoveEdge(GraphMtx* g, T v1, T v2);
void DestroyGraph(GraphMtx* g);
int GetFistNeighbor(GraphMtx* g, T v);
int GetNextNeighbor(GraphMtx* g, T v, T w);

E GetWeight(GraphMtx* g, int v1, int v2);
void ShortestPath(GraphMtx* g,T vertex,E dist[],int path[]);




