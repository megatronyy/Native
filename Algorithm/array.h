/*
	1、连续存储的线性内存单元
	2、元素类型相同，大小想等
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
	int *pBase;//存储的是数组第一个元素的地址
	int len;//数组所能容纳的最大元素的个数
	int cnt;//当前数组有效元素的个数
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


