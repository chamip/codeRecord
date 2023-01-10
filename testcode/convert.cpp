/*
 * @Author: chamip
 * @Date: 2023-01-10 15:42:50
 * @LastEditTime: 2023-01-10 15:45:49
 * @LastEditors: chamip
 * @FilePath: /codeRecord/testcode/convert.cpp
 */
#include <iostream>
#include <iomanip>
#include <cstdlib>
 
int main(int argc, char *argv[])
{
    std::cout << "argc == " << argc << '\n';
 
    for(int ndx{}; ndx != argc; ++ndx) {
        std::cout << ndx << ":" << "argv[" << ndx << "] == " << std::quoted(argv[ndx]) << '\n';
    }
    std::cout << "argv[" << argc << "] = "
              << static_cast<void*>(argv[argc]) << '\n';
    /*...*/
    return argc == 3 ? EXIT_SUCCESS : EXIT_FAILURE; // 可选返回值
}