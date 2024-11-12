/*
    UVa1329 Corporative Network
    https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=497&page=show_problem&problem=4075
    Created at 11/12/2024 by MFunction.
 */

#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int MAXN = 20000 + 20;
int root[MAXN], d[MAXN];

int findset(int x)
{
	if (root[x] == x) return x;
	else
	{
		int r = findset(root[x]);
		d[x] += d[root[x]];
		return root[x] = r;
	}
}

int main()
{
	//freopen("1329.in", "r", stdin);
	int T;
	while (scanf("%d", &T) == 1)
	{
		while (T--)
		{
			int n;
			scanf("%d\n", &n);
			for (int i = 1; i <= n; ++i) root[i] = i;
			memset(d, 0, sizeof(d));
			char cmd;
			while (cmd = getchar(), cmd != 'O')
			{
				if (cmd == 'E')
				{
					int e;
					scanf("%d\n", &e);
					findset(e);
					printf("%d\n", d[e]);
				}
				else
				{
					int I, J;
					scanf("%d%d\n", &I, &J);
					root[I] = J;
					d[I] = abs(I - J) % 1000;
				}
			}
		}
	}
	return 0;
}