// •   Write a function that takes a single string to reverse the order of the words in a sentence (not reverse the words).
// •   Example
// o   Input: The cat sat on the mat with another cat!
// o   Output: Cat! another with mat the on sat cat the
#include <string>
#include <iostream>
using namespace std;
void foo(string str)
{
    stringstream ss = str;
    string word [str.length()];
    for (int i = 0; i < str.len(); i++)
    {
        if (str.charAt(i) = ' ')
        {
            word[i] = str.substring(' ', i);
        }
        string temp;
        temp = word[i];
        word[i] = word[i + ];
        
    }
}