/*
    HDU1020 Encoding
    http://acm.hdu.edu.cn/showproblem.php?pid=1020
    Created at 12/31/2019 by MFunction.
 */
#define LOCAL

#include <cstdio>
#include <cstring>

const auto MAXN = 10000 + 10;

char str[MAXN];

int main()
{
#ifdef LOCAL
    freopen("1020.in", "r", stdin);
    freopen("1020.out", "w", stdout);
#endif
    int n;
    while (scanf("%d", &n) == 1)
    {
        while (n--)
        {
            scanf("%s", str);
            auto l = strlen(str);
            char c = '\0';
            int cnt = 1;
            for (auto i = 0; i < l; ++i)
            {
                if (str[i] == c) ++cnt;
                else 
                {
                    if (c == '\0') c = str[i];
                    else 
                    {
                        if (cnt > 1) printf("%d", cnt);
                        putchar(c);
                        c = str[i];
                        cnt = 1;
                    }
                }
            }
            if (cnt > 1) printf("%d", cnt);
            printf("%c\n", c);
        }
    }
#ifdef LOCAL
    freopen("CON", "r", stdin);
    freopen("CON", "w", stdout);
#endif
    return 0;
}