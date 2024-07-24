#include<iostream>
using namespace std;

// Function to swap two elements
void swap(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
}

// Function to print an array
void printArray(int arr[], int size) {
    for(int i = 0; i < size; i++)
        cout << arr[i] << " ";
    cout << endl;
}

// Partition function for QuickSort
int partition(int arr[], int l, int h) {
    int pivot = arr[l];
    int i = l; 
    int j = h;

    while(i < j) {
        while(arr[i] <= pivot && i <= h-1) {
            i++;
        }
        while(arr[j] > pivot && j >= l+1) {
            j--;
        }
        if(i < j) {
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[l], arr[j]);
    return j;
}

// QuickSort function
void QuickSort(int arr[], int l, int h) {
    if(l < h) {
        int partition_index = partition(arr, l, h);
        QuickSort(arr, l, partition_index - 1);
        QuickSort(arr, partition_index + 1, h);
    }
}

int main() {
    int n;
    cout << "Enter the number of elements in the array: ";
    cin >> n;
    int arr[n];
    
    cout << "Enter the elements of the array: ";
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    cout << "Unsorted array: ";
    printArray(arr, n);

    QuickSort(arr, 0, n - 1);

    cout << "Sorted array: ";
    printArray(arr, n);

    return 0;
}
