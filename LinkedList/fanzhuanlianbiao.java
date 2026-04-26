package LinkedList;

// 链表节点类
class ListNode {
    int val;
    ListNode next;
    ListNode(int val) {
        this.val = val;
    }
}

public class fanzhuanlianbiao {

    // 你写的反转链表方法（Java版）
    public ListNode reverseList(ListNode head) {
        ListNode cur = head;
        ListNode pre = null;
        ListNode temp;

        while (cur != null) {
            temp = cur.next;
            cur.next = pre;
            pre = cur;
            cur = temp;
        }
        return pre;
    }

    // ===================== 测试代码 =====================
    public static void main(String[] args) {
        // 构建链表 1 -> 2 -> 3 -> 4 -> 5
        ListNode head = new ListNode(1);
        head.next = new ListNode(2);
        head.next.next = new ListNode(3);
        head.next.next.next = new ListNode(4);
        head.next.next.next.next = new ListNode(5);

        fanzhuanlianbiao solution = new fanzhuanlianbiao();
        ListNode newHead = solution.reverseList(head);

        // 打印反转后的链表
        ListNode cur = newHead;
        while (cur != null) {
            System.out.print(cur.val + " ");
            cur = cur.next;
        }
    }
}
