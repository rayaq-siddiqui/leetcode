#include <iostream>

using namespace std;

struct Node {
    int val;
    Node *next = nullptr;
};

void printLL(Node *ptr) {
    while (ptr) {
        cout << ptr->val << endl;
        ptr = ptr->next;
    }
}

void appendToTail(Node *ptr, int val) {
    Node* n = new Node();
    n->val = val;

    while (ptr->next) ptr = ptr->next;
    ptr->next = n;
}

// partially implemented runner technique
Node *deleteNode(Node *head, int d) {
    if (head == nullptr) return nullptr;
    Node *n = head;

    if (n->val == d) return n->next;
    while (n->next) {
        if (n->next->val == d) {
            Node* tmp = n->next;
            n->next = n->next->next;
            delete tmp;
            return head;
        }
        n = n->next;
    }
    return head;
}
