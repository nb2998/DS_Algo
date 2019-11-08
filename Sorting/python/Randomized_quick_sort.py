# Uses python3

# Input Format. The first line of the input contains an integer n. The next line contains a sequence of n
# integers a 0 , a 1 , . . . , a n−1 .

# Constraints. 1 ≤ n ≤ 10 5 ; 1 ≤ a i ≤ 10 9 for all 0 ≤ i < n.

# Output Format. Output this sequence sorted in non-decreasing order.

# Sample 1.

# Input:
# 5
# 23922

# Output:
# 22239

import sys
import random

def partition3(a, l, r):
    x = a[l]
    i = j = l
    t = r

    while i <= t:
        if a[i] < x:
            a[j] , a[i] = a[i] , a[j]
            j += 1

        elif a[i] > a[j]:
            a[t] , a[i] = a[i] , a[t]
            t -= 1
            i-=1
        i+=1
    return j, t



def randomized_quick_sort(a, l, r):
    if l >= r:
        return
    k = random.randint(l, r)
    a[l], a[k] = a[k], a[l]
    m1, m2 = partition3(a, l, r)
    randomized_quick_sort(a, l, m1 - 1)
    randomized_quick_sort(a, m2 + 1, r)


if __name__ == '__main__':


    n = int(input())
    a = [int(i) for i in input().strip().split(" ")]
    randomized_quick_sort(a, 0, n-1)
    for x in a:
        print(x, end=" ")
