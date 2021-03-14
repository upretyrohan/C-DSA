#include <stdio.h>
#include <string>
using namespace std;

bool isPalindrome(string& s)
{
    int begin = 0;
    int end = s.length() - 1;
    while (begin < end)
    {
        if (s[begin] != s[end])
            return false;
        else
            begin++;
            end--;
    }

    return true;
}

int main()
{
    string a = "ABCCBA";
    printf("%d",isPalindrome(a));

}