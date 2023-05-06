#include"Tree.h"
void InitTree(Tree* tree, ElemType ref)
{
	tree->root = NULL;
	tree->refvalue = ref;
}
void CreateTree(Tree* tree, char* str)
{
	CreateTree(tree, tree->root, str);
}
void CreateTree(Tree* tree, TreeNode*& t, char*& str)
{
	if (*str==tree->refvalue)
	{
		t = NULL;
	}
	else
	{
		t = (TreeNode*)malloc(sizeof(TreeNode));
		assert(t != NULL);
		t->data = *str;
		CreateTree(tree, t->fistChild, ++str);
		CreateTree(tree, t->nextChild, ++str);

	}
}
TreeNode* Root(Tree* tree)
{
	return tree->root;
}
TreeNode* FirstChild(Tree* tree)
{
	return FirstChild(tree->root);
}
TreeNode* FirstChild(TreeNode* t)
{
	if (t==NULL)
	{
		return NULL;
	}
	return t->fistChild;
}
TreeNode* NextSibling(Tree* tree)
{
	return NextSibling(tree->root);
}
TreeNode* NextSibling(TreeNode* t)
{
	if (t=NULL)
	{
		return NULL;
	}
	return t->nextChild;
}
TreeNode* Find(Tree* tree, ElemType key)
{
	return Find(tree->root, key);
}
TreeNode* Find(TreeNode* t, ElemType key)
{
	if (t=NULL)
	{
		return NULL;
	}
	if (t->data==key)
	{
		return t;
	}
	TreeNode* p = Find(t->fistChild, key);
	if (p!=NULL)
	{
		return p;
	}
	return Find(t->nextChild, key);

}
TreeNode* Parent(Tree* tree, TreeNode* p)
{
	return Parent(tree->root,p);
}
TreeNode* Parent(TreeNode* t, TreeNode* p)
{
	if (t==NULL||p==NULL||p==t)
	{
		return NULL;
	}
	TreeNode* q = t->fistChild;
	TreeNode* parent;
	while (q!=NULL&&q!=p)
	{
		parent = Parent(q, p);
		if (parent!=NULL)
		{
			return parent;
		}
	}
	if (q != NULL && q == p)
		return t;
	return NULL;
}