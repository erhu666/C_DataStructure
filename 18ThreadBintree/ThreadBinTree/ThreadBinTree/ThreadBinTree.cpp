#include "ThreadBintree.h"

BinTreeNode* _BuyNode(ElemType x)
{
	BinTreeNode* s = (BinTreeNode*)malloc(sizeof(BinTreeNode));
	assert(s != NULL);
	s->data = x;
	s->leftchild = s->rightchild = NULL;
	s->ltag = s->rtag = LINK;
	return s;
}
void InitBinTree(BinTree* bt, ElemType ref)
{
	bt->root = NULL;
	bt->refvalue = ref;
}
void CreateBinTree(BinTree* bt, char* str)
{
	CreateBinTree(bt, bt->root, str);
}
void CreateBinTree(BinTree* bt, BinTreeNode*& t, char*& str)
{
	if (*str==bt->refvalue)
	{
		t = NULL;
	}
	else
	{
		t = _BuyNode(*str);
		CreateBinTree(bt, t->leftchild, ++str);
		CreateBinTree(bt, t->rightchild, ++str);

	}
}
void CreateThread(BinTree* bt)
{
	BinTreeNode* pre = NULL;
	CreateThread(bt->root, pre);
	pre->rightchild = NULL;
	pre->rtag = THREAD;
}
void CreateThread(BinTreeNode*& t, BinTreeNode*& pre)
{
	if (t==NULL)
	{
		return;
	}
	CreateThread(t->leftchild, pre);
	if (t->leftchild==NULL)
	{
		t->ltag = THREAD;
		t->leftchild = pre;

	}
	if (pre!=NULL&&pre->rightchild==NULL)
	{
		pre->rtag = THREAD;
		pre->rightchild = t;
	}
	pre = t;
	CreateThread(t->rightchild, pre);
}
///////////////////////////////////////////////////////////////
BinTreeNode* First(BinTree* bt)
{
	return First(bt->root);
}
BinTreeNode* First(BinTreeNode* t)
{
	if (t==NULL)
	{
		return NULL;
	}
	BinTreeNode* p = t;
	while (p->ltag==LINK)
	{
		p = p->leftchild;
		return p;
	}
}
BinTreeNode* Last(BinTree* bt)
{
	return Last(bt->root);
}
BinTreeNode* Last(BinTreeNode* t)
{
	if (t==NULL)
	{
		return NULL;
	}
	BinTreeNode* p = t;
	while (p->rtag==LINK)
	{
		p = p->rightchild;
	}
	return p;
}
BinTreeNode* Next(BinTree* bt, BinTreeNode* cur)
{
	return Next(bt->root, cur);
}
BinTreeNode* Next(BinTreeNode* t, BinTreeNode* cur)
{
	if (t==NULL||cur==NULL)
	{
		return NULL;
	}
	if (cur->rtag==THREAD)
	{
		return cur->rightchild;
		return First(cur->rightchild);

	}
}
BinTreeNode* Prio(BinTree* bt, BinTreeNode* cur)
{
	return Prio(bt->root, cur);
}
BinTreeNode* Prio(BinTreeNode* t, BinTreeNode* cur)
{
	if (t==NULL||cur==NULL)
	{
		return NULL;
	}
	if (cur->ltag==THREAD)
	{
		return cur->leftchild;
	}
	return Last(cur->leftchild);
}
void InOrder(BinTree* bt)
{
	InOrder(bt->root);
}
void InOrder(BinTreeNode* t)
{
	BinTreeNode* p;
	for (p = First(t); p != NULL; p = Next(t, p))
	{
		printf("%c", p->data);
	}
	printf("\n");
}
BinTreeNode* Search(BinTree* bt, ElemType key)
{
	return Search(bt->root, key);
}
BinTreeNode* Search(BinTreeNode* t, ElemType key)
{
	if (t==NULL)
	{
		return NULL;
	}
	if (t->data==key)
	{
		return t;
	}
	BinTreeNode* p;
	for (p = First(t); p != NULL; p = Next(t, p))
	{
		if (p->data==key)
		{
			return p;
		}
		
	}
	return NULL;

}
BinTreeNode* Parent(BinTree* bt, BinTreeNode* cur)
{
	return Parent(bt->root, cur);

}
BinTreeNode* Parent(BinTreeNode* t, BinTreeNode* cur)
{
	if (t==NULL||cur==NULL)
	{
		return NULL;
	}
	if (t==cur)
	{
		return NULL;
	}
	BinTreeNode* p=NULL;
	if (cur->ltag==THREAD)
	{
		p = cur->leftchild;
		if (p->rightchild==cur)
		{
			return p;
		}
	}
	if (cur->rtag==THREAD)
	{
		if (p->leftchild==cur)
		{
			return p;
		}

	}
	p = First(cur->leftchild);
	p = p->leftchild;
	if (p!=NULL&&p->rightchild==cur)
	{
		return p;
	}
	p = Last(cur->rightchild);
	return p->rightchild;
}