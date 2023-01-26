/*
* @Author: chamip
* @Date:   2022-12-09 12:07:27
* @Last Modified by:   chamip
* @Last Modified time: 2022-12-09 12:12:02
*/

/*
给定两个正整数（不含前导 0），计算它们的和。

输入格式
共两行，每行包含一个整数。

输出格式
共一行，包含所求的和。

数据范围
1≤整数长度≤100000
输入样例：
12
23
输出样例：
35
*/

#include <iostream>
#include <vector>

std::vector<int> add(const std::vector<int> &A, const std::vector<int> &B) {
	std::vector<int> C;
	int t = 0; //进位位
	for (int i = 0; i < A.size() || i < B.size(); ++i) {
		if (i < A.size()) t += A[i];
		if (i < B.size()) t += B[i];
		C.emplace_back(t % 10);
		t /= 10;
	}
	if (t) C.emplace_back(t);
	return C;
}

int main(int argc, char const *argv[])
{
	std::string a, b;
	std::vector<int> A, B;
	std::cin >> a >> b; //a = "123456"
	for (int i = a.size() - 1; i >= 0; --i) A.emplace_back(a[i] - '0'); //A = {6, 5, 4, 3, 2, 1}
	for (int i = b.size() - 1; i >= 0; --i) B.emplace_back(b[i] - '0');
	auto C = add(A, B);
	for (int i = C.size() - 1; i >= 0; --i) std::cout << C[i];
	std::cout << std::endl;
	return 0;
}
