# Program to Implement Insertion Sort

# Input : 3 1 2 5 4
# Output :  1, 2, 3, 4, 5

import time

###---------------  Function to implement Insertion sort ----------------###
def insertion_sort(array):
    for i in range(1, len(array)):
        for j in range(i-1, -1, -1):
            if array[j] > array[j+1]:
                array[j], array[j+1] = array[j+1], array[j]
            
            else:
                break
    return array

###------------------------ driver function ----------------------###
def main():
    print()

    array = [ int(i) for i in input("Enter the elements in array : ").strip().split(" ")]
    
    print("---- Using Insertion Sort -----")
    start = time.time()
    array_ins = insertion_sort(array)
    end = time.time()
    total_time_insertion = end - start
    print("Sorted Array :", array_ins)
    print(f"Total time taken by program is {total_time_insertion}")
    
###-------------- Calling driver function ------------------###
main()
