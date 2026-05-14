#include<bits/stdc++.h>
using namespace std;
int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        int n;
        cin>>n;

        vector<vector<bool>> can_show(n,vector<bool>(10,false));
        for (int i = 0; i < n; i++)
        {
            bool has6 = false;
            for (int j = 0; j < 6; j++)
            {
                int x;
                cin>>x;
                can_show[i][x] = true;
                if (x == 6) has6 = true;
            }
            if (has6) {                       
                can_show[i][9] = true;        
            }
        }

         // dp[i][j] 表示：前 i 个骰子，且第 i 个骰子显示的数字是 j 的合法序列数
         vector<vector<long long>> dp(n,vector<long long>(10,0));
         for (int j = 0; j <= 9; j++)
         {
            if (can_show[0][j])
            {
                dp[0][j] = 1;
            }
         }

         // 递推：从第二个骰子开始，一直到最后一个骰子
         for (int i = 1; i < n; i++)
         {
            for (int j = 0; j <= 9; j++)
            {
                if (!can_show[i][j]) continue;

                long long sum = 0;
                for (int k = 0; k <= j; k++) { // k 表示前一个骰子显示的数字
                    sum += dp[i-1][k];         // 加上前一个骰子显示 k 时的方案数
                }
                dp[i][j] = sum;                // 当前状态的方案数等于所有合法前序状态的累加
            }
         }

         long long ans = 0;
         for (int j = 0; j <= 9; j++)
         {
            ans += dp[n-1][j];
         }
         cout << ans << endl; 
    }
    return 0;
}