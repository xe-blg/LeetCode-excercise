package LinkedList;

public class delLinkedList {
    
    // 链表节点定义
    static class ListNode {
        int val;
        ListNode next;
        ListNode() {}
        ListNode(int val) { this.val = val; }
        ListNode(int val, ListNode next) { this.val = val; this.next = next; }
    }
    
    // 链表类（独立管理链表）
    static class LinkedList {
        private ListNode head;
        
        // 构造函数
        public LinkedList() {
            this.head = null;
        }
        
        // 通过数组创建链表
        public LinkedList(int[] values) {
            if (values == null || values.length == 0) {
                this.head = null;
                return;
            }
            
            this.head = new ListNode(values[0]);
            ListNode current = this.head;
            for (int i = 1; i < values.length; i++) {
                current.next = new ListNode(values[i]);
                current = current.next;
            }
        }
        
        // 添加元素到末尾
        public void add(int val) {
            ListNode newNode = new ListNode(val);
            if (head == null) {
                head = newNode;
                return;
            }
            
            ListNode current = head;
            while (current.next != null) {
                current = current.next;
            }
            current.next = newNode;
        }
        
        // 在指定位置插入元素（索引从0开始）
        public void add(int index, int val) {
            if (index < 0) return;
            
            ListNode newNode = new ListNode(val);
            
            if (index == 0) {
                newNode.next = head;
                head = newNode;
                return;
            }
            
            ListNode current = head;
            for (int i = 0; i < index - 1 && current != null; i++) {
                current = current.next;
            }
            
            if (current != null) {
                newNode.next = current.next;
                current.next = newNode;
            }
        }
        
        // 删除指定值的第一个节点
        public boolean remove(int val) {
            if (head == null) return false;
            
            if (head.val == val) {
                head = head.next;
                return true;
            }
            
            ListNode current = head;
            while (current.next != null && current.next.val != val) {
                current = current.next;
            }
            
            if (current.next != null) {
                current.next = current.next.next;
                return true;
            }
            return false;
        }
        
        // 获取链表头节点
        public ListNode getHead() {
            return head;
        }
        
        // 设置链表头节点
        public void setHead(ListNode head) {
            this.head = head;
        }
        
        // 获取链表长度
        public int size() {
            int count = 0;
            ListNode current = head;
            while (current != null) {
                count++;
                current = current.next;
            }
            return count;
        }
        
        // 获取指定位置的元素
        public Integer get(int index) {
            if (index < 0) return null;
            
            ListNode current = head;
            for (int i = 0; i < index && current != null; i++) {
                current = current.next;
            }
            
            return current != null ? current.val : null;
        }
        
        // 判断是否包含某个值
        public boolean contains(int val) {
            ListNode current = head;
            while (current != null) {
                if (current.val == val) return true;
                current = current.next;
            }
            return false;
        }
        
        // 清空链表
        public void clear() {
            head = null;
        }
        
        // 判断链表是否为空
        public boolean isEmpty() {
            return head == null;
        }
        
        // 打印链表
        public void print() {
            ListNode current = head;
            while (current != null) {
                System.out.print(current.val);
                if (current.next != null) {
                    System.out.print(" -> ");
                }
                current = current.next;
            }
            System.out.println(" -> null");
        }
        
        // 将链表转换为数组
        public int[] toArray() {
            int[] result = new int[size()];
            ListNode current = head;
            int index = 0;
            while (current != null) {
                result[index++] = current.val;
                current = current.next;
            }
            return result;
        }
    }

    // 解决方案类
    static class Solution {
        public ListNode removeElements(ListNode head, int val) {
            while(head != null && head.val == val)
            {
                ListNode temp = head; 
                head = head.next;
                temp.next = null;
            }

            ListNode cur = head;
            while(cur != null && cur.next != null)
            {
                if(cur.next.val == val)
                {
                    ListNode temp = cur.next;
                    cur.next = cur.next.next;
                    temp.next = null; 
                }
                else
                {
                    cur = cur.next;
                }
            }
            return head;
        }
    }

    // 辅助方法：打印链表（兼容原有接口）
    public static void printList(ListNode head) {
        ListNode cur = head;
        while (cur != null) {
            System.out.print(cur.val);
            if (cur.next != null) {
                System.out.print(" -> ");
            }
            cur = cur.next;
        }
        System.out.println(" -> null");
    }

    public static void main(String[] args) {
        // 使用 LinkedList 类创建链表
        System.out.println("=== 方式1：通过数组创建链表 ===");
        LinkedList list1 = new LinkedList(new int[]{1, 2, 6, 3, 4, 5, 6});
        System.out.print("原链表: ");
        list1.print();
        
        Solution solution = new Solution();
        ListNode result = solution.removeElements(list1.getHead(), 6);
        
        System.out.print("删除后: ");
        printList(result);
        
        System.out.println("\n=== 方式2：动态添加元素 ===");
        LinkedList list2 = new LinkedList();
        list2.add(1);
        list2.add(2);
        list2.add(6);
        list2.add(3);
        list2.add(4);
        list2.add(5);
        list2.add(6);
        System.out.print("原链表: ");
        list2.print();
        System.out.println("链表长度: " + list2.size());
        System.out.println("包含6吗? " + list2.contains(6));
        
        ListNode result2 = solution.removeElements(list2.getHead(), 6);
        System.out.print("删除后: ");
        printList(result2);
        
        System.out.println("\n=== 方式3：使用链表类的删除方法（对比） ===");
        LinkedList list3 = new LinkedList(new int[]{1, 2, 6, 3, 4, 5, 6});
        System.out.print("原链表: ");
        list3.print();
        list3.remove(6); // 只删除第一个6
        System.out.print("删除第一个6后: ");
        list3.print();
    }
}