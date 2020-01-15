/*
    HDU1042 Keep on Truckin'
    http://acm.hdu.edu.cn/showproblem.php?pid=1042
    Created at 01/02/2020 by MFunction.
 */
#define LOCAL

#include <cstdio>
#include <cstring>
#include <string>
using namespace std;

const auto MAXN = 10000 + 10;
const auto SPLIT = 12;

//string factorial[MAXN];
string cache;

void reserve(string& str)
{
    int l = str.length();
    for (auto i = 0; i < (l >> 1); ++i)
    {
        auto tmp = str[i];
        str[i] = str[l - 1 - i];
        str[l - 1 - i] = tmp;
    }
}

unsigned long long power(int x)
{
    unsigned long long ans = 1;
    while (x--) ans *= 10;
    return ans;
}

void custom_plus(string num, int index)
{
    int cl = cache.length(), nl = num.length(), shift = index * SPLIT;
    bool exceed = false;
    for (auto i = 0; i < nl ; ++i)
    {
        auto j = i + shift;
        int n1 = j < cl ? cache[j] - '0' : 0;
        int n2 = num[nl - 1 - i] - '0';
        //int n2 = num[nl] - '0';
        auto tmp = n1 + n2;
        if (exceed) ++tmp;
        exceed = tmp / 10;
        if (j < cl) cache[j] = tmp % 10 + '0';
        else cache.push_back(tmp % 10 + '0');
    }
    for (auto j = nl + shift; exceed; ++j)
    {
        auto tmp = j < cl ? cache[j] - '0' : 0;
        if (exceed) ++tmp;
        exceed = tmp / 10;
        if (j < cl) cache[j] = tmp % 10 + '0';
        else cache.push_back(tmp % 10 + '0');
    }
}

string multiple(string num1, int num2)
{
    int l = num1.length(), cnt = 0;
    unsigned long long tmp = 0;
    cache.clear();
    for (auto i = 0; i < l; ++i)
    {
        //long long n = num1[l - 1 - i] - '0';
        long long n = num1[i] - '0';
        tmp += n * power(i % SPLIT);
        if ((i && (i + 1) % SPLIT == 0) || i == l - 1) 
        {
            auto str = to_string(tmp * num2);
            if (l > SPLIT && str == "0")
            {
                auto j = SPLIT;
                while (j--) cache.push_back('0');
            }
            else
            {
                custom_plus(str, cnt);
            }
            ++cnt;
            tmp = 0;
        }
    }
    //reserve(cache);
    return cache;
}

string factorial(int n)
{
    string ans = "1";
    for (auto i = 2; i <= n; ++i)
    {
        ans = multiple(ans, i);
    }
    reserve(ans);
    return ans;
}

int main()
{
#ifdef LOCAL
    freopen("1042.in", "r", stdin);
    freopen("1042.out", "w", stdout);
#endif
/*    for (auto i = 1; i < MAXN; ++i)
    {
        //printf("%s\n", num.c_str());
        if (i == 0 || i == 1) factorial[i] = "1";
        else factorial[i] = multiple(factorial[i - 1], i);
        printf("%s\n", factorial[i].c_str());
    }*/
    int n;
    //while (scanf("%d", &n) == 1) printf("%s\n", factorial[n].c_str());
    while (scanf("%d", &n) == 1) printf("%s\n", factorial(n).c_str());
#ifdef LOCAL
    freopen("CON", "r", stdin);
    freopen("CON", "w", stdout);
#endif
    return 0;
}