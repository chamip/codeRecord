#include <iostream>
#include <functional>
#include <typeinfo>

std::function<int(int, int)> returnLambda () {
    return [] (int x, int y) {
        return x + y;
    };
}

std::function<int(int, int)> returnLambda1 = [] (int x, int y) -> int {
    return x + y;
};

int main()
{
    auto lf = returnLambda();
    std::cout << lf(2, 3) << std::endl;
    auto ans = returnLambda1(1 ,2);
    std::cout << ans << std::endl;
    const std::type_info &rlInfo = typeid(returnLambda());
    const std::type_info &rl1Info = typeid(returnLambda1);
    std::cout << "type of rl:" << rlInfo.name() << std::endl;
    std::cout << "type of rl1:" << rl1Info.name() << std::endl;
    std::cout << (typeid(rlInfo) == typeid(rl1Info) ? "equal" : "not equal") << std::endl;
    return 0;
}