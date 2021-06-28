package javaapplication43;
import java.util.*;
public class JavaApplication43 {

    public static int IncresingSubsequence(int[] arr)
    {
        int i=1;
        int j=0;
        int[] Lis = new int[arr.length];
        
        
        for(int k=0;k<Lis.length;k++)
        {
            Lis[k]=1;
        }
        for(;i<arr.length;i++)
        {
            j=0;
            while(j<i)
            {
                System.out.println("i="+i+" j="+j+" arr[i]="+arr[i]+" arr[j] "+arr[j]);
                if(arr[i]>arr[j])
                {
                    Lis[i]=Math.max(Lis[i], 1+Lis[j]);
                    j++;
                }
                else
                {
                    j++;
                }
            }
        }
        for(i=0;i<Lis.length;i++)
        {
            System.out.print(Lis[i]+" ");
        }
        
        int max=1;
        for(i=0;i<Lis.length;i++)
        {
            if(max<Lis[i])
            {
                max=Lis[i];
            }
        }
        return max;
    }
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int size;
        System.out.println("Enter the size of the array");
        size = sc.nextInt();
        int[] arr = new int[size];
        
        System.out.println("Enter the array elements ");
        for(int i=0;i<arr.length;i++)
        {
            arr[i]=sc.nextInt();
        }
        System.out.println("The legth of longest incresing subseqence is "+IncresingSubsequence(arr));
    }
    
}
