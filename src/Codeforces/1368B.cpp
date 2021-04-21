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
	freopen("1368B.in", "r", stdin);
	freopen("1368B.out", "w", stdout);
#endif
	int t;
	while (scanf("%d", &t) == 1)
	{
		if (t < 11)
		{
			printf("codeforce");
			for (auto i = 0; i < t; ++i) printf("s");
		}
		else
		{
			
		}
		
	}
#ifdef LOCAL
	freopen("CON", "r", stdin);
	freopen("CON", "w", stdout);
#endif
	return 0;
}