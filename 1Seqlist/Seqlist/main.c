#include "Seqlist.h"
void main()
{
	SeqList mylist;
	InitSeqList(&mylist);
	ElemType Item;
	int pos;
	int select = 1;
	while (select)
	{
		printf("*********************************************\n");
		printf("*[1]  push_back           [2] push_fornt   *\n");
		printf("*[3]  show_list           [4] pop_back     *\n");
		printf("*[5]  pop_front           [6] insert_pos   *\n");
		printf("*[7]  find                [8] lenght       *\n");
		printf("*[9]  delete_pos          [10] delete_val  *\n");
		printf("*[11] sort                [12] resver      *\n");
		printf("*[13] clear               [14] destroy     *\n");
		printf("*[0]  quit_system                          *\n");
		printf("*********************************************\n");
		printf("请选择：>");
		scanf_s("%d", &select);
		if (select==0)
		{
			break;
		}
		switch (select)
		{
		case 1:
			printf("请输入要插入的数据(-1结束)：>");
			while (scanf_s("%d",&Item),Item!=-1)
			{
				push_back(&mylist,Item);
			}
	
			break;
		case 2:
			printf("请输入要插入的数据(-1结束)：>");
			while (scanf_s("%d", &Item), &Item != -1)
			{
				push_front(&mylist, Item);
			}
			break;
		case 3:
			show_list(&mylist);
			break;
		case 4:
			pop_back(&mylist);
			break;
		case 5:
			pop_front(&mylist);
			break;
		case 6:
			printf("请输入要插入的数据.\n");
			scanf_s("%d", &Item);
			printf("输入要插入的位置.\n");
			scanf_s("%d", &pos);
			insert_pos(&mylist, pos, Item);
			break;
		case 7:
			printf("请输入要查找的数据.\n");
			scanf_s("%d", &Item);
			pos = find(&mylist, Item);
			if (pos == -1)
				printf("查找的数据不存在.\n");
			else
			{
				printf("数据%d在%d", Item, pos);
			}
			break;
		case 8:
			printf("顺序表的长度为%d\n", length(&mylist));
			break;
		case 9:
			printf("输入删除数据的位置");
			scanf_s("%d", &pos);
			delete_pos(&mylist, pos);
			break;
		case 10:
			printf("输入删除数据");
			scanf_s("%d", &Item);
			delete_pos(&mylist, Item);
			break;
		case 11:
			sort(&mylist);
			break;
		case 12:
			resver(&mylist);
			break;
		case 13:
			clear(&mylist);
			break;
		default:
			printf("输入错误，重新输入");
		}




	}
}