#pragma once
#include <stdio.h>
#include <malloc.h>

/*
	动态规则--钢条切割的问题
	动态规划的两个方式：
	1、带备忘录的自顶向下
	2、自底向上
*/

//自底向上
int bottom_up_cut_aux(int);
void print_cut_rod_solution(int);
//带备忘录的自顶向下
int top_down_cut(int);
int top_down_cut_aux(int);
extern void testSteelMain();