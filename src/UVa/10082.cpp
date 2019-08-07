/*
    UVa10082 - WERTYU
    https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=12&page=show_problem&problem=1023
    Created at 08/06/2019.
 */

#include <cstdio>

int main()
{
    const auto ch = "`1234567890-=QWERTYUIOP[]\\ASDFGHJKL;'ZXCVBNM,./";
    //freopen("10082.in", "r", stdin);
    int c;
    while (c = getchar(), c != EOF)
    {
        auto i = 1;
        for (; ch[i] && ch[i] != c; i++)
            ;
        if (ch[i])
            putchar(ch[i - 1]);
        else
            putchar(c);
    }
    //freopen("CON", "r", stdin);
    return 0;
}