/*
An iterator is an object (like a pointer) that points to an element inside the container. We can use iterators to move through the contents of the container. They can be visualised as something similar to a pointer pointing to some location and we can access content at that particular location using them.
*/
// iterator point to the memory where element is lie
#include<bits/stdc++.h>
using namespace std;
void iteratorExplain() {
    vector<int>v = {1,2,3,4,5,6,8,7};
    vector<int>::iterator it = v.begin();
    it++;
    cout << *(it) << " "; // the moment you give * then the element under the memory is exces 

    it = it + 2; // it mean shifted by two position
    cout << *(it) << " ";
    vector<int>v1 = {2,3,4,5,6,7,8,9};
    vector<int>:: iterator it1 = v1.end(); // end will point after 9 , it not point to 9 if you want to point 9 then you took it-- then it point to the 9
    vector<int>:: reverse_iterator it2 = v1.rend();
    vector<int>:: reverse_iterator it3 = v1.rbegin();
    cout<< v1[0] << " " << v1.at(0)<< " "; 
    cout << v1.back();


    for(vector<int>::iterator it = v1.begin(); it != v1.end(); it++) {
        cout<< *(it) << " ";
    } cout << endl;// ---------------- or you can wirte below auto autometcilly assigne the data type no need to define
    // auto a = 5;   computer automatically says a is integers
    for(auto it = v1.begin(); it != v1.end(); it++) {
        cout<< *(it) << " " ;
    } cout << endl;
    for(auto it : v) {
        cout << it << " ";
    } 
}
int main (){
    iteratorExplain();
    return 0;
}