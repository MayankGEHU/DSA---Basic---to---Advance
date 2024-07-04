/*
Maps are associative containers that store elements in a mapped fashion. Each element has a key value and a mapped value. No two mapped values can have the same key values.
map store unique key in sorted order
std::map is the class template for map containers and it is defined inside the <map> header file.

Basic std::map Member Functions
Some basic functions associated with std::map are:

begin() – Returns an iterator to the first element in the map.
end() – Returns an iterator to the theoretical element that follows the last element in the map.
size() – Returns the number of elements in the map.
max_size() – Returns the maximum number of elements that the map can hold.
empty() – Returns whether the map is empty.
pair insert(keyvalue, mapvalue) – Adds a new element to the map.
erase(iterator position) – Removes the element at the position pointed by the iterator.
erase(const g)– Removes the key-value ‘g’ from the map.
clear() – Removes all the elements from the map.
*/
#include<bits/stdc++.h>
using namespace std;
void LearnMap() {
    // 1st type declareation
    map<int, int>mpp;
    mpp[1] = 2;   // key = 1, and velur = 2; [1,2]
    mpp.insert({1,2});

    // 2nd type declareation
     map<int, pair<int, int>>m;
     m[1] = {2, 3};
     m[2] = {3, 4};
     m[3] = {2, 5};
     for(auto it : m) {
        cout<< it.first <<" "<< it.second.first << endl;
     }
   
    // map<pair<int, int> ,int>mpp;
}
void print() {
      map<string, int> mp;
 
    // Insert some values into the map
    mp["one"] = 1;
    mp["two"] = 2;
    mp["three"] = 3;
 
    // Get an iterator pointing to the first element in the
    // map
    map<string, int>::iterator it = mp.begin();
 
    // Iterate through the map and print the elements
    while (it != mp.end()) {
        cout << "Key: " << it->first
             << ", Value: " << it->second << endl;
        ++it;
    }
}
int main(){
    LearnMap();
    print();
return 0;
}