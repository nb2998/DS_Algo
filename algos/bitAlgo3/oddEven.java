package bitAlgorithms;

public class oddEven {
	 // Function to swap even 
    // and odd bits 
    static int swapBits(int x) 
    { 
        // Get all even bits of x 
        int even_bits = x & 0xAAAAAAAA;  
      
        // Get all odd bits of x 
        int odd_bits = x & 0x55555555;  
      
        // Right shift even bits 
        even_bits >>= 1;  
          
        // Left shift even bits 
        odd_bits <<= 1;  
          
        // Combine even and odd bits 
        return (even_bits | odd_bits);  
    } 
      
    
    public static void main(String[] args) 
    { 
        int x = 23; // 00010111 
      
        // Output is 43 (00101011) 
        System.out.println(swapBits(x)); 
    } 
}
