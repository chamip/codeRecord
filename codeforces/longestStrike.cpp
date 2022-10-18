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
		int n, k;
		cin >> n >> k;
		map<int, int> mp;
		for (int i = 0; i < n; ++i) {
			int x;
			cin >> x;
			++mp[x];
		}
		int l = -1, ans = 0, w = 0, r = -1;
		for (auto & i : mp) {
			int x = i.first, y = i.second;
			if (y < k) {
				l = -1;
				w = 0;
			} else {
				if (x != l + 1) {
					w = 0;
				}
				++w;
				if (ans < w) {
					ans = w;
					r = x;
				}
				l = x;
			}
		}
		if (r == -1) {
			cout << -1 << endl;
		} else {
			cout << r - ans + 1 << " " << r << endl;
		}
	}
	return 0;
}
