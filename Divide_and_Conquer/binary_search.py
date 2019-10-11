# Uses python3
# Problem Description
# Task: The goal in this code problem is to implement the binary search algorithm.

# Input Format. 
# The first line of the input contains an integer n and a sequence a 0 < a 1 < . . . < a n−1 
# The next line contains an integer k and k.

# Constraints. 1 ≤ n, k ≤ 10 4 ; 1 ≤ a i ≤ 10 9 for all 0 ≤ i < n; 1 ≤ b j ≤ 10 9 for all 0 ≤ j < k;

# Output Format. For all i from 0 to k − 1, output an index 0 ≤ j ≤ n − 1 such that a j = b i or −1 if there
# is no such index.:

#Example :
# 5 1 5 8 12 13    <-- input ( first line )
# 5 8 1 23 1 11    <-- input ( second line )
# 2 0 -1 0 -1      <-- output



def binary_search(a, x):
    l, r = 0, len(a)-1
    idx = -1
    while l <= r:
        mid = (l + r)//2
        if a[mid] == x:
            idx = mid
            break
        elif a[mid] < x:
            l = mid+1
            #return binary_search(a[mid+1: ], x)
        elif a[mid] > x:
            r = mid-1
            #return binary_search(a[: mid], x)
    return idx



def main():
    n_array = [int(i) for i in  input().strip().split(" ")]
    k_elements = [int(i) for i in  input().strip().split(" ")]
    n = n_array[0]
    array = n_array[1:]
    k = (k_elements[0])
    elements = k_elements[1:]
    for i in range(k):
        bs = binary_search(array, elements[i])
        print( bs , end=" ")
    print()


main() 
