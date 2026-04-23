#include <iostream>
#include <vector>
using namespace std;

// 你原来的代码不动
class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> res(n, vector<int>(n, 0));
        int startx = 0;
        int starty = 0;
        int loop = n / 2;
        int mid = n / 2;
        int offset = 1;
        int count = 1;

        while (loop--) {
            int i = startx;
            int j = starty;

            // 向右
            for (j; j < n - offset; j++) {
                res[i][j] = count++;
            }
            // 向下
            for (i; i < n - offset; i++) {
                res[i][j] = count++;
            }
            // 向左
            for (j; j > starty; j--) {
                res[i][j] = count++;
            }
            // 向上
            for (i; i > startx; i--) {
                res[i][j] = count++;
            }

            startx++;
            starty++;
            offset++;
        }

        // 如果n是奇数，最中间赋值
        if (n % 2 == 1) {
            res[mid][mid] = count;
        }

        return res;
    }
};

// 主函数测试
int main() {
    int n;
    cout << "请输入矩阵大小 n：";
    cin >> n;

    Solution sol;
    vector<vector<int>> mat = sol.generateMatrix(n);

    // 输出螺旋矩阵
    cout << "生成的螺旋矩阵为：" << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << mat[i][j] << "\t";
        }
        cout << endl;
    }

    return 0;
}