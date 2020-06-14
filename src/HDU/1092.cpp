/*
	HDU1092 A+B for Input-Output Practice (IV)
	http://acm.hdu.edu.cn/showproblem.php?pid=1092
	Created at 06/14/2020 by MFunction.
 */
#define LOCAL

#include <cstdio>

int main()
{
#ifdef LOCAL
	freopen("1092.in", "r", stdin);
	freopen("1092.out", "w", stdout);
#endif
	int n;
	while (scanf("%d", &n), n)
	{
		int ans = 0, num;
		while (n--)
		{
			scanf("%d", &num);
			ans += num;
		}
		printf("%d\n", ans);
	}
#ifdef LOCAL
	freopen("CON", "r", stdin);
	freopen("CON", "w", stdout);
#endif
	return 0;
}