#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

typedef struct Node
{
	int data;//数据域
	struct Node *pNext;//指针域
} NODE, *PNODE;

extern PNODE create_list();
extern void traverse_list(PNODE);
extern bool is_empty(PNODE);
extern int length_list(PNODE);
extern bool insert_list(PNODE, int, int);
extern bool delete_list(PNODE, int, int *);
extern void sort_list(PNODE);
extern void testList();
extern PNODE reverse_list(PNODE);//反转单链表
