#include <stdio.h>

struct Student
{
	int sid;
	char name[200];
	int age;
	
};//�ֺŲ���ʡ��
int main(void)
{
	struct Student st = { 1000, "zhangsan", 20 };
	printf("%d %s %d\n", st.sid,st.name,st.age);
	return 0;
}