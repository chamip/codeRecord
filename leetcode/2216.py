class Solution:
    def minDeletion(self, nums: list[int]) -> int:
        n, i, res = len(nums), 0, len(nums)
        while i + 1 < n:
            if (nums[i] == nums[i + 1]):
                res -= 1
                i += 1
            elif nums[i] != nums[i + 1]:
                i += 2
        # print(res)
        if res % 2:
            res -= 1
        return n - res

if __name__ == '__main__':
    nums = [1, 1, 2, 3, 5]
    print(Solution().minDeletion(nums))
