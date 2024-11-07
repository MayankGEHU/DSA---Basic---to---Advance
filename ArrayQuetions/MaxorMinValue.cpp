#include <iostream>
#include <climits> 
using namespace std;

int getMax(int arr[], int size) {
    int max = INT_MIN;
    for (int i = 0; i < size; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }
    return max;
}

int getMin(int arr[], int size) {
    int min = INT_MAX;
    for (int i = 0; i < size; i++) {
        if (arr[i] < min) {
            min = arr[i];
        }
    }
    return min;
}
KO
int main() {
    int size;
    cout << "Enter the size of array: ";
    cin >> size;

    if (size > 100) {
        cout << "Size exceeds maximum allowed size (100)." << endl;
        return 1;
    }

    int arr[100];
    for (int i = 0; i < size; i++) {
        cout << "Enter element " << i + 1 << ": ";
        cin >> arr[i];
    }

    int max = getMax(arr, size);
    int min = getMin(arr, size);

    cout << "Maximum value: " << max << endl;
    cout << "Minimum value: " << min << endl;

    return 0;
}
