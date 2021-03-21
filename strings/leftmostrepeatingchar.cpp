#include <stdio.h>
#include <string>
using namespace std;

int leftMost(string &s1)
{
    char count[256] = {0};

    for (int i = 0; i < s1.length(); i++)
    {
        count[s1[i]]++;
    }

    for (int i = 0; i < s1.length(); i++)
    {
        if (count[s1[i]] > 1)
            return i;
    }

    return -1;
}

int main()
{
    string s1 = "geeksforgeeks";
    printf("%d\n", leftMost(s1));
    string s3 = "abbcc";
    printf("%d\n", leftMost(s3));
    string s5 = "abcd";
    printf("%d\n", leftMost(s5));
}