#pragma once
#ifndef __SEQQUEUE_H_
#define __SEQQUEUE_H_

#include <stdio.h>
#include <malloc.h>
#include <assert.h>

#define ElemType int
#define MaxSize 8

typedef struct Queue {
	ElemType* base;
	int front;
	int rear;
}Queue;

void InitQueu(Queue* Q);
void EnQueue(Queue*Q,ElemType x);
void ShowQueu(Queue* Q);
void DeQueue(Queue* Q);
void DeQueue(Queue* Q);
void GetHead(Queue* Q, ElemType* x);
int Length(Queue* Q);
void ClearQueue(Queue* Q);
void DestroyQueue(Queue* Q);




#endif // !__SEQQUEUE_H_

