struct ListNode {
    int val;
    ListNode *next;
    ListNode(int v): val(v), next(nullptr) { }
};

ListNode *findFirstCommonNode(ListNode *headA, ListNode *headB) {
    if(headA == nullptr || headB == nullptr) return nullptr;
    
    ListNode *a = headA, *b = headB;
    while(a != b) {
        a = (a == nullptr ? headB : a->next);
        b = (b == nullptr ? headB : b->next);
    }
    return a;
}
