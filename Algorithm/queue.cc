#include "queue.h"

void testQueue()
{
	QUEUE Q;
	init(&Q);
	enqueue(&Q, 1);
	enqueue(&Q, 2);
	enqueue(&Q, 3);
	enqueue(&Q, 4);
	enqueue(&Q, 5);
	enqueue(&Q, 6);
	enqueue(&Q, 7);
	enqueue(&Q, 8);

	traverse_queue(&Q);

	int val;
	if (dequeue(&Q, &val))
	{
		printf("出队成功，你出队的元素是：%d\n", val);
	}
	else
	{
		printf("出队失败");
	}

	traverse_queue(&Q);
}

void init(PQUEUE pQ)
{
	pQ->pBase = (int *)malloc(sizeof(int) * 6);
	pQ->front = 0;
	pQ->rear = 0;
}

bool enqueue(PQUEUE pQ, int val)
{
	if (full_queue(pQ))
	{
		return false;
	}
	else
	{
		pQ->pBase[pQ->rear] = val;
		pQ->rear = (pQ->rear + 1) % 6;

		return true;
	}
}

bool dequeue(PQUEUE pQ, int *pVal)
{
	if (empty_queue(pQ))
	{
		return false;
	}
	else
	{
		*pVal = pQ->pBase[pQ->front];
		pQ->front = (pQ->front + 1) % 6;

		return true;
	}
}

bool full_queue(PQUEUE pQ)
{
	if ((pQ->rear + 1) % 6 == pQ->front)
		return true;
	else
		return false;
}

bool empty_queue(PQUEUE pQ)
{
	if (pQ->front == pQ->rear)
		return true;
	else
		return false;
}

void traverse_queue(PQUEUE pQ)
{
	int i = pQ->front;
	while (i != pQ->rear)
	{
		printf("%d ", pQ->pBase[i]);
		i = (i + 1) % 6;
	}
	printf("\n");
	return;
}