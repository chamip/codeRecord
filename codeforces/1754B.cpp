#include <iostream>
#include <vector>
using namespace std;

int main(int argc, char const *argv[])
{
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		int cur = n / 2, step = n / 2;
		vector<int> res;
		if (n % 2 == 1) {
			res.push_back(n);
		}
		while (cur > 0) {
			res.push_back(cur);
			res.push_back(cur + step);
			--cur;
		}
		for (int i = 0; i < n - 1; ++i) {
			std::cout << res[i] << " ";
		}
		std::cout << res[n - 1] << std::endl;
	}
	return 0;
}
