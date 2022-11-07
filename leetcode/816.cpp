//
// Created by chamip on 2022/11/7.
//

#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    vector<string> getPos(string s) {
        vector<string> pos;
        if (s[0] != '0' || s == "0") pos.push_back(s);
        for (int p = 1; p < s.size(); ++p) {
            if ((p != 1 && s[0] == '0') || s.back() == '0') continue;
            pos.push_back(s.substr(0, p) + "." + s.substr(p));
        }
        return pos;
    }
    vector<string> ambiguousCoordinates(string s) {
        int n = s.size() - 2;
        vector<string> res;
        s = s.substr(1, s.size() - 2);
        for (int l = 1; l < n; ++l) {
            vector<string> lt = getPos(s.substr(0, l));
            if (lt.empty()) continue;
            vector<string> rt = getPos(s.substr(l));
            if (rt.empty()) continue;
            for (auto& i : lt) {
                for (auto& j : rt) {
                    res.push_back("(" + i + ", " + j + ")");
                }
            }
        }
        return res;
    }
};

int main(int argc, char const *argv[])
{
    Solution* s = new Solution();
    string str = "(123)";
    vector<string> res = s->ambiguousCoordinates(str);
    for (auto x : res) {
        cout << x << endl;
    }
}