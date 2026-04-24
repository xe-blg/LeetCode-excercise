#include <iostream>
#include <vector>
using namespace std;

// ListNode 定义
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

// 辅助函数：创建链表
ListNode* createList(vector<int> vals) {
    ListNode* dummy = new ListNode(0);
    ListNode* cur = dummy;
    for (int val : vals) {
        cur->next = new ListNode(val);
        cur = cur->next;
    }
    return dummy->next;
}

// 辅助函数：打印链表
void printList(ListNode* head) {
    while (head) {
        cout << head->val << " -> ";
        head = head->next;
    }
    cout << "null" << endl;
}

// 辅助函数：删除链表（释放内存）
void deleteList(ListNode* head) {
    while (head) {
        ListNode* tmp = head;
        head = head->next;
        delete tmp;
    }
}

// 这里放入你的三个 Solution 类（任选一个）
class Solution1 {
public:
    ListNode* removeElements(ListNode* head, int val) {
        ListNode* dummyHead = new ListNode(0);
        dummyHead->next = head;
        ListNode* cur = dummyHead;
        while (cur->next != NULL) {
            if(cur->next->val == val) {
                ListNode* tmp = cur->next;
                cur->next = cur->next->next;
                delete tmp;
            } else {
                cur = cur->next;
            }
        }
        head = dummyHead->next;
        delete dummyHead;
        return head;
    }
};

class Solution2 {
public:
    ListNode* removeElements(ListNode* head, int val) {
        ListNode* dummyHead = new ListNode(0); // 设置一个虚拟头结点
        dummyHead->next = head; // 将虚拟头结点指向head，这样方便后面做删除操作
        ListNode* cur = dummyHead;
        while (cur->next != NULL) {
            if(cur->next->val == val) {
                ListNode* tmp = cur->next;
                cur->next = cur->next->next;
                delete tmp;
            } else {
                cur = cur->next;
            }
        }
        head = dummyHead->next;
        delete dummyHead;
        return head;
    }
};

//递归
class Solution3 {
public:
    ListNode* removeElements(ListNode* head, int val) {
        // 基础情况：空链表
        if (head == nullptr) {
            return nullptr;
        }

        // 递归处理
        if (head->val == val) {
            ListNode* newHead = removeElements(head->next, val);
            delete head;
            return newHead;
        } else {
            head->next = removeElements(head->next, val);
            return head;
        }
    }
};


// 测试
int main() {
    Solution1 solution;
    
    // 测试用例1
    vector<int> vals = {1,2,6,3,4,5,6};
    ListNode* head = createList(vals);
    cout << "原链表: ";
    printList(head);
    
    head = solution.removeElements(head, 6);
    cout << "删除6后: ";
    printList(head);
    
    deleteList(head);
    
    return 0;
}