#ifndef HARRAY_H
#define HARRAY_H

#include <assert.h>

typedef int bool;

// Array

typedef struct HArray
{
    int Size;
    int Capacity;
    int *Data;
} HArray;

HArray *HArrayNew(int capacity);
void HArrayDestroy(HArray *array);

int HArraySize(HArray *array);
bool HArrayAppend(HArray *array, int item);
void HArrayPrint(HArray *array);
int HArrayCapacity(HArray *array);
bool HArrayIsEmpty(HArray *array);
int HArrayRecalculateCapacity(int capacity);
void HArrayResize(HArray *array);


// Tests

void RunAllTests();
void TestAppend();
void TestSize();
void TestEmpty();
void TestResize();

#endif