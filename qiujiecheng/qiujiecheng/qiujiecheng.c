//2022��3��2�� 11��00��
#include<stdio.h>


//�ٶ� n��ֵ��1 ���ߴ���1 ��ֵ��
int f(int n)
{
	
	if (n == 1)
	{
		return 1 ;
	}
	else
	{
		return( n * f(n - 1));
	}
}
int g(int n)
{
	int product = n;

	for (int i = n-1; i > 0; i--)
	{
		product = product* i;
	}

	return product;
}

int main(void)
{
	
	printf("�ݹ�ó��Ľ���ǣ�%d\n", f(6));
	printf("ѭ���ó��Ľ���ǣ�%d\n", f(6));


	return 0;
}