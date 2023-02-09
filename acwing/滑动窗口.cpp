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
const int    NUM = 1e6 + 10;

void fileIO() {   
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
}

int q[NUM], a[NUM];
int n, k, hh, tt;

void solve() {
    std::cin >> n >> k;
    for (int i = 0; i < n; ++i) {
        std::cin >> a[i];
    }
    hh = 0, tt = -1;
    for (int i = 0; i < n; ++i) {
        //检测窗口大小
        if (hh <= tt && q[hh] < i - k + 1) ++hh;
        //单调递增
        while (hh <= tt && a[q[tt]] >= a[i]) --tt;
        q[++tt] = i;

        if (i + 1 >= k) std::cout << a[q[hh]] << " ";
    }
    std::cout << std::endl;
    // std::cout << "----------qaq" << std::endl;
    hh = 0, tt = -1;
    for (int i = 0; i < n; ++i) {
        //检测窗口大小
        if (hh <= tt && q[hh] < i - k + 1) ++hh;
        //单调递减
        while (hh <= tt && a[q[tt]] <= a[i]) --tt;
        q[++tt] = i;

        if (i + 1 >= k) std::cout << a[q[hh]] << " ";
    } 
    return ;
}

int main(void)
{
    std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
    fileIO();
    solve();
    return 0;
}
