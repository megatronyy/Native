#include "list.h"

void testList()
{
	PNODE pHead = create_list();
	traverse_list(pHead);

	/*int len = length_list(pHead);
	printf("链表的长度为：%d\n", len);*/

	//insert_list(pHead, 3, 9);

	/*int val;
	delete_list(pHead, 3, &val);*/

	sort_list(pHead);

	traverse_list(pHead);
}

//创建链表
PNODE create_list(void)
{
	int len;
	int i;
	int val;
	PNODE pHead = (PNODE)malloc(sizeof(NODE));

	if (NULL == pHead)
	{
		printf("分配失败\n");
		exit(-1);
	}

	PNODE pTail = pHead;
	pTail->pNext = NULL;

	printf("请输入你需要创建的链表的长度len = ");
	scanf_s("%d", &len);

	for (i = 0; i < len; ++i)
	{
		printf("请输入第%d个节点的值:", i + 1);
		scanf_s("%d", &val);
		PNODE pNew = (PNODE)malloc(sizeof(NODE));
		if (NULL == pNew)
		{
			printf("分配失败\n");
			exit(-1);
		}
		pNew->data = val;
		pNew->pNext = NULL;
		pTail->pNext = pNew;
		pTail = pNew;
	}

	return pHead;
}

//遍历链表
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

//链表的长度
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

//判断链表是否为空
bool is_empty(PNODE pHead)
{
	if (NULL == pHead->pNext)
		return true;
	else
		return false;
}

//在pHead所指的链表的第pos个节点的前面插入一个新的结点，该结点的值是val
bool insert_list(PNODE pHead, int pos, int val)
{
	int i = 0;
	PNODE p = pHead->pNext;

	//执行完，返回pos前的节点
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
		printf("分配失败\n");
		exit(-1);
	}

	pNew->data = val;
	PNODE q = p->pNext;//临时节点
	pNew->pNext = q;
	p->pNext = pNew;

	return true;
}

//删除节点
bool delete_list(PNODE pHead, int pos, int * pVal)
{
	int i = 0;
	PNODE p = pHead;

	//循环完以后，p就等于需要删除节点之前的节点
	while (NULL != p->pNext && i < pos - 1)
	{
		p = p->pNext;
		++i;
	}

	if (i > pos - 1 || NULL == p->pNext)
		return false;

	PNODE q = p->pNext;//临时节点
	*pVal = q->data;
	p->pNext = p->pNext->pNext;

	free(q);
	q = NULL;

	return true;
}

//链表的排序
void sort_list(PNODE pHead)
{
	int i, j, t;
	PNODE p, q;
	int len = length_list(pHead);
	for (i = 0, p = pHead->pNext; i < len - 1; ++i, p=p->pNext)
	{
		for (j = i + 1, q=p->pNext; j < len; ++j, q = q->pNext)
		{
			if (p->data > q->data) //类似于数组中的：a[i]>a[j]
			{
				t = p->data;
				p->data = q->data;
				q->data = t;
			}
		}
	}
}