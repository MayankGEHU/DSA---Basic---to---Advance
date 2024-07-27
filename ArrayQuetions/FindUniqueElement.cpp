#include<iostream>
using namespace std;

int FindUnique(int arr[], int size) {
    int ans = 0;
    for(int i = 0; i < size; i++) {
        ans = ans ^ arr[i];
    }
    return ans;
}
int main() {
    int arr[5] = {1, 2, 1, 2, 4};
    int uniqueElement = FindUnique(arr, 5);
    cout << "The unique element is: " << uniqueElement << endl;
    return 0;
}
