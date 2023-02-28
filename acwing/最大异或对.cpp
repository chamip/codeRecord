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

void fileIO() {   
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
}

/*
在给定的 N个整数 A1，A2……AN中选出两个进行 xor（异或）运算，得到的结果最大是多少？

输入格式
第一行输入一个整数 N。

第二行输入 N个整数 A1～AN。

输出格式
输出一个整数表示答案。

数据范围
1≤N≤105,
0≤Ai<231
输入样例：
3
1 2 3
输出样例：
3
*/
const int    N = 3100000;
const int    M = 1e5 + 10;
int n;
int arr[M], idx, son[N][2];

void insert(int x) {
    int p = 0;
    for (int i = 30; ~i; --i) {
        int s = x >> i & 1;
        if (!son[p][s]) son[p][s] = ++idx;
        p = son[p][s]; 
    }
    return ;
}

int query(int x) {
    int p = 0, res = 0;
    for (int i = 30; ~i; --i) {
        int s = x >> i & 1;
        if (son[p][!s]) {
            res += 1 << i;
            p = son[p][!s];
        } else {
            p = son[p][s];
        }
    }
    return res;
}

void solve() {
    std::cin >> n;
    for (int i = 0; i < n; ++i) {
        std::cin >> arr[i];
        insert(arr[i]);
    }
    int res = 0;
    for (int i = 0; i < n; ++i) {
        res = std::max(res, query(arr[i]));
    }
    std::cout << res << std::endl;
    return ;
}

int main(void)
{
    std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
    fileIO();
    // for (int i = 30; ~i; --i) {
    //     std::cout << ~i << std::endl;
    // }
    solve();
    return 0;
}
