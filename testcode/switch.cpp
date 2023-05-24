#include <iostream>
#include <unordered_map>

void solve(int&);

std::unordered_map<std::string, int> mp{{"int4", 4}, {"int2", 2}};

int main(int argc, char const *argv[])
{
    int oci_type_size = 0;
    solve(oci_type_size);
    std::cout << oci_type_size << std::endl;
    return 0;
}

void solve(int &oci_type_size) {
    std::string oci_type_name("int2");
    if (mp.count(oci_type_name)) {
        oci_type_size = mp[oci_type_name];
    }
    return ;
}