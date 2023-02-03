#include <iostream>
#include <string>

int main(int argc, char const *argv[])
{
	std::string str;
	std::cin >> str;
	int n = str.size() - 1;
	int res = 0;
	while (n >= 0) {
		if (n > 1 && str[n] == '0' && str[n - 1] == '0') {
			++res;
			n -= 2;
		} else {
			++res;
			n -= 1;
		}
	}
	std::cout << res << std::endl;
	return 0;
}