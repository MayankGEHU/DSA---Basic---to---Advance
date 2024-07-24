#include<iostream>
using namespace std;
int fibo(int n){
    if(n == 0 || n == 1) return n;
    return fibo(n -1) + fibo (n - 2);
}
int main(){
    int n;
    cout<< "Enter the number : ";
    cin >> n;
    int result = fibo(n);
    cout<<"Fibonacci number is: " <<  result;
return 0;
}

/*
function fibonacci(n)  

         //   base case

         if n equals 1 OR 0

                    return n

          //   getting answer of the smaller problem 

          recursionResult1 = fibonacci(n - 1)     

          recursionResult2 = fibonacci(n - 2)    

          //  self work 

          ans = recursionResult1 + recursionResult2                                   

          return ans

*/