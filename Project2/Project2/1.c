#include <stdio.h>

void f(int **p);

int main(void)
{
	int i = 9;
	int* p = &i;
	
	printf("%p\n", p);
	f(&p);
	printf("%p\n", p);
	printf("%d\n", i);
	return 0;
}

void f(int **p)
{
	*p = 1;
	//**p = 1;
	return;
}