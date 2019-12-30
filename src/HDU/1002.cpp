/*
    HDU1002 A + B Problem II
    http://acm.hdu.edu.cn/showproblem.php?pid=1002
    Created at 12/29/2019 by MFunction.
 */
#define LOCAL

#include <cstdio>
#include <cstring>

const auto MAXN = 1000 + 10;

char a[MAXN], b[MAXN], ans[MAXN];

void reverse(char* str)
{
    auto l = strlen(str);
    for (auto i = 0; i < l >> 1; ++i)
    {
        auto tmp = str[i];
        str[i] = str[l - i - 1];
        str[l - i - 1] = tmp;
    }
}

int main()
{
#ifdef LOCAL
    freopen("1002.in", "r", stdin);
    freopen("1002.out", "w", stdout);
#endif
    int t;
    while (scanf("%d", &t) == 1)
    {
        for (auto cnt = 1; cnt <= t; ++cnt)
        {
            if (cnt > 1) printf("\nCase %d:\n", cnt);
            else printf("Case %d:\n", cnt);
            scanf("%s%s", a, b);
            memset(ans, 0 ,sizeof ans);
            int l1 = strlen(a);
            int l2 = strlen(b);
            auto l = l1 > l2 ? l1 : l2;
            auto exceed = false;
            for (auto i = 0; i < l; ++i)
            {
                auto i1 = l1 - 1 - i;
                auto i2 = l2 - 1 - i;
                auto n1 = (i1 < 0 ? 0 : a[i1] - '0');
                auto n2 = (i2 < 0 ? 0 : b[i2] - '0');
                auto tmp = n1 + n2;
                if (exceed) ++tmp;
                exceed = tmp > 9;
                ans[i] = tmp % 10 + '0';
            }
            if (exceed) ans[l] = '1';
            reverse(ans);
            printf("%s + %s = %s\n", a, b, ans);
        }
    }
#ifdef LOCAL
    freopen("CON", "r", stdin);
    freopen("CON", "w", stdout);
#endif
    return 0;
}