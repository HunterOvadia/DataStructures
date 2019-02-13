#include <stdio.h>
#include <stdlib.h>

#include "array.h"
#include "array.c"


void RunExample()
{
	int Capacity = 0;
	printf("Array Size: ");
	scanf_s("%d", &Capacity);
	
	int CanAppend = 0;
	HArray *NewArray = HArrayNew(Capacity);
	for(int i = 1; i <= Capacity; ++i)
	{
		CanAppend = HArrayAppend(NewArray, i);
		if(!CanAppend)
		{
			printf("Array Full.\n");
			break;
		}
	}
	
	HArrayPrint(NewArray);
	HArrayDestroy(NewArray);
}

int main(int argc, char *argv[])
{
	RunAllTests();
	printf("Tests Successfully Passed.\n");
    RunExample();
	
	system("pause");
	return(EXIT_SUCCESS);
}