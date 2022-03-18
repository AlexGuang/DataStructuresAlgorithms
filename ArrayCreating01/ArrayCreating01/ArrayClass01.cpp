#include <stdio.h>
#include <malloc.h>//������malloc������
#include <stdlib.h>//������exit������

//������һ���������ͣ����������͵����ֽ��� struct Arr, ���������ͺ���������Ա���ֱ���pBase, len, cnt
struct Arr {
	
	int* pBase;  //�洢��������ĵ�һ��Ԫ�صĵ�ַ	
	int len;//�����������ɵ����Ԫ�صĸ���
	int cnt;//��ǰ������ЧԪ�صĸ���
	//int increment;//�Զ���������
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
	printf("�ղ�ɾ�������ǣ�%d\n	", val);
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
	printf("�����鵹�����\n");
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
		printf("����Ϊ�գ�\n");
	}
	else
	{
		printf("��������Ԫ���ǣ�\n");
		for (int i = 0; i < pArr->cnt; i++)
		{
			printf("%d   ", pArr->pBase[i]);
		}
		printf("\n");
	}
	printf("�������ĳ����ǣ�%d\n", pArr->len);
	printf("����������Ч������%d\n", pArr->cnt);
	printf("��������ָ����%p\n", pArr->pBase);
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
		printf("��̬�ڴ����ʧ�ܣ�\n");
		exit(-1);//��ֹ��������
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
		printf("�Բ����������λ�ó�����Χ\n");
		return false;
	}
	else
	{
		if (is_full(pArr))
		{
			printf("�Բ��������Ѿ����ˣ��޷���������\n");
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
			printf("���ڵ�%d��λ�ò�����ֵ%d\n", pos, val);
			return true;
		}

	}
	
}

bool delete_arr(struct Arr* pArr, int pos, int*p)
{
	if (is_empty(pArr))
	{
		printf("�Բ��𣬱������ǿ����飬���޷�ɾ��Ԫ��\n");
		return false;

	}
	else
	{
		if (pos < 1 || pos > pArr->cnt)
		{
			printf("����ɾ�������ֲ�����");
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
	printf("�������С�����������\n");

}
bool append_arr(struct Arr* pArr, int val)
{
	if (is_full(pArr))
	{
		printf("�������Ѿ�����,������������ʧ��\n");
		return false;
	}
	else
	{
		pArr->pBase[pArr->cnt] = val;
		pArr->cnt++;
		return true;
	}
}