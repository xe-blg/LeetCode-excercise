// 给你一个数组 nums 和一个值 val，你需要 原地 移除所有数值等于 val 的元素。元素的顺序可能发生改变。然后返回 nums 中与 val 不同的元素的数量。

// 假设 nums 中不等于 val 的元素数量为 k，要通过此题，您需要执行以下操作：

// 更改 nums 数组，使 nums 的前 k 个元素包含不等于 val 的元素。nums 的其余元素和 nums 的大小并不重要。
// 返回 k

//方法一
#include <iostream>
#include <vector>
using namespace std;
//暴力解法
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int sum = 0;
        int i = 0;
        while(i < nums.size())
        {
            if(nums[i] != val)
            {
                sum++;
                i++;
            }
            else
            {
                // 后面元素整体前移覆盖
                for(int j = i; j < nums.size() - 1; j++)
                {
                    nums[j] = nums[j + 1];
                }
                nums.pop_back();    // 真正删除末尾，数组变短
            }
        }
        return sum;
    }
};

//双指针法

// 时间复杂度：O(n)
// 空间复杂度：O(1)
class Solution2 {
public:
    int removeElement(vector<int>& nums, int val) {
        int slowIndex = 0;
        for (int fastIndex = 0; fastIndex < nums.size(); fastIndex++) {
            if (val != nums[fastIndex]) {
                nums[slowIndex++] = nums[fastIndex];
            }
        }
        return slowIndex;
    }
};

// 打印vector工具函数
void printVector(vector<int>& v) {
    for(int i = 0; i < v.size(); i++) {
        cout << v[i] << " ";
    }
    cout << endl;
}

// 主函数测试
int main() {
    Solution sol;

    // 测试用例1：普通情况（首尾都有要删除的数）
    vector<int> nums1 = {3, 2, 2, 3};
    int val1 = 3;
    int len1 = sol.removeElement(nums1, val1);
    cout << "测试1：" << endl;
    cout << "删除值：" << val1 << endl;
    cout << "剩余长度：" << len1 << endl;
    cout << "剩余数组："; printVector(nums1);
    cout << "-------------------" << endl;

    // 测试用例2：所有元素都要删除
    vector<int> nums2 = {2, 2, 2};
    int val2 = 2;
    int len2 = sol.removeElement(nums2, val2);
    cout << "测试2：" << endl;
    cout << "删除值：" << val2 << endl;
    cout << "剩余长度：" << len2 << endl;
    cout << "剩余数组："; printVector(nums2);
    cout << "-------------------" << endl;

    // 测试用例3：没有元素需要删除
    vector<int> nums3 = {1, 2, 3, 4};
    int val3 = 5;
    int len3 = sol.removeElement(nums3, val3);
    cout << "测试3：" << endl;
    cout << "删除值：" << val3 << endl;
    cout << "剩余长度：" << len3 << endl;
    cout << "剩余数组："; printVector(nums3);
    cout << "-------------------" << endl;

    // 测试用例4：空数组
    vector<int> nums4;
    int val4 = 1;
    int len4 = sol.removeElement(nums4, val4);
    cout << "测试4：" << endl;
    cout << "删除值：" << val4 << endl;
    cout << "剩余长度：" << len4 << endl;
    cout << "剩余数组："; printVector(nums4);

    return 0;
}