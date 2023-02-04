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
    int x = 0, y = 0;
    bool flag = false;
    for (int i = 0; i < n; ++i) {
        if (s[i] == 'L') {
            x -= 1;
        } else if (s[i] == 'R') {
            x += 1;
        } else if (s[i] == 'U') {
            y += 1;
        } else {
            y -= 1;
        }
        if (x == 1 && y == 1) {
            flag = true;
            break;
        }
    }
    if (flag) std::cout << "YES" << std::endl;
    else std::cout << "NO" << std::endl;
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
