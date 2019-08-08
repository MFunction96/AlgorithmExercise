/*
    UVa272 - TEX Quotes
    https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=4&page=show_problem&problem=208
    Created at 08/08/2019 by MFunction.
 */

#include <cstdio>

int main()
{
    freopen("272.in", "r", stdin);
    auto flag = false;
    int c;
    while (c = getchar(), c != EOF)
    {
        if (c == '\"') printf("%s", flag ? "\'\'" : "``");
        else putchar(c);
        flag = !flag;
    }
    freopen("CON", "r", stdin);
    return 0;
}