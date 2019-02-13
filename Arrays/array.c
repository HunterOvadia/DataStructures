// Array

HArray*
HArrayNew(int capacity)
{
    int NewCap = HArrayRecalculateCapacity(capacity);
    // Allocate space for an array
    HArray *NewArray = malloc(sizeof(HArray));
    NewArray->Size = 0;
    NewArray->Capacity = NewCap;
    NewArray->Data = (int *)malloc(sizeof(int) * NewCap);
    
    return(NewArray);
}

int HArrayRecalculateCapacity(int capacity)
{
    int TrueCapacity = 16;
    
    // If Max Size is less than 1
    assert(capacity > 0);
    
    int Power = 16;
    while(capacity > Power / 2)
    {
        Power *= 2;
    }
    
    TrueCapacity = Power;
    
    return(TrueCapacity);
}

void
HArrayResize(HArray *array)
{
    int OldCapacity = array->Capacity;
    int NewCapacity = HArrayRecalculateCapacity(OldCapacity);
    
    int *NewData = (int *)malloc(sizeof(int) * NewCapacity);
    
    for(int i = 0; i < OldCapacity; ++i)
    {
        NewData[i] = array->Data[i];
    }
    
    free(array->Data);
    
    array->Data = NewData;
    array->Capacity = NewCapacity;
}

int
HArraySize(HArray *array)
{
    return(array->Size);
}

void
HArrayDestroy(HArray *array)
{
    free(array->Data);
    free(array);
}

bool
HArrayAppend(HArray *array, int item)
{
    int Success = 0;
    
    // If the current size of the array is less than the max size
    if(array->Size == array->Capacity)
    {
        HArrayResize(array);
    }
    
    if(array->Size < array->Capacity)
    {
        array->Data[array->Size] = item;
        ++array->Size;
        Success = 1;
    }
    
    return(Success);
}

void
HArrayPrint(HArray *array)
{
    printf("Size: %d\n", array->Size);
    printf("Capacity: %d\n", array->Capacity);
    printf("Items: \n");
    
    for(int i = 0; i < array->Size; ++i)
    {
        printf("%d: %d\n", i, array->Data[i]);
    }
}

int
HArrayCapacity(HArray *array)
{
    return(array->Capacity);
}

bool
HArrayIsEmpty(HArray *array)
{
    return (array->Size == 0);
}


// Tests
void RunAllTests()
{
    TestSize();
    TestAppend();
    TestEmpty();
    TestResize();
}

void
TestAppend()
{
    HArray *NewArray = HArrayNew(2);
    HArrayAppend(NewArray, 2);
    HArrayAppend(NewArray, 12);
    int Size = HArraySize(NewArray);
    assert(Size == 2);
    HArrayDestroy(NewArray);
}

void
TestSize()
{
    HArray *NewArray = HArrayNew(5);
    assert(HArraySize(NewArray) != 5);
    HArrayDestroy(NewArray);
}



void
TestEmpty()
{
    HArray *NewArray = HArrayNew(2);
    assert(HArrayIsEmpty(NewArray) == 1);
    HArrayAppend(NewArray, 1);
    assert(HArrayIsEmpty(NewArray) == 0);
    HArrayDestroy(NewArray);
}


void
TestResize()
{
    HArray *NewArray = HArrayNew(2);
    
    int OldCap = HArrayCapacity(NewArray);
    assert(OldCap == 16);
    
    for(int i = 0; i < 18; ++i)
    {
        HArrayAppend(NewArray, i + 1);
    }
    
    int NewCap = HArrayCapacity(NewArray);
    assert(NewCap == 32);
}