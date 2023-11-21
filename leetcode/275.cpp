#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int hIndex(vector<int>& citations) {
        int n = citations.size();
        int left = 0, right = n - 1;
        while (left <= right) {
            int mid = left + (right - left + 1) / 2;
            if (citations[mid] >= n - mid) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        return n - left;
    }
};

int main(int argc, char const *argv[]) 
{
    // vector<int> citations {0, 1, 3, 5, 6};
    vector<int> citations {1, 2, 100};
    Solution *s = new Solution();
    int res = s->hIndex(citations);
    cout << res << endl;
    return 0;
}