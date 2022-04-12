/* 2.3 Delete Middle Node
 * Implement an algorithm to delete a node in the middle (i.e. any node that is not the first
 * or last) of a singly linked list, given access to only that node. Output should return nothing
 * 
 * Hints:
 * 72. picture 1->5->9->12 and you only have access to 9. Removing 9 would make it look like
 *     1->5->12
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

// we are assuming that n is not in the front or end
// will still work if it is the first node
void deleteMiddleNode(Node* n) {
    if (n == nullptr || n->next == nullptr) throw invalid_argument("Node should not be at the end of the linked list or be a nullptr");;
    Node* tmp = n->next;
    n->val = tmp->val;
    n->next = tmp->next;
    delete tmp;
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
    n = head;
    while (n) {
        if (n->val == 3) deleteMiddleNode(n);
        n = n->next;
    }
    printLL(head);

    return 0;
}
