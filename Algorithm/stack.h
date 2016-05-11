#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

typedef struct Node
{
	int data;//������
	struct Node *pNext;//ָ����
} NODE, *PNODE;

typedef struct Stack {
	PNODE pTop;
	PNODE pBottom;
} STACK, *PSTACK;

extern void init(PSTACK); //���һ����ջ
extern void push(PSTACK, int);//ѹջ
extern void traverse(PSTACK);//����
extern bool pop(PSTACK, int *);//��ջ
extern bool is_empty(PSTACK);
extern void clear(PSTACK);
extern void testStack();