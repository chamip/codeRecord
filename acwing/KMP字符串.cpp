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
const int N = 1e5 + 10;
const int M = 1e6 + 10;


int n, m;
int ne[N];
char p[N], s[M];

//求模式串的next数组
void getNext() {
    for (int i = 2, j = 0; i <= n; ++i) {
        while (j && p[i] != p[j + 1]) j = ne[j];
        if (p[i] == p[j + 1]) ++j;
        ne[i] = j;
    }
    return ;
}

void fileIO() {   
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
}

int main(void)
{
    std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
    fileIO();
    std::cin >> n;
    for (int i = 1; i <= n; ++i) std::cin >> p[i];
    std::cin >> m;
    for (int i = 1; i <= m; ++i) std::cin >> s[i];

    getNext();
    //kmp
    for (int i = 1, j = 0; i <= m; ++i) {
        while (j && s[i] != p[j + 1]) j = ne[j];
        if (s[i] == p[j + 1]) ++j;
        if (j == n) {
            std::cout << i - n << " ";
            j = ne[j];
        }
    }

    return 0;
}
