# Class definition for bubble sort algorithm

class BubbleSort:
    def __init__ (self, arr):
        self.arr = arr
        
    def swap(self, index):
        temp = self.arr[index]
        self.arr[index] = self.arr[index+1]
        self.arr[index+1] = temp

    def sort (self):
        for i in range (0,len(self.arr)):
            for j in range (0,len(self.arr)-1):
                if self.arr[j] > self.arr[j+1]:
                    self.swap (j)
            
    def printArr (self):
        print(self.arr)
            
# Main Program execution begins here
if __name__ == '__main__':
    newsort = BubbleSort([23,47,12,63,3,75])
    newsort.sort()
    print (newsort.arr)
    
