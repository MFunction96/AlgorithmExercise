/*
	HDU1093 A+B for Input-Output Practice (V)
	http://acm.hdu.edu.cn/showproblem.php?pid=1093
	Created at 06/14/2020 by MFunction.
 */
#define LOCAL

#include <cstdio>

int main()
{
#ifdef LOCAL
	freopen("1093.in", "r", stdin);
	freopen("1093.out", "w", stdout);
#endif
	int t;
	while (scanf("%d", &t) == 1)
	{
		while (t--)
		{
			int n, ans = 0, num;
			scanf("%d", &n);
			while (n--)
			{
				scanf("%d", &num);
				ans += num;
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