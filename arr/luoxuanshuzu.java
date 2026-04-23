public class luoxuanshuzu {
    public static void main(String[] args) 
    {
        Solutionlxsz sol = new Solutionlxsz();
        int[][] matrix = sol.way(3);

        // 打印结果
        for (int i = 0; i < matrix.length; i++) {
            for (int j = 0; j < matrix[i].length; j++) {
                System.out.print(matrix[i][j] + " ");
            }
            System.out.println();
        }
    }
}

class Solutionlxsz
{
    public int[][] way(int n)
    {
        int[][] res = new int[n][n];
        int startx = 0;
        int starty = 0;
        int loop = n/2;
        int offest = 1;
        int count = 1;
        while(loop>0)
        {
            int i = startx;
            int j = starty;
            for(;j<n-offest;j++)
            {
                res[i][j] = count;
                count++;
            }
            for(;i<n-offest;i++)
            {
                res[i][j] = count;
                count++;
            }
            for(;j>starty;j--)

            {
                res[i][j] = count;
                count++;
            }
            for(;i>startx;i--)
            {
                res[i][j] = count;
                count++;
            }
            loop--;
            if(n%2 != 0)
            {
                res[n/2][n/2] = count;
            }
        }
        return res;
    }
}
