/*
	HDU1089 A+B for Input-Output Practice (I)
	http://acm.hdu.edu.cn/showproblem.php?pid=1089
	Created at 06/14/2020 by MFunction.
 */
#define LOCAL

#include <cstdio>

int main()
{
#ifdef LOCAL
	freopen("1089.in", "r", stdin);
	freopen("1089.out", "w", stdout);
#endif
	int a, b;
	while (scanf("%d%d", &a, &b) == 2) printf("%d\n", a + b);
#ifdef LOCAL
	freopen("CON", "r", stdin);
	freopen("CON", "w", stdout);
#endif
	return 0;
}