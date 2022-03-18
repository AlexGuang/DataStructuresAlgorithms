//2022年3月2日 11点48分
#include <stdio.h>
#pragma warning(disable : 4996)

long hannuotaCount(int n)
{
	if (1 == n)
	{
		return 1;
	}
	else
	{
		return 2 * hannuotaCount(n - 1) + 1;
	}
	
}
void hannuota(int n, char A, char B, char C, int* p)
{
	if (1 == n)
	{
		(*p)++;
		printf("第%d步,我现在把第%d个盘子从%c柱拿到%c柱。\n", *p, n, A, C);

	}
	else
	{
		hannuota(n - 1, A, C, B, p);
		(*p)++;
		printf("第%d步,我现在把第%d个盘子从%c柱拿到%c柱。\n", *p, n, A, C);

		hannuota(n - 1, B, A, C, p);

	}
}
void hannuota2(int n, char A, char C, char B, int* p)
{
	if (1 == n)
	{
		(*p)++;
		printf("第%d步,我现在把第%d个盘子从%c柱拿到%c柱。\n", *p, n, A, B);

	}
	else
	{
		hannuota2(n - 1, A, B, C, p);
		(*p)++;
		printf("第%d步,我现在把第%d个盘子从%c柱拿到%c柱。\n", *p, n, A, B);

		hannuota2(n - 1, C, A, B, p);

	}
}
void hannuota1(int n, char A, char B, char C, int* p)
{
		if (1 == n)
		{
			(*p)++;
			printf("第%d步,我现在把第%d个盘子从%c柱拿到%c柱。\n", *p, n, A, C);

		}
		else
		{
			hannuota1(n - 1, A, C, B, p);
			(*p)++;
			printf("第%d步,我现在把第%d个盘子从%c柱拿到%c柱。\n", *p, n, A, C);

			hannuota1(n - 1, B, A, C, p);

		}


	return;
}
void hannuota4(int n, char A, char B, char C,int *p)
{
	/*
		如果是1个盘子
			直接将A柱子上的盘子从A移到C
		否则
			先将A柱子上的n-1个盘子借助C移到B
			直接将A柱子上的盘子从A移到C
			最后将B柱子上的n-1个盘子借助A移到C
	*/
	if (1 == n)
	{
		(*p)++;
		printf("%d,将编号为%d的盘子直接从%c柱子移到%c柱子\n", *p,n, A, C);
	}
	else
	{
		hannuota4(n - 1, A, C, B,p);
		(*p)++;
		printf("%d,将编号为%d的盘子直接从%c柱子移到%c柱子\n",*p, n, A, C);
		hannuota4(n - 1, B, A, C,p);
	}
}
void hannuota5(int n, char A, char B, char C, int* p);
int main(void)
{
	int b = 0;
	char yes;
	int a;
	int c = 0;
	int d = 0;
	int e = 0;

	printf("请您输入想要移动的盘子数量：\n");
	scanf("%d", &a);
	printf("您这次要移动%ld个盘子\n", hannuotaCount(a));
	/*printf("您是否想看盘子的搬运过程？ 请输入y 或者 n\n");
	scanf(" %c", &yes);
	if (" y" == yes)
	{
		hannuota(a, "a", "b", "c");
		return 0;
	}
	else
	{
		return 0;
	}*/
	//hannuota(a, 'A','B','C',&b);
	printf("\n");
	printf("\n");
	//hannuota2(a, 'A', 'B', 'C', &c);
	printf("\n");
	printf("\n");
	//hannuota1(a, 'A', 'B', 'C', &d);
	printf("\n");
	printf("\n");
	//hannuota4(a, 'A', 'B', 'C', &e);
	

	
}


void hannuota5(int n, char A, char B, char C,int *p)
{
	/*
		如果是1个盘子
			直接将A柱子上的盘子从A移到C
		否则
			先将A柱子上的n-1个盘子借助C移到B
			直接将A柱子上的盘子从A移到C
			最后将B柱子上的n-1个盘子借助A移到C
	*/
	if (1 == n)
	{
		printf("将编号为%d的盘子直接从%c柱子移到%c柱子\n", n, A, C);
	}
	else
	{
		hannuota5(n - 1, A, C, B,p);
		printf("将编号为%d的盘子直接从%c柱子移到%c柱子\n", n, A, C);
		hannuota5(n - 1, B, A, C,p);
	}
}

