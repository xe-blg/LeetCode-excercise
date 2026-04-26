import java.util.Scanner;

public class kaifashang {
     public static void main(String[] args)
     {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        int m = scanner.nextInt();
        int sum = 0;
        int[][] vec = new int[n][m];
        for(int i=0;i<n;i++)
        {
            for(int j=0;i<m;j++)
            {
                vec[i][j] = scanner.nextInt();
                sum = sum+vec[i][j];
            }
        }

        int result = Integer.MAX_VALUE;
        int count = 0; // 统计遍历过的行

        // 行切分
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                count += vec[i][j];
                // 遍历到行末尾时候开始统计
                if (j == m - 1) {
                    result = Math.min(result, Math.abs(sum - 2 * count));
                }
            }
        }

        count = 0;
        // 列切分
        for (int j = 0; j < m; j++) {
            for (int i = 0; i < n; i++) {
                count += vec[i][j];
                // 遍历到列末尾时候开始统计
                if (i == n - 1) {
                    result = Math.min(result, Math.abs(sum - 2 * count));
                }
            }
        }
        scanner.close();
     }
}
