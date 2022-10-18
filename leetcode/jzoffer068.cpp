#include <iostream>
#include <vector>
using namespace std;
int searchInsert(vector<int>& nums, int target) {
    int left = 0;
    int right = nums.size() - 1;
    while (left < right) {
        int mid = left + (right - left) / 2;
        if (nums[mid] == target) {
            return mid;
        } else if (nums[mid] > target) {
            right = mid;
        } else {
            left = mid + 1;
        }
    }
    return left;
}
int main(int argc, char const *argv[])
{
	vector<int> nums {1,3,5,6};
	int target = 2;
	cout << searchInsert(nums, target) << endl;
	return 0;
}
