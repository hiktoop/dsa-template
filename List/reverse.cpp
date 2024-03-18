#include <iostream>
using namespace std;

struct ListNode {
    int val; 
    ListNode *next;
    ListNode(int v): val(v), next(nullptr) { }
};

ListNode *reverse(ListNode *head) {
    ListNode *pre = nullptr, *next = nullptr;
    while(head) {
        next = head->next;
        head->next = pre;
        pre = head;
        head = next;
    }
    return pre;
}

int main() {
    ListNode *head = new ListNode(0);
    for(int i = 0; i < 10; ++i) {
        ListNode *node = new ListNode(10 - i);
        node->next = head->next;
        head->next = node;
    }

    ListNode *node = reverse(head->next);

    while(node) {
        cout << node->val << " ";
        node = node->next;
    }
    cout << endl;
    return 0;
}
