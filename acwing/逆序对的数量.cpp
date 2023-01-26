/*
* @Author: chamip
* @Date:   2022-12-09 12:04:50
* @Last Modified by:   chamip
* @Last Modified time: 2022-12-09 12:05:02
*/

/*
给定一个长度为 n 的整数数列，请你计算数列中的逆序对的数量。

逆序对的定义如下：对于数列的第 i 个和第 j 个元素，如果满足 i<j 且 a[i]>a[j]，则其为一个逆序对；否则不是。

输入格式
第一行包含整数 n，表示数列的长度。

第二行包含 n 个整数，表示整个数列。

输出格式
输出一个整数，表示逆序对的个数。

数据范围
1≤n≤100000，
数列中的元素的取值范围 [1,109]。

输入样例：
6
2 3 4 5 6 1
输出样例：
5
*/

#include  <iostream>

typedef long long LL;
const int N = 1e5 + 10;
int q[N], tmp[N];

LL merge_sort(int l, int r) {
	if (l >= r) return 0;
	
	int mid = (l + r) >> 1;
	
	LL res = merge_sort(l, mid) + merge_sort(mid + 1, r);
	
	int k = 0, i = l, j = mid + 1;
	
	while (i <= mid && j <= r) {
		if (q[i] <= q[j]) tmp[k++] = q[i++];
		else {
			tmp[k++] =q[j++];
			res += mid - i + 1;
		}
	}
	while (i <= mid ) tmp[k++] = q[i++];
	while (j <= r) tmp[k++] =q[j++];
	
	for (int i = l, k = 0; i <= r; ++i, ++k) q[i] = tmp[k]; 
	return res;
}

int main(int argc, char const *argv[])
{
	int n;
	std::cin >> n;
	for (int i = 0; i < n; ++i) std::cin >> q[i];
	LL res = merge_sort(0, n - 1);
	std::cout << res << std::endl;
	return 0;
}
