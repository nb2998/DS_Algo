class Node: 
      
     
    def __init__(self, data): 
        self.data = data  
        self.next = None
  
class CircularLinkedList: 
      
  
    def __init__(self): 
        self.head = None
  
    
    def push(self, data): 
        ptr1 = Node(data) 
        temp = self.head 
          
        ptr1.next = self.head 
  
        
        if self.head is not None: 
            while(temp.next != self.head): 
                temp = temp.next 
            temp.next = ptr1 
  
        else: 
            ptr1.next = ptr1 # For the first node 
  
        self.head = ptr1  
  
    
    def printList(self): 
        temp = self.head 
        if self.head is not None: 
            while(True): 
                print "%d" %(temp.data), 
                temp = temp.next
                if (temp == self.head): 
                    break 
  
  
 
cllist = CircularLinkedList() 
  
cllist.push(12) 
cllist.push(56) 
cllist.push(2) 
cllist.push(11) 
  
print "Circular Linked List"
cllist.printList() 
