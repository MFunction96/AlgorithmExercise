/*
	Codeforces 1370C Number Game
	https://codeforces.com/problemset/problem/1370/C
	Created at 06/20/2020 by MFunction.
 */
#define LOCAL

#include <cstdio>
#include <cmath>

bool isprime(int number)
{
	if (number < 4) return true;
	if (number % 6 != 1 && number % 6 != 5) return false;
	int sq = sqrt(number);
	for (auto i = 5; i <= sq; i += 6)
	{
		if (number % i == 0) return false;
	}
	return true;
}

int main()
{
#ifdef LOCAL
	freopen("1370C.in", "r", stdin);
	freopen("1370C.out", "w", stdout);
#endif
	int t;
	while (scanf("%d", &t) == 1)
	{
		while (t--)
		{
			int n;
			scanf("%d", &n);
			if (n == 1) printf("FastestFinger\n");
			else if (n == 2 || n % 2) printf("Ashishgup\n");
			else if (isprime(n >> 1)) printf("FastestFinger\n");
			else printf("Ashishgup\n");
		}
	}
#ifdef LOCAL
	freopen("CON", "r", stdin);
	freopen("CON", "w", stdout);
#endif
	return 0;
}