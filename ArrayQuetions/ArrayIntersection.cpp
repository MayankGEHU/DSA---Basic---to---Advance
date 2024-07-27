#include <iostream>
#include <vector>
using namespace std;

vector<int> ArrayIntersection(int arr1[], int arr2[], int n, int m) {
    vector<int> ans;
    int i = 0, j = 0;
    while (i < n && j < m) {
        if (arr1[i] == arr2[j]) {
            ans.push_back(arr1[i]);
            i++;
            j++;
        } else if (arr1[i] < arr2[j]) {
            i++;
        } else {
            j++;
        }
    }
    return ans;
}

int main() {
    int arr1[3] = {2, 3, 4};
    int arr2[5] = {2, 3, 4, 5, 6};
    vector<int> result = ArrayIntersection(arr1, arr2, 3, 5);
    
    cout << "Intersection of arrays: ";
    for (int val : result) {
        cout << val << " ";
    }
    cout << endl;

    return 0;
}
