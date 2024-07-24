#include<iostream>
using namespace std;
int factorial(int n){
    if(n == 0)
    return 1;

    // int samllestProb = factorial(n -1);
    // int bigProb = n * samllestProb;
    // return bigProb;

    return n * factorial(n - 1);
}
int main(){
    int n ;
    cout<< "Enter the number : ";
    cin >> n;
    int ans = factorial(n);
    cout<< ans << endl;
    return 0;
}
/*
In recursion, the idea is that we represent a problem in terms of smaller problems. 
We know that 5! = 5 * 4!. Let’s assume that recursion will give us an answer of 4!. 
Now to get the solution to our problem will become 5 * (the answer of the recursive call).
 
Similarly, when we give a recursive call for 4!; recursion will give us an answer of 3!.
 Since the same work is done in all these steps we write only one function and give it a call recursively. 
 Now, what if there is no base case? Let's say 1! Will give a call to 0!; 0! will give a call to -1! (doesn’t exist) and so on.
  Soon the function call stack will be full of method calls and give an error Stack Overflow. To avoid this we need a base case.
   So in the base case, we put our own solution to one of the smaller problems.

function factorial(n)  

         //   base case

         if n equals 0

                    return 1

          //   getting answer of the smaller problem 

          recursionResult = factorial(n-1)     

          //  self work 

          ans = n * recursionResult                                   

          return ans

*/