#include <iostream>
#include <vector>

class Solution {
public:
    int getSum(int k) {
        int sum = 0;
        while (k > 0) {
            sum += (k % 10);
            k /= 10;
        }
        return sum;
    }
    int countBalls(int lowLimit, int highLimit) {
		std::vector<int> vc(highLimit, 0);
        int res = 0; 
        for (int k = lowLimit; k <= highLimit; ++k) {
            int sum = getSum(k);
            ++vc[sum];
            res = std::max(res, vc[sum]);
        }
        return res;
    }
};

int main(int argc, char const *argv[])
{
	Solution *s = new Solution();
	int lowLimit, highLimit;
	std::cin >> lowLimit >> highLimit;
	std::cout << s->countBalls(lowLimit, highLimit) << std::endl;
	return 0;
}
