#include <climits>
#include <iostream>

int lowbit(int x) {
	return (x == INT_MIN ? x :  x & (-x));
}
int main (int argc, char *argv[])
{
	int x;
	std::cout << INT_MIN << std::endl;
	std::cout << "------" << std::endl;
	while ((std::cin >> x) && x != -1) {
		int lsb = lowbit(x);
		std::cout << "lowbit(x) : " << lsb  << std::endl;
		std::cout << "x & lsb(lowbit(x)) = " << (x & lsb) << std::endl;
	}    
    return 0;
}
