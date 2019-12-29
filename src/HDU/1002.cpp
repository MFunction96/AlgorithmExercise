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
            reverse(a);
            reverse(b);
            auto l1 = strlen(a);
            auto l2 = strlen(b);
            auto l = l1 < l2 ? l1 : l2;
            auto exceed = false;
            for (auto i = 0; i < l; ++i)
            {
                auto tmp = a[i] + b[i] - '0' - '0';
                if (exceed) ++tmp;
                if (tmp > 9)
                {
                    exceed = true;
                    tmp %= 10;
                }
                else exceed = false;
                ans[i] = '0' + tmp;
            }
            if (exceed) 
            {
                ans[l] = '1';
                ans[l + 1] = 0;
            }
            reverse(a);
            reverse(b);
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