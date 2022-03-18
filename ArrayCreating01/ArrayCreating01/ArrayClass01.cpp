#include <stdio.h>
#include <malloc.h>//包含了malloc函数的
#include <stdlib.h>//包含了exit函数的

//定义了一个数据类型，该数据类型的名字叫作 struct Arr, 该数据类型含有三个成员，分别是pBase, len, cnt
struct Arr {
	
	int* pBase;  //存储的是数组的第一个元素的地址	
	int len;//数组所能容纳的最大元素的个数
	int cnt;//当前数组有效元素的个数
	//int increment;//自动增长因子
};

void init_arr(struct Arr *pArr, int len);
bool append_arr(struct Arr* pArr, int val);
bool insert_arr(struct Arr* pArr, int pos, int val);
bool delete_arr(struct Arr* pArr, int pos, int*p);
bool get();
bool is_empty(struct Arr* pArr);
bool is_full(struct Arr*pArr);
void sort_arr(struct Arr* pArr);
void show_arr(struct Arr*pArr);
void inversion_arr(struct Arr*pArr);


int main(void)
{

	struct Arr arr;
	init_arr(&arr, 6);
	show_arr(&arr);
	append_arr(&arr, -3);
	show_arr(&arr);
	append_arr(&arr, 8);
	show_arr(&arr);
	append_arr(&arr, 6);
	append_arr(&arr, 10);
	append_arr(&arr, 999);
	append_arr(&arr, 1);
	show_arr(&arr);
	append_arr(&arr, 2);
	show_arr(&arr);
	int val;
	int* pVal;
	pVal = &val;
	delete_arr(&arr, 4, pVal);
	show_arr(&arr);
	printf("刚才删除的数是：%d\n	", val);
	insert_arr(&arr, 4, 10);
	show_arr(&arr);
	insert_arr(&arr, 4, 10);
	inversion_arr(&arr);
	show_arr(&arr);
	sort_arr(&arr);
	show_arr(&arr);
	

	return 0;
}
void inversion_arr(struct Arr* pArr)
{
	int a = pArr->cnt-1;
	int i = 0;
	int t = 0;
	while (a>i)
	{
		t = pArr->pBase[i];
		pArr->pBase[i] = pArr->pBase[a];
		pArr->pBase[a] = t;
		i++;
		a--;

	}
	printf("本数组倒置完毕\n");
	return;

}
bool is_empty(struct Arr* pArr)
{
	if (pArr->cnt == 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}
bool is_full(struct Arr* pArr)
{
	if (pArr->cnt == pArr->len)
	{
		return true;
	}
	else
	{
		return false;
	}
}

void show_arr(struct Arr* pArr)
{
	if (is_empty(pArr))
	{
		printf("数组为空！\n");
	}
	else
	{
		printf("这个数组的元素是：\n");
		for (int i = 0; i < pArr->cnt; i++)
		{
			printf("%d   ", pArr->pBase[i]);
		}
		printf("\n");
	}
	printf("这个数组的长度是：%d\n", pArr->len);
	printf("这个数组的有效长度是%d\n", pArr->cnt);
	printf("这个数组的指针是%p\n", pArr->pBase);
		printf("\n");
	printf("\n");
	printf("\n");
	printf("\n");
}

void init_arr(struct Arr *pArr, int length) 
{
	pArr->pBase = (int*)malloc(sizeof(int) * length);
	if (NULL == pArr->pBase)
	{
		printf("动态内存分配失败！\n");
		exit(-1);//终止整个程序
	}
	else
	{
		pArr->len = length;
		pArr->cnt = 0;
	}
	return;

}

bool insert_arr(struct Arr* pArr, int pos, int val)
{
	if (pos < 1 || pos> pArr->cnt + 1)
	{
		printf("对不起，您插入的位置超出范围\n");
		return false;
	}
	else
	{
		if (is_full(pArr))
		{
			printf("对不起，数组已经满了，无法插入新数\n");
			return false;
		}
		else
		{
			for (int i = pArr->cnt; i >= pos; i--)
			{
				pArr->pBase[i] = pArr->pBase[i - 1];

			}
			pArr->pBase[pos - 1] = val;
			pArr->cnt++;
			printf("您在第%d个位置插入了值%d\n", pos, val);
			return true;
		}

	}
	
}

bool delete_arr(struct Arr* pArr, int pos, int*p)
{
	if (is_empty(pArr))
	{
		printf("对不起，本数组是空数组，您无法删除元素\n");
		return false;

	}
	else
	{
		if (pos < 1 || pos > pArr->cnt)
		{
			printf("您想删除的数字不存在");
			return false;
		}
		else
		{
			*p = pArr->pBase[pos - 1];

			/*if (pos == parr->cnt)
			{

			}*/
			for (int i = pos; i < pArr->cnt; i++)
			{
				pArr->pBase[i - 1] = pArr->pBase[i];

			}
			pArr->cnt--;
			return true;
		}
	}
	
}
void sort_arr(struct Arr* pArr)
{
	int i, j, t;
	for ( i = 0; i < pArr->cnt-1; i++)
	{
		for ( j = i + 1; j < pArr->cnt; j++)
		{
			if (pArr->pBase[i]> pArr->pBase[j])
			{
				t = pArr->pBase[i];
				pArr->pBase[i] = pArr->pBase[j];
				pArr->pBase[j] = t;
			}
		}
	}
	printf("本数组从小到大排序结束\n");

}
bool append_arr(struct Arr* pArr, int val)
{
	if (is_full(pArr))
	{
		printf("本数组已经满了,本次扩充数组失败\n");
		return false;
	}
	else
	{
		pArr->pBase[pArr->cnt] = val;
		pArr->cnt++;
		return true;
	}
}