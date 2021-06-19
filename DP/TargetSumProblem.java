
import java.util.*;
public class TargetSumProblem {
    public static int TargetSum(int[] wt,int sum,int n)
    {
        int[][] dp = new int[n+1][sum+1];
        for(int i=0;i<=sum;i++)
        {
            dp[0][i]=0;
        }
        for(int i=0;i<=n;i++)
        {
            dp[i][0]=1;
        }
        for(int i=0;i<=n;i++)
        {
            for(int j=0;j<=sum;j++)
            {
                try
                {
                    dp[i][j]=dp[i-1][j-wt[i-1]] + dp[i-1][j];
                }
                catch(Exception e)
                {

                }
            }
        }
        for(int i=0;i<=n;i++)
        {
            for(int j=0;j<=sum;j++)
            {
                System.out.print(dp[i][j]+" ");
            }
            System.out.println();
        }
        
        return dp[n][sum];
            
    }
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int size;
        System.out.println("Enter the number of elements in the array");
        size=sc.nextInt();
        System.out.println("Enter number in the array");
        int[] wt = new int[size];
        for(int i=0;i<wt.length;i++)
        {
            wt[i]=sc.nextInt();
        }
        int target;
        System.out.println("Enter the target value");
        target=sc.nextInt();
        int sum=0;
        for(int i=0;i<wt.length;i++)
        {
            sum=sum+wt[i];
        }
        int s1=(sum+target)/2;
        System.out.println(TargetSum(wt,s1,size));
        
    }

}
