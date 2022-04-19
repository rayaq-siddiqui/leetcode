/* 2.8 Loop Detection
 * Given a linkedlist which might contain a loop, implement an algorithm that returns the node 
 * at the beginning of the loop
 * 
 * Hints
 * 50. 
 * 69. 
 * 83. 
 * 90. 
 */

#include <iostream>
#include <unordered_set>

using namespace std;

struct Node {
    int val;
    Node *next = nullptr;
};

void printLL(Node *ptr) {
    int i = 0;
    while (ptr && i++ < 25) {
        cout << ptr->val << " ";
        ptr = ptr->next;
    }
    cout << endl;
}

bool isLoop(Node* head) {
    Node *slow = head, *fast = head;

    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast) return true;
    }

    return false;
}

Node* loopDetection(Node* head) {
    // if (!isLoop(head)) return nullptr;
    unordered_set<Node*> s;

    Node* n = head;
    bool found = false;
    while (n && !found) {
        if (s.find(n) == s.end()) {
            s.insert(n);
            n=n->next;
        }
        else found = true;
    }
    return n;
}

int main() {
    Node* head = new Node();
    head->val = 5;

    Node *n = head, *hold, *tmp;
    for (int i = 0; i < 10; i++) {
        tmp = new Node();
        tmp->val = i;
        n->next = tmp;
        n = tmp;

        if (i == 7) { 
            hold = tmp; 
            cout << "Answer: " << hold << " " << hold->val << endl; 
        }
    }

    printLL(head);
    cout << "No Loop: " << loopDetection(head) << endl;

    n->next = hold;
    printLL(head);
    Node *loop = loopDetection(head);
    cout << "Loop Detected: " << loop << " " << loop->val << endl;
    return 0;
}

