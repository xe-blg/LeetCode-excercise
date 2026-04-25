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
        if(index>(size-1) || index<0)
        {
            return -1;
        }
        LinkNode* cur = dummyHead->next;
        for(int i=0;i<index;i++)
        {
            cur=cur->next;
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
        LinkNode*temp = new LinkNode(val);
        LinkNode* cur = dummyHead;
        while(cur->next != nullptr)
        {
            cur = cur ->next;
        }
        cur->next = temp;
        size++;
    }
    
    void addAtIndex(int index, int val) {
        if(index > size) return;
        if(index < 0) index = 0;       
        LinkNode*temp = new LinkNode(val);
        LinkNode* cur = dummyHead->next;
        if(index == 0)
        {
            temp->next = dummyHead->next;
            dummyHead->next = temp;
        }
        else
        {
            for(int i=0;i<index-1;i++)
            {
                cur = cur->next;
            }
            temp->next = cur->next;
            cur->next = temp;
        }
        
        size++;
    }
    
    void deleteAtIndex(int index) {
        if (index >= size || index < 0) {
            return;
        }
        LinkNode* cur = dummyHead;
        while(index--) {
            cur = cur ->next;
        }
        LinkNode* tmp = cur->next;
        cur->next = cur->next->next;
        delete tmp;
        
        tmp=nullptr;
        size--;
    }

    private:
    int size;
    LinkNode* dummyHead;
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */