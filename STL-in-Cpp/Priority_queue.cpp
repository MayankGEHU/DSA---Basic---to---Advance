/*
A priority queue is a type of queue that arranges elements based on their priority values. 
Elements with higher priority values are typically retrieved before elements with lower priority values.
*/

//---------- complexity ---------> push---> log(n)
//------------------------------> pop ----> log(n)
//-------------------------> top ----> o(1)
#include<bits/stdc++.h>
using namespace std;
void LearnPriority_Queue(){
    // max heap
    priority_queue<int>pq;
    pq.push(4);
    pq.push(5);
    pq.push(2);
    pq.push(7);
    pq.push(1);
    cout<< pq.top();
    pq.pop();
    // minimum Heap
    priority_queue<int, vector<int>, greater<int>>pq1;
    pq1.push(4);
    pq1.push(5);
    pq1.push(2);
    pq1.push(7);
    pq1.push(1);
    cout<< pq1.top();
    pq1.pop();
}
int main(){
    LearnPriority_Queue();
return 0;
}