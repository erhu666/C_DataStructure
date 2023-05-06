#pragma once
#include <stdio.h>
#include <malloc.h>
#include <assert.h>
#define ElemType char
typedef enum{LINK,THREAD}Tag_Type;
typedef struct BinTreeNode {
	ElemType data;
	struct BinTreeNode* leftchild;
	struct BinTreeNode* rightchild;
	Tag_Type ltag;
	Tag_Type rtag;
}BinTreeNode;
typedef struct BinTree
{
	BinTreeNode* root;
	ElemType refvalue;
}BinTree;

BinTreeNode* _BuyNode(ElemType x);
void InitBinTree(BinTree* bt, ElemType ref);
void CreateBinTree(BinTree* bt, char* str);
void CreateBinTree(BinTree* bt, BinTreeNode*& t, char*& str);
void CreateThread(BinTree* bt);
void CreateThread(BinTreeNode*& t, BinTreeNode*& pre);
///////////////////////////////////////////////////////////////
BinTreeNode* First(BinTree* bt);
BinTreeNode* First(BinTreeNode* t);
BinTreeNode* Last(BinTree* bt);
BinTreeNode* Last(BinTreeNode* t);
BinTreeNode* Next(BinTree* bt, BinTreeNode* cur);
BinTreeNode* Next(BinTreeNode* t, BinTreeNode* cur);
BinTreeNode* Prio(BinTree* bt, BinTreeNode* cur);
BinTreeNode* Prio(BinTreeNode* t, BinTreeNode* cur);
void InOrder(BinTree* bt);
void InOrder(BinTreeNode* t);
BinTreeNode* Search(BinTree* bt, ElemType key);
BinTreeNode* Search(BinTreeNode* t, ElemType key);
BinTreeNode* Parent(BinTree* bt, BinTreeNode* cur);
BinTreeNode* Parent(BinTreeNode* t, BinTreeNode* cur);

