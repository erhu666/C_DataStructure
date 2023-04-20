#include "Slist.h"
void initList(List*list)
{
	list->fist = list->last = (Node*)malloc(sizeof(Node));
	assert(list->fist != NULL);
	list->fist->next = NULL;
	list->size = 0;
}
void push_back(List* list, ElemType x)
{
	Node* s = (Node*)malloc(sizeof(Node));
	assert(s != NULL);
	s->data = x;
	s->next = NULL;


	list->last->next = s;
	list->last = s;
	list->size++;
}

void push_front(List* list, ElemType x)
{
	Node* s = (Node*)malloc(sizeof(Node));
	assert(s != NULL);
	s->data = x;
	
	s->next = list->fist->next;
	list->fist->next = s;
	if (list->size==0)
	{
		list->last = s;
	}
	list->size++;
}


void show_list(List* list)
{
	Node* p = list->fist->next;
	while (p!=NULL)
	{
		printf("%d-->", p->data);
		p = p->next;

	}
	printf("NUll \n");
}
void pop_back(List* list)
{
	if (list->size == 0)
	{
		return;
	}
	Node* p = list->fist;
	while (p->next!=list->last)
	{
		p = p->next;
	}
	free(list->last);
	list->last = p;
	list->last->next = NULL;
	list->size--;
}

void pop_front(List* list)
{
	if (list->size == 0)
	{
		return;
	}
	Node* p = list->fist->next;
	list->fist->next = p->next;
	free(p);
	if (list->size == 1)
	{
		list->last = list->fist;
	}
	list->size--;
}

void insert_val(List* list, ElemType x)
{
	Node* s = (Node*)malloc(sizeof(Node));
	assert(s != NULL);
	s->data = x;
	s->next = NULL;

	Node* p = list->fist;
	
	while (p->next!=NULL&& p->next->data<x)
	{
		p = p->next;
	}

	s->next = p->next;
	p->next = s;
	list->size++;



}

Node* find(List* list, ElemType Key)
{
	Node* p = list->fist->next;
	while (p!=NULL&&p->data!=Key)
	{
		p->next;
	}
	return p;
}
int length(List* list)
{
	return list->size;
}

void delete_val(List* list, ElemType key)
{
	if (list->size==0)
	{
		return;
	}

	Node* p = find(list, key);
	if (p==NULL)
	{
		printf("ɾ�����ݲ�����");
		return;
	}

	if (p==list->last)
	{
		pop_back(list);
	}
	else
	{
		Node* q = p->next;
		p->data = q->data;
		p->next = q->next;
		free(q);
		list->size--;
	}


}

void sort(List* list)
{
	if (list->size == 0 || list->size == 1)
	{
		return;
	}
	Node* s = list->fist->next;
	Node* q = s->next;

	list->last = s;
	list->last->next = NULL;


	while (q!=NULL)
	{
		s = q;
		q = q->next;

		Node* p = list->fist;
		while (p->next!=NULL&&p->next->data<s->data)
		{
			p = p->next;
		}
		if (p->next==NULL)
		{
			list->last = s;
		}

		s->next = p->next;
		p->next = s;
	}

}

void resver(List* list)
{
	if (list->size == 0 || list->size == 1)
	{
		return;
	}
	Node* p = list->fist->next;
	Node* q = p->next;
	list->last = p;
	list->last->next = NULL;


	while (q!=NULL)
	{
		p = q;
		q = p->next;

		p->next = list->fist->next;
		list->fist->next = p;

	}
}

void clear(List* list)
{
	if (list->size == 0)
	{
		return;
	}
	Node* p = list->fist->next;
	while (p!=NULL)
	{
		list->fist->next = p->next;
		free(p);
		p = list->fist->next;
	}

	list->last = list->fist;
	list->size = 0;

}

void destroy(List* list)
{
	clear(list);
	free(list->fist);
	list->fist = list->last = NULL;


}

Node* _BuyNode(ElemType x)
{
	Node* s = (Node*)malloc(sizeof(Node));
	assert(s != NULL);
	s->data = x;
	s->next = NULL;
	return s;
}

It begin(List* list)
{
	return list->fist->next;
}
It end(List* list)
{
	return list->last->next;

}

void insert(List* list, It pos, ElemType x)
{
	Node* p = list->fist;
	while (p->next!=pos)
	{
		p = p->next;
	}
	Node* s = _BuyNode(x);
	s->next = p->next;
	p->next = s;
	if (pos == NULL)
	{
		list->last = s;

	}
	list->size++;
}

