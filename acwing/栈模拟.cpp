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

int t;

int stk[NUM], tt = 0;
bool empty() {
    return tt <= 0;
}

void push(int x) {
    stk[++tt] = x;
}

void pop() {
    --tt;
}

int top() {
    return stk[tt];
}

void solve() {
    std::string str;
    std::cin >> str;
    if (str == "push") {
        int x;
        std::cin >> x;
        push(x);
    } else if (str == "pop") {
        pop();
    } else if (str == "empty") {
        if (empty()) std::cout << "YES" << std::endl;
        else std::cout << "NO" << std::endl;
    } else if (str == "query") {
        std::cout << top() << std::endl;
    }
    return ;
}

int main(void)
{
    std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
    fileIO();
    std::cin >> t;
    while (t--) {
      solve();
    }
    return 0;
}
