#include <iostream>
#include <vector>

int main(int argc, char const *argv[])
{
	int t;
	std::cin >> t;
	while (t--) {
		int n;
		std::cin >> n;
		std::vector<char> vc(n);
		int res = 0;
		for (int i = 0; i < n; ++i) {
			std::cin >> vc[i];
			if (vc[i] == 'Q') {
				--res;
			} else if (vc[i] == 'A') {
				++res;
				if (res > 0) {
					res = 0;
				}
			}
		}
		std::cout << (res == 0 ? "YES" : "NO") << std::endl;
	}
	return 0;
}
