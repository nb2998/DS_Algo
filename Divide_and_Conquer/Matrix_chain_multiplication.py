# Program to Implement Matrix Chain Multiplication (MCM):

# Input (array) :  5 4 6 2 7
#Output :

# Total Time taken is : 5.0067901611328125e-05 seconds
# The cost of Matrix Chain Multiplication is :
#  [[  0. 120.  88. 158.]
#  [ inf   0.  48. 104.]
#  [ inf  inf   0.  84.]
#  [ inf  inf  inf   0.]]
# The optimal values of k are :
#  [[-1.  0.  0.  2.]
#  [-1. -1.  1.  2.]
#  [-1. -1. -1.  2.]
#  [-1. -1. -1. -1.]]
# The optimal expression for given Matrix chain Multiplication is :
# ((A0 (A1 A2 ))A3 )



import math as m
import numpy as np
from time import time

# mcm function for calculating cost and optimal values of k
def mcm(m, s, n , p):
    for l in range(n-1):
        for r in range(n-l-2):
            c = r+1+l
            for k in range(r,c):

                temp = m[r,k] + m[k+1, c] + (p[r]*p[k+1]*p[c+1])
                if temp < m[r,c]:
                    m[r,c] = temp
                    s[r,c] = k
    return m, s
                
# print_mcm function for printing optimal expression for given matrix chain multiplication
def print_mcm(s, i , j):
    if i == j:
        print("A"+str(i), end=" ")
    else:
        print('(', end="")
        print_mcm(s, i, int(s[i,j]))
        print_mcm(s, int(s[i,j])+1, j)
        print(')', end="")

# Main function    
def main():
    p = [int(i) for i in input().strip().split(" ")]
    n = len(p)
    
    m = np.zeros((n-1, n-1))
    s = np.zeros((n-1, n-1)) - 1 
    

    for i in range(n-1):
        for j in range(n-1):
            if i == j:
                m[i,j] = 0
            else:
                m[i,j] = np.inf
    start = time()           
    m , s = mcm(m, s, n, p)
    end = time()
    print("Total Time taken is :", end-start,"seconds")
    print("The cost of Matrix Chain Multiplication is :\n" , m)
    print("The optimal values of k are :\n" ,s)
    
    print("The optimal expression for given Matrix chain Multiplication is :")
    print_mcm(s,0,n-2)
    print()
 
# Calling Main Function
main()
