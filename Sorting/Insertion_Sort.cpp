#include<iostream>
using namespace std;
void Insertion_Sort(int arr[], int n){
    for(int i = 0; i <= n - 1; i++) {
        int j = i;
        while( j > 0 && arr[j - 1] > arr[j]){
            int temp = arr[j - 1];
            arr[j - 1] = arr[j];
            arr[j] = temp;
            j--;
        }
    }
}
int main() {
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++) cin >> arr[i];
    Insertion_Sort(arr, n);
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";  
    }
    cout << endl;  
    return 0;
}
/*Approach: 

Select an element in each iteration from the unsorted array(using a loop).
Place it in its corresponding position in the sorted part and shift the remaining elements accordingly (using an inner loop and swapping).
The “inner while loop” basically shifts the elements using swapping.*/