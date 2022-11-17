//
// Created by chamip on 2022/11/16.
//
#include <iostream>
#include <vector>
#include <unordered_set>

class Solution {
public:
    std::string destCity(std::vector<std::vector<std::string>>& paths) {
        std::unordered_set<std::string> us;
        for (std::vector<std::string> vs : paths) {
            us.emplace(vs[0]);
        }
        for (std::vector<std::string> vs : paths) {
            if (us.find(vs[1]) == us.end()) {
                return vs[1];
            }
        }
        return "";
    }
};

int main(int argc, char const *argv[])
{
    std::vector<std::vector<std::string>> paths {{"London", "New York"}, {"New York", "Lima"}, {"Lima", "Sao Paulo"}};
    Solution *s = new Solution();
    std::string res = s->destCity(paths);
    std::cout << res << std::endl;
    return 0;
}