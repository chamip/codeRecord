#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

class Solution {
public:
    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) {
        int m = queries.size();
        vector<int> res(m);
        int n = words.size();
        vector<int> cnt(n);
        unordered_set<char> usc {'a', 'e', 'i', 'o', 'u'};
        function<bool(string)> checkStatus = [=] (string s) {
            if (usc.count(s[0]) && usc.count(s[s.size() - 1])) {
                return true;
            }
            return false;
        };
        for (int i = 0; i < n; ++i) {
            cnt[i] = checkStatus(words[i]) ? 1 : 0;
        }
        vector<int> prefixSum(n + 1, 0);
        for (int i = 1; i <= n; ++i) {
            prefixSum[i] = prefixSum[i - 1] + cnt[i - 1];
        }
        for (int i = 0; i < m; ++i) {
            res[i] = prefixSum[queries[i][1] + 1] - prefixSum[queries[i][0]];
        }
        return res;
    }
};

int main(int argc, char const *argv[])
{
    Solution *s = new Solution();
    vector<string> words {"a","e","i"};
    vector<vector<int>> queries {{0,2}, {0,1}, {2,2}};
    vector<int> res = s->vowelStrings(words, queries);
    for (int i = 0; i < res.size(); ++i) {
        cout << res[i] << " ";
    }
    cout << endl;
    return 0;
}