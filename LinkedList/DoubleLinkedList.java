package dll;

/**
 * A generic DoubleLinkedList.
 * @param <T> The generic type
 * @author mateustranquilino
 */
public class DoubleLinkedList<T extends Comparable<T>>{

    private Node<T> head;
    private Node<T> tail;
    private int size;

    public DoubleLinkedList(){
        this.size = 0;
    }

    // Insert a new element at start of list.
    public void insertFirst(T element){

        if (this.isEmpty()){
            this.setHead(new Node<T>(element));
            this.setTail(this.head);

        } else {

            Node<T> newNode = new Node<T>(element);        
            newNode.setNext(this.head);
            this.head.setPrevious(newNode);
            this.setHead(newNode);
        }

        this.size++;
    }

    // Insert a new element at end of list.
    public void insertLast(T element){
        
        if (this.isEmpty()){
            insertFirst(element);
        
        } else {
            
            Node<T> newNode = new Node<T>(element);
            newNode.setPrevious(this.getTail());
            this.tail.setNext(newNode);
            this.setTail(newNode);
            this.size++;
        }

    }

    // Return a element if exist in the list, null otherwise.
    public T search(T element){
        T result = null;
        Node<T> aux = this.getHead();

        while (aux != null && !aux.getData().equals(element)){
            aux = aux.getNext();
        }

        if (aux != null){
            result = aux.getData();
        }

        return result;
    }

    // Remove the first element of the list.
    public void removeFirst(){
       
        if (size > 0){
            if (size == 1){
                this.setHead(null);
                this.setTail(null);

            } else {
                Node<T> newHead = this.getHead().next;
                newHead.setPrevious(null);
                this.getHead().setNext(null);
                this.setHead(newHead);
            }

            this.size--;
        }
    }

    // Remove the last element of the list.
    public void removeLast(){

        if (size > 0){
            if(size == 1){
                this.setHead(null);
                this.setTail(null);

            } else {
                Node<T> newTail = this.tail.getPrevious();
                newTail.setNext(null);
                this.getTail().setPrevious(null);
                this.setTail(newTail);
            }

            this.size--;
        }
    }

    // Remove the first ocurrence of a given element.
    public void remove(T element){

        Node<T> aux = this.getHead();
        while (aux != null && !aux.getData().equals(element)){
            aux = aux.getNext();
        }

        if (aux != null){

            if (aux.getNext() == null){
                removeLast();

            } else if (aux.getPrevious() == null){
                removeFirst();

            } else {

                Node<T> auxNext = aux.getNext();
                Node<T> auxPrev = aux.getPrevious();

                auxNext.setPrevious(auxPrev);
                auxPrev.setNext(auxPrev);
                this.size--;
            }
        }
    }

    // Return the representation in the form of a array.
    public T[] toArray(){
        
        T[] result = (T[]) new Comparable[this.size];
        Node<T> aux = this.getHead();
        int index = 0;

        while (aux != null){
            result[index] = aux.getData();
            aux = aux.getNext();
            index++;
        }

        return result;
    }

    public int size(){
        return size();
    }

    public boolean isEmpty(){
        return size == 0;
    }

    public Node<T> getHead() {
        return head;
    }

    public void setHead(Node<T> head) {
        this.head = head;
    }

    public Node<T> getTail() {
        return tail;
    }

    public void setTail(Node<T> tail) {
        this.tail = tail;
    }

    private class Node<T> {

        private T data;
        private Node previous;
        private Node next;

        public Node(){}

        public Node(T data){
            this.setData(data);
        }

        public Node getNext() {
            return next;
        }

 
        public void setNext(Node next) {
            this.next = next;
        }

        public T getData() {
            return data;
        }

        public void setData(T data) {
            this.data = data;
        }

        public Node getPrevious() {
            return previous;
        }


        public void setPrevious(Node previous) {
            this.previous = previous;
        }


    }

} 