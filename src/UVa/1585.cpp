/*
    UVa1585 - Score
    https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=448&page=show_problem&problem=4460
    Created at 08/21/2019 by MFunction.
 */

#include <cstdio>

int main()
{
    //freopen("1585.in", "r", stdin);
    int n;
    while (scanf("%d", &n) == 1)
    {
        getchar();
        while (n--)
        {
            char c;
            auto cnt = 0, ans = 0;;
            while (c = getchar(), c != '\n')            
            {
                if (c == 'O') ans += ++cnt;
                else cnt = 0;
            }
            printf("%d\n", ans);
        }
    }
    //freopen("CON", "r", stdin);
    return 0;
}