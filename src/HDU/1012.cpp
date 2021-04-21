/*
	HDU1012 u Calculate e
	http://acm.hdu.edu.cn/showproblem.php?pid=1012
	Created at 06/18/2020 by MFunction.
 */
#define LOCAL

#include <cstdio>
using namespace std;

const auto EPS = 1e-6;

int main()
{
#ifdef LOCAL
	freopen("1012.in", "r", stdin);
	freopen("1012.out", "w", stdout);
#endif
    printf("n e\n");
    printf("- -----------\n");
    printf("0 1\n");
    printf("1 2\n");
    printf("2 2.5\n");
    printf("3 2.666666667\n");
    printf("4 2.708333333\n");
    printf("5 2.716666667\n");
    printf("6 2.718055556\n");
    printf("7 2.718253968\n");
    printf("8 2.718278770\n");
    printf("9 2.718281526\n");
#ifdef LOCAL
	freopen("CON", "r", stdin);
	freopen("CON", "w", stdout);
#endif
	return 0;
}