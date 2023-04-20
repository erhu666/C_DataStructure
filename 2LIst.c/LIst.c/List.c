#include <stdio.h>
#include <assert.h>
#include<malloc.h>
#define ElemType int
typedef struct {
	ElemType data;
	struct ListNode* next;
}ListNode;

typedef ListNode* List;

void initlist(List* head)//head是一个二级指针
{
	*head = (ListNode*)malloc(sizeof(ListNode));
	assert(*head != NULL);
	(*head)->next = NULL;
}
void CreateList(List* head)//带头节点的创建链表
{
	ListNode* p = *head;
	for (int i=0 ; i <= 10; ++i)
	{
		p = p->next = (ListNode*)malloc(sizeof(ListNode));
		assert(p != NULL);
		p->data = i;
		p->next = NULL;
	}
}
void ShowList(List head)
{
	ListNode* p = head->next;
	while (p!=NULL)
	{
		printf(" %d --> ", p->data);
		p = p->next;
	}
	printf(" NUl.\n");
}

void main()
{
	List mylist;
	initlist(&mylist);
	CreateList(&mylist);
	ShowList(mylist);
}