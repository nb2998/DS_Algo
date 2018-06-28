package Lec5;

public class Queue {

	protected int front;
	protected int size;
	protected int[] data;

	public Queue(int cap) {
		this.front = 0;
		this.size = 0;
		this.data = new int[cap];
	}

	public boolean isEmpty() {
		return this.size == 0;
	}

	public int size() {
		return this.size;
	}

	public void enqueue(int item) throws Exception {
		if (this.size == this.data.length)
			throw new Exception("Queue is full");

		this.data[(this.front + this.size) % this.data.length] = item;
		this.size++;

	}

	public int dequeue() throws Exception {
		if (this.size == 0)
			throw new Exception("Queue is empty");

		int rv = this.data[this.front];
		this.data[this.front] = 0;
		this.front = (this.front + 1) % this.data.length;
		this.size--;
		return rv;
	}

	public void display() {
		// System.out.println(this.size);
		for (int i = 0; i < this.size; i++) {
			System.out.print(this.data[(i + this.front) % this.data.length] + " ");
		}
		System.out.println();
	}

	public int getFront() throws Exception {
		if(this.size==0) throw new Exception("Queue is empty");
		return this.data[this.front];
	}
}
