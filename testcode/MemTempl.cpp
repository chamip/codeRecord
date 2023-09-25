/* 
 * Member Templete
 * class的成员函数可以是templete，但是member templete不可以是virtual
 */

#include <iostream>
#include <ostream>
#include <typeinfo>

template <typename T>
class MyClass {
    private:
        T value;
    public:
        MyClass():value(0) {}
        MyClass(T _value):value(_value) {}

        template <typename U>
        void assign(const U& x) {
            value = x.getValue();
        }

        //assign的实参x的类型与*this不同，不能直接取用MyClass<>的private和protected成员
        T getValue() const {
            return value;
        }

        friend std::ostream &operator<<(std::ostream &os, const MyClass<T> &t) {
            os << t.getValue();
            return os;
        }

        ~MyClass() {}
};

int main(int argc, char const *argv[])
{
    MyClass<double> d(1.0);
    MyClass<int> i(1);
    d.assign(d);
    d.assign(i);
    std::cout << d << " " << i << std::endl;

    const std::type_info &tid = typeid(d);
    const std::type_info &tii = typeid(i);
    std::cout << "name: \t" << "before: \t" << "hash_code: \t" << std::endl;
    std::cout << tid.name() << "\t" << tid.before(tii) << "\t" << tid.hash_code() << "\t" << std::endl;
    std::cout << tii.name() << "\t" << tii.before(tid) << "\t" << tii.hash_code() << "\t" << std::endl;
    return 0;
}