#include<iostream>
using namespace std;
bool isSorted(int arr[], int size){
    if(size == 0 || size == 1) return true;
    if(arr[0] > arr[1]){
        return false;
    } else {
        bool remainPart = isSorted(arr + 1, size -1);
        return remainPart;
    }
}
int main(){
    int arr[] = {2,4,5,6,7,8};
    int size = 6;
    bool ans = isSorted(arr, size);
    if(ans) {
        cout<<"Array is sorted";
    } else {
        cout<<"Array is not sorted";
    }
return 0;
}