/*
Any function which calls itself is called recursion. A recursive method solves a problem by calling a copy of 
itself to work on a smaller problem. Each time a function calls itself with a slightly simpler version of the original problem.
 This sequence of smaller problems must eventually converge on a base case.
 */
/*

Working of recursion

 

We can define the steps of the recursive approach by summarizing the above three steps:

Base case: A recursive function must have a terminating condition at which the process will stop calling itself. 
Such a case is known as the base case. In the absence of a base case, it will keep calling itself and get stuck in an 
infinite loop. Soon, the recursion depth* will be exceeded and it will throw an error.
Recursive call (Smaller problem): The recursive function will invoke itself on a smaller version of the main problem. 
We need to be careful while writing this step as it is crucial to correctly figure out what your smaller problem is.
Self-work : Generally, we perform a calculation step in each recursive call. We can achieve this calculation step before 
or after the recursive call depending upon the nature of the problem.

*/
/*

Note*: Recursion uses an in-built stack that stores recursive calls. 
Hence, the number of recursive calls must be as small as possible to avoid memory-overflow.
 If the number of recursion calls exceeded the maximum permissible amount, the recursion depth* will be exceeded. 
 This condition is called stack overflow.

*/