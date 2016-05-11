#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

typedef struct Node
{
	int data;//数据域
	struct Node *pNext;//指针域
} NODE, *PNODE;

typedef struct Stack {
	PNODE pTop;
	PNODE pBottom;
} STACK, *PSTACK;

extern void init(PSTACK); //造出一个空栈
extern void push(PSTACK, int);//压栈
extern void traverse(PSTACK);//遍历
extern bool pop(PSTACK, int *);//出栈
extern bool is_empty(PSTACK);
extern void clear(PSTACK);
extern void testStack();