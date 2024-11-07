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

Node* InsertAtHead(Node* head, int val) {
    Node* temp = new Node(val, head);
    return temp;
}


Node* InsertAtEnd(Node* head, int val) {
    Node* newNode = new Node(val);
    if (head == nullptr) {
        return newNode;
    }
    Node* temp = head;
    while (temp->next != nullptr) {
        temp = temp->next;
    }
    temp->next = newNode;
    return head;
}

Node* InsertAtSpecificPos(Node* head, int ele, int k){
    if(head == NULL){
        if(k == 1){
            Node* newNode = new Node(ele);
            return newNode;
        } else {
           return head;
        }
    }
    if(k == 1){
        Node* temp = new Node(ele,head);
        return temp;
    }
    int cnt = 0;
    Node* temp = head;
    while(temp != NULL){
        cnt++;
        if(cnt == k - 1){
            Node* newNode = new Node(ele, temp -> next);
            newNode -> next = newNode;
            break;
        } else {
            temp = temp -> next;
        }
    }
    return head;
}

// SinglyLinkedListNode* insertNodeAtPosition(SinglyLinkedListNode* llist, int data, int position) {

//     // Create a new node with the given data
//     SinglyLinkedListNode* newNode = new SinglyLinkedListNode(data);

//     // If inserting at the head of the list
//     if (position == 0) {
//         newNode->next = llist;
//         return newNode;
//     }

//     int cnt = 0;
//     SinglyLinkedListNode* temp = llist;

//     // Traverse the list to find the node just before the position
//     while (temp != NULL && cnt < position - 1) {
//         cnt++;
//         temp = temp->next;
//     }

//     if (temp == NULL) {
//         // Position is out of bounds, return the original list
//         return llist;
//     }

//     // Insert the new node at the desired position
//     newNode->next = temp->next;
//     temp->next = newNode;

//     return llist;
// }



void printList(Node* node) {
    while (node != nullptr) {
        cout << node->data << " ";
        node = node->next;
    }
    cout << endl;
}

int main() {
    Node* head = nullptr;
    int n;
    cout << "Enter the number of elements to insert into the list initially: ";
    cin >> n;
    for (int i = 0; i < n; i++) {
        int value;
        cout << "Enter value " << (i + 1) << ": ";
        cin >> value;
        head = InsertAtEnd(head, value);
    }
    int lastElement;
    cout << "Enter the last element to insert at the end of the list: ";
    cin >> lastElement;
    head = InsertAtEnd(head, lastElement);
    cout << "The final linked list is: ";
    printList(head);

    return 0;
}
