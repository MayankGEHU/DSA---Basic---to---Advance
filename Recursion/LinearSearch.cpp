#include<iostream>
using namespace std;

void print(int arr[], int n){
    cout<<"Size of array is " <<n<<endl;
    for(int i = 0; i < n; i++) {
        cout<<arr[i]<< " ";
    } cout<< endl;
}
bool linearSearch(int arr[], int size, int key){
    print(arr, size);
    if(size == 0){
        return false;
    }
    if(arr[0] == key){
        return true;
    } else {
        int remainPart = linearSearch(arr+1, size-1, key);
        return remainPart;
    }
}
int main(){
    int arr[] = {3,4,5,2,7};
    int size = 5;
    int key = 0;
    bool ans = linearSearch(arr, size,key);
    if(ans){
        cout<<"Key is present in array";
    } else {
        cout<<"Key is not present in array";
    }
return 0;
}