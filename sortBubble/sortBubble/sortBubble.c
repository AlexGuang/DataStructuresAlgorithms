#include <stdio.h>

int main()
{   

	int t = 0;

	int a[6] =
	{
		9, 5, 4, 2, 8, 1
	};

	printf("开始时数组a是：");
	for (int i = 0; i < 6; i++)
	{
		printf("%d ", a[i]);
	}
	printf("\n");

	for (int i = 0;  i< 6; i++)
	{
		for (int j = 5; j >i; j--)
		{                   
			
			if (a[i] > a[j])
			{
				t = a[i];
				a[i] = a[j];
				a[j] = t;
			}
			
		}
	}
	printf("排序完成后的数组a是：");
	for (int i = 0; i < 6; i++)
	{
		printf("%d ", a[i]);
	}
	printf("\n");
	printf("\n");
	printf("\n");
	printf("\n");
	printf("\n");
	printf("\n");
	printf("\n");






	int a1[6] =
	{
		5, 7, 4, 9, 8, 3
	};

	printf("开始时数组a1是：");
	for (int i = 0; i < 6; i++)
	{
		printf("%d ", a1[i]);
	}
	printf("\n");

	for (int i = 0; i < 6; i++)
	{
		for (int j = i+1; j<6; j++)
		{

			if (a1[i] > a1[j])
			{
				t = a1[i];
				a1[i] = a1[j];
				a1[j] = t;
			}

		}
	}
	printf("排序完成后的数组a1是：");
	for (int i = 0; i < 6; i++)
	{
		printf("%d ", a1[i]);
	}

	printf("\n");
	printf("\n");
	printf("\n");
	printf("\n");
	printf("\n");
	printf("\n");
	printf("\n");






	int a2[6] =
	{
		6, 9, 5, 7, 8, 3
	};

	printf("开始时数组a2是：");
	for (int i = 0; i < 6; i++)
	{
		printf("%d ", a2[i]);
	}
	printf("\n");

	/*for (int i = 0; i < 6; i++)
	{
		for (int j = i + 1; j < 6; j++)
		{

			if (a1[i] > a1[j])
			{
				t = a1[i];
				a1[i] = a1[j];
				a1[j] = t;
			}

		}
	}*/
	
	for (int l = 5; l > 0; l--)
	{
		int i = 0;
		for (int k = l; k > 0; k--)
		{
			
			int j = i + 1;
			if (a2[i] > a2[j])
			{
				t = a2[i];
				a2[i] = a2[j];
				a2[j] = t;
			}
			i++;
	}
	
		


	}
	printf("排序完成后的数组a2是：");
	for (int i = 0; i < 6; i++)
	{
		printf("%d ", a2[i]);
	}
	printf("\n");
	printf("\n");
	printf("\n");
	printf("\n");
	printf("\n");
	printf("\n");
	printf("\n");


	
	int sum = 0;
	for (int i = 0; i < 11; i++)
	{
		sum += i;
	}

	printf("%d\n", sum);
	return 0;
}