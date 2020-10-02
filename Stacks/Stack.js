class Stack {
	constructor() {
		this.items = [];
		this.top = -1;
	}

	// insert an element at the top of the stack
	push(element) {
		if(element !== null || element !== undefined){
			this.top += 1;
			this.items.push(element);
		}
	}

	// remove an element at the top of the stack
	pop() {
		if(!this.isEmpty()){
			var element = this.peek();
			this.top -= 1;
			this.items.pop();
			return element;
		} else {
			throw "StackUnderflow Exception";
		}
	}

	// peek the top element of the 
	// stack without emoving it
	peek() {
		return this.items[this.top];
	}

	// checks if the stack is empty
	isEmpty() {
		return this.top == -1;
	}

	// returns the size of the stack
	size() {
		return this.top + 1;
	}

	// prints the stack
	print() {
		console.log("Stack\n")
	    for (var i = this.top; i >= 0; i--) 
	        console.log(this.items[i] + " ");

	}
}