/*
	Codeforces 1374D Zero Remainder Array
	https://codeforces.com/problemset/problem/1374/D
	Created at 06/28/2020 by MFunction.
 */
#define LOCAL

#include <cstdio>
#include <map>
using namespace std;

map<int, int> mod;

int main()
{
#ifdef LOCAL
	freopen("1374D.in", "r", stdin);
	freopen("1374D.out", "w", stdout);
#endif
	int t;
	while (scanf("%d", &t) == 1)
	{
		while (t--)
		{
			mod.clear();
			int n, k;
			scanf("%d%d", &n, &k);
			auto max = -1;
			auto xmod = -1;
			while (n--)
			{
				int num;
				scanf("%d", &num);
				auto tmp = k - num % k;
				if (mod.find(tmp) != mod.end()) mod[tmp]++;
				else mod[tmp] = 1;
				if (tmp != k && mod[tmp] >= max)
				{
					if (tmp < xmod && mod[tmp] == max) continue;
					max = mod[tmp];
					xmod = tmp;
				}
			}
			if (xmod == -1) printf("0\n");
			else printf("%d\n", (--max) * k + xmod + 1);
		}
	}
#ifdef LOCAL
	freopen("CON", "r", stdin);
	freopen("CON", "w", stdout);
#endif
	return 0;
}