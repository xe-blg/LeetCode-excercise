package LinkedList;

public class liangliangjiaohuan {

    // 链表节点类（内部类）
    static class ListNode {
        int val;
        ListNode next;
        ListNode(int val) {
            this.val = val;
        }
    }

    // 交换算法（内部类）
    static class Soulutionjiaohuan {
        public ListNode swapPairs(ListNode head) {
            ListNode dummyHead = new ListNode(0);
            dummyHead.next = head;
            ListNode cur = dummyHead;
            ListNode temp;
            ListNode firstnode;
            ListNode secondnode;

            while(cur.next != null && cur.next.next != null) {
                temp = cur.next.next.next;
                firstnode = cur.next;
                secondnode = cur.next.next;

                cur.next = secondnode;       
                secondnode.next = firstnode; 
                firstnode.next = temp;      
                cur = firstnode; 
            }
            return dummyHead.next;  
        }
    }

    // 测试主方法
    public static void main(String[] args) {
        // 构建测试链表 1 -> 2 -> 3 -> 4
        ListNode head = new ListNode(1);
        head.next = new ListNode(2);
        head.next.next = new ListNode(3);
        head.next.next.next = new ListNode(4);

        // 调用交换方法
        Soulutionjiaohuan solution = new Soulutionjiaohuan();
        ListNode newHead = solution.swapPairs(head);

        // 打印结果
        ListNode cur = newHead;
        while (cur != null) {
            System.out.print(cur.val + " ");
            cur = cur.next;
        }
    }
}