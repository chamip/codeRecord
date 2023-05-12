#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

std::string make_plural(size_t t, const std::string &a, const std::string &b) {
    return t > 1 ? a + b : a;
}

void biggies(std::vector<std::string> &words, std::vector<std::string>::size_type sz) {
    // 按照字典序排序，去掉重复元素
    std::sort(words.begin(), words.end());
    auto end_unique = unique(words.begin(), words.end());
    words.erase(end_unique, words.end());
    // for_each(words.begin(), words.end(), [] (const std::string &a) {std::cout << a << " ";});
    // std::cout << std::endl;
    // 按照长度排序，长度相同的字典序不变
    std::stable_sort(words.begin(), words.end(), [] (const std::string &a, const std::string &b) {
        return a.size() < b.size();
    });
    // for_each(words.begin(), words.end(), [] (const std::string &a) {std::cout << a << " ";});
    // std::cout << std::endl;
    auto wc = find_if(words.begin(), words.end(), [sz] (const std::string &a) {
        return a.size() >= sz;
    });
    int count = words.end() - wc;
    std::cout << count << " " << make_plural(count, "word", "s") << " of length " \
              << sz << " or longger" << std::endl;
    for_each(wc, words.end(), [] (const std::string &a) {std::cout << a << " ";});
    std::cout << std::endl;
}


int main(int argc, char const *argv[])
{
    std::vector<std::string> words {"Julia", "Zek", "Ak", "David", "Ak"};
    std::vector<std::string>::size_type sz = 3;
    biggies(words, sz);
    return 0;
}
