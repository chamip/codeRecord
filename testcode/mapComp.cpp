#include <iostream>
#include <map>

class Foo {
public:
    int j;
    Foo(int a) : j(a) {}
};
struct compareFunction {
    bool operator()(const Foo& a, const Foo& b) const {
        return a.j < b.j;
    }
};

int main(int argc, char const *argv[])
{
	// this isn't allowed (although it can vary depending on compiler)
	// std::map<Foo, int> fooMap;
	std::map<Foo, int, compareFunction> fooMap;
	fooMap[Foo(2)]  = 1;
	auto it = fooMap.find(Foo(1)); //true
	if (it != fooMap.end()) std::cout << "true";
	else std::cout << "false";
	std::cout << std::endl;
}
