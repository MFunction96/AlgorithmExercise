/*
    UVa401 - Palindromes
    https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=6&page=show_problem&problem=342
    Created at 08/09/2019 by MFunction.
 */

#include <cstdio>
#include <cstring>
#include <cctype>

const int MAXN = 300 + 10;
char str[MAXN];
const char *rev = "A   3  HIL JM O   2TUVWXY51SE Z  8 ";
const char *msg[] = {"not a palindrome.\n\n", "a regular palindrome.\n\n","a mirrored string.\n\n","a mirrored palindrome.\n\n"};

char revchar(char c)
{
    return isalpha(c) ? rev[c - 'A'] : rev[c + 25 - '0'];
}

int main()
{
    //freopen("401.in", "r", stdin);  
    while (scanf("%s", str) == 1)
    {
        const auto len = strlen(str);
        auto flag = 3;
        for (auto i = 0;i < (len + 1 >> 1) && flag;i++)
        {
            if (str[i] != str[len - 1 - i]) flag &= 2;
            if (str[i] != revchar(str[len - 1 - i])) flag &= 1;
        }
        printf("%s -- is %s", str, msg[flag]);
    }
    //freopen("CON", "r", stdin);
    return 0;
}