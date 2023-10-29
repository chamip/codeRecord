#include <iostream>

using namespace std;

typedef int32_t int32;
#define VARHDRSZ ((int32)sizeof(int32))

int main(int argc, char const *argv[])
{
    cout << VARHDRSZ << endl;
    return 0;
}