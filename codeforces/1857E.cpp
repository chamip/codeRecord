#include <iostream>
#include <algorithm>

typedef long long ll;
constexpr int N = 2e5+5;
std::pair<int, int> x[N];
ll a[N];

void solve() {
	int n;
	std::cin >> n;
	ll s1 = 0, s2 = 0;
	for (int i = 1; i <= n; ++i) {
		std::cin >> x[i].first;
		x[i].second = i;
		s2 += x[i].first;
	}
	sort(x+1, x+1+n);
	for (int i = 1; i <= n; ++i) {
		s2 -= x[i].first;
		s1 += x[i].first;
		a[x[i].second] = n + 1ll * x[i].first * (2 * i - n) - s1 + s2;
	}
	for (int i = 1; i <= n; ++i) {
		std::cout << a[i] << " \n"[i==n];
	}
	return ;
}

int main(int argc, char const *argv[])
{
	int t;
	std::cin >> t;
	while (t--) {
		solve();
	}
	return 0;
}