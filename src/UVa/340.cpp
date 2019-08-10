/*
    UVa340 - Master-Mind Hints
    https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=5&page=show_problem&problem=276
    Created at 08/10/2019 by MFunction.
 */

#include <cstdio>
#include <cstring>

const int MAXN = 1000 + 10;
int secret[MAXN], guess[MAXN], vis[MAXN];

int main()
{
    //freopen("340.in", "r", stdin);  
    auto n = 0, cnt = 0;
    while (scanf("%d", &n), n)
    {
        printf("Game %d:\n", ++cnt);
        for (auto i = 0;i < n;i++) scanf("%d", &secret[i]);
        for (auto flag = true;;flag = true)
        {
            for (auto i = 0;i < n;i++)
            {
                scanf("%d", &guess[i]);
                if (flag && guess[i]) flag = false; 
            }
            if (flag) break;
            memset(vis, 0, sizeof vis);
            auto strong = 0, weak = 0;
            for (auto i = 0;i < n;i++)
            {
                if (secret[i] == guess[i])
                {
                    ++strong;
                    vis[i] = 3;
                }
            }
            for (auto i = 0;i < n;i++)
            {
                if (vis[i] & 1) continue;
                for (auto j = 0;j < n;j++)
                {
                    if (!(vis[j] & 2) && secret[j] == guess[i])
                    {
                        ++weak;
                        vis[i] |= 1;
                        vis[j] |= 2;
                        break;
                    }
                }
            }
            printf("    (%d,%d)\n", strong, weak);
        }
    }
    //freopen("CON", "r", stdin);
    return 0;
}