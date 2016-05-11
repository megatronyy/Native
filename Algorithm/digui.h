/*
递归的定义：
一个函数直接或者间接的调用自己。

递归满足三个条件
1、递归必须得有一个明确的中止条件。、
2、该函数所处理的数据规模必须在递减。
3、这个转化必须是可解的。

递归与循环的比较
递归：
易于理解
速度慢
存储空间大
循环
不易理解
速度快
存储空间小

汉诺塔
伪算法：
三根柱子，A、B、C
if(n > 1)
{
先把A柱子上的前n-1个盘子从A借助C移到B
将A柱子上的第n个盘子直接移到C
再将B柱子上的n-1个盘子借助A移到C
}

n不能大于64
*/

#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

extern void hannuota(int n, char A, char B, char C);
extern void testHannuota();

