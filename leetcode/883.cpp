#include <cstdio>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cctype>
#include <cstring>
#include <cmath>
#include <iostream>
#include <sstream>
#include <string>
#include <list>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <algorithm>
#include <numeric>
#include <functional>
#define mem(ar,num) memset(ar,num,sizeof(ar))
#define me(ar) memset(ar,0,sizeof(ar))
#define lowbit(x) (x&(-x))
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
const int    prime = 999983;
const int    INF = 0x7FFFFFFF;
const LL     INFF =0x7FFFFFFFFFFFFFFF;
const double pi = acos(-1.0);
const double inf = 1e18;
const double eps = 1e-6;
const LL     mod = 1e9 + 7;

int projectionArea(vector<vector<int>>& grid);

int main(void)
{
 //    #ifdef ONLINE_JUDGE
	// #else
	// 	freopen("in.txt", "r", stdin);
	// 	freopen("out.txt", "w", stdout);
	// #endif
    //std::ios::sync_with_stdio(false);
    //printf("Strive for excellence");
    //vector<vector<int>> vec{{1, 2}, {3, 4}};
    // vector<vector<int>> vec{{2}};
    vector<vector<int>> vec{{1, 0}, {0, 2}};
    int ans = projectionArea(vec);
    cout << ans << endl;
    // cin.get();
    cin.get();
    return 0;
}

int projectionArea(vector<vector<int>>& grid) {
    int res = 0;
    //三视图
    //计算底面：n*n且每个位置的高度不为0
    int m = grid.size();
    int n = grid[0].size();
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            if (grid[i][j] != 0) {
                ++res;
            }
        }
    }
    //计算正视图：每行
    for (int i = 0; i < m; ++i) {
        int temp = 0;
        for (int j = 0; j < n; ++j) {
            temp = max(temp, grid[i][j]);
        }
        res += temp;
    }
    //计算侧视图：每列
    for (int j = 0; j < n; ++j) {
        int temp = 0;
        for (int i = 0; i < m; ++i) {
            temp = max(temp, grid[i][j]);
        }
        res += temp;
    }
    return res;
}