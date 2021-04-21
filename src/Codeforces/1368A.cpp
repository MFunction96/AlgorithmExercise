/*
	Codeforces 1368A C+=
	https://codeforces.com/problemset/problem/1368/A
	Created at 06/18/2020 by MFunction.
 */
#define LOCAL

#include <cstdio>

int main()
{
#ifdef LOCAL
	freopen("1368A.in", "r", stdin);
	freopen("1368A.out", "w", stdout);
#endif
	int t;
	while (scanf("%d", &t) == 1)
	{
		while (t--)
		{
			int a, b, n;
			scanf("%d%d%d", &a, &b, &n);
			for (auto i = 0;; ++i)
			{
				if (a > n || b > n)
				{
					printf("%d\n", i);
					break;
				}
				if (a < b) a += b;
				else b += a;
			}
		}
	}
#ifdef LOCAL
	freopen("CON", "r", stdin);
	freopen("CON", "w", stdout);
#endif
	return 0;
}