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
	printf("�����ǣ�%d\n", pst->age);
	printf("ͬѧ�ı���ǣ�%d\n", pst->sid);
	printf("���ͬѧ�������ǣ�%s\n", pst->name);
	return;
}
void f(struct Student* pst)
{
	(*pst).age = 15;
	strcpy((pst->name), "xiaohong");
	(*pst).sid = 1;
	return;
}