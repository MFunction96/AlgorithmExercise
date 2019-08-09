/*
    UVa401 - Palindromes
    https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=6&page=show_problem&problem=342
    Created at 08/09/2019 by MFunction.
 */

#include <cstdio>
#include <cstring>

const int MAXN = 300 + 10;
char str[MAXN];
bool ch[100];

int main()
{
    freopen("401.in", "r", stdin);
    memset(ch, 0, sizeof ch);
    ch['A'] = true;
    ch['E'] = true;
    ch['H'] = true;
    ch['I'] = true;
    ch['J'] = true;
    ch['L'] = true;
    ch['M'] = true;
    ch['O'] = true;
    ch['S'] = true;
    ch['T'] = true;
    ch['U'] = true;
    ch['V'] = true;
    ch['W'] = true;
    ch['X'] = true;
    ch['Y'] = true;
    ch['Z'] = true;
    ch['1'] = true;
    ch['2'] = true;
    ch['3'] = true;
    ch['5'] = true;
    ch['8'] = true;
    while (scanf("%s", str) == 1)
    {
        printf("%s -- is ", str);
        const auto len = strlen(str);
        auto flag = 3;
        for (auto i = 0;i < len && flag;i++)
        {
            if (flag & 1 && str[i] != str[len - 1 - i])
            {
                flag &= 2;
            }
            if (flag & 2 && !ch[str[i]])
            {
                flag &= 1;
            }
        }
        if (flag == 0) printf("not a palindrome.\n\n");
        else if (flag == 1) printf("a regular palindrome.\n\n");
        else if (flag == 2) printf("a mirrored string.\n\n");
        else printf("a mirrored palindrome.\n\n");
    }
    freopen("CON", "r", stdin);
    return 0;
}