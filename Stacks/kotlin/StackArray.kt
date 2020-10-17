package tecnicheDiProgrammazione.stack

import kotlin.math.min

class StackArray<Value> : Stack<Value> {
    private var array: Array<Value?> = arrayOfNulls<Any?>(2) as Array<Value?>
    private var posOfNextElement: Int = 0

    override fun push(value: Value) {
        array[posOfNextElement] = value
        posOfNextElement++
        if (posOfNextElement >= array.size)
            resizing(2 * array.size)

    }

    override fun pop(): Value? {
        val v = peek()
        if (isEmpty())
            return null
        posOfNextElement--
        if (size() != 0 && size() <= array.size / 4)
            resizing(array.size / 2)
        return v
    }

    override fun peek(): Value? {
        if (isEmpty())
            return null
        return array[posOfNextElement - 1]
    }

    override fun isEmpty(): Boolean {
        return posOfNextElement == 0
    }

    override fun size(): Int {
        return posOfNextElement
    }

    private fun resizing(capacity: Int) {
        val newArray: Array<Value?> =
            arrayOfNulls<Any?>(capacity) as Array<Value?>

        for (i in 0 until posOfNextElement)
            newArray[i] = array[i]

        array = newArray
    }


}
