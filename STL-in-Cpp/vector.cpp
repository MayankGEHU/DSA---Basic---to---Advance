#include<bits/stdc++.h>
using namespace std;
void vectorexplain() {
    vector<int>v;  // create a empty container 
    v.push_back(1);  // push 1 in the vector 
    v.emplace_back(2);   // it dinamically increase the size of vector and push the 2 it is simmilar to the push_back but it is fast then push_back
    cout<< v[0] << " " << v[1];

    vector<pair<int , int>>vec;
    vec.push_back({1,3});
    vec.emplace_back(1,5);

    vector<int> v1(5, 100);  // {100, 100, 100, 100, 100}   first value is the size of container. A container content 100 , 5 times
    vector<int> v2 (5);  // it create with garbage value

}
int main() {
    vectorexplain();
    return 0;
}