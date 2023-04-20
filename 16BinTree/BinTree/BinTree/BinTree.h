#pragma once
#include<stdio.h>
#include<malloc.h>
#include<assert.h>
#include<string.h>
#include<stdbool.h>

#define ElemType char
typedef struct BinTreeNode {
	ElemType data;
	struct BinTreeNode* leftchild;
	struct BinTreeNode* rightchild;

 }BinTreeNode;

typedef struct Bintree
{
	BinTreeNode* root;
	ElemType refvalue;
}Bintree;

void InitBinTree(Bintree* bt, ElemType ref);
////////////////////////
void CreateBintree_1(Bintree* bt);
void CreateBintree_1(Bintree* bt, BinTreeNode** t);

void CreateBintree_2(Bintree* bt);
void CreateBintree_2(Bintree* bt, BinTreeNode*& t);

void CreateBintree_3(Bintree* bt);
BinTreeNode* CreateBintree_3_(Bintree* bt);

void CreateBintree_4(Bintree* bt, char* str);
void CreateBintree_4(Bintree* bt, BinTreeNode*& t, char*& str);

//////////////////////////////////////////////////////////////
void PreOrder(Bintree* bt);
void PreOrder(BinTreeNode* t);

void InOrder(Bintree* bt);
void InOrder(BinTreeNode* t);

void PostOrder(Bintree* bt);
void PostOrder(BinTreeNode* t);

void LevelOrder(Bintree* bt);
void Leve1Order(BinTreeNode* t);
///////////////////////////////////////////////////////////////
int Size(Bintree* bt);
int Size(BinTreeNode* t);

int Height(Bintree* bt);
int Height(BinTreeNode* bt);

BinTreeNode* Search(Bintree* bt, ElemType key);
BinTreeNode* Search(BinTreeNode* t, ElemType key);

BinTreeNode* Parent(Bintree* bt, BinTreeNode* p);
BinTreeNode* Parent(BinTreeNode* t, BinTreeNode* p);

BinTreeNode* LeftChild(BinTreeNode* p);
BinTreeNode* RightChild(BinTreeNode* p);

bool BinTreeEmpty(Bintree* bt);

void Copy(Bintree* bt1, Bintree* bt2);
void Copy(BinTreeNode*& t1, BinTreeNode* t2);

void BinTreeClear(Bintree* bt1);
void BinTreeClear(BinTreeNode*& t);

////////////////////////////////////////////////////////////////
void PreOrder_1(Bintree* bt);
void PreOrder_1(BinTreeNode* t);

void InOrder_1(Bintree* bt);
void InOrder_1(BinTreeNode* t);

void PostOrder_1(Bintree* bt);
void PostOrder_1(BinTreeNode* t);
/////////////////////////////////////////////////////////
//由展开的结果倒推二叉树

void CreteBinTree_5(Bintree* bt, char* VLR, char* LVR, int n);
void CreteBinTree_5(BinTreeNode* bt, char* VLR, char* LVR, int n);
void CreteBinTree_6(Bintree* bt, char* LVR, char* LRV, int n);
void CreteBinTree_6(BinTreeNode* bt, char* LVR, char* LRV, int n);





