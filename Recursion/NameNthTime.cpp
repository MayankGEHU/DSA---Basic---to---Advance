#include<iostream>
using namespace std;
void PrintName(int N){
    if(N == 0) return;
    PrintName(N -1);
    cout<<"GFG"<<" ";
}
int main(){
    int N;
    cout<<"Enter the number to Print the name at the time : ";
    cin>>N;
    PrintName(N);
return 0;
}