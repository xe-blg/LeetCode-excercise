import java.util.Scanner;
public class qujianhe {
public static void main(String[] args)
{
    Scanner sc = new Scanner(System.in);
    int n = sc.nextInt();
    int[] vec = new int[n];
    int[] p = new int[n];
    int pre = 0;
    for(int i = 0; i < n;i++)
    {
        vec[i] = sc.nextInt();
        pre = pre + vec[i];
        p[i] = pre;
    }
    while(sc.hasNextInt())
    {
        int a = sc.nextInt();
        int b = sc.nextInt();
        int sum = 0;
        if(a==0)
        {
            sum = p[b];
        }
        else
        {
            sum = p[b] - p[a-1];
        }
        System.out.println(sum);
    }
    sc.close();
}
    
}
