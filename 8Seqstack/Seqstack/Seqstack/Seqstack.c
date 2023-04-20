#include"Seqstack.h"
void InitStack(SeqStack* s)
{
	s->base = (ElemType*)malloc(sizeof(ElemType) * STACK_INIT_SIZE);
	assert(s->base != NULL);
	s->capacity = STACK_INIT_SIZE;
	s->top = 0;
}

bool Inc(SeqStack* s)
{
	ElemType* newbase = (ElemType*)realloc(s->base, sizeof(ElemType) * (s->capacity +
		STACK_INIT_SIZE));
	if (newbase==NULL)
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
void Push(SeqStack* s, ElemType x)
{
	if (isFull(s)&&!Inc(s))
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

bool GetTop(SeqStack* s, ElemType* v)
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
	for (int i = s->top; i >=0; --i)
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
