/*
 * @Author: chamip
 * @Date: 2022-04-21 11:35:17
 * @LastEditTime: 2022-04-21 11:39:28
 * @LastEditors: chamip
 * @FilePath: /vscCpp/projecteuler/2.cpp
 */
#include <cstdio>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cctype>
#include <cstring>
#include <cmath>
#include <iostream>
#include <sstream>
#include <string>
#include <list>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <algorithm>
#include <functional>
#define mem(ar,num) memset(ar,num,sizeof(ar))
#define me(ar) memset(ar,0,sizeof(ar))
#define lowbit(x) (x&(-x))
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
const int    prime = 999983;
const int    INF = 0x7FFFFFFF;
const LL     INFF =0x7FFFFFFFFFFFFFFF;
const double pi = acos(-1.0);
const double inf = 1e18;
const double eps = 1e-6;
const LL     mod = 1e9 + 7;
const int MaxN = 1000000;
const int Limit = 4000000;
int main(void)
{
    int dp[MaxN] = {0};
    dp[1] = 1;
    dp[2] = 2;
    int sum = dp[2];
    for (int i = 3; i < MaxN; ++i) {
        dp[i] = dp[i - 1] + dp[i - 2];
        if (dp[i] > Limit) {
            break;
        } else {
            if (dp[i] % 2 == 0) {
                sum += dp[i];
            }
        }
    }
    cout << sum << endl;
    //std::ios::sync_with_stdio(false);
    //printf("Strive for excellence");
    return 0;
}