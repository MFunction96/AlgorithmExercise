/*
    HDU1000 A + B Problem
    http://acm.hdu.edu.cn/showproblem.php?pid=1000
    Created at 12/29/2019 by MFunction.
 */
#define LOCAL

#include <cstdio>

int main()
{
#ifdef LOCAL
    freopen("1000.in", "r", stdin);
    freopen("1000.out", "w", stdout);
#endif
    int a, b;
    while (scanf("%d%d", &a, &b) == 2) printf("%d\n", a + b);
#ifdef LOCAL
    freopen("CON", "r", stdin);
    freopen("CON", "w", stdout);
#endif
    return 0;
}