/*
    UVa1586 - Molar mass
    https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=448&page=show_problem&problem=4461
    Created at 08/21/2019 by MFunction.
 */

#include <cstdio>
#include <cstring>
#include <cctype>

const auto MAXN = 100 + 10;

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
            auto str = new char[MAXN];
            scanf("%s", str);
            const auto len = strlen(str);
            auto cnt = 0;
            double ans = 0.0;
            char c = 0;
            for (auto i = 0;i < len;++i)            
            {
                if (isalpha(str[i]))
                {
                    ans += cal(c, cnt);
                    c = str[i];
                    cnt = 0;
                }
                else cnt = cnt * 10 + str[i] - '0';
            }
            ans += cal(c, cnt);
            printf("%.3f\n", ans);
            delete str;
        }
    }
    //freopen("CON", "r", stdin);
    return 0;
}