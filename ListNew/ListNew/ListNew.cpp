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
	int val;// ������ʱ����û�����Ľڵ��ֵ
	printf("����������Ҫ���ɵ�����ڵ�ĸ�����len = \n");
	scanf("%d",&len);

	PNODE pHead = (PNODE)malloc((sizeof(NODE)));
	if (NULL == pHead)
	{
		printf("����ͷָ��ʧ��,������ֹ��\n");
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
				printf("����ͷָ��ʧ��,������ֹ��\n");
				exit(1);
			}
			/*pTail = pNew->pNext;
			printf("�����뱾�ڵ���Ҫ��������ݣ�");
			scanf("%d", &val);
			pNew->data = val;*/
			printf("�������%d���ڵ��ֵ��", i);
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
		printf("��1�����ϵ�����Ϊ��%d", pNew->data);
		int i = 2;
		while (pNew->pNext != NULL)
		{
			
			printf("��%d�����ϵ�����Ϊ: %d",i,pNew->pNext->data);
				i++;
				pNew = pNew->pNext;
		}   
	}
	else
	{
		printf("��������ǿ�����");
	}
	return;

}
void traverse_list(PNODE pHead)
{
	PNODE pNew = pHead->pNext;
	int j = 1;
	while (NULL != pNew)
	{
		
		printf("����� %d �����������ǣ�%d\n", j, pNew->data);
		j++;
		pNew = pNew->pNext;
	}
	printf("\n");
}


int main(void)
{
	PNODE pHead = NULL;

	pHead = createList(); //����һ����ѭ�������������������ͷ�ڵ�ĵ�ַ�����pHead;
	traverse_list(pHead);
	is_empty(pHead);
	printf("һ����%d������\n", length_list(pHead));
	//sort_list(pHead);
	traverse_list(pHead);
	printf("һ����%d������\n", length_list(pHead));
	insert_listNew(pHead, 1, 5);
	printf("�ڵ�1��λ�ò����5\n");
	printf("һ����%d������\n", length_list(pHead));
	traverse_list(pHead);
	int val;
	int* pVal = &val;
	printf("ȥ�����������Ӻ�������ǣ�\n");
	delete_listNew(pHead, 1, pVal);
	printf("ȥ��������%d\n", val);
	printf("һ����%d������\n", length_list(pHead));
	traverse_list(pHead);
	return 0;
}
bool is_empty(PNODE pHead)
{
	if (NULL == pHead->pNext)
	{
		printf("�������ǿ�����\n");
		return true;
	}
	else
	{
		printf("�������ǿ�����\n");
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
		printf("�������λ�ò����ʣ�����ʧ��");
		return false;
	}
	PNODE pTail = pHead;
	while (pTail->pNext!= NULL)
	{ 
		pTail = pTail->pNext;

	}
	if (NULL == pTail)
	{
		printf("p��null\n");
	}
	PNODE Pnew ;
	Pnew = (PNODE)malloc(sizeof(NODE));
	if (Pnew == NULL)
	{
		printf("����ʧ�ܣ��˳�����");
		return false;
		exit(1);
	}

	len = length_list(pHead);
	printf("û��������ʱ������%d\n", len);
	pTail->pNext = Pnew;
	Pnew->pNext = NULL;

	
	len = length_list(pHead);
	/*printf("û��������ʱ������%d\n", len);
	p = Pnew;
	if (NULL == p)
	{
		printf("p��null\n");
	}
	else
	{
		printf("p�Ѿ�����ֵ\n");
	}
	p->pNext = NULL;*/
	len = length_list(pHead);
	printf("�������ӵ�ʱ�򳤶���%d\n", len);
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
		printf("�������λ�ò�����\n");
		return(false);
	}
	PNODE pNew = (PNODE)malloc(sizeof(NODE));
	if (NULL == pNew)
	{
		printf("����ʧ�ܣ�������ֹ��\n");
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
		printf("�������λ�ò�����\n");
		return false;
	}
	*(val) = p->pNext->data;
	PNODE q = p->pNext;
	p->pNext = p->pNext->pNext;
	free(q);
	q = NULL;
	return true;

}
