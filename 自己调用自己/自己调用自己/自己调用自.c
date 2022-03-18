//2022年3月2日 10点52分 李晓光
#include <stdio.h>

void f(int n)
{
	if (1 == n)
	{
		printf("哈哈\n");
	}
	else
	{
		f(n-1);
	}
	
	
}
int main(void)
{
	int n = 10;
	f(n);

	return 0;
}