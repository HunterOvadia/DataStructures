#include <stdio.h>
#include <stdlib.h>

// O(n)
template <typename T>
T LinearSearch(T array[], T item)
{
    for(int i = 0; i < sizeof(array) / sizeof(array[0]); ++i)
    {
        if(array[i] == item)
            return array[i];
    }

    return NULL;
}

// Fastest search algorithm with O(log n)
// Uses Divide and Conquer
// To work effectively, the data should be sorted.
template <typename T>
T BinarySearch(T array[], T item)
{
    int arraySize = sizeof(array) / sizeof(array[0]);

    int lowerBound = 0;
    int upperBound = arraySize;
    int midPoint = -1;
    int Result = -1;

    while(lowerBound <= upperBound)
    {
        midPoint = (lowerBound + (upperBound - lowerBound) / 2);
        if(array[midPoint] == item)
        {
            index = midPoint;
            break;
        }
        else
        {
            if(array[midPoint] < data)
            {
                lowerBound = midPoint + 1;
            }
            else
            {
                upperBound = midPoint - 1;
            }      
        }
    }

    return index;
}
