#pragma once
#ifndef __LinkQueue_H_
#define __LinkQueue_H_
#include<stdio.h>
#include<malloc.h>
#include<assert.h>
#include<stdbool.h>
#define ElemType int

typedef struct QueueNode {
	ElemType data;
	struct QueueNode* next;
}QueueNode;

typedef struct LinkQueue {
	QueueNode* front;
	QueueNode* tail;
}LinkQueue;
bool Empty(LinkQueue* Q);
void InitQueue(LinkQueue* Q);
void EnQueue(LinkQueue* Q, ElemType x);
void ShowQueue(LinkQueue* Q);
void DeQueue(LinkQueue* Q);
void GetHead(LinkQueue* Q, ElemType* x);
void Length(LinkQueue* Q);
void ClearQueue(LinkQueue* Q);
void Detroy(LinkQueue* Q);
#endif // !__LinkQueue_H_