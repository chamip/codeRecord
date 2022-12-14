#include <iostream>
#include <vector>

class Solution {
public:
	std::vector<int> findDisappearedNumbers(std::vector<int>& nums) {
        int n = (int)nums.size();
        for (auto num : nums) {
            int x = (num - 1) % n;
            nums[x] += n;
        }
		std::vector<int> res;
        for (int i = 0; i < n; ++i) {
            if (nums[i] <= n) {
                res.push_back(i + 1);
            }
        }
        return res;
    }
};

int main(int argc, char const *argv[])
{
	std::vector<int> nums {4,3,2,7,8,2,3,1};
	Solution *s = new Solution();
	std::vector<int> res = s->findDisappearedNumbers(nums);
	for (auto x : res) {
		std::cout << x << " ";
	}
	std::cout << std::endl;
	return 0;
}
