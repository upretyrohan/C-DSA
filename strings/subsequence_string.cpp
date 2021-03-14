#include <stdio.h>
#include <string>
using namespace std;

bool issubsequence(string &s1, string &s2)
{
    int m = s2.length() - 1;
    int n = s1.length() - 1;
    int j = 0;
    for (int i = 0; i < n && j < m; i++)
    {
        if (s2[j] == s1[i])
        {
            j++;
        }
    }

    return (j==m);
}

int main()
{
    string s1 = "ABCD";
    string s2 = "ABD";
    printf("%d\n", issubsequence(s1, s2));

    string s3 = "ABCDE";
    string s4 = "AED";
    printf("%d", issubsequence(s3, s4));
}