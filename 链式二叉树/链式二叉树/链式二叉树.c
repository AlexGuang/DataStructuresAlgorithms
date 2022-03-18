#include <stdio.h>	
#include <malloc.h>
//д��ʱ�䣺2022��3��7�� 12��02�֣�д��Ŀ�ģ��õݹ�ķ���ʵ�ֶ���ʽ�����������������Լ�����ı�����д���ߣ���硣

struct tNode
{

	char data;
	struct tNode* lpTnode;
	struct tNode* rpTnode;
};

struct tNode* creatTreeNode()
{
	struct tNode* pA = (struct tNode*)malloc(sizeof(struct tNode));
	struct tNode* pB = (struct tNode*)malloc(sizeof(struct tNode));
	struct tNode* pF = (struct tNode*)malloc(sizeof(struct tNode));
	struct tNode* pD = (struct tNode*)malloc(sizeof(struct tNode));
	struct tNode* pC = (struct tNode*)malloc(sizeof(struct tNode));
	struct tNode* pL = (struct tNode*)malloc(sizeof(struct tNode));
	struct tNode* pM = (struct tNode*)malloc(sizeof(struct tNode));
	struct tNode* pN = (struct tNode*)malloc(sizeof(struct tNode));

	pA->data = 'A';
	pB->data = 'B';
	pF->data = 'F';
	pD->data = 'D';
	pC->data = 'C';
	pL->data = 'L';
	pM->data = 'M';
	pN->data = 'N';

	pA->lpTnode = pB;
	pA->rpTnode = pD;
	pB->lpTnode = NULL;
	pB->rpTnode = pF;
	pF->lpTnode = pF->rpTnode = NULL;
	pD->lpTnode = pC;
	pD->rpTnode = pL;
	pC->lpTnode = pC->rpTnode = NULL;
	pL->lpTnode = NULL;
	pL->rpTnode = pM;
	pM->lpTnode = pN;
	pM->rpTnode = NULL;
	pN->lpTnode = pN->rpTnode = NULL;

	
	return pA;
}
void PreTreaverse(struct tNode* pTnode)
{
	if (NULL != pTnode)
	{
		printf("%c\n", pTnode->data);
	}
	if (NULL!= pTnode->lpTnode)
	{
		PreTreaverse(pTnode->lpTnode);
	}
	if (NULL!= pTnode->rpTnode)
	{
		PreTreaverse(pTnode->rpTnode);
	}


	return;
}
void MidTreaverse(struct tNode* pTnode)
{
	
	if (NULL != pTnode->lpTnode)
	{
		MidTreaverse(pTnode->lpTnode);
	}

	printf("%c\n", pTnode->data);

	if (NULL != pTnode->rpTnode)
	{
		MidTreaverse(pTnode->rpTnode);
	}

	return;
}

void PostTreaverse(struct tNode* pTnode)
{

	if (NULL != pTnode->lpTnode)
	{
		PostTreaverse(pTnode->lpTnode);
	}

	if (NULL != pTnode->rpTnode)
	{
		PostTreaverse(pTnode->rpTnode);
	}
	printf("%c\n", pTnode->data);

	

	return;
}

int main(void) 
{

	struct tNode* pTnode;
	pTnode = creatTreeNode();
	printf("�Ѵ���ʹ����������Ľ���ǣ�\n");
	PreTreaverse(pTnode);
	printf("�Ѵ���ʹ����������Ľ���ǣ�\n");
	MidTreaverse( pTnode);
	printf("�Ѵ���ʹ�ú�������Ľ���ǣ�\n");
	PostTreaverse( pTnode);




	return 0;
}