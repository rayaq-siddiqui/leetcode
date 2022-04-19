/* 2.7 Intersection
 * Given 2 singly LL, determine if the two lists intersect. Return the intersecting node
 * 
 * Hints
 * 20. You can do this in O(A+B) with O(1) additional space. This means no hashtable
 * 45. examples will help you
 * 55. focus first on identifyig if there is an intersection
 * 65. observe that intersecting linked lists will always have the same last node
 * 76. depth first traversal
 * 93. need to find where the linked lists intersect
 * 111. if they were the same length, how could you adjust this
 * 120. try using the difference between both linked list length
 * 129. if you know the difference between the lengths of both of the lists, could you adjust  the list 
 * to make this difference
 */

#include <iostream>
#include <unordered_set>

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

// s.find(element) has complexity of O(1) since it is an unordered_set
// while loop has a complexity of O(N)
// overall complexity is O(N)
Node* intersection(Node* n1, Node* n2) {
    unordered_set<Node*> s;

    Node* tmp = n1;
    while (tmp) {
        s.insert(tmp);
        tmp = tmp->next;
    }

    tmp = n2;
    while (tmp) {
        bool contains = s.find(tmp) != s.end();
        if (contains) return tmp;
        tmp = tmp->next;
    }

    return nullptr;
}

Node* intersectionRecursive(Node* n1, Node* n2) {
    Node* n;
    if (n1->next && n2->next) n = intersectionRecursive(n1->next, n2->next);
    else if (n1->next || n2->next) n = intersectionRecursive(n1->next ? n1->next : n1, n2->next ? n2->next : n2);
    else n = nullptr;

    if (n1 == n2) n = n1;
    return n;
}

int main() {
    Node* head = new Node(), *tmp;
    head->val = 5;

    Node *n = head;
    for (int i = 0; i < 10; i++) {
        tmp = new Node();
        tmp->val = i;
        n->next = tmp;
        n = tmp;
    }

    Node* head2 = new Node();
    head2->val = 5;

    n = head2;
    for (int i = 0; i < 10; i++) {
        tmp = new Node();
        tmp->val = i;
        n->next = tmp;
        n = tmp;
    }
    

    printLL(head);
    printLL(head2);
    cout << intersection(head, head2) << " " << intersectionRecursive(head, head2) << endl;

    n->next = head;
    printLL(head);
    printLL(head2);
    cout << intersection(head, head2) << " " << intersectionRecursive(head, head2) << endl;

    return 0;
}

