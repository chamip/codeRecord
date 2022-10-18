#include <iostream>
#include <vector>
using namespace std;
vector<int> targetIndices(vector<int>& nums, int target) {
    int cnt1 = 0;
    int cnt2 = 0;
    for (const auto& x : nums) {
        if (x < target) {
            ++cnt1;
        } else if (x == target) {
            ++cnt2;
        }
    }
    vector<int> res;
    for (int i = cnt1; i < cnt1 + cnt2; ++i) {
        res.push_back(i);
    }
    return res;
}

int main(int argc, char const *argv[])
{
	vector<int> nums = {1,2,5,2,3};
	int target = 5;
	vector<int> res = targetIndices(nums, target);
	for (int i = 0; i < res.size(); ++i) {
		cout << res[i] << endl;
	}
	return 0;
}
