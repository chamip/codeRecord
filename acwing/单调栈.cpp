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
const int    NUM = 1e5 + 10;

void fileIO() {   
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
}

int stk[NUM], tt = 0;

void push(int x) {
    stk[++tt] = x;
}

void pop() {
    --tt;
}

bool empty() {
    return tt <= 0;
}

int top() {
    return stk[tt];
}

void solve() {
    int n;
    std::cin >> n;
    int x;
    for (int i = 0; i < n; ++i) {
        std::cin >> x;
        while (!empty() && top() >= x) pop();
        if (empty()) std::cout << -1 << " ";
        else std::cout << top() << " ";
        push(x);
    }
    return ;
}

int main(void)
{
    std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
    solve();
    return 0;
}
