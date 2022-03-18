#include	<stdio.h>
/*
2022��3��8�� 13��37�֣����������˫ָ���������
�˴���˫ָ����������±꣬��������ָ��

*/

void fastSort(int* pa, int c,int b)
{
	
	int pos;
	
	
	if (c < b)
	{
		pos = findPos(pa, c, b);
		fastSort(pa, c, pos - 1);
		fastSort(pa, pos + 1, b);
	}

	return;
}
int findPos(int* pa, int c, int b)
{
	int val = pa[c];
	while (c < b)
	{
		while (c < b && pa[b]>= val)
		{
			b--;
		}
		pa[c] = pa[b];
		while (c < b && pa[c]<= val)
		{
			c++;
		}
		pa[b] = pa[c];
	}//��ֹwhileѭ��֮�� c �� b һ������ȵģ�
	pa[c] = val;
	return c;//c���Ը�Ϊb,�����ܸ�Ϊval
}


int main(void)

{
	int a[5] = {9, 5, 8, 3, -10};
	fastSort(a,0,4);//֮ǰ��������Ϊ�������4д����5���ͼ����������±����ֵ������Ԫ��������һ��

	for (int i = 0; i < 5; i++)
	{
		printf("%d ", a[i]);
	}
	printf("\n");
}