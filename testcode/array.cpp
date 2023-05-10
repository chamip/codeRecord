#include <iostream>

int main(int argc, char const *argv[])
{
    const int N = 5;
    std::array<int, N> arr {1, 2};
    for (int i = 0; i < N; ++i) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
    
    // 报错，大小也是array的一部分
    // std::array<int, 10> arr1 = arr;
    // for (int i = 0; i < 10; ++i) {
    //     std::cout << arr1[i] << " ";
    // }

    std::array<int, N> arr1(arr);
    for (int i = 0; i < N; ++i) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
    return 0;
}