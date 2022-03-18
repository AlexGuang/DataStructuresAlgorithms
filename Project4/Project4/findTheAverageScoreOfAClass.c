#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

int main(void)
{
	int score;
	int count;
	int sum = 0;
	double average;
	
	printf("请输入班级的人数：\n");
	scanf("%d", &count);
	for ( int i = 0; i < count; i++)
	{
		printf("请输入第%d个同学的分数\n", i + 1);
		scanf("%d", &score);
		sum = sum + score;
	}
	average = sum / count;
	printf("这个班级的平均分数是:%d", average);

	return;
}