// #include<iostream>
// using namespace std;

// int main(){
//     int arr[] = {2,3,4,5,6,7,8,8,9};

//     cout<<"Size of single array : "<<sizeof(arr[0]) << endl;
//     cout<<"size of array : "<<sizeof(arr)<< endl;
//     int n = sizeof(arr) / sizeof(arr[0]);
//     cout<< "length of array : "<< n << endl;
// return 0;
// }

// #include<iostream>
// using namespace std;

// int main(){
//     int arr[100];
//     for(int i = 0; i < 100; i++){
//         arr[i] = {-12};
//         cout<<arr[i];
//     } 
// return 0;
// }

#include<iostream>
using namespace std;
void printArray(int arr[], int size){
    for(int i = 0; i < size; i++){
        cout<<arr[i] << endl;
    }
}
int main(){
    int arr[5] = {1,3,3,4,5};
    int n = 5;
    printArray(arr, 5);
return 0;
}