/*
    UVa1225 - Digit Counting
    https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=247&page=show_problem&problem=3666
    Created at 08/28/2019 by MFunction.
 */
#define LOCAL

#include <cstdio>
#include <cstring>
#include <string>
using namespace std;

int main()
{
    int n, cnt[10];
#ifdef LOCAL
    freopen("1225.in", "r", stdin);
#endif
    while (scanf("%d", &n) == 1)
    {
        while (n--)
        {
            memset(cnt, 0, sizeof cnt);
            int num;
            scanf("%d", &num);
            string str = "";
            for (auto i = 1; i <= num; ++i) str.append(to_string(i));
            for (auto i = 0; i < str.length(); ++i) ++cnt[(str[i] - '0')];
            for (auto i = 0; i < 10; ++i)
            {
                if (i) printf(" %d", cnt[i]);
                else printf("%d", cnt[i]);
            }
            putchar('\n');
        }
    }
#ifdef LOCAL
    freopen("CON", "r", stdin);
#endif
    return 0;
}