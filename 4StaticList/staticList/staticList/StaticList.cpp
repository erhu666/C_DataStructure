#include "StaticList.h"
int Malloc_SL(StaticList &space)
{
	int i = space[1].cur;
	if (space[1].cur!=0)
	{
		space[1].cur = space[i].cur;
	
	}

	return i;
}

void Free_SL(StaticList& space, int k)
{
	space[k].cur = space[1].cur;
	space[1].cur = k;
}
void InitSlist(StaticList& space)
{
	for (int i = 0; i < Max_Size-1; i++)
	{
		space[i].cur = i + 1;
	}

	space[Max_Size - 1].cur = 0;
	space[0].cur = -1;
}

void Insert(StaticList& space,ElemType x)
{
	int i= Malloc_SL(space);
	if (i==0)
	{
		printf("ÉêÇë½ÚµãÊ§°Ü");
		return;
	}
	space[i].data = x;
	if (space[0].cur==-1)
	{
		space[i].cur = -1;
	}
	else
	{
		space[i].cur = space[0].cur;
	}
	space[0].cur = i;
	
}

void ShowList(StaticList& space)
{
	int i = space[0].cur;
	while (i!=-1)
	{
		printf("%c-->",space[i].data );
		i = space[i].cur;
	}
	printf("Nul.\n");
}

void Delete(StaticList& space)
{
	int i = space[0].cur;
	space[0].cur = space[i].cur;
	Free_SL(space, i);
}
