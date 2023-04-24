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

void fileIO() {   
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
}

void solve() {
    int r, c;
    std::cin >> r >> c;
    std::vector<std::vector<char>> v(r, std::vector<char>(c));
    for (int i = 0; i < r; ++i) {
        for (int j = 0; j < c; ++j) {
            std::cin >> v[i][j];
        }
    }
    std::vector<std::vector<char>> ans(v);
    // for (int i = 0; i < r; ++i) {
    //     for (int j = 0; j < c; ++j) {
    //         std::cout << ans[i][j];
    //     } 
    //     std::cout << std::endl;
    // }
    std::vector<std::vector<bool>> visit(r, std::vector<bool>(c, false));
    for (int i = 0; i < r; ++i) {
        for (int j = 0; j < c; ++j) {
            if (isdigit(v[i][j])) {
                int tem = v[i][j] - '0';
                for (int k1 = std::max(0, i - tem); k1 < std::min(r, i + tem + 1);++k1) {
                    for (int k2 = std::max(0, j - tem); k2 < std::min(c, j + tem + 1); ++k2) {
                        if (abs(i - k1) + abs(j - k2) <= tem) {
                            ans[k1][k2] = '.';
                            visit[k1][k2] = true;
                        }
                    }
                }
            } else if (!visit[i][j] && v[i][j] == '#') ans[i][j] = '#';
        }
    }
    for (int i = 0; i < r; ++i) {
        for (int j = 0; j < c; ++j) {
            // std::cout << ans[i][j] << " \n"[j + 1 == c];
            std::cout << ans[i][j];
        }
        std::cout << std::endl;
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
