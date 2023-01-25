#include <iostream>
#include <vector>

int main(int argc, char const *argv[])
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(nullptr);
	int n, k;
	std::cin >> n >> k;
	std::vector<int> vi(n + 1);
	for (int i = 1; i <= n; ++i) {
		std::cin >> vi[i];
	}
	int res = 0;
	for (int i = 1; i <= n; ++i) {
		if (vi[i] == 0 || vi[i] < vi[k]) {
			break;
		}
		++res;
	}
	std::cout << res << std::endl;
	return 0;
}