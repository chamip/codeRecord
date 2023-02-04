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

int digitSum(int num) {
    int res = 0;
    while (num > 0) {
        res += num % 10;
        num /= 10;
    }
    return res;
}

void solve() {
    int n, q;
    std::cin >> n >> q;
    std::vector<int> v(n);
    std::set<int> s;
    for (int i = 0; i < n; ++i) {
        std::cin >> v[i];
        if (v[i] > 9) s.insert(i);
    }
    while (q--) {
        int type;
        std::cin >> type;
        if (type == 1) {
            int l, r;
            std::cin >> l >> r;
            --l, --r;
            int lst = l;
            while (!s.empty()) {
                auto it = s.lower_bound(lst);
                if (it == s.end() || *it > r) break;
                v[*it] = digitSum(v[*it]);
                int cur = *it;
                s.erase(cur);
                if (v[cur] > 9) s.insert(cur);
                lst = cur + 1;
            }
        } else if (type == 2) {
            int x;
            std::cin >> x;
            std::cout << v[x - 1] << std::endl;
        }
    }
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
