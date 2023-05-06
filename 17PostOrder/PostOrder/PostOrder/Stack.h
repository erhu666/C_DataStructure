#pragma once
#ifndef __SEQSTACK_H_
#define __SEQSTACK_H_
#include <stdio.h>
#include <malloc.h>
#include <assert.h>
#include<stdbool.h>

struct BinTreeNode;
typedef enum{L,R}Tag;
typedef struct StkNode {
	BinTreeNode* ptr;
	Tag tag;

}StkNode;

#define STACK_INIT_SIZE 8
#define SATCK_INC_SIZE 3
#define ET StkNode

typedef struct SeqStack {
	ET* base;
	int capacity;
	int top;

}SeqStack;


bool Inc(SeqStack* s);
void InitStack(SeqStack* s);
bool isFull(SeqStack* s);
bool IsEmpty(SeqStack* s);

void Push(SeqStack* s, ET x);
void Pop(SeqStack* s);
bool GetTop(SeqStack* s, ET* v);
void Show(SeqStack* s);
int Length(SeqStack* s);
void Clear(SeqStack* s);
void Destroy(SeqStack* s);




#endif // !__SEQSTACK_H_
void InitStack(SeqStack* s)
{
	s->base = (ET*)malloc(sizeof(ET) * STACK_INIT_SIZE);
	assert(s->base != NULL);
	s->capacity = STACK_INIT_SIZE;
	s->top = 0;
}

bool Inc(SeqStack* s)
{
	ET* newbase = (ET*)realloc(s->base, sizeof(ET) * (s->capacity +
		STACK_INIT_SIZE));
	if (newbase == NULL)
	{
		printf("内存不足，无法申请.\n");
		return false;

	}
	s->base = newbase;
	s->capacity += SATCK_INC_SIZE;
	return true;

}

bool isFull(SeqStack* s)
{
	return s->top >= s->capacity;
}
bool IsEmpty(SeqStack* s)
{
	return  s->top == 0;
}
void Push(SeqStack* s, ET x)
{
	if (isFull(s) && !Inc(s))
	{
		printf("栈已满");
		return;
	}
	s->base[s->top++] = x;

}
void Pop(SeqStack* s)
{
	if (IsEmpty(s))
	{
		printf("栈已经空");
		return;

	}

	s->top--;
}

bool GetTop(SeqStack* s, ET* v)
{
	if (IsEmpty(s))
	{
		printf("栈空，不能取元素");
		return;
	}
	*v = s->base[s->top - 1];
	return true;
}
void Show(SeqStack* s)
{
	for (int i = s->top; i >= 0; --i)
	{
		printf("%d\n", s->base[i]);
	}
	printf("\n");
}

int Length(SeqStack* s)
{
	return s->top;
}
void Clear(SeqStack* s)
{
	s->top = 0;
}
void Destroy(SeqStack* s)
{
	free(s->base);
	s->base = NULL;
	s->capacity = s->top = 0;
}


