#pragma once
#ifndef __SEQSTACK_H_
#define __SEQSTACK_H_
#include <stdio.h>
#include <malloc.h>
#include <assert.h>
#include<stdbool.h>

#define ElemType int
#define STACK_INIT_SIZE 8
#define SATCK_INC_SIZE 3

typedef struct SeqStack {
	ElemType* base;
	int capacity;
	int top;

}SeqStack;


bool Inc(SeqStack* s);
void InitStack(SeqStack* s);
bool isFull(SeqStack* s);
bool IsEmpty(SeqStack* s);

void Push(SeqStack* s, ElemType x);
void Pop(SeqStack* s);
bool GetTop(SeqStack* s, ElemType* v);
void Show(SeqStack* s);
int Length(SeqStack* s);
void Clear(SeqStack* s);
void Destroy(SeqStack* s);




#endif // !__SEQSTACK_H_

