/*
	Codeforces 1374A Required Remainder
	https://codeforces.com/problemset/problem/1374/A
	Created at 06/28/2020 by MFunction.
 */
#define LOCAL

#include <cstdio>
#include <cmath>

int main()
{
#ifdef LOCAL
	freopen("1374A.in", "r", stdin);
	freopen("1374A.out", "w", stdout);
#endif
	int t;
	while (scanf("%d", &t) == 1)
	{
		while (t--)
		{
			int x, y, n;
            scanf("%d%d%d", &x, &y, &n);
			int ans = 0;
			if (n % x < y) ans = (n / x - 1) * x + y;
            else ans = n / x * x + y;
			printf("%d\n", ans < 0 ? 0 : ans);
		}
	}
#ifdef LOCAL
	freopen("CON", "r", stdin);
	freopen("CON", "w", stdout);
#endif
	return 0;
}