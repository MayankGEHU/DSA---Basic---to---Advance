#include<bits/stdc++.h>
using namespace std;
void deletion() {
vector<int>v = {1,2,3,4,5,6,7,8,9,0};
v.erase(v.begin()+1); // after this operation the vector is delete 2 and it resuffeld
v.erase(v.begin()+2, v.begin()+4); //  {10 , 20 ,35, 50 , 59}  [start, end] = after operation the result is [10, 20 , 59]

// Insert function
vector<int>v1 = {2, 100}; // {100 ,100};
v1.insert(v1.begin(), 300); // {300 , 100 ,100}
v1.insert(v1.begin() + 1, 2 , 10); // {300, 10 , 10 , 100 , 100}

vector<int>copy = {2, 50}; // {50, 50}
v1.insert(v1.begin(), copy.begin(), copy.end()); // {50, 50 , 300, 10 , 10 , 100, 100}

// to get the size of vector is 
cout<< v1.size();

// to pop last element 
 v1.pop_back();

 // to erase everything to the vector
 v1.clear();

}
// ---- to swep-vector
void swep() {
 // -> v3 = {30, 40}
 // -> v2 = {10, 20}
    vector<int> v3 = {30, 40};
    vector<int> v4 = {10, 20};
    
    v3.swap(v4);
    
    // Printing v3
    cout << "v3: ";
    for(int i : v3) {
        cout << i << " ";
    }
    cout << endl;
    // Printing v4
    cout << "v4: ";
    for(int i : v4) {
        cout << i << " ";
    }

}
int main(){
    deletion();
    swep();
return 0;
}