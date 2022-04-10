/* 2.1 Remove Dups
 * Write code to remove duplicates from unsorted linkedlists
 * FOLLOW UP: How would you solve this problem if a temporary buffer was not allowed?
 * 
 * Hints:
 * 9. Have you tried a hashtable
 * 40. Without extra space, you'll need O(N^2) time. try using two pointers where the second one searches ahead of the first one
 */

#include <iostream>
#include <unordered_map>

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

Node *removeDups(Node *head) {
    unordered_map<int, bool> map;
    Node* n = head;
    map[n->val] = true;
    while (n->next) {
        if (map[n->next->val]) {
            Node* tmp = n->next;
            n->next = n->next->next;
            delete tmp;
        }
        else {
            map[n->next->val] = true;
            n = n->next;
        }
    }
    return head;
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
    for (int i = 0; i < 10; i++) {
        Node *tmp = new Node();
        tmp->val = i;
        n->next = tmp;
        n = tmp;
    }

    printLL(head);
    cout << "removeDups" << endl;
    head = removeDups(head);
    printLL(head);

    return 1;
}

