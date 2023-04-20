#include"Dclist.h"
Node* _Buynode(ElemType x)
{
	Node* s = (Node*)malloc(sizeof(Node));
	assert(s != NULL);
	s->data = x;
	s->next = s->prio = NULL;
	return  s;
}
void initDClist(List* list)
{
	Node* s = (Node*)malloc(sizeof(Node));
	assert(s != NULL);
	list->fist = list->last = s;
	list->fist->prio = list->last;
	list->last->next = list->fist;
	list->size = 0;
}
void push_back(List* list, ElemType x)
{
	Node* s = _Buynode(x);
	s->next = list->last->next;
	s->next->prio = s;
	s->prio = list->last;
	list->last->next = s;

	list->last = s;
	list->size++;
}

void push_front(List* list, ElemType x)
{
	Node* s = _Buynode(x);
	s->next = list->fist->next;
	s->next->prio = s;
	s->prio = list->fist;
	list->fist->next = s;

	if (list->fist==list->last)
	{
		list->last = s;
	}
	list->size++;
}

void show_list(List* list)
{
	Node* p = list->fist->next;
	while (p!=list->fist)
	{
		printf("%d-->", p->data);
		p = p->next;
	}
	printf("Nul.\n");
}
void pop_back(List* list)
{
	if (list->size==0)
	{
		return 0;
	}
	Node* p = list->last;
	list->last = list->last->prio;

	p->next->prio = p->prio;
	p->prio->next = p->next;
	free(p);
	list->size--;
}

void pop_front(List* list)
{
	if (list->size==0)
	{
		return;
	}
	Node* p = list->fist->next;
	p->next->prio = p->prio;
	p->prio->next = p->next;

	if (list->size==1)
	{
		list->last = list->fist;

	}
	list->size--;
}

void insert_val(List* list, ElemType x)
{
	Node* p = list->fist;
	while (p->next!=list->last&&p->next->data<x)
	{
		p = p->next;

	}
	if (p->next == list->last && p->next->data < x)
	{
		push_back(list, x);
	}
	else
	{
		Node* s = _Buynode(x);
		s->next = p->next;
		s->next->prio = s;
		s->prio = p;
		s->next = s;
		list->size++;
	}
}
Node* find(List* list, ElemType x)
{
	Node* p = list->fist->next;
	while (p!=list->fist&&p->data!=key)
	{
		p = p->next;
	}
	if (p == list->fist)
	{
		return NULL;
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
	if (p=NULL)
	{
		printf("删除数据不存在");
		return;
	}
	if (p==list->last)
	{
		pop_back(list);
	}
	else
	{
		p->next->prio = p->prio;
		p->prio->next = p->next;
		free(p);
		list->size--;
	}


}
void sort(List* list)
{
	if (list->size==0||list->size==1)
	{
		return;
	}
	Node* s = list->fist->next;
	Node* q = s->next;
	list->last->next = NULL;
	list->last = s;
	list->last->next = list->fist;
	list->fist->prio = list->last;

	while (q!=NULL)
	{
		s = q;
		q = q->next;

		Node* p = list->fist;

		while (p->next!=list->last&&p->next->data<s->data)
		{
			p = p->next;
		}
		if (p->next==list->last&&p->next->data<s->data)
		{
			s->next = list->last->next;
			s->next->prio = s;
			s->prio = list->last;
			list->last->next = s;
			list->last = s;
		}
		else
		{
			s->next = p->next;
			s->next->prio = s;
			s->prio = p;
			p->next = s;
		}
	}
}
void resver(List* list)
{
	if (list->size==0||list->size==1)
	{
		return;
	}
	Node* p = list->fist->next;
	Node* q = p->next;
	list->last->next = NULL;
	list->last = p;
	list->last->next = list->fist;
	list->fist->prio = list->last;

	while (q!=NULL)
	{
		p = q;
		q = q->next;

		p->next = list->fist->next;
		p->next->prio = p;
		p->prio = list->fist;
		list->fist->next;
	}
}

void clear(List* list)
{
	if (list->size==0)
	{
		return;
	}
	Node* p = list->fist->next;
	while (p!=list->fist)
	{
		p->next->prio = list->fist;
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