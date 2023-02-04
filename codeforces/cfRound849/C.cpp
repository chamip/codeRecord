#pragma GCC optimize(3)
#include <cstdio>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cctype>
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
typedef long long LL;
typedef unsigned long long ULL;
const int    prime = 999983;
const int    INF = 0x7FFFFFFF;
const LL     INFF =0x7FFFFFFFFFFFFFFF;
const double pi = acos(-1.0);
const double inf = 1e18;
const double eps = 1e-6;
const LL     mod = 1e9 + 7;

int t;

void solve() {
    int n;
    std::cin >> n;
    std::string s;
    std::cin >> s;
    int res = n;
    int left = 0, right = n - 1;
    while (left < right) {
        if (s[left] != s[right]) {
            ++left;
            --right;
            res -= 2;
        } else {
            break;
        }
    }
    std::cout << res << std::endl;
    return ;
}

int main(void)
{
    //#ifdef ONLINE_JUDGE
	//#else
	//	freopen("in.txt", "r", stdin);
	//	freopen("out.txt", "w", stdout);
	//#endif
	//cin/cout解绑后无法使用scanf/printf
    std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
    std::cin >> t;
    while (t--) {
      solve();
    }
    return 0;
}
