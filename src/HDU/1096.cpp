/*
	HDU1096 A+B for Input-Output Practice (VIII)
	http://acm.hdu.edu.cn/showproblem.php?pid=1096
	Created at 06/14/2020 by MFunction.
 */
#define LOCAL

#include <cstdio>

int main()
{
#ifdef LOCAL
	freopen("1096.in", "r", stdin);
	freopen("1096.out", "w", stdout);
#endif
	int t;
	while (scanf("%d", &t) == 1)
	{
		auto flag = true;
		while (t--)
		{
			int n;
			scanf("%d", &n);
			int num, ans = 0;
			while (n--)
			{
				scanf("%d", &num);
				ans += num;
			}
			if (flag) printf("%d\n", ans);
			else printf("\n%d\n", ans);
			flag = false;
		}
	}
#ifdef LOCAL
	freopen("CON", "r", stdin);
	freopen("CON", "w", stdout);
#endif
	return 0;
}