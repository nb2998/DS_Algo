class Node {
    constructor(val) {
        this.value = val;
        this.next = null;
    }
}

class LinkList {
    constructor() {
        this.head = null;
        this.size = 0;
    }

    // This method appends given node to linklist
    add(val) {
        const newNode = new Node(val);
        let current;
        if (this.head === null) {
            this.head = newNode;
        } else {
            current = this.head;

            while (current.next) {
                current = current.next;
            }
            current.next = newNode;
        }

        this.size++;
    }

    // This method displays linklist nodes separated by arrows
    print() {
        let current;
        let linkliststr = '';
        if (this.head === null) {
            console.log('List Empty');
        } else {
            current = this.head;
            while (current !== null) {
                linkliststr += `${current.value}->`;
                current = current.next;
            }
        }
        console.log(linkliststr + 'null');
    }

    // This method helps to insert a node at specified position in linklist
    // element -> argument that represents value of node
    // pos -> argument that represents index at which node is to be inserted
    insertAt(element, pos) {
        let nodeToInsert = new Node(element);
        let count = 0;
        let current = this.head;
        let previous;
        if (pos === 0) {
            nodeToInsert.next = this.head;
            this.head = nodeToInsert;
        } else if (pos == this.size) {
            while (count < pos) {
                previous = current;
                current = current.next;
                count++;
            }
            previous.next = nodeToInsert;
        }
        else {
            while (count < pos) {
                previous = current;
                current = current.next;
                count++;
            }
            nodeToInsert.next = previous.next;
            previous.next = nodeToInsert;
            this.size++;
        }
    }

    // This method removes given node from mentioned position in linklist
    // pos -> index of node which is to be removed.
    remove(pos) {
        let curr = this.head;
        let prev;
        let count = 0;
        if (pos == 0) {
            this.head = curr.next; // removes element from head
        } else if (pos === this.size) {
            while (count < pos) {
                prev = curr;
                curr = curr.next;
                count++;
            }
            prev.next = null;
        } else {
            while (count < pos) {
                prev = curr;
                curr = curr.next;
                count++;
            }
            prev.next = curr.next;
        }
        this.size--;
    }

    // returns size of linklist
    sizeOfList() {
        return this.size;
    }

    // checks if given linklist is empty or not
    isEmpty() {
        return this.head;
    }

    // returns index of a given node in linklist
    indexOf(element) {
        let count = 0;
        let current = this.head;
        while (current != null) {
            if (current.value === element) {
                return count;
            }
            count++;
            current = current.next;
        }
        return -1;
    }
}

const linkList = new LinkList();
linkList.add(1);
linkList.add(2);
linkList.add(3);
linkList.add(4);
linkList.print();
linkList.insertAt(11, 4);
linkList.print();
linkList.remove(2);
linkList.print();