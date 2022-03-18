#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Student
{
	int sid;
	char name[100];
	char sex;
}*PST;

int main(void)
{
	struct Student st;

	PST pst;
	pst = &st;
	pst->sid = 1;
	//strcpy(pst->name,"guangge");
	//strcpy(pst->sex,"M");
	printf("%d", pst->sid);
	

}
