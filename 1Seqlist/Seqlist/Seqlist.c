#include "Seqlist.h"
bool Inc(SeqList* list)//���ӿռ�
{
	ElemType* newbase = (ElemType*)realloc(list->base, sizeof(ElemType) * (list->capacity + INC_SIZE));
	if (newbase==NULL)
	{
		printf("�ռ�����ʧ�ܣ��ڴ治��.\n");
		return false;
	}
	list->base = newbase;
	list->capacity += INC_SIZE;
	return true;
}
void InitSeqList(SeqList* list)//��ʼ��
{
	list->base = (ElemType*)malloc(sizeof(ElemType) * SEQLIST_INIT_SIZE);
	assert(list->base != NULL);
	list->capacity = SEQLIST_INIT_SIZE;
	list->size = 0;
}
void push_back(SeqList* list, ElemType x)//β��
{
	if (list->size >= list->capacity && !Inc(list))
	{
		printf("�ռ����ˣ�����β��");
		return;
	}
	list->base[list->size] = x;
	list->size++;
}

void push_front(SeqList* list, ElemType x)//ͷ��
{
	if (list->size >= list->capacity && !Inc(list))
	{
		printf("˳���ռ��������޷�����.\n");
		return;
	}
	for (int i = list->size; i > 0; --i)
	{
		list->base[i] = list->base[i - 1];
	}
	list->base[0] = x;
	list->size++;
}

void  show_list(SeqList* list)//��ʾ����
{
	for (int i = 0; i < list->size; i++)
	{
		printf("%d", list->base[i]);
	}
	printf("\n");
}


void pop_back(SeqList* list)//βɾ
{
	if (list->size == 0)
	{
		printf("˳���Ϊ�գ��޷�ɾ��.\n");
		return;
	}
	list->size--;//����ֱ�Ӽ����Ϳ���
}

void pop_front(SeqList* list)//ͷɾ
{
	if (list->size==0)
	{
		printf("˳���Ϊ���޷�ɾ��.\n");
		return;
	}
	for (int i = 0; i < list->size - 1; i++)
	{
		list->base[i] = list->base[i + 1];//�Ѻ��������ǰ�ƾͿ���ͷɾ

	}
	list->size--;

}

void insert_pos(SeqList* list, int pos, ElemType x)//��λ�ò�������
{
	if (pos<0 || pos>list->size)
	{
		printf("����λ�÷Ƿ�.\n");
		return;
	}
	if (list->size >= list->capacity && !Inc(list))
	{
		printf("���Ѿ����ˣ��޷�����");
		return;
	}
	for (int i = list->size; i > pos; --i)
	{
		list->base[i] = list->base[i - 1];

	}
	list->base[pos] = x;
	list->size++;
}
int find(SeqList* list, ElemType key)//��������
{
	for (int i = 0; i < list->size; ++i)
	{
		if (list->base[i] == key)
			return i;
	}
	return -1;
}

int length(SeqList* list)//�󳤶�
{
	return list->size;
}

void delete_pos(SeqList* list, int pos)//��λ��ɾ������
{
	if (pos < 0 || pos >= list->size)
	{
		printf("λ�÷Ƿ�������ɾ������.\n");

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
		printf("ɾ�����ݲ�����.\n");
		return;
	}
	delete_pos(list, pos);

}

void sort(SeqList* list)//ð������
{
	for (int i = 0; i < list->size - 1; i++)//�߽������ж�
	{
		for (int j = 0; j < list->size - i - 1; ++j)//�߽������ж�
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

void resver(SeqList* list)//����
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
