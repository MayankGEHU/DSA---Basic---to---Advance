#include<iostream>
using namespace std;

int duplicate(int arr[], int n){
    int ans = 0;
    for(int i = 0; i < n; i++){
        ans = ans ^ arr[i];
    }
    for(int i = 1; i < n; i++){
        ans = ans ^ i;
    }
    return ans;
}

int main(){
    int arr[5] = {5, 5, 3, 2, 4}; 
    int uniqueElement = duplicate(arr, 5);
    cout << "The unique element is: " << uniqueElement << endl;
    return 0;
}
