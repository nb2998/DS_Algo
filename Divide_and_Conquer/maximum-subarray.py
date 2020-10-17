# Problem

# Task:
# You are given a one dimensional array that may contain both positive and negative integers.
# find the sum of contiguous subarray of numbers which has the largest sum.

# Input Format. The input consists of a one dimensional space separated array.

# Constraints. 1 ≤ m ≤ 10**3 .

# Output Format. Output the starting index, ending index and value of sum of subarray.

# Example :
# -3 -8 6 -2 -3 1 5 -6                       <--- input
#  2 6 7                                     <--- output

import math as m


def max_crossing_subarray( a, low, mid, high):
    left_sum = -m.inf
    right_sum = -m.inf
    s = 0
    
    for i in range(mid, low-1, -1):
        s += a[i]
        if s > left_sum:
            left_sum = s
            max_left = i
    s = 0
    
    for i in range(mid+1, high+1):
         s += a[i]
         if s > right_sum:
             right_sum= s
             max_right = i

    return (max_left, max_right, left_sum+right_sum)

def find_max_subarray(a, low, high):
    if low == high:
        return (low, high, a[low])
    else:
        mid = (low+high)//2
        left_low,left_high, left_sum = find_max_subarray(a, low, mid)
        
        right_low, right_high, right_sum = find_max_subarray(a, mid+1, high)


        cross_low, cross_high, cross_sum =max_crossing_subarray(a, low,mid, high)
        if left_sum >= right_sum and left_sum >= cross_sum :
            return (left_low, left_high, left_sum )
        elif right_sum >= left_sum and right_sum >= cross_sum:
            return (right_low, right_high, right_sum )
        else:
            return (cross_low, cross_high, cross_sum)

def main():
    array = [ int(i) for i in input().strip().split(" ")]
    low, high, s = find_max_subarray( array, 0, len(array)-1)
    print(low, high, s)

main()
