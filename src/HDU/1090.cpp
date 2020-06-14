/*
	HDU1090 A+B for Input-Output Practice (II)
	http://acm.hdu.edu.cn/showproblem.php?pid=1090
	Created at 06/14/2020 by MFunction.
 */
#define LOCAL

#include <cstdio>

int main()
{
#ifdef LOCAL
	freopen("1090.in", "r", stdin);
	freopen("1090.out", "w", stdout);
#endif
	int t;
	while (scanf("%d", &t) == 1)
	{
		while (t--)
		{
			int a, b;
			scanf("%d%d", &a, &b);
			printf("%d\n", a + b);
		}
	}
#ifdef LOCAL
	freopen("CON", "r", stdin);
	freopen("CON", "w", stdout);
#endif
	return 0;
}