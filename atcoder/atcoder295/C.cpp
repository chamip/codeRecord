#include <iostream>
#include<unordered_map>
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

void fileIO() {   
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
}

void solve() {
    int n;
    std::cin >> n;
    std::unordered_map<int, int> umii;
    umii.clear();
    int a;
    for (int i = 0; i < n; ++i) {
        std::cin >> a;
        ++umii[a]; 
    } 
    int res = 0;
    for (auto [_, y] : umii) {
        res += y / 2;
    }
    std::cout << res << std::endl; 
    return ;
}

int main(void)
{
    std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
    solve();
    return 0;
}
