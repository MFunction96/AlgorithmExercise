/*
    UVa1583 - Digit Generator
    https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=448&page=show_problem&problem=4458
    Created at 08/15/2019 by MFunction.
 */

#include <cstdio>
#include <cstring>

const int MAXN = 100000 + 10;

int gen[MAXN];

int main()
{
    //freopen("1583.in", "r", stdin);  
    memset(gen, 0, sizeof gen);
    for (auto i = 1;i < MAXN;i++)
    {
        auto digit = i;
        for (auto j = i;j;j /= 10) digit += j % 10;
        if (!gen[digit]) gen[digit] = i;
    }
    int t;
    while (scanf("%d", &t) == 1)
    {
        while (t--)
        {
            int n;
            scanf("%d", &n);
            printf("%d\n", gen[n]);
        }
    }
    //freopen("CON", "r", stdin);
    return 0;
}