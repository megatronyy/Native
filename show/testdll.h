#pragma once 

#include <Windows.h>
#include <stdio.h>
#include <stdlib.h>

typedef int (*DLLFUN)(int &a, int &b);

void testDll()
{
	DLLFUN Dll_addFun;
	HINSTANCE hDLL = LoadLibrary((LPCTSTR)"Common.dll");

	if(hDLL == NULL)
	{
		Dll_addFun = (DLLFUN)GetProcAddress(hDLL, "add");
		int a = 1;
		int b = 2;

		printf("%d\n", Dll_addFun(a, b));
	}
	else
	{
		printf("¼ÓÔØDLLÊ§°Ü,³ÌÐòÍË³ö");
	}

	if(hDLL)
	{
		FreeLibrary(hDLL);
		hDLL = NULL;
	}
}