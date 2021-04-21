/*
	Codeforces 1368C Even Picture
	https://codeforces.com/problemset/problem/1368/C
	Created at 06/18/2020 by MFunction.
 */
#define LOCAL

#include <cstdio>

int main()
{
#ifdef LOCAL
	freopen("1368C.in", "r", stdin);
	freopen("1368C.out", "w", stdout);
#endif
	int t;
	const auto MAXN = 24;
	auto matrix = new int[MAXN];
	for (auto i = 1; i < MAXN; ++i)
		matrix[i] = i * i;
	while (scanf("%d", &t) == 1)
	{
		for (auto i = 1; i < MAXN; ++i)
		{
			if (t > matrix[i]) continue;
			if (t == matrix[i])
			{
				printf("%d\n", (i + 2) * (i + 2) - 4);
				auto bolder = i + 2;
				for (auto y = 0; y < bolder; ++y)
				{
					for (auto x = 0; x < bolder; ++x)
					{
						if (x == 0 && y == 0)
							continue;
						if (x == bolder - 1 && y == bolder - 1)
							continue;
						if (x == 0 && y == bolder - 1)
							continue;
						if (x == bolder - 1 && y == 0)
							continue;
						printf("%d %d\n", x, y);
					}
				}
			}
			else
			{
				if (t == matrix[i] - i)
				{
					printf("%d\n", (i + 2) * (i + 1) - 4);
					auto bolder = i + 2;
					for (auto y = 0; y < bolder - 1; ++y)
					{
						for (auto x = 0; x < bolder; ++x)
						{
							if (x == 0 && y == 0)
								continue;
							if (x == bolder - 1 && y == bolder - 2)
								continue;
							if (x == 0 && y == bolder - 2)
								continue;
							if (x == bolder - 1 && y == 0)
								continue;
							printf("%d %d\n", x, y);
						}
					}
				}
				else if (t < matrix[i] - i)
				{
					auto cnt = (i + 2) * (i + 1) - 4;
					auto bolder = i + 2;
					auto a = matrix[i] - i - t;
					if (a == 1)
					{
						cnt -= 2;
						printf("%d\n", cnt);
						for (auto y = 0; y < bolder - 1; ++y)
						{
							for (auto x = 0; x < bolder; ++x)
							{
								if (x == 0 && y == 0)
									continue;
								if (x == bolder - 1 && y == bolder - 2)
									continue;
								if (x == 0 && y == bolder - 2)
									continue;
								if (x == bolder - 1 && y == 0)
									continue;
								if (x == bolder - 2 && y == bolder - 2)
									continue;
								if (x == bolder - 1 && y == bolder - 3)
									continue;
								printf("%d %d\n", x, y);
							}
						}
					}
					else if (a == 2)
					{
						cnt -= 4;
						printf("%d\n", cnt);
						for (auto y = 0; y < bolder - 1; ++y)
						{
							for (auto x = 0; x < bolder; ++x)
							{
								if (x == 0 && y == 0)
									continue;
								if (x == bolder - 1 && y == bolder - 2)
									continue;
								if (x == 0 && y == bolder - 1)
									continue;
								if (x == bolder - 1 && y == 0)
									continue;
								if (x == bolder - 2 && y == bolder - 2)
									continue;
								if (x == bolder - 1 && y == bolder - 3)
									continue;
								if (x == bolder - 1 && y == 1)
									continue;
								if (x == bolder - 2 && y == 0)
									continue;	
								printf("%d %d\n", x, y);
							}
						}
					}
					else
					{
						cnt -= a + 2;
						printf("%d\n", cnt);
						for (auto y = 0; y < bolder - 1; ++y)
						{
							for (auto x = 0; x < bolder; ++x)
							{
								if (x == 0 && y == 0)
									continue;
								if (x == bolder - 1 && y == bolder - 2)
									continue;
								if (x == 0 && y == bolder - 1)
									continue;
								if (x == bolder - 1 && y == 0)
									continue;
								if (x == bolder - 2 && y == bolder - 2)
									continue;
								if (x == bolder - 1 && y == bolder - 3)
									continue;
								if (x == bolder - 1 && y == 1)
									continue;
								if (x == bolder - 2 && y == 0)
									continue;	
								printf("%d %d\n", x, y);
							}
						}
					}
					
				}
				else
				{
					auto cnt = (i + 2) * (i + 2) - 4;
					auto bolder = i + 2;
					auto a = matrix[i] - t;
					if (a == 1)
					{
						cnt -= 2;
						printf("%d\n", cnt);
						for (auto y = 0; y < bolder; ++y)
						{
							for (auto x = 0; x < bolder; ++x)
							{
								if (x == 0 && y == 0)
									continue;
								if (x == bolder - 1 && y == bolder - 1)
									continue;
								if (x == 0 && y == bolder - 1)
									continue;
								if (x == bolder - 1 && y == 0)
									continue;
								if (x == bolder - 2 && y == bolder - 1)
									continue;
								if (x == bolder - 1 && y == bolder - 2)
									continue;
								printf("%d %d\n", x, y);
							}
						}
					}
					else if (a == 2)
					{
						cnt -= 4;
						printf("%d\n", cnt);
						for (auto y = 0; y < bolder; ++y)
						{
							for (auto x = 0; x < bolder; ++x)
							{
								if (x == 0 && y == 0)
									continue;
								if (x == bolder - 1 && y == bolder - 1)
									continue;
								if (x == 0 && y == bolder - 1)
									continue;
								if (x == bolder - 1 && y == 0)
									continue;
								if (x == bolder - 2 && y == bolder - 1)
									continue;
								if (x == bolder - 1 && y == bolder - 2)
									continue;
								if (x == bolder - 1 && y == 1)
									continue;
								if (x == bolder - 2 && y == 0)
									continue;	
								printf("%d %d\n", x, y);
							}
						}
					}
					else
					{
						cnt -= a + 2;
						printf("%d\n", cnt);
						for (auto y = 0; y < bolder; ++y)
						{
							for (auto x = 0; x < bolder; ++x)
							{
								if (x == 0 && y == 0)
									continue;
								if (x == bolder - 1 && y == bolder - 1)
									continue;
								if (x == 0 && y == bolder - 1)
									continue;
								if (x == bolder - 1 && y == 0)
									continue;
								if (x == bolder - 2 && y == bolder - 1)
									continue;
								if (x == bolder - 1 && y == bolder - 2)
									continue;
								if (x == bolder - 1 && y == 1)
									continue;
								if (x == bolder - 2 && y == 0)
									continue;	
								printf("%d %d\n", x, y);
							}
						}
					}
				}
			}
			break;
		}
	}
	delete[] matrix;
#ifdef LOCAL
	freopen("CON", "r", stdin);
	freopen("CON", "w", stdout);
#endif
	return 0;
}