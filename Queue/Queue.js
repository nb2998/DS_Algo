// In this implementation we use an array to represent elements

// Constructor function with elements field initialized empty
function Queue() {
    this.elements = [];
}

// method to add an element at the end of the queue
Queue.prototype.enqueue = function (e) {
    this.elements.push(e);
 };

 // method to remove an element at the fronto of the queue
 Queue.prototype.dequeue = function () {
    return this.elements.shift();
};

// method to check if the queue is empty
Queue.prototype.isEmpty = function () {
    return this.elements.length == 0;
};

// method to get first elemento from front of the queue
Queue.prototype.first = function () {
    return !this.isEmpty() ? this.elements[0] : undefined;
};

// method to get length of the queue
Queue.prototype.length = function() {
    return this.elements.length;
}