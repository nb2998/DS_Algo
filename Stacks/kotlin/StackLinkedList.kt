package tecnicheDiProgrammazione.stack

class StackLinkedList<Value> : Stack<Value> {
    private var head: Node<Value>? = null
    private var count: Int = 0

    class Node<Value>(var next: Node<Value>?, var value: Value)

    override fun push(value: Value) {
        val newNode: Node<Value> =
            Node(head, value)
        head = newNode
        count++
    }

    override fun pop(): Value? {
        val v = peek()
        if (isEmpty())
            return null
        head = head?.next
        count--
        return v
    }

    override fun peek(): Value? {
        return head?.value
    }

    override fun isEmpty(): Boolean {
        return count == 0
    }
    override fun size() : Int{
        return count
    }

}