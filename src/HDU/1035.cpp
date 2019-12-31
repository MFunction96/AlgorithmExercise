/*
    HDU1035 Robot Motion
    http://acm.hdu.edu.cn/showproblem.php?pid=1035
    Created at 12/31/2019 by MFunction.
 */
#define LOCAL

#include <cstdio>
#include <cstring>

const auto MAXN = 10 + 10;

struct point
{
    int x, y;
    point(int x = 0, int y = 0) : x(x), y(y) {}
    void operator+= (const point p)
    {
        x += p.x;
        y += p.y;
    }
};

char maze[MAXN][MAXN];
bool vis[MAXN][MAXN];
point dp[4] = { point(0, -1), point(1, 0), point(-1, 0), point(0, 1) };

int main()
{
#ifdef LOCAL
    freopen("1035.in", "r", stdin);
    freopen("1035.out", "w", stdout);
#endif
    int r, c;
    while (scanf("%d%d", &r, &c), r || c)
    {
        int s;
        scanf("%d", &s);
        for (auto i = 0; i < r; ++i) scanf("%s", maze[i]);
        memset(vis, -1, sizeof vis);
        auto cnt = 0;
        auto p = point(s - 1, 0);
        for (;;)
        {
            if (vis[p.y][p.x])
            {
                vis[p.y][p.x] = false;
                if (maze[p.y][p.x] == 'N') p += dp[0];
                else if (maze[p.y][p.x] == 'E') p += dp[1];
                else if (maze[p.y][p.x] == 'W') p += dp[2];
                else if (maze[p.y][p.x] == 'S') p += dp[3];                
                ++cnt;
                if (p.x < 0 || p.y < 0 || p.x == c || p.y == r)
                {
                    printf("%d step(s) to exit\n", cnt);
                    break;
                }
            }
            else
            {
                auto loop = 0;
                memset(vis, -1, sizeof vis);
                for (;;)
                {
                    if (vis[p.y][p.x] == false) break;
                    vis[p.y][p.x] = false;
                    if (maze[p.y][p.x] == 'N') p += dp[0];
                    else if (maze[p.y][p.x] == 'E') p += dp[1];
                    else if (maze[p.y][p.x] == 'W') p += dp[2];
                    else if (maze[p.y][p.x] == 'S') p += dp[3]; 
                    ++loop;
                }
                printf("%d step(s) before a loop of %d step(s)\n", cnt - loop, loop);
                break;
            }
        }
    }
#ifdef LOCAL
    freopen("CON", "r", stdin);
    freopen("CON", "w", stdout);
#endif
    return 0;
}