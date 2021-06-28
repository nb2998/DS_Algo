
package javaapplication37;
import java.util.*;

public class JavaApplication37 {
    public static boolean Check(String s1,String s2,String s3,int l1,int l2,int l3,int p1,int p2,int p3)
    {
        //System.out.println("l1,l2,l3,p1,p2,p3= "+l1+" "+l2+" "+l3+" "+p1+" "+p2+" "+p3);
        if(p3==l3)
        {
            
            if(l1==p1 && l2==p2)
            {
                return true;
            }
            else
            {
                return false;
            }
        }
        
        String key = Integer.toString(p1)+"*"+Integer.toString(p2);
        
        Map<String,Boolean> map = new HashMap<>();
        
        if(map.get(key)!=null)
        {
            return map.get(key);
        }
        
        if(p1==l1)
        {
            if(s2.charAt(p2)==s3.charAt(p3))
            {
                map.put(key, Check(s1,s2,s3,l1,l2,l3,p1,p2+1,p3+1));
                return map.get(key);
            }
            else
            {
                return false;
            }
        }
        if(p2==l2)
        {
            if(s1.charAt(p1)==s3.charAt(p3))
            {
                map.put(key, Check(s1,s2,s3,l1,l2,l3,p1+1,p2,p3+1));
                return map.get(key);
            }
            else
            {
                return false;
            }
        }
        boolean one,two;
        one=two=false;
        if(s1.charAt(p1)==s3.charAt(p3))
        {
            one=Check(s1,s2,s3,l1,l2,l3,p1+1,p2,p3+1);
        }
        if(s2.charAt(p2)==s3.charAt(p3))
        {
            one=Check(s1,s2,s3,l1,l2,l3,p1,p2+1,p3+1);
        }
        
        map.put(key, one||two);
        return map.get(key);
        
        
    }
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        
        System.out.println("Enter the string s1");
        String s1 = sc.nextLine();
        System.out.println("Enter the string s2");
        String s2 = sc.nextLine();
        System.out.println("Enter the string s3");
        String s3 = sc.nextLine();
        int l1=s1.length();
        int l2=s2.length();
        int l3=s3.length();
        if(l3==l1+l2)
        {
            System.out.println(Check(s1,s2,s3,l1,l2,l3,0,0,0));
        }
        else
        {
            System.out.println(false);
        }
    }
    
}
