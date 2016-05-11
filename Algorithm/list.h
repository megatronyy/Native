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