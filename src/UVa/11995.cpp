/*
    UVa11995 - I Can Guess the Data Structure!
    https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=229&page=show_problem&problem=3146
    Created at 11/11/2024 by MFunction.
 */

#include <cstdio>
#include <queue>
#include <stack>
using namespace std;

int main()
{
	//freopen("11995.in", "r", stdin);
	int n;
	while (scanf("%d", &n) == 1)
	{
		int ans = 7;
		stack<int> s;
		queue<int> q;
		priority_queue<int> pq;
		while (n--)
		{
			int op, x;
			scanf("%d%d", &op, &x);
			if (op == 1)
			{
				s.push(x);
				q.push(x);
				pq.push(x);
			}
			else
			{
				if (s.empty())
				{
					ans = 0;
					continue;
				}

				int t;
				t = s.top();
				if (t != x) ans &= 3;
				t = q.front();
				if (t != x) ans &= 5;
				t = pq.top();
				if (t != x) ans &= 6;
				s.pop();
				q.pop();
				pq.pop();
			}
		}

		if (ans == 4) printf("stack\n");
		else if (ans == 2) printf("queue\n");
		else if (ans == 1) printf("priority queue\n");
		else if (ans == 0) printf("impossible\n");
		else printf("not sure\n");
	}
	//freopen("CON", "r", stdin);
	return 0;
}