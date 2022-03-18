#include <stdio.h>	

void f( int *p);

int main(void)
{
	
	int i = 10;
	f(&i);
	printf("%d\n", i);
	return 0;

}
void f( int * p)
{

	*p = 3;
}