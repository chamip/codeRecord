#include <iostream>
#include <vector>
using namespace std;
/* 先判断两条斜边的中点是否重合
 * 再判断长度是否相等
 * 最后判断是否垂直
*/
class Solution {
private:
	bool checkMid(const vector<int>& p1, const vector<int>& p2, const vector<int>& p3, const vector<int>& p4) {
		return (p1[0] + p2[0] == p3[0] + p4[0]) && (p1[1] + p2[1] == p3[1] + p4[1]);
	}

	bool checkLen(const vector<int>& v1, const vector<int>& v2) {
		if (v1[0] * v1[0] + v1[1] * v1[1] == v2[0] * v2[0] + v2[1] * v2[1]) {
			return true;
		}
		return false;
	}
	
	bool checkAngle(const vector<int>& v1, const vector<int>& v2) {
		if (v1[0] * v2[0] + v1[1] * v2[1] == 0) {
			return true;
		}
		return false;
	}

	bool check(vector<int>& p1, vector<int>& p2, vector<int>& p3, vector<int>& p4) {
		vector<int> v1 = {p1[0] - p2[0], p1[1] - p2[1]};
		vector<int> v2 = {p3[0] - p4[0], p3[1] - p4[1]};
		if (checkMid(p1, p2, p3, p4) && checkLen(v1, v2) && checkAngle(v1, v2)) {
			return true;
		}
		return false;
	}

public:
    bool validSquare(vector<int>& p1, vector<int>& p2, vector<int>& p3, vector<int>& p4) {
		if (p1 == p2) {
			return false;
		}
		if (check(p1, p2, p3, p4)) {
			return true;
		}
		if (p1 == p3) {
			return false;
		}
		if (check(p1, p3, p2, p4)) {
			return true;
		}
		if (p1 == p4) {
			return false;
		}
		if (check(p1, p4, p2, p3)) {
			return true;
		}
		return false;
    }
};

int main(int argc, char const *argv[])
{
//    using std::cout;
//    using std::endl;
	Solution *s = new Solution();
//	vector<int> p1 = {0, 0};
//	vector<int> p2 = {1, 1};
//	vector<int> p3 = {1, 0};
//	vector<int> p4 = {0, 1};
//	vector<int> p1 = {0, 0};
//	vector<int> p2 = {1, 1};
//	vector<int> p3 = {1, 0};
//	vector<int> p4 = {0, 12};
	vector<int> p1 = {1, 0};
	vector<int> p2 = {-1, 0};
	vector<int> p3 = {0, 1};
	vector<int> p4 = {0, -1};
	if (s->validSquare(p1, p2, p3, p4)) {
		cout << "YES" << endl;
	} else {
		cout << "NO" << endl;
	}
	return 0;
}
