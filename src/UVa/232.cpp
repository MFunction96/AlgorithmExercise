/*
    UVa232 Crossword Answers
    https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=4&page=show_problem&problem=168
    Created at 12/26/2019 by MFunction.
 */
#define LOCAL

#include <cstdio>
#include <cstring>

const auto MAXN = 10 + 10;

char puzzle[MAXN][MAXN];
int number[MAXN][MAXN];

int main()
{
#ifdef LOCAL
    freopen("232.in", "r", stdin);
#endif
    int r, c, cnt = 0;
    while (scanf("%d", &r), r)
    {
        scanf("%d", &c);
        if (cnt) putchar('\n');
        printf("puzzle #%d:\n", ++cnt);
        memset(number, 0, sizeof number);
        auto mark = 1;
        for (auto i = 0; i < r; ++i)
        {
            scanf("%s", puzzle[i]);
            for (auto j = 0; j < c; ++j)
            {
                if (puzzle[i][j] == '*') continue;
                auto tmp = number[i][j];
                if (i == 0) number[i][j] += mark << 8;
                else if (puzzle[i - 1][j] == '*') number[i][j] += mark << 8;
                if (j == 0) number[i][j] += mark;
                else if (puzzle[i][j - 1] == '*') number[i][j] += mark;
                if (tmp ^ number[i][j]) ++mark;
            }
        }
        printf("Across\n");
        for (auto i = 0; i < r; ++i)
        {
            for (auto j = 0; j < c; ++j)
            {
                if (puzzle[i][j] == '*') continue;
                auto tmp = number[i][j] & 255;
                if (tmp) 
                {
                    if (tmp == 1) printf("  %d.", tmp);
                    else printf("\n  %d.", tmp);
                }
                putchar(puzzle[i][j]);
            }
        }
        putchar('\n');
        printf("Down\n");
        for (auto i = 0; i < r; ++i)
        {
            for (auto j = 0; j < c; ++j)
            {
                if (puzzle[i][j] == '*') continue;
                auto tmp = number[i][j] >> 8;
                if (tmp) 
                {
                    if (tmp == 1) printf("  %d.", tmp);
                    else printf("\n  %d.", tmp);
                    for (auto k = i; k < r; ++k)
                    {
                        if (puzzle[k][j] == '*') break;
                        putchar(puzzle[k][j]);
                    }
                }
            }
        }
        putchar('\n');
    }
#ifdef LOCAL
    freopen("CON", "r", stdin);
#endif
    return 0;
}