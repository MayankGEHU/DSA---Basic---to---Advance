#include<iostream>
using namespace std;

bool BinarySearch(int arr[], int s, int e, int key) {
    if (s > e) {
        return false;
    }
    int mid = s + (e - s) / 2;
    if (arr[mid] == key) {
        return true;
    }
    if (arr[mid] > key) {
        return BinarySearch(arr, s, mid - 1, key);
    } else {
        return BinarySearch(arr, mid + 1, e, key);
    }
}

int main() {
    int arr[] = {2, 3, 4, 5, 6, 7};
    int size = 6;
    int key = 4;
    cout << "Key is Present or not : " << BinarySearch(arr, 0, size - 1, key) << endl;
    return 0;
}
