#include <string>
#include <iostream>

bool
IsPermutation(char *s, char *t)
{
    if(strlen(s) != strlen(t))
        return;

    int letters[128];
    for(int i = 0; i < strlen(s); ++i)
    {
        letters[i]++;
    }
}