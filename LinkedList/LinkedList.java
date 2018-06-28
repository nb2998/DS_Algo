package Lec6;

public class LinkedList {

	private class Node {
		int data;
		Node next;

		Node() {

		}

		Node(int data) {
			this.data = data;
			this.next = null;
		}
	}

	Node head, tail;
	int size;

	public int getFirst() throws Exception {
		if (this.size == 0)
			throw new Exception("LL is empty");

		return this.head.data;
	}

	public int getLast() throws Exception {
		if (this.size == 0)
			throw new Exception("LL is empty");

		return this.tail.data;
	}

	public int getAt(int idx) throws Exception {
		if (this.size == 0)
			throw new Exception("LL is empty");

		if (idx < 0 || idx >= this.size)
			throw new Exception("Invalid index");
		Node temp = this.head;
		for (int i = 0; i < idx; i++)
			temp = temp.next;
		return temp.data;
	}

	private Node getNodeAt(int idx) throws Exception {
		if (this.size == 0)
			throw new Exception("LL is empty");

		if (idx < 0 || idx >= this.size)
			throw new Exception("Invalid index");
		Node temp = this.head;
		for (int i = 0; i < idx; i++)
			temp = temp.next;
		return temp;
	}

	public void addLast(int item) {
		Node nn = new Node(item);
		if (this.size == 0)
			this.head = nn;
		else
			this.tail.next = nn;
		this.tail = nn;
		this.size++;
	}

	public void addFirst(int item) {
		Node nn = new Node(item);
		if (this.size == 0)
			this.tail = nn;
		else
			nn.next = this.head;

		this.head = nn;
		this.size++;
	}

	public void addAt(int idx, int item) throws Exception {
		if (idx < 0 || idx > this.size)
			throw new Exception("Invalid index");
		if (idx == 0)
			addFirst(item);
		else if (idx == this.size)
			addLast(item);
		else {
			Node nn = new Node(item);
			Node nm1 = getNodeAt(idx - 1);
			Node np1 = getNodeAt(idx);
			nm1.next = nn;
			nn.next = np1;
			this.size++;
		}
	}

	public int removeFirst() throws Exception {
		if (this.size == 0)
			throw new Exception("LL is empty");

		int rv = this.head.data;
		this.head = this.head.next;
		if (this.size == 1)
			this.tail = null;
		this.size--;
		return rv;
	}

	public int removeLast() throws Exception {
		if (this.size == 0)
			throw new Exception("LL is empty");

		int rv = this.tail.data;

		if (this.size == 1) {
			this.tail = null;
			this.head = null;
		} else {
			Node nm1 = getNodeAt(this.size - 2);
			nm1.next = null;
			this.tail = nm1;
		}
		this.size--;
		return rv;
	}

	public int removeAt(int idx) throws Exception {
		if (idx < 0 || idx >= this.size)
			throw new Exception("Invalid index");
		if (idx == 0)
			return removeFirst();
		else if (idx == this.size - 1)
			return removeLast();
		else {
			Node nm1 = getNodeAt(idx - 1);
			Node ntbr = getNodeAt(idx);
			Node np1 = getNodeAt(idx + 1);
			nm1.next = np1;
			ntbr.next = null;
			this.size--;
			return ntbr.data;
		}
	}

	public void display() {
		Node temp = this.head;
		while (temp != null) {
			System.out.print(temp.data + "->");
			temp = temp.next;
		}
		System.out.print("END");
		System.out.println();
	}

	public void reverseDI() throws Exception {
		int start = 0, last = this.size - 1;
		while (start <= last) {
			Node one = getNodeAt(start);
			Node two = getNodeAt(last);
			int temp = one.data;
			one.data = two.data;
			two.data = temp;
			start++;
			last--;
		}
	}

	public void reversePI() {
		Node prev = null;
		Node curr = this.head;
		Node nex = curr.next;
		while (nex != null) {
			curr.next = prev;
			prev = curr;
			curr = nex;
			nex = nex.next;
		}
		curr.next = prev;
		Node temp = this.head;
		this.head = this.tail;
		this.tail = temp;
	}

	public void reversePR() {
		reversePR(this.head, this.head.next);
		Node temp = this.head;
		this.head = this.tail;
		this.tail = temp;
		this.tail.next = null;
	}

	private void reversePR(Node prev, Node curr) {
		if (curr == null)
			return;
		reversePR(curr, curr.next);
		curr.next = prev;
	}

	// private void reverseDR(Node left, Node right, int ctr) { // will not work
	// if(right==null) return;
	//
	// reverseDR(left, right.next, ctr+1);
	//
	// if(ctr>=(this.size/2)) {
	// int temp = left.data;
	// left.data=right.data;
	// right.data=temp;
	// left=left.next;
	// }
	//
	//
	// }

	private class Mover {
		Node left;
	}

	public void reverseDR() {
		Mover mover = new Mover();
		mover.left = this.head;
		reverseDR(mover, this.head, 0);
	}

	private void reverseDR(Mover mover, Node right, int ctr) {
		if (right == null)
			return;

		reverseDR(mover, right.next, ctr + 1);

		if (ctr >= (this.size / 2)) {
			int temp = mover.left.data;
			mover.left.data = right.data;
			right.data = temp;
			mover.left = mover.left.next;
		}

	}

	public void foldLL() {
		Mover mover = new Mover();
		mover.left = this.head;
		foldLL(mover, this.head, 0);
	}

	private void foldLL(Mover mover, Node right, int ctr) {
		if (right == null)
			return;
		foldLL(mover, right.next, ctr + 1);
		if (ctr > (this.size / 2)) {
			Node temp = mover.left.next; // remember to store first
			mover.left.next = right;
			mover.left = temp;
			right.next = temp;
		}
		if (ctr == this.size / 2) {
			this.tail = right;
			this.tail.next = null; // REMEMBER
		}
	}
	
	// ***************************************
	// LECTURE 7
	
	public int mid() {
		Node temp1=this.head;
		Node temp2=this.head;
		while(temp2!=null && temp2.next!=null && temp2.next.next!=null) {
			temp1=temp1.next;
			temp2=temp2.next.next;
		}
		return temp1.data;
	}
	
	public int kthFromLast(int k) {
		Node temp1=this.head;
		Node temp2=this.head;
		int i=0;
		while(i<k) {
			temp1=temp1.next;
			i++;
		}
		
		while(temp1!=null) {
			temp2=temp2.next;
			temp1=temp1.next;
		}
		return temp2.data;
	}
	
//	public void kReverse(int k) {
//		int i=0;
//		Node prev=null;
//		Node curr=this.head;
//		Node nex = curr.next;
//		Node temp1=this.head;
//		while(i<=k) {
//			curr.next=prev;
//			prev=curr;
//			curr=nex;
//			nex=nex.next;
//			i++;
//		}
////		System.out.println(curr.data);
//		System.out.println(temp1.data);
////		temp1.next=curr;
//		Node temp2=curr;
//		Node h=prev;
//		
//		while(nex!=null) {
//			curr.next=prev;
//			prev=curr;
//			curr=nex;
//			nex=nex.next;
//		}
//		System.out.println(temp2.data);
//		System.out.println(curr.data);
//		temp1.next=curr;
//		this.tail=temp2;
//		temp2.next=null;
//		this.head=h;
//		
//	}
	
	
	public void kReverse(int k) throws Exception {
		LinkedList prev= null;
		LinkedList curr = null;
		
		while(this.size!=0) {
			
			curr = new LinkedList();
			for(int i=1; i<=k; i++) {
				curr.addFirst(this.removeFirst());
			}
			
			if(prev==null) {
				prev=curr;
			} else {
				prev.tail.next=curr.head;
				prev.tail=curr.tail;
				prev.size+=(curr.size);
			}
			
		}
		this.head=prev.head;
		this.tail=prev.tail;
		this.size=prev.size;
		
	}
	
	// TODO
	
	public int intersection(LinkedList ll2) {
		Node temp=this.head;
		Node temp1=ll2.head;
		
		
		return -1;
	}

}
