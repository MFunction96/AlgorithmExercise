/*
	Codeforces 1370A Even Picture
	https://codeforces.com/problemset/problem/1370/A
	Created at 06/20/2020 by MFunction.
 */
#define LOCAL

#include <cstdio>
#include <cmath>
#include <vector>
using namespace std;

vector<int> prime;

bool isprime(int number)
{
	if (number == 2) return true;
	if (number % 2 == 0) return false;
	int sq = sqrt(number);
	for (auto i = 1; prime[i] <= sq; ++i)
	{
		if (number % prime[i] == 0) return false;
	}
	return true;
}

int main()
{
#ifdef LOCAL
	freopen("1370A.in", "r", stdin);
	freopen("1370A.out", "w", stdout);
#endif
	prime.push_back(2);
	prime.push_back(3);
	prime.push_back(5);
	prime.push_back(7);
	prime.push_back(11);
	for (auto i = 13; i < 100000 + 10; i += 2)
	{
		if (isprime(i)) prime.push_back(i);
	}
	int t;

	while (scanf("%d", &t) == 1)
	{
		while (t--)
		{
			int n;
			scanf("%d", &n);
			auto ans = 1;
			int sq = sqrt(n);
			printf("%d\n", ans);
		}
	}
#ifdef LOCAL
	freopen("CON", "r", stdin);
	freopen("CON", "w", stdout);
#endif
	return 0;
}