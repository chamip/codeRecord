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
		int n, m;
		cin >> n >> m;
		vector<string> v(n);
		for (int i = 0; i < n; ++i) {
			cin >> v[i];
		}
		int res = INT_MAX;
		for (int j = 0; j < n; ++j) {
			for (int k = j + 1; k < n; ++k) {
				int cnt = 0;
				for (int p = 0; p < m; ++p) {
					cnt += abs(v[k][p] - v[j][p]);
				}
				res = min(res, cnt);
			}
		}
		cout << res << endl;
	}
	return 0;
}
