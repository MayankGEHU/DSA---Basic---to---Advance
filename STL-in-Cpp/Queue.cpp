/*
Queues are a type of container adaptors that operate in a first in first out (FIFO) type of arrangement. 
Elements are inserted at the back (end) and are deleted from the front. Queues use an encapsulated object of deque or list 
(sequential container class) as its underlying container, providing a specific set of member functions to access its elements.
*/
//---------- complexity ---------> o(1)
#include<bits/stdc++.h>
using namespace std;
void LearnQueue(){
    queue<int>q;
    q.push(2);
    q.push(4);
    q.push(6);
    q.push(5);

    while(!q.empty()){
        cout<< q.front() <<" ";
        q.pop();
    }
}
int main(){
    LearnQueue();
return 0;
}