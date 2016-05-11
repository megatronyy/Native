#include "stack.h"

void testStack()
{
	STACK S;
	init(&S);
	push(&S, 1);
	push(&S, 2);
	push(&S, 3);
	push(&S, 4);
	push(&S, 5);
	traverse(&S);
	int val;
	if (pop(&S, &val))
	{
		printf("出栈元素:%d\n", val);
		traverse(&S);
	}
	clear(&S);
	traverse(&S);
}

void init(PSTACK ps)
{
	ps->pTop = (PNODE)malloc(sizeof(NODE));
	if (NULL == ps->pTop)
	{
		printf("动态内存分配失败！\n");
		exit(-1);
	}
	else
	{
		ps->pBottom = ps->pTop;
		ps->pTop->pNext = NULL;
	}
}

void push(PSTACK ps, int val)
{
	PNODE pNew = (PNODE)malloc(sizeof(NODE));
	if (NULL == pNew)
	{
		printf("动态内存分配失败！\n");
		exit(-1);
	}

	pNew->data = val;

	pNew->pNext = ps->pTop;

	ps->pTop = pNew;
	
	return;
}

void traverse(PSTACK ps)
{
	PNODE p = ps->pTop;
	while (p != ps->pBottom)
	{
		printf("%d ", p->data);
		p = p->pNext;
	}

	printf("\n");
}

bool pop(PSTACK ps, int *pVal)
{
	if (is_empty(ps))
	{
		printf("这是一个空栈");
		return false;
	}
	else
	{
		PNODE p = ps->pTop;
		*pVal = p->data;
		ps->pTop = p->pNext;
		free(p);
		p = NULL;
		return true;
	}
}

bool is_empty(PSTACK ps)
{
	if (ps->pBottom == ps->pTop)
		return true;
	else
		return false;
}

void clear(PSTACK ps)
{
	if (is_empty(ps))
		return;

	PNODE p, q;
	p = ps->pTop;
	q = NULL;
	while (p != ps->pBottom)
	{
		q = p->pNext;
		free(p);
		p = q;
	}
	ps->pTop = ps->pBottom;
	p = NULL;
	q = NULL;
}