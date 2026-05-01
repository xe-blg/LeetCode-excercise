#include <iostream>
using namespace std;

// 定义链表节点
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode* curA = headA;
        ListNode* curB = headB;
        int lenA = 0, lenB = 0;

        // 求链表A的长度
        while (curA != NULL) {
            lenA++;
            curA = curA->next;
        }

        // 求链表B的长度
        while (curB != NULL) {
            lenB++;
            curB = curB->next;
        }

        // 重置指针到头部
        curA = headA;
        curB = headB;

        // 让curA指向更长的链表，lenA存其长度
        if (lenB > lenA) {
            swap(lenA, lenB);
            swap(curA, curB);
        }

        // 计算长度差
        int gap = lenA - lenB;
        // 长链表先走gap步，对齐末尾
        while (gap--) {
            curA = curA->next;
        }

        // 同时遍历两个链表，找交点
        while (curA != NULL) {
            if (curA == curB) {
                return curA;
            }
            curA = curA->next;
            curB = curB->next;
        }

        return NULL;
    }
};

// 主函数
int main() {
    // 创建测试用例
    ListNode* common = new ListNode(8);
    common->next = new ListNode(4);
    common->next->next = new ListNode(5);

    ListNode* headA = new ListNode(4);
    headA->next = new ListNode(1);
    headA->next->next = common;

    ListNode* headB = new ListNode(5);
    headB->next = new ListNode(6);
    headB->next->next = new ListNode(1);
    headB->next->next->next = common;

    Solution sol;
    ListNode* res = sol.getIntersectionNode(headA, headB);
    
    // 这里中文现在永久正常！
    if (res) {
        cout << "相交节点的值为：" << res->val << endl;
    } else {
        cout << "两个链表不相交" << endl;
    }

    return 0;
}