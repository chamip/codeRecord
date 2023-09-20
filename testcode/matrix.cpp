#include <iostream>
#include <ostream>

struct Matrix {
    float data[3][3];
};


Matrix add(Matrix ma, Matrix mb) {
    Matrix mr;
    for (int i=0; i<3; i++){
        for (int j = 0; j < 3; ++j) {
            mr.data[i][j] = ma.data[i][j] + mb.data[i][j];
        }
    }
    return mr;
}

std::ostream &operator<<(std::ostream &os, Matrix &m) {
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            os << m.data[i][j] << "\t";
        }
        os << std::endl;
    }
    os << std::endl;
    return os;
}

int main() {
    Matrix a = {{{1,2,3},{4,5,6},{7,8,9}}};
    Matrix b = {{{2,2,2},{3,3,3},{4,5,6}}};
    Matrix c = add(a, b);
    std::cout << c << std::endl;
    return 0;
}