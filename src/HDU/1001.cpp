/*
    HDU1001 Sum Problem
    http://acm.hdu.edu.cn/showproblem.php?pid=1001
    Created at 12/29/2019 by MFunction.
 */
#define LOCAL

#include <cstdio>

int main()
{
#ifdef LOCAL
    freopen("1001.in", "r", stdin);
    freopen("1001.out", "w", stdout);
#endif
    long long a;
    while (scanf("%lld", &a) == 1) printf("%lld\n\n", ((1 + a) * a) >> 1);
#ifdef LOCAL
    freopen("CON", "r", stdin);
    freopen("CON", "w", stdout);
#endif
    return 0;
}