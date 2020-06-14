/*
	HDU1095 A+B for Input-Output Practice (VII)
	http://acm.hdu.edu.cn/showproblem.php?pid=1095
	Created at 06/14/2020 by MFunction.
 */
#define LOCAL

#include <cstdio>

int main()
{
#ifdef LOCAL
	freopen("1095.in", "r", stdin);
	freopen("1095.out", "w", stdout);
#endif
	int a, b;
	while (scanf("%d%d", &a, &b) == 2)
	{
		printf("%d\n\n", a + b);
	}
#ifdef LOCAL
	freopen("CON", "r", stdin);
	freopen("CON", "w", stdout);
#endif
	return 0;
}