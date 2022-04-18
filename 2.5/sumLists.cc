/* 2.5 Sum Lists
 * you have two numbers represented by linked lists, hwere each node contains a single digit
 * the digits are stored in reversed order, such tht the ones is at the head of the list
 * Write a function that adds the two functions and returns the sum as a linked list
 * You are not allowed to cheat and convert the linked list into an integer
 * 
 * Ex: (7,1,6) + (5,9,2) returns (2,1,9)
 * 
 * Hints
 * 7. do not convert to an integer as interviewer will prolly ask you to do it as a linked list
 * 30. try recursion
 * 71. make sure you have considered if linked lists are not the same length
 * 95. DOes you algorithm work for (9,7,8) + (6,8,5) ?
 * 109. for the follow up
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

Node* sumList(Node *a, Node *b, int carry=0) {
    int val, c;
    if (a && b) val = a->val + b->val;
    else if (a || b) val = a ? a->val : b->val;
    else if (carry) val = 0;
    else return nullptr;

    val += carry;
    c = val / 10;
    val = val % 10;

    Node *curr = new Node();
    curr->val = val;
    curr->next = sumList(a ? a->next : nullptr, b ? b->next : nullptr, c);
    return curr;
}

int main() {
    Node *headA = new Node(), *headB = new Node();
    headA->val = 7;
    headB->val = 5;

    int a[2] = {1,6}, b[2] = {9,2};

    Node *n = headA;
    for (int i = 0; i < 2; i++) {
        Node *tmp = new Node();
        tmp->val = a[i];
        n->next = tmp;
        n = tmp;
    }

    n = headB;
    for (int i = 0; i < 2; i++) {
        Node *tmp = new Node();
        tmp->val = b[i];
        n->next = tmp;
        n = tmp;
    }

    printLL(headA);
    printLL(headB);
    Node* sum = sumList(headA, headB);
    printLL(sum);


    // harder solution
    Node *headC = new Node(), *headD = new Node();
    headC->val = 9;
    headD->val = 6;

    int c[2] = {7,8}, d[2] = {8,5};

    n = headC;
    for (int i = 0; i < 2; i++) {
        Node *tmp = new Node();
        tmp->val = c[i];
        n->next = tmp;
        n = tmp;
    }

    n = headD;
    for (int i = 0; i < 2; i++) {
        Node *tmp = new Node();
        tmp->val = d[i];
        n->next = tmp;
        n = tmp;
    }

    printLL(headC);
    printLL(headD);
    Node* sum2 = sumList(headC, headD);
    printLL(sum2);

    return 0;
}
