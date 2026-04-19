import java.util.Arrays;  


public class pingfangpaixu {

    // 主函数：程序入口
    public static void main(String[] args) {
        Solutionpfpx solution = new Solutionpfpx();

        // 测试用例
        int[] nums = {-4, -1, 0, 3, 10};

        // 方法1：暴力平方 + 排序
        int[] res1 = solution.sortedSquares(nums.clone()); // 用clone避免原数组被修改
        System.out.println("方法1（平方+排序）：" + Arrays.toString(res1));

        // 方法2：双指针最优解法
        int[] res2 = solution.sortedSquares2(nums);
        System.out.println("方法2（双指针）：" + Arrays.toString(res2));
    }
}


class Solutionpfpx {
    // 方法1：暴力法 平方 + 排序
    public int[] sortedSquares(int[] nums) {
        for (int i = 0; i < nums.length; i++) {
            nums[i] = nums[i] * nums[i];
        }
        Arrays.sort(nums);
        return nums;
    }

    // 方法2：双指针法（最优 O(n)）
    public int[] sortedSquares2(int[] nums) {
        int right = nums.length - 1;
        int left = 0;
        int[] result = new int[nums.length];
        int index = result.length - 1;
        
        while (left <= right) {
            if (nums[left] * nums[left] > nums[right] * nums[right]) {
                result[index--] = nums[left] * nums[left];
                left++;
            } else {
                result[index--] = nums[right] * nums[right];
                right--;
            }
        }
        return result;
    }
}