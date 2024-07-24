#include<iostream>
using namespace std;
int power(int n ) {
    if(n == 0) return 1;

    int smallestProb = power(n - 1);
    int bigProb = 2* smallestProb;
    return bigProb;

    // return 2* power(n - 1);
}
int main(){
    int n ;
    cout<<"Enter the number : ";
    cin>> n;
    int ans = power(n);
    cout<< ans << endl;
}