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

#ifdef __cplusplus
extern "C" {
#endif

__declspec(dllexport) extern void init_arr(PARR, int);
__declspec(dllexport) extern bool append_arr(PARR, int);
__declspec(dllexport) extern bool insert_arr(PARR, int, int);
__declspec(dllexport) extern bool delete_arr(PARR, int, int*);
__declspec(dllexport) extern int get(PARR, int);
__declspec(dllexport) extern bool is_empty(PARR);
__declspec(dllexport) extern bool is_full(PARR);
__declspec(dllexport) extern void sort_arr(PARR);
__declspec(dllexport) extern void show_arr(PARR);
__declspec(dllexport) extern void inversion_arr(PARR);

#ifdef __cplusplus
	}
#endif
//测试方法
void testArr()
{
	ARR arr;

	init_arr(&arr, 6);
	append_arr(&arr, 3);
	append_arr(&arr, 2);
	append_arr(&arr, 1);
	append_arr(&arr, 5);
	append_arr(&arr, 4);
	insert_arr(&arr, 6, 99);
	show_arr(&arr);

	sort_arr(&arr);

	show_arr(&arr);

	/*int delVal;
	delete_arr(&arr, 4, &delVal);*/



	inversion_arr(&arr);

	show_arr(&arr);
}

