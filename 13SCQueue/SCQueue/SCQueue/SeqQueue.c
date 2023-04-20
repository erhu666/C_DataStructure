#include"SeqQueue.h"
void InitQueu(Queue* Q)
{
	Q->base = (ElemType*)malloc(sizeof(ElemType) * MaxSize);
	assert(Q->base != NULL);
	Q->front = Q->rear = 0;
}
void EnQueue(Queue* Q, ElemType x)
{
	if (((Q->rear+1)%MaxSize)==Q->front)
	{
		return;
	}

	Q->base[Q->rear] = x;
	Q->rear = (Q->rear + 1) % MaxSize;
}
void ShowQueu(Queue* Q)
{
	for (int i = Q->front; i != Q->rear;)
	{
		printf("%d", Q->base[i]);
		i = (i + 1) % MaxSize;
	}
	printf("\n");
}

void DeQueue(Queue* Q)
{
	if (Q->front==Q->rear)
	{
		return;
	}
	Q->front = (Q->front + 1) % MaxSize;
}

void GetHead(Queue* Q, ElemType* x)
{
	if (Q->front == Q->rear)
		return;

	*x = Q->base[Q->front];


}

int Length(Queue* Q)
{
	return(Q->rear - Q->front);
}

void ClearQueu(Queue* Q)
{
	Q->front = Q->rear = 0;
}
void DestroyQueu(Queue* Q)
{
	free(Q->base);
	Q->base = NULL;
}

