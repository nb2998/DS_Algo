# Program to Implement Selection Sort

# Input : 2 4 3 1 7
# Output : 1 2 3 4 7
import time
###---------------  Function to implement selection sort ----------------###
def selection_sort(array):
    for i in range(len(array)):
        min = i
        for j in range(i+1, len(array)):
            if array[min] > array[j]:
                min = j
        array[i], array[min] = array[min] , array[i]
    return array

###------------------------ driver function ----------------------###
def main():
    print()
    array = [ int(i) for i in input("Enter the elements in array : ").strip().split(" ")]
    print("---- Using Selection Sort -----")
    start = time.time()
    array_sel = selection_sort(array)
    end = time.time()
    total_time_selection = end - start
    print("Sorted Array :", array_sel)
    print(f"Total time taken by program is {total_time_selection}")
    
###-------------- Calling driver function ------------------###
main()
