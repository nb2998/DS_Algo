# Uses python3
# Problem Description

# Task. The goal in this problem is to find the minimum number of coins needed to change the input value
# (an integer) into coins with denominations 1, 5, and 10.

# Input Format. The input consists of a single integer m.

# Constraints. 1 ≤ m ≤ 10**3 .

# Output Format. Output the minimum number of coins with denominations 1, 5, 10 that changes m.

# Example :
# 24          <--- input
# 6         <--- output

# 26        <-- input
#4          <-- output

def get_change(m):
    
    count = 0
    while(m > 0):
        # By Greedy approach, first we subtract highest value from denominations ( 10 here ) 
        # if value of m (i.e. money) is greater than 10 
        if m > 10:
            m -= 10
        
        # if m < 10 but greater than 5, then we will subtract '5' ( second largest value of denomination here)
        elif m > 5:
            m -= 5
        
        # if m < 5, then we subtract '1' ( lowest value of denomination )
        else:
            m -= 1

        # finally we increase count by 1 
        count += 1

    return count

def main():
    m = int(input()) 
    print(get_change(m))

main()