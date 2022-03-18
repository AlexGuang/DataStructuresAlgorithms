#include <stdio.h>	

void f();
void g();
void k();

void f()
{
	printf("FFFF\n");
	g();
}

void g()
{
	printf("GGGG\n");
	k();
}
void k()
{
	printf("KKKK\n");

}

int main(void) 
{
	f();

	return 0;
}