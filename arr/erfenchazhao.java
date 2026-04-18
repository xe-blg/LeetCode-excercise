// 给定一个 n 个元素有序的（升序）整型数组 nums 和一个目标值 target  ，写一个函数搜索 nums 中的 target，如果 target 存在返回下标，否则返回 -1。

// 你必须编写一个具有 O(log n) 时间复杂度的算法。


// 示例 1:

// 输入: nums = [-1,0,3,5,9,12], target = 9
// 输出: 4
// 解释: 9 出现在 nums 中并且下标为 4
// 示例 2:

// 输入: nums = [-1,0,3,5,9,12], target = 2
// 输出: -1
// 解释: 2 不存在 nums 中因此返回 -1 {

public class erfenchazhao {
    public static void main(String[] args) {
        Solution solution = new Solution();

        // 有序数组（二分查找必须有序）
        int[] nums = {-1, 0, 3, 5, 9, 12};

        // 测试 1：目标存在 9 → 下标 4
        int target1 = 9;
        System.out.println("查找 " + target1 + "，下标：" + solution.search(nums, target1));

        // 测试 2：目标存在 12 → 下标 5
        int target2 = 12;
        System.out.println("查找 " + target2 + "，下标：" + solution.search(nums, target2));

        // 测试 3：目标不存在 2 → 返回 -1
        int target3 = 2;
        System.out.println("查找 " + target3 + "，下标：" + solution.search(nums, target3));

        // 测试 4：超出范围 15 → 直接返回 -1（你代码里的优化）
        int target4 = 15;
        System.out.println("查找 " + target4 + "，下标：" + solution.search(nums, target4));
    }
}

// 你原来的代码不动
class Solution {
    public int search(int[] nums, int target) {
        // 避免当 target 小于nums[0] nums[nums.length - 1]时多次循环运算
        if (target < nums[0] || target > nums[nums.length - 1]) {
            return -1;
        }
        int left = 0, right = nums.length - 1;
        while (left <= right) {
            int mid = left + ((right - left) >> 1);
            if (nums[mid] == target) {
                return mid;
            }
            else if (nums[mid] < target) {
                left = mid + 1;
            }
            else { // nums[mid] > target
                right = mid - 1;
            }
        }
        // 未找到目标值
        return -1;
    }
}
    

