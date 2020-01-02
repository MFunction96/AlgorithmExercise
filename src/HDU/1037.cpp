/*
    HDU1037 Keep on Truckin'
    http://acm.hdu.edu.cn/showproblem.php?pid=1037
    Created at 01/02/2020 by MFunction.
 */
#define LOCAL

#include <cstdio>

int main()
{
#ifdef LOCAL
    freopen("1037.in", "r", stdin);
    freopen("1037.out", "w", stdout);
#endif
    int a, b, c;
    while (scanf("%d%d%d", &a, &b, &c) == 3)
    {
        if (a <= 168) printf("CRASH %d\n", a);
        else if (b <= 168) printf("CRASH %d\n", b);
        else if (c <= 168) printf("CRASH %d\n", c);
        else printf("NO CRASH\n");
    }
#ifdef LOCAL
    freopen("CON", "r", stdin);
    freopen("CON", "w", stdout);
#endif
    return 0;
}