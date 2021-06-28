
package javaapplication38;
import java.util.*;

public class JavaApplication38 {

    public static void LenghtOFSubsequence(String s1,String s2)
    {
        int r,c;
        r=s1.length()+1;
        c=s2.length()+1;
        int[][] dp = new int[r][c];
        

        
        for(int i=0;i<r;i++)
        {
            dp[i][0]=0;
        }
        for(int i=0;i<c;i++)
        {
            dp[0][i]=0;
        }
        
        for(int i=1;i<r;i++)
        {
            for(int j=1;j<c;j++)
            {
                if(s1.charAt(i-1)==s2.charAt(j-1))
                {
                    dp[i][j]=1+dp[i-1][j-1];
                }
                else
                {
                    dp[i][j]=Math.max(dp[i-1][j], dp[i][j-1]);
                }
            }
        }
        
        for(int i=0;i<r;i++)
        {
            for(int j=0;j<c;j++)
            {
                System.out.print(dp[i][j]+" ");
            }
            System.out.println();
        }
        
        int index = dp[r-1][c-1];
        System.out.println(index);
        char[] lcs = new char[index+1];
        lcs[index]='\0';
        int i=r-1;int j=c-1;
        while(i>0 && j>0)
        {
            if(s1.charAt(i-1)==s2.charAt(j-1))
            {
                lcs[index-1]=s1.charAt(i-1);
                i--;
                j--;
                index--;
            }
            else if(dp[i-1][j]>dp[i][j-1])
            {
                i--;
            }
            else
            {
                j--;
            }
        }
        System.out.println("The longest common subsequence is ");
        for(i=0;lcs[i]!='\0';i++)
        {
            System.out.print(lcs[i]+" ");
        }
        
        
        
        
        
        
        
    }
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        
        String s1;
        String s2;
        System.out.println("Enter the string 1");
        s1 = sc.nextLine();
        System.out.println("Enter the string 2");
        s2=sc.nextLine();
        //System.out.println("Length of the longest common susequence is"+LenghtOFSubsequence(s1,s2));
        LenghtOFSubsequence(s1,s2);
    }
    
}
