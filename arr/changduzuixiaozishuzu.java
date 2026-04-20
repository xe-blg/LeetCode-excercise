public class changduzuixiaozishuzu {
    public static void main(String[] args) {
        Solutionzuixiaozishuzu solution = new Solutionzuixiaozishuzu();

        // 测试用例 1
        int[] nums1 = {2,3,1,2,4,3};
        int target1 = 7;
        System.out.println("测试用例1结果：" + solution.minSubArrayLen(target1, nums1)); // 预期 2

        // 测试用例 2
        int[] nums2 = {1,4,4};
        int target2 = 4;
        System.out.println("测试用例2结果：" + solution.minSubArrayLen(target2, nums2)); // 预期 1

        // 测试用例 3
        int[] nums3 = {1,1,1,1,1};
        int target3 = 11;
        System.out.println("测试用例3结果：" + solution.minSubArrayLen(target3, nums3)); // 预期 0
    }
}

class Solutionzuixiaozishuzu {

    // 滑动窗口（标准最优解）
    public int minSubArrayLen(int s, int[] nums) {
        int left = 0;
        int sum = 0;
        int result = Integer.MAX_VALUE;

        for (int right = 0; right < nums.length; right++) {
            sum += nums[right];

            // 当和满足条件，尝试缩小窗口
            while (sum >= s) {
                result = Math.min(result, right - left + 1);
                sum -= nums[left];
                left++;
            }
        }

        // 如果没找到，返回 0
        return result == Integer.MAX_VALUE ? 0 : result;
    }
}