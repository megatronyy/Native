#include "array.h"

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

void init_arr(PARR pArr, int length)
{
	//动态内存分配，如果分配失败，就把NULL分配给pArr->pBase
	pArr->pBase = (int*)malloc(sizeof(int) * length);
	//pArr->arrType = (ArrType*)malloc(sizeof(ArrType));
	if (NULL == pArr->pBase)
	{
		printf("动态内存分配失败\n");
		exit(-1);//终止整个程序
	}
	else
	{
		pArr->len = length;
		pArr->cnt = 0;
	}
}

//追加元素
bool append_arr(PARR pArr, int val)
{
	//判断数组是否已满
	if (is_full(pArr))
		return false;
	//不满时追加
	pArr->pBase[pArr->cnt] = val;
	(pArr->cnt)++;

	return true;
}

//在具体位置添加元素
bool insert_arr(PARR pArr, int pos, int val)
{
	int i;

	if (is_full(pArr))
		return false;

	if (pos<1 || pos>pArr->cnt + 1)
		return false;

	for (i = pArr->cnt - 1; i >= pos - 1; --i)
	{
		pArr->pBase[i + 1] = pArr->pBase[i];
	}
	pArr->pBase[pos - 1] = val;

	pArr->cnt++;

	return true;
}

//对数组元素进行排序
void sort_arr(PARR pArr)
{
	int i, j, t;
	for (i = 0; i < pArr->cnt-1; ++i)
	{
		for (j = i + 1; j < pArr->cnt; ++j)
		{
			if (pArr->pBase[i] > pArr->pBase[j])
			{
				t = pArr->pBase[i];
				pArr->pBase[i] = pArr->pBase[j];
				pArr->pBase[j] = t;
			}
		}
	}
}

//删除元素
bool delete_arr(PARR pArr, int pos, int *pVal)
{
	int i;
	if (is_empty(pArr))
		return false;

	if (pos < 1 || pos > pArr->cnt)
		return false;
	*pVal = pArr->pBase[pos - 1];
	for (i = pos; i < pArr->cnt; ++i)
	{
		pArr->pBase[i - 1] = pArr->pBase[i];
	}
	pArr->cnt--;
	
	return true;
}

//倒置
void inversion_arr(PARR pArr)
{
	int i=0, j=pArr->cnt-1;
	int t;
	while (i < j)
	{
		t = pArr->pBase[i];
		pArr->pBase[i] = pArr->pBase[j];
		pArr->pBase[j] = t;
		++i;
		--j;
	}

	return;
}
//获取值
int get(PARR pArr, int pos)
{
	if (is_empty(pArr))
		return -100;

	if (pos < 1 || pos > pArr->cnt)
		return -100;

	return pArr->pBase[pos - 1];
}

//判断数组是否为空
bool is_empty(PARR pArr)
{
	if (0 == pArr->cnt)
	{
		return true;
	}
	else
	{
		return false;
	}
}

//判断数组是否已满
bool is_full(PARR pArr)
{
	if (pArr->cnt == pArr->len)
	{
		return true;
	}
	else
	{
		return false;
	}
}

//展示元素
void show_arr(PARR pArr)
{
	if (is_empty(pArr))
	{
		printf("数组为空！\n");
	}
	else
	{
		for (int i = 0; i < pArr->cnt; ++i)
		{
			printf("%d ", pArr->pBase[i]);
		}
		printf("\n");
	}
}