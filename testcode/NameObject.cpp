#include <string>
#include <iostream>
#include <ostream>

// template <typename T>
class NameObject {
    public:
        NameObject(std::string &name, const int &value): nameValue(name), objectValue(value) {}
        
        NameObject &operator=(const NameObject &rhs) {
            nameValue = rhs.nameValue;
            objectValue = rhs.objectValue;
            return *this;
        }

        friend std::ostream &operator<<(std::ostream &os, const NameObject &no);

    private:
        std::string nameValue;
        int objectValue;
};

std::ostream &operator<<(std::ostream &os, const NameObject &no) {
    os << "nameValue: " << no.nameValue << std::endl \
          << "objectValue: " << no.objectValue << std::endl;
          return os;
}

int main(int argc, char const *argv[]) {
    std::string newDog("abc");
    std::string oldDog("def");
    NameObject p(newDog, 2);
    NameObject s(oldDog, 1);
    p = s;
    std::cout << p << std::endl;
}