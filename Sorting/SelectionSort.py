# Class definition for selection sort algorithm

class SelectionSort:
    def __init__ (self, arr):
        self.arr = arr
        
    def swapWithSmallest(self, low, high):
        for i in range (low+1,high-1):
            if self.arr[low] > self.arr[i]:
                temp = self.arr[i]
                self.arr[i] = self.arr[low]
                self.arr[low] = temp

    def sort (self):
        for i in range (0,len(self.arr)):
            self.swapWithSmallest (i,len(self.arr))
    def printArr (self):
        print(self.arr)
            
# Main Program execution begins here
if __name__ == '__main__':
    newsort = SelectionSort([23,47,12,63,3,75])
    newsort.sort()
    print (newsort.arr)
    
