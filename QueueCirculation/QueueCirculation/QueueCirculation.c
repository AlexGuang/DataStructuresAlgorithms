#include <stdio.h>
#include <malloc.h>
#include <stdbool.h>

typedef struct Queue
{
	int* pBase;
	int front;
	int rear; 
}QUEUE;


void init(QUEUE*);
bool en_queue(QUEUE*, int );
void traverse(QUEUE*);
bool full_queue(QUEUE*);
bool out_queue(QUEUE*, int*);
bool empt_queue(QUEUE*);

int main(void)
{
	QUEUE qQ;
	init(&qQ);
	en_queue(&qQ, 1);
	en_queue(&qQ, 2);
	en_queue(&qQ, 3);
	en_queue(&qQ, 4);
	en_queue(&qQ, 5);
	en_queue(&qQ, 6);
	en_queue(&qQ, 7);
	en_queue(&qQ, 8);
	traverse(&qQ);
	int val;
	int* pVal = &val;
	out_queue(&qQ, pVal);
	out_queue(&qQ, pVal);
	out_queue(&qQ, pVal);
	traverse(&qQ);
	out_queue(&qQ, pVal);
	out_queue(&qQ, pVal);
	out_queue(&qQ, pVal);
	traverse(&qQ);



	return 0;
}
void init(QUEUE* qQ)
{
	qQ->pBase = (int*)malloc((sizeof(int)) * 6);
	if (qQ->pBase == NULL)
	{
		printf("初始化队列失败，程序退出\n	");
		exit(1);
	}
	else
	{
		qQ->front = 0;
		qQ->rear = 0;
	}
}
bool en_queue(QUEUE* q, int val)
{
	if (full_queue(q))
	{
		printf("队列已满，添加元素失败\n");
		return false;
	}
	else
	{
		q->pBase[q->rear] = val;
		q->rear = (q->rear + 1) % 6;
		printf("本次添加的元素是%d,front 是%d,rear是%d,\n", val,q->front,q->rear);
		
	}
	return true;
}
bool full_queue(QUEUE* qQ)
{
	if ((qQ->rear+1)%6 == qQ->front)
	{		
		return true;
	}
	else
	{
		return false;
	}
}
void traverse(QUEUE* qQ)
{
	if (empt_queue(qQ))
	{
		printf("本队列为空\n");
	}
	else
	{
		int i = qQ->front;
		//printf("front是%d", qQ->front);
		//printf("%d\n", qQ->pBase[i]);
		while (i != qQ->rear)
		{
			printf("%d\n", qQ->pBase[i]);
			i = (i + 1)%6;

			
		}
		print("\n");
	}
	return;
}
bool empt_queue(QUEUE* qQ)
{
	if (qQ->front == qQ->rear)
	{
		return true;
	}
	else
	{
		return false;
	}
}
bool out_queue(QUEUE* qQ, int* p)
{
	if (empt_queue(qQ))
	{
		printf("本队列是空队列，无法出队\n");
		return false;
	}
	else
	{
		*p = qQ->pBase[qQ->front];
		qQ->front = (qQ->front + 1) % 6;
		printf("本次出队的数是%d\n", *p);
	}
	return true;
}