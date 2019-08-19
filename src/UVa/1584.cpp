/*
    UVa1584 - Circular Sequence
    https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=448&page=show_problem&problem=4459
    Created at 08/15/2019 by MFunction.
 */

#include <cstdio>
#include <cstring>

const auto MAXN = 100 + 10;
auto seq = new char[MAXN];

bool less(const char *seq, int n1, int n2)
{
    const auto len = strlen(seq);
    for (auto i = 0;i < len;++i)
    {
        if (seq[(n1 + i) % len] < seq[(n2 + i) % len]) return true;
        if (seq[(n1 + i) % len] > seq[(n2 + i) % len]) return false;
    }
    return false;
}

int main()
{
    //freopen("1584.in", "r", stdin);
    int n;
    while (scanf("%d", &n) == 1)
    {
        while (n--)
        {
            scanf("%s", seq);
            const auto len = strlen(seq);
            auto ans = 0;
            for (auto i = 1; i < len; ++i)
            {
                if (less(seq, i, ans)) ans = i;
            }
            for (auto i = 0;i < len;++i) putchar(seq[(ans + i) % len]);
            putchar('\n');
        }
    }
    //freopen("CON", "r", stdin);
    return 0;
}