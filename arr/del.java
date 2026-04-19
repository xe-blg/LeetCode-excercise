class Solutiondel {
    // 暴力法
    public int removeElement(int[] nums, int val) {
        int n = nums.length;
        for (int i = 0; i < n; i++) {
            if (nums[i] == val) {
                for (int j = i + 1; j < n; j++) {
                    nums[j - 1] = nums[j];
                }
                i--;
                n--;
            }
        }
        return n;
    }

    // 快慢指针
    public int removeElement2(int[] nums, int val) {
        int slowIndex = 0;
        for (int fastIndex = 0; fastIndex < nums.length; fastIndex++) {
            if (nums[fastIndex] != val) {
                nums[slowIndex] = nums[fastIndex];
                slowIndex++;
            }
        }
        return slowIndex;
    }
}

// 这个必须是 public，因为你的文件名是 del.java
public class del {
    public static void main(String[] args) {
        Solutiondel solution = new Solutiondel();

        // 测试用例 1
        int[] nums1 = {3, 2, 2, 3};
        int val1 = 3;
        int len1 = solution.removeElement(nums1, val1);
        System.out.println("测试1 新长度：" + len1);
        System.out.print("新数组：");
        for (int i = 0; i < len1; i++) {
            System.out.print(nums1[i] + " ");
        }
        System.out.println("\n-------------------");

        // 测试用例 2
        int[] nums2 = {0,1,2,2,3,0,4,2};
        int val2 = 2;
        int len2 = solution.removeElement(nums2, val2);
        System.out.println("测试2 新长度：" + len2);
        System.out.print("新数组：");
        for (int i = 0; i < len2; i++) {
            System.out.print(nums2[i] + " ");
        }
    }
}