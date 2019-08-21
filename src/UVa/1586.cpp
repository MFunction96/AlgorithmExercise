/*
    UVa1586 - Molar mass
    https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=448&page=show_problem&problem=4461
    Created at 08/21/2019 by MFunction.
 */

#include <cstdio>
#include <cctype>

double cal(char atom, int cnt)
{
    if (!cnt) ++cnt;
    if (atom == 'C') return 12.01 * cnt;
    if (atom == 'H') return 1.008 * cnt;
    if (atom == 'O') return 16.00 * cnt;
    if (atom == 'N') return 14.01 * cnt;
    return 0.0;
}

int main()
{
    //freopen("1586.in", "r", stdin);
    int n;
    while (scanf("%d", &n) == 1)
    {
        getchar();
        while (n--)
        {
            char c = 0, lc = 0;
            auto cnt = 0;
            auto ans = 0.0;
            while (c = getchar(), c != '\n' && c != EOF)            
            {
                if (isalpha(c))
                {
                    
                    ans += cal(lc, cnt);
                    lc = c;
                    cnt = 0;
                }
                else cnt = cnt * 10 + c - '0';
            }
            ans += cal(lc, cnt);
            printf("%.3f\n", ans);
        }
    }
    //freopen("CON", "r", stdin);
    return 0;
}