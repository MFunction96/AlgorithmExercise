/*
    UVa11235 Frequent values
    https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=24&page=show_problem&problem=2176
    Created at 11/13/2024 by MFunction.
 */

#include <cstdio>
#include <cmath>
#include <cstring>
#include <cstdint>
#include <tuple>
#include <vector>
using namespace std;

const int MAXN = 100000 + 10;
vector<tuple<int, int, int> > v; // RLE, Run Length Encoding(number, start, length)
vector<int> finder; // data index map to RLE index
int d[MAXN][20]; // RMQ query array

// RMQ for max length of completed number fragments, using Sparse Table
void RMQ_init()
{
	int size = v.size();
	for (int i = 1; i <= size; ++i) d[i][0] = get<2>(v[i]);
	for (int j = 1; (1 << j) <= size; ++j)
		for (int i = 0; i + (1 << j) - 1 < size; ++i) 
			d[i][j] = max(d[i][j - 1], d[i + (1 << (j - 1))][j - 1]);
}

// query among completed number fragments
int RMQ_query(int L, int R)
{
	int k = log2(R - L + 1); // O(1)
	return max(d[L][k], d[R - (1 << k) + 1][k]);
}

int main()
{
	//freopen("11235.in", "r", stdin);
	int n;
	while (scanf("%d", &n), n)
	{
		int q;
		scanf("%d", &q);
		v.clear();
		finder.clear();
		finder.push_back(-1); // fill empty data on index 0 (index range: 1~n)
		memset(d, 0, sizeof(d));
		auto p = make_tuple(INT32_MAX, 1, 1); // init RLE tuple for data input
		int cnt = 0; // RLE index
		for (int i = 1; i <= n; ++i)
		{
			int num;
			scanf("%d", &num);
			if (get<0>(p) == INT32_MAX) // first input
			{
				get<0>(p) = num;
				finder.push_back(cnt); // map data index to RLE index
			}
			else if (get<0>(p) == num) // same number to increase length
			{
				++get<2>(p);
				finder.push_back(cnt);
			}
			else // push previous RLE data then increase RLE index and create new RLE data
			{
				v.push_back(p);
				finder.push_back(++cnt);
				p = make_tuple(num, i, 1);
			}
		}
		if (get<0>(v.back()) != get<0>(p)) // push last RLE data if not in it
		{
			v.push_back(p);
		}
		RMQ_init();
		while (q--)
		{
			int l, r;
			scanf("%d%d", &l, &r);
			int L = finder[l], R = finder[r]; // get RLE index
			if (L == R) printf("%d\n", r - l + 1); // l, r in same RLE
			else if (R - L == 1) printf("%d\n", max(get<2>(v[L]) + get<1>(v[L]) - l, r - get<1>(v[R]) + 1)); // l, r is side-by-side RLE
			else // max(left fragment length, completed parts to RMQ, right fragment length
			{
				int rmq = RMQ_query(L + 1, R - 1);
				printf("%d\n", max(rmq, max(get<2>(v[L]) + get<1>(v[L]) - l, r - get<1>(v[R]) + 1)));
			}
		}
	}
	return 0;
}