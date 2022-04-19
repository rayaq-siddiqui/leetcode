/* 2.6 Palindrome
 * Implement a function to check if a linkedlist is a palindrome
 * 
 * Hints
 * 5. a palindrome is something that is the same forwards and backwards. reverse linked list?
 * 13. try using a stack
 * 29. assume you have the length of the linkedlist. Can you do it recursively?
 * 61. 
 * 101. class to return multiple values
 */

#include <iostream>
#include <stack>

using namespace std;

struct Node {
    string val;
    Node *next = nullptr;
};

void printLL(Node *ptr) {
    while (ptr) {
        cout << ptr->val << " ";
        ptr = ptr->next;
    }
    cout << endl;
}

bool isPalindromeLL(Node* head) {
    stack<string> s;
    string val;

    Node *slow = head, *fast = head;
    while (fast && fast->next) {
        s.push(slow->val);
        slow = slow->next;
        fast = fast->next->next;
    }

    if (fast != nullptr) slow = slow->next;

    while (slow) {
        val = s.top();
        s.pop();

        if (val != slow->val) return false;
        slow = slow->next;
    }

    return true;
}

// assume we know the length of the linked list,
// could we do it recursively?
// this is a very long solution
// bool recurHelper(Node* n, int &mid, bool &even) {
//     if (mid > 0) {
//         mid--;
//         recurHelper(n->next, mid, even);
//     }

//     if (!even) {
//         even = false;
//     }
//     else {

//     }
// }

// bool isPalindromeLLRecur(Node* head, int length) {
//     int mid = length / 2;
//     bool even = length % 2 == 0;
//     return recurHelper(head, mid, even);
// }

struct Result {
    Node* node;
    bool result;
};

Result *createResult(Node* n, bool b) {
    Result *r = new Result();
    r->node = n;
    r->result = b;
    return r;
}

int lengthOfList(Node* n) {
    int size = 0;
    while (n) {
        size++;
        n=n->next;
    }
    return size;
}

Result *isPalindromeLLRecurse(Node* head, int length) {
    // even number of nodes
    if (!head || length <= 0) return createResult(head, true);
    // odd number of nodes
    else if (length == 1) return createResult(head->next, true);

    // recurse on sublist
    Result *res = isPalindromeLLRecurse(head->next, length - 2);

    // if the child is not a palindrome, pass back up a failure
    if (!res->result || res->node == nullptr) return res;

    // check if the value matches the node on the other side
    res->result = (head->val == res->node->val);

    // return corresponding node
    res->node = res->node->next;

    return res;
}

bool isPalindromeLLRecursive(Node* head) {
    int length = lengthOfList(head);
    Result *p = isPalindromeLLRecurse(head, length);
    return p->result;
}

int main() {
    Node* head = new Node();
    head->val = "r";

    string s = "acecar";

    Node *n = head;
    for (int i = 0; i < s.length(); i++) {
        Node *tmp = new Node();
        tmp->val = s.substr(i, 1);
        n->next = tmp;
        n = tmp;
    }

    printLL(head);
    cout << isPalindromeLL(head) << endl;
    cout << isPalindromeLLRecursive(head) << endl;

    return 0;
}

