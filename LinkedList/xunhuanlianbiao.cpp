#include <iostream>
using namespace std;

// 链表节点定义
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

// 你的正确代码
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode* fast = head;
        ListNode* slow = head;
        while(fast != NULL && fast->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;
            // 快慢指针相遇，此时从head 和 相遇点，同时查找直至相遇
            if (slow == fast) {
                ListNode* index1 = fast;
                ListNode* index2 = head;
                while (index1 != index2) {
                    index1 = index1->next;
                    index2 = index2->next;
                }
                return index2; // 返回环的入口
            }
        }
        return NULL; // 无环
    }
};

// ------------------- 测试代码 -------------------
int main() {
    // 创建带环链表
    // 结构：1 -> 2 -> 3 -> 4 -> 2  (环入口是 2)
    ListNode* n1 = new ListNode(1);
    ListNode* n2 = new ListNode(2);
    ListNode* n3 = new ListNode(3);
    ListNode* n4 = new ListNode(4);

    n1->next = n2;
    n2->next = n3;
    n3->next = n4;
    n4->next = n2; // 造环：4 指向 2，环入口是 n2

    Solution sol;
    ListNode* entry = sol.detectCycle(n1);

    if (entry) {
        cout << "环的入口节点值是：" << entry->val << endl;
    } else {
        cout << "链表没有环" << endl;
    }

    return 0;
}