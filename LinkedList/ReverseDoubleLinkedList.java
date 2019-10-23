
public class DoubleLinkedList {
	
	static Node head;
	class Node{
		int data;
		Node next;
		Node prev;
		Node(int d){
			data = d;
			next = null;
			prev = null;
		}
	}
	
	//This function is to insert an element in start of doubly linkedlist
	public void push(int data) {
		Node new_node = new Node(data);
		new_node.prev = null;
		new_node.next = head;
		// change prev of head node to new node */
	    if (head != null) 
	        head.prev = new_node; 
		head = new_node;
	}
	
	//This function is to insert an element at the end of doubly linkedlist
	public void ammend(int data) {
		Node temp = head;
		Node new_node = new Node(data);
		if(temp == null) {
			new_node.prev = null;
			new_node.next = head;
			head = new_node;
			return;
		}
		while(temp.next!=null) {
			temp = temp.next;
		}
		temp.next = new_node;
		new_node.prev = temp;
		new_node.next = null;//useless
	}
	
	//This function is to insert an element after a particular node
	public void insertAfter(Node node,int data) {
		if(node == null)
			return ;
		Node new_node = new Node(data);
		new_node.prev = node;
		new_node.next = node.next;
		node.next = new_node;
		new_node.next.prev = new_node;
	}
	
	//This function is to delete an element at a particular position
	public void deletePos(int pos) {
		Node temp = head;
		if(head == null)
			return;
		if(pos == 1) {
			if(temp.next == null)//only one element
				head = null;
			else {
				temp.next.prev = null;
				head = temp.next;
			}
			return;
		}
		for(int i = 1;i<pos-1 && temp!=null;i++) {
			temp = temp.next;
		}
		if(temp == null || temp.next == null || pos<1) {
			return;
		}
		if(temp.next.next == null) //last element
			{
			temp.next = null;
			return;
			}
		Node next = temp.next.next;
		next.prev = temp;
		temp.next = next;
	}
	
	//This function is to delete a particular element
	public void deleteKey(int key) {
		Node temp = head,prevtemp = null;
		if(temp!=null && temp.data == key) {
			if(temp.next == null)//only one element
				head = null;
			else {
				temp.next.prev = null;
				head = temp.next;
			}
			return;
		}
		while(temp!=null &&  temp.data!=key) {
			prevtemp = temp;
			temp = temp.next;
		}
		if(temp == null)//key not found
			return;
		if(temp.next == null) {//last key
			prevtemp.next = null;
			return;
		}
		prevtemp.next = temp.next;
		temp.next.prev = prevtemp;
	}
	
	//This function is to print the list
	public void printList() {
		Node temp = head;
		while(temp!=null) {
			System.out.print(temp.data+" ");
			temp = temp.next;
		}
		System.out.println();
	}
	
	//this function is to reverse the links of dll
	public void reverse() {
		Node temp = null;
		Node current = head;
		while(current!=null) {
			temp = current.prev;
			current.prev = current.next; //concept is to swap prev and next
			current.next = temp;
			current = current.prev;
		}
		/* Before changing head, check for the cases like empty  
        list and list with only one node */
       if (temp != null) { 
           head = temp.prev; 
       } 
	}

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		DoubleLinkedList dll = new DoubleLinkedList();
		dll.push(20);
		dll.push(30);
		dll.ammend(15);
		dll.ammend(29);
		dll.insertAfter(head, 13);
		dll.printList();
		dll.deleteKey(2);
		dll.deletePos(2);
		dll.printList();
		dll.reverse();
		dll.printList();
	}

}
