/*
 * @Author: chamip
 * @Date: 2023-01-21 15:22:43
 * @LastEditTime: 2023-01-21 15:38:32
 * @LastEditors: chamip
 * @FilePath: /codeRecord/leetcode/1824.cpp
 */

/**
 * @brief 最少侧跳次数
 * location: Yichang,Hubei
 */

 #include <algorithm>
#include <ios>
#include <iostream>
#include <vector>

static constexpr int maxCnt = INT_MAX;

int minSideJumps(std::vector<int>& obstacles) {
    int res;
    std::vector<int> d {1, 0, 1};
    int n = obstacles.size();
    for (int i = 1; i < n; ++i) {
        int minCnt = maxCnt;
        for (int j = 0; j < 3; ++j) {
            if (j == obstacles[i] - 1) d[j] = maxCnt;
            else minCnt = std::min(minCnt, d[j]);
        }
        for (int j = 0; j < 3; ++j) {
            if (j == obstacles[i] - 1) continue;
            d[j] = std::min(d[j], minCnt + 1);
        }
    }
    res = *std::min_element(d.begin(), d.end());
    return res;
}

int main(int argc, char const *argv[])
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::vector<int> obstacles {0, 2, 1, 0, 3, 0};
    std::cout << minSideJumps(obstacles) << std::endl;
    
    return 0;
}