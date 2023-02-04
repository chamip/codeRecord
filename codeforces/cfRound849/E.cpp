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
#include <unordered_set>
#include <map>
#include <unordered_map>
#include <queue>
#include <stack>
#include <algorithm>
#include <numeric>
#include <functional>
#define mem(ar,num) memset(ar,num,sizeof(ar))
#define me(ar)      memset(ar,0,sizeof(ar))
#define all(v)      v.begin(), v.end()
#define rall(v)     v.rbegin(), v.rend()
#define sz(a)       (int)a.size()

//#define lowbit(x) (x&(-x))
typedef long long LL;
// typedef unsigned long long ULL;
// const int    prime = 999983;
// const int    INF = 0x7FFFFFFF;
// const LL     INFF =0x7FFFFFFFFFFFFFFF;
// const double pi = acos(-1.0);
// const double inf = 1e18;
// const double eps = 1e-6;
const LL     mod = 1e9 + 7;
const int    NUM = 2e5 + 10;

int t;

void solve() {
    int n;
    std::cin >> n;
    std::vector<int> v(n);
    LL res = 0;
    int neg = 0;
    for (int i = 0; i < n; ++i) {
        std::cin >> v[i];
        if (v[i] < 0) {
            ++neg;
            v[i] = -v[i];
        }
        res += v[i];
    }
    if (neg % 2 == 1) {
        int small = *min_element(all(v));
        res -= small * 2;
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
