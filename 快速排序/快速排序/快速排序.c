#include	<stdio.h>
/*
2022年3月8日 13点37分，李晓光完成双指针快速排序法
此处的双指针是数组的下标，并不是真指针

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
	}//终止while循环之后 c 和 b 一定是相等的；
	pa[c] = val;
	return c;//c可以改为b,但不能改为val
}


int main(void)

{
	int a[5] = {9, 5, 8, 3, -10};
	fastSort(a,0,4);//之前报错是因为括号里的4写成了5，低级错误。数组下标最大值是数组元素数量减一。

	for (int i = 0; i < 5; i++)
	{
		printf("%d ", a[i]);
	}
	printf("\n");
}