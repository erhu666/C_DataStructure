#ifndef __STATICLIST__H_
#define __STATICLIST__H_
#include <stdio.h>
#include <malloc.h>

#define Max_Size 20
#define ElemType char
typedef struct
{
	ElemType data;
	int cur;
}ListNode;

typedef ListNode StaticList[Max_Size];

int Malloc_SL(StaticList&space);//按照引用传递
void Free_SL(StaticList& space, int k);


void InitSlist(StaticList& space);
void Insert(StaticList& space, ElemType x);
void Delete(StaticList& space);
void ShowList(StaticList& space);






#endif // !__STATICLIST__H_
