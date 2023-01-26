/*
* @Author: chamip
* @Date:   2022-12-06 22:14:04
* @Last Modified by:   chamip
* @Last Modified time: 2022-12-09 12:13:01
*/

/*
给定两个非负整数（不含前导 0） A 和 B，请你计算 A×B 的值。

输入格式
共两行，第一行包含整数 A，第二行包含整数 B。

输出格式
共一行，包含 A×B 的值。

数据范围
1≤A的长度≤100000,
0≤B≤10000
输入样例：
2
3
输出样例：
6
*/

#include <iostream>
#include <vector>

std::vector<int> mul(std::vector<int> &A, int b) {
	std::vector<int> C;
	int t = 0;//进位位
	for (int i = 0; i < A.size() || t; ++i) {
		if (i < A.size()) t += A[i] * b;
		C.emplace_back(t % 10);
		t /= 10;
	}
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
	
	auto C = mul(A, b);
	for (int i = C.size() - 1; i >= 0; --i) std::cout << C[i];
	std::cout << std::endl;
	return 0;
}
