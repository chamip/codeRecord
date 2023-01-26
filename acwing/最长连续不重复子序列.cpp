#include <iostream>

const int N = 1e5 + 10;
int a[N], s[N];

int main(int argc, char const *argv[])
{
	int n, res = 0;
	std::cin >> n;
	for (int i = 0; i < n; ++i) std::cin >> a[i];
	for (int i = 0, j = 0; i < n; ++i) {
		++s[a[i]];
		while (s[a[i]] > 1) {
			--s[a[j]];
			++j;
		}
		res = std::max(res, i - j + 1);
	}
	std::cout << res << std::endl;
	return 0;
}