/*
    UVa455 - Digit Counting
    https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=396
    Created at 12/25/2019 by MFunction.
 */
#define LOCAL

#include <cstdio>
#include <cstring>

const auto MAXN = 100 + 10;

int main()
{
    int n;
#ifdef LOCAL
    freopen("455.in", "r", stdin);
#endif
    while (scanf("%d", &n) == 1)
    {
        while (n--)
        {
            auto str = new char[MAXN];
            scanf("%s", str);
            auto len = strlen(str);
            auto ans = 0;
            for (auto i = 1; i <= len; ++i)
            {
                ans = -1;
                for (auto j = 0; j < len; ++j)
                {
                    if (str[j] != str[(i + j) % len]) 
                    {
                        ans = 0;
                        break;
                    }
                }
                if (ans) 
                {
                    ans = i;
                    break;
                }
            }
            delete[] str;
            printf("%d\n", ans);
            if (n) putchar('\n');
        }
    }
#ifdef LOCAL
    freopen("CON", "r", stdin);
#endif
    return 0;
}