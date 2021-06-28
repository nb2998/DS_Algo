package javaapplication41;
import java.util.*;


public class JavaApplication41 {
    
    public static void LongestReapetinSubsequence(String s1,String s2)
    {
        int r,c;
        r=s1.length()+1;
        c=s1.length()+1;
        int[][] dp = new int[r][c];
        
        for(int i=0;i<r;i++)
        {
            dp[i][0]=0;
        }
        
        for(int i=0;i<c;i++)
        {
            dp[0][i]=0;
        }
        
        
        
        
        //Filling the table
        
        
        for(int i=1;i<r;i++)
        {
            for(int j=1;j<c;j++)
            {
                if(s1.charAt(i-1)==s2.charAt(j-1) && i!=j)
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
        
        System.out.println("Length of the lrs is "+dp[r-1][c-1]);
        
        
        //Finding the LRS 
        
        int index = dp[r-1][c-1];
        System.out.println("Index "+index);
        char[] lrs = new char[index+1];
        lrs[index]='\0';
        
        
        int i,j;
        i=r-1;
        j=c-1;
        
        while(i>0 && j>0 && index >0)
        {
            if(s1.charAt(i-1)==s2.charAt(j-1) && i!=j)
            {
                lrs[index-1]=s1.charAt(i-1);
                index--;
                i--;
                j--;
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
        
        
        //Printing LRS 
        
        for(i=0;lrs[i]!='\0';i++)
        {
            System.out.print(lrs[i]);
        }
        
        System.out.println();
        
        
        
        
        
        
        
        
        
    }
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        
        String s1;
        System.out.println("Enter the string ");
        s1=sc.nextLine();
        String s2 =s1;
        LongestReapetinSubsequence(s1,s2);
    }
    
}
