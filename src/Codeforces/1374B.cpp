/*
	Codeforces 1374B Multiply by 2, divide by 6
	https://codeforces.com/problemset/problem/1374/B
	Created at 06/28/2020 by MFunction.
 */
#define LOCAL

#include <cstdio>
#include <cmath>

int main()
{
#ifdef LOCAL
	freopen("1374B.in", "r", stdin);
	freopen("1374B.out", "w", stdout);
#endif
	int t;
	while (scanf("%d", &t) == 1)
	{
		while (t--)
		{
			int n;
			scanf("%d", &n);
			if (n == 1) 
			{
				printf("0\n");
				continue;
			}
			if (n % 6 == 1 || n % 6 == 5) 
			{
				printf("-1\n");
				continue;
			}
			auto ans = 0;
			while (n > 1)
			{
				if (n % 3) 
				{
					ans = -1;
					break;
				}
				if (n % 6)
				{
					++ans;
					n <<= 1;
				}
				n /= 6;
				++ans;
			}
			printf("%d\n", ans);
		}
	}
#ifdef LOCAL
	freopen("CON", "r", stdin);
	freopen("CON", "w", stdout);
#endif
	return 0;
}