/*
A stack is a container that stores elements in a last-in first-out (LIFO) order. 
They are implemented as a container adaptor, a class that uses another container class as its underlying container.
*/
//---------- complexity ---------> o(1)
#include<bits/stdc++.h>
using namespace std;
void Learnstack() {
    stack<int>st;
    st.push(2);
    st.push(4);
    st.push(5);
    st.push(7);

    cout << st.top() << endl;
    st.pop();
    cout << st.size() << endl;
    while(!st.empty()) {
        cout<<st.top() << " ";
        st.pop();
    }
    stack<int>st1, st2;
    st1.swap(st2);
}
int main(){
    Learnstack();
return 0;
}