//2022年3月2日 11点00分
#include<stdio.h>


//假定 n的值是1 或者大于1 的值；
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
	
	printf("递归得出的结果是：%d\n", f(6));
	printf("循环得出的结果是：%d\n", f(6));


	return 0;
}