# include<stdio.h>

struct Student 
{
	int sid;
	char name[200];
	int age;
};
void showStruct(struct Student* pst);
void f(struct Student* pst);
int main(void)
{
	  
	struct Student st;
	f(&st);
	
	showStruct(&st);
	return 0;
}
void showStruct(struct Student* pst)
{
	printf("年龄是：%d\n", pst->age);
	printf("同学的编号是：%d\n", pst->sid);
	printf("这个同学的名字是：%s\n", pst->name);
	return;
}
void f(struct Student* pst)
{
	(*pst).age = 15;
	strcpy((pst->name), "xiaohong");
	(*pst).sid = 1;
	return;
}