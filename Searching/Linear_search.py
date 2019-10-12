# Program to Implement Linear Search 
# Input (array) : 2 4 1 3 6 7
# Input (Element) : 3
# Output : Key Found!

import time
###---------------  Function to implement Insertion sort ----------------###
def linear_search(array, key):
    found = False
    start = time.time()
    for i in array:
        if i == key:
            found = True
            break
    end = time.time()
    total_time = end - start
    return found , total_time

###------------------------ driver function ----------------------###
def main():
    Array = [ int(i) for i in input("Enter the elements in array : ").strip().split(" ")]
    key = int(input("Enter the value of Key :"))
    print("------ Using Linear Search to Find element {} in array -------".format(key))
    result, total_time_linear = linear_search(Array, key)
    if result:
        print("Key found in the array !")
    else:
        print("Key doesn't exists !")
    print("Total time taken by program is {}".format(total_time_linear))

###-------------- Calling driver function ------------------###
main()
