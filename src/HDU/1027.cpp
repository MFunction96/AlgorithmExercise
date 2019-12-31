/*
    HDU1027 Ignatius and the Princess II
    http://acm.hdu.edu.cn/showproblem.php?pid=1027
    Created at 12/31/2019 by MFunction.
 */
#define LOCAL

#include <cstdio>
#include <algorithm>
using namespace std;

const auto MAXN = 1000 + 10;

int num[MAXN];

int main()
{
#ifdef LOCAL
    freopen("1027.in", "r", stdin);
    freopen("1027.out", "w", stdout);
#endif
    int n, m;
    while (scanf("%d%d", &n, &m) == 2)
    {
        for (auto i = 1; i <= n; ++i) num[i - 1] = i;
        for (auto i = 1; i < m; ++i) next_permutation(num, num + n);
        for (auto i = 0; i < n; ++i)
        {
            if (i) printf(" %d", num[i]);
            else printf("%d", num[i]);
        }
        putchar('\n');
    }
#ifdef LOCAL
    freopen("CON", "r", stdin);
    freopen("CON", "w", stdout);
#endif
    return 0;
}