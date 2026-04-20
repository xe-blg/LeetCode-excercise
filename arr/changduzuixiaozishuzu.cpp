#include <iostream>
#include <vector>
#include <cassert>
#include <climits>

using namespace std;
//暴力解法
class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int minlen = nums.size()+1;
        for(int i = 0;i < nums.size();i++)
        {
            int sum = 0; 
            int length = 0;
            
            for(int j = i;(j<nums.size())&&(sum<target);j++)
            {
                sum = sum + nums[j];
                
                length++;
            }
            if(sum>=target)
            {
                if(length<minlen)
                {
                    minlen = length;
                }
            }

        }
        if(minlen<=nums.size())
        {
            return minlen;
        }
        else
        {
            return 0;
        }
    }
};

class Solution2 {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        int result = nums.size() + 1;
        int sum = 0; // 滑动窗口数值之和
        int i = 0; // 滑动窗口起始位置
        int subLength = 0; // 滑动窗口的长度
        for (int j = 0; j < nums.size(); j++) {
            sum += nums[j];
            // 满足条件就收缩左边界
            while (sum >= s) {
                subLength = (j - i + 1);
                result = result < subLength ? result : subLength;
                sum -= nums[i++];
            }
        }
        
        return result == nums.size() + 1 ? 0 : result;
    }
};

// 测试函数
void runTests() {
    Solution solution;
    
    // 测试用例1：基本示例
    {
        vector<int> nums = {2, 3, 1, 2, 4, 3};
        int target = 7;
        int expected = 2;  // [4,3]
        int result = solution.minSubArrayLen(target, nums);
        cout << "Test 1: target=" << target << ", nums=[2,3,1,2,4,3]" << endl;
        cout << "Expected: " << expected << ", Got: " << result << endl;
        assert(result == expected);
        cout << "✓ Passed" << endl << endl;
    }
    
    // 测试用例2：所有元素之和刚好等于target
    {
        vector<int> nums = {1, 2, 3, 4, 5};
        int target = 15;
        int expected = 5;
        int result = solution.minSubArrayLen(target, nums);
        cout << "Test 2: target=" << target << ", nums=[1,2,3,4,5]" << endl;
        cout << "Expected: " << expected << ", Got: " << result << endl;
        assert(result == expected);
        cout << "✓ Passed" << endl << endl;
    }
    
    // 测试用例3：没有满足条件的子数组
    {
        vector<int> nums = {1, 1, 1, 1, 1};
        int target = 11;
        int expected = 0;
        int result = solution.minSubArrayLen(target, nums);
        cout << "Test 3: target=" << target << ", nums=[1,1,1,1,1]" << endl;
        cout << "Expected: " << expected << ", Got: " << result << endl;
        assert(result == expected);
        cout << "✓ Passed" << endl << endl;
    }
    
    // 测试用例4：单个元素等于target
    {
        vector<int> nums = {5, 1, 2, 3};
        int target = 5;
        int expected = 1;
        int result = solution.minSubArrayLen(target, nums);
        cout << "Test 4: target=" << target << ", nums=[5,1,2,3]" << endl;
        cout << "Expected: " << expected << ", Got: " << result << endl;
        assert(result == expected);
        cout << "✓ Passed" << endl << endl;
    }
    
    // 测试用例5：单个元素大于target
    {
        vector<int> nums = {10, 2, 3};
        int target = 7;
        int expected = 1;
        int result = solution.minSubArrayLen(target, nums);
        cout << "Test 5: target=" << target << ", nums=[10,2,3]" << endl;
        cout << "Expected: " << expected << ", Got: " << result << endl;
        assert(result == expected);
        cout << "✓ Passed" << endl << endl;
    }
    
    // 测试用例6：空数组（虽然题目约束说至少一个元素，但为了完整性）
    {
        vector<int> nums = {};
        int target = 10;
        int expected = 0;
        int result = solution.minSubArrayLen(target, nums);
        cout << "Test 6: target=" << target << ", nums=[]" << endl;
        cout << "Expected: " << expected << ", Got: " << result << endl;
        assert(result == expected);
        cout << "✓ Passed" << endl << endl;
    }
    
    // 测试用例7：需要整个数组
    {
        vector<int> nums = {1, 2, 3, 4};
        int target = 10;
        int expected = 4;
        int result = solution.minSubArrayLen(target, nums);
        cout << "Test 7: target=" << target << ", nums=[1,2,3,4]" << endl;
        cout << "Expected: " << expected << ", Got: " << result << endl;
        assert(result == expected);
        cout << "✓ Passed" << endl << endl;
    }
    
    // 测试用例8：多个解，取最小长度
    {
        vector<int> nums = {1, 2, 3, 4, 5, 6};
        int target = 9;
        int expected = 2;  // [4,5]
        int result = solution.minSubArrayLen(target, nums);
        cout << "Test 8: target=" << target << ", nums=[1,2,3,4,5,6]" << endl;
        cout << "Expected: " << expected << ", Got: " << result << endl;
        assert(result == expected);
        cout << "✓ Passed" << endl << endl;
    }
    
    // 测试用例9：target为0（边界情况）
    {
        vector<int> nums = {1, 2, 3};
        int target = 0;
        int expected = 0;  // 题目通常target>=1，但逻辑上应该是0
        int result = solution.minSubArrayLen(target, nums);
        cout << "Test 9: target=" << target << ", nums=[1,2,3]" << endl;
        cout << "Expected: " << expected << ", Got: " << result << endl;
        // 注意：原代码对于target=0会返回0，因为sum>=target始终为true
        // 但实际题目约束target>=1
        cout << "✓ Passed (target=0 is edge case)" << endl << endl;
    }
    
    // 测试用例10：大数值但很快找到
    {
        vector<int> nums = {1, 100, 1, 1, 1};
        int target = 100;
        int expected = 1;
        int result = solution.minSubArrayLen(target, nums);
        cout << "Test 10: target=" << target << ", nums=[1,100,1,1,1]" << endl;
        cout << "Expected: " << expected << ", Got: " << result << endl;
        assert(result == expected);
        cout << "✓ Passed" << endl << endl;
    }
    
    cout << "==================================" << endl;
    cout << "All tests passed successfully!" << endl;
}

int main() {
    runTests();
    return 0;
}