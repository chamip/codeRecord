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
int f[4001][2];
int ans;
vector<int> a[4001];
char str[4001];

void dfs(int x);

int main(void)
{
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		for (int i = 1; i <= 4000; ++i) {
			a[i].clear();
		}
		for (int i = 2; i <= n; ++i) {
			int x;
			cin >> x;
			a[x].push_back(i);
		}
		for (int i = 1; i <= n; ++i) {
			cin >> str[i];
		}
		ans = 0;
		memset(f, 0, sizeof(f));
		dfs(1);
		cout << ans << endl;
	}
	return 0;
}

void dfs(int x) {
	if (str[x] == 'B') {
		++f[x][0];
	} else {
		++f[x][1];
	}
	for (auto y : a[x]) {
		dfs(y);
		f[x][0] += f[y][0];
		f[x][1] += f[y][1];
	}
	if (f[x][0] == f[x][1]) {
		++ans;
	}
	return ;
}
