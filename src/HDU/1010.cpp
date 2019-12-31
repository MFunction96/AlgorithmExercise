/*
    HDU1010 Tempter of the Bone
    http://acm.hdu.edu.cn/showproblem.php?pid=1010
    Created at 12/30/2019 by MFunction.
 */
#define LOCAL

#include <cstdio>
#include <cmath>
#include <cstring>

const auto MAXN = 10;

struct point
{
    int x, y;
    point(int x = 0, int y = 0): x(x), y(y) {}
    point operator+ (const point p) const
    {
        return point(x + p.x, y + p.y);
    }
    point operator== (const point p) const
    {
        return p.x == x && p.y == y;
    }
};

char maze[MAXN][MAXN];
bool vis[MAXN][MAXN];
int n, m, t;
point dp[4] = { point(1, 0), point(0, 1), point(-1, 0), point(0, -1) };

bool isValid(point p)
{
    return p.x < m && p.y < n && p.x >= 0 && p.y >= 0 && vis[p.y][p.x] && maze[p.y][p.x] != 'X';
}

bool dfs(point p, int time)
{
    if (maze[p.y][p.x] == 'D' && time == t) return true;
    if (time > t) return false;
    vis[p.y][p.x] = false;
    for (auto i = 0; i < 4; ++i)
    {
        auto pp = p + dp[i];
        if (!isValid(pp)) continue;
        if (dfs(pp, time + 1)) return true;
    }
    vis[p.y][p.x] = true;
    return false;
}

int main()
{
#ifdef LOCAL
    freopen("1010.in", "r", stdin);
    freopen("1010.out", "w", stdout);
#endif
    while (scanf("%d%d%d", &n, &m, &t), n || m || t)
    {
        point s, d;
        for (auto i = 0; i < n; ++i)
        {
            scanf("%s", maze[i]);
            for (auto j = 0; j < m; ++j)
            {
                if (maze[i][j] == 'S') s = point(j, i);
                if (maze[i][j] == 'D') d = point(j, i);
            }
        }
        auto dis = abs(s.x - d.x) + abs(s.y - d.y);
        if (t < dis || t > m * n || abs(dis - t) % 2)
        {
            printf("NO\n");
            continue;
        }
        memset(vis, -1, sizeof vis);
        auto ans = dfs(s, 0);
        if (ans) printf("YES\n");
        else printf("NO\n");
    }
#ifdef LOCAL
    freopen("CON", "r", stdin);
    freopen("CON", "w", stdout);
#endif
    return 0;
}