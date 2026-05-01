#include <iostream>
using namespace std;

class MyLinkedList {
public:
    struct LinkNode
    {
        int val;
        LinkNode* next;
        LinkNode(int val)
        {
            this->val = val;
            this->next = nullptr;
        }
    };
    MyLinkedList() {
        dummyHead = new LinkNode(0);
        size = 0;
    }
    
    int get(int index) {
        if(index >= size || index < 0)
        {
            return -1;
        }
        LinkNode* cur = dummyHead->next;
        for(int i=0;i<index;i++)
        {
            cur = cur->next;
        }
        return cur->val;
    }
    
    void addAtHead(int val) {
        LinkNode* temp = new LinkNode(val);
        temp->next = dummyHead->next;
        dummyHead->next = temp;
        size++;
    }
    
    void addAtTail(int val) {
        LinkNode* temp = new LinkNode(val);
        LinkNode* cur = dummyHead;
        while(cur->next != nullptr)
        {
            cur = cur->next;
        }
        cur->next = temp;
        size++;
    }
    
    void addAtIndex(int index, int val) {
        if(index > size) return;
        if(index < 0) index = 0;       
        LinkNode* temp = new LinkNode(val);
        // 修正：cur 从 dummyHead 开始
        LinkNode* cur = dummyHead;
        for(int i=0;i<index;i++)
        {
            cur = cur->next;
        }
        temp->next = cur->next;
        cur->next = temp;
        size++;
    }
    
    void deleteAtIndex(int index) {
        if (index >= size || index < 0) {
            return;
        }
        LinkNode* cur = dummyHead;
        while(index--) {
            cur = cur->next;
        }
        LinkNode* tmp = cur->next;
        cur->next = cur->next->next;
        delete tmp;
        tmp = nullptr;
        size--;
    }

    // 辅助函数：打印链表
    void printList() {
        LinkNode* cur = dummyHead->next;
        while(cur) {
            cout << cur->val << " -> ";
            cur = cur->next;
        }
        cout << "null" << endl;
    }

private:
    int size;
    LinkNode* dummyHead;
};

// 测试用例
int main() {
    MyLinkedList* obj = new MyLinkedList();
    obj->addAtHead(1);
    obj->addAtTail(3);
    obj->addAtIndex(1, 2);  // 链表变为 1->2->3
    cout << "get(1): " << obj->get(1) << endl; // 输出 2
    obj->deleteAtIndex(1);  // 链表变为 1->3
    cout << "get(1): " << obj->get(1) << endl; // 输出 3
    obj->printList();
    delete obj;
    return 0;
}