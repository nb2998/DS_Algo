package tecnicheDiProgrammazione.queue

interface Queue<Value> {
    fun enqueue(value : Value)
    fun dequeue() : Value?
    fun peek () : Value?
    fun size() : Int
    fun isEmpty() : Boolean
}