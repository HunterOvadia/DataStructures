/*
    Is Unique: Implement an algorithm to determine if a string has all unique characters. What if you cannot use additional data structures?

    - Ask if ASCII or Unicode
*/
#include <iostream>
#include <string>

bool
HasUniqueCharacters(std::string string)
{
    if(string.length() > 128)
        return false;

    bool char_set[128];
    for(int i = 0; i < string.length(); ++i)
    {
        char val = string.at(i);
        if(char_set[val])
        {
            return false;
        }
        char_set[val] = true;
    }

    return true;
}