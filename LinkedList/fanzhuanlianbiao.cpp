#include <iostream>
using namespace std;

// é“¾è¡¨èŠ‚ç‚¹å®šä¹‰
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};


class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* cur = head;
        ListNode* pre = NULL;
        ListNode* temp;
        while(cur != NULL)
        {
            temp = cur->next;
            cur->next = pre;
            pre = cur;
            cur = temp;
        }
        return pre;
    }
};

// å·¥å…·å‡½æ•°ï¼šæ‰“å°é“¾è¡?
void printList(ListNode* head) {
    ListNode* cur = head;
    while (cur != nullptr) {
        cout << cur->val << " ";
        cur = cur->next;
    }
    cout << endl;
}

// æµ‹è¯•ä¸»å‡½æ•?
int main() {
    // 1. åˆ›å»ºé“¾è¡¨ 1 -> 2 -> 3 -> 4 -> 5
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);

    cout << "²âÊÔÊä³ö";
    printList(head);

    Solution sol;
    ListNode* newHead = sol.reverseList(head);

    cout << "²âÊÔÊä³ö";
    printList(newHead);

    return 0;
}