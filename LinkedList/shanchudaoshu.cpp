#include <iostream>
using namespace std;

// 链表节点定义
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

// 你的正确代码
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* dummyHead = new ListNode(0);
        dummyHead->next = head;
        ListNode* fast;
        ListNode *slow;
        fast = dummyHead;
        slow = dummyHead;

        for(int i=0;i<n;i++)
        {
            fast=fast->next;
        }

        fast = fast->next;

        while(fast != NULL)
        {
            fast=fast->next;
            slow=slow->next;
        }

        slow->next=slow->next->next;
        return dummyHead->next;
    }
};

// 辅助函数：打印链表
void printList(ListNode* head) {
    ListNode* cur = head;
    while (cur != nullptr) {
        cout << cur->val << " ";
        cur = cur->next;
    }
    cout << endl;
}

// 主函数测试
int main() {
    // 构建测试链表 1 -> 2 -> 3 -> 4 -> 5
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);

    cout << "原链表：";
    printList(head);

    // 删除倒数第 2 个节点（4）
    Solution sol;
    ListNode* newHead = sol.removeNthFromEnd(head, 2);

    cout << "删除后：";
    printList(newHead);

    return 0;
}