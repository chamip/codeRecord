#include <iostream>
#include <map>

int main(int argc, char const *argv[])
{
    std::map<int, int> m;
    //对不在map（unordered_map）中的元素使用下标操作会插入新元素，关联值进行值初始化
    m[1];
    for (auto [x, y]  : m) {
        std::cout << x << " " << y << std::endl;
    }
    return 0;
}