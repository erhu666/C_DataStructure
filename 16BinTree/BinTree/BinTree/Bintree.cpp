#include"BinTree.h"
#include"Queue.h"
#include"Stack.h"

void InitBinTree(Bintree* bt, ElemType ref)
{
	bt->root = NULL;
	bt->refvalue = ref;
}
////////////////////////
void CreateBintree_1(Bintree* bt)
{
	CreateBintree_1(bt, &(bt->root));
}
//递归创建二叉树，用栈画图去走几个循环取理解
void CreateBintree_1(Bintree* bt, BinTreeNode** t)
{
	ElemType Item;
	scanf_s("%c", &Item);
	if (Item==bt->refvalue)
	{
		(*t) = NULL;
	}
	else
	{
		(*t) = (BinTreeNode*)malloc(sizeof(BinTreeNode));
		assert((*t) != NULL);
		(*t)->data = Item;
		CreateBintree_1(bt, &((*t)->leftchild));
		CreateBintree_1(bt, &((*t)->rightchild));
	}
}




void CreateBintree_2(Bintree* bt)
{
	CreateBintree_2(bt, bt->root);
}
void CreateBintree_2(Bintree* bt, BinTreeNode*& t)
{
	ElemType Item;
	scanf_s("%c", &Item);
	if (Item==bt->refvalue)
	{
		t = NULL;
	}
	else
	{
		t = (BinTreeNode*)malloc(sizeof(BinTreeNode));
		assert(t != NULL);
		t->data = Item;
		CreateBintree_2(bt, t->leftchild);
		CreateBintree_2(bt, t->rightchild);
	}
}

void CreateBintree_3(Bintree* bt)
{
	bt->root = CreateBintree_3_(bt);
}
BinTreeNode* CreateBintree_3_(Bintree* bt)
{
	ElemType Item;
	scanf_s("%c", &Item);
	if (Item==bt->refvalue)
	{
		return NULL;
	}
	else
	{
		BinTreeNode* t = (BinTreeNode*)malloc(sizeof(BinTreeNode));
		assert(t != NULL);
		t->data = Item;
		t->leftchild = CreateBintree_3_(bt);
		t->rightchild = CreateBintree_3_(bt);
		return t;
	}
}



void CreateBintree_4(Bintree* bt, char* str)
{
	CreateBintree_4(bt, bt->root, str);

}
void CreateBintree_4(Bintree* bt, BinTreeNode*& t, char*& str)
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
		CreateBintree_4(bt, t->leftchild, ++str);
		CreateBintree_4(bt, t->rightchild, ++str);

	}
}

//////////////////////////////////////////////////////////////
void PreOrder(Bintree* bt)
{
	PreOrder(bt->root);
}
void PreOrder(BinTreeNode* t)
{
	if (t!=NULL)
	{
		printf("%c", t->data);
		PreOrder(t->leftchild);
		PreOrder(t->rightchild);
	}
}

void InOrder(Bintree* bt)
{
	InOrder(bt->root);
}
void InOrder(BinTreeNode* t)
{
	if (t!=NULL)
	{
		InOrder(t->leftchild);
		printf("%c", t->data);
		InOrder(t->rightchild);
	}
}


void PostOrder(Bintree* bt)
{
	PostOrder(bt->root);
}
void PostOrder(BinTreeNode* t)
{
	if (t!=NULL)
	{
		PostOrder(t->leftchild);
		PostOrder(t->rightchild);
		printf("%c", t->data);
	}
}

void LevelOrder(Bintree* bt)
{
	Leve1Order(bt->root);
}
void Leve1Order(BinTreeNode* t)
{
	LinkQueue Q;
	BinTreeNode* v;
	if (t!=NULL)
	{
		
		
		InitQueue(&Q);
		EnQueue(&Q, t);

	}
	while (!QueueIsEmpty(&Q))
	{
		GetHead(&Q, &v);
		DeQueue(&Q);
		printf("%c", v->data);
		if (v->leftchild!=NULL)
		{
			EnQueue(&Q, v->leftchild);
		}
		if (v->rightchild!=NULL)
		{
			EnQueue(&Q, v->rightchild);
		}
	}
}
///////////////////////////////////////////////////////////////
int Size(Bintree* bt)
{
	return Size(bt->root);
}
int Size(BinTreeNode* t)
{
	if (t==NULL)
	{
		return 0;
	}
	else
	{
		return Size(t->leftchild) + Size(t->rightchild) + 1;
	}
}

int Height(Bintree* bt)
{
	return Height(bt->root);
}
int Height(BinTreeNode* t)
{
	if (t==NULL)
	{
		return 0;
	}
	else
	{
		int left_hight = Height(t->leftchild);
		int right_hight = Height(t->rightchild);
		return (left_hight > right_hight ? left_hight : right_hight) + 1;
	}
}

BinTreeNode* Search(Bintree* bt, ElemType key)
{
	return Search(bt->root, key);
}
BinTreeNode* Search(BinTreeNode* t, ElemType key)
{
	if (t==NULL)
	{
		return NULL;
	}
	if (t->data == key)
		return t;
	BinTreeNode* p = Search(t->leftchild, key);
	if (p!=NULL)
	{
		return p;
	}
	return Search(t->rightchild, key);

}


BinTreeNode* Parent(Bintree* bt, BinTreeNode* p)
{
	return Parent(bt->root, p);
}
BinTreeNode* Parent(BinTreeNode* t, BinTreeNode* p)
{
	if (t==NULL||p==NULL)
	{
		return NULL;
	}
	if (t->leftchild==p||t->rightchild==p)
	{
		return t;
	}
	BinTreeNode* q = Parent(t->leftchild, p);
	if (q!=NULL)
	{
		return q;
	}
	return Parent(t->rightchild, p);
}

BinTreeNode* LeftChild(BinTreeNode* p)
{
	if (p!=NULL)
	{
		return p->leftchild;
	}
	return NULL;
}
BinTreeNode* RightChild(BinTreeNode* p)
{
	if (p!=NULL)
	{
		return p->rightchild;

	}
	return NULL;
}

bool BinTreeEmpty(Bintree* bt)
{
	return bt->root == NULL;
}

void Copy(Bintree* bt1, Bintree* bt2)
{
	Copy(bt1->root, bt2->root);
}
void Copy(BinTreeNode*& t1, BinTreeNode* t2)
{
	if (t2==NULL)
	{
		t1 = NULL;
	}
	else
	{
		t1 = (BinTreeNode*)malloc(sizeof(BinTreeNode));
		assert(t1 != NULL);
		t1->data = t2->data;
		Copy(t1->leftchild, t2->leftchild);
		Copy(t1->leftchild, t2->rightchild);
	}

}

void BinTreeClear(Bintree* bt1)
{
	BinTreeClear(bt1->root);
}
void BinTreeClear(BinTreeNode*& t)
{
	if (t!=NULL)
	{
		BinTreeClear(t->leftchild);
		BinTreeClear(t->rightchild);
		free(t);
		t = NULL;
	}
}

//非递归遍历，人都嘛了
////////////////////////////////////////////////////////////////
void PreOrder_1(Bintree* bt)
{
	PreOrder_1(bt->root);

}
void PreOrder_1(BinTreeNode* t)
{
	LinkStack st;
	init(&st);
	BinTreeNode* p;
	Push(&st, t);

}

void InOrder_1(Bintree* bt)
{

}
void InOrder_1(BinTreeNode* t)
{

}

void PostOrder_1(Bintree* bt)
{
	//人嘛了
}
void PostOrder_1(BinTreeNode* t)
{

}
/////////////////////////////////////////////////////////
//由展开的结果倒推二叉树
//由前序和中序恢复二叉树
void CreteBinTree_5(Bintree* bt, char* VLR, char* LVR, int n)
{
	CreteBinTree_5(bt->root, VLR, LVR, n);
}
void CreteBinTree_5(BinTreeNode* t, char* VLR, char* LVR, int n)
{
	if (n==0)
	{
		t = NULL;
	}
	else
	{
		int k = 0;
		while (VLR[0]!=LVR[k])
		{
			k++;
		}
		t = (BinTreeNode*)malloc(sizeof(BinTreeNode));
		assert(t != NULL);
		t->data = LVR[k];
		CreteBinTree_5(t->leftchild, VLR + 1, LVR, k);
		CreteBinTree_6(t->rightchild, VLR + k + 1, LVR + k + 1, n - k - 1);
	}
}
//由中序和后续恢复二叉树
void CreteBinTree_6(Bintree* bt, char* LVR, char* LRV, int n)
{
	CreteBinTree_6(bt->root, LVR, LRV, n);
}
void CreteBinTree_6(BinTreeNode* t, char* LVR, char* LRV, int n)
{
	if (n==0)
	{
		t = NULL;
	}
	else
	{
		int k = 0;
		while (LRV[n-1]!=LVR[k])
		{
			k++;
		}
		t = (BinTreeNode*)malloc(sizeof(BinTreeNode));
		assert(t != NULL);
		t->data = LVR[k];
		CreteBinTree_6(t->rightchild, LVR + k + 1, LRV + k, n - k - 1);
		CreteBinTree_6(t->leftchild, LVR, LRV, k);
	}
}
