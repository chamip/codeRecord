#include <iostream>
#include <vector>

using namespace std;

void quicksort(vector<int>& arr, int left, int right) {
    if (left >= right) {
        return;
    }

    int pivot = arr[left];
    int i = left + 1;
    int j = right;

    while (i <= j) {
        if (arr[i] <= pivot) {
            i++;
        } else if (arr[j] >= pivot) {
            j--;
        } else {
            swap(arr[i], arr[j]);
        }
    }

    swap(arr[left], arr[j]);

    quicksort(arr, left, j - 1);
    quicksort(arr, j + 1, right);
}

int main() {
    vector<int> arr = {3, 7, 1, 2, 9, 5, 4, 8, 6};
    quicksort(arr, 0, arr.size() - 1);

    for (int i = 0; i < arr.size(); i++) {
        cout << arr[i] << " ";
    }

    return 0;
}