#include <iostream>

class Cls
{
    //some var
    //some methods
    private:
        int a;
        float b;
    public:
        void f1();
        Cls():a(0), b(0.0) {};
        friend std::ostream &operator<<(std::ostream &os, const Cls &cls) {
            return os << cls.a << " " << cls.b << std::endl;
        };
};

int main()
{
    Cls obj;
    std::cout << obj;
}