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
		printf("内存分配失败，程序终止\n");
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
		printf("内存分配失败，程序退出");
		exit(1);
	}
	pNew->pNext = pS->pTop;
	pNew->data = val;
	pS->pTop = pNew;

	printf("我现在把%d压进栈里\n", val);
	return;

}
void traverse(PSTACK pS)
{
	if (ifEmpty(pS))
	{
		printf("这个栈链是空的，无法遍历");
	}
	else
	{
		PNODE p;
		p = pS->pTop;
		printf("我现在开始遍历这个栈链\n");
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
		printf("空栈，无法出栈\n");
		return false;
	}
	else
	{
		PNODE r = pS->pTop;
		*val = r->data;
		pS->pTop = r->pNext;
		free(r);
		r = NULL;

		printf("我现在把栈顶出栈。\n");

		return true;
	}
}

void clear(PSTACK pS)
{
	if (ifEmpty(pS))
	{
		printf("此栈已经被清空");
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
			//错误p = q->pNext;正确的是 “p = q",把q的值赋给新p;
			p = q;
		}
		pS->pTop = pS->pBottom;
	}
	printf("我现在要清空这个栈链\n");
	return;


}