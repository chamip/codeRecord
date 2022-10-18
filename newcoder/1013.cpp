/*
 * @Author: chamip
 * @Date: 2022-04-28 15:41:02
 * @LastEditTime: 2022-04-28 16:28:04
 * @LastEditors: chamip
 * @FilePath: /vscCpp/newcoder/1013.cpp
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
#include <numeric>
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

static int res = 0;
const int model = 20010905;	
int dp[8];

int main(void)
{
 // 	#ifdef ONLINE_JUDGE
	// #else
	// 	freopen("in.txt", "r", stdin);
	// 	freopen("out.txt", "w", stdout);
	// #endif
    //std::ios::sync_with_stdio(false);
    //printf("Strive for excellence");
    string str;
    cin >> str;
	int len = str.size();
	for (int i = 0; i < len; ++i) {
		char ch = tolower(str[i]);
		if (ch == 'i') {
			++dp[0];
		}
		if (ch == 'l') {
			dp[1] = (dp[1] + dp[0]) % model;
		}
		if (ch == 'o') {
			dp[2] = (dp[2] + dp[1]) % model;
		}
		if (ch == 'v') {
			dp[3] = (dp[3] + dp[2]) % model;
		}
		if (ch == 'e') {
			dp[4] = (dp[4] + dp[3]) % model;
		}
		if (ch == 'y') {
			dp[5] = (dp[5] + dp[4]) % model;
		}
		if(ch == 'o') {
			dp[6] = (dp[6] + dp[5]) % model;
		}
		if (ch == 'u') {
			dp[7] = (dp[7] + dp[6]) % model;
		}
	}
	res = dp[7];
    cout << res << endl;
    // cin.get();
    // cin.get();
    return 0;
}