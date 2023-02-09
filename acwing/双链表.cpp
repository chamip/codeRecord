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
const int    N = 1e5 + 10;

void fileIO() {   
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
}

int m;
int e[N], l[N], r[N], idx;

void init() {
    r[0] = 1;
    l[1] = 0;
    idx = 2;
}

//在a节点后插入一个值为x的节点
void insert(int a, int x) {
    e[idx] = x;
    r[idx] = r[a];
    l[idx] = a;
    l[r[a]] = idx;
    r[a] = idx;
    ++idx;
}

//删除节点a
void remove(int a) {
    r[l[a]] = r[a];
    l[r[a]] = l[a];
}

int main(void)
{
    std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
    init();
    fileIO();
    std::cin >> m;
    for (int i = 0; i < m; ++i) {
        std::string str;
        std::cin >> str;
        int k, x;
        if (str == "L") {
            std::cin >> x;
            insert(0, x);
        } else if (str == "R") {
            std::cin >> x;
            insert(l[1], x);
        } else if (str == "D") {
            std::cin >> k;
            remove(k + 1);
        } else if (str == "IL") {
            std::cin >> k >> x;
            insert(l[k + 1], x);
        } else if (str == "IR") {
            std::cin >> k >> x;
            insert(k + 1, x);
        }
    }
    for (int i = r[0]; i != 1; i = r[i]) {
        std::cout << e[i] << " ";
    }
    std::cout << std::endl;
    return 0;
}
