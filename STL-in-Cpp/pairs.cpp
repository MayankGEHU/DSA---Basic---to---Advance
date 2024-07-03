#include<bits/stdc++.h>
using namespace std;

void explaiPairs() {
    pair<int,int>p = {1 , 3};
    cout<<p.first << " " << p.second << endl;

    pair<int , pair<int, int>> M = {1, {2,3}};
    cout<<M.first << " " << M.second.second << M.second.first << endl;

    pair<int, int> arr[] = { {1,2}, {3,5}, {5,6}};
    cout<< arr[1].second;
}
int main(){
    explaiPairs();
    return 0;
}