#include <iostream>
#include <vector>
#include <algorithm>  // sort 排序需要这个头文件
using namespace std;

class Solution {
public:
    vector<int> sortedSquares(vector<int>& A) {
        // 第一步：每个数平方
        for (int i = 0; i < A.size(); i++) {
            A[i] *= A[i];
        }
        // 第二步：排序
        sort(A.begin(), A.end());
        return A;
    }
};

class Solution2 {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        vector<int> result(nums.size(),0);
        int k = result.size()-1;
        int i = 0;
        int j = nums.size()-1;
        while(i<j)
        {
            if(nums[i]*nums[i]<nums[j]*nums[j])
            {
                result[k]=nums[j]*nums[j];
                k--;
                j--;
            }
            else if(nums[i]*nums[i]>=nums[j]*nums[j])
            {
                result[k]=nums[i]*nums[i];
                k--;
                i++;
            }
        }
        result[k] = nums[i]*nums[i];
        return result;
    }
};

// 打印数组
void printVector(vector<int>& v) {
    for (int i = 0; i < v.size(); i++) {
        cout << v[i] << " ";
    }
    cout << endl;
}

int main() {
    Solution sol;

    // 测试用例：[-4,-1,0,3,10]
    vector<int> nums = {-4, -1, 0, 3, 10};
    
    cout << "原数组：";
    printVector(nums);

    vector<int> res = sol.sortedSquares(nums);

    cout << "平方+排序后：";
    printVector(res);

    return 0;
}