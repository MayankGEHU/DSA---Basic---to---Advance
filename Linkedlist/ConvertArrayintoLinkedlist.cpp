#include<bits/stdc++.h>
using namespace std;

class Node {
    public:
    int data;
    Node* next;

    public:
    // Constructor to initialize data and next
    Node(int data1, Node* next1 = nullptr) {
        data = data1;
        next = next1;
    }
};

int main() {
    vector<int> arr = {2, 4, 5, 6};
    Node* y = new Node(arr[0]);
    cout << y->data;
    return 0;
}
