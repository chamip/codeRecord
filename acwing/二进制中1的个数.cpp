/*
给定一个长度为 n 的数列，请你求出数列中每个数的二进制表示中 1 的个数。

输入格式
第一行包含整数 n。

第二行包含 n 个整数，表示整个数列。

输出格式
共一行，包含 n 个整数，其中的第 i 个数表示数列中的第 i 个数的二进制表示中 1 的个数。

数据范围
1≤n≤100000,
0≤数列中元素的值≤109
输入样例：
5
1 2 3 4 5
输出样例：
1 1 2 1 2
*/
#include <iostream>

const int N = 1e5 + 10;
int q[N];

//返回最后一位1，如1010000: 10000
int lowbit(int x) {
	return x & (-x);
}

int main(int argc, char const *argv[])
{
	int n;
	std::cin >> n;
	for (int i = 0; i < n; ++i) std::cin >> q[i];
	for (int i = 0; i < n; ++i) {
		int count = 0;
		int x = q[i];
		while (x > 0) {
			x -= lowbit(x);
			++count;
		}
		std::cout << count << " ";
	}
	return 0;
}