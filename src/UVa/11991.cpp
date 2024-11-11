/*
    UVa11991 - Easy Problem from Rujia Liu?
    https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=229&page=show_problem&problem=3142
    Created at 11/11/2024 by MFunction.
 */

#include <cstdio>
#include <vector>
#include <map>
using namespace std;

map<int, vector<int> > vec;

int main()
{
	//freopen("11991.in", "r", stdin);
	int n, m;
	while (scanf("%d%d", &n, &m) == 2)
	{
		vec.clear();
		int pos = 0;
		for (int i = 1; i <= n; ++i)
		{
			int number;
			scanf("%d", &number);
			if (vec.find(number) == vec.end()) vec[number] = vector<int>();
			vec[number].push_back(i);
		}
		while (m--)
		{
			int k, v;
			scanf("%d%d", &k, &v);
			if (vec.find(v) == vec.end() || vec[v].size() < k) printf("0\n");
			else printf("%d\n", vec[v][k - 1]);
		}
	}
	//freopen("CON", "r", stdin);
	return 0;
}