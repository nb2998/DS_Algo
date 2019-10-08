package tecnicheDiProgrammazione.queue

class QueueArray<Value> : Queue<Value> {

    private var array: Array<Value?> = arrayOfNulls<Any?>(1) as Array<Value?>
    private var posOfNextElement: Int = 0
    private var elemToDelete: Int = 0

    override fun enqueue(value: Value) {
        array[posOfNextElement] = value
        posOfNextElement = (posOfNextElement + 1) % array.size
        if (size() == array.size)
            resizing(array.size*2)
    }

    override fun dequeue(): Value? {
        val v = peek()
        if (isEmpty())
            return null
        array[elemToDelete] = null
        elemToDelete = (elemToDelete + 1) % array.size
        if (size() <= (array.size/4) && size() != 0)
            resizing(array.size/2)
        return v
    }

    override fun peek(): Value? {
        if (isEmpty())
            return null
        return array[elemToDelete]
    }

    override fun size(): Int {
        if (posOfNextElement < elemToDelete)
            return array.size - (elemToDelete - posOfNextElement)
        else if (posOfNextElement == elemToDelete && array[elemToDelete] != null)
            return array.size
        return posOfNextElement - elemToDelete
    }

    override fun isEmpty(): Boolean {
        return size() == 0
    }

    fun resizing(capacity: Int) {
        val newArray: Array<Value?> =
            arrayOfNulls<Any?>(capacity) as Array<Value?>
        for (i in 0 until size())
            newArray[i] = array[(i+elemToDelete)%array.size]
        posOfNextElement = size()
        array = newArray
        elemToDelete = 0



    }

}