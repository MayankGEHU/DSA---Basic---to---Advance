#include <iostream>
using namespace std;

void SwapAlternate(int arr[], int n) {
    for (int i = 0; i < n - 1; i += 2) {
       if(i < n){
         swap(arr[i], arr[i + 1]);
       }
    }
}

int main() {
    int arr[6] = {1, 2, 3, 4, 5,6};
    SwapAlternate(arr, 6);
    for (int i = 0; i < 6; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}
