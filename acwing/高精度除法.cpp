/*
* @Author: chamip
* @Date:   2022-12-06 23:33:49
* @Last Modified by:   chamip
* @Last Modified time: 2022-12-09 12:13:36
*/

/*
给定两个非负整数（不含前导 0） A，B，请你计算 A/B 的商和余数。

输入格式
共两行，第一行包含整数 A，第二行包含整数 B。

输出格式
共两行，第一行输出所求的商，第二行输出所求余数。

数据范围
1≤A的长度≤100000,
1≤B≤10000,
B 一定不为 0
输入样例：
7
2
输出样例：
3
1
*/

#include <iostream>
#include <vector>
#include <algorithm>

std::vector<int> div(std::vector<int> &A, int b, int &t) {
	std::vector<int> C;
	for (int i = A.size() - 1; i >= 0; --i) {
		t = t * 10 + A[i];
		C.emplace_back(t / b);
		t %= b;
	}
	reverse(C.begin(), C.end());
	while (C.size() > 1 && C.back() == 0) C.pop_back();
	return C;
}

int main(int argc, char const *argv[])
{
	std::string a;
	int b;
	std::vector<int> A;
	std::cin >> a >> b; //a = "123456"
	for (int i = a.size() - 1; i >= 0; --i) A.emplace_back(a[i] - '0'); //A = {6, 5, 4, 3, 2, 1}
	int t = 0;
	auto C = div(A, b, t);
	for (int i = C.size() - 1; i >= 0; --i) std::cout << C[i];
	std::cout << std::endl << t << std::endl;
	return 0;
}
