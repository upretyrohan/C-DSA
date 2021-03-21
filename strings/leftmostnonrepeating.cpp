#include <stdio.h>
#include <string>
using namespace std;

int leftMostNonRepeating(string &s1)
{
    char count[256] = {0};

    for (int i = 0; i < s1.length(); i++)
    {
        count[s1[i]]++;
    }

    for (int i = 0; i < s1.length(); i++)
    {
        if (count[s1[i]] == 1)
            return i;
    }

    return -1;
}

int main()
{
    string s1 = "geeksforgeeks";
    printf("%d\n", leftMostNonRepeating(s1));
    string s3 = "abcabc";
    printf("%d\n", leftMostNonRepeating(s3));
    string s5 = "apple";
    printf("%d\n", leftMostNonRepeating(s5));
}