package Lec5;

public class QueueClient {

	public static void main(String[] args) throws Exception {
		// TODO Auto-generated method stub
		Queue q=new Queue(50);
		q.enqueue(10);
		q.enqueue(20);
		q.enqueue(30);
		q.enqueue(40);
		q.display();
		System.out.println("Removing "+q.dequeue());
		q.enqueue(50);
		q.display();
		

	}

}
