#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

int main(void)
{
	int score;
	int count;
	int sum = 0;
	double average;
	
	printf("������༶��������\n");
	scanf("%d", &count);
	for ( int i = 0; i < count; i++)
	{
		printf("�������%d��ͬѧ�ķ���\n", i + 1);
		scanf("%d", &score);
		sum = sum + score;
	}
	average = sum / count;
	printf("����༶��ƽ��������:%d", average);

	return;
}