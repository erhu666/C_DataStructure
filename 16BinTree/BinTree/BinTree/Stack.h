#pragma once
#ifndef __LINKSTACK_H_
#define __LINKSTACK_H_
#include<stdio.h>
#include<malloc.h>
#include<assert.h>

#define ET BinTreeNode*

typedef struct StackNode {
	ET data;
	StackNode* next;
}StackNode;

typedef StackNode* LinkStack;
void init(LinkStack* s);
bool IsFull(LinkStack* s);
bool IsEmpty(LinkStack* s);

void Push(LinkStack* s, ET x);
void show(LinkStack* s);
void Pop(LinkStack* s);
bool GetTop(LinkStack* s, ET* v);
int Length(LinkStack* s);
void Clear(LinkStack* s);
void Destroy(LinkStack* s);




#endif // !__LINKSTACK_H_
void init(LinkStack* s)
{
	*s = NULL;
}
void Push(LinkStack* s, ET x)
{
	StackNode* t = (StackNode*)malloc(sizeof(StackNode));
	assert(t != NULL);
	t->data = x;
	if (*s == NULL)
	{
		*s = t;
		t->next = NULL;
	}
	else
	{
		t->next = *s;
		*s = t;
	}

}
void Pop(LinkStack* s)
{
	StackNode* p = *s;
	*s = p->next;
	free(p);
	p = NULL;
}
void show(LinkStack* s)
{
	StackNode* p = *s;
	while (p != NULL)
	{
		printf("%d\n", p->data);
		p = p->next;
	}
	printf("\n");
}
bool IsFull(LinkStack* s)
{

}
bool IsEmpty(LinkStack* s)
{

}
bool GetTop(LinkStack* s, ET* v)
{

}
int Length(LinkStack* s)
{

}
void Clear(LinkStack* s)
{

}
void Destroy(LinkStack* s)
{

}