#include <iostream>
#include <string>
#include <map>
#include <vector>
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
    std::string str;
    std::cin >> str;
    std::map<std::vector<int>, LL> umsll;
    umsll.clear();
    std::vector<int> v(10, 0);
    ++umsll[v];
    for (auto ch : str) {
        ++v[ch - '0'];
        v[ch - '0'] %= 2;
        ++umsll[v];
    }
    LL res = 0;
    for (auto [_, y] : umsll) {
        res += y * (y - 1) / 2;
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
