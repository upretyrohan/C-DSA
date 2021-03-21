#include <stdio.h>
#include <string>
#include <stack>

using namespace std;

bool matchPattern(char top, char s)
{
    return ((top == '(' && s == ')') || (top == '{' && s == '}') || (top == '[' && s == ']'));
}

bool isBalancedParanthesis(string s)
{
    stack<char> st;
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] == '(' || s[i] == '[' || s[i] == '{')
            st.push(s[i]);

        else
        {
            if (st.empty() == true) return false;
            else if (matchPattern(st.top(), s[i]) == false) return false;
            else st.pop();
        }
    }

    return true;
}

int main()
{
    string s = "([])";
    printf("%d\n", isBalancedParanthesis(s));

    string s1 = "[{]}";
    printf("%d\n", isBalancedParanthesis(s1));

    string s2 = "{}[()]";
    printf("%d\n", isBalancedParanthesis(s2));
}