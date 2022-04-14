/* 2.4 partition
 * Write code to partition a linkedlist around a value x, such that all nodes less than x come before
 * al nodes greater or equal to x
 * IMPORTANT: the partition element x can appear anywhere in the right partition, it does not need to be 
 * between the left and right partitions
 * 
 * EX: 1 -> 5 -> 2 -> 3
 * this is one of many solutions
 * OUTPUT: 1 -> 2 ->     ->     3 -> 5, given partition=3
 * 
 * Hints:
 * 3. many solution for this problem. Some have cleaner code, some have optimal runtime. What are they
 * 24. consider that elements don't have to stay in the same relative order. we only need to ensure that
 * elements less than the pivot be before before elements greater than or equal to the pivot
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

Node* partition(Node* head, int partition) {
    if (!head) return nullptr;

    Node *lower = nullptr, *upper = nullptr, *lowertmp = nullptr, *uppertmp = nullptr, *n=head;
    bool lowerFound = false, upperFound = false;

    while(n) {
        Node *tmp = n;
        n = n->next;
        int val = tmp->val;
        if (val < partition) {
            if (!lowerFound) {
                lower = tmp;
                lowertmp = lower;
                lowerFound = true;
            }
            else {
                lowertmp->next = tmp;
                lowertmp = lowertmp->next;
            }            
        }
        if (val >= partition) {
            if (!upperFound) {
                upper = tmp;
                uppertmp = upper;
                upperFound = true;
            }
            else {
                uppertmp->next = tmp;
                uppertmp = uppertmp->next;
            }
        }
    }

    if (!lowerFound) return upper;
    else if (!upperFound) return lower;
    lowertmp->next = upper;
    return lower;
}


int main() {
    Node* head = new Node();
    head->val = 5;

    int a[10] = {0, 2, 4, 6, 8, 1, 3, 5, 7, 9};

    Node *n = head;
    for (int i = 0; i < 10; i++) {
        Node *tmp = new Node();
        tmp->val = a[i];
        n->next = tmp;
        n = tmp;
    }

    printLL(head);
    head = partition(head, 4);
    printLL(head);
    return 0;
}

