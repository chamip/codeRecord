/*
 * @Author: chamip
 * @Date: 2023-02-01 16:42:18
 * @LastEditTime: 2023-02-01 17:19:21
 * @LastEditors: chamip
 * @FilePath: /undefined/Users/chamip/github/codeRecord/leetcode/87.cpp
 */
#include <algorithm>
#include <string>
#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
private:
	int memo[30][30][31];
	string s1, s2;
public:
	bool checkIfSimilar(int i1, int i2, int length) {
		unordered_map<char, int> umci;
		for (int i = i1; i < i1 + length; ++i) {
			++umci[s1[i]];
		}
		for (int i = i2; i < i2 + length; ++i) {
			--umci[s2[i]];
		}
		//在lambda使用auto时，-std>=c++14
		if (any_of(umci.begin(), umci.end(), [] (const auto &entry)->bool { return entry.second != 0;})) {
			return false;
		}
		return true;
	}

	bool dfs(int i1, int i2, int length) {
		//记忆话搜索
		if (memo[i1][i2][length] != 0) return memo[i1][i2][length] == 1;
		//字符串相等
		if (s1.substr(i1, length) == s2.substr(i2, length)) {
			memo[i1][i2][length] = 1;
			return true;
		}
		//每个字符出现次数
		if (!checkIfSimilar(i1, i2, length)) {
			memo[i1][i2][length] = -1;
			return false;
		}
		//枚举分割位置
		for (int i = 1; i < length; ++i) {
			if (dfs(i1, i2, i) && dfs(i1 + i, i2 + i, length - i)) {
				memo[i1][i2][length] = 1;
				return true;
			}
			if (dfs(i1, i2 + length - i, i) && dfs(i1 + i, i2, length - i)) {
				memo[i1][i2][length] = 1;
				return true;
			}
		}
		memo[i1][i2][length] = -1;
		return false;
	}

	bool isScramble(string s1, string s2) {
		memset(memo, 0, sizeof(memo));
		int n = s1.size();
		this->s1 = s1;
		this->s2 = s2;
		return dfs(0, 0, n);
	}
};

int main(int argc, char const *argv[])
{
	Solution *s = new Solution();
	if (s->isScramble("great", "rgeat")) {
		cout << "true!!!" << endl;
	} else cout << "false..." << endl;
	return 0;
}
