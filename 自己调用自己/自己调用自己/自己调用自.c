//2022��3��2�� 10��52�� ������
#include <stdio.h>

void f(int n)
{
	if (1 == n)
	{
		printf("����\n");
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