#include"LinkStack.h"
void init(LinkStack* s)
{
	*s = NULL;
}
void Push(LinkStack* s, ElemType x)
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
	while (p!=NULL)
	{
		printf("%d\n", p->data);
		p = p->next;
	}
	printf("\n");
}