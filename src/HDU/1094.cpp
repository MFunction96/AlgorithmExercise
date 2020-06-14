/*
	HDU1094 A+B for Input-Output Practice (VI)
	http://acm.hdu.edu.cn/showproblem.php?pid=1094
	Created at 06/14/2020 by MFunction.
 */
#define LOCAL

#include <cstdio>

int main()
{
#ifdef LOCAL
	freopen("1094.in", "r", stdin);
	freopen("1094.out", "w", stdout);
#endif
	int n;
	while (scanf("%d", &n) == 1)
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