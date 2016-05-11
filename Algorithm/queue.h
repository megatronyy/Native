/*
	����һ��ѭ�����У�������ʵ�ֵģ�����������ʵ�ֵĶ���
	1�����У��Ƚ��ȳ���
	2�����к�ʱ���йصĲ������ж��е�Ӱ�ӡ�
	ѭ�����еĽ��⣺
		1����̬����Ϊʲô������ѭ������
		2��ѭ��������Ҫ����������ȷ��
			front
			rear
		3��ѭ�����и��������ĺ���
			2��������ͬ�����в�ͬ�ĺ���
				1).���г�ʼ��
					front��rear��ֵ������
				2).���зǿ�
					front������Ƕ��еĵ�һ��Ԫ��
					rear������Ƕ��е����һ����ЧԪ�ص���һ��Ԫ��
				3).���п�
					front��rear��ֵ��ȣ�����һ����
		4��ѭ���������α�㷨
			1).��ֵ����rear�������λ��
			2).�����д����r = r + 1
			   ��ȷ��д����r= (r + 1) % ����ĳ���
		5��ѭ�����г���α�㷨����
			1).f = (f + 1) % ����ĳ���
		6������ж�ѭ�������Ƿ�Ϊ��
			1).���frontֵ��rearֵ��ȣ����о�һ��Ϊ��
		7������ж�ѭ�������Ƿ�����
		   frontֵ�п��ܱ�rear��Ҳ����С��Ҳ�������
		   ���ַ�ʽ��
			1).������һ����ʶ��������Σ�����ĳ���
			2).����һ��Ԫ�أ����rear��front��ֵ�����ţ����������
			   ��C����α�㷨��ʾ���ǣ�
			    if((r + 1) % ����ĳ��� == f)
					����
				else
					����

		
		
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





