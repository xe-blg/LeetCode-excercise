// 给定一个 n 个元素有序的（升序）整型数组 nums 和一个目标值 target  ，写一个函数搜索 nums 中的 target，如果 target 存在返回下标，否则返回 -1。

// 你必须编写一个具有 O(log n) 时间复杂度的算法。


// 示例 1:

// 输入: nums = [-1,0,3,5,9,12], target = 9
// 输出: 4
// 解释: 9 出现在 nums 中并且下标为 4
// 示例 2:

// 输入: nums = [-1,0,3,5,9,12], target = 2
// 输出: -1
// 解释: 2 不存在 nums 中因此返回 -1

#include <iostream>
#include <vector>
using namespace std;

// 你原来的二分查找代码（不动）
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size() - 1; 
        while (left <= right) { 
            int middle = left + ((right - left) / 2);
            if (nums[middle] > target) {
                right = middle - 1;
            } else if (nums[middle] < target) {
                left = middle + 1;
            } else {
                return middle; 
            }
        }
        return -1;
    }
};

// 主函数测试
int main() {
    // 1. 创建一个有序数组（二分查找必须有序！）
    vector<int> nums = { -1, 0, 3, 5, 9, 12 };

    Solution sol;

    // 2. 测试1：找得到的数字 9
    int target1 = 9;
    int res1 = sol.search(nums, target1);
    cout << "查找 " << target1 << " 下标是：" << res1 << endl; 
    // 预期输出 4

    // 3. 测试2：找得到的数字 12
    int target2 = 12;
    int res2 = sol.search(nums, target2);
    cout << "查找 " << target2 << " 下标是：" << res2 << endl; 
    // 预期输出 5

    // 4. 测试3：找不到的数字 2
    int target3 = 2;
    int res3 = sol.search(nums, target3);
    cout << "查找 " << target3 << " 下标是：" << res3 << endl; 
    // 预期输出 -1

    return 0;
}