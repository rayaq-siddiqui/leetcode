/* 2.2 Return Kth to Last
 * Implement an algorithm to find the kth to last element of a singly linked list
 * 
 * Hints
 * 8. What if you knew the linked list size? What's the difference between finding
 *    the kth to last element vs the xth element
 * 25. If you do not know linkedlist size, could you compute it? How does it impact runtime
 * 41. recursion?
 * 67. might find it useful to return multiple values
 * 126. Can you do it iteravely with a lagging pointer
 */

#include <iostream>

using namespace std;

struct Node {
    int val;
    Node *next = nullptr;
};

void printLL(Node *ptr) {
    while (ptr) {
        cout << ptr->val << " ";
        ptr = ptr->next;
    }
    cout << endl;
}

Node* recursiveHelper(Node* n, int &count, const int k) {
    if (n->next) {
        Node* tmp = recursiveHelper(n->next, count, k);
        if (tmp != nullptr) return tmp;
    }
    if (count == k) return n;
    count++;
    return nullptr;
}

Node* returnKthLastRecursive(Node* head, const int k) {
    if (k < 0 || head == nullptr) return nullptr;
    int count = 0;
    return recursiveHelper(head, count, k);
}

Node* recursiveHelperAlternate(Node* n, int &count, const int k) {
    if (n == nullptr) return nullptr;
    Node* tmp = recursiveHelperAlternate(n->next, count, k);
    count++;
    return count == k ? n : tmp;
}

Node* returnKthLastRecursiveAlternate(Node* head, const int k) {
    if (k < 0 || head == nullptr) return nullptr;
    int count = 0;
    return recursiveHelperAlternate(head, count, k+1);
}

Node* returnKthLastLaggingPtr(Node* head, int k) {
    if (k < 0 || head == nullptr) return nullptr;

    int ind = 0;
    Node *tmp = head, *lagging = head;
    while (tmp->next) {
        if (ind == k) lagging = lagging->next;
        else ind++;
        tmp = tmp->next;
    }
    return ind == k ? lagging : nullptr;
}

int main() {
    Node* head = new Node();
    head->val = 5;

    Node *n = head;
    for (int i = 0; i < 10; i++) {
        Node *tmp = new Node();
        tmp->val = i;
        n->next = tmp;
        n = tmp;
    }

    printLL(head);
    for (int ind = 0; ind <= 10; ind++) {
        Node* m = returnKthLastRecursive(head, ind);
        Node* r = returnKthLastLaggingPtr(head, ind);
        Node* s = returnKthLastRecursiveAlternate(head, ind);
        cout << "returnKthLastRecursive: " << m->val << " returnKthLastLaggingPtr: " << r->val << " returnKthLastRecursiveAlternate: " << s->val << endl;
    }
    
    return 0;
}
