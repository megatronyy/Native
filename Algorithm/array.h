/*
	1�������洢�������ڴ浥Ԫ
	2��Ԫ��������ͬ����С���
*/

#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
//typedef struct ArrType
//{
//	void(*init_arr)(PARR arr, int length);
//} arrType;
typedef struct Arr
{
	int *pBase;//�洢���������һ��Ԫ�صĵ�ַ
	int len;//�����������ɵ����Ԫ�صĸ���
	int cnt;//��ǰ������ЧԪ�صĸ���
	//struct ArrType *arrType;
} *PARR, ARR;

 extern void init_arr(PARR, int);
extern bool append_arr(PARR, int);
extern bool insert_arr(PARR, int, int);
extern bool delete_arr(PARR, int, int*);
extern int get(PARR, int);
extern bool is_empty(PARR);
extern bool is_full(PARR);
extern void sort_arr(PARR);
extern void show_arr(PARR);
extern void inversion_arr(PARR);
extern void testArr();


