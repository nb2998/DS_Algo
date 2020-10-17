bool isSubsetSum(int set[], int n, int sum) 
{ 
   
    bool subset[n+1][sum+1]; 
   
   
    for (int i = 0; i <= n; i++) 
      subset[i][0] = true; 
   
  
    for (int i = 1; i <= sum; i++) 
      subset[0][i] = false; 
   
     
     for (int i = 1; i <= n; i++) 
     { 
       for (int j = 1; j <= sum; j++) 
       { 
         if(j<set[i-1]) 
         subset[i][j] = subset[i-1][j]; 
         if (j >= set[i-1]) 
           subset[i][j] = subset[i-1][j] ||  
                                 subset[i - 1][j-set[i-1]]; 
       } 
     } 
   
   
     for (int i = 0; i <= n; i++) 
     { 
       for (int j = 0; j <= sum; j++) 
          printf ("%4d", subset[i][j]); 
       printf("\n"); 
     }*/
   
     return subset[n][sum]; 
} 
