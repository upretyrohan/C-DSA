#include <stdio.h>
#include <string>
using namespace std;

bool isAnagram(string &s1, string &s2)
{
    char count[256] = {0};
    if (s1.length() != s2.length())
        return false;

    for (int i = 0; i < s1.length(); i++)
    {
        count[s1[i]]++;
        count[s2[i]]--;
    }

    for (int i = 0; i < 256; i++)
    {
        if (count[i] != 0)
            return false;
    }

    return true;
}

int main()
{
    string s1 = "silent";
    string s2 = "listen";
    printf("%d\n", isAnagram(s1, s2));
    string s3 = "aaacb";
    string s4 = "cabaa";
    printf("%d\n", isAnagram(s3, s4));
    string s5 = "aab";
    string s6 = "bab";
    printf("%d\n", isAnagram(s5, s6));
}