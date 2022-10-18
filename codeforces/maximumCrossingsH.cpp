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

int a[200001];
int f[200001];
int n;
int calc(int x);
void insert(int x);

int main(void)
{
	int t;
	cin >> t;
	while (t--) {
		cin >> n;
		for (int i = 1; i <= n; ++i) {
			cin >> a[i];
		}
		long long ans = 0;
		memset(f, 0, sizeof(f));
		for (int i = n; i > 0; --i) {
			ans += calc(a[i]);
			insert(a[i]);
		}
		cout << ans << endl;
	}
	return 0;
}

inline void insert(int x) {
	for (; x <= n; x += x & (-x)) {
		++f[x];
	}
	return ;
}

int calc(int x) {
	int res = 0;
	for (; x; x-= x & (-x)) {
		res += f[x];
	}
	return res;
}
