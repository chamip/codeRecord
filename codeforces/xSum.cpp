#include <climits>
#include <cstdio>
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

int main(void)
{
    int t;
	cin >> t;
	while (t--) {
		int n,m;
		cin >> n >> m;
		vector<vector<int>> v(n, vector<int>(m));
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < m; ++j) {
				cin >> v[i][j];
			}
		}
		int res = INT_MIN;
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < m; ++j) {
				int temp = v[i][j];
				int x = i - 1;
				int y = j - 1;
				while (x >= 0 && y >= 0) {
					temp += v[x][y];
					--x;
					--y;
				}
				x = i - 1;
				y = j + 1;
				while (x >= 0 && y < m) {
					temp += v[x][y];
					--x;
					++y;
				}
				x = i + 1;
				y = j - 1;
				while (x < n && y >= 0) {
					temp += v[x][y];
					++x;
					--y;
				}
				x = i + 1;
				y = j + 1;
				while (x < n && y < m) {
					temp += v[x][y];
					++x;
					++y;
				}
				res = max(res, temp);
			}
		}
		cout << res << endl;
	}
	return 0;
}
