#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
#pragma warning(disable:4996)

typedef struct Node 
{
	int data;
	struct Node* pNext;
}NODE,*PNODE;

bool is_empty(PNODE pHead);
int length_list(PNODE pHead);
bool insert_list(PNODE pHead, int pos, int val);
bool delete_list(PNODE, int, int*);
void sort_list(PNODE pHead);
bool insert_listNew(PNODE pHead, int pos, int val);
bool delete_listNew(PNODE pHead, int pos, int *val);

PNODE createList(void)
{
	int len;
	int i;
	int val;// 用来临时存放用户输入的节点的值
	printf("请输入您需要生成的链表节点的个数：len = \n");
	scanf("%d",&len);

	PNODE pHead = (PNODE)malloc((sizeof(NODE)));
	if (NULL == pHead)
	{
		printf("创建头指针失败,程序终止！\n");
		exit(1);
	}
	else

	{
		PNODE pTail = pHead;
		pTail->pNext = NULL;
		//PNODE pTail = pHead->pNext;
				
		for ( i = 1; i <= len; i++)
		{
			PNODE pNew = pTail;
			pNew = (PNODE)malloc((sizeof(NODE)));
			if (NULL == pNew)
			{
				printf("创建头指针失败,程序终止！\n");
				exit(1);
			}
			/*pTail = pNew->pNext;
			printf("请输入本节点需要保存的数据：");
			scanf("%d", &val);
			pNew->data = val;*/
			printf("请输入第%d个节点的值：", i);
			scanf("%d", &val);
			pNew->data = val;
			pTail->pNext = pNew;
			pNew->pNext = NULL;
			pTail = pNew;
		}
		return pHead;
	}
}
//PNODE appendList(PNODE pHead,int data)
//{
//	PNODE pList;
//	pList = pHead->pNext = (PNODE)malloc((sizeof(NODE)));
//	pList->data = data;
//
//}
void traverse_list1(PNODE pHead)
{
	if (pHead->pNext!= NULL)
	{
		PNODE pNew = pHead->pNext;
		printf("第1个链上的数据为：%d", pNew->data);
		int i = 2;
		while (pNew->pNext != NULL)
		{
			
			printf("第%d个链上的数据为: %d",i,pNew->pNext->data);
				i++;
				pNew = pNew->pNext;
		}   
	}
	else
	{
		printf("这个链表是空链表。");
	}
	return;

}
void traverse_list(PNODE pHead)
{
	PNODE pNew = pHead->pNext;
	int j = 1;
	while (NULL != pNew)
	{
		
		printf("链表第 %d 个链的数据是：%d\n", j, pNew->data);
		j++;
		pNew = pNew->pNext;
	}
	printf("\n");
}


int main(void)
{
	PNODE pHead = NULL;

	pHead = createList(); //创建一个非循环单链表，并将该链表的头节点的地址分配给pHead;
	traverse_list(pHead);
	is_empty(pHead);
	printf("一共有%d个链子\n", length_list(pHead));
	//sort_list(pHead);
	traverse_list(pHead);
	printf("一共有%d个链子\n", length_list(pHead));
	insert_listNew(pHead, 1, 5);
	printf("在第1个位置插入个5\n");
	printf("一共有%d个链子\n", length_list(pHead));
	traverse_list(pHead);
	int val;
	int* pVal = &val;
	printf("去掉第三个链子后的链表是：\n");
	delete_listNew(pHead, 1, pVal);
	printf("去掉的数是%d\n", val);
	printf("一共有%d个链子\n", length_list(pHead));
	traverse_list(pHead);
	return 0;
}
bool is_empty(PNODE pHead)
{
	if (NULL == pHead->pNext)
	{
		printf("本链表是空链表！\n");
		return true;
	}
	else
	{
		printf("本链表不是空链表\n");
		return false;
	}
}
int length_list(PNODE pHead)
{
	PNODE p = pHead->pNext;
	int len = 0;
	while (p!= NULL)
	{
		len++;
		p = p->pNext;

	}
	return len;
}
void sort_list(PNODE pHead)
{
	int i = 0;
	int j = 0;
	int t;
	PNODE p, q;
	int len = length_list(pHead);
	for ( i = 0,p = pHead->pNext ; i < len-1; i++, p = p->pNext)
	{
		for ( j = i+1,q = p->pNext; j < len; j++,q = q->pNext)
		{
			if (p->data > q ->data)
			{
				t = p->data;
				p->data = q->data;
				q->data = t;
			}
		}
	}
	return;
}
bool insert_list(PNODE pHead, int pos, int val)
{
	int len = length_list(pHead);
	if (pos<0||pos>len)
	{
		printf("您插入的位置不合适，插入失败");
		return false;
	}
	PNODE pTail = pHead;
	while (pTail->pNext!= NULL)
	{ 
		pTail = pTail->pNext;

	}
	if (NULL == pTail)
	{
		printf("p是null\n");
	}
	PNODE Pnew ;
	Pnew = (PNODE)malloc(sizeof(NODE));
	if (Pnew == NULL)
	{
		printf("插入失败，退出程序");
		return false;
		exit(1);
	}

	len = length_list(pHead);
	printf("没接上链子时长度是%d\n", len);
	pTail->pNext = Pnew;
	Pnew->pNext = NULL;

	
	len = length_list(pHead);
	/*printf("没接上链子时长度是%d\n", len);
	p = Pnew;
	if (NULL == p)
	{
		printf("p是null\n");
	}
	else
	{
		printf("p已经被赋值\n");
	}
	p->pNext = NULL;*/
	len = length_list(pHead);
	printf("接上链子的时候长度是%d\n", len);
	for (int i = len,l = 1; i >pos ; i--,l++)
	{
		
		PNODE p1;
		p1	= pHead->pNext;
		for (int j = 0; j < len-l; j++)
		{
			p1 = p1->pNext;
		}
		PNODE p2;
		p2= pHead->pNext;
		for (int k = 0; k < len - l - 1; k++)
		{
			p2 = p2->pNext;
		}
		p1->data = p2->data;
	}
	PNODE p3;
	p3 = pHead->pNext;
	for (int g = 0; g < pos-1; g++)
	{
		p3 = p3->pNext;
	}
	p3->data = val;
	return true;
}
bool insert_listNew(PNODE pHead, int pos, int val)
{
	int i = 0;
	PNODE p = pHead;
	while (NULL!= p && i<pos - 1 )
	{
		p = p->pNext;
		i++;
	}
	if (p == NULL || i>pos -1)
	{
		printf("您输入的位置不合适\n");
		return(false);
	}
	PNODE pNew = (PNODE)malloc(sizeof(NODE));
	if (NULL == pNew)
	{
		printf("插入失败，程序终止！\n");
		exit(-1);
	}
	pNew->data = val;
	PNODE q = p->pNext;
	p->pNext = pNew;
	pNew->pNext = q;
}
bool delete_listNew(PNODE pHead, int pos, int *val)
{
	
	PNODE p = pHead;
	int i = 0;
	while (p->pNext != NULL && i < pos-1)
	{
		p = p->pNext;
		i++;
	}

	if (p == NULL || i>pos-1 || p->pNext == NULL)
	{
		printf("您输入的位置不合适\n");
		return false;
	}
	*(val) = p->pNext->data;
	PNODE q = p->pNext;
	p->pNext = p->pNext->pNext;
	free(q);
	q = NULL;
	return true;

}
