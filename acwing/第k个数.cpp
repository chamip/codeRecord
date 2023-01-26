/*
* @Author: chamip
* @Date:   2022-12-09 12:03:54
* @Last Modified by:   chamip
* @Last Modified time: 2022-12-09 12:04:23
*/

/*
给定一个长度为 n 的整数数列，以及一个整数 k，请用快速选择算法求出数列从小到大排序后的第 k 个数。

输入格式
第一行包含两个整数 n 和 k。

第二行包含 n 个整数（所有整数均在 1∼109 范围内），表示整数数列。

输出格式
输出一个整数，表示数列的第 k 小数。

数据范围
1≤n≤100000,
1≤k≤n
输入样例：
5 3
2 4 1 5 3
输出样例：
3
*/

#include <iostream>
const int N = 1e5 + 10;
int q[N];

void quick_sort(int q[], int l, int r) {
	if (l >= r) return ;
	int i = l - 1, j = r + 1, x = q[(l + r) >> 1];
	while (i < j) {
		do i++; while (q[i] < x);
		do j--; while (q[j] > x);
		if (i < j) std::swap(q[i], q[j]);
	}
	quick_sort(q, l, j);
	quick_sort(q, j + 1, r);
}

int main(int argc, char const * argv[])
{
	int n, k;
	std::cin >> n >> k;
	for (int i = 0; i < n; ++i) {
		std::cin >> q[i];
	}
	quick_sort(q, 0, n - 1);
	std::cout << q[k - 1] << std::endl;
	return 0;
}
