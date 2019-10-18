package bitAlgorithms;

public class multipleOfThree {
	// Function to check if n 
    // is a multiple of 3 
    static int isMultipleOf3(int n) 
    { 
        int odd_count = 0; 
        int even_count = 0; 
  
        /* Make no positive if +n is multiple  
    of 3 then is -n. We are doing this to  
    avoid stack overflow in recursion*/
        if (n < 0) 
            n = -n; 
        if (n == 0) 
            return 1; 
        if (n == 1) 
            return 0; 
  
        while (n != 0) { 
            /* If odd bit is set then 
        increment odd counter */
            if ((n & 1) != 0) 
                odd_count++; 
  
            /* If even bit is set then 
        increment even counter */
            if ((n & 2) != 0) 
                even_count++; 
  
            n = n >> 2; 
        } 
  
        return isMultipleOf3(Math.abs(odd_count - even_count)); 
    } 
  
    /* Program to test function isMultipleOf3 */
    public static void main(String[] args) 
    { 
        int num = 24; 
  
        if (isMultipleOf3(num) != 0) 
            System.out.println(num + " is multiple of 3"); 
        else
            System.out.println(num + " is not a multiple of 3"); 
    } 

}
