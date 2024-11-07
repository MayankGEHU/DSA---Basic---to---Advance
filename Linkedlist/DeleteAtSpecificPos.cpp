#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int data1, Node* next1 = nullptr) {
        data = data1;
        next = next1;
    }
};

Node* DeleteAtBeginning(Node* head) {
    if (head == nullptr) {
        return nullptr;
    }
    Node* temp = head;
    head = head->next;
    delete temp;
    return head;
}

Node* DeleteAtTail(Node* head) {
    if (head == nullptr || head->next == nullptr) {
        return nullptr;
    }
    Node* temp = head;
    while (temp->next->next != nullptr) {
        temp = temp->next;
    }
    delete temp->next;
    temp->next = nullptr;
    return head;
}

Node* DeleteAtSpecificPos(Node* head, int k) {
    if (head == nullptr || k <= 0) {
        return head;
    }
    if (k == 1) {
        return DeleteAtBeginning(head);
    }
    Node* temp = head;
    Node* prev = nullptr;
    int cnt = 1;
    while (temp != nullptr && cnt < k) {
        prev = temp;
        temp = temp->next;
        cnt++;
    }
    if (temp != nullptr) {
        prev->next = temp->next;
        delete temp;
    }
    return head;
}
Node* DeleteAElement(Node* head, int Ele) {
    if (head == nullptr || Ele <= 0) {
        return head; // No changes if the list is empty or invalid element
    }
    if (head->data == Ele) {
        Node* temp = head;
        head = head->next; 
        delete temp;
        return head; 
    }
    Node* temp = head;
    Node* prev = nullptr;

    while (temp != nullptr && temp->data != Ele) {
        prev = temp;
        temp = temp->next;
    }
    if (temp != nullptr) {
        prev->next = temp->next; 
        delete temp; 
    }
    return head; 
}
int main() {
    vector<int> arr = {2, 4, 5, 6};
    Node* head = new Node(arr[0]);
    Node* temp = head;
    for (int i = 1; i < arr.size(); i++) {
        temp->next = new Node(arr[i]);
        temp = temp->next;
    }
    // Delete at beginning
    // head = DeleteAtBeginning(head);
    // Delete at tail
    // head = DeleteAtTail(head);
    // Delete at specific position
    int k = 2;
    head = DeleteAtSpecificPos(head, k);
    // Print the updated linked list
    temp = head;
    while (temp != nullptr) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
    return 0;
}
