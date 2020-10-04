// class definition
class Queue {
  constructor(size) {
    this.size = size;
    this.data = [];
  }

  // checks if Queue is empty
  isEmpty() {
    return this.data.length === 0;
  }

  // checks if Queue is full
  isFull() {
    return this.data.length === this.size;
  }

  // Inserts element at the last of the Queue
  enQueue(element) {
    if (!this.isFull()) {
      this.data.push(element);
    } else {
      throw Error("Queue overflow.");
    }
  }

  // Removes first element from the Queue. 
  deQueue() {
    if (this.isEmpty()) {
      throw Error("Queue underflow.");
    } else {
      return this.data.shift();
    }
  }

  // Peek at the front of the Queue. This doesn't remove element from the Queue;
  front() {
    if (this.isEmpty()) {
      console.log("Queue is empty.");
    } else {
      return this.data[0];
    }
  }

  // To print the Queue data.
  printQueue() {
    console.log(this.data);
  }
}


// Usage
const q = new Queue(5);
q.enQueue(1); // [1]
q.enQueue(2); // [1, 2]
q.enQueue(3); // [1, 2, 3]
q.enQueue(4); // [1, 2, 3, 4]
q.enQueue(5); // [1, 2, 3, 4, 5]
q.front(); // 1
q.deQueue(); // 5
q.enQueue(5); // [1, 2, 3, 4, 5]
q.printQueue(); // prints the Queue data. 
q.enQueue(6); // Queue Overflow Error
