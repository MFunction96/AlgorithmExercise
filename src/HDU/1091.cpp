/*
	HDU1091 A+B for Input-Output Practice (III)
	http://acm.hdu.edu.cn/showproblem.php?pid=1091
	Created at 06/14/2020 by MFunction.
 */
#define LOCAL

#include <cstdio>

int main()
{
#ifdef LOCAL
	freopen("1091.in", "r", stdin);
	freopen("1091.out", "w", stdout);
#endif
	int a, b;
	while (scanf("%d%d", &a, &b), a || b)
	{
		printf("%d\n", a + b);
	}
#ifdef LOCAL
	freopen("CON", "r", stdin);
	freopen("CON", "w", stdout);
#endif
	return 0;
}