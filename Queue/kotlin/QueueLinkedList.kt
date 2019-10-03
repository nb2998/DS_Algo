package tecnicheDiProgrammazione.queue

class QueueLinkedList<Value> : Queue<Value> {
    class Node<Value>(var next: Node<Value>?, var value: Value)

    private var head: Node<Value>? = null
    private var last: Node<Value>? = null
    private var count: Int = 0


    override fun enqueue(value: Value) {
        val newNode: Node<Value>? = Node(null, value)
        if (isEmpty()) {
            last = newNode
            head = newNode
        } else {
            last?.next = newNode
            last = newNode
        }
        count++
    }

    override fun dequeue(): Value? {
        val v = peek()
        if (isEmpty())
            return null
        head = head?.next
        count --
        return v
    }

    override fun peek(): Value? {
        return head?.value
    }

    override fun size(): Int {
        return count
    }

    override fun isEmpty(): Boolean {
        return count == 0
    }
}