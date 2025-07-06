#include "iostream"

using namespace std;

class Node {
public:
    int data;
    Node *next;

    Node(int value){
        data = value;
        next = nullptr;
    }

};

void insertAtStart(Node *&head, Node *&tail, int data) {
    Node *temp = new Node(data);
    if(head == nullptr) {
        head = temp; 
        tail = head;
    }else {
        temp->next = head;
        head = temp;
    }
}
void insertAtEnd(Node *&head, Node *&tail, int data) {
    Node *temp = new Node(data);
    if(head == nullptr) {
        head = temp; 
        tail = head;
    }else {
        tail->next = temp;
        tail = temp;
    }
}

void printLL(Node* head) {
    while(head != nullptr) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

void insertAtPosition(Node *&head, int pos, int data) {
    Node *temp = head;
    int currPos = 1;
    while(currPos < pos - 1) {
        temp  = temp->next;
        currPos++;
    }
    Node *node = new Node(data);
    node->next = temp->next;
    temp->next = node;
}

void deleteAtBeginning(Node *&head) {
    if(head == nullptr) {
        return;
    } else if(head->next == nullptr) {
        delete head;
        head = nullptr;
        return;
    }
    Node *temp = head;
    head = head->next;
    delete temp;
}

void deleteAtEnd(Node *&head, Node *&tail) {
    Node *temp = head;
    if(temp == nullptr) {
        return;
    } else if(head == tail) {
        delete head;
        head = nullptr;
        tail = nullptr;
        return;
    }
    while(temp->next != tail) {
        temp = temp->next;
    }
    delete tail;
    temp->next = nullptr;
    tail = temp;
}

void deleteAtPostion(Node *&head, Node *&tail, int pos) {
    Node *temp = head;
    if(temp == nullptr) {
        return;
    } else if(head == tail) {
        delete head;
        head = nullptr;
        tail = nullptr;
        return;
    }
    int currPos = 1;
    while(currPos < pos - 1) {
        temp = temp->next;
        currPos++;
    }
    Node *delNode = temp->next;
    temp->next = delNode->next;
    delete delNode;
}


int main() {
    Node *head = nullptr;
    Node *tail = nullptr;
    insertAtStart(head, tail, 3);
    insertAtStart(head, tail,  4);
    insertAtStart(head, tail, 6);
    insertAtStart(head, tail,  3);
    insertAtEnd(head, tail, 69);
    insertAtPosition(head, 2, 5000);
    insertAtEnd(head, tail, 9);
    printLL(head);
    deleteAtBeginning(head);
    printLL(head);
    deleteAtEnd(head, tail);
    printLL(head);
    deleteAtPostion(head, tail, 3);
    printLL(head);
insertAtPosition(head, 4, 1000);
    printLL(head);
    return 0;
}

