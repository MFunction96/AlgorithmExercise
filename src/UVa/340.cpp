/*
    UVa340 - Master-Mind Hints
    https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=5&page=show_problem&problem=276
    Created at 08/10/2019 by MFunction.
 */

#include <cstdio>
#include <cstring>

const int MAXN = 1000 + 10;
int secret[MAXN], number_secret[10], number_guess[10];

int main()
{
    //freopen("340.in", "r", stdin);  
    auto n = 0, cnt = 0;
    while (scanf("%d", &n), n)
    {
        printf("Game %d:\n", ++cnt);
        memset(number_secret, 0, sizeof number_secret);
        for (auto i = 0;i < n;++i) 
        {
            scanf("%d", &secret[i]);
            // 答案序列中数字出现次数。
            ++number_secret[secret[i]];
        }
        for (;;)
        {
            auto number = 0, strong = 0, count = 0;
            memset(number_guess, 0, sizeof number_guess);
            for (auto i = 0;i < n;++i)
            {
                scanf("%d", &number);
                // 可直接确定强匹配数量，减少一边循环开销。
                if (secret[i] == number) ++strong;
                // 猜测序列中数字出现次数，用完即销。
                ++number_guess[number];
            }
            // 有效输入为1-9，且输入全为0为终止标记，即判定第一个数为0则停止本轮猜测。
            if (!number) break;
            auto match = 0;
            // 核心计算时间复杂度为O(1)，空间复杂度O(1)。每个数字的匹配数量等于答案序列与猜测序列的最小值。
            for (auto i = 1; i < 10;++i) match += number_secret[i] < number_guess[i] ? number_secret[i] : number_guess[i];
            // 弱匹配数=匹配数-强匹配数
            printf("    (%d,%d)\n", strong, match - strong);
        }
    }
    //freopen("CON", "r", stdin);
    return 0;
}