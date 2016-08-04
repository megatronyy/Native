#include <stdio.h>
#include <malloc.h>

extern void testQuickSort();
extern void quicksort(int *, int, int);
extern int findpos(int *, int, int);
extern int position(int *, int, int);
void exchange(int *, int, int);