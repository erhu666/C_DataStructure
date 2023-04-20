#include "Seqlist.h"
bool Inc(SeqList* list)//增加空间
{
	ElemType* newbase = (ElemType*)realloc(list->base, sizeof(ElemType) * (list->capacity + INC_SIZE));
	if (newbase==NULL)
	{
		printf("空间增加失败，内存不足.\n");
		return false;
	}
	list->base = newbase;
	list->capacity += INC_SIZE;
	return true;
}
void InitSeqList(SeqList* list)//初始化
{
	list->base = (ElemType*)malloc(sizeof(ElemType) * SEQLIST_INIT_SIZE);
	assert(list->base != NULL);
	list->capacity = SEQLIST_INIT_SIZE;
	list->size = 0;
}
void push_back(SeqList* list, ElemType x)//尾插
{
	if (list->size >= list->capacity && !Inc(list))
	{
		printf("空间满了，不能尾插");
		return;
	}
	list->base[list->size] = x;
	list->size++;
}

void push_front(SeqList* list, ElemType x)//头插
{
	if (list->size >= list->capacity && !Inc(list))
	{
		printf("顺序表空间已满，无法插入.\n");
		return;
	}
	for (int i = list->size; i > 0; --i)
	{
		list->base[i] = list->base[i - 1];
	}
	list->base[0] = x;
	list->size++;
}

void  show_list(SeqList* list)//显示函数
{
	for (int i = 0; i < list->size; i++)
	{
		printf("%d", list->base[i]);
	}
	printf("\n");
}


void pop_back(SeqList* list)//尾删
{
	if (list->size == 0)
	{
		printf("顺序表为空，无法删除.\n");
		return;
	}
	list->size--;//这里直接减减就可以
}

void pop_front(SeqList* list)//头删
{
	if (list->size==0)
	{
		printf("顺序表为空无法删除.\n");
		return;
	}
	for (int i = 0; i < list->size - 1; i++)
	{
		list->base[i] = list->base[i + 1];//把后面的数据前移就可以头删

	}
	list->size--;

}

void insert_pos(SeqList* list, int pos, ElemType x)//按位置插入数据
{
	if (pos<0 || pos>list->size)
	{
		printf("插入位置非法.\n");
		return;
	}
	if (list->size >= list->capacity && !Inc(list))
	{
		printf("表已经满了，无法插入");
		return;
	}
	for (int i = list->size; i > pos; --i)
	{
		list->base[i] = list->base[i - 1];

	}
	list->base[pos] = x;
	list->size++;
}
int find(SeqList* list, ElemType key)//查找数据
{
	for (int i = 0; i < list->size; ++i)
	{
		if (list->base[i] == key)
			return i;
	}
	return -1;
}

int length(SeqList* list)//求长度
{
	return list->size;
}

void delete_pos(SeqList* list, int pos)//按位置删除数据
{
	if (pos < 0 || pos >= list->size)
	{
		printf("位置非法，不能删除数据.\n");

	}

	for (int i = pos; i < list->size; ++i)
	{
		list->base[i] = list->base[i + 1];
	}
	list->size--;
}

void delete_val(SeqList* list, ElemType key)
{
	int pos = find(list, key);
	if (pos == -1)
	{
		printf("删除数据不存在.\n");
		return;
	}
	delete_pos(list, pos);

}

void sort(SeqList* list)//冒泡排序
{
	for (int i = 0; i < list->size - 1; i++)//边界条件判断
	{
		for (int j = 0; j < list->size - i - 1; ++j)//边界条件判断
		{
			if (list->base[j] > list->base[j + 1])
			{
				ElemType tmp = list->base[j];
				list->base[j] = list->base[j + 1];
				list->base[j + 1] = tmp;
			}
		}
	}
}

void resver(SeqList* list)//倒置
{
	if (list->size == 0 || list->size == 1)
		return;
	int low = 0;
	int high = list->size - 1;
	ElemType tmp;
	while (low<high)
	{
		tmp = list->base[low];
		list->base[low] = list->base[high];
		list->base[high] = tmp;

		low++;
		high++;
	}
}


void clear(SeqList* list)
{
	list->size = 0;
}

void destroy(SeqList* list)
{
	free(list->base);
	list->base;
	list->capacity = 0;
	list->size = 0;
}

void merge(SeqList* lt, SeqList* la, SeqList* lb)
{
	lt->capacity = la->size + lb->size;
	lt->base = (ElemType*)malloc(sizeof(ElemType) * lt->capacity);
	assert(lt->base != NULL);
	int ia = 0;
	int ib = 0;
	int ic = 0;

	while (ia<la->size&&ib<lb->size)
	{
		if (la->base[ia] < lb->base[ib])
			lt->base[ic++] = la->base[ia++];
		else
		{
			lt->base[ic++] = lb->base[ib++];
		}
	}
	while (ia<la->size)
	{
		lt->base[ic++] = la->base[ia++];

	}
	while (ib < lb->size)
	{
		lt->base[ic++] = lb->base[ib++];
	}
	lt->size = la->size + lb->size;
}
