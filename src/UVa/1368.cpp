/*
    UVa1368 DNA Consensus String
    https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=446&page=show_problem&problem=4114
    Created at 12/29/2019 by MFunction.
 */
#define LOCAL

#include <cstdio>
#include <string>
using namespace std;

char seq[100][1010];

int main()
{
#ifdef LOCAL
    freopen("1368.in", "r", stdin);
    freopen("1368.out", "w", stdout);
#endif
    int t;
    while (scanf("%d", &t) == 1)
    {
        while (t--)
        {
            int n, m;
            scanf("%d%d", &m, &n);
            for (auto i = 0; i < m; ++i) scanf("%s", seq[i]);
            string ans = "";
            auto dif = 0;
            for (auto j = 0; j < n; ++j)
            {
                int cnt[4] = {0, 0, 0, 0};
                for (auto i = 0; i < m; ++i)
                {
                    if (seq[i][j] == 'A') ++cnt[0];
                    else if (seq[i][j] == 'C') ++cnt[1];
                    else if (seq[i][j] == 'G') ++cnt[2];
                    else ++cnt[3];
                }
                if (cnt[0] >= cnt[1] && cnt[0] >= cnt[2] && cnt[0] >= cnt[3])
                {
                    ans.append("A");
                    dif += m - cnt[0];
                }
                else if (cnt[1] >= cnt[0] && cnt[1] >= cnt[2] && cnt[1] >= cnt[3])
                {
                    ans.append("C");
                    dif += m - cnt[1];
                }
                else if (cnt[2] >= cnt[0] && cnt[2] >= cnt[1] && cnt[2] >= cnt[3])
                {
                    ans.append("G");
                    dif += m - cnt[2];
                }
                else
                {
                    ans.append("T");
                    dif += m - cnt[3];
                }
            }
            printf("%s\n%d\n", ans.c_str(), dif);
        }
    }
#ifdef LOCAL
    freopen("CON", "r", stdin);
    freopen("CON", "w", stdout);
#endif
    return 0;
}