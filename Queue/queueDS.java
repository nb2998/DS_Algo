package com.company;

class NodeQ{
    NodeQ next;
    int data;
    NodeQ(int data){
        this.data = data;
    }
}

class queueDS {
    private NodeQ head; // remove from head
    private NodeQ tail; // add at tail

    public boolean isEmpty(){
        return head == null;
    }

    public int peek(){
        if(isEmpty()){
            throw new NullPointerException();
        }
        return head.data;
    }

    public void add(int data){
        NodeQ node = new NodeQ(data);
        // it will check whether the tail is at last node if then new node will be inserted there
        if(tail != null){
            tail.next = node;
        }
        tail = node;
        // if head is not there that means queue is empty then insert at head
        if(head == null){
            head = node;
        }
    }

    public int remove(){
        int temp = head.data;
        head = head.next;
        if(head == null){
            tail = null;
        }
        return temp;
    }

    public void printQ(){
        NodeQ nodeQ = head;
        while(nodeQ != null){
            System.out.println(nodeQ.data);
            nodeQ = nodeQ.next;
        }
    }

    public static void main(String[] args) {
        queueDS qd = new queueDS();
        qd.add(34);
        qd.add(56);
        qd.add(90);
        qd.add(18);

        qd.printQ();
    }
}
