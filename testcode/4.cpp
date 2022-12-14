#include <iostream>
typedef signed int int32;
#define VARHDRSZ ((int32)sizeof(int32));

int main(int argc, char const *argv[])
{
	std::cout << VARHDRSZ;
	return 0;
}