#include <iostream>

int main(int argc, char const *argv[])
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(nullptr);
	int m, n;
	std::cin >> m >> n;
	std::cout << m * n / 2 << std::endl;
	return 0;
}