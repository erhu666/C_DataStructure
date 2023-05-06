#pragma once
#include<stdio.h>
#include<malloc.h>
#include<assert.h>
#include<stdlib.h>
#include<stdbool.h>
#define Default_Vertex_Size 10;
#define T char
#define E int
#define MAX_COST 0x7fffffff
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
void InsertEdge(GraphMtx* g, T v1, T v2, E cost);
void RemoveVertex(GraphMtx* g, T v);
void RemoveEdge(GraphMtx* g, T v1, T v2);
void DestroyGraph(GraphMtx* g);
int GetFirstNeighbor(GraphMtx* g, T v);
int GetNextNeighbor(GraphMtx* g, T v, T w);
E GetWeight(GraphMtx* g, int v1, int v2);
void MiniSpanTree_Prim(GraphMtx* g, T vertex);


typedef struct Edge {
	int x;
	int y;
	E cost;
}Edge;

void MiniSpanTree_kruskal(GraphMtx* g);


