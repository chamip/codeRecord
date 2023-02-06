#include <iostream>
using namespace std;

void print_array(const int array[], const int length) {
    cout << "[";
    for (int i=0; i<length; i++) {
        // Last element
        if (i == length-1) {
            cout << array[i] << "]" << endl;
        } else {
            // Any other element
            cout << array[i] << ", ";
        }
    }
    cout << endl;
}

int main(int argc, char const *argv[])
{
    int array[] = {1, 3, 5, 7, 9, 15, 15, 16, 40, 70};
    int length = 10;

    cout << "Array is = ";
    print_array(array, length);
    return 0;
}