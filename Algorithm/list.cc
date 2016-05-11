#include "list.h"

void testList()
{
	PNODE pHead = create_list();
	traverse_list(pHead);

	/*int len = length_list(pHead);
	printf("����ĳ���Ϊ��%d\n", len);*/

	//insert_list(pHead, 3, 9);

	/*int val;
	delete_list(pHead, 3, &val);*/

	sort_list(pHead);

	traverse_list(pHead);
}

//��������
PNODE create_list(void)
{
	int len;
	int i;
	int val;
	PNODE pHead = (PNODE)malloc(sizeof(NODE));

	if (NULL == pHead)
	{
		printf("����ʧ��\n");
		exit(-1);
	}

	PNODE pTail = pHead;
	pTail->pNext = NULL;

	printf("����������Ҫ����������ĳ���len = ");
	scanf_s("%d", &len);

	for (i = 0; i < len; ++i)
	{
		printf("�������%d���ڵ��ֵ:", i + 1);
		scanf_s("%d", &val);
		PNODE pNew = (PNODE)malloc(sizeof(NODE));
		if (NULL == pNew)
		{
			printf("����ʧ��\n");
			exit(-1);
		}
		pNew->data = val;
		pNew->pNext = NULL;
		pTail->pNext = pNew;
		pTail = pNew;
	}

	return pHead;
}

//��������
void traverse_list(PNODE pHead)
{
	PNODE p = pHead->pNext;

	while (NULL != p)
	{
		printf("%d ", p->data);
		p = p->pNext;
	}

	printf("\n");
}

//����ĳ���
int length_list(PNODE pHead)
{
	PNODE p = pHead->pNext;
	int len = 0;
	while (NULL != p)
	{
		++len;
		p = p->pNext;
	}

	return len;
}

//�ж������Ƿ�Ϊ��
bool is_empty(PNODE pHead)
{
	if (NULL == pHead->pNext)
		return true;
	else
		return false;
}

//��pHead��ָ������ĵ�pos���ڵ��ǰ�����һ���µĽ�㣬�ý���ֵ��val
bool insert_list(PNODE pHead, int pos, int val)
{
	int i = 0;
	PNODE p = pHead->pNext;

	//ִ���꣬����posǰ�Ľڵ�
	while (NULL != p && i < pos - 1)
	{
		p = p->pNext;
		++i;
	}

	if (i > pos - 1 || NULL == p)
		return false;

	PNODE pNew = (PNODE)malloc(sizeof(NODE));
	if (NULL == pNew)
	{
		printf("����ʧ��\n");
		exit(-1);
	}

	pNew->data = val;
	PNODE q = p->pNext;//��ʱ�ڵ�
	pNew->pNext = q;
	p->pNext = pNew;

	return true;
}

//ɾ���ڵ�
bool delete_list(PNODE pHead, int pos, int * pVal)
{
	int i = 0;
	PNODE p = pHead;

	//ѭ�����Ժ�p�͵�����Ҫɾ���ڵ�֮ǰ�Ľڵ�
	while (NULL != p->pNext && i < pos - 1)
	{
		p = p->pNext;
		++i;
	}

	if (i > pos - 1 || NULL == p->pNext)
		return false;

	PNODE q = p->pNext;//��ʱ�ڵ�
	*pVal = q->data;
	p->pNext = p->pNext->pNext;

	free(q);
	q = NULL;

	return true;
}

//���������
void sort_list(PNODE pHead)
{
	int i, j, t;
	PNODE p, q;
	int len = length_list(pHead);
	for (i = 0, p = pHead->pNext; i < len - 1; ++i, p=p->pNext)
	{
		for (j = i + 1, q=p->pNext; j < len; ++j, q = q->pNext)
		{
			if (p->data > q->data) //�����������еģ�a[i]>a[j]
			{
				t = p->data;
				p->data = q->data;
				q->data = t;
			}
		}
	}
}