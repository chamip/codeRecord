#include <iostream>

int main(int argc, char const *argv[])
{
	int l = 8;
	int r = 16;
	//右移优先级比加号低
	int res1 = l + (r - l) >> 1;    // 8
	int res2 = l + ((r - l) >> 1);  // 12
	std::cout << res1 << std::endl << res2 << std::endl;
	return 0;
}