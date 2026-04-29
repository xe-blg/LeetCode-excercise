package LinkedList;

class ListNode1 {
    int val;
    ListNode1 next;
    ListNode1() {}
    ListNode1(int val) { this.val = val; }
    ListNode1(int val, ListNode1 next) {
        this.val = val;
        this.next = next;
    }
}

public class shanchudaoshi {
    // 和你C++完全一致的快慢指针逻辑
    public ListNode1 removeNthFromEnd(ListNode1 head, int n) {
        ListNode1 dummyHead = new ListNode1(0);
        dummyHead.next = head;
        ListNode1 fast = dummyHead;
        ListNode1 slow = dummyHead;

        // fast 先走 n 步
        for (int i = 0; i < n; i++) {
            fast = fast.next;
        }

        // 再多走一步（和你C++代码完全对应）
        fast = fast.next;

        // 快慢一起走
        while (fast != null) {
            fast = fast.next;
            slow = slow.next;
        }

        // 删除目标节点
        slow.next = slow.next.next;
        return dummyHead.next;
    }

    // 测试打印链表
    public void printList(ListNode1 head) {
        ListNode1 cur = head;
        while (cur != null) {
            System.out.print(cur.val + " ");
            cur = cur.next;
        }
        System.out.println();
    }

    // 主方法测试
    public static void main(String[] args) {
        // 构造链表 1->2->3->4->5
        ListNode1 head = new ListNode1(1);
        head.next = new ListNode1(2);
        head.next.next = new ListNode1(3);
        head.next.next.next = new ListNode1(4);
        head.next.next.next.next = new ListNode1(5);

        shanchudaoshi solu = new shanchudaoshi();
        System.out.print("原链表：");
        solu.printList(head);

        // 删除倒数第2个
        ListNode1 newHead = solu.removeNthFromEnd(head, 2);
        System.out.print("删除后：");
        solu.printList(newHead);
    }
}
