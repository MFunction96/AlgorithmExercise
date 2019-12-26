/*
    UVa227 - Puzzle
    https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=4&page=show_problem&problem=163
    Created at 12/25/2019 by MFunction.
 */
#define LOCAL

#include <cstdio>
#include <iostream>
#include <string>
using namespace std;

string puzzle[5];

int main()
{
#ifdef LOCAL
    freopen("227.in", "r", stdin);
#endif
    int cnt = 0;
    for (;;)
    {
        getline(cin, puzzle[0], '\n');
        if (puzzle[0] == "Z") break;
        if (cnt) cout << endl;
        printf("Puzzle #%d:\n", ++cnt);
        auto pos = -1;
        for (auto i = 0; i < 5; ++i)
        {
            if (puzzle[0].length() != 5) puzzle[0].append(" ");
            if (puzzle[0][i] == ' ') 
            {
                pos = i;
                break;
            }
        }
        for (auto i = 1; i < 5; ++i)
        {
            getline(cin, puzzle[i], '\n');
            if (pos < 0)
            {
                if (puzzle[i].length() != 5) puzzle[i].append(" ");
                for (auto j = 0; j < 5; ++j)
                {
                    if (puzzle[i][j] == ' ') 
                    {
                        pos = (i << 4) + j;
                        break;
                    }
                }
            }
        }
        char c;
        auto flag = false;
        while (c = getchar(), c != '0')
        {
            if (flag) continue;
            auto x = pos & 7, y = pos >> 4;
            if (c == 'A')
            {
                if (y < 1)
                {
                    flag = true;
                    
                    continue;
                }
                puzzle[y][x] = puzzle[y - 1][x];
                puzzle[y - 1][x] = ' ';
                pos -= (1 << 4);
            }
            else if (c == 'B')
            {
                if (y > 3)
                {
                    flag = true;
                    continue;
                }
                puzzle[y][x] = puzzle[y + 1][x];
                puzzle[y + 1][x] = ' ';
                pos += (1 << 4);
            }
            else if (c == 'L')
            {
                if (x < 1)
                {
                    flag = true;
                    continue;
                }
                puzzle[y][x] = puzzle[y][x - 1];
                puzzle[y][x - 1] = ' ';
                --pos;
            }
            else if (c == 'R')
            {
                if (x > 3)
                {
                    flag = true;
                    continue;
                }
                puzzle[y][x] = puzzle[y][x + 1];
                puzzle[y][x + 1] = ' ';
                ++pos;
            }
            else continue;
        }
        getchar();
        if (flag) printf("This puzzle has no final configuration.\n");
        else
        {
            for (auto i = 0;i < 5 ; ++i)
            {
                for (auto j = 0; j < 5; ++j)
                {
                    if (j) printf(" %c", puzzle[i][j]);
                    else printf("%c", puzzle[i][j]);
                }
                printf("\n");
            }
        }
        
    }
#ifdef LOCAL
    freopen("CON", "r", stdin);
#endif
    return 0;
}