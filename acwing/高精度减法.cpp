/*
* @Author: chamip
* @Date:   2022-12-06 21:35:01
* @Last Modified by:   chamip
* @Last Modified time: 2022-12-09 12:12:34
*/

/*
给定两个正整数（不含前导 0），计算它们的差，计算结果可能为负数。

输入格式
共两行，每行包含一个整数。

输出格式
共一行，包含所求的差。

数据范围
1≤整数长度≤105
输入样例：
32
11
输出样例：
21
*/

#include <iostream>
#include <vector>

bool cmp(const std::vector<int> &A, const std::vector<int> &B) {
	if (A.size() != B.size()) return A.size() > B.size();
	for (int i = A.size() - 1; i >= 0; --i) {
		if (A[i] != B[i]) return A[i] > B[i];
	}
	return true;
}

std::vector<int> sub(const std::vector<int> &A, const std::vector<int> &B) {
	std::vector<int> C;
	int t = 0; //借位位
	for (int i = 0; i < A.size(); ++i) {
		t = A[i] - t;
		if (i < B.size()) t -= B[i];
		C.emplace_back((t + 10) % 10);
		if (t < 0) t = 1;
		else t = 0;
	}
	while (C.size() > 1 && C.back() == 0) C.pop_back();
	return C;
}

int main(int argc, char const *argv[])
{
	std::string a, b;
	std::vector<int> A, B;
	std::cin >> a >> b; //a = "123456"
	for (int i = a.size() - 1; i >= 0; --i) A.emplace_back(a[i] - '0'); //A = {6, 5, 4, 3, 2, 1}
	for (int i = b.size() - 1; i >= 0; --i) B.emplace_back(b[i] - '0');
	if (cmp(A, B)) {
		auto C = sub(A, B);
		for (int i = C.size() - 1; i >= 0; --i) std::cout << C[i];
	} else {
		auto C = sub(B, A);
		std::cout << "-";
		for (int i = C.size() - 1; i >= 0; --i) std::cout << C[i];
	}
	std::cout << std::endl;
	return 0;
}
