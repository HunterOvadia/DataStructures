#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define SIZE 20

typedef struct data_item
{
    int Data;
    int Key;
} data_item;

data_item *HashArray[SIZE];
data_item *DummyItem;
data_item *Item;

int
HashCode(int key)
{
    return key % SIZE;
}

data_item *Search(int key)
{
    int HashIndex = HashCode(key);

    while(HashArray[HashIndex] != NULL)
    {
        if(HashArray[HashIndex]->Key == key)
            return HashArray[HashIndex];
        
        ++HashIndex;
        HashIndex %= SIZE;
    }

    return NULL;
}

void Insert(int key, int data)
{
    data_item *Item = (data_item *)malloc(sizeof(data_item));
    Item->Data = data;
    Item->Key = key;

    int hashIndex = HashCode(key);

    while(HashArray[hashIndex] != NULL && HashArray[hashIndex]->Key != -1)
    {
        ++hashIndex;
        hashIndex %= SIZE;
    }

    HashArray[hashIndex] = Item;
}

data_item* Delete(data_item* item)
{
    int key = item->Key;
    int hashIndex = HashCode(key);

    while(HashArray[hashIndex] != NULL)
    {
        if(HashArray[hashIndex]->Key == key)
        {
            data_item *Temp = HashArray[hashIndex];
            HashArray[hashIndex] = DummyItem;
            return Temp;
        }

        ++hashIndex;
        hashIndex %= SIZE;
    }

    return NULL;
}