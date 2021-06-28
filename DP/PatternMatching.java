
package javaapplication42;
import java.util.*;


public class JavaApplication42 {
    public static boolean PatternMatching(String s,String p)
    {
        int r = p.length()+1;
        int c = s.length()+1;
        
        int[][] dp = new int [r][c];
        
        for(int i=0;i<r;i++)
        {
            dp[i][0]=0;
        }
        for(int i=0;i<c;i++)
        {
            dp[0][i]=0;
        }
        
        //Filling the dp table
        
        for(int i=1;i<r;i++)
        {
            for(int j=1;j<c;j++)
            {
                if(p.charAt(i-1)==s.charAt(j-1))
                {
                    dp[i][j]=1+dp[i-1][j-1];
                }
                else
                {
                    dp[i][j]=Math.max(dp[i-1][j], dp[i][j-1]);
                }
            }
        }
        
        
        //Finding the lcs
        
        int index = dp[r-1][c-1];
        
        char[] lcs = new char[index+1];
        lcs[index] = '\0';
        
        int i =r-1;
        int j = c-1;
           
        while(i>0 && j>0 && index>0)
        {
            if(p.charAt(i-1)==s.charAt(j-1))
            {
                lcs[index-1] = p.charAt(i-1);
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
        
        //Printing lcs 
        
        for(i=0;lcs[i]!='\0';i++)
        {
            System.out.print(lcs[i]+" ");
        }
        System.out.println();
        

        for(i=0;i<r;i++)
        {
            for(j=0;j<c;j++)
            {
                System.out.print(dp[i][j]+" ");
            }
            System.out.println();
        }
        String arr = String.valueOf(lcs);
        System.out.println();
        System.out.println(arr);
        System.out.println(p);
        if(arr.equals(p))
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String s,p;
        System.out.println("Enter the pattern string");
        p=sc.nextLine();
        System.out.println("Enter the String");
        s=sc.nextLine();
        System.out.println(PatternMatching(s,p));
        
    }
    
}
