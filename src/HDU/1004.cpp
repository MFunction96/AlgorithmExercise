/*
    HDU1004 Let the Balloon Rise
    http://acm.hdu.edu.cn/showproblem.php?pid=1004
    Created at 12/30/2019 by MFunction.
 */
#define LOCAL

#include <cstdio>
#include <iostream>
#include <string>
#include <map>
using namespace std;

map<string, int> m;

int main()
{
#ifdef LOCAL
    freopen("1004.in", "r", stdin);
    freopen("1004.out", "w", stdout);
#endif
    int t;
    while (scanf("%d", &t), t)
    {
        m.clear();
        while (t--)
        {
            string str;
            cin >> str;
            ++m[str];
        }
        string ans;
        int max = -1;
        for (auto it = m.begin(); it != m.end(); ++it)
        {
            if (it->second < max) continue;
            max = it->second;
            ans = it->first;
        }
        printf("%s\n", ans.c_str());
    }
#ifdef LOCAL
    freopen("CON", "r", stdin);
    freopen("CON", "w", stdout);
#endif
    return 0;
}