//2022��3��2�� 11��48��
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
		printf("��%d��,�����ڰѵ�%d�����Ӵ�%c���õ�%c����\n", *p, n, A, C);

	}
	else
	{
		hannuota(n - 1, A, C, B, p);
		(*p)++;
		printf("��%d��,�����ڰѵ�%d�����Ӵ�%c���õ�%c����\n", *p, n, A, C);

		hannuota(n - 1, B, A, C, p);

	}
}
void hannuota2(int n, char A, char C, char B, int* p)
{
	if (1 == n)
	{
		(*p)++;
		printf("��%d��,�����ڰѵ�%d�����Ӵ�%c���õ�%c����\n", *p, n, A, B);

	}
	else
	{
		hannuota2(n - 1, A, B, C, p);
		(*p)++;
		printf("��%d��,�����ڰѵ�%d�����Ӵ�%c���õ�%c����\n", *p, n, A, B);

		hannuota2(n - 1, C, A, B, p);

	}
}
void hannuota1(int n, char A, char B, char C, int* p)
{
		if (1 == n)
		{
			(*p)++;
			printf("��%d��,�����ڰѵ�%d�����Ӵ�%c���õ�%c����\n", *p, n, A, C);

		}
		else
		{
			hannuota1(n - 1, A, C, B, p);
			(*p)++;
			printf("��%d��,�����ڰѵ�%d�����Ӵ�%c���õ�%c����\n", *p, n, A, C);

			hannuota1(n - 1, B, A, C, p);

		}


	return;
}
void hannuota4(int n, char A, char B, char C,int *p)
{
	/*
		�����1������
			ֱ�ӽ�A�����ϵ����Ӵ�A�Ƶ�C
		����
			�Ƚ�A�����ϵ�n-1�����ӽ���C�Ƶ�B
			ֱ�ӽ�A�����ϵ����Ӵ�A�Ƶ�C
			���B�����ϵ�n-1�����ӽ���A�Ƶ�C
	*/
	if (1 == n)
	{
		(*p)++;
		printf("%d,�����Ϊ%d������ֱ�Ӵ�%c�����Ƶ�%c����\n", *p,n, A, C);
	}
	else
	{
		hannuota4(n - 1, A, C, B,p);
		(*p)++;
		printf("%d,�����Ϊ%d������ֱ�Ӵ�%c�����Ƶ�%c����\n",*p, n, A, C);
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

	printf("����������Ҫ�ƶ�������������\n");
	scanf("%d", &a);
	printf("�����Ҫ�ƶ�%ld������\n", hannuotaCount(a));
	/*printf("���Ƿ��뿴���ӵİ��˹��̣� ������y ���� n\n");
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
		�����1������
			ֱ�ӽ�A�����ϵ����Ӵ�A�Ƶ�C
		����
			�Ƚ�A�����ϵ�n-1�����ӽ���C�Ƶ�B
			ֱ�ӽ�A�����ϵ����Ӵ�A�Ƶ�C
			���B�����ϵ�n-1�����ӽ���A�Ƶ�C
	*/
	if (1 == n)
	{
		printf("�����Ϊ%d������ֱ�Ӵ�%c�����Ƶ�%c����\n", n, A, C);
	}
	else
	{
		hannuota5(n - 1, A, C, B,p);
		printf("�����Ϊ%d������ֱ�Ӵ�%c�����Ƶ�%c����\n", n, A, C);
		hannuota5(n - 1, B, A, C,p);
	}
}

