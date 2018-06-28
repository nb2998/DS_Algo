package Lec6;

public class LLClient {
	public static void main(String[] args) throws Exception {
		LinkedList ll = new LinkedList();
		ll.addLast(10);
		ll.addLast(20);
		ll.addLast(30);
		ll.addLast(40);
		ll.addLast(50);
		ll.addLast(60);
		ll.addLast(70);
		ll.addLast(80);
		ll.addLast(90);
//		ll.addLast(70);
//		ll.addLast(70);
//		ll.addLast(80);
		ll.display();
//		System.out.println(ll.kthFromLast(4));
//		System.out.println(ll.mid());
		
		ll.kReverse(3);
		ll.display();
		ll.addLast(90);
		ll.display();
//		ll.addLast(60);
//		ll.addFirst(50);
//		ll.display();
//		ll.removeFirst();
//		ll.display();
//		ll.removeAt(2);
//		ll.display();
//		ll.addAt(3, 70);
//		ll.display();
////		ll.removeLast();
//		ll.display();
//		
//		ll.reverseDI();
//		ll.display();
//		
//		ll.reversePI();
//		ll.display();
////		
//		ll.reverseDR();
//		ll.display();
//		
//		ll.foldLL();
//		ll.display();
		
	}

}
