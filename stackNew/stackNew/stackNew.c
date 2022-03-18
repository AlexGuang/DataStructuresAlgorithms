#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <stdbool.h>

typedef  struct Node
{
	int data;
	struct Node* pNext;
}NODE,*PNODE;

typedef struct stack
{
	PNODE pTop;
	PNODE pBottom;
}STACK,*PSTACK;


void init(PSTACK pS);
void push(PSTACK pS, int val);
bool pop(PSTACK pS ,int *p);
void clear(PSTACK pS);
bool ifEmpty(PSTACK pS);
void traverse(PSTACK pS);


int main(void)
{
	STACK stack;
	PSTACK pS = &stack;
	init(pS);
	traverse(pS);
	push(pS, 1);
	push(pS, 2);
	push(pS, 3);
	push(pS, 41);
	push(pS, 5);
	traverse(pS);
	int val;
	int* pVal = &val;
	pop(pS, pVal);
	traverse(pS);
	clear(pS);
	traverse(pS);

	return 0;
}
void init(PSTACK pS)
{
	pS->pBottom = (PNODE)malloc(sizeof(NODE));
	if (NULL== pS->pBottom)
	{
		printf("�ڴ����ʧ�ܣ�������ֹ\n");
		exit(1);
	}
	else
	{
		pS->pTop = pS->pBottom;
		pS->pTop->pNext = NULL;
	}
	
}

void push(PSTACK pS,int val)
{
	PNODE pNew = (PNODE)malloc(sizeof(NODE));
	if (pNew == NULL)
	{
		printf("�ڴ����ʧ�ܣ������˳�");
		exit(1);
	}
	pNew->pNext = pS->pTop;
	pNew->data = val;
	pS->pTop = pNew;

	printf("�����ڰ�%dѹ��ջ��\n", val);
	return;

}
void traverse(PSTACK pS)
{
	if (ifEmpty(pS))
	{
		printf("���ջ���ǿյģ��޷�����");
	}
	else
	{
		PNODE p;
		p = pS->pTop;
		printf("�����ڿ�ʼ�������ջ��\n");
		while (p != pS->pBottom)
		{
			printf("%d\n", p->data);
			p = p->pNext;
		}
		
	}
	printf("\n");
	return;
}
bool ifEmpty(PSTACK pS)
{
	if (pS->pBottom == pS->pTop)
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool pop(PSTACK pS,int*val)
{
	if (ifEmpty(pS))
	{
		printf("��ջ���޷���ջ\n");
		return false;
	}
	else
	{
		PNODE r = pS->pTop;
		*val = r->data;
		pS->pTop = r->pNext;
		free(r);
		r = NULL;

		printf("�����ڰ�ջ����ջ��\n");

		return true;
	}
}

void clear(PSTACK pS)
{
	if (ifEmpty(pS))
	{
		printf("��ջ�Ѿ������");
		return;
	}
	else
	{
		PNODE p, q;
		q = NULL;
		p = pS->pTop;
		while (p != pS->pBottom)
		{
			q = p->pNext;
			free(p);
			//����p = q->pNext;��ȷ���� ��p = q",��q��ֵ������p;
			p = q;
		}
		pS->pTop = pS->pBottom;
	}
	printf("������Ҫ������ջ��\n");
	return;


}