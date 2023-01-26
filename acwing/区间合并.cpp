/*
给定 n 个区间 [li,ri]，要求合并所有有交集的区间。

注意如果在端点处相交，也算有交集。

输出合并完成后的区间个数。

例如：[1,3] 和 [2,6] 可以合并为一个区间 [1,6]。

输入格式
第一行包含整数 n。

接下来 n 行，每行包含两个整数 l 和 r。

输出格式
共一行，包含一个整数，表示合并区间完成后的区间个数。

数据范围
1≤n≤100000,
−109≤li≤ri≤109
输入样例：
5
1 2
2 4
5 6
7 8
7 9
输出样例：
3
*/

#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>

typedef std::pair<int, int> PII;

void mergeLR(std::vector<PII> &segs) {
	std::vector<PII> res;
	sort(segs.begin(),segs.end());
	int fi = INT_MIN, se = INT_MIN;
	for (auto seg : segs) {
		if (se < seg.first) {
			if (se != INT_MIN) res.push_back({fi, se});
			fi = seg.first, se = seg.second;
		} else {
			se = std::max(se, seg.second);
		}
	}
	if (se != INT_MIN) res.push_back({fi, se});
	segs = res;
}

int main(int argc, char const *argv[])
{
	int n;
	std::cin >> n;
	std::vector<PII> v(n);
	for (int i = 0; i < n; ++i) std::cin >> v[i].first >> v[i].second;
	mergeLR(v);
	std::cout << v.size() << std::endl;
	return 0;
}