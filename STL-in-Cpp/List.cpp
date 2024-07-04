#include<bits/stdc++.h>
using namespace std;
void List() {
    list<int>ls = {2,3};
    ls.push_back(2);
    ls.emplace_back(4);

    ls.push_front(4);
}

//--------------- dequeue
// simmilar as list , vector and provide same function as vector and list

void dequeue() {
    deque<int>dq = {2,3};
    dq.push_back(2);
}
int main(){
    List();
return 0;
}