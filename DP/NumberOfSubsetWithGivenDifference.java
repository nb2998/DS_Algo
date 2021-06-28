
import java.util.*;
public class NumberOfSubsetWithGivenDifference {
    public static int CountSubset(int[] wt,int sum,int n)
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
                    dp[i][j]=dp[i-1][j] + dp[i-1][j-wt[i-1]];
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
        int[] wt = new int[size];
        System.out.println("Enter the elements in the array");
        for(int i=0;i<wt.length;i++)
        {
            wt[i]=sc.nextInt();
        }
        int diff;
        System.out.println("Enter the given difference value");
        diff=sc.nextInt();
        int sum=0;
        for(int i=0;i<wt.length;i++)
        {
            sum=sum+wt[i];
        }
        int s1;
        s1=(sum+diff)/2;
        System.out.println(CountSubset(wt,s1,size));
    }
    
}
