/*
* @Author: chamip
* @Date:   2022-12-09 12:06:24
* @Last Modified by:   chamip
* @Last Modified time: 2022-12-09 12:06:33
*/

/*
给定一个浮点数 n，求它的三次方根。

输入格式
共一行，包含一个浮点数 n。

输出格式
共一行，包含一个浮点数，表示问题的解。

注意，结果保留 6 位小数。

数据范围
−10000≤n≤10000
输入样例：
1000.00
输出样例：
10.000000
*/

//浮点数二分
#include <ios>
#include <iostream>

const double eps = 1e-8;
double n;

int main(int argc, char const *argv[])
{
	double n;
	std::cin >> n;
	double r = 100, l = -100;
	while (r - l > eps) {
		double mid = (l + r) / 2;
		if (mid * mid *mid >= n) r = mid;
		else l = mid;
	}
	std::cout.setf(std::ios_base::fixed, std::ios_base::floatfield);
	std::cout.precision(6);
	std::cout << l << std::endl;
	return 0;
}
