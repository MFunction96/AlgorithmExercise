/*
	Codeforces 1374C Move Brackets
	https://codeforces.com/problemset/problem/1374/C
	Created at 06/28/2020 by MFunction.
 */
#define LOCAL

#include <cstdio>
#include <cmath>
#include <stack>
using namespace std;

int main()
{
#ifdef LOCAL
	freopen("1374C.in", "r", stdin);
	freopen("1374C.out", "w", stdout);
#endif
	int t;
	while (scanf("%d", &t) == 1)
	{
		while (t--)
		{
			int n;
			scanf("%d\n", &n);
			auto ans = 0;
			auto s = new stack<char>();
			char c;
			while (c = getchar(), c != '\n' && c != EOF)
			{
				if (c == '(') s->push(c);
				else if (!s->empty()) s->pop();
			}
			printf("%d\n", int(s->size()));
			delete s;
		}
	}
#ifdef LOCAL
	freopen("CON", "r", stdin);
	freopen("CON", "w", stdout);
#endif
	return 0;
}