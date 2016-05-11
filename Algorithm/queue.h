/*
	这是一个循环队列，以数组实现的，还有以链表实现的队列
	1、队列：先进先出。
	2、所有和时间有关的操作都有队列的影子。
	循环队列的讲解：
		1、静态队列为什么必须是循环队列
		2、循环队列需要几个参数来确定
			front
			rear
		3、循环队列各个参数的含义
			2个参数不同场合有不同的含义
				1).队列初始化
					front和rear的值都是零
				2).队列非空
					front代表的是队列的第一个元素
					rear代表的是队列的最后一个有效元素的下一个元素
				3).队列空
					front和rear的值相等，但不一定零
		4、循环队列入队伪算法
			1).将值存入rear所代表的位置
			2).错误的写法：r = r + 1
			   正确的写法：r= (r + 1) % 数组的长度
		5、循环队列出队伪算法讲解
			1).f = (f + 1) % 数组的长度
		6、如何判断循环队列是否为空
			1).如果front值与rear值相等，队列就一定为空
		7、如何判断循环队列是否已满
		   front值有可能比rear大，也可能小，也可能相等
		   两种方式：
			1).多增加一个标识参数，如何，数组的长度
			2).少用一个元素，如果rear与front的值紧挨着，则队列已满
			   用C语言伪算法表示就是：
			    if((r + 1) % 数组的长度 == f)
					已满
				else
					不满

		
		
*/
#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

typedef struct Queue
{
	int *pBase;
	int front;
	int rear;
} QUEUE, *PQUEUE;



extern void init(PQUEUE);
extern bool enqueue(PQUEUE, int);
extern bool dequeue(PQUEUE, int *);
extern void traverse_queue(PQUEUE);
extern bool full_queue(PQUEUE);
extern bool empty_queue(PQUEUE);
extern void testQueue();





