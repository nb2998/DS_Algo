array_list = [int(x) for x in input().split()] // space seperated array inputs
gap = int(len(array_list)/2)
while gap >= 1:
    for i in range(gap, len(array_list)):
        key = array_list[i]
        j = i-gap
        while j >= 0 and array_list[j] > key:
            array_list[j+gap] = array_list[j]
            j -= gap
        array_list[j+gap] = key
    gap = int(gap/2)
	
print(array_list)
