#include"Stack.h"
#include<stdio.h>
#include<malloc.h>
#include<assert.h>
#include<stdbool.h>
#define ElemType char
typedef struct BinTreeNode {
	ElemType data;
	struct BinTreeNode* leftchild;
	struct BinTreeNode* rightchild;

}BinTreeNode;
typedef struct BinTree {
	BinTreeNode* root;
	ElemType refvalue;
}BinTree;
void InitBinTree(BinTree* bt, ElemType ref);
void CreateBinTree_4(BinTree* bt, char* str);
void CreateBinTree_4(BinTree* bt, BinTreeNode*& t, char*& str);
void PostOrder(BinTree* bt);
void PostOrder(BinTreeNode* t);

////////////////////////////////////////////////////
void InitBinTree(BinTree* bt, ElemType ref)
{
	bt->root = NULL;
	bt->refvalue = ref;

}
void CreateBinTree_4(BinTree* bt, char* str)
{
	CreateBinTree_4(bt, bt->root, str);

}
void CreateBinTree_4(BinTree* bt, BinTreeNode*& t, char*& str)
{
	if (*str==bt->refvalue)
	{
		t = NULL;
	}
	else
	{
		t = (BinTreeNode*)malloc(sizeof(BinTreeNode));
		assert(t != NULL);
		t->data = *str;
		CreateBinTree_4(bt, t->leftchild, ++str);
		CreateBinTree_4(bt, t->rightchild, ++str);

	}
}
void PostOrder(BinTree* bt)
{
	PostOrder(bt->root);
}
void PostOrder(BinTreeNode* t)
{
	if (t!=NULL)
	{
		SeqStack st;
		InitStack(&st);
		BinTreeNode* p;
		StkNode sn;
		do
		{
			while (t != NULL)
			{
				sn.ptr = t;
				sn.tag = L;
				Push(&st, sn);
				t = t->leftchild;
			}
			bool flag = true;
			while (flag&&!IsEmpty(&st))
			{
				GetTop(&st, &sn);
				Pop(&st);
				p = sn.ptr;
				switch (sn.tag)
				{
				case L:
					sn.tag = R;
					Push(&st, sn);
					flag = false;
					t = p->rightchild;
					break;
				case R:
					printf("%c", p->data);
					break;
				}
			}
		} while (!IsEmpty(&st));
	}
}