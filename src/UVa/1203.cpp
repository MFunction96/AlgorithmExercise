/*
    UVa1203 - Argus
    https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=497&page=show_problem&problem=3644
    Created at 11/11/2024 by MFunction.
 */

#include <algorithm>
#include <cstdio>
#include <cstring>
#include <map>
#include <queue>
using namespace std;

map<int,int> c;
priority_queue<int, vector<int>, greater<int> > pq;

int gcd(int x, int y)
{
	int r;
	while (x % y != 0)
	{
		r = x % y;
		x = y;
		y = r;
	}

	return y;
}

int main()
{
	//freopen("1203.in", "r", stdin);
	char cmd[20];
	int g = 0;
	while (scanf("%s", cmd), strcmp(cmd, "#") != 0)
	{
		int q, p;
		scanf("%d%d", &q, &p);
		c[q] = p;
		if (g == 0) g = p;
		else g = gcd(g, p);
	}
	int k;
	scanf("%d", &k);
	for (int i = g, cnt = 0; cnt < k; i += g)
	{
		for (auto it = c.begin(); it != c.end(); ++it)
		{
			if (i % it->second == 0) pq.push(it->first);
		}

		while (!pq.empty())
		{
			printf("%d\n", pq.top());
			if (++cnt == k)
			{
				break;
			}

			pq.pop();
		}
	}
	//freopen("CON", "r", stdin);
	return 0;
}