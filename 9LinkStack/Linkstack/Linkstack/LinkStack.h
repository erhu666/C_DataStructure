#pragma once
#ifndef __LINKSTACK_H_
#define __LINKSTACK_H_
#include<stdio.h>
#include<malloc.h>
#include<assert.h>

#define ElemType int

typedef struct StackNode{
	ElemType data;
	StackNode* next;
}StackNode;
typedef StackNode* LinkStack;
void init(LinkStack* s);
void Push(LinkStack* s, ElemType x);
void Show(LinkStack* s);
void Pop(LinkStack* s);




#endif // !__LINKSTACK_H_
