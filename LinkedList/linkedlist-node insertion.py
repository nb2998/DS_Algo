# This function is in LinkedList class 
# Function to insert a new node at the beginning 
def push(self, new_data): 
  
    # 1 & 2: Allocate the Node & 
    #        Put in the data 
    new_node = Node(new_data) 
          
    # 3. Make next of new Node as head 
    new_node.next = self.head 
          
    # 4. Move the head to point to new Node  
    self.head = new_node 
