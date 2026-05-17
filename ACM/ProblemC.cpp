#include <bits/stdc++.h>  // 万能头文件，包含了C++所有标准库（vector、iostream、algorithm等）
using namespace std;       // 使用标准命名空间，这样可以直接写cin/cout/vector，不用写std::cin

int main() {               // 主函数，程序入口
    ios::sync_with_stdio(false);  // 取消C++和C的输入输出同步，让cin/cout更快
    cin.tie(nullptr);             // 解除cin和cout的绑定，输入前不会自动刷新输出缓冲区
    
    int n;                 // 定义整数n，表示矩阵的大小
    cin >> n;              // 从输入读取n
    
    vector<int> a(n + 1), b(n + 1);  // 创建两个vector，大小都是n+1（下标从1开始用，第0个位置空着）
    for (int i = 1; i <= n; i++) cin >> a[i];  // 循环读取n个整数到a[1]到a[n]
    for (int i = 1; i <= n; i++) cin >> b[i];  // 循环读取n个整数到b[1]到b[n]
    
    // 构造标准矩阵: 第 i 行最后 i 个位置是 1
    // base是一个二维vector，大小为 (n+1) x (n+1)，所有元素初始化为0
    vector<vector<int>> base(n + 1, vector<int>(n + 1, 0));
    
    // 外层循环：遍历每一行 i 从 1 到 n
    for (int i = 1; i <= n; i++) {
        // 内层循环：从第 n-i+1 列开始，到第 n 列结束
        // 例如 n=5, i=1时: j从5到5, 只填最后一列
        //        i=2时: j从4到5, 填最后两列
        //        i=3时: j从3到5, 填最后三列
        // 这样第 i 行恰好有 i 个1（因为从n-i+1到n一共是i列）
        for (int j = n - i + 1; j <= n; j++) {
            base[i][j] = 1;  // 把这个位置设为1
        }
    }
    
    // 输出最终矩阵
    // 第 i 行取 base 的第 a[i] 行，第 j 列取 base 的第 b[j] 列
    for (int i = 1; i <= n; i++) {          // 遍历最终矩阵的每一行
        for (int j = 1; j <= n; j++) {      // 遍历最终矩阵的每一列
            // base[a[i]][b[j]] 的含义：
            // a[i] 是原始第i行应该对应的行号
            // b[j] 是原始第j列应该对应的列号
            // 所以取 base 矩阵中 (a[i]行, b[j]列) 的值作为最终矩阵的 (i,j) 位置
            cout << base[a[i]][b[j]];       // 输出这个值（0或1），不换行
        }
        cout << "\n";  // 每行结束后输出换行符
    }
    
    return 0;  // 程序正常结束，返回0
}