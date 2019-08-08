/*
    UVa272 - TEX Quotes
    https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=4&page=show_problem&problem=208
    Created at 08/08/2019.
 */

#include <cstdio>

int main()
{
    //freopen("272.in", "r", stdin);
    auto q1 = false, q2 = false;
    int c;
    while (c = getchar(), c != EOF)
    {
        if (c == '\"')
        {
            if (q1) 
            {
                putchar('\'');
                putchar('\'');
            }
            else 
            {
                putchar('`');
                putchar('`');
            }
            q1 = !q1;
        }
        else if (c == '\'')
        {
            if (q2) putchar('\'');
            else putchar('`');
            q2 = !q2;
        }
        else putchar(c);
    }
    //freopen("CON", "r", stdin);
    return 0;
}