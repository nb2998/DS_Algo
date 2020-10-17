# Python program to demonstrate Succinct Tree Encoding and Decoding 

# Node structure 
class Node: 
	# Utility function to create new Node 
	def __init__(self , key): 
		self.key = key 
		self.left = None
		self.right = None

def EncodeSuccint(root , struc , data): 
	
	# If root is None , put 0 in structure array and return 
	if root is None : 
		struc.append(0) 
		return

	# Else place 1 in structure array, key in 'data' array 
	# and recur for left and right children 
	struc.append(1) 
	data.append(root.key) 
	EncodeSuccint(root.left , struc , data) 
	EncodeSuccint(root.right , struc ,data) 
	

# Constructs tree from 'struc' and 'data' 
def DecodeSuccinct(struc , data): 
	if(len(struc) <= 0): 
		return None
	
	# Remove one item from structure list 
	b = struc[0] 
	struc.pop(0) 
	
	# If removed bit is 1 
	if b == 1: 
		key = data[0] 
		data.pop(0) 
	
		#Create a tree node with removed data 
		root = Node(key) 

		#And recur to create left and right subtrees 
		root.left = DecodeSuccinct(struc , data); 
		root.right = DecodeSuccinct(struc , data); 
		return root 

	return None


def preorder(root): 
	if root is not None: 
		print "key: %d" %(root.key), 
			
		if root.left is not None: 
			print "| left child: %d" %(root.left.key), 
		if root.right is not None: 
			print "| right child %d" %(root.right.key), 
		print "" 
		preorder(root.left) 
		preorder(root.right) 

# Driver Program 
root = Node(10) 
root.left = Node(20) 
root.right = Node(30) 
root.left.left = Node(40) 
root.left.right = Node(50) 
root.right.right = Node(70)		 

print "Given Tree"
preorder(root) 
struc = [] 
data = [] 
EncodeSuccint(root , struc , data) 

print "\nEncoded Tree"
print "Structure List"

for i in struc: 
	print i , 

print "\nDataList"
for value in data: 
	print value, 

newroot = DecodeSuccinct(struc , data) 

print "\n\nPreorder Traversal of decoded tree"
preorder(newroot)
